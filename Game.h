#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include <vector>

class Game {
public:
    

    Game();
    ~Game();
    void update(char* keys, char* preKeys);
    void draw();
private:
    Player player;
 Bullet bullet;
    Enemy enemy;
};

#endif // GAME_H
