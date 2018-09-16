
// Complexotron.cpp
// Author: Siraj Qazi
// Complexotron v4.2
// Dated: May 29th, 2018
// Class Complexotron's implementation file

#include <iostream>     // Standard C++ I/O
#include <iomanip>      // Stream Manipulations
#include <string>       // Standard C++ <string> class header
#include <fstream>      // For file I/O
#include <cctype>       // Character testing function prototypes
#include <cmath>        // Mathematical Functions
#include <conio.h>      // For _getch() Function
#include <Windows.h>    // Sleep() Command

#include "Complexotron.h"

using namespace std;

int tempcommandNumber = 0;
int stringCount = 0;
// int editLocation = 0;

Complexotron::Complexotron()  // Class Complexotron Constructor
{

	// Ask user to set console window font size 36 at startup
	cout << "\n Please set this Console Window's Font Size"
		<< "\n\n to 36 For the best experience with this Application.\n"
		<< "\n Click Window icon(top-left) > Properties > Font > 36 > OK"
		<< "\n\n <PRESS ANY KEY WHEN YOU'RE DONE>";
	_getch();


	// Initializing Memory Arrays: 

	integerMemory = new int[100];
	stringMemory = new string[100];
	instructionMemory = new int[100];
	decMemory = new double[100];

	for (int i = 0; i<100; i++) 
	{
		integerMemory[i] = 0;
		instructionMemory[i] = 0;
		decMemory[i] = 0.0;
		stringMemory[i] = " ";
	}

	// Initializing Complexotron's Registers: 

	congregator = 0;
	dcongregator = 0.0;
	instructionMeasure = 0;
	commandID = 0;
	location = 0;
	commandRgstr = 0;

	ifstream passwd("adminPd.txt");  // Read admin password from file
	if (!passwd)
		adminPasswd = "@complexotron1"; // Set default password
	else
		passwd >> adminPasswd;
	passwd.close();
}

void Complexotron::enterComplexotron() // Startup
{
	system("color 0a");
	system("cls");

	cout << "\n #############################################################################\n\n"
		<< "                               Hydra :: Complexotron\n"
		<< "                                   Version 4.2\n"
		<< " #############################################################################\n"
		<< "\n                                                  Logged in: @" << userID << "\n"
		<< "\n Welcome to The Complexotron! A Computer that runs programs written in\n"
		<< " it's own machine language, a.k.a the Complexotron Machine Language(CML).\n"
		<< " \n\n Press "
		<< "\n 1 to Enter new program."
		<< "\n 2 to Load a source file. "
		<< "\n 3 to see documentation on The Complexotron. "
		<< "\n 4 to change Administrator password. "
		<< "\n 5 to Exit. ";

	char choicey = _getch();
	switch (choicey)
	{
	case '1':
		enterCML();
		break;

	case '2':
		loadFromFile();
		break;

	case '3':
		documentation();
		break;

	case '4':
		changePasswd();
		break;

	case '5':
		exit(0);

	default:
		cout << "\n Press 1-4 only.\n <PRESS ANY KEY> ";
		_getch();
		enterComplexotron();
	}
}

