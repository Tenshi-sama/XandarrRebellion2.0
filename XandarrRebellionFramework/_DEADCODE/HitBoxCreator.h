#ifndef HITBOXCREATOR_H
#define HITBOXCREATOR_H

#include "HitBox.h"
#include <iostream>
#include <string>

using namespace std;

class HitBoxCreator : public HitBox {
private:

public:
	HitBoxCreator() {}
	HitBoxCreator(string type, int x, int y);
	virtual void someFunc() {}
};

#endif

HitBoxCreator::HitBoxCreator(string type, int x, int y) {
	type_ = type;
	x_ = x;
	y_ = y;

	cout << "{" + type + " is created}" << endl;
}