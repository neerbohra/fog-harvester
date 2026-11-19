# Build log

One entry per work session. Newest at the bottom. Photos go in `docs/photos/` and are linked from the entry.

---

### Wed Nov 18, 2026: picked the project

Switched my fall project to a fog harvester test bench: compare a mesh, a harp and a mesh-harp hybrid collector on the same stand, with the same fog, and measure how much water each one collects with a load cell and an Arduino. It uses parts I already have (straws, the 1 kg load cell + HX711, nuts and bolts) and the department 3D printer.

### Thu Nov 19: makerspace + first CAD

- Went to the makerspace. The printer is a Bambu Lab P1S with a 256 × 256 × 256 mm bed, so every part fits flat.
- Got the full drawing set (8 sheets) with dimensions and position tables for every part.
- Modelled the test piece in Fusion: a 30 × 30 × 5 frame with a 20 × 20 window, 4 strands (0.8 wide, 2.5 pitch) and 3 harp notches top and bottom (1.0 wide, 1.5 deep).

Things I learned:

- Extrude only offers the ring between two squares if both squares are in the **same sketch**. Mine were in different sketches, so I extruded the full square and cut the window instead.
- A shape drawn with the Line tool has to be **closed** before Extrude can select it. The 2-Point Rectangle is always closed.
- The notches only go 1.5 mm into the bar from the outer edge. If the notch runs all the way to the window, the frame falls apart.
- The fishing line doesn't go through a hole. It wraps over the outer edge, sitting in the notch like a guitar string.
- Measuring positions from the inner window edge is easier than from the outer edge, because that's the edge you click when dimensioning.
