#include "Fish.hpp"

Fish::Fish(double x, double y, double width, double height, char type) : Entity(x, y, width, height, type){
	setDirRight(true);
	setHunger(true);
}

void Fish::setDirRight(bool dir){
	dirRight = dir;
}

void Fish::setHunger(bool hgr){
	hunger = hgr;
}

bool Fish::getDirRight(){
	return dirRight;
}

bool Fish::getHunger(){
	return hunger;
}