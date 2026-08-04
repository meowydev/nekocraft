//
// Created by meowy on 8/4/26.
//

#include "Button.hpp"
#include <raylib.h>

namespace GUI {
    Button::Button(
            Texture2D normal,
            Texture2D hover,
            Vector2 pos,
            std::string txt
        )
    {
        Image = normal;
        hoverImage = hover;
        position = pos;
        text = txt;
    }

    void Button::Update() {
        Vector2 mousePos = GetMousePosition();

        Rectangle bounds = {
            position.x,
            position.y,
            (float)Image.width,
            (float)Image.height
        };

        hovered = CheckCollisionPointRec(
            mousePos,
            bounds
        );
    }

    void Button::Draw() {
        if (!hovered) {
            DrawTexture(
                Image,
                position.x,
                position.y,
                WHITE
            );
        }
        else {
            DrawTexture(
                hoverImage,
                position.x,
                position.y,
                WHITE
            );
        }
        DrawText(text.c_str(),position.x,position.y,30,WHITE);
    }

    bool Button::IsClicked() {
        return hovered && IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
    }

} // GUI