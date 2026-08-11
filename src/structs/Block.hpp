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
        Block()
        {
            mesh = GenMeshCube(1.0f,1.0f,1.0f);
            cube = LoadModelFromMesh(mesh);

        }

        void Draw(const Vector3 &position, const Texture2D &texture) {

            cube.materials[0]
                .maps[MATERIAL_MAP_ALBEDO]
                .texture = texture;

            DrawModel(
                cube,
                position,
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
