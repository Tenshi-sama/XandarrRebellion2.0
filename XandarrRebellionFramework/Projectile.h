#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Weapon.h"

class Projectile : public Weapon
{
private:
	unsigned short reload_;
	unsigned short range_;

public:
	Projectile() {}
	Projectile::~Projectile() {}
};

#endif