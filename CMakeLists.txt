cmake_minimum_required(VERSION 3.14)

# Set the project name. This is not the executable program's name!
project(graphical_template)

# Some CMake tomfoolery
if(POLICY CMP0135)
cmake_policy(SET CMP0135 NEW)
endif()
# End CMake tomfoolery

# Try to find a locally installed raylib, but don't quit on fail
find_package(raylib 5.0 QUIET)

# This code downloads raylib into a directory called _deps and adds it as a subdirectory, compiling it with the program when running the build command
include(FetchContent)
if (NOT raylib_FOUND)
    FetchContent_Declare(
        raylib
        URL https://github.com/raysan5/raylib/archive/refs/tags/5.0.tar.gz
    )
    FetchContent_MakeAvailable(raylib)
endif()

# We don't want raylib's examples built. This option is picked up by raylib's CMakeLists.txt
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

# List ImGui source files
set(IMGUI_SRC
    imgui/imgui.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_tables.cpp
    imgui/imgui_widgets.cpp
    imgui/imgui_demo.cpp
)

# List rlImGui source files
set(RLIMGUI_SRC
    rlImGui/rlImGui.cpp
    # Add other rlImGui source files as needed
)

# Here, the executable is declared with its sources. "main", or "main.exe" on Windows will be the program's name
add_executable(main "main.cpp" ${IMGUI_SRC} ${RLIMGUI_SRC})

# Include directories for ImGui and rlImGui
target_include_directories(main PRIVATE 
    ${raylib_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/imgui
    ${CMAKE_SOURCE_DIR}/rlImGui
)

# Link raylib to main
target_link_libraries(main 
    raylib
)
