#include "Food.hpp"

Food::Food(int x, int y, int width, int height) : Item(x, y, width, height, TYPE_FOOD){
}

void Food::tick(){
	int y = this->getY();
	if (!(this->isAtBottom)){
		y = y + 1;
		this->setY(y);
	}
}