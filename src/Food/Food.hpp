#ifndef FOOD_HPP
#define FOOD_HPP

#include "../Item/Item.hpp"

class Food : public Item {
	public:
		Food(int x, int y);
		void tick();
};

#endif