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
            Texture2D normal,
            Texture2D hover,
            Vector2 pos,
            std::string text
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
