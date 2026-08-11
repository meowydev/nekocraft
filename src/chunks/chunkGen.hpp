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
        Chunk generateChunk() {
            Chunk chunk;

            int height = GetRandomValue(4, 20);

            for (int x = 0; x < 16; x++) {
                for (int z = 0; z < 16; z++) {
                    for (int y = 0; y < height; y++) {
                        chunk.setBlock(x, y, z, 1);
                    }
                }
            }

            return chunk;
        }
    private:
    };
}

#endif //NEKOCRAFT_CHUNKGEN_HPP
