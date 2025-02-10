#include "Game.h"
#include <Novice.h>
#include "Enemy.h"

Game::Game()
{
    player = new Player(500, 500, 5);
    enemy = new Enemy(100, 100, 2.0f, 1.0f);
    bullet = new Bullet();
}

Game::~Game()
{
    delete player;
    delete enemy;
    delete bullet;
}

void Game::update(char* keys, char* preKeys) {
    // プレイヤーの移動
    if (keys[DIK_A] != 0) {
        player->move(-1, 0);  // 左に移動
    }
    if (keys[DIK_D] != 0) {
        player->move(1, 0);   // 右に移動
    }
    if (keys[DIK_W] != 0) {
        player->move(0, -1);  // 上に移動
    }
    if (keys[DIK_S] != 0) {
        player->move(0, 1);   // 下に移動
    }

    // 弾の発射
    if (keys[DIK_SPACE] != 0 && preKeys[DIK_SPACE] == 0) {
        bullet->SetBulletPosition(player->x, player->y);
    }

    // 弾の移動
    bullet->move();

    // 敵の移動
    if (enemy != nullptr) {
        enemy->move();
    }

    //弾と敵
    float BulletToEnemyX = enemy->GetEnemyPosX() -bullet->GetBulletPosX();
    float BulletToEnemyY = enemy->GetEnemyPosY() - bullet->GetBulletPosY();
    float BulletToEnemy = (BulletToEnemyX * BulletToEnemyX) + (BulletToEnemyY * BulletToEnemyY);
    if (BulletToEnemy <= (40 + bullet->GetBulletRadius()) *(40 + bullet->GetBulletRadius())) {
        delete enemy;
        enemy = nullptr;
    }
    //敵と自機
    float PlayerToEnemyX = float(static_cast<int>(enemy->GetEnemyPosX() - static_cast<int>(bullet->GetBulletPosX())));
    float PlayerToEnemyY = float(static_cast<int>(enemy->GetEnemyPosY() - static_cast<int>(bullet->GetBulletPosY())));
    float PlayerToEnemy = (PlayerToEnemyX * PlayerToEnemyX) + (PlayerToEnemyY *PlayerToEnemyY);
    if (PlayerToEnemy <= (40 + 30)* (40 + 30)) {
        delete player;
        player = nullptr;
    }
    if (keys[DIK_R]) {
        delete player;
        delete enemy;
        delete bullet;
        player = new Player(500, 500, 5);
        enemy = new Enemy(100, 100, 2.0f, 1.0f);
        bullet = new Bullet();
    }
}

void Game::draw() {
    // プレイヤーの描画
    if (player != nullptr){
        Novice::DrawEllipse(
            static_cast<int>(player->x),
            static_cast<int>(player->y),
            30, 30,
            0.0f,
            BLUE,
            kFillModeSolid
        );
    }
   

    // 弾の描画
   
    if (bullet != nullptr) {
        Novice::DrawEllipse(
            static_cast<int>(bullet->GetBulletPosX()),
            static_cast<int>(bullet->GetBulletPosY()),
            20, 20,
            0.0f,
            WHITE,
            kFillModeSolid);
       }
           
        
    

    // 敵の描画
   
            if (enemy != nullptr) {
                Novice::DrawBox(
                    static_cast<int>(enemy->GetEnemyPosX()),
                    static_cast<int>(enemy->GetEnemyPosY()),
                    40, 40,
                    0.0f,
                    RED,
                    kFillModeSolid);
       }
           
      
    
}
