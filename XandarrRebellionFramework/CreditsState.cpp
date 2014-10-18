#include "CreditsState.h"

// Creates and loads the main menu's buttons
void CreditsState::Init(WindowManager* w) {
	cout << "|-->CreditsState::Init() Invoked" << endl;

	ptr_background_texture_ = RenderingEngine::LoadTexture(w->getRenderer(), "_resources\\creditsTeamScreen.png");

	string str = "Back";
	string str2 = "Exit";

	SDL_Color button_text_color = {255, 0, 0, 255};

	// Stores the x-axis value of tex's centre point
	int center_x_of_texture;

	// *Round down (so we end up with a whole number then explicitly converts
	// value to integer so there is no data loss. Failing to do so will result
	// in lost data (through the implicit conversion of double to int)
	int center_x_of_window = (int)floor(w->getWidth() * 0.5);	//*
	int window_height_one_eighth = (int)floor(w->getHeight() * 0.125);	//*
	
	main_menu_btn_ = new Button(w->getRenderer(), str, button_text_color);
	center_x_of_texture = (int)floor(main_menu_btn_->getBoundingBox().w * 0.5); //*
	main_menu_btn_->setPosition(0 + center_x_of_texture, window_height_one_eighth * 6);
	
	quit_game_btn_ = new Button(w->getRenderer(), str2, button_text_color);
	center_x_of_texture = (int)floor(quit_game_btn_->getBoundingBox().w * 0.5); //*
	quit_game_btn_->setPosition(center_x_of_window - center_x_of_texture, window_height_one_eighth * 6);
}

void CreditsState::Clean() {
	cout << "|-->CreditsState::Clean() Invoked" << endl;

	RenderingEngine::DestroyTexture(ptr_background_texture_);

	delete main_menu_btn_;
	delete quit_game_btn_;
}

// Handles the main menu's button's events
void CreditsState::HandleEvents(SDL_Event* event) {
	// Event Handler for main_menu_btn_
	main_menu_btn_->HandleEvents(event);

	// Event Handler for quit_game_btn_
	quit_game_btn_->HandleEvents(event);

	switch (event->type) {
		case SDL_MOUSEBUTTONDOWN:
			if (event->button.button == SDL_BUTTON_LEFT || event->button.button == SDL_BUTTON_RIGHT) {
				cout << "|--> Mouse Click(" << event->button.x << ", " << event->button.y << ") | Current State: Main Menu State" << endl;
			}
			break;

		case SDL_KEYDOWN:
			// Change States when Escape is pressed
			if (event->key.keysym.sym == SDLK_ESCAPE) {
				GameStateManager::setCurrentState(GAMESTATE_MAINMENU);
			}
			break;
	}
}

// Checks to see if either of the buttons have been clicked.
// If so the current game state is changed.
void CreditsState::Update(WindowManager* w) {
	if (main_menu_btn_->getState() == CLICKED) {
		GameStateManager::setCurrentState(GAMESTATE_MAINMENU);
		return;
	}

	if (quit_game_btn_->getState() == CLICKED) {
		GameStateManager::setCurrentState(GAMESTATE_TERMINATE);
	}
}

// All Draw Operations for the main menu state are performed here. Everything
// drawn within this method is drawn to the RenderingEngine's scene_property.
void CreditsState::Render(WindowManager* w) {
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

	// Buttons
	RenderingEngine::DrawTexture(w->getRenderer(), main_menu_btn_->getTexture(), main_menu_btn_->getBoundingBox().x, main_menu_btn_->getBoundingBox().y);
	RenderingEngine::DrawTexture(w->getRenderer(), quit_game_btn_->getTexture(), quit_game_btn_->getBoundingBox().x, quit_game_btn_->getBoundingBox().y);
}