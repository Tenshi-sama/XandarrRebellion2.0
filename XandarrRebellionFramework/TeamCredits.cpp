#include "TeamCredits.h"

// Creates and loads the main menu's buttons
void TeamCredits::Init(WindowManager* w) {
	cout << "|-->CreditsState::Init() Invoked" << endl;
	
	ptr_background_texture_ = RenderingEngine::LoadTexture(w->getRenderer(), "_resources\\creditsTeamScreen.png");

	state_life_timer_.Start();
}

void TeamCredits::Clean() {
	cout << "|-->CreditsState::Clean() Invoked" << endl;

	RenderingEngine::DestroyTexture(ptr_background_texture_);
}

// Handles the main menu's button's events
void TeamCredits::HandleEvents(SDL_Event* event) {
	switch (event->type) {
		case SDL_MOUSEBUTTONDOWN:
			if (event->button.button == SDL_BUTTON_LEFT || event->button.button == SDL_BUTTON_RIGHT) {
				cout << "|--> Mouse Click(" << event->button.x << ", " << event->button.y << ") | Current State: Main Menu State" << endl;
				GameStateManager::setCurrentState(GAMESTATE_MAINMENU);
			}
			break;

		case SDL_KEYDOWN:
			// Change States when Escape is pressed
			if (event->key.keysym.sym == SDLK_RETURN || event->key.keysym.sym == SDLK_KP_ENTER) {
				GameStateManager::setCurrentState(GAMESTATE_MAINMENU);
			}
			break;
	}
}

// Checks to see if either of the buttons have been clicked.
// If so the current game state is changed.
void TeamCredits::Update(WindowManager* w) {
	if ((state_life_timer_.getTicks() / 1000.f) >= 3) {
		GameStateManager::setCurrentState(GAMESTATE_MAINMENU);
	}
}

// All Draw Operations for the main menu state are performed here. Everything
// drawn within this method is drawn to the RenderingEngine's scene_property.
void TeamCredits::Render(WindowManager* w) {
// Background Fill

	// Set the Renderer Color to desired value for drawing the background.
	SDL_SetRenderDrawColor(w->getRenderer(), 80, 20, 163, 255);

	// Define the x and even y as well as width and height properties of the
	// background image.
	SDL_Rect bgRect = {0, 0, w->getWidth(), w->getHeight()};

	// Paint the area defined by bgRect to the Scene2D object within
	// RenderingEngine
	SDL_RenderFillRect(w->getRenderer(), &bgRect);

	// Draw the ptr_background_texture_image to the Scene2D object within RenderingEngine
	RenderingEngine::DrawTexture(w->getRenderer(), ptr_background_texture_, 0, 0);
}