void Complexotron::enterCML()  // CML Code entry window
{
	int	commandNumber = 0;			// array index
	int userInput = 0;
	system("cls");
	cout << "\n #############################################################################\n\n"
		<< "                           THE COMPLEXOTRON :: CML\n"
		<<"                                 Version 4.2\n\n"
		<< " #############################################################################\n\n";
	cout << " Enter Complexotron Machine Language (CML) Code here:\n"
		<< "\n Enter one instruction per line number, and enter sentinel value -1 to\n"
		<< " stop entering further instructions.\n Press foward slash(/) to refer to the documentation for CML.\n\n";
	cout << noshowpos;
	entry:
	while (commandNumber < 100) 
	{
		if (commandNumber < 10)
		{
			cout << " 0";
			cout << commandNumber << " > ";
		}
		else
			cout << " "<< commandNumber << " > ";

		//cin >> userInput;

		char userInputchar[4], c; 
		int i = 0;
		do    // Input mechanism: _getch() function rather than std::cin
		{
			c = _getch();  // so that a keypress is captured, Pressing enter isn't required.
			if (c == '-')
			{
				cout << "-";
				c = _getch();
				if (c == '1')
				{
					cout << 1;
					userInput = -1;
					break;
				}
				else
					continue;
			}
			else if (c == '/')
				documentation();

			else if (c == 8)   // ASCII For BackSpace key is 8
			{
				cout << "\b";
				i--;
			}
				
			if (!isdigit(c))
				continue;       // Character Exception Handling

			cout << c;
			userInputchar[i++] = c;

		} while (i != 4);  // Allow entry of only 4 characters

	// afteruserInput:

		if (userInput != -1)
		{
			userInput = atoi(userInputchar);  // cout << "\n userInput = " << userInput;
			int testVal = userInput / 100; //  cout << "\n testVal = " << testVal;
			int complexoCommands[30] = { 0,10,11,12,13,20,21,22,23,30,31,21,33,34,35,36,37,38,40,41,42,43,50,51,52,53,54,70,71,99 };
			for (int i = 0; i < 30; ++i)
			{
				// cout << "\n loop running: testVal= " << testVal << " command[" << i << "] = " << complexoCommands[i]<<"\n";
				if (testVal == complexoCommands[i])
					break;
				else if (i == 29 && testVal != complexoCommands[i])
				{
					cout << " ~ Unrecognized Command. Please enter again.\n\n";
			
					goto entry;
				}
			}

			 instructionMemory[commandNumber] = userInput; /*
														   Save entered instruction
														   into the instructionMemory[] array
														   */

			/*--------------------------------
			if (editLocation == 0)
			{
				cout << "\n editLocation = 0";
				instructionMemory[commandNumber] = userInput;
			}
				
			else
			{
				cout << "\n editLocation = "<<editLocation;
				instructionMemory[editLocation] = userInput;
				_getch();
			}
				

			//-------------------------------------- */
		}

		displayCommand(userInput); 
		cout << endl;

		/* while ((userInput < -1 && userInput != -1) || userInput > 9999) // Invalid value check loop
		{
			cout << "User userInput invalid. Please try again." << endl;
			if (commandNumber < 10) {
				cout << " 0";
			}
				cout << commandNumber << " > ";
			cin >> userInput;
		}
		*/

		// instructionMemory[commandNumber] = userInput;

		if (userInput / 100 == 99)
		{
			if (instructionMemory[commandNumber] % 100 < 10)
				cout << " 0";
			cout << instructionMemory[commandNumber] % 100 << " > ";
			cin >> instructionMemory[userInput % 100];

			//-----------------------------------------
			/* editLocation = userInput % 100;
			cout << "\n editLocation = " << editLocation<<"\n";
			_getch();
			//----------------------------------------- 

			 

			//----------------------------------------- */
			/*
			int i = 0;
			do
			{
				c = _getch();
				if (c == '-')
				{
					cout << "-";
					c = _getch();
					if (c == '1')
					{
						cout << 1;
						userInput = -1;
						break;
					}
					else
						continue;
				}
				else if (c == '/')
					documentation();

				else if (c == 8)
				{
					cout << "\b";
					i--;
				}

				if (!isdigit(c))
					continue;       // Character Exception Handling

				cout << c;
				userInputchar[i++] = c;

			} while (i != 4);
			
			goto afteruserInput;

			//------------------------------------------ */
		}

		commandNumber++;
		tempcommandNumber = commandNumber;

		if (userInput == -1)
		{
			if (instructionMemory[0] == 0)
				instructionMemory[0] = 4300;

			for (int i = 0; i < commandNumber; i++)
			{
				if (instructionMemory[i] / 100 == 70)
				{
					stringInput();
					break;         /* So that the duplication
								   of for loops doesnt occur,
								   i.e. once this for loop and then
								   again the for loop inside
								   stringInput()*/
				}
			}
			
				break; /* Break out of the main userInput while loop
					   (while commandNumber < 100) 
					   To stop entering further instructions */
		}
	}
	// Successfully loaded.
	loadedSuccessfully();
}

