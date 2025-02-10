#include "Bullet.h"

Bullet::Bullet(float startX, float startY,float radius) {
    x_ = startX;
    y_ = startY;
    radius_ = radius;
}
void Bullet::move() {
    y_ -= speed_; // 弾は上方向に進む
}

void Bullet::SetBulletPosition(float x, float y)
{
    x_ = x;
    y_ = y;
}
