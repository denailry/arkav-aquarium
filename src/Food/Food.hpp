#ifndef FOOD_HPP
#define FOOD_HPP

#include "../Item/Item.hpp"

class Food : public Item {
	public:
		Food(int x, int y, int width, int height);
		void tick(int delay);
};

#endif