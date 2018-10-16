// #include "userInputValidator.hpp"
#include "Game.hpp"
#include <iostream>
#include <string>

using std::endl;
using std::cout;
using std::cin;
using std::string;

Game::Game(){
	setIsRunning(false);
}

void Game::run(){
	startMenu();
	setup();
	gameplay();
	end();
}

void Game::startMenu(){	
	string input;
	cout << "1: Play Zoo Tycoon Boom" << endl << "0: Exit" << endl;
	getline(cin, input);

	isRunning = stoi(input);


}

void Game::setup(){
	string tigers, penguins, turtles;
	playerMoney = 100000;
	isFirstDay = true;
	zoo = new Zoo();

	cout << zoo->getTigerCount() << endl;

	cout << "Welcome to Zuuu Tycoon!" << endl <<endl;

	cout << "Let's build a zoo!" << endl << endl
	<< "You've inherited $100,000 from you late great uncle and an empty zoo." << endl 
	<< "Let's buy some animals!" << endl 
	<< "How many tigers would you like to buy? There's only two available at the moment." << endl;

	getline(cin, tigers);
	for(int n = 0; n < (stoi(tigers)); n++){
		// zoo->buyTiger(1);
		zoo->buyAnimal(zoo->getTigerArray(), zoo->getTigerCount(), 1);
		playerMoney -= zoo->getTiger()->getCost();
	}

	cout << endl << "How many penguins would you like to purchase? You have to have one or two of these guys in the park! They're too cute!" << endl
		<< "Enter 1 or 2 to purchase: ";

	getline(cin, penguins);
	for(int n = 0; n < (stoi(penguins)); n++){
		zoo->buyPenguin(1);
		playerMoney -= zoo->getPenguin()->getCost();
	}

	cout << endl << "How many turtles would you like to purchase? You have to have one or two of these guys in the park! They're turtles!" << endl
		<< "Enter 1 or 2 to purchase: ";

	getline(cin, turtles);
	for(int n = 0; n < (stoi(turtles)); n++){
		zoo->buyTurtle(1);
		playerMoney -= zoo->getTurtle()->getCost();
	}

	cout << endl << "You have $" << playerMoney << " left." << endl << endl;
}

void Game::gameplay(){
	int day = 1;
	string continueGame;
	while(isRunning){
		cout << "Day " << day << endl
		<< "=============" << endl << endl;

		if(day == 1){
			zoo->animalsAge();
		}
		feedAnimals();
		// randomEvent();
		payoff();
		purchase();
		cout << "Do you want to continue to the next day?" << endl;
		getline(cin, continueGame);

		setIsRunning(stoi(continueGame));
		day++;
	}
}
void Game::feedAnimals(){
	cout << "You fed all the animals!" << endl << "It cost $" <<  zoo->feedAnimalsCost() << endl;
	playerMoney -= zoo->feedAnimalsCost();	
}

void Game::payoff(){
	cout << "Your zoo gained $" << zoo->totalPayoff() << " today!" << endl
		<< "You have $" << playerMoney << " left" << endl << endl;

	playerMoney += zoo->totalPayoff();	
}

void Game::purchase(){
	string choice;
	cout << "It's the end of day and the the animal wrangler is coming around with some more animals." << endl;
	cout << "You have " << zoo->getTigerCount() << endl
		<< "You have " << zoo->getPenguinCount() << endl
		<< "You have " << zoo->getTurtleCount() << endl
		<< "You have $" << playerMoney << " left." << endl
		<< "1: Buy an adult tiger" << endl
		<< "2: Buy an adult penguin" << endl
		<< "3: Buy an adult turtle" << endl
		<< "0: Don't buy an animal today" << endl;
	getline(cin, choice);
	zoo->buyAnimal(zoo->getTigerArray(), zoo->getTigerCount(), stoi(choice));
	// switch(stoi(choice)){
	// 	case 1:
	// 		zoo->buyTiger(3);
	// 		break;
	// 	case 2:
	// 		zoo->buyPenguin(3);
	// 		break;
	// 	case 3:
	// 		zoo->buyTurtle(3);
	// 		break;
	// 	case 0:
	// 		break;
	// }
}

void Game::setIsRunning(bool isRunning){
	this->isRunning = isRunning;
}

void Game::end(){
	delete zoo;

}
