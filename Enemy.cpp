#include "Enemy.h"

Enemy::Enemy(float startX, float startY, float spd, float velocity)
    : x_(startX), y_(startY), speed_(spd), velocityX_(velocity) {
    // コンストラクタ内での初期化
}
Enemy::~Enemy() {};
void Enemy::move() {
    if (x_ >= 1280 || x_ <= 0) {
        velocityX_ *= -1;
    }
    if (this == nullptr) {
        return;
    }

    // x座標の移動処理
    x_ += velocityX_ * speed_;
}

void Enemy::SetPosition(float x, float y) {
    if (this == nullptr) {
        return;
    }
    x_ = x;
    y_ = y;
}