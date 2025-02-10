#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
public:
    Enemy(float startX, float startY, float spd, float velocity); 
    ~Enemy();
    void move();  // 移動処理
    float GetEnemyPosX() { return x_; };
    float GetEnemyPosY() { return y_; };
    float GetEnemySpeed() { return speed_; };
    float GetVelocityX() { return velocityX_; };
    void SetPosition(float x, float y);

private:
    float x_, y_;
    float speed_;
    float velocityX_;
};

#endif // ENEMY_H