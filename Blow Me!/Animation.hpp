#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <cstdint>
#include <raylib.h>
class Animation {
    private:
        int64_t start_frame = -1;
        unsigned current_frame = 0;
        unsigned frame_count;
        unsigned frame_speed;
        int width;
        int height;
        Texture2D texture;
        int invertRatio;
    public:
        Animation(const char * path, int _frame_count, int _frame_speed, bool shouldInvert = false);
        Animation();
      
        
        ~Animation();
        void draw(int64_t& global_frame, int pos_x, int pos_y, float scale);
};

#endif
