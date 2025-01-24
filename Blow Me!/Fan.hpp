#ifndef FAN_HPP
#define FAN_HPP

typedef enum {WIND, FIRE} state;

class Fan
{
  private:
    static constexpr double RADIUS = 16;

    double x;
    state state_of_fan;
    double velocity;

  public:
    Fan(double x_ = 5, state state_of_fan_ = WIND);

    void update_velocity(double velocity_);
    void update();
    void switch_state();
    void draw();
    bool check_colision(double x1, double x2);
};

#endif
