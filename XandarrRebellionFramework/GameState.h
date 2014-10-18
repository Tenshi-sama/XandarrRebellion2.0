#ifndef SDL2_FRAMEWORK_GAMESTATE_H
#define SDL2_FRAMEWORK_GAMESTATE_H

#include <iostream>

#include "RenderingEngine.h"

using std::cout;
using std::endl;

// (Pure) Abstract Base Class for all GameState's
class GameState {
	//======================//
	//		Behaviours		//
	//======================//
public:
	virtual ~GameState() {};

	// GameState initialization method
	virtual void Init(WindowManager* w) = 0;

	// GameState clean (destruction) method
	virtual void Clean() = 0;

	// GameState event handler method
	virtual void HandleEvents(SDL_Event* event) = 0;

	// GameState logic method
	virtual void Update(WindowManager* w) = 0;

	// GameState render method
	virtual void Render(WindowManager* w) = 0;

protected:
	GameState() {}
};

#endif