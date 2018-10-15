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

	isFirstDay = true;

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
** Description: Public method. Allows user to buy animals. Frees memory of the Animal type to allow
the the array to hold an animal of a specific type.
**************************************************************************************************/
void Zoo::buyTiger(){
	delete tigers[tigerCount];
	tigers[tigerCount] = new Tiger(1); 
	tigerCount++;
	cout << "You just bought a fierce tiger!" << endl 
	<< "You now have " << tigerCount << " tigers." << endl;
}

void Zoo::buyPenguin(){
	delete penguins[penguinCount];
	penguins[penguinCount] = new Penguin(1); 
	penguinCount++;
	cout << "You just bought a adorable penguin!" << endl << 
	"You now have " << penguinCount << " penguins." << endl;
}
void Zoo::buyTurtle(){
	delete turtles[turtleCount];
	turtles[turtleCount] = new Turtle(1); 
	turtleCount++;
	cout << "You just bought a radical turtle!" << endl 
	<< "You now have " << turtleCount << " turtle" << endl;
}

/**************************************************************************************************
** Description: Public method. These methods are used to simulate when new animals are born. Free
memory of the Animal type to allow the array to hold an animal of a specfic type.
**************************************************************************************************/
void Zoo::tigerIsBorn(){
	delete tigers[tigerCount];
	tigers[tigerCount] = new Tiger();
	tigerCount++;
	cout << "A fierce, tiny, tiger was born!" << endl 
	<< "You now have " << tigerCount << " tigers." << endl;
}


void Zoo::penguinIsBorn(){
	delete penguins[penguinCount];
	penguins[penguinCount] = new Penguin(); 
	penguinCount++;
	cout << "An adorable penguin was born!" << endl << 
	"You now have " << penguinCount << " penguins." << endl;
}
void Zoo::turtleIsBorn(){
	delete turtles[turtleCount];
	turtles[turtleCount] = new Turtle(); 
	turtleCount++;
	//TODO: work on the problem of the when the animal count becomes too large.
	// if(turtleCount != 0 && turtleCount % 10 == 0){
	// 	getMoreTurtleCages(sizeOfTigerCage);
	// }
	cout << "A radical turtle was just hatched!" << endl 
	<< "You now have " << turtleCount << " turtle" << endl;
}

int Zoo::feedAnimalsCost(){
	cout << "You fed all the animals!" << endl << "It cost $" <<  tigerCount * tigersFeedCost() + penguinCount* penguinsFeedCost() + turtleCount * turtlesFeedCost();
	return tigerCount * tigersFeedCost() + penguinCount* penguinsFeedCost() + turtleCount * turtlesFeedCost();
}

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



Animal* Zoo::getTiger(){
	return tigers[tigerCount-1];
}
Animal* Zoo::getTurtle(){
	return turtles[turtleCount-1];
}
Animal* Zoo::getPenguin(){
	return penguins[penguinCount-1];
}
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
bool Zoo::getIsFirstDay(){
	return isFirstDay;
}
void Zoo::setIsFirstDay(bool notFirstDay){
	isFirstDay = notFirstDay;
}
void getMoreTurtleCages(int cages){

}
/**************************************************************************************************
** I don't know if I will use this.
**************************************************************************************************/

// Animal** Zoo::getTigerArray(){
// 	return tigers;
// }

// Animal** Zoo::getPenguinArray(){
// 	return penguins;
// }
// Animal** Zoo::getTurtleArray(){
// 	return turtles;
// }

// void Zoo::buyAnimal(Animal **& animal, int& animalCount){
// 	delete animal[animalCount];
// 	animal[animalCount] = new animal[animalCount];
// 	animalCount++;
// }
// int& Zoo::getTigerCount(){
// 	return tigerCount;
// }

// int& Zoo::getPenguinCount(){
// 	return penguinCount;
// }

// int& Zoo::getTurtleCount(){
// 	return turtleCount;
// }
