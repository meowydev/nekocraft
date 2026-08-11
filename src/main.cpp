#include "structs/Block.hpp"
#include "structs/BlockID.hpp"
#include "structs/Button.hpp"
#include <raylib.h>
#include "chunks/chunkType.hpp"
#include <vector>
#include "crashhandler/crashhandler.hpp"

#include "chunks/chunkGen.hpp"
#include "chunks/chunkMesh.hpp"
#include "chunks/chunkModel.hpp"

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

  nekocraft::ChunkGen Chunker;
  nekocraft::ChunkMesh Chunkmeshr;

  std::vector<ChunkModel> chunkModels;

  int offX = 0;
  int offZ = 0;

  for (int e = 0; e < 4; e++) {
    for (int c = 0; c < 4; c++) {
      chunkModels.emplace_back(
        LoadModelFromMesh(Chunkmeshr.build(Chunker.generateChunk())),
        Vector3{static_cast<float>(offX),0.0f ,static_cast<float>(offZ)}
      );
      offZ += 16;
    }
    offZ = 0;
    offX += 16;
  }

  for (auto& chunk : chunkModels) {
    chunk.chunk.materials[0]
        .maps[MATERIAL_MAP_ALBEDO]
        .texture = grass;
  }

  while (!WindowShouldClose()) {

    UpdateCamera(&cam, CAMERA_FREE);

    BeginDrawing();

      ClearBackground(WHITE);

      BeginMode3D(cam);

        for (const auto& chunkModel : chunkModels) {
          DrawModel(
              chunkModel.chunk,
              chunkModel.pos,
              1.0f,
              WHITE
          );
        }

      EndMode3D();

    EndDrawing();

  }

  UnloadTexture(grass);
  UnloadSound(GUISelect);

  CloseWindow();
}
