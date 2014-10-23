#ifndef SRC_FRAMEWORK_BUTTON_H
#define SRC_FRAMEWORK_BUTTON_H

#include "RenderingEngine.h"
#include "RenderTarget.h"

// Convenient enumeration type used to represent the current state of the
// Buttom object. There are a total of four possible states for a button.
enum ButtonState {
	// NORMAL is the active state if the conditions for HOVERING, CLICKED
	// and RELEASED are not met.
	NORMAL = 0,

	// HOVERING is the active state when the mouse cursor's (x, y) position
	// is within the Button's bounding box.
	HOVERING,

	// CLICKED is the active state when the mouse cursor's (x, y) position
	// is within the Button's bounding box during an SDL_MOUSEBUTTONDOWN event.
	CLICKED,

	// RELEASED is the active state when the mouse cursor's (x, y) position
	// is within the Button's bounding box during and SDL_MOUSEBUTTONUP event.
	// typically the RELEASED state follows the CLICKED state.
	RELEASED
};

// The Button object is a simple Graphical User Interface (GUI) component.
class Button {
	//======================//
	//		Properties		//
	//======================//
private:
	// Pointer to the Button object's font, used to convert text into an SDL_Texture
	TTF_Font* ptr_font_;

	// A struct with a pointer to an SDL_Texture and a pointer to an SDL_Rect
	// which serves as the texture bounding box.
	TextureBB label_texbb_;

	// Stores the current ButtonState (NORMAL, HOVERING, CLICKED, RELEASED)
	ButtonState current_state_;

	//======================//
	//		Behaviours		//
	//======================//

	// Fills in the appropriate vlaues for the textures bounding box.
	//		@param texbb Is a struct composed of a pointer to the SDL_Texture to
	//		generate a bounding box for as well as an SDL_Rect used store the
	//		bounding box data.
	void GenerateBoundingBox(TextureBB& texbb);

	// Determines if a given 2D point (x, y) falls within the specified rectangle
	//		@param rect The rectangle to perform the comparison against
	//		@param x The position of the point to test on the x-axis
	//		@param y The position of the point to text on the y-axis
	//		@return true IF the x and y fall within rect
	//		@return false IF the x and y do NOT fall within rect
	bool isInsideRect(const SDL_Rect& rect, const int x, const int y) const;

public:
	// Default Constuctor
	Button() : ptr_font_(nullptr), current_state_(NORMAL) {}

	// Generates a TextureBB object to store the Button object's image and
	// bounding box.
	//		@param r Pointer to the renderer
	//		@param label The string sequence to converted
	//		@param fontSize Defines the size of the font used
	Button(SDL_Renderer* r, const string& label, SDL_Color& textColor, const Uint8 fontSize = 42);

	~Button();

	// Handles events for the object
	//		@param event The game's event struct which holds the current SDL_Event to
	//		be processed.
	void HandleEvents(SDL_Event* event);

	// Accessor method for Button object's texture
	//		@return lable_texbb.tex Pointer to an SDL_Texture object
	inline SDL_Texture* getTexture() const { return label_texbb_.tex; }

	// Accessor method for _pLabelTex.dimensions
	//		@return label_texbb.dimensions An SDL_Rect representing the bounding
	//		box for the Button.
	inline SDL_Rect getBoundingBox() const { return label_texbb_.dimensions; }

	// Accessor method for _currentState
	inline ButtonState getState() const { return current_state_; }

	// Mutator for label_texbb_dimensions->x & label_texbb_.dimensions->y
	//		@param x Value representing object's position on screen's x-axis
	//		@param y Value representing object's position on screen's y-axis
	inline void setPosition(const int x, const int y) {
		label_texbb_.dimensions.x = x;
		label_texbb_.dimensions.y = y;
	}
};

#endif