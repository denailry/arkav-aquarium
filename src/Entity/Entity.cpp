#include "Entity.hpp"

Entity::Entity(int x, int y, int width, int height, char type) {
	this->radX = width/2;
	this->radY = height/2;
	this->x = x;
	this->y = y;
	this->type = type;
}

void Entity::tick(int delay) {
	this->tickTime = tickTime + 1;
}

// Getter
int Entity::getId() const {
	return this->id;
}
int Entity::getX() const {
	return this->x;
}
int Entity::getY() const {
	return this->y;
}
int Entity::getRadX() const {
	return this->radX;
}
int Entity:: getRadY() const {
	return this->radY;
}
int Entity::getLeft() const {
	return this->x - this->radX;
}
int Entity::getRight() const {
	return this->x + this->radX;
}
int Entity::getTop() const {
	return this->y - this->radY;
}
int Entity::getBottom() const {
	return this->y + this->radY;
}
Space* Entity::getSpace() const {
	return this->space;
}

// Setter
void Entity::setId(int id) {
	this->id = id;
}
void Entity::setX(int x) {
	this->x = x;
}
void Entity::setY(int y) {
	this->y = y;
}
void Entity::setRadX(int radX) {
	this->radX = radX;
}
void Entity::setRadY(int radY) {
	this->radY = radY;
}
void Entity::setSpace(Space* space) {
	this->space = space;
}