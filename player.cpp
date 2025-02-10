#include "Player.h"

// コンストラクタで初期位置と速度を設定
Player::Player(float startX, float startY, float spd) {
    x_ = startX;
    y_ = startY;
    speed_ = spd;
}

// プレイヤーの移動関数
void Player::move(float dx, float dy) {
    x_ += dx * speed_;  // X座標を移動
    y_ += dy * speed_;  // Y座標を移動
}

// 弾を発射する関数
void Player::shoot() {
    // プレイヤーの位置から弾を発射する
    bullet_.SetBulletPosition(x_, y_);
}

// 弾を動かす関数
void Player::moveBullet() {
    bullet_.move();  // 弾を動かす
}
