#ifndef SRC_LOADINGSTATE_H
#define SRC_LOADINGSTATE_H

#include "GameState.h"
#include "GameStateManager.h"
#include "Texture.h"
#include "Timer.h"

// Second GameState of the application
// Is a faux loading state, nothing is loaded here just
// a way to demonstrate our timer object in action.
class LoadingState : public GameState {
	//======================//
	//		Properties		//
	//======================//
private:
	// Loading screen image
	SDL_Texture * ptr_background_texture_;
	SDL_Texture * ptr_credits_texture_;

	Texture story_text_;

	// Timer object used to track this faux loading state's lifetime.
	Timer state_life_timer_;

	//======================//
	//		Behaviours		//
	//======================//
public:
	LoadingState() : ptr_background_texture_(nullptr) {}
	~LoadingState() {}

	// Loading state initialization method
	virtual void Init(WindowManager* w);

	// Loading state clean method
	virtual void Clean();

	// Loading state event handler method
	virtual void HandleEvents(SDL_Event* event);

	// Loading state logic update method
	virtual void Update(WindowManager* w);

	// Loading state render method
	virtual void Render(WindowManager* w);
};

#endif