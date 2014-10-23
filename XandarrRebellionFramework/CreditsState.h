#ifndef SRC_CREDITS_STATE_H
#define SRC_CREDITS_STATE_H

#include "GameState.h"
#include "GameStateManager.h"
#include "Button.h"

//Third GameState of the application
class CreditsState : public GameState {
	//======================//
	//		Properties		//
	//======================//
private:
	// Loading screen image
	SDL_Texture * ptr_background_texture_;

	// Pointer to Button for Back to Main Menu
	Button* main_menu_btn_;

	// Pointer to Button to Quit
	Button* quit_game_btn_;

	//======================//
	//		Behaviours		//
	//======================//
public:
	CreditsState() : ptr_background_texture_(nullptr), main_menu_btn_(nullptr), quit_game_btn_(nullptr) {}
	~CreditsState() {}

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