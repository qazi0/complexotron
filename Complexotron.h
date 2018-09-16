
// Complexotron.h
// Author: Siraj Qazi
// Complexotron v4.2
// Dated: May 29th, 2018
// Header file with Class definitions

#include <iostream>
using namespace std;

#ifndef HYDRA_CLASS
#define HYDRA_CLASS

class Hydra
{
protected:

	int* instructionMemory;
	int* integerMemory;
	double* decMemory;
	string* stringMemory;

	enum Complexotron_Commands 
	{
		READ = 10,
		WRITE = 11,
		READ_DECIMAL=12,
		WRITE_DECIMAL=13,
		LOAD = 20,
		STORE = 21,
		LOAD_DECIMAL=22,
		STORE_DECIMAL=23,
		ADD = 30,
		SUBTRACT = 31,
		DIVIDE = 32,
		MULTIPLY = 33,
		POWER = 34,
		LOG = 35,
		SIN = 36,
		COS = 37,
		TAN = 38,
		GOTO = 40,
		GOTO_IF_NEG = 41,
		GOTO_IF_ZERO = 42,
		STOP = 43,
		GOTO_IF_NEG_DECIMAL=44,
		GOTO_IF_ZERO_DECIMAL=45,
		ADD_DECIMAL=50,
		SUBTRACT_DECIMAL=51,
		MULTIPLY_DECIMAL=52,
		DIVIDE_DECIMAL=53,
		POWER_DECIMAL=54,
		READ_STRING = 70,
		WRITE_STRING = 71,
		STORE_STRING = 72,
		EDIT=99
	};

};

class Complexotron : public Hydra
{
public:
	Complexotron();
	void Start();

	/* void debugMode()
	{
		enterComplexotron();
	}  */

private:
	// Member functions
	void enterComplexotron();
	void enterCML();
	void execute();
	void CML();
	void stringInput();
	void loadFromFile();
	void saveToFile();
	void loading();
	void loadedSuccessfully();
	void documentation();
	void showError(string);
	void printStats();
	void showProjectCredits();
	void displayCommand(int);
	void changePasswd();

	// Data Members
	int congregator;
	double dcongregator;
	int instructionMeasure;
	int commandID;
	int location;
	int commandRgstr;
	string userID;
	string adminPasswd;
};


#endif