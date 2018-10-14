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
	setup();
	zoo->animalsAge();
	zoo->getAllTigersAges();
	// startMenu();
	// while(isRunning){
	// 	setup();
	// 	gameplay();
	// }
	end();
}

void Game::startMenu(){	
	string input;
	cout << "1: Play Zoo Tycoon Boom" << endl << "0: Exit" << endl;

}

void Game::gameplay(){
	// if(!isFirstDay){
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
	cout << playerMoney <<endl;
	zoo->getAllTigersAges();
}


void Game::setIsRunning(bool isRunning){
	this->isRunning = isRunning;
}

void Game::end(){
	delete zoo;

}
