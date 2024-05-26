# Aim
I took this amazing GitHub from the original creator and added rlImGui and ImGui support so you can have a built in UI with your
Raylib project to allow you to monitor and change things in your game. It's a very simple template at the moment but works very 
well!

# Usage
```sh
git clone https://github.com/manuel5975p/raylib-cmake-template.git
cd raylib-cmake-template
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug #Can also be =Release, =RelWithDebInfo, nothing defaults to Debug
cmake --build .
Debug/main.exe (or ./main if you're on macos/linux I believe)
```
# Usage with VSCode

- Open the `raylib-cmake-template` directory in VSCode
- Make sure the "C/C++" extension as well "CMake Tools" are installed
- Also have a compiler installed (e.g. [the latest w64devkit](https://github.com/skeeto/w64devkit/releases))
- Hit the debug, build button or hit Ctrl+Shift+P for the command menu and run "CMake: Debug" or something similar
