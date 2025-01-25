#include "Animation.hpp"
#include <raylib.h>

Animation::Animation(const char * path, int _width, int _height) {
    LoadTexture(path);
    width = _width;
    height = _height;
}

Animation::~Animation() {
    UnloadTexture(texture);
}

void Animation::draw(int64_t global_frame, int pos_x, int pos_y, float scale) {
    if (start_frame == -1) {
        start_frame = global_frame;
    }

    if (global_frame - start_frame >= GetFPS()/frame_speed) {
        start_frame = global_frame;
        current_frame ++;
        if (current_frame >= frame_count) {
            current_frame = 0;
        }
    }
    Rectangle source_rect = {
        (float)width * current_frame, 
        0.f, 
        (float)width, 
        (float)height
    };

    Rectangle dest_rect = {
        pos_x - (width * scale)/2, 
        pos_y - (height * scale)/2,
        width * scale,
        height * scale
    };

    DrawTexturePro(texture, source_rect, dest_rect, (Vector2){0, 0}, 0, WHITE);

}
