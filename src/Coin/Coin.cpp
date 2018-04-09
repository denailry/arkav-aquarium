#include "Coin.hpp"

Coin::Coin(int x, int y, int nilai) : Item(x,y,TYPE_COIN){
	value = nilai;
}

int Coin::getValue(){ //mendapatkan nilai koin
	return value;
} 

void Coin::tick(){
	int y = this->getY();
	if (!(this->isAtBottom)){
		y = y + 1;
		this->setY(y);
	}
}