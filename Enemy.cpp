#include "Enemy.h"



Enemy::Enemy(float startX, float startY, float spd, float velocity)
{
    x_= startX;
    y_ = startY;
    speed_ = spd;
    velocityX_ = velocity;
    
}

void Enemy::move() {
    x_ += speed_*velocityX_;
    if (x_ >= 1280||x_<=0) {
        velocityX_ *= -1;
    }
}

void Enemy::SetPosition(float x, float y)
{
    x_ = x;
    y_ = y;
}
