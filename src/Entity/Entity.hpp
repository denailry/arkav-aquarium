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
	double x; // X-Position of Entity
	double y; // Y-Position of Entity
	double radY;
	double radX;
	char type; // type of Entity
public:
	// Constructor
	// Need position x and y
	// Need type
	Entity(double x, double y, double width, double height, char type);

	// Implementation of Tick
	void tick(double delay);

	// Getter
	int getId() const;
	double getX() const;
	double getY() const;
	double getRadX() const;
	double getRadY() const;
	double getTop() const;
	double getLeft() const;
	double getRight() const;
	double getBottom() const;
	Space* getSpace() const;

	// Setter
	void setId(int id);
	void setX(double x);
	void setY(double y);
	void setRadX(double radX);
	void setRadY(double radY);
	void setSpace(Space *space);
};

#endif