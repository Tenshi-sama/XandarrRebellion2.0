#include "Window.h"

// Initializes member variables to initial values. Does NOT create the Window
// or Renderer.
WindowManager::WindowManager() {
	ptr_app_window_ = nullptr;
	ptr_renderer_ = nullptr;

	is_mouse_focused_ = false;
	is_keyboard_focused_ = false;
	is_fullscreen_ = false;
	width_ = 800;
	height_ = 544;
}

WindowManager::~WindowManager() {
	SDL_DestroyRenderer(ptr_renderer_);
	SDL_DestroyWindow(ptr_app_window_);

	is_mouse_focused_ = false;
	is_keyboard_focused_ = false;
	is_fullscreen_ = false;
	width_ = 0;
	height_ = 0;
}

// Creates the window context for SDL and the 2D rendering
// context for the window. Also responsible for setting renderer
// scale quality.
bool WindowManager::Init() {
	// Creates an application window for SDL.
	ptr_app_window_ = SDL_CreateWindow(
		"XANDARR REBELLION",		// Window Title (UTF-8 encoding)
		25,		// Initial X position of window
		40,		// Initial Y position of window
		width_,		// Window's width, in pixels
		height_,	// Window's height, in pixels
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);	// Flags

	// nullptr check
	if (!ptr_app_window_) {
		cout << "Error Trying to Create Window!" << SDL_GetError() << endl;
	} else {
		is_mouse_focused_ = true;
		is_keyboard_focused_ = true;
	}

	// Creates a 2D rendering context for a window.
	ptr_renderer_ = SDL_CreateRenderer(
		ptr_app_window_,	// The Window
		-1,		// The index calue of the rendering driver to initialize, or -1 to initialize the first one supporting the requested flags
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);	 //Flags

	// nullptr check
	if (!ptr_renderer_) {
		cout << "Error Trying to Create Renderer!" << SDL_GetError() << endl;
		return false;
	}

	// Smoothed scaled rendering
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	return true;
}

// Handles all SDL_WINDOWEVENT events
void WindowManager::HandleEvents(SDL_Event* event) {
	if (event->type == SDL_WINDOWEVENT) {
		switch (event->window.event) {
			// Get new dimensions and repoint on window size change
		case SDL_WINDOWEVENT_SIZE_CHANGED:
			width_ = event->window.data1;
			height_ = event->window.data2;
			SDL_RenderPresent(ptr_renderer_);
			break;

			// Repaint on exposure
		case SDL_WINDOWEVENT_EXPOSED:
			SDL_RenderPresent(ptr_renderer_);
			break;

			// Mouse entered window
		case SDL_WINDOWEVENT_ENTER:
			is_mouse_focused_ = true;
			break;

			// Mouse left window
		case SDL_WINDOWEVENT_LEAVE:
			is_mouse_focused_ = false;
			break;

			// Window has keyboard focus
		case SDL_WINDOWEVENT_FOCUS_GAINED:
			is_keyboard_focused_ = true;
			break;

			// Window lost keyboard focus
		case SDL_WINDOWEVENT_FOCUS_LOST:
			is_keyboard_focused_ = false;
			break;
		}
	}

	if (event->type == SDL_KEYDOWN) {
		if (event->key.keysym.sym == SDLK_f) {
			cout << "isFullscreen is: " << isFullscreen() << endl;
			if (isFullscreen()) {
				isFullscreen(false);
				cout << "isFullscreen is: " << isFullscreen() << endl;
			} else {
				isFullscreen(true);
				cout << "isFullscreen is: " << isFullscreen() << endl;
				SDL_WINDOW_FULLSCREEN;
			}
		}
	}
}