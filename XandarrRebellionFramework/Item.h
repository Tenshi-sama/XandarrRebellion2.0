#ifndef ITEM_H
#define ITEM_H

#include "Texture.h"
#include "Window.h"

#include <iostream>
#include <string>

using namespace std;

class Item
{
protected:
	Texture sprite_;
	const string SPRITE_LOCATION;
	
	string name_;
	string description_;
	unsigned int worth_;
	unsigned short weight_;
	unsigned short stack_size_;
	unsigned short max_stack_size_;
	unsigned short heal_;
	unsigned short damage_;
	

public:
	Item() : SPRITE_LOCATION("_resources\\potion3.png") {}
	~Item() { sprite_.~Texture(); }

	void Init(SDL_Renderer* r);
	void HandleEvents(SDL_Event* event);
	void Update(WindowManager* w);
	void Render(WindowManager* w);

	
	inline int getXPos() { return sprite_.x(); }
	inline int getYPos() { return sprite_.y(); }
	inline int getWidth() { return sprite_.width(); }
	inline int getHeight() { return sprite_.height(); }

	inline void setXPos(const int newValue) { sprite_.x(newValue); }
	inline void setYPos(const int newValue) { sprite_.y(newValue); }

	inline void setVisible(bool newValue) { sprite_.visible(newValue); }
	//inline void notVisible() { return sprite_.visible(false); }
	inline bool getVisible() { return sprite_.visible(); }
	
	inline bool isFull() const { return (max_stack_size_ - stack_size_ == 0); }
	inline bool isStackable() const { return (max_stack_size_ > 1); }
	inline string& name() { return name_; }
	inline unsigned int worth() const { return worth_; }
	inline unsigned short weight() const { return weight_; }
	inline unsigned short stackSize() const { return stack_size_; }
	inline const string& description() const { return description_; }
	inline unsigned short maxStackSize() const { return max_stack_size_; }
	inline unsigned short heal() const { return heal_; }
	inline unsigned short damage() const { return damage_; }
	
	inline void name(const string& newValue) { name_ = newValue; }
	inline void description(const string& newValue) { description_ = newValue; }
	inline void worth(const unsigned int newValue) { worth_ = newValue; }
	inline void weight(const unsigned short newValue) { weight_ = newValue; }
	inline void stackSize(const unsigned short newValue) { stack_size_ = newValue; }
	inline void maxStackSize(const unsigned short newValue) { max_stack_size_ = newValue; }
	inline void heal(const unsigned short newValue) { heal_ = newValue; }
	inline void damage(const unsigned short newValue) { damage_ = newValue; }
	
	virtual void printInfo() {}
	
};

#endif