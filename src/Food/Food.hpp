#ifndef FOOD_HPP
#define FOOD_HPP

#include "../Item/Item.hpp"

class Food : public Item {
	public:
		Food(double x, double y, double width, double height);
		void tick(int delay);
};

#endif