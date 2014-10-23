#include "Texture.h"


Texture::Texture() {
	name_ = "";
	alpha_ = 255;
	rotation_point_.x = 0;
	rotation_point_.y = 0;
	rotate_ = 0.0;
	scaleX_ = 1.0f;
	scaleY_ = 1.0f;
	texture_ = nullptr;
	visible_ = true;
	width_ = 0;
	height_ = 0;
	x_ = 0;
	y_ = 0;
}

Texture::Texture(SDL_Renderer* r, const string& imgLocation) {
	name_ = "";
	alpha_ = 255;
	rotation_point_.x = 0;
	rotation_point_.y = 0;
	rotate_ = 0.0;
	scaleX_ = 1.0f;
	scaleY_ = 1.0f;
	texture_ = nullptr;
	visible_ = true;
	width_ = 0;
	height_ = 0;
	x_ = 0;
	y_ = 0;

	// Load Texture object's image data into texture_property
	if (!LoadTexture(r, imgLocation)) {
		// Failure
		cout << "FAAAAAAAAAAAAAAAAAAAAIL!!\n";
	}
}


Texture::~Texture() {
	SDL_DestroyTexture(texture_);
	texture_ = nullptr;
}

bool Texture::LoadTexture(SDL_Renderer* r, const string& imgLocation) {
	texture_ = IMG_LoadTexture(r, imgLocation.c_str());

	if (texture_ == nullptr) {
		// TODO: Handle ERROR
		cout << "@Texture::LoadTexture -- Failed to LoadTexture(" + name_ + "):\n" << SDL_GetError() << endl;
		return false;
	}

	// SDL_QueryTexture is used to query the attributes of a texture
	SDL_QueryTexture(texture_, NULL, NULL, &width_, &height_);

	// Set default point to perform rotations around (centre of texture)
	rotation_point_.x = int(width_ * 0.5f);
	rotation_point_.y = int(height_ * 0.5f);

	return true;
}

void Texture::Draw(SDL_Renderer* r) {
	// visibility check
	if (!visible_) { return; }

	// Destination rectangle
	SDL_Rect dst = { x_, y_, (int)(width_ *scaleX_), (int)(height_ *scaleY_) };

	// Draw texture to renderer
	SDL_RenderCopyEx(r, texture_, NULL, &dst, rotate_, &rotation_point_, SDL_FLIP_NONE);
}

void Texture::alpha(int newValue) {
	// SDL2 alpha channel has valid range of 0 - 255, these checks ensure
	// the passed value adheres to said range
	if (newValue < 0) { newValue = 0; }
	if (newValue > 255) { newValue = 255; }

	// Apply the new alpha value to texture_ and check the return value of the
	// call to ensure the new alpha value has been successfully applied.
	if (SDL_SetTextureAlphaMod(texture_, newValue) < 0) {
		// todo: better error handling/reporting
		// additional note: It is possible for renderer NOT to support alpha modulation at all,
		// ad  additional handle for such situation
		cout << "@Texture::alpha(int newValue) -- SDL_SetTextureAlphaMod call failed:\n" << SDL_GetError() << endl;
	} else {
		alpha_ = newValue;
	}
}

bool Texture::CreateTextureFromText(SDL_Renderer* r, const string& textValue, TTF_Font* textFont, SDL_Color textColor) {
	SDL_Surface* textSurface = TTF_RenderText_Solid(textFont, textValue.c_str(), textColor);

	SDL_Texture* final_texture = nullptr;

	if (textSurface == nullptr) {
		return false;
	} else {
		final_texture = SDL_CreateTextureFromSurface(r, textSurface);

		if(final_texture == nullptr) {
			return false;
		}

		SDL_FreeSurface(textSurface);
	}

	texture_ = final_texture;

	SDL_QueryTexture(texture_, NULL, NULL, &width_, &height_);

	rotation_point_.x = int(width_ * 0.5f);
	rotation_point_.y = int(height_ * 0.5f);

	return true;
}