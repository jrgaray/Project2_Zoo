/**************************************************************************************************
** Author: Jose Garay
** Date: 10/13/2018
** Description: Zoo class interface file. The Zoo class models an actual zoo. Within the zoo 
you can buy and feed animals. The Zoo class is made to be used in a zoo tycoon game where you are 
in charge of the managing of the zoo.
**************************************************************************************************/
#ifndef ZOO_HPP
#define ZOO_HPP 
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include "Animal.hpp"

class Zoo{
private:

	int tigerCount;
	int penguinCount;
	int turtleCount;

	int sizeOfTigerCage;
	int sizeOfPenguinCage;
	int sizeOfTurtleCage;

	Animal **tigers;
	Animal **penguins;
	Animal **turtles;

	int tigersFeedCost();
	int penguinsFeedCost();
	int turtlesFeedCost();

	void getMoreCages(Animal**&, int&);
public:
	Zoo();
	~Zoo();
	void newAnimal(int, int);

	int feedAnimalsCost();
	int totalAnimalsPayoff();

	void getAllTigersAges();
	void animalsAge();

	Animal* getTiger();
	Animal* getPenguin();
	Animal* getTurtle();

	int getTigerCount();
	int getPenguinCount();
	int getTurtleCount();



};
#endif