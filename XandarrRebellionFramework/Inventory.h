#ifndef INVENTORY_H
#define INVENTORY_H

#include "Texture.h"
#include "Window.h"

#include "Item.h"
#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Inventory {
private:
	unsigned short current_weight_;
	unsigned short capacity_;
	vector<Item *> inventory_space_;
	const string SPRITE_LOCATION;

	Texture invBox_;

	const string SPRITE_PIC1;
	//const string SPRITE_PIC2;
	//const string SPRITE_PIC3;
	//const string SPRITE_PIC4;
	//const string SPRITE_PIC5;
	//const string SPRITE_PIC6;

	Texture itemPic1_;
	Texture itemPic2_;
	Texture itemPic3_;
	Texture itemPic4_;
	Texture itemPic5_;
	Texture itemPic6_;
	int textXPos, textYPos;

public:
	Inventory() : capacity_(100), current_weight_(0), SPRITE_LOCATION("_resources\\blank.png"), SPRITE_PIC1("_resources\\potion3.png") {};
	~Inventory() {};

	void Init(SDL_Renderer* r);
	void HandleEvents(SDL_Event* event);
	void Update(WindowManager* w);
	void Render(WindowManager* w);

	void addItem(Item newItem);
	void removeItem(string);
	bool isFull() const;

	inline unsigned short getCurrentWeight() const { return current_weight_; }
	inline unsigned short getCapacity() const { return capacity_; }
	//inline Texture* getTexture() { return &invBox_; }

	inline void Inventory::setCapacity(const unsigned short newValue) { capacity_ = newValue; }
	inline void Inventory::setCurrentWeight(const unsigned short newValue) { current_weight_ = newValue; }

	void printInventory();
	void clearInventory();
};

#endif