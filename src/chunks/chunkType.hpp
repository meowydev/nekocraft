// Made by Meowy
// Using Clion (created with neovim tho)
#pragma once
#include "../crashhandler/crashhandler.hpp"

namespace nekocraft {

    class Chunk {
    public:
        inline int getBlock(int x, int y, int z) const { return blocks[x][y][z]; }
        inline void setBlock(int x, int y, int z, int value) {
            if (x < 0 || x >= 16 ||
                y < 0 || y >= 128 ||
                z < 0 || z >= 16)
            {
                crashhandler::Fatal("Hmmm my cats are purring \n\n They only do that when its \n\n something really bad");
            }
            blocks[x][y][z] = value;
        }
        inline void setOrigin(int x, int z) { originX = x; originZ = z; }
        inline int getOriginX() const { return originX; }
        inline int getOriginZ() const { return originZ; }

    private:
        int blocks[16][128][16] = {};
        int originX = 0;
        int originZ = 0;
    };

}
