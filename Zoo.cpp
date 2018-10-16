/**************************************************************************************************
** Author: Jose Garay
** Date: 10/13/2018
** Description: Zoo class implementation file. The Zoo class models an actual zoo. Within the zoo 
you can buy and feed animals. The Zoo class is made to be used in a zoo tycoon game where you are 
in charge of the managing of the zoo.
**************************************************************************************************/

#include "Zoo.hpp"
#include <iostream>
using std::cout;
using std::endl;

/**************************************************************************************************
** Description: The default constructor for the Zoo class. All data members are initialized to 
their starting attributes. 
**************************************************************************************************/
Zoo::Zoo(){

	//The number of each animal the zoo has.
	tigerCount = 0;
	penguinCount = 0;
	turtleCount = 0;

	//The number of each animals the zoo can hold.
	sizeOfTurtleCage = 10;
	sizeOfTigerCage = 10;
	sizeOfPenguinCage = 10;

	//Setting the pointer of each type of animal to a pointer of Animal type.
	tigers = new Animal*[sizeOfTigerCage];
	penguins = new Animal*[sizeOfPenguinCage];
	turtles = new Animal*[sizeOfTurtleCage];

	//Placing "empty" animals in the cages to know that they are empty.
	for(int n = 0; n < sizeOfTigerCage; n++){
		tigers[n] = new Animal();
	}
	for(int n = 0; n < sizeOfTurtleCage; n++){
		turtles[n] = new Animal();
	}
	for(int n = 0; n < sizeOfPenguinCage; n++){
		penguins[n] = new Animal();
	}
}

/**************************************************************************************************
** Description: Deconstructor for the Zoo class. Any memory that has been allocated will be freed.
**************************************************************************************************/

Zoo::~Zoo(){
	for(int n = 0; n < sizeOfTurtleCage; n++){
		delete turtles[n];
	}
	for(int n = 0; n < sizeOfPenguinCage; n++){
		delete penguins[n];
	}
	for(int n = 0; n < sizeOfTigerCage; n++){
		delete tigers[n];
	}
	delete [] tigers;
	delete [] penguins;
	delete [] turtles;
}

/**************************************************************************************************
** Description: 
**************************************************************************************************/
int Zoo::feedAnimalsCost(){
	cout << "You fed all the animals!" << endl << "It cost $" <<  tigerCount * tigersFeedCost() + penguinCount* penguinsFeedCost() + turtleCount * turtlesFeedCost();
	return tigerCount * tigersFeedCost() + penguinCount* penguinsFeedCost() + turtleCount * turtlesFeedCost();
}

/**************************************************************************************************
** Description: 
**************************************************************************************************/
int Zoo::tigersFeedCost(){
	if(tigerCount == 0){
		return 0;
	}else{
		return getTiger()->getBaseFoodCost() * 5;	
	}
}

int Zoo::penguinsFeedCost(){
	if(penguinCount == 0){
		return 0;
	}else{
		return getPenguin()->getBaseFoodCost();	
	}
}
int Zoo::turtlesFeedCost(){
	if(turtleCount == 0){
		return 0;
	}else{
		return getTurtle()->getBaseFoodCost() / 2 ;	
	}
}
void Zoo::getAllTigersAges(){
	if(tigerCount == 0){
		cout << "You have no tigers! :[" << endl;
	}
	else{
		for(int n = 0; n < tigerCount; n++){
			cout <<"Tiger " << n +1 <<" is " << tigers[n]->getAge() << " days old." << endl;;
		}
	}
}

/**************************************************************************************************
** Description: 
**************************************************************************************************/
int Zoo::totalAnimalsPayoff(){
	int pay = 0;
	for(int n = 0; n < tigerCount; n++){
		pay += tigers[n]->getPayoff();
	}
	for(int n = 0; n < penguinCount; n++){
		pay += penguins[n]->getPayoff();
	}
	for(int n = 0; n < turtleCount; n++){
		pay += turtles[n]->getPayoff();
	}
	return pay;
}

/**************************************************************************************************
** Description: Getters methods. Returns an integer representing the number of the specified animal. 
**************************************************************************************************/
int Zoo::getTigerCount(){
	return tigerCount;
}

int Zoo::getPenguinCount(){
	return penguinCount;
}

int Zoo::getTurtleCount(){
	return turtleCount;
}
/**************************************************************************************************
** Description: Getter methods. Returns the last Animal pointer in an array.
**************************************************************************************************/
Animal* Zoo::getTiger(){
	return tigers[tigerCount-1];
}
Animal* Zoo::getTurtle(){
	return turtles[turtleCount-1];
}
Animal* Zoo::getPenguin(){
	return penguins[penguinCount-1];
}
/**************************************************************************************************
** Description: Public method. Increments the animals age by one day. 
**************************************************************************************************/
void Zoo::animalsAge(){
	for(int n = 0; n < tigerCount; n++){
		tigers[n]->animalSeesAnotherDay();
	}
	for(int p = 0; p < penguinCount; p++){
		penguins[p]->animalSeesAnotherDay();
	}
	for(int tu = 0; tu < turtleCount; tu++){
		turtles[tu]->animalSeesAnotherDay();
	}
}

/**************************************************************************************************
** Description: Private method. Takes in a reference to a pointer to a pointer and a reference to 
an integer and returns nothing. Dynamically allocates memory when all of the "cages" are filled.
**************************************************************************************************/
void Zoo::getMoreCages(Animal **&originalCages, int &numberOfCages){
	Animal **newCages = new Animal*[numberOfCages+10];
	for(int n = 0; n < numberOfCages + 10; n++){
		if(n < numberOfCages){
			newCages[n] = originalCages[n];
		}
		else{
			newCages[n] = new Animal();
		}
	}
	delete [] originalCages;
	originalCages = newCages;	
	numberOfCages += 10;
}

/**************************************************************************************************
** Description: 
**************************************************************************************************/
void Zoo::newAnimal(int animalType, int animalAge){
	switch(animalType){
		case 1:
			delete tigers[tigerCount];
			tigers[tigerCount] = new Tiger(animalAge);
			tigerCount++;
			if(tigerCount == sizeOfTigerCage){
				getMoreCages(tigers, sizeOfTigerCage);
			}
			break;
		case 2:
			delete penguins[penguinCount];
			penguins[penguinCount] = new Penguin(animalAge);
			penguinCount++;
			if(penguinCount == sizeOfPenguinCage){
				getMoreCages(penguins, sizeOfPenguinCage);
			}
			break;
		case 3:
			delete turtles[turtleCount];
			turtles[turtleCount] = new Turtle(animalAge);
			turtleCount++;
			if(turtleCount == sizeOfTurtleCage){
				getMoreCages(turtles, sizeOfTurtleCage);
			}
			break;
	}
}

