#include "Item.hpp"

Item::Item(int x, int y, int width, int height, char type) : Entity(x, y, width, height, type){
	isAtBottom = false;
}