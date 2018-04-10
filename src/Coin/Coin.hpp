#ifndef COIN_HPP
#define COIN_HPP

#include "../Item/Item.hpp"

class Coin : public Item {
	public:
		Coin(int x, int y, int width, int height, int nilai);
		int getValue(); //mendapatkan nilai koin
		void tick(int delay);
	private:
		int value; //nilai koin
};

#endif