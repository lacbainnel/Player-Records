#include <iostream>
#include <cstring>
#include <string>
#include <windows.h>
#include <iomanip>
#include <cstdlib>
using namespace std;

#define player_count 5 //setting the player limit

//Storing information of 5 players

int input_record();
int menu();
int compute_ave();
void getMaxAve(int &maxAve);
void getMinAve();
void option_exit();

//Structure with members equivalent to needed information
struct record {
	char name[50];
	int age;
	int score1;
	int score2;
	double ave;
};

record players[player_count] = {};
int storedData = 0;
void display_info();

int main ()
{
	int choice;
	record rec;
	int maximum_average;
	
	cout << "==================================================\n";
	cout << "                        MENU                      \n";
	cout << "==================================================\n";
	cout << "1. Add record\n";
	cout << "2. View player records\n";
	cout << "3. Compute for the average\n";
	cout << "4. Show the player(s) who gets the max average\n";
	cout << "5. Show the player(s) who gets the min average\n";
	cout << "6. Exit\n";
	cout << "==================================================\n";
	cout << "Enter choice: ";
	cin >> choice;
	cout << endl;
	
	switch (choice) {
		case 1:
			//limits stored data to 5 players only
			if (storedData >= player_count) {
			cout << "Up to 5 player information can only be stored!";
			} else {
				system("cls");
				input_record();
				cout << "\n======================================\n";
				menu();
			}
			break;
		case 2:
			system("cls");
			display_info();
			cout << "\n======================================\n";
			menu();
			break;
		case 3:
			system ("cls");
			compute_ave();
			cout << "\n======================================\n";
			menu();
		case 4:
			system ("cls");
			getMaxAve(maximum_average);
			cout << "\n======================================\n";
			menu();
			break;
		case 5:
			system("cls");
			getMinAve();
			cout << "\n======================================\n";
			menu();
			break;
		case 6:
			system("cls");
			option_exit();
			break;
		default:
			cout << "Input valid number.";
	}
	
	return 0;
}

int menu () {
	int menu_choice;
	
	cout << "Return to menu?\n";
	cout << "[1] YES\n";
	cout << "[2] NO\n";
	cout << "Enter choice: ";
	cin >> menu_choice;
	
	 if (menu_choice == 1) {
	 	system("cls");
		 main ();
	 } else {
	 	system("cls");
		 option_exit();
	 }
	 
	 return 0;
}

int input_record() {
	cout << "===================================\n";
	cout << "        ADD PLAYER RECORDS         \n";
	cout << "===================================\n";

		for (int i=0; i<5; i++) {
		cout << "\nPlayer number " << i+1 << endl;

		cin.ignore(); //since char and int are two different data types
		cout << "Enter name: ";
		cin.getline(players[i].name, 50);

		cout << "Enter age: ";
		cin >> players[i].age;
	
		cout << "Enter first score: ";
		cin >> players[i].score1;
	
		cout << "Enter second score: ";
		cin >> players[i].score2;
	}
	
	return 0;
}

void display_info() {
	//simply displaying stored data
	cout << "===================================\n";
	cout << "       VIEW PLAYER RECORDS         \n";
	cout << "===================================\n";

		for (int i=0; i<5; i++) {
		cout << "\nPlayer number " << i+1 << ":"<< endl;
	
		cout << "Name is " << players[i].name << endl;

		cout << "Age is " << players[i].age << endl;
	 
		cout << "First score is " << players[i].score1 << endl;
	
		cout << "Second score is " << players[i].score2 << endl;
	}
}

int compute_ave() {
	//computing the average of their two scores
	cout << "===================================\n";
	cout << "         AVERAGE OF SCORES         \n";
	cout << "===================================\n";
	
	double result;
	
	for (int i=0; i<5; i++) {
		cout << "\nPlayer number " << i+1 <<"\'s average: \n";
		result = (players[i].score1+players[i].score2)/2;
 		cout << result << endl;
	}
}

void getMaxAve (int &maxAve) {
	//using pass by reference to use for minimum average comparison
	int current_ave;
	
	//determining who got the maximum average
	cout << "===============================================\n";
	cout << "         PLAYER(S) WITH MAXIMUM AVERAGE        \n";
	cout << "===============================================\n";
	
	for (int i=0; i<5; i++) {
		current_ave = (players[i].score1 + players[i].score2)/2;
		if (current_ave > maxAve);
			maxAve = current_ave;
	do
	{
		current_ave = (players[i].score1 + players[i].score2)/2;
		if (current_ave == maxAve) 
			cout << "Player " << players[i].name
			<< " got the maximum average of " << current_ave << endl;
			
			i++;	
	} while (i<5);
}

}

void getMinAve () {
	int maxAve, current_ave, min_ave=0;
	getMaxAve (maxAve); // using the pass by reference function

	//determining who got the minimum average
	cout << "===============================================\n";
	cout << "         PLAYER(S) WITH MINIMUM AVERAGE        \n";
	cout << "===============================================\n";
	
	for (int i=0; i<5; i++) {
		current_ave = (players[i].score1 + players[i].score2)/2;
			min_ave = current_ave;
				if (min_ave < maxAve) {
					 if (min_ave < maxAve)
						cout << "Player " << players[i].name
						<< " got the minimum average of " << current_ave << endl;
				}
			}
}

void option_exit() {
	cout << "===============================================\n";
	cout << "                  EXIT PROGRAM                 \n";
	cout << "===============================================\n";
}





