#ifndef TIGER_HPP
#define TIGER_HPP 
#include "Animal.hpp"
class Tiger : public Animal{
private:
	int babies;
public:
	Tiger();
	Tiger(int);
	~Tiger();
};
#endif