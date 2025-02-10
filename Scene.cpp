#include "Scene.h"

Scene::Scene()
{
	title_ = new Title();
	game_ = nullptr;
	sceneNumber_ = TITLE;
}

Scene::~Scene()
{
}

void Scene::Draw()
{
	switch (sceneNumber_) {
	case TITLE:
		if (title_ != nullptr) {
			title_->Draw();
			
		}
		break;
	case GAME:
		if (game_ != nullptr) {
			game_->Draw();
			
		}
		break;
	}
}

void Scene::Update(char* keys, char* preKeys)
{
	switch (sceneNumber_) {
	case TITLE:
		if (title_ != nullptr) {
			title_->Update(keys,preKeys);
			if (title_->GetSratGame()) {
				sceneNumber_ = GAME;
				delete title_;
				title_ = nullptr;
				game_ = new Game();
			}
		}
		break;
	case GAME:
		if (game_ != nullptr) {
			game_->update(keys, preKeys);
			if (game_->GetStarTitle()) {
				sceneNumber_ = TITLE;
				delete game_;
				game_ = nullptr;
				title_ = new Title();
			}
		}
		break;
}
}
