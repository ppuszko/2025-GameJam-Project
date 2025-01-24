#ifndef BUBBLE_HPP
#define BUBBLE_HPP

class Bubble
{
private:
    const double MAX_HEIGHT = 20.0;
    const double MIN_HEIGHT = 0.0;
    const double VELOCITY_UP = 2.0;
    const double VELOCITY_DOWN = -1.0;

    double x, y;
    double radius;
    double velocity;
    double weight_factor;

public:
    Bubble(double x_ = 1.0, double y_ = 1.0, double radius_ = 1.0, double velocity_ = 1.0);

    void move();
    void updateVelocity(double x1, double x2);
    void show();
};

#endif