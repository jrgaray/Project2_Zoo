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
	while(isRunning){
		setup();
		if(!zoo->getIsFirstDay()){
			zoo->animalsAge();
			zoo->setIsFirstDay(false);
		}
		zoo->getAllTigersAges();
		zoo->animalsAge();
		zoo->getAllTigersAges();
		end();
		isRunning = false;
	// 	gameplay();
	}
}

void Game::startMenu(){	
	string input;
	cout << "1: Play Zoo Tycoon Boom" << endl << "0: Exit" << endl;
	getline(cin, input);

	isRunning = stoi(input);


}

void Game::gameplay(){
	// if(!getIsFirstDay()){
	// 	animalsAge();
	// }
	// feedAnimals();
	// randomEvent();
	// payoff();
	// purchase();
}

void Game::setup(){
	string tigers, penguins, turtles;
	playerMoney = 100000;
	isFirstDay = true;
	zoo = new Zoo();
	cout << "Welcome to Zuuu Tycoon!" << endl <<endl;
	cout << "Let's build a zoo!" << endl << "You've inherited $100,000 from you late great uncle and an empty zoo." << endl
		<< "Let's buy some animals!" << endl << "How many tigers would you like to buy? There's only two available at the moment." << endl;
	getline(cin, tigers);
	for(int n = 0; n < (stoi(tigers)); n++){
		zoo->buyTiger();
		playerMoney -= zoo->getTiger()->getCost();
	}

	cout << "How many penguins would you like to purchase? You have to have one or two of these guys in the park! They're too cute!" << endl
		<< "Enter 1 or 2 to purchase: ";

	getline(cin, penguins);
	for(int n = 0; n < (stoi(penguins)); n++){
		zoo->buyPenguin();
		playerMoney -= zoo->getPenguin()->getCost();
	}

	cout << "How many turtles would you like to purchase? You have to have one or two of these guys in the park! They're turtles!" << endl
		<< "Enter 1 or 2 to purchase: ";

	getline(cin, turtles);
	for(int n = 0; n < (stoi(turtles)); n++){
		zoo->buyTurtle();
		playerMoney -= zoo->getTurtle()->getCost();
	}

	cout << "You have $" << playerMoney << " left." << endl << endl;
}


void Game::setIsRunning(bool isRunning){
	this->isRunning = isRunning;
}

void Game::end(){
	delete zoo;

}
