#include "raylib.h"
#include "imgui.h"

#include "rlImGui.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "raylib [C++]");
    SetTargetFPS(60);
    float sliders[4] = {0.0f, 0.0f, 0.0f, 0.0f};
    rlImGuiSetup(true);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        rlImGuiBegin();
        ImGui::Begin("Hello, world!");
        ImGui::Text("Hello, world!");
        ImGui::SliderFloat4("float4", &sliders[0], 0.0f, 1.0f);
        ImGui::End();
        rlImGuiEnd();
        unsigned char red = (unsigned char)(sliders[0] * 255.0f);
        unsigned char green = (unsigned char)(sliders[1] * 255.0f);
        unsigned char blue = (unsigned char)(sliders[2] * 255.0f);
        unsigned char alpha = (unsigned char)(sliders[3] * 255.0f);
        DrawText("Hello, world!", 120, 300, 20, {
            red, green, blue, alpha
        });
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
