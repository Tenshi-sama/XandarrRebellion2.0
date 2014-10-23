#ifndef SRC_LEVELONE_H
#define SRC_LEVELONE_H

#include "Texture.h"
#include "Window.h"


class LevelOne 
{
private:
	//======================//
	//		Properties		//
	//======================//
	const string SPRITE_LOCATION;
	Texture tile_;

public:
	// Ctor and Dtor
	LevelOne() : SPRITE_LOCATION("_resources\\TileDevTest.png") {};
	~LevelOne(){};

	//======================//
	//		Behaviours		//
	//======================//
	void Init(SDL_Renderer* r);
	void HandleEvents(SDL_Event* event);
	void Update(WindowManager* w);
	void Render(WindowManager* w);
};

#endif