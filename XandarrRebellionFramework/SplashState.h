#ifndef SRC_SPLASHSTATE_H
#define SRC_SPLASHSTATE_H

#include "GameStateManager.h"
#include "Button.h"
#include "Texture.h"

using namespace std;

//First GameState of the application
class SplashState : public GameState {
	//======================//
	//		Properties		//
	//======================//
private:
	// Pointer to splash screen texture
	SDL_Texture* ptr_splash_screen_;

	const string SPRITE_LOCATION;
	Texture sprite_;

	//======================//
	//		Behaviours		//
	//======================//
public:
	SplashState() : ptr_splash_screen_(nullptr), SPRITE_LOCATION("_resources/start.png") {}
	~SplashState() {}

	// Splash state initialization method
	virtual void Init(WindowManager* w);

	// Splash state clean (destruction) method
	virtual void Clean();

	// Splash state event handler method
	virtual void HandleEvents(SDL_Event* event);

	// Splash state logic update method
	virtual void Update(WindowManager* w);

	// Splash state render method
	virtual void Render(WindowManager* w);
};

#endif