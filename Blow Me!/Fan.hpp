#ifndef FAN_HPP
#define FAN_HPP

enum state {WIND, FIRE} ;

class Fan
{
  private:
    static constexpr float RADIUS = 16;

    float x;
    state stateOfFan;
    float velocity;

  public:
    Fan(float x_ = 5, state state_of_fan_ = WIND);

    void updateVelocity(float velocity_);
    void update();
    void switchState();
    void draw();
    bool checkCollision(float x1);
    state getFanState();

};

#endif
