//
// Created by meowy on 8/11/26.
//

#pragma once
#include <raylib.h>

#ifndef NEKOCRAFT_CHUNKMODEL_HPP
#define NEKOCRAFT_CHUNKMODEL_HPP

struct ChunkModel {
    Model chunk;
    Vector3 pos;

    ChunkModel(Model mdl, Vector3 position) {
        chunk = mdl;
        pos = position;
    }
};

#endif //NEKOCRAFT_CHUNKMODEL_HPP
