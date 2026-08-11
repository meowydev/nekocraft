//
// Created by meowy on 8/5/26.
//

#pragma once
#include <raylib.h>

#ifndef NEKOCRAFT_BLOCK_HPP
#define NEKOCRAFT_BLOCK_HPP

namespace nekocraft {
    class Block {
    public:
        Block(
            const Texture2D &texture
        )
        {
            mesh = GenMeshCube(1.0f,1.0f,1.0f);
            cube = LoadModelFromMesh(mesh);

            cube.materials[0]
                .maps[MATERIAL_MAP_ALBEDO]
                .texture = texture;
        }

        void Draw() const {
            DrawModel(
                cube,
                {0.0f,0.0f,0.0f},
                1.0f,
                WHITE
            );
        }
    private:
        Mesh mesh;
        Model cube;
    };
}

#endif //NEKOCRAFT_BLOCK_HPP
