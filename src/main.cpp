#include "structs/Block.hpp"
#include "structs/BlockID.hpp"
#include "structs/Button.hpp"
#include <raylib.h>
#include "chunks/chunkType.hpp"
#include <vector>

#include "chunks/chunkGen.hpp"

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

  std::vector<nekocraft::Chunk> chunks;

  nekocraft::ChunkGen Chunker;

  Chunker.generateChunks(chunks);

  nekocraft::Block tmpblock;

  while (!WindowShouldClose()) {

    UpdateCamera(&cam, CAMERA_FREE);

    BeginDrawing();

      ClearBackground(WHITE);

      BeginMode3D(cam);

        DrawGrid(10, 10);

        for (const auto& chunc : chunks) {
          for (int x = 0; x < 16; x++) {
            for (int y = 0; y < 128 ; y++) {
              for (int z = 0; z < 16; z++) {
                int block = chunc.getBlock(x,y,z);
                if (block == 1) {
                  tmpblock.Draw({static_cast<float>(x) + chunc.getOriginX() ,static_cast<float>(y),static_cast<float>(z) + chunc.getOriginZ()},grass);
                }
              }
            }
          }
        }




      EndMode3D();

    EndDrawing();

  }

  UnloadTexture(grass);
  UnloadSound(GUISelect);

  CloseWindow();
}
