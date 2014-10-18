#ifndef ENERGY_H
#define ENERGY_H

#include "Weapon.h"

class Energy : public Weapon
{
private:
	unsigned short cool_down_;
	unsigned short range_;

public:
	Energy() {}
	Energy::~Energy() {}
};

#endif