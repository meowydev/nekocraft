//
// Created by meowy on 8/4/26.
//

#pragma once
#include <raylib.h>
#include <string>

#ifndef NEKOCRAFT_BUTTON_HPP
#define NEKOCRAFT_BUTTON_HPP



namespace GUI {
    class Button {
    public:
        Button(
            const Texture2D &normal,
            const Texture2D &hover,
            const Vector2 &pos,
            const std::string &txt
        );

        void Update();
        void Draw();
        bool IsClicked();
    private:
        Texture2D Image;
        Texture2D hoverImage;

        std::string text;

        Vector2 position;

        bool hovered = false;

    };
} // GUI

#endif //NEKOCRAFT_BUTTON_HPP
