#include <Novice.h>
#include "Scene.h"

const char kWindowTitle[] = "LC1B_07_キド_シヅノ";

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    // ライブラリの初期化
    Novice::Initialize(kWindowTitle, 1280, 720);

    // キー入力結果を受け取る箱
    char keys[256] = { 0 };
    char preKeys[256] = { 0 };

    // ゲームのインスタンスを作成
    Scene *scene=new Scene();

    // ウィンドウの×ボタンが押されるまでループ
    while (Novice::ProcessMessage() == 0) {
        // フレームの開始
        Novice::BeginFrame();

        // キー入力を受け取る
        memcpy(preKeys, keys, 256);
        Novice::GetHitKeyStateAll(keys);

        // ゲームの更新
        scene->Update(keys, preKeys);

        // ゲームの描画
        scene->Draw();

        // フレームの終了
        Novice::EndFrame();

        // ESCキーが押されたらループを抜ける
        if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
            break;
        }
    }
    delete scene;
    // ライブラリの終了
    Novice::Finalize();
    return 0;
}
