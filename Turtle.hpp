#ifndef TURTLE_HPP
#define TURTLE_HPP 
#include "Animal.hpp"
class Turtle : public Animal{
private:
	int babies = 0;
public:
	Turtle();
	Turtle(int);
	~Turtle();
};
#endif