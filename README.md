# tPixelWindowEngine

This repository contains a simple demo application (`TestingApp`) built using the **tPixelWindowEngine (tPWE)**, which extends the **tPixelGameEngine (tPGE)** with support for **Dear ImGui** and a windowed rendering workflow on **DirectX 11**.  

The project demonstrates:  
- How to integrate **Dear ImGui** with a pixel-based game engine into singular **tPixelWindowEngine**  
- Rendering into a custom viewport with resizable docking support
- Fixed updates, frame rendering, and ImGui-based UI
- How to encapsulate functionality and provide only the necessary API

---

## Project Structure

- **`TestingApp.cpp`** – Defines a demo application that uses `tPWE::Application`.  
  - Implements callbacks:  
    - `OnCreate()` – setup logic
    - `OnUIRender()` – shows the ImGui demo window 
    - `OnFixedUpdate()` – increments an internal timer
    - `OnFrameRender()` – renders a colorful random-pixel background with overlay text

- **`tPixelWindowEngine.cpp`** – Implements `tPWE::WindowEngine`, which manages the render loop, DirectX 11 device, and ImGui integration.  
  - Handles viewport rendering inside an ImGui docking layout
  - Provides an application entry point (`tPWE_Main`) for both **console (debug)** and **WinMain (release)** builds

---

## Distribution
Your project needs the headers and libraries that have been automatically deployed to the `distribution` folder. That's it!

```
.../tPixelWindowEngine/
└── distribution/
    ├── include/
    │   ├── imgui/
    │   │   ├── imconfig.h            (9,999 B)
    │   │   ├── imgui.h               (330,955 B)
    │   │   ├── imgui_impl_dx11.h     (1,491 B)
    │   │   ├── imgui_impl_win32.h    (3,240 B)
    │   │   ├── imgui_internal.h      (240,891 B)
    │   │   ├── imstb_rectpack.h      (20,344 B)
    │   │   ├── imstb textedit.h      (54,933 B)
    │   │   └── imstb_truetype.h      (199,422 B)
    │   │
    │   ├── tpge/
    │   │   └── tPixelGameEngine.h    (72,600 B)
    │   │
    │   └── tpwe/
    │       └── tPWE.h                (1,433 B)
    │
    └── lib/
        └── tPixelWindowEngine.lib    (16,238,358 B)
```
