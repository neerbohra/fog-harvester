# Fog harvester test bench

**Neer Bohra · Howard University, BS Mechanical Engineering (first year) · Fall 2026**

Fog collectors catch water from fog with a mesh or a set of vertical strings. Small droplets hit the strands, merge, and drip down into a gutter. In the Himalayan villages I know from Nepal, a cheap collector like this could be a real water source. This project builds a small, repeatable test bench to compare three collector designs:

- **Mesh**: a printed grid of thin strands, like the classic Raschel mesh used in the field.
- **Harp**: vertical fishing-line strings only, based on the fog harps developed at Virginia Tech.
- **Hybrid**: the harp with two thin cross-bars to stop the strings sticking together.

Each collector is 3D printed, slides into the same stand, and gets the same fog. A load cell under the collecting cup logs the water's weight every second, so each design gets a collection rate in grams per minute.

## How the bench works

1. A fan blows air through a box of short straws (a flow straightener), which turns the fan's swirl into a straight, even flow.
2. Mist from an ultrasonic humidifier is added just before the straws.
3. The fog passes through the collector held in the stand.
4. Drops roll down to the collector's chamfered bottom edge and fall into a sloped gutter.
5. The gutter carries the water through a hole in the stand's post to a cup on the load cell.
6. An Arduino UNO reads the load cell through an HX711 and prints `time_s,grams` once a second. The output is saved as a CSV and analysed in pandas.

## Parts

All dimensions in mm. Full dimensions, position tables and Fusion steps are in the [drawing set](cad/Fog_Harvester_CAD_Drawings.pdf) and the [build spec](docs/build-spec.md).

| # | Part | Size | Print |
|---|---|---|---|
| 0 | Test piece | 30 × 30 × 5, 4 strands + 3 harp notches top and bottom | PLA, flat |
| 1 | Mesh collector | 110 × 110 × 5 frame, 39 + 39 strands (0.8 wide, 2.5 pitch) | PLA, 100% infill |
| 2 | Harp collector | Same frame, 32 notches top and bottom (1.0 × 1.5, 3 pitch) | PLA, 100% infill |
| 3 | Hybrid collector | Harp + two 1.0 × 1.0 cross-bars | PLA, 100% infill |
| 4 | Collector stand | 150 × 80 base, two 12 × 28 × 125 posts with slots | PLA, 20% infill |
| 5 | Gutter | U-channel 170 long, 16 × 10, 2 mm walls | PETG if possible |
| 6 | Straw box | 114 × 114, depth 8 × straw diameter, rear grid | PLA |
| 7 | Load cell base | 130 × 40 × 6 plate + 15 mm pad | PLA (after the load cell arrives) |
| 8 | Cup platform | Ø70 × 4 disk + pad | PLA (after the load cell arrives) |

Printer: Bambu Lab P1S at the Howard makerspace (256 × 256 × 256 mm build volume), sliced in Bambu Studio.

## Electronics and code

- **Arduino UNO R3** (Elegoo starter kit), **1 kg bar load cell + HX711** amplifier.
- [`arduino/fog_logger/fog_logger.ino`](arduino/fog_logger/fog_logger.ino): logs `time_s,grams` once a second, with tare and calibration commands over Serial. *Draft, not yet run on the hardware.*
- [`analysis/collection_rate.py`](analysis/collection_rate.py): reads every run in `data/runs/`, finds the first drip, fits grams vs time to get g/min, and plots mesh vs harp vs hybrid. *Draft.*

Runs are saved as `data/runs/<collector>_run<N>.csv`, for example `mesh_run1.csv`.

## Plan and progress

- [Build log](docs/build-log.md): what happened in each work session.
- [Build spec](docs/build-spec.md): every part's dimensions and the print settings.

| Piece | State |
|---|---|
| Drawing set (8 sheets) | Done (Nov 19) |
| Test piece CAD | Done (Nov 19) |
| Test piece print + fishing-line fit | Next |
| Collectors CAD (mesh, harp, hybrid) | Nov 21 |
| Stand + gutter CAD | Nov 24 |
| Straw box + load cell parts CAD | Nov 25, after measuring the straws and load cell |
| Printing | From Nov 25 |
| Load cell calibration + CSV logging | Dec 12 |
| Fog runs (3 per collector) | Dec 12–14 |
| Analysis + write-up | Dec 14 |

*Claude (Anthropic) helped with the drawing set, the dimensions and the planning. The CAD modelling, building and testing are mine.*
