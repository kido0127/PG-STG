#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

class Game {
public:
    Game();
    ~Game();
    void update(char* keys, char* preKeys);
    void Draw();
    int GetStarTitle();
private:
    Player* player;           // プレイヤーのポインタ
    Bullet* bullets[100];      // 弾の配列（最大100発）
    int bulletCount;           // 発射された弾の数
    Enemy* enemies[10];       // 敵の配列（最大10体）
    int enemyCount;           // 敵の数
    int startTitle;
};

#endif // GAME_H
