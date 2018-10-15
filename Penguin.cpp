#include "Penguin.hpp"

Penguin::Penguin(){
	age = 0;
	cost = 1000;
	numberOfBabies = 5;
	payoff = 100;
	babies = 0;
}
Penguin::Penguin(int age){
	this->age = age;
	cost = 1000;
	numberOfBabies = 5;
	payoff = 100;
	babies = 0;
}
Penguin::~Penguin(){

}
