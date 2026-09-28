# CS151: C++ Programming & Concepts

A collection of C++ projects and coursework completed during CS151.

## Key Topics Covered
- **Pointers & Memory:** Manual memory management, pointer arithmetic, dynamic allocation.
- **Functions & Structures:** Function overloading, pass-by-reference, custom data structures.

## Featured Mini-Projects
- **Treasure Hunt Game (`/Mini-Projects/Treasure-Hunt`):** Interactive terminal-based grid game written in C++.
- **Computer Simulator (`/Mini-Projects/Computer-Simulator`):** C++ implementation modeling basic CPU/memory execution routines.

### Module: Extended Array Manipulation & Offsets
* **`array_offset_modifier.cpp`**: Safely updates specific ranges of array elements starting at designated offsets with out-of-bounds protection.

### Module: C-Strings, Heap Concatenation & Dynamic 2D Arrays
* **`custom_strlen.cpp`**: Re-implementation of `strlen()` using character pointer iteration until encountering the null-terminator (`'\0'`).
* **`string_concat_comparison.cpp`**: Side-by-side implementation comparing low-level heap memory string concatenation (`new char[]` / `delete[]`) with high-level `std::string` concatenation.
* **`dynamic_2d_board_game.cpp`**: Implementation of a dynamic 2D game board using double pointers (`int**`), custom reveal/hide logic based on cell state values, and proper multi-level heap cleanup routines.
