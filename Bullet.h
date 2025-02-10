#ifndef BULLET_H
#define BULLET_H

class Bullet {
public:
    Bullet();  // コンストラクタ
    void move();  // 弾を動かす関数
    float GetBulletPosX() { return x_; };
    float GetBulletPosY() { return y_; };
    float GetBulletSpeed() { return speed_; };
    float GetBulletRadius() { return radius_; };
    void SetBulletPosition(float x, float y);  // 弾の位置設定関数

private:
    float x_, y_;  // 弾の座標
    float speed_;   // 弾の移動速度
    float radius_;  // 弾の半径
};

#endif // BULLET_H
