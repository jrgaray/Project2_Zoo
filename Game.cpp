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
	zoo = new Zoo();

	cout << "Welcome to Zuuu Tycoon!" << endl <<endl;

	cout << "Let's build a zoo!" << endl << endl
	<< "You've inherited $100,000 from you late great uncle and an empty zoo." << endl 
	<< "Let's buy some animals!" << endl 
	<< "How many tigers would you like to buy? There's only two available at the moment." << endl;

	getline(cin, tigers);
	for(int n = 0; n < (stoi(tigers)); n++){
		zoo->newAnimal(1, 1);
		playerMoney -= zoo->getTiger()->getCost();
	}

	cout << endl << "How many penguins would you like to purchase? You have to have one or two of these guys in the park! They're too cute!" << endl
		<< "Enter 1 or 2 to purchase: ";

	getline(cin, penguins);
	for(int n = 0; n < (stoi(penguins)); n++){
		zoo->newAnimal(2, 1);
		playerMoney -= zoo->getPenguin()->getCost();
	}

	cout << endl << "How many turtles would you like to purchase? You have to have one or two of these guys in the park! They're turtles!" << endl
		<< "Enter 1 or 2 to purchase: ";

	getline(cin, turtles);
	for(int n = 0; n < (stoi(turtles)); n++){
		zoo->newAnimal(3, 1);
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
		if(day != 1){
			zoo->animalsAge();
		}
		feedAnimals();
		cout << "You have " << zoo->getTigerCount() << endl;
		// randomEvent();
		// payoff();
		purchase();
		cout << "Do you want to continue to the next day?" << endl;
		getline(cin, continueGame);
		setIsRunning(stoi(continueGame));
		day++;
	}
}
void Game::feedAnimals(){
	playerMoney -= zoo->feedAnimalsCost();	
	cout << endl << "You have $" << playerMoney << " left." << endl;
}

void Game::purchase(){
	string choice;
	cout << "You have " << zoo->getTigerCount() << " tigers." << endl
		<<"You have " << zoo->getPenguinCount() << " penguins." << endl
		<<"You have " << zoo->getTurtleCount() << " turtles." << endl
		<< "You have $" << playerMoney << " left." << endl << endl
		<< "It is the end of the day!" << endl
		<< "The exotic pet shop has animals for sale. Would you like to purchase one?" << endl << endl
		<< "1: Adult Tiger" << endl
		<<"2: Adult Penguin" << endl
		<<"3: Adult Turtle" << endl
		<< "0: Pass on making a purchase" << endl
		<< "Your choice: ";
	getline(cin, choice);
	//validate this	
	switch(stoi(choice)){
		case 1:	
			zoo->newAnimal(stoi(choice), 3);
			break;
		case 2:	
			zoo->newAnimal(stoi(choice), 3);
			break;
		case 3:	
			zoo->newAnimal(stoi(choice), 3);
			break;
		case 0:	
			break;
	}
}

void Game::setIsRunning(bool isRunning){
	this->isRunning = isRunning;
}

void Game::end(){
	delete zoo;

}
