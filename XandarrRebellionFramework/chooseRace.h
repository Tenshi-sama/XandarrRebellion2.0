#ifndef SRC_CHOOSERACE_H
#define SRC_CHOOSERACE_H

#include "GameState.h"
#include "GameStateManager.h"
#include "Texture.h"

// Second GameState of the application
// Is a faux loading state, nothing is loaded here just
// a way to demonstrate our timer object in action.
class chooseRace : public GameState {
	//======================//
	//		Properties		//
	//======================//
private:
	// Loading screen image
	SDL_Texture * ptr_background_texture_;

	Button* xanos_btn_;
	Button* transient_btn_;
	Button* zenturian_btn_;
	Button* human_btn_;
	//Button* deltan_btn_;

	//======================//
	//		Behaviours		//
	//======================//
public:
	chooseRace() : ptr_background_texture_(nullptr) {}
	~chooseRace() {}

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