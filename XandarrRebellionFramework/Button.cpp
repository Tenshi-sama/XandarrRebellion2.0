#include "Button.h"

// Attempts to load Button font external resource, on success the Button
// texture is generated and it's bounding box filled with the appropriate
// values. On failure of trying to load the Button font an error message
// is displayed which invokes SDL_GetError() for optimum error reporting.
Button::Button(SDL_Renderer* r, const string& label, SDL_Color& textColor, const Uint8 fontSize) : ptr_font_(nullptr),  // Pointer to the Button object's font
	current_state_(NORMAL) {	// Tracks the current ButtonState
		// Try and load font first, in event of failure...
		ptr_font_ = TTF_OpenFont("_resources/TPBAFK-Regular.otf", fontSize);

		if (ptr_font_ == nullptr) {
			cout << "Error @ TTF INIT" << SDL_GetError() << endl;
		}

		// Generate texture from string
		label_texbb_.tex = RenderingEngine::CreateTextureFromString(r, label, textColor, ptr_font_);

		// Fill the values of label_texbb's bounding box
		GenerateBoundingBox(label_texbb_);
}

Button::~Button() {
	TTF_CloseFont(ptr_font_);
	ptr_font_ = nullptr;
}

// Listens for SDL_MOUSEMOTION, SDL_MOUSEBUTTONDOWN and SDL_MOUSEBUTTONUP
// events only. Based on the processed event the Button's state may change.
void Button::HandleEvents(SDL_Event* event) {
	if (current_state_ != NORMAL) {
		current_state_ = NORMAL;
	}

	switch (event->type) {
		case SDL_MOUSEMOTION:
			// onHover
			if (isInsideRect(label_texbb_.dimensions, event->motion.x, event->motion.y)) {
				current_state_ = HOVERING;
			}

			break;

		case SDL_MOUSEBUTTONDOWN:
			// onClick
			if (isInsideRect(label_texbb_.dimensions, event->button.x, event->button.y)) {
				current_state_ = CLICKED;
#ifndef DEBUG
				cout << "Button Clicked" << endl;
#endif
			}

			break;

		case SDL_MOUSEBUTTONUP:
			// onRelease
			if (isInsideRect(label_texbb_.dimensions, event->button.x, event->button.y)) {
				current_state_ = RELEASED;
#ifndef DEBUG
				cout << "Button Released" << endl;
#endif
			}
	}
}

// Uses SDL_QueryTexture method to determine the width and height of the 
// texture. All Button objects, by default, are initialized to the
// position of (0, 0).
void Button::GenerateBoundingBox(TextureBB& texbb) {
	int w, h;
	SDL_QueryTexture(texbb.tex, NULL, NULL, &w, &h);

	label_texbb_.dimensions.x = 0;	// X Position on Screen
	label_texbb_.dimensions.y = 0;	// Y Position on Screen
	label_texbb_.dimensions.w = w;	// Width of Texture
	label_texbb_.dimensions.h = h;	// Height of Texture
}

// Determines if a given 2D point (x, y) falls within the specified rectangle
// For Example:
//		Given a rectangle with a position of (0, 0) and widht and height of 50.
//		And given a point with the position of (15, 25). If 15 is greater than 0
//		and 15 is less than 0+50 and 25 is greater than 0 and 25 is less than
//		0+50 - our point is inside the rectangle.
bool Button::isInsideRect(const SDL_Rect& rect, const int x, const int y) const {
	if (x > rect.x && x < rect.x + rect.w && y > rect.y && y < rect.y + rect.h) {
		return true;
	} else {
		return false;
	}
}