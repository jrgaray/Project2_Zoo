#include "Animal.hpp"

Animal::Animal(){
	age = -1;
	cost = -1;
	numberOfBabies = -1;
	baseFoodCost = 10;
	payoff = -1;
	isAdult = false;
}

int Animal::getAge(){
	return age;
}
int Animal::getNumberOfBabies(){
	return numberOfBabies;
}

int Animal::getCost(){
	return cost;
}

int Animal::getBaseFoodCost(){
	return baseFoodCost;
}

bool Animal::getIsAdult(){
	return isAdult;
}

int Animal::getPayoff(){
	return payoff;
}

void Animal::animalSeesAnotherDay(){
	age++;
}

Animal::~Animal(){
}