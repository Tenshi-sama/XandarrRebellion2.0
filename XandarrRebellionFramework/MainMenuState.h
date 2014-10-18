#ifndef SRC_MAIN_MENU_STATE_H
#define SRC_MAIN_MENU_STATE_H

#include "GameState.h"
#include "GameStateManager.h"
#include "Button.h"

//Third GameState of the application
class MainMenuState : public GameState {
	//======================//
	//		Properties		//
	//======================//
private:
	// Pointer to Button for New Game
	Button* new_game_btn_;

	// Pointer to Button to Credtis
	Button* credits_game_btn_;

	// Pointer to Button to Quit
	Button* quit_game_btn_;

	//======================//
	//		Behaviours		//
	//======================//
public:
	MainMenuState() {}
	~MainMenuState() {}

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