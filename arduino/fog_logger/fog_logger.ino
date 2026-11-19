/*
  fog_logger.ino  --  DRAFT, not yet run on hardware

  Reads the load cell under the collecting cup and prints one CSV line per
  second over USB:

      time_s,grams

  Copy the output from the Serial Monitor into a file such as
  data/runs/mesh_run1.csv, or save it with a serial logger.

  Commands (type in the Serial Monitor, 9600 baud, then press Enter):
    t   tare: zero the scale with the empty cup on it
    c   calibrate: put a known weight on, then type its grams, e.g. "c25"
    s   start logging (time restarts at 0)
    x   stop logging

  Wiring (Arduino UNO):
    HX711  DT -> D3, SCK -> D2, VCC -> 5V, GND -> GND
    Load cell -> HX711 E+ (red), E- (black), A+ (green), A- (white)
    If the reading goes DOWN when you add weight, swap the green and white
    wires (or just use the negative calibration factor it prints).

  Library: "HX711" by Bogdan Necula (Library Manager -> search HX711).
*/

#include "HX711.h"

const int HX_DT  = 3;
const int HX_SCK = 2;
const int N_READS = 10;            // readings averaged per logged point
const unsigned long PERIOD_MS = 1000;

// Raw units per gram. Set it with the "c" command, then paste the printed
// value here so it survives a reset.
float SCALE = 1.0;

HX711 scale;
bool logging = false;
unsigned long t0 = 0;
unsigned long nextLog = 0;

void setup() {
  Serial.begin(9600);
  scale.begin(HX_DT, HX_SCK);
  scale.set_scale(SCALE);
  delay(1000);
  scale.tare();
  Serial.println("# fog_logger ready: t = tare, c<grams> = calibrate, s = start, x = stop");
}

void handleCommand() {
  String cmd = Serial.readStringUntil('\n');
  cmd.trim();
  if (cmd.length() == 0) return;

  if (cmd[0] == 't') {
    scale.tare(20);
    Serial.println("# tared");
  } else if (cmd[0] == 'c') {
    float grams = cmd.substring(1).toFloat();
    if (grams <= 0) {
      Serial.println("# type the weight in grams after c, e.g. c25");
      return;
    }
    scale.set_scale(1.0);
    float raw = scale.get_units(20);     // raw units above the tare
    SCALE = raw / grams;
    scale.set_scale(SCALE);
    Serial.print("# calibration factor = ");
    Serial.println(SCALE, 4);
    Serial.println("# paste this into SCALE at the top of the sketch");
  } else if (cmd[0] == 's') {
    logging = true;
    t0 = millis();
    nextLog = t0;
    Serial.println("time_s,grams");
  } else if (cmd[0] == 'x') {
    logging = false;
    Serial.println("# stopped");
  }
}

void loop() {
  if (Serial.available()) handleCommand();

  if (logging && millis() >= nextLog) {
    float g = scale.get_units(N_READS);
    float t = (nextLog - t0) / 1000.0;
    Serial.print(t, 1);
    Serial.print(",");
    Serial.println(g, 2);
    nextLog += PERIOD_MS;
  }
}
