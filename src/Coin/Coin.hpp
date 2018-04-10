#ifndef COIN_HPP
#define COIN_HPP

#include "../Item/Item.hpp"

class Coin : public Item {
	public:
		Coin(double x, double y, double width, double height, int nilai);
		int getValue(); //mendapatkan nilai koin
		void tick(double delay);
	private:
		int value; //nilai koin
};

#endif