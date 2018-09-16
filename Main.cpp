// Main.cpp
// Author: Siraj Qazi
// Complexotron v4.2
// Dated: May 29th, 2018


#include <iostream>
#include <string>
#include <conio.h>
#include "Complexotron.h"

using namespace std;

// Main method to begin inputing and executing code. 
int main()
{
	system("cls");

	Complexotron Machine;
 
   Machine.Start();

	// Machine.debugMode();

	cout << "\n\n < PRESS ANY KEY TO LAUNCH COMPLEXOTRON AGAIN > ";
	_getch();
	system("cls");
	main();
}