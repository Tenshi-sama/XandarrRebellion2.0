#include "LoadingState.h"

// Loads the loading screen's background image resource and starts the timer
// object, which is used to simulate this 'Loading' state. Once a certain
// amount of time has passed, as dictated by state_life_timer_, this state
// will move on to the next state.
void LoadingState::Init(WindowManager* w) {
	cout << "|-->story1State::Init() Invoked" << endl;

	ptr_background_texture_ = RenderingEngine::LoadTexture(w->getRenderer(), "_resources\\storyScreen.png");
	ptr_credits_texture_ = RenderingEngine::LoadTexture(w->getRenderer(), "_resources\\creditsTeamScreen.png");

	state_life_timer_.Start();
}

// Cleans the object in preparation for safe destruction of object.
void LoadingState::Clean() {
	cout << "|-->story1State::Clean() Invoked" << endl;

	RenderingEngine::DestroyTexture(ptr_background_texture_);
	RenderingEngine::DestroyTexture(ptr_credits_texture_);
}

// Handles events for the loading state
void LoadingState::HandleEvents(SDL_Event* event) {
	switch (event->type) {
		case SDL_MOUSEBUTTONDOWN:
			if (event->button.button == SDL_BUTTON_LEFT || event->button.button == SDL_BUTTON_RIGHT) {
				cout << " | Current State: story1State" << endl;
				GameStateManager::setCurrentState(GAMESTATE_TEAM);
			}
			break;

		case SDL_KEYDOWN:
			// Change States when Escape is pressed
			if (event->key.keysym.sym == SDLK_RETURN || event->key.keysym.sym == SDLK_KP_ENTER) {
				GameStateManager::setCurrentState(GAMESTATE_TEAM);
			}
			break;
	}
}

// Update method for the loading state, checks to see if enough seconds have
// passed since the timer object started. If it has then the current gamestate
// is changed to GAMESTATE_MAINMENU.
void LoadingState::Update(WindowManager* w) {
	if ((state_life_timer_.getTicks() / 1000.f) >= 10) {
		/*
		// Creates a 2D rendering context for a window.
		sdl_renderer *renderer;

		ttf_font* font = ttf_openfont( "_resources\\showg.ttf", 36 );
		sdl_color textcolor = { 0, 0, 0 }; // rgb value for black

		story_text_.createtexturefromtext(renderer, "a game by", font, textcolor); 
		*/
		GameStateManager::setCurrentState(GAMESTATE_TEAM);

		//RenderingEngine::DrawTexture(w->getRenderer(), ptr_credits_texture_, 0, 0);
		/*
		if ((state_life_timer_.getTicks() / 1000.f) >= 3) {
			GameStateManager::setCurrentState(GAMESTATE_MAINMENU);
		}*/
	}
}

// All Draw operations for the loading state are performed here. Everything
// draw within this method is drawn to the RenderingEngine's scene_property.
void LoadingState::Render(WindowManager* w) {
// Background Fill

	// Set the Renderer Colour to desired value for drawing the background.
	SDL_SetRenderDrawColor(w->getRenderer(), 80, 20, 162, 255);

	// Define the x and y as well as width and height properties of the
	// background image.
	SDL_Rect bgRect = {0, 0, w->getWidth(), w->getHeight()};

	// Paint the area defined by bgRect to the Scene2D object within
	// RenderingEngine
	SDL_RenderFillRect(w->getRenderer(), & bgRect);

// Draw the loading tex

	// Draw the ptr_background_texture_image to the Scene2D object within RenderingEngine
	RenderingEngine::DrawTexture(w->getRenderer(), ptr_background_texture_, 0, 0);
}