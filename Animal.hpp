#ifndef ANIMAL_HPP
#define ANIMAL_HPP 
class Animal{
protected:
	int age;
	int cost;
	int numberOfBabies;
	int baseFoodCost;
	int payoff;
	bool isAdult;

public:

	int getAge();
	int getNumberOfBabies();
	int getCost();
	int getPayoff();
	int getBaseFoodCost();
	bool getIsAdult();

	void animalSeesAnotherDay();
	Animal();
	~Animal();
};
#endif