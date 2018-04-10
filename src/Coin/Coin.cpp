#include "Coin.hpp"

Coin::Coin(int x, int y, int width, int height, int nilai) : Item(x, y, width, height, TYPE_COIN){
	value = nilai;
}

int Coin::getValue(){ //mendapatkan nilai koin
	return value;
} 

void Coin::tick(int delay) {
	int y = this->getY();
	if (!(this->isAtBottom)){
		y = y + 1;
		this->setY(y);
	}
}