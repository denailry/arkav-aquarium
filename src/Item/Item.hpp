#ifndef ITEM_HPP
#define ITEM_HPP

#include "../Entity/Entity.hpp"

class Item : public Entity {
	public:
		Item(double x, double y, double width, double height, char type);
	protected:
		bool isAtBottom; //apakah item sudah berada di dasar akuarium atau belum
};

#endif