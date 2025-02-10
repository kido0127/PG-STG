#include "Game.h"
#include <Novice.h>
#include "Enemy.h"

// コンストラクタ
Game::Game() {
    // プレイヤーを生成
    player = new Player(500.0f, 500.0f, 5.0f);

    // 敵を生成
    enemyCount = 1;
    enemies[0] = new Enemy(100.0f, 100.0f, 2.0f, 1.0f);

    // 弾の初期化
    bulletCount = 0;
    startTitle = 0;
}

// デストラクタ
Game::~Game() {
    // プレイヤー、弾、敵のメモリを手動で解放
    delete player;
    for (int i = 0; i < bulletCount; i++) {
        delete bullets[i];
    }
    for (int i = 0; i < enemyCount; i++) {
        delete enemies[i];
    }
}

void Game::update(char* keys, char* preKeys) {
    // プレイヤーの移動
    if (player != nullptr) {
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
            if (bulletCount < 100) {
                bullets[bulletCount] = new Bullet();
                bullets[bulletCount]->SetBulletPosition(player->getX(), player->getY());
                bulletCount++;
            }
        }

        // 弾の移動
        for (int i = 0; i < bulletCount; i++) {
            if (bullets[i] != nullptr) {
                bullets[i]->move();
            }
        }
    }

    // 敵の移動
    for (int i = 0; i < enemyCount; i++) {
        if (enemies[i] != nullptr) {
            enemies[i]->move();
        }
    }

    // 弾と敵の当たり判定
    for (int i = 0; i < bulletCount; i++) {
        for (int j = 0; j < enemyCount; j++) {
            if (bullets[i] != nullptr && enemies[j] != nullptr) {
                float BulletToEnemyX = enemies[j]->GetEnemyPosX() - bullets[i]->GetBulletPosX();
                float BulletToEnemyY = enemies[j]->GetEnemyPosY() - bullets[i]->GetBulletPosY();
                float BulletToEnemy = (BulletToEnemyX * BulletToEnemyX) + (BulletToEnemyY * BulletToEnemyY);

                if (BulletToEnemy <= (40 + bullets[i]->GetBulletRadius()) * (40 + bullets[i]->GetBulletRadius())) {
                    delete enemies[j];
                    enemies[j] = nullptr;  // 敵を削除
                    
                }
            }
        }
    }

    // 敵と自機の当たり判定
    if (player != nullptr) {
        for (int i = 0; i < enemyCount; i++) {
            if (enemies[i] != nullptr) {
                float PlayerToEnemyX = enemies[i]->GetEnemyPosX() - player->getX();
                float PlayerToEnemyY = enemies[i]->GetEnemyPosY() - player->getY();
                float PlayerToEnemy = (PlayerToEnemyX * PlayerToEnemyX) + (PlayerToEnemyY * PlayerToEnemyY);

                if (PlayerToEnemy <= (40 + 30) * (40 + 30)) {
                    delete player;
                    player = nullptr;  // プレイヤーを削除
                    startTitle = 1;
                }
            }
        }
    }

    // リセット処理
    if (keys[DIK_R]) {
        delete player;
        player = new Player(500.0f, 500.0f, 5.0f);

        for (int i = 0; i < enemyCount; i++) {
            delete enemies[i];
        }
        enemyCount = 1;
        enemies[0] = new Enemy(100.0f, 100.0f, 2.0f, 1.0f);

        for (int i = 0; i < bulletCount; i++) {
            delete bullets[i];
        }
        bulletCount = 0;
    }
    if (keys[DIK_1]) {
        startTitle = 1;
    }
}

void Game::Draw() {
    // プレイヤーの描画
    if (player != nullptr) {
        Novice::DrawEllipse(static_cast<int>(player->getX()), static_cast<int>(player->getY()), 30, 30, 0.0f, BLUE, kFillModeSolid);
    }

    // 弾の描画
    for (int i = 0; i < bulletCount; i++) {
        if (bullets[i] != nullptr) {
            Novice::DrawEllipse(static_cast<int>(bullets[i]->GetBulletPosX()), static_cast<int>(bullets[i]->GetBulletPosY()), 20, 20, 0.0f, WHITE, kFillModeSolid);
        }
    }

    // 敵の描画
    for (int i = 0; i < enemyCount; i++) {
        if (enemies[i] != nullptr) {
            Novice::DrawBox(static_cast<int>(enemies[i]->GetEnemyPosX()), static_cast<int>(enemies[i]->GetEnemyPosY()), 40, 40, 0.0f, RED, kFillModeSolid);
        }
    }

}

int Game::GetStarTitle()
{
    return startTitle;
}
