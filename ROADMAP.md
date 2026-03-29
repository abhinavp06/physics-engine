## Phase 1 — Math Foundation + Window
- **Node 1.1** — `Vec3.h` · constructors, operators, dot, cross, normalize
- **Node 1.2** — `Vec2.h` · screen coords, UV coords
- **Node 1.3** — `Mat4.h` · identity, multiply, multiplyPoint, multiplyDirection
- **Node 1.4** — SDL3 window · game loop, vsync, event handling, clean shutdown

## Phase 2 — Software Rasterizer
- **Node 2.1** — Pixel buffer · SDL_Texture, raw pixel write, index formula
- **Node 2.2** — Bresenham's line algorithm · integer only, wireframe render
- **Node 2.3** — Triangle rasterization · scanline fill, flat color
- **Node 2.4** — Z-buffer · depth sorting, correct occlusion
- **Node 2.5** — Shading · surface normals, back-face culling, flat shading with directional light

## Phase 3 — 3D Pipeline
- **Node 3.1** — Model/View/Projection matrices
- **Node 3.2** — Perspective divide + W component
- **Node 3.3** — Viewport transform
- **Node 3.4** — Clipping

## Phase 4 — GPU Pipeline (OpenGL)
- **Node 4.1** — VAO, VBO, EBO
- **Node 4.2** — GLSL vertex + fragment shaders
- **Node 4.3** — Textures + UV mapping
- **Node 4.4** — Phong lighting model

## Phase 5 — Scene Graph + ECS
- **Node 5.1** — Entity-Component-System architecture
- **Node 5.2** — Transform hierarchy
- **Node 5.3** — Camera system

## Phase 6 — Advanced Rendering
- **Node 6.1** — Shadow maps
- **Node 6.2** — Normal maps
- **Node 6.3** — Deferred shading
- **Node 6.4** — PBR intro

## Phase 7 — Physics Integration
- **Node 7.1** — Rigid bodies
- **Node 7.2** — Collision detection
- **Node 7.3** — Euler + Verlet integration

## Phase 8 — Game Engine Layer
- **Node 8.1** — Asset pipeline
- **Node 8.2** — Input system
- **Node 8.3** — Audio
- **Node 8.4** — Scripting layer