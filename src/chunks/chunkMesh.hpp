//
// Created by meowy on 8/11/26.
//

#pragma once

#include <raylib.h>
#include <vector>
#include <algorithm>

#include "chunkType.hpp"

#ifndef NEKOCRAFT_CHUNKMESH_HPP
#define NEKOCRAFT_CHUNKMESH_HPP

namespace nekocraft {

    class ChunkMesh {
    public:

        Mesh build(const Chunk& chunk) {
            std::vector<float> vertices;
            std::vector<float> texturecoords;

            bool Top = false;
            bool Left = false;
            bool Right = false;
            bool Bottom = false;
            bool Forward = false;
            bool Backward = false;

            for (int x = 0; x < 16; x++) {
                for (int y = 0; y < 128; y++) {
                    for (int z = 0; z < 16; z++) {

                        int block = chunk.getBlock(x, y, z);

                        if (block != 0) {

                            if (y == 127 || chunk.getBlock(x, y + 1, z) == 0) {
                                Top = true;
                            }

                            if (x == 0 || chunk.getBlock(x - 1, y, z) == 0) {
                                Left = true;
                            }

                            if (x == 15 || chunk.getBlock(x + 1, y, z) == 0) {
                                Right = true;
                            }

                            if (y == 0 || chunk.getBlock(x, y - 1, z) == 0) {
                                Bottom = true;
                            }

                            if (z == 15 || chunk.getBlock(x, y, z + 1) == 0) {
                                Forward = true;
                            }

                            if (z == 0 || chunk.getBlock(x, y, z - 1) == 0) {
                                Backward = true;
                            }

                            float fx = static_cast<float>(x);
                            float fy = static_cast<float>(y);
                            float fz = static_cast<float>(z);

                            if (Top) {
                                vertices.insert(vertices.end(), {
                                    fx,        fy + 1.0f, fz,
                                    fx,        fy + 1.0f, fz + 1.0f,
                                    fx + 1.0f, fy + 1.0f, fz + 1.0f,

                                    fx,        fy + 1.0f, fz,
                                    fx + 1.0f, fy + 1.0f, fz + 1.0f,
                                    fx + 1.0f, fy + 1.0f, fz
                                });

                                addFaceUVs(texturecoords);
                            }

                            if (Bottom) {
                                vertices.insert(vertices.end(), {
                                    fx,        fy, fz,
                                    fx + 1.0f, fy, fz,
                                    fx + 1.0f, fy, fz + 1.0f,

                                    fx,        fy, fz,
                                    fx + 1.0f, fy, fz + 1.0f,
                                    fx,        fy, fz + 1.0f
                                });

                                addFaceUVs(texturecoords);
                            }

                            if (Left) {
                                vertices.insert(vertices.end(), {
                                    fx, fy,        fz,
                                    fx, fy,        fz + 1.0f,
                                    fx, fy + 1.0f, fz + 1.0f,

                                    fx, fy,        fz,
                                    fx, fy + 1.0f, fz + 1.0f,
                                    fx, fy + 1.0f, fz
                                });

                                addFaceUVs(texturecoords);
                            }

                            if (Right) {
                                vertices.insert(vertices.end(), {
                                    fx + 1.0f, fy,        fz,
                                    fx + 1.0f, fy + 1.0f, fz,
                                    fx + 1.0f, fy + 1.0f, fz + 1.0f,

                                    fx + 1.0f, fy,        fz,
                                    fx + 1.0f, fy + 1.0f, fz + 1.0f,
                                    fx + 1.0f, fy,        fz + 1.0f
                                });

                                addFaceUVs(texturecoords);
                            }

                            if (Forward) {
                                vertices.insert(vertices.end(), {
                                    fx,        fy,        fz + 1.0f,
                                    fx + 1.0f, fy,        fz + 1.0f,
                                    fx + 1.0f, fy + 1.0f, fz + 1.0f,

                                    fx,        fy,        fz + 1.0f,
                                    fx + 1.0f, fy + 1.0f, fz + 1.0f,
                                    fx,        fy + 1.0f, fz + 1.0f
                                });

                                addFaceUVs(texturecoords);
                            }

                            if (Backward) {
                                vertices.insert(vertices.end(), {
                                    fx,        fy,        fz,
                                    fx,        fy + 1.0f, fz,
                                    fx + 1.0f, fy + 1.0f, fz,

                                    fx,        fy,        fz,
                                    fx + 1.0f, fy + 1.0f, fz,
                                    fx + 1.0f, fy,        fz
                                });

                                addFaceUVs(texturecoords);
                            }
                        }

                        Top = false;
                        Left = false;
                        Right = false;
                        Bottom = false;
                        Forward = false;
                        Backward = false;
                    }
                }
            }

            Mesh mesh = {};

            mesh.vertexCount =
                static_cast<int>(vertices.size() / 3);

            mesh.triangleCount =
                mesh.vertexCount / 3;

            mesh.vertices = static_cast<float*>(
                MemAlloc(vertices.size() * sizeof(float))
            );

            mesh.texcoords = static_cast<float*>(
                MemAlloc(texturecoords.size() * sizeof(float))
            );

            std::copy(
                vertices.begin(),
                vertices.end(),
                mesh.vertices
            );

            std::copy(
                texturecoords.begin(),
                texturecoords.end(),
                mesh.texcoords
            );

            UploadMesh(&mesh, false);

            return mesh;
        }

    private:

        static void addFaceUVs(
            std::vector<float>& texturecoords
        ) {
            texturecoords.insert(texturecoords.end(), {
                0.0f, 0.0f,
                0.0f, 1.0f,
                1.0f, 1.0f,

                0.0f, 0.0f,
                1.0f, 1.0f,
                1.0f, 0.0f
            });
        }
    };

}

#endif // NEKOCRAFT_CHUNKMESH_HPP