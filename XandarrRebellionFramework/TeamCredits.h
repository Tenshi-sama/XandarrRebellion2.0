#ifndef SRC_TEAMCREDITS_H
#define SRC_TEAMCREDITS_H

#include "GameState.h"
#include "GameStateManager.h"
#include "Timer.h"

//Third GameState of the application
class TeamCredits : public GameState {
	//======================//
	//		Properties		//
	//======================//
private:
	// Loading screen image
	SDL_Texture * ptr_background_texture_;

	// Timer object used to track this faux loading state's lifetime.
	Timer state_life_timer_;

	//======================//
	//		Behaviours		//
	//======================//
public:
	TeamCredits() : ptr_background_texture_(nullptr) {}
	~TeamCredits() {}

	// Main menu state initialization method
	virtual void Init(WindowManager* w);

	// Main menu state clean method
	virtual void Clean();

	// Main menu state event handler method
	virtual void HandleEvents(SDL_Event* event);

	// Main menu state logic update method
	virtual void Update(WindowManager* w);

	// Main menu state render method
	virtual void Render(WindowManager* w);
};

#endif