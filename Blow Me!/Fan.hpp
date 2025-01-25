#ifndef FAN_HPP
#define FAN_HPP

#include "Animation.hpp"

enum state {WIND, FIRE} ;

class Fan
{
  private:
    float RADIUS = 16;

    float x;
    state stateOfFan;
    float velocity;
    float scale;
   

  public:
    Fan(float x_ ,float radius, float velocity, float scale, const char* path, int frameCount, int frameSpeed, state state_of_fan_ = WIND);

    ~Fan();

    void updatePosition(int direction, int screenWidth);
    void update(int screenWidth, int64_t& globalFrame);
    void switchState();
    void draw(int64_t& globalFrame);
    bool checkCollision(float x1);
    state getFanState();
    void handleInput();

    Animation* animComponent;

};

#endif
