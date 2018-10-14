#ifndef GAME_HPP
#define GAME_HPP 
#include "Zoo.hpp"

class Game{
private:

   void startMenu();
   void gameplay();
   void end();
   void setup(); 
   void reset();
   void setIsRunning(bool);


   void feedAnimals();
   void randomEvent();
   void payoff();
   void purchase();


   bool isFirstDay;
   bool isRunning;
   int playerMoney;

   Zoo *zoo;
public:
	Game();
	void run();

};
#endif