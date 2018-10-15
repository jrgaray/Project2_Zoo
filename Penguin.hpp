#ifndef PENGUIN_HPP
#define PENGUIN_HPP 
#include "Animal.hpp"
class Penguin : public Animal{
private:
	int babies;
public:
	Penguin();
	Penguin(int);
	~Penguin();
};
#endif