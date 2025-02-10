#include "Game.h"
#include <Novice.h>
#include <enemy.h>

Game::Game()
{
    Player* player = new Player(500, 500, 5);
    Enemy* enemy = new Enemy(100, 100, 2.0f, 1.0f);
    Bullet* bullet = new Bullet();
}

Game::~Game()
{
    if () {
        delete enemy;
    }
}

void Game::update(char* keys, char* preKeys) {
    // プレイヤーの移動
    if (keys[DIK_A] != 0) {
        player.move(-1, 0);  // 左に移動
    }
    if (keys[DIK_D] != 0) {
        player.move(1, 0);   // 右に移動
    }
    if (keys[DIK_W] != 0) {
        player.move(0, -1);  // 上に移動
    }
    if (keys[DIK_S] != 0) {
        player.move(0, 1);   // 下に移動
    }

    // 弾の発射
    if (keys[DIK_SPACE] != 0 && preKeys[DIK_SPACE] == 0) {
        
    }

    // 弾の移動
    for (auto& bullet : bullets) {
        bullet.move();
    }

    // 敵の移動
    for (auto& enemy : enemies) {
        enemy.move();
    }

    //弾と敵
    float BulletToEnemyX = float(static_cast<int>(enemy.GetEnemyPosX() - static_cast<int>(bullet.GetBulletPosX()) )
    //敵と自機

}

void Game::draw() {
    // プレイヤーの描画
    Novice::DrawEllipse(
        static_cast<int>(player.x),
        static_cast<int>(player.y),
        30, 30,
        0.0f,
        BLUE,
        kFillModeSolid
    );

    // 弾の描画
    for (auto& bullet : bullets) {
        if (bullet.GetBulletPosY() > -9999) {
            Novice::DrawEllipse(
                static_cast<int>(bullet.GetBulletPosX()),
                static_cast<int>(bullet.GetBulletPosY()),
                20, 20,
                0.0f,
                WHITE,
                kFillModeSolid);
        }
    }

    // 敵の描画
    for (auto& enemy : enemies) {
        if (enemy.GetEnemyPosY() > -9999) {
            Novice::DrawBox(
                static_cast<int>(enemy.GetEnemyPosX()),
                static_cast<int>(enemy.GetEnemyPosY()),
                40, 40,
                0.0f,
                RED,
                kFillModeSolid);
        }
    }
}
