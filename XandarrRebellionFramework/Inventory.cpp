#include "Inventory.h"

void Inventory::Init(SDL_Renderer* r) {
	invBox_.LoadTexture(r, SPRITE_LOCATION);
	invBox_.alpha(150);
	invBox_.x(0);
	invBox_.y(460);
	invBox_.scaleX(2.7);

	itemPic1_.LoadTexture(r, SPRITE_PIC1);
	itemPic1_.x(10);
	itemPic1_.y(465);

	itemPic2_.LoadTexture(r, SPRITE_PIC1);
	itemPic2_.x(10);
	itemPic2_.y(500);

	itemPic3_.LoadTexture(r, SPRITE_PIC1);
	itemPic3_.x(70);
	itemPic3_.y(465);

	itemPic4_.LoadTexture(r, SPRITE_PIC1);
	itemPic4_.x(70);
	itemPic4_.y(500);

	itemPic5_.LoadTexture(r, SPRITE_PIC1);
	itemPic5_.x(130);
	itemPic5_.y(465);

	itemPic6_.LoadTexture(r, SPRITE_PIC1);
	itemPic6_.x(130);
	itemPic6_.y(500);

	itemPic1_.visible(false);
	itemPic2_.visible(false);
	itemPic3_.visible(false);
	itemPic4_.visible(false);
	itemPic5_.visible(false);
	itemPic6_.visible(false);

	invBox_.visible(false);
}

void Inventory::HandleEvents(SDL_Event* event) {
	//check if mouse is within the item in the enventory AND clicked (the event passed is mouse click)
	if ((itemPic1_.visible()) && (event->motion.x >= itemPic1_.x() && event->motion.x <= (itemPic1_.x() + itemPic1_.width())) && (event->motion.y >= itemPic1_.y() && event->motion.y <= (itemPic1_.y() + itemPic1_.height()))) {
		//when clicked, the player uses potion1
	}

}

void Inventory::Update(WindowManager* w) {

}

void Inventory::Render(WindowManager* w) {
	invBox_.Draw(w->getRenderer());

	itemPic1_.Draw(w->getRenderer());
	itemPic2_.Draw(w->getRenderer());
	itemPic3_.Draw(w->getRenderer());
	itemPic4_.Draw(w->getRenderer());
	itemPic5_.Draw(w->getRenderer());
	itemPic6_.Draw(w->getRenderer());
}

void Inventory::addItem(Item newItem) {
	current_weight_ += newItem.weight();

	bool uniqueItem = true;

	vector<Item *>::iterator invIter = inventory_space_.begin();

	if (newItem.isStackable() == true && !inventory_space_.empty()) {
		for (; invIter != inventory_space_.end(); invIter++) {
			if (newItem.name() == (*invIter)->name() && !(*invIter)->isFull()) {
				(*invIter)->stackSize((*invIter)->stackSize() + 1);
				uniqueItem = false;
				break;
			}
		}
	}

	if (uniqueItem == true || newItem.isStackable() == false) {
		inventory_space_.push_back(&newItem);
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

void Inventory::printInventory() {
	vector<Item *>::iterator invIter = inventory_space_.begin();
	unsigned short runs = 0;

		for (; invIter != inventory_space_.end(); invIter++) {
			/*
			if ((*invIter)->isStackable() == false) {
				(*invIter)->printInfo();
			} else {
				(*invIter)->printInfo();
			}
			*/

			if (runs == 0) {
				itemPic1_.visible(true);
			} else if (runs == 1) {
				itemPic2_.visible(true);
			} else if (runs == 2) {
				itemPic3_.visible(true);
			} else if (runs == 3) {
				itemPic4_.visible(true);
			} else if (runs == 4) {
				itemPic5_.visible(true);
			} else if (runs == 5) {
				itemPic6_.visible(true);
			}
			
			runs++;
		}

		if (invBox_.visible()) {
			invBox_.visible(false);
			itemPic1_.visible(false);
			itemPic2_.visible(false);
			itemPic3_.visible(false);
			itemPic4_.visible(false);
			itemPic5_.visible(false);
			itemPic6_.visible(false);
		} else {
			invBox_.visible(true);
		}
}

bool Inventory::isFull() const {
	if (current_weight_ >= capacity_) {
		return true;
	} else {
		return false;
	}
}