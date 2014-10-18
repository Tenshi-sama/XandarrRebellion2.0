#include "chooseRace.h"

// Loads the loading screen's background image resource and starts the timer
// object, which is used to simulate this 'Loading' state. Once a certain
// amount of time has passed, as dictated by state_life_timer_, this state
// will move on to the next state.
void chooseRace::Init(WindowManager* w) {
	cout << "|-->chooseRace::Init() Invoked" << endl;

	ptr_background_texture_ = RenderingEngine::LoadTexture(w->getRenderer(), "_resources\\chooseRace.png");

	string str = "Xanos";
	string str2 = "Transients";
	string str3 = "Zenturian";
	string str4 = "Human";

	SDL_Color button_text_color = {255, 0, 0, 255};

	// Stores the x-axis value of tex's centre point
	int center_x_of_texture;

	// *Round down (so we end up with a whole number then explicitly converts
	// value to integer so there is no data loss. Failing to do so will result
	// in lost data (through the implicit conversion of double to int)
	int center_x_of_window = (int)floor(w->getWidth() * 0.5);
	int window_height_one_eighth = (int)floor(w->getHeight() * 0.125);
	int window_width_one_fifth = (int)floor(w->getWidth() * 0.2);	

	//xanos button position
	xanos_btn_ = new Button(w->getRenderer(), str, button_text_color);
	center_x_of_texture = (int)floor(xanos_btn_->getBoundingBox().w * 0.5); 
	xanos_btn_->setPosition(window_width_one_fifth*1 - center_x_of_texture, window_height_one_eighth * 4);

	//transient button position
	transient_btn_ = new Button(w->getRenderer(), str2, button_text_color);
	center_x_of_texture = (int)floor(transient_btn_->getBoundingBox().w * 0.5);
	transient_btn_->setPosition(window_width_one_fifth*4 - center_x_of_texture, window_height_one_eighth * 4);

	//zenturian button position
	zenturian_btn_ = new Button(w->getRenderer(), str3, button_text_color);
	center_x_of_texture = (int)floor(zenturian_btn_->getBoundingBox().w * 0.5);
	zenturian_btn_->setPosition(window_width_one_fifth*1 - center_x_of_texture, window_height_one_eighth * 6);

	//human button position
	human_btn_ = new Button(w->getRenderer(), str3, button_text_color);
	center_x_of_texture = (int)floor(human_btn_->getBoundingBox().w * 0.5);
	human_btn_->setPosition(window_width_one_fifth*4 - center_x_of_texture, window_height_one_eighth * 6);
}

// Cleans the object in preparation for safe destruction of object.
void chooseRace::Clean() {
	cout << "|-->chooseRace::Clean() Invoked" << endl;

	delete xanos_btn_;
	delete transient_btn_;
	delete zenturian_btn_;
	delete human_btn_;

	RenderingEngine::DestroyTexture(ptr_background_texture_);
}

// Handles events for the loading state
void chooseRace::HandleEvents(SDL_Event* event) {
	xanos_btn_->HandleEvents(event);
	transient_btn_->HandleEvents(event);
	zenturian_btn_->HandleEvents(event);
	human_btn_->HandleEvents(event);

	switch (event->type) {
		case SDL_MOUSEBUTTONDOWN:
			if (event->button.button == SDL_BUTTON_LEFT || event->button.button == SDL_BUTTON_RIGHT) {
				cout << " | Current State: chooseRace" << endl;
			}
			break;
	}
}

// Update method for the loading state, checks to see if enough seconds have
// passed since the timer object started. If it has then the current gamestate
// is changed to GAMESTATE_MAINMENU.
void chooseRace::Update(WindowManager* w) {
	if (xanos_btn_->getState() == CLICKED || human_btn_->getState() == CLICKED || transient_btn_->getState() == CLICKED || zenturian_btn_->getState() == CLICKED) {
		//Clean();
		cout << "|-->chooseRace::Update() Invoked" << endl;
		GameStateManager::setCurrentState(GAMESTATE_GAMEPLAY);
	}
}

// All Draw operations for the loading state are performed here. Everything
// draw within this method is drawn to the RenderingEngine's scene_property.
void chooseRace::Render(WindowManager* w) {
// Background Fill

	// Set the Renderer Colour to desired value for drawing the background.
	SDL_SetRenderDrawColor(w->getRenderer(), 80, 20, 162, 255);

	// Define the x and y as well as width and height properties of the
	// background image.
	SDL_Rect bgRect = {0, 0, w->getWidth(), w->getHeight()};

	// Paint the area defined by bgRect to the Scene2D object within
	// RenderingEngine
	SDL_RenderFillRect(w->getRenderer(), & bgRect);

	// Buttons
	RenderingEngine::DrawTexture(w->getRenderer(), xanos_btn_->getTexture(), xanos_btn_->getBoundingBox().x, xanos_btn_->getBoundingBox().y);
	RenderingEngine::DrawTexture(w->getRenderer(), transient_btn_->getTexture(), transient_btn_->getBoundingBox().x, transient_btn_->getBoundingBox().y);
	RenderingEngine::DrawTexture(w->getRenderer(), zenturian_btn_->getTexture(), zenturian_btn_->getBoundingBox().x, zenturian_btn_->getBoundingBox().y);
	RenderingEngine::DrawTexture(w->getRenderer(), human_btn_->getTexture(), human_btn_->getBoundingBox().x, human_btn_->getBoundingBox().y);

// Draw the loading tex

	// Draw the ptr_background_texture_image to the Scene2D object within RenderingEngine
	RenderingEngine::DrawTexture(w->getRenderer(), ptr_background_texture_, 0, 0);
}