#include "Novice.h"
#include "Title.h"
Title::Title() {
	startGame = 0;
}
Title::~Title() {
}
void Title::Draw() {
	Novice::ScreenPrintf(300, 300, "TITLE");
	Novice::ScreenPrintf(400, 500, "SPACE START");
}
void Title::Update(char *keys,char *preKeys) {
	preKeys;
	if (keys[DIK_SPACE]) {
		startGame = 1;
	}
}

int Title::GetSratGame()
{
	return startGame;
}
