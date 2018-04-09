#ifndef ITEM_HPP
#define ITEM_HPP

#include "../Entity/Entity.hpp"

class Item : public Entity {
	public:
		Item(int x, int y, char type);
	protected:
		bool isAtBottom; //apakah item sudah berada di dasar akuarium atau belum
};

#endif