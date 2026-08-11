#include "structs/Block.hpp"
#include "structs/BlockID.hpp"
#include "structs/Button.hpp"
#include <iostream>
#include <raylib.h>
#include <vector>

int main() {

  InitWindow(1920, 1080, "NekoCraft 3D");

  InitAudioDevice();

  Sound GUISelect = LoadSound("assets/sound/select.mp3");

  // Camera

  Camera3D cam;

  cam.fovy = 45.0f;
  cam.position = {5.0f, 3.0f, 0.0f};
  cam.projection = CAMERA_PERSPECTIVE;
  cam.target = {0.0f, 1.0f, 0.0f};
  cam.up = {0.0f, 1.0f, 0.0f};

  // Textures

  Texture2D grass = LoadTexture("assets/textures/grass.png");
  SetTextureFilter(grass, TEXTURE_FILTER_POINT);

  while (!WindowShouldClose()) {

    int screenCenterX = GetScreenWidth() / 2;
    int screenCenterY = GetScreenHeight() / 2;
    Vector2 cursorPosScreen = GetMousePosition();

    UpdateCamera(&cam, CAMERA_FREE);

    BeginDrawing();

    BeginMode3D(cam);

    DrawGrid(10, 10);

    EndMode3D();

    EndDrawing();

    ClearBackground(WHITE);
  }

  UnloadTexture(grass);
  UnloadSound(GUISelect);

  CloseWindow();
}
