#pragma once
#ifndef BULLET_H
#define BULLET_H

class Bullet {
public:
   

    Bullet();
    void move();
    float GetBulletPosX() { return x_; };
    float GetBulletPosY() { return y_; };
    float GetBulletSpeed() { return speed_; };
    float GetBulletRadius() { return radius_; };
    void SetBulletPosition(float x, float y);
private:
    float x_, y_;
    float speed_;
    float radius_;
};

#endif // BULLET_H
