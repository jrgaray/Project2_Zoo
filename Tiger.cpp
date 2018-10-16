#include "Tiger.hpp"

Tiger::Tiger(){
	age = 0;
	cost = 10000;
	numberOfBabies = 1;
	payoff = getCost() * 0.2;
	babies = 0;
}

Tiger::Tiger(int age){
	this->age = age;
	cost = 10000;
	numberOfBabies = 1;
	payoff = getCost() * 0.2;
	babies = 0;
}
Tiger::~Tiger(){
}

