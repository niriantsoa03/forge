cmake_minimum_required(VERSION 3.21)

project(forge VERSION 0.1.0)

# ---- C standard ----
set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# ---- Compiler option ----
add_library(warnings INTERFACE)

target_compile_options(warnings INTERFACE
    -Wall
    -Wextra
    -Werror
)

# ---- SDL ----
add_subdirectory(external/SDL)

# ---- library ----
add_library(libforge
    src/renderer.c
)

target_include_directories(libforge
    PUBLIC include
)

target_link_libraries(libforge
    PUBLIC SDL3::SDL3
)

target_link_libraries(libforge PRIVATE warnings)

# ---- executable ----
add_executable(forge
    src/main.c
)

target_link_libraries(forge
    PRIVATE libforge
)

target_link_libraries(forge PRIVATE warnings)
