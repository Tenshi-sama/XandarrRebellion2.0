#ifndef SRC_FRAMEWORK_SCENE2D_H
#define SRC_FRAMEWORK_SCENE2D_H

#include "SDL.h"

#include <iostream>
#include <string>

using std::string;

// The RenderTarget object utilizes an SDL_Texture created using the
// SDL_TEXTUREACCESS_TARGET flag, allowing the texture to be targeted by the
// renderer.
class RenderTarget {
	//======================//
	//		Properties		//
	//======================//
private:
	// Pointer to SDL_Texture created with the SDL_TEXTUREACCESS_TARGET flag.
	SDL_Texture* ptr_texture_;

	//======================//
	//		Behaviours		//
	//======================//
public:
	RenderTarget() {}
	RenderTarget(SDL_Renderer* r, const int width, const int height);
	~RenderTarget();

	// Tells SDL to set ptr_texture_ as the render target.
	//		@param r Pointer to Renderer
	void AcquireRenderTarget(SDL_Renderer* r);

	// Tells SDL to set the render target back to the default renderer
	//		@param r Pointer to Renderer
	void ReleaseRenderTarget(SDL_Renderer* r);

	// Re-Initialize object; safely destroys and recreates ptr_texture_
	//		@param r Pointer to Renderer
	//	@ param width Width of Window
	//	@ param height Height of Window
	void Reset(SDL_Renderer* r, int width, int height);

	// Accessor Method for Button object's texture
	//		@return ptr_texture_
	inline SDL_Texture* getTexture() const { return ptr_texture_; }
};

#endif