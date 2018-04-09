#include "Fish.hpp"

Fish::Fish(int x, int y, char type) : Entity(x,y,type){
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