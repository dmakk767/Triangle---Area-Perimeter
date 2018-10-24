// Ch4Num2.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <iostream>
#include <cstdlib>
using namespace std;
//predifine 
void compute(double a, double b, double c, double& area, double& perimeter);

//This program takes in the three lengthes of a triangle checks to see if they can make a triangle then finds the Area and Perimeter if they can.

int main()
{
	//setup veriables for input and calc purposes
	double a = 0, b = 0, c = 0, perimeter = 0, area = 0.0;
	//flag used to loop back in case of invalid input
	bool error = true;
	//write loop to catch error for invalid lengths and let user retry
	while (error) {
		//get info from user
		cout << "Please input the length of side A:" << endl; cin >> a;
		cout << "Please input the length of side B:" << endl; cin >> b;
		cout << "Please input the length of side C:" << endl; cin >> c;
		//check validity of lengths a, b, c 
		if ((a + b > c) && (a + c > b) && (b + c > a)) {
			//when valid do calc
			compute(a, b, c, area, perimeter);
			cout << "The area is: " << area << " units squared." << endl;
			cout << "The perimeter is: " << perimeter << " units." << endl;
			//let program know we completed ok
			error = false;
			//allow for continue after correct answer
			char cont = 'n';
			cout << "\nDo you want to input another set of data, y/n?" << endl;
			cin >> cont;
			if ((cont == 'y') || (cont == 'Y')) {
				error = true;
			}
			else {
				error = false;
			}
		}
		//else when not valid give them an error and set error bool to true so we can loop
		else {
			cout << "\n***Error: these lengths do not make a triangle. Try again.***" << endl << endl;
			error = true;
		}
	}
    return 0;
}

//define our functions
void compute(double a, double b, double c, double& area, double& perimeter) {
	//calc semiperimeter
	double s = ( a + b + c) / 2;
	area = (sqrt(s * (s - a) * (s - b) * (s - c)));
	perimeter = a + b + c;
}

