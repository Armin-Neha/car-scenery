# Animated 2D Landscape Renderer (OpenGL/C)

A C program that procedurally renders and animates a 2D night landscape — starry sky, moon, hills, a river with a sailboat, a road, and a car driving across the scene — using raw OpenGL primitives (no external image assets, no game engine, no textures).

## What it does

Everything on screen is built from scratch using `glBegin`/`glVertex2f` polygons, triangle fans, and a custom parametric ellipse function — no bitmaps, sprites, or textures are loaded.

- **Sky** — a dark navy background with a randomly generated starfield (`rand()`-placed points).
- **Moon** — an ellipse drawn via a reusable polar-to-Cartesian coordinate routine.
- **Hills** — four overlapping triangular polygons in alternating gold tones.
- **River & boat** — a flat-color river band with a hand-built sailboat (hull, mast, two-part sail).
- **Road & ground** — layered rectangles forming a road with lane-colored strips over green ground.
- **Car** — a multi-part vehicle composed of stacked polygons for the body, roof, trim stripes, and windows, with wheels drawn using the same ellipse routine as the moon (outer tire + inner hubcap). The car's position is parametrized by a single horizontal offset, so it drives smoothly across the screen and wraps back around once it exits.

The scene uses **double buffering** (`GLUT_DOUBLE` + `glutSwapBuffers()`) driven by a `glutTimerFunc` running at ~60 FPS, so the car's motion renders without flicker — this replaced the original single-buffered, single-frame version (`glFlush()`, no redraw loop).

## Tech stack

- **Language:** C
- **Graphics API:** OpenGL (legacy fixed-function pipeline)
- **Windowing/utility toolkit:** GLUT (freeglut)
- **Build tooling:** Originally built with Code::Blocks + MinGW on Windows; also compiles directly with GCC on Linux/macOS.

## Getting started

### Linux (Debian/Ubuntu/WSL)

```bash
sudo apt install freeglut3-dev
gcc main.cpp -o car_scene -lGL -lGLU -lglut
./car_scene
```

### macOS

GLUT is deprecated but still usable:

```bash
g++ main.cpp -o car_scene -framework OpenGL -framework GLUT -Wno-deprecated-declarations
./car_scene
```

### Windows (Code::Blocks)

1. Open `car1.cbp` in Code::Blocks.
2. Ensure the `freeglut`, `opengl32`, `glu32`, `winmm`, and `gdi32` libraries are linked (already configured in the project file).
3. Build and run (F9).

## Project structure

```
.
├── main.cpp      # All scene-drawing logic
├── car1.cbp      # Code::Blocks project file (Windows/MinGW build config)
└── README.md
```

## Possible extensions

Ideas for building on this project further:

- **Boat motion** — apply the same offset technique used for the car to bob the sailboat on the river.
- **Day/night cycle** — interpolate background and object colors over time for a lighting transition.
- **Interactivity** — keyboard/mouse controls (`glutKeyboardFunc`) to steer the car or move the camera.
- **Modern OpenGL** — port from the fixed-function pipeline (`glBegin`/`glVertex2f`) to shader-based rendering with VBOs/VAOs.

## Notes

This project was built as a computer graphics fundamentals exercise, focused on 2D primitive composition, coordinate transforms, manual scene layering, and (in its current version) basic real-time animation with double buffering.
