#include "Food.hpp"

Food::Food(double x, double y, double width, double height) : Item(x, y, width, height, TYPE_FOOD){
}

void Food::tick(int delay){
	double y = this->getY();
	if (!(this->isAtBottom)){
		y = y + 1;
		this->setY(y);
	}
}