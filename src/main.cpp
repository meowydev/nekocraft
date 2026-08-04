#include <iostream>
#include <raylib.h>
#include <tinyfiledialogs.h>
#include "crashhandler/crashhandler.hpp"
#include <vector>
#include "structs/Button.hpp"

int main()
{

    InitWindow(1920,1080,"NekoCraft 3D");

    InitAudioDevice();

    Sound GUISelect = LoadSound("assets/sound/select.mp3");

    GUI::Button sampleBtn(
        LoadTexture("assets/button.png"),
        LoadTexture("assets/button_highlighted.png"),
        {50,50},
        "Hello!"
    );

    while (!WindowShouldClose()) {

        int screenCenterX = GetScreenWidth() / 2;
        int screenCenterY = GetScreenHeight() / 2;
        Vector2 cursorPosScreen = GetMousePosition();

        sampleBtn.Update();

        if (sampleBtn.IsClicked()) {
            PlaySound(GUISelect);
        }

        BeginDrawing();

            sampleBtn.Draw();

        EndDrawing();

    }

    UnloadSound(GUISelect);

    CloseWindow();
}
