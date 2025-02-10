#include "Player.h"

Player::Player(float startX, float startY, float spd) {
    x = startX;
    y = startY;
    speed = spd;
}

void Player::move(float dx, float dy) {
    x += dx * speed;  // X座標を移動
    y += dy * speed;  // Y座標を移動
}
