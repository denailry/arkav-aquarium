/*
 * Class Entity
 * 
 * Base class of everything exist in the screen of Aquarium
 */

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "../Space/Space.hpp"
#include "../Tick/Tick.hpp"

#define TYPE_COIN 'c'
#define TYPE_FOOD 'f'
#define TYPE_GUPPY 'g'
#define TYPE_PIRANHA 'p'
#define TYPE_SNAIL 's'

class Entity : protected Tick {
private:
	Space *space; // The space where the entity belong
	int id; // Unique id for each entity
	int x; // X-Position of Entity
	int y; // Y-Position of Entity
	int radY;
	int radX;
	char type; // type of Entity
public:
	// Constructor
	// Need position x and y
	// Need type
	Entity(int x, int y, int width, int height, char type);

	// Implementation of Tick
	void tick(int delay);

	// Getter
	int getId() const;
	int getX() const;
	int getY() const;
	int getRadX() const;
	int getRadY() const;
	int getTop() const;
	int getLeft() const;
	int getRight() const;
	int getBottom() const;
	Space* getSpace() const;

	// Setter
	void setId(int id);
	void setX(int x);
	void setY(int y);
	void setRadX(int radX);
	void setRadY(int radY);
	void setSpace(Space *space);
};

#endif