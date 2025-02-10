#pragma once
class Title {
	
private:
	int startGame;
	
public:
	Title();
	~Title();
	void Draw();
	void Update(char* keys, char* preKeys);
	int GetSratGame();
};