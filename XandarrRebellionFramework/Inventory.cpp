#include "Inventory.h"

void Inventory::Init(SDL_Renderer* r) {
	invBox_.LoadTexture(r, SPRITE_LOCATION);
	invBox_.alpha(150);
	invBox_.x(0);
	invBox_.y(460);
	invBox_.scaleX(2.7);

	invBox_.visible(false);
}

void Inventory::HandleEvents(SDL_Event* event, Player* player_) {
	//check if mouse is within the item in the enventory AND clicked (the event passed is mouse click)

	vector<Item *>::iterator invIter = inventory_space_.begin();

	for (; invIter != inventory_space_.end(); invIter++) {
		if ((*invIter)->getVisible() && (event->motion.x >= (*invIter)->getXPos() && event->motion.x <= ((*invIter)->getXPos() + (*invIter)->getWidth())) && (event->motion.y >= (*invIter)->getYPos() && event->motion.y <= ((*invIter)->getYPos() + (*invIter)->getHeight()))) {
			cout << "Player is healed " << (*invIter)->heal() << " health!\n";

			player_->setCurrentHealth(player_->getCurrentHealth() + (*invIter)->heal());
			(*invIter)->setVisible(false);
			removeItem((*invIter)->name());
		}
	}

	/*
	if ((itemPic1_.visible()) && (event->motion.x >= itemPic1_.x() && event->motion.x <= (itemPic1_.x() + itemPic1_.width())) && (event->motion.y >= itemPic1_.y() && event->motion.y <= (itemPic1_.y() + itemPic1_.height()))) {
		//when clicked, the player uses potion1

		//////////////////////////////
		// PROBLEM!!!!!
		// Object properties are NOT passed when adding object to inventory! D:
		// This means that the heal() and name() functions for a potion do NOT have values!
		//////////////////////////////

		cout << inventory_space_.at(0)->heal() << endl;

		//player_->setCurrentHealth(player_->getCurrentHealth() + inventory_space_.at(0)->heal());
		//removeItem(inventory_space_.at(0)->name());
		itemPic1_.visible(false);
	} else if ((itemPic2_.visible()) && (event->motion.x >= itemPic2_.x() && event->motion.x <= (itemPic2_.x() + itemPic2_.width())) && (event->motion.y >= itemPic2_.y() && event->motion.y <= (itemPic2_.y() + itemPic2_.height()))) {
		//when clicked, the player uses potion2
	} else if ((itemPic3_.visible()) && (event->motion.x >= itemPic3_.x() && event->motion.x <= (itemPic3_.x() + itemPic3_.width())) && (event->motion.y >= itemPic3_.y() && event->motion.y <= (itemPic3_.y() + itemPic3_.height()))) {
		//when clicked, the player uses potion3
	} else if ((itemPic4_.visible()) && (event->motion.x >= itemPic4_.x() && event->motion.x <= (itemPic4_.x() + itemPic4_.width())) && (event->motion.y >= itemPic4_.y() && event->motion.y <= (itemPic4_.y() + itemPic4_.height()))) {
		//when clicked, the player uses potion4
	} else if ((itemPic5_.visible()) && (event->motion.x >= itemPic5_.x() && event->motion.x <= (itemPic5_.x() + itemPic5_.width())) && (event->motion.y >= itemPic5_.y() && event->motion.y <= (itemPic5_.y() + itemPic5_.height()))) {
		//when clicked, the player uses potion5
	} else if ((itemPic6_.visible()) && (event->motion.x >= itemPic6_.x() && event->motion.x <= (itemPic6_.x() + itemPic6_.width())) && (event->motion.y >= itemPic6_.y() && event->motion.y <= (itemPic6_.y() + itemPic6_.height()))) {
		//when clicked, the player uses potion6
	}
	*/

}

void Inventory::Update(WindowManager* w) {

}

void Inventory::Render(WindowManager* w) {
	invBox_.Draw(w->getRenderer());
}

void Inventory::addItem(Item* newItem) {
	current_weight_ += newItem->weight();

	bool uniqueItem = true;

	vector<Item *>::iterator invIter = inventory_space_.begin();

	if (newItem->isStackable() == true && !inventory_space_.empty()) {
		for (; invIter != inventory_space_.end(); invIter++) {
			if (newItem->name() == (*invIter)->name() && !(*invIter)->isFull()) {
				(*invIter)->stackSize((*invIter)->stackSize() + 1);
				uniqueItem = false;
				break;
			}
		}
	}

	if (uniqueItem == true || newItem->isStackable() == false) {
		inventory_space_.push_back(newItem);
	}
}

void Inventory::clearInventory() {
	inventory_space_.erase(inventory_space_.begin(), inventory_space_.end());
}

void Inventory::removeItem(string itemName) {
	int j = 0;
	bool fullRemove = true;
	vector<Item *> tmpInv(inventory_space_.size() - 1);
	vector<Item *>::iterator invIter;

	for (invIter = inventory_space_.begin(); invIter != inventory_space_.end(); invIter++) {
		if (itemName == (*invIter)->name()) {
			current_weight_ -= (*invIter)->weight();

			if ((*invIter)->isStackable() == true && (*invIter)->stackSize() > 1) {
				fullRemove = false;
				(*invIter)->stackSize((*invIter)->stackSize() - 1);
			} else {
				delete *invIter;
				*invIter = nullptr;
			}

			break;
		}
	}

	if (fullRemove == true) {
		for (invIter = inventory_space_.begin(); invIter != inventory_space_.end(); invIter++) {
			if (*invIter != nullptr) {
				tmpInv.at(j) = *invIter;
				j++;
			}
		}

		inventory_space_.clear();

		inventory_space_ = vector<Item *>(tmpInv);
	}
}

void Inventory::printInventory(WindowManager* w) {
	vector<Item *>::iterator invIter = inventory_space_.begin();

	unsigned short invItemX = invBox_.x() + 10;
	unsigned short invItemY = invBox_.y() + 20;

	if (invBox_.visible()) {
		invBox_.visible(false);
	} else {
		invBox_.visible(true);
	}

		for (; invIter != inventory_space_.end(); invIter++) {
			/*
			if ((*invIter)->isStackable() == false) {
				(*invIter)->printInfo();
			} else {
				(*invIter)->printInfo();
			}
			*/

			(*invIter)->setXPos(invItemX);
			(*invIter)->setYPos(invItemY);

			if (invBox_.visible()) {
				(*invIter)->setVisible(true);
			} else {
				(*invIter)->setVisible(false);
			}

			invItemX += 60;
		}
}

bool Inventory::isFull() const {
	if (current_weight_ >= capacity_) {
		return true;
	} else {
		return false;
	}
}