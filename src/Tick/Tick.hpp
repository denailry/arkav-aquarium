/* 
 * Abstract Class Tick
 *
 * Tick is object timer
 * Time in the program is defined by tick
 * Something in the program will trigger the tick of every object
 */ 

#ifndef TICK_HPP
#define TICK_HPP

class Tick {
protected:
	int tickTime;
public:	
	// Constructor
	// Initialize tickTime = 0;
	Tick();

	// What to do for every tick of program
	// Normally tick is doing tickTime++
	virtual void tick(double delay) = 0;

	int getTickTime();
	void resetTickTime();
	void increaseTick();
	int diff(int tickTime);
};

#endif