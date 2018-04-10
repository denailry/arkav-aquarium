#include "Item.hpp"

Item::Item(double x, double y, double width, double height, char type) : Entity(x, y, width, height, type){
	isAtBottom = false;
}