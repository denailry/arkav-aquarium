/* 
 * Class Fish
 * 
 * Define fish behaviour as specification
 */ 

#ifndef FISH_HPP
#define FISH_HPP

#include "../Food/Food.hpp"
#include "../Entity/Entity.hpp"

class Fish : public Entity {
protected:
	bool dirRight; //bernilai true jika ke arah kanan dan false jika ke arah kiri
	bool hunger; //bernilai true apabila ikan lapar
public:
	// Constructor
	// Need position x and y
	Fish(double x, double y, double width, double height, char type);
	
	void setDirRight(bool);
	void setHunger(bool);
	bool getDirRight();
	bool getHunger();

};

#endif