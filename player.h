#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    float x, y;  // 自機の座標
    float speed; // 自機の移動速度

    Player(float startX, float startY, float spd);
    void move(float dx, float dy); // プレイヤーの移動関数
};

#endif // PLAYER_H