void Complexotron::execute() {
	while (instructionMeasure < 100)
	{
		commandRgstr = instructionMemory[instructionMeasure];
		if ((instructionMemory[instructionMeasure++] / 100 )!= 70)
			CML();
	}
}

void Complexotron::CML() // Complexotron's Core Processing Function
{ 
	
	commandID = commandRgstr / 100;
	location = commandRgstr % 100;


	switch (commandID)   // MASTER SWITCH : CPU OF COMPLEXOTRON
	{
	case READ:
		cin >> integerMemory[location];
		break;

	case WRITE:
		cout << "\n "<< integerMemory[location] << endl;
		break;

	case READ_DECIMAL:
		cin >> decMemory[location];
		break;

	case WRITE_DECIMAL:
		cout << "\n " << decMemory[location] << endl;
		break;

	case LOAD:
		congregator = integerMemory[location];
		break;

	case STORE:
		integerMemory[location] = congregator;
		break;

	case LOAD_DECIMAL:
		dcongregator = decMemory[location];
		break;

	case STORE_DECIMAL:
		decMemory[location] = dcongregator;
		break;

	case ADD:
		congregator += integerMemory[location];
		break;

	case SUBTRACT:
		congregator -= integerMemory[location];
		break;

	case MULTIPLY:
		congregator *= integerMemory[location];
		break;

	case DIVIDE:
		if (integerMemory[location] == 0)
			showError("divide0");
		else 
			congregator /= integerMemory[location];
		break;

	case POWER:
	{
		int power = congregator;
		for (int i = 1; i < integerMemory[location]; ++i)
			congregator *= power;
	}
		break;

	case ADD_DECIMAL:
		dcongregator += decMemory[location];
		break;

	case SUBTRACT_DECIMAL:
		dcongregator -= decMemory[location];
		break;

	case MULTIPLY_DECIMAL:
		dcongregator *= decMemory[location];
		break;

	case DIVIDE_DECIMAL:
		if (decMemory[location] == 0.0)
			showError("divide0");
		else
			dcongregator /= decMemory[location];
		break;

	case POWER_DECIMAL:
	{
		double power = dcongregator;
		for (int i = 1; i < decMemory[location] ; ++i)
			dcongregator *= power;
	}
		break;

	case LOG:
		dcongregator = log(decMemory[location]);
		break;

	case SIN:
		dcongregator = sin(decMemory[location]);
		break;

	case COS:
		dcongregator = cos(decMemory[location]);
		break;

	case TAN:
		dcongregator = tan(decMemory[location]);
		break;

	case GOTO:
		instructionMeasure = location;
		break;

	case GOTO_IF_NEG:
		if (congregator < 0)
			instructionMeasure = location;
		break;

	case GOTO_IF_ZERO:
		if (congregator == 0)
			instructionMeasure = location;
		break;

	case GOTO_IF_NEG_DECIMAL:
		if (dcongregator < 0)
			instructionMeasure = location;
		break;

	case GOTO_IF_ZERO_DECIMAL:
		if (dcongregator == 0)
			instructionMeasure = location;
		break;

		/*  This part is never executed, cz of the if condition
		    in the while loop of execute()
	case READ_STRING:
	    cout << "\n Enter string in case READ STRING";
		getline(cin, stringMemory[location]);
		break;

		*/

	case WRITE_STRING:
		cout << "\n "<<stringMemory[location]<<endl;
		break;

	case STOP:
		cout << "------- Complexotron execution Completed -------" << endl;
		_getch();
		printStats();
		instructionMeasure = 100;		
		break;

	case EDIT:
		break;

	default:
		cout << "Invalid userInput";
		cout << "\n InstructionMemory[location]::  " << instructionMemory[location]<<"\n";
	}

}

