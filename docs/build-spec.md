# Build spec

All dimensions in mm. X = left–right (across the airflow), Y = along the airflow, Z = up. Positions on the collectors are measured from the **inner window edge**. The [drawing set](../cad/Fog_Harvester_CAD_Drawings.pdf) has every view and position table.

Printer: Bambu Lab P1S (enclosed, 256 × 256 × 256 mm bed), sliced in Bambu Studio. PLA unless noted, 0.4 mm nozzle, 0.2 mm layers, no supports.

Build order: measure → test piece → collectors → stand + gutter → straw box → load cell parts.

## 0. Measure first

- Straw outside diameter
- Fishing line diameter (it's on the spool label)
- Cup base diameter and height (a short cup, about 40–60 tall, works best)
- Load cell length, the hole spacing at each end, and the thread size (M4 or M5)

## Test piece

- Frame 30 × 30 × 5 with a 20 × 20 window.
- 4 strands, 0.8 wide × 1.0 thick, flush with the front face. Left sides at 2.1, 4.6, 7.1 and 9.6 from the window's left edge (2.5 pitch, 1.7 clear gap).
- 3 notches top and bottom, 1.0 wide × 1.5 deep into the outer edge, cut through the full 5 mm thickness. Left sides at 12.5, 15.5 and 18.5 from the window's left edge (3 pitch, 2.0 clear gap).
- Passes if the strands print separate and unbroken and the fishing line drops into the notches. If strands merge, use 3.0 pitch on the collectors; if the line won't go in, widen the notches by 0.2.

## Parts 1–3: collectors (shared frame)

- Frame 110 × 110 × 5, 100 × 100 window (5 mm bars).
- Bottom bar: 2 × 2 chamfer on both lower edges, leaving a 1 mm flat so drops gather and fall into the gutter.
- **1 Mesh:** 39 vertical + 39 horizontal strands, 0.8 wide × 1.0 thick, flush with the front face. First strand's left side 2.1 from the window edge, then every 2.5; the last one ends 2.1 before the far edge.
- **2 Harp:** 32 notches top and bottom, 1.0 wide × 1.5 deep, through the full thickness. First notch's left side 3.0 from the window's left edge, then every 3.0; the last ends 3.0 before the far edge. The line runs down the front, wraps behind the bar to the next notch, and comes back to the front.
- **3 Hybrid:** the harp notches plus two 1.0 × 1.0 bars across the window on the front face, bottom sides 32.5 and 66.5 above the window's bottom edge.
- Print flat, front face down, 100% infill.

## Part 4: stand

- Base 150 (X) × 80 (Y) × 5.
- Two posts 12 × 28 × 125, inner faces 99 apart, 26 from the front edge.
- A slot in each post's inner face, 5.5 wide × 6 deep, from the top down to 32 above the base. The slots are 111 apart, so the 110 frame has 0.5 of play.
- Gutter hole through the right post: 20 wide × 18 tall, bottom 4 above the base (leaves 4 mm walls).
- Gutter support block 12 × 20 × 18, 1.5 in from the left post.
- Print base down, 20% infill.

## Part 5: gutter

- U-channel 170 long, outside 16 × 10, 2 mm walls and floor (inside 12 × 8). Left end closed, right end open.
- Fusion: 16 × 10 rectangle, extrude 170, Shell the top face and the right end face at 2.
- Sits on the block's corner and the far edge of the post hole: about an 8° slope, staying about 2 below the collector. The spout ends about level with the bottom of the stand's base.
- PETG if available; otherwise PLA sealed with clear coat.

## Riser and cup

- The stand sits on a riser about cup height + 50 tall, so the spout is about 10 above the cup rim.
- The load cell runs front to back, with the cup centred under the spout and clear of the riser.

## Part 6: straw box

- Square tube, 114 × 114 outside, 2 mm walls, depth D = 8 × straw diameter (48 for a 6 mm straw).
- Grid on the downwind face: 6 + 6 bars, 1.5 × 1.5, centres every 15.7 from the inside wall.
- Straw pieces needed: about 560 (5 mm), 385 (6 mm), 285 (7 mm), 220 (8 mm).
- Sit it on a block 35 taller than the riser so its centre lines up with the collector's.

## Part 7: load cell base (confirm once the cell arrives)

- Plate 130 × 40 × 6 with a 25 × 13 × 15 pad at one end, giving a 15 mm gap under the cell so it can flex.
- 2 holes Ø4.5 (M4) or Ø5.5 (M5), typically 10 apart, counterbored Ø8.5 from underneath.

## Part 8: cup platform (confirm once the cell arrives)

- Disk Ø70 × 4 with a 25 × 13 × 4 pad underneath, 2 holes matching the free end, counterbored from the top.
- Bolted to the cell's free end. The arrow on the load cell points down.

## Not printed

Cup, fan, ultrasonic humidifier, cardboard duct, riser.
