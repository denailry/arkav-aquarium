#include "Food.hpp"
#include <cmath>

Food::Food(double x, double y, double width, double height) : Item(x, y, width, height, TYPE_FOOD){
	this->setDirection(atan(1)*4.0/2.0);
	this->setImage("food.png");
}

void Food::tick(double delay){
	double newX = this->getX() + 50*cos(this->getDirection())*delay;
	double newY = this->getY() + 50*sin(this->getDirection())*delay;
	if (this->getSpace()->moveTo(this->getId(), TYPE_FOOD, newX, newY)) {
		this->setX(newX);
	 	this->setY(newY);
	}else{
		this->getSpace()->remove(this->getId(), TYPE_FOOD);	
	}
}