void Complexotron::printStats()
{
	system("cls");
	system("color 0b");
	cout << "\n #############################################################################\n\n"
		<< "                        THE COMPLEXOTRON :: Memory Stats\n\n"
		<< " #############################################################################\n\n";
	cout << "\n COMPLEXOTRON MEMORY REGISTERS:" << endl;
	cout << "\n congregator:                " << showpos << setw(5) << setfill('0') << congregator << endl;
	cout << "\n instructionMeasure:         " << showpos << setw(2) << setfill('0')  << instructionMeasure << endl;
	cout << "\n commandRgstr:               " << showpos << setw(5) << setfill('0')  << commandRgstr << endl;
	cout << "\n commandID:                  " << showpos << setw(2) << setfill('0')  << commandID << endl;
	cout << "\n location:                   " << showpos << setw(2) << setfill('0') << location << endl;
	cout << "\n UserID:                     " << userID << endl;
	cout << "" << endl;

	cout << "\n\n";

	// Instruction Memory
	cout << "\n INSTRUCTION MEMORY:" << endl;
	cout << "   0     1     2     3     4     5     6     7     8     9" << endl;

	cout << "00 ";
	for (int i = 0; i < 10; i++) {
		cout << showpos << setw(5) << setfill('0')  << instructionMemory[i] << " ";
	}
	cout << endl;
	for (int j = 10; j < 100; j+= 10)
	{
		cout << noshowpos << j << " ";
		for (int i = 0; i < 10; ++i) {
			cout << showpos << setw(5) << setfill('0') << instructionMemory[j + i] << " ";
		}
		cout << endl;
	}

	// Integer Memory
	cout << "\n INTEGER MEMORY:" << endl;
	cout << "   0     1     2     3     4     5     6     7     8     9" << endl;

	cout << "00 ";
	for (int i = 0; i < 10; i++) {
		cout << showpos << setw(6) << setfill('0') << integerMemory[i] << " ";
	}
	cout << endl;
	for (int j = 10; j < 100; j+= 10)
	{
		cout << noshowpos << j << " ";
		for (int i = 0; i < 10; i++) {
			cout << showpos << setw(6) << setfill('0') << integerMemory[j + i] << " ";
		}
		cout << endl;
	}

	cout << "\n DECIMAL MEMORY:" << endl;
	cout << "   0        1        2        3        4        5        6        7        8        9" << endl;

	cout << "00 ";
	for (int i = 0; i < 10; ++i) {
		cout << showpos << setw(6) << setfill('0') << decMemory[i] << " ";
	}
	cout << endl;
	for (int j = 10; j < 100; j += 10)
	{
		cout << noshowpos << j << " ";
		for (int i = 0; i < 10; ++i) {
			cout << showpos << setw(6) << setfill('0') << decMemory[j + i] << " ";
		}
		cout << endl;
	}


	// String Memory
	cout << noshowpos << "\n STRING MEMORY:\n" << endl;

	for (int i = 0; i < stringCount; ++i)
	{
		if (i < 10)
		{
			cout << " 0";
			cout << i;
		}
		else
			cout << " " << i;
		
		cout << "  " << stringMemory[i]<<"\n";
	}
	_getch();
	enterComplexotron();
}


