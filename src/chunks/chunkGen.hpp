//
// Created by meowy on 8/11/26.
//

#pragma once
#include <vector>
#include "chunkType.hpp"
#include <raylib.h>

#ifndef NEKOCRAFT_CHUNKGEN_HPP
#define NEKOCRAFT_CHUNKGEN_HPP

namespace nekocraft {
    class ChunkGen {
    public:
        void generateChunks(std::vector<nekocraft::Chunk>& chunks) {
            chunks.reserve(16);
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    Chunk chunk;
                    chunk.setOrigin(offsetX, offsetZ);

                    int height = GetRandomValue(4, 20);

                    for (int x = 0; x < 16; x++) {
                        for (int z = 0; z < 16; z++) {
                            for (int y = 0; y < height; y++) {
                                chunk.setBlock(x, y, z, 1);
                            }
                        }
                    }

                    chunks.push_back(std::move(chunk));

                    offsetZ += 16;
                }
                offsetZ = 0;
                offsetX += 16;
            }
        }
    private:
        int offsetX = 0;
        int offsetZ = 0;
    };
}

#endif //NEKOCRAFT_CHUNKGEN_HPP
