#ifndef HITBOX_H
#define HITBOX_H

#include "Window.h"
#include <iostream>
#include "Texture.h"

class HitBox {
protected:
	static const int WIDTH = 32;
	static const int HEIGHT = 32;
	int x_, y_;
	string type_;

	Texture hitbox_;

public:
	HitBox() { cout << "I'm initialized" << endl; }
	~HitBox(){};

	inline int getXPos() { return x_; }
	inline int getYPos() { return y_; }
	inline int getWidth() { return WIDTH; }
	inline int getHeight() { return HEIGHT; }
	inline string& getType() { return type_; }
	inline Texture* getTexture() { return &hitbox_; }

	inline void setXPos(const int newValue) { x_ = newValue; }
	inline void setYPos(const int newValue) { y_ = newValue; }
	inline void setType(const string& newValue) { type_ = newValue; }
};

#endif