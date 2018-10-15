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
	bool isFirstDay;

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
public:
	Zoo();
	~Zoo();
	// void buyAnimal(Animal**&, int&);
	void buyTiger();
	void buyTurtle();
	void buyPenguin();

	void tigerIsBorn();
	void penguinIsBorn();
	void turtleIsBorn();

	int feedAnimalsCost();

	void getAllTigersAges();
	void animalsAge();

	Animal* getTiger();
	Animal* getPenguin();
	Animal* getTurtle();

	// Animal** getTigerArray();
	// Animal** getPenguinArray();
	// Animal** getTurtleArray();

	// int& getTigerCount();
	// int& getPenguinCount();
	// int& getTurtleCount();

	bool getIsFirstDay();
	void setIsFirstDay(bool);


};
#endif