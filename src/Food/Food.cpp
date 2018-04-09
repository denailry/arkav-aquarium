#include "Food.hpp"

Food::Food(int x, int y) : Item(x,y,TYPE_FOOD){
}

void Food::tick(){
	int y = this.getY();
	if (!(this.isAtBottom)){
		y = y + 1;
		this.setY(y);
	}
}