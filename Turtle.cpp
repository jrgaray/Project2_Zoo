	#include "Turtle.hpp"

Turtle::Turtle(){
	age = 0;
	cost = 100;
	numberOfBabies = 10;
	payoff = 5;
	babies = 0;
}
Turtle::Turtle(int age){
	this->age = age;
	cost = 100;
	numberOfBabies = 10;
	payoff = 5;
	babies = 0;
}
Turtle::~Turtle(){
}

int Turtle::turtleFeedCost(int numberOfTurtles){
	return numberOfTurtles * (baseFoodCost /2);
}