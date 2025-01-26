#include <raylib.h>

#include "Animation.hpp"

Animation::Animation(const char * path, 
    int _frame_count, int _frame_speed, bool shouldInvert) {
    texture = LoadTexture(path);
    width = texture.width/_frame_count;
    height = texture.height;
    frame_count = _frame_count;
    frame_speed = _frame_speed;
    invertRatio = shouldInvert ? -1 : 1;
}

Animation::Animation(Texture2D & _texture, 
    int _frame_count, int _frame_speed, bool shouldInvert) {
    texture = _texture;
    width = texture.width/_frame_count;
    height = texture.height;
    frame_count = _frame_count;
    frame_speed = _frame_speed;
    invertRatio = shouldInvert ? -1 : 1;
}

Animation::Animation()
{
    frame_count = 0;
    frame_speed = 0;
    width = 0;
    height = 0;
    invertRatio = 1;
}

void Animation::draw(int64_t& global_frame, int pos_x, int pos_y, float scale) {
    if (start_frame == -1) {
        start_frame = global_frame;
    }

    if (global_frame - start_frame >= 60/frame_speed) {
        start_frame = global_frame;
        current_frame ++;
        if (current_frame >= frame_count) {
            current_frame = 0;
        }
    }
    Rectangle source_rect = {
        (float)width * current_frame, 
        0.f, 
        static_cast<float>(invertRatio * width),
        1.0f * height
    };

    Rectangle dest_rect = {
        pos_x - (width * scale)/2, 
        pos_y - (height * scale)/2,
        width * scale,
        height * scale
    };

    DrawTexturePro(texture, source_rect, dest_rect, {0, 0}, 0, WHITE);
}