void Complexotron::showError(string errorType)
{
	if (errorType == "dividebyZero") {
		cout << "An attempt was made to divide by 0. The program will terminate." << endl;
		instructionMeasure = 100;
		printStats();
	}
	else
	{
		cout << "\n An Exception occured.\n";
		instructionMeasure = 100;
		printStats();
	}
}
void Complexotron::loadFromFile()
{
	string fileName;
	cout << "\n\n Enter the name of the file(with type extension):\n > ";
	cin >> fileName;
	ifstream inFile(fileName);
	if (!inFile)
	{
		cout << "\n File couldn't be opened.\n";
		_getch();
		enterComplexotron();
	}
	cout << "\n\n Reading instructions from file";
	for (int i = 0; i<5; ++i)
	{
		Sleep(130);
		cout << ".";
	}
	cout << "\n\n";
	for (int x = 0; !inFile.eof(); ++x)  // Read from the file until EndOfFile(EOF)
	{
		inFile >> instructionMemory[x];
		cout <<"\n "<< instructionMemory[x];
		displayCommand(instructionMemory[x]);
		tempcommandNumber++;
		Sleep(100);
	}
	stringInput();
	loadedSuccessfully();
}

 void Complexotron::saveToFile()  // Function to output code to a file
{
	 string fileName;
	 cout << "\n Enter the file name you want to save this CML Code to:\n > ";
	 cin >> fileName;
	 fileName.append(".txt");
		ofstream outFile(fileName);
		if (!outFile)
		{
			cout << "\n File couldn't be created.\n";
			_getch();
			exit(0);
		}
		cout << "\n\n Saving Program to file";
		for (int i = 0; i<5; ++i)
		{
			Sleep(130);
			cout << ".";
		}
		cout << "\n";
		for (int x = 0; x < tempcommandNumber; ++x)
		{
			outFile << instructionMemory[x]<<"\n";
			cout << "\n " << instructionMemory[x];
			displayCommand(instructionMemory[x]);
			Sleep(100);
		}
		cout << "\n File saved successfully. \n <PRESS ANY KEY> ";
		_getch();
		enterComplexotron();
		exit(0);
} 

void Complexotron::loadedSuccessfully()
{
	int loop = 5;
	cout << "\n Building program";
	while (loop-- >= 0)  //Loading Animation
	{
		Sleep(100);        
		cout << ".";
	}
	cout << "\n\n Program loaded successfully.\n";
loaded:
	cout << "\n\n Press"
		<< "\n 1 To Execute Program."
		<< "\n 2 to Save program to a file."
		<< endl;
	char x = _getch();
	switch (x)
	{
	case '1':
		cout << "\n";
		system("cls");
		cout << "\n ------------------------- OUTPUT CONSOLE --------------------------\n\n";
		break;
	case '2':
		saveToFile();
	default:
		cout << "\n Press 1-2 ?\n ";
		goto loaded;
	}
	execute();
}

void Complexotron::Start()  // Startup function, with login
{
	string pass;
	string username;
	char password[100];
	system("cls");
	cout << "\n -----------------------------------------------------------------------------"
		<< "\n                      The COMPLEXOTRON :: LOGIN CONSOLE"
		<< "\n -----------------------------------------------------------------------------"
		<< endl;

	cout << "\n\n Enter Login ID:   > ";
	cin >> userID;
	if (userID == "admin")
	{
		int i = 0;
		cout << "\n Enter password:   > ";
		char c = _getch();
		while (c != 13)   // Accept input until Enter(ASCII 13) is pressed.
		{
			if (c == 8)  // Allow Backspace for erasing characters
			{
				if (i == 0);
				else
				{
					password[--i] = '\0';
					cout << "\b \b";
				}
			}
			else
			{
				password[i++] = c;
				cout << "*";
			}
			c = _getch();
		}
		password[i] = '\0';  // Terminate the string in memory

		if (password == adminPasswd)
		{
			loading();
			exit(0);
		}
		else
		{
			cout << "\n\n The password is INCORRECT.\n" << endl;
			_getch();
			Start();
		}
	}
	username = userID;
	username.append(".txt");
	ifstream saveData(username);   // Open the file corresponding to userID
	if (!saveData)
	{
		cout << "\n Authentication Error: No such account exists in the "
			<< " Complexotron DataBase." << endl;
		_getch();
		Start();
	}
	else
	{
		int i = 0;
		cout << "\n Enter password:   > ";
		char c = _getch();
		while (c != 13)   // Accept input until Enter(ASCII 13) is pressed.
		{
			if (c == 8)  // Allow Backspace for erasing characters
			{
				if (i == 0);
				else
				{
					password[--i] = '\0';
					cout << "\b \b";
				}
			}
			else
			{
				password[i++] = c;
				cout << "*";
			}
				c = _getch();
		}
		password[i] = '\0';  // Terminate the string in memory
		saveData >> pass;   // Read password from file
		if (password == pass)
		{
			loading();
			exit(0);
		}
		else
		{
			cout << "\n\n The password is INCORRECT.\n" << endl;
			_getch();
			Start();
		}
	}

}

