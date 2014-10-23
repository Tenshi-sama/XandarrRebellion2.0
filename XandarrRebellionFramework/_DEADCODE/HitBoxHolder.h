#ifndef HITBOXHOLDER_H
#define HITBOXHOLDER_H

#include "Window.h"
#include "HitBox.h"

#include <iostream>
#include <vector>

using std::vector;

class HitBoxHolder {
private:
	vector<HitBox*> hitboxes_;

public:
	HitBoxHolder() {}
	~HitBoxHolder() {}
	

	void addHitBox(HitBox &newHitBox);

};

#endif

void HitBoxHolder::addHitBox(HitBox &newHitBox) {
	hitboxes_.push_back(&newHitBox);
}