#include "Bullet.h"

Bullet::Bullet() {
    x_ = 0.0f;
    y_ = 0.0f;
    speed_ = 5.0f;
    radius_ = 10.0f;
}

void Bullet::move() {
    y_ -= speed_;  // 弾は上方向に進む
}

void Bullet::SetBulletPosition(float x, float y) {
    x_ = x;
    y_ = y;
}
