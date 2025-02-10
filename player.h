#ifndef PLAYER_H
#define PLAYER_H

#include "Bullet.h"  // Bullet クラスのインクルード

class Player {
public:
    // コンストラクタで初期位置と速度を設定
    Player(float startX, float startY, float spd);

    // プレイヤーの移動関数
    void move(float dx, float dy);

    // 弾を発射する関数
    void shoot();

    // 弾を動かす関数
    void moveBullet();

    // getter メソッド
    float getX() const { return x_; }
    float getY() const { return y_; }
    float getSpeed() const { return speed_; }

    // setter メソッド（必要に応じて使用）
    void setX(float x) { x_ = x; }
    void setY(float y) { y_ = y; }
    void setSpeed(float spd) { speed_ = spd; }

private:
    float x_, y_;  // 自機の座標
    float speed_;   // 自機の移動速度
    Bullet bullet_; // Player に Bullet を包含
};

#endif // PLAYER_H
