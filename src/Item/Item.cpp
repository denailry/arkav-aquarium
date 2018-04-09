#include "Item.hpp"

Item::Item(int x, int y, char type) : Entity(x,y,type){
	isAtBottom = false;
}