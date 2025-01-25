#include <cstdint>
#include <raylib.h>
class Animation {
    private:
        int64_t start_frame = -1;
        unsigned current_frame = 0;
        unsigned frame_count;
        unsigned frame_speed;
        unsigned width;
        unsigned height;
        Texture2D texture;
    public:
        Animation(const char * path, int _width, int _height);
        ~Animation();
        void draw(int64_t global_frame, int pos_x, int pos_y, float scale);
};