void Complexotron::loading()
{
	system("color 0b");
	system("cls");
	cout << "\n\n Logging you in  ";
	for (int i = 0; i < 5; ++i)      // Rotating '/' animation
	{
		Sleep(105);
		cout << "\b\\" << flush;
		Sleep(105);
		cout << "\b|" << flush;
		Sleep(105);
		cout << "\b/" << flush;
		Sleep(105);
		cout << "\b--" << flush;
	}

	system("cls");
	system("color 0e");
	cout << "\n\n Fetching data  ";
	for (int i = 0; i < 5; ++i)
	{
		Sleep(105);
		cout << "\b\\" << flush;
		Sleep(105);
		cout << "\b|" << flush;
		Sleep(105);
		cout << "\b/" << flush;
		Sleep(105);
		cout << "\b--" << flush;
	}
	enterComplexotron();
}

void Complexotron::documentation()
{
	system("color 0e");
	system("cls");
	cout << "\n #############################################################################\n\n"
		<< "                         THE COMPLEXOTRON :: User Guide\n\n"
		<< " #############################################################################\n\n";
	cout << "\n Welcome to the User Guide for The Complexotron!"
		<< "\n\n On this page you will find all the details on how to operate this "
		<< "\n Hybrid Machine Language Simulation (HMLS)."
		<< "\n\n Below is a list of ML Codes of all the available commands\n in The Complexotron:"
		<< "\n" << endl;
	cout << "\tCML COMMAND\tINSTRUCTION CODE & DESCRIPTION\n"
		<< " -------------------------------------------------------------\n";
	cout << "\n \tREAD\t\t|   10\tRead a number from the keyboard."
		"\n \tWRITE\t\t|   11\tWrite a number onto the screen."
		"\n \tLOAD\t\t|   20\tLoad a number to the CONGREGATOR."
		"\n \tSTORE\t\t|   21\tStore the CONGREGATOR RESULT into memory."
		"\n \tADD\t\t|   30\tAdd a number to the CONGREGATOR."
		"\n \tSUBTRACT\t|   31\tSubtract a number from the CONGREGATOR."
		"\n \tDIVIDE\t\t|   32\tDivide the CONGREGATOR by a number."
		"\n \tMULTIPLY\t|   33\tMultiply the CONGREGATOR by a number."
		"\n \tPOWER\t\t|   34\tRaise to power the CONGREGATOR."
		"\n \tLOG\t\t|   35\tCalculate log() of CONGREGATOR."
		"\n \tSIN\t\t|   36\tCalculate sin() of CONGREGATOR."
		"\n \tCOS\t\t|   37\tCalculate cos() of CONGREGATOR."
		"\n \tTAN\t\t|   38\tCalculate tan() of CONGREGATOR."
		"\n \tGOTO\t\t|   40\tGOTO a specified LINE NUMBER."
		"\n \tGOTO_IF_NEG\t|   41\tGoto a line if CONGREGATOR is negative."
		"\n \tGOTO_IF_ZERO\t|   42\tGoto a line if CONGREGATOR is zero."
		"\n \tSTOP\t\t|   43\tEnd of program."
		"\n \tREAD_STRING\t|   70\tRead a string from the user."
		"\n \tWRITE_STRING\t|   71\tWrite a string tto the screen."
		"\n \tEDIT\t\t|   99\tEdit a line."
		;
	cout << "\n\n --------  DECIMAL MANIPULATIONS ----------\n";
	cout<< "\n \tREAD_DECIMAL\t|   12\tRead a decimal number from the keyboard."
		"\n \tWRITE_DECIMAL\t|   13\tWrite a decimal number on the screen."
		"\n \tLOAD_DECIMAL\t|   22\tLoad a decimal number into the dcongregator."
		"\n \tSTORE_DECIMAL\t|   23\tStore the dcongregator into a memory location."
		"\n \tADD_DECIMAL\t|   50\tAdd a decimal number to the dcongregator."
		"\n \tSUBTRACT_DECIMAL|   51\tSubtract a decimal number from dcongregator."
		"\n \tDIVIDE_DECIMAL\t|   52\tDivide the dcongregator by a decimal number."
		"\n \tMULTIPLY_DECIMAL|   53\tMultiply a decimal number to the dcongregator."
		"\n \tPOWER_DECIMAL\t|   54\tRaise the dcongregator to a power."

		<< endl;

	cout << "\n\n < PRESS ANY KEY TO LAUNCH COMPLEXOTRON AGAIN > ";
	_getch();
	enterComplexotron();
}

