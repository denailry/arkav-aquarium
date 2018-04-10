#include "Coin.hpp"

Coin::Coin(double x, double y, double width, double height, int nilai) : Item(x, y, width, height, TYPE_COIN){
	value = nilai;
}

int Coin::getValue(){ //mendapatkan nilai koin
	return value;
} 

void Coin::tick(int delay) {
	double y = this->getY();
	if (!(this->isAtBottom)){
		y = y + 1;
		this->setY(y);
	}
}