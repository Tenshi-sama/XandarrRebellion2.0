#ifndef SRC_LEVEL_H
#define SRC_LEVEL_H

#include "Texture.h"
#include "Window.h"
#include "Player.h"
#include "HitBox.h"

#include <vector>

using std::vector;

class Level
{
private:
	//======================//
	//		Properties		//
	//======================//
	const string LEVEL_LOCATION;
	const string BOX_LOCATION;
	Texture level_;

	vector<HitBox*> hitBox_;
	HitBox hitbox1;

public:
	Level() : LEVEL_LOCATION("_resources/Maps/map.png"), BOX_LOCATION("_resources/Player_.png") {}
	~Level(){}

	void Init(SDL_Renderer* r);
	void HandleEvents(SDL_Event* event);
	void Update(WindowManager* w);
	void Render(WindowManager* w);

	HitBox getHitbox() { return hitbox1; };
};

#endif