void Complexotron::stringInput()
{
	cout << "\n\n -----------  Preprocessing dependencies ----------------\n";
	for (int i = 0; i < tempcommandNumber; i++)
	{
		if (instructionMemory[i] / 100 == 70)
		{
			stringCount++;
			cout << "\n Enter string["<< instructionMemory[i] % 100<<"]: ";
			cin.ignore();
			getline(cin, stringMemory[instructionMemory[i] % 100]);
		}
	}
}

void Complexotron::displayCommand(int instruction)
{
	if (instruction == -1)
		cout << "\t\tBEGIN CODE EXECUTION ";
	else
	{
		int commandID = instruction / 100;
		int location = instruction % 100;

		switch (commandID)
		{
		case READ:
			cout << "\t\tREAD into integerMemory[" << location << "]"; 
			break;

		case WRITE:
			cout << "\t\tWRITE integerMemory[" << location << "] to std::out";
			break;

		case READ_DECIMAL:
			cout << "\t\tREAD into decimalMemory[" << location << "]";
			break;

		case WRITE_DECIMAL:
			cout << "\t\tWRITE decimalMemory[" << location << "] to std::out";
			break;

		case LOAD:
			cout << "\t\tLOAD " << "integerMemory[" << location << "] into CONGREGATOR";
			break;

		case STORE:
			cout << "\t\tSTORE CONGREGATOR to integerMemory[" << location << "]";
			break;

		case LOAD_DECIMAL:
			cout << "\t\tLOAD " << "decMemory[" << location << "] into decimalCONGREGATOR";
			break;

		case STORE_DECIMAL:
			cout << "\t\tSTORE decimalCONGREGATOR to decMemory[" << location << "]";
			break;

		case ADD:
			cout << "\t\tADD " << "integerMemory[" << location << "] TO CONGREGATOR";
			break;

		case SUBTRACT:
			cout << "\t\tSUBTRACT " << "integerMemory[" << location << "] FROM CONGREGATOR";
			break;

		case MULTIPLY:
			cout << "\t\tMULTIPLY CONGREGATOR BY integerMemory[" << location << "]";
			break;

		case DIVIDE:
			cout << "\t\tDIVIDE CONGREGATOR BY integerMemory[" << location << "]";
			break;

		case POWER:
			cout << "\t\tEXPONENTIATE CONGREGATOR TO integerMemory[" << location<<"]";
			break;

		case ADD_DECIMAL:
			cout << "\t\tADD decMemory[" << location << "] TO decimalCONGREGATOR";
			break;

		case SUBTRACT_DECIMAL:
			cout << "\t\tSUBTRACT decMemory[" << location << "] FROM decimalCONGREGATOR";
			break;

		case MULTIPLY_DECIMAL:
			cout << "\t\tMULTIPLY decimalCONGREGATOR BY decMemory[" << location << "]";
			break;

		case DIVIDE_DECIMAL:
			cout << "\t\tDIVIDE decimalCONGREGATOR BY " << "decMemory[" << location << "]";
			break;

		case POWER_DECIMAL:
			cout << "\t\tEXPONENTIATE decimalCONGREGATOR TO decMemory[" << location<<"]";
			break;

		case LOG:
			cout << "\t\tSTORE LOG OF integerMemory[" << location << "] TO CONGREGATOR";
			break;

		case SIN:
			cout << "\t\tSTORE SIN OF integerMemory[" << location << "] TO CONGREGATOR";
			break;

		case COS:
			cout << "\t\tSTORE COS OF integerMemory[" << location << "] TO CONGREGATOR";
			break;

		case TAN:
			cout << "\t\tSTORE TAN OF integerMemory[" << location << "] TO CONGREGATOR";
			break;

		case GOTO:
			cout << "\t\tGOTO LINE " << location;
			break;

		case GOTO_IF_NEG:
			cout << "\t\tGOTO LINE " << location << " IF CONGREGATOR IS NEGATIVE";
			break;

		case GOTO_IF_ZERO:
			cout << "\t\tGOTO LINE " << location << " IF CONGREGATOR IS ZERO";
			break;

		case GOTO_IF_NEG_DECIMAL:
			cout << "\t\tGOTO LINE " << location << " IF decimalCONGREGATOR IS NEGATIVE";
			break;

		case GOTO_IF_ZERO_DECIMAL:
			cout << "\t\tGOTO LINE " << location << " IF decimalCONGREGATOR IS ZERO";
			break;

		case READ_STRING:
			cout << "\t\tREAD string into stringMemory[" << location << "]";
			break;

		case WRITE_STRING:
			cout << "\t\tWRITE stringMemory[" << location << "] to std::out";
			break;

		case STOP:
			cout << "\t\tEND OF PROGRAM";
			break;

		case EDIT:
			cout << "\t\tREWRITE LINE " << location;
			break;

		case 0:
			cout << "\t\tDEFAULT(EMPTY) COMMAND";
			break;

		default:
			cout << "\t\tINVALID userInput\n";
			// cout << "\n InstructionMemory[location]::  " << instructionMemory[location] << "\n";
		}
	}
}

