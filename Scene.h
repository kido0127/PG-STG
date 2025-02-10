#pragma once
#include "Game.h"
#include "Title.h"

enum SceneName {
	TITLE,
	GAME,
};
class Scene {
public:
	Scene();
	~Scene();
	void Draw();
	void Update(char *keys,char *preKeys);
private:
	int sceneNumber_;
	Title *title_;
	Game* game_;
};