void Complexotron::changePasswd()
{
	system("color 0e");
	system("cls");
	char password[100];
	cout << "\n #############################################################################\n\n"
		<< "                         THE COMPLEXOTRON :: Password Change\n\n"
		<< " #############################################################################\n\n";
	cout << "\n\n Enter current admin password: > ";
	int i = 0;
	char c = _getch();
	while (c != 13)   // Accept input until Enter(ASCII 13) is pressed.
	{
		if (c == 8)  // Allow Backspace for erasing characters
		{
			if (i == 0);
			else
			{
				password[--i] = '\0';
				cout << "\b \b";
			}
		}
		else
		{
			password[i++] = c;
			cout << "*";
		}
		c = _getch();
	}
	password[i] = '\0';  // Terminate the string in memory

	if (password == adminPasswd)
	{
		cout << "\n\n Enter new password:           > ";
		int i = 0;
		char c = _getch();
		if (c == 13)
		{
			cout << "\n\n Password must be atleast 5 characters long.";
			_getch();
			changePasswd();
		}
		while (c != 13)   // Accept input until Enter(ASCII 13) is pressed.
		{
			if (c == 8)  // Allow Backspace for erasing characters
			{
				if (i == 0);
				else
				{
					password[--i] = '\0';
					cout << "\b \b";
				}
				
			}
			else
			{
				password[i++] = c;
				cout << "*";
			}
			c = _getch();
		}
		password[i] = '\0';
		adminPasswd = password;
		cout << "\n\n Password changed successfully. ";

		ofstream passwd("adminPd.txt"); //Save new password to file
		passwd << adminPasswd;
		passwd.close();
		Sleep(800);
		Start();
	}
	else
	{
		cout << "\n\n The password is INCORRECT.\n" << endl;
		_getch();
		Start();
	}
}