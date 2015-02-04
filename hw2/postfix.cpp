#include "stackdbl.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdexcept>

using namespace std;

double calculate( string& expr, bool& success )
{
	
	StackDbl * list = new StackDbl();

	// use a stringstream to go through every integer or operator because it stops at a space
	// so call stringstream ss;
	// string token;
	// ss << token;
	// check if token is an operator
	// if not make it an integer
	// lecture 13 will help

	stringstream nn;
	string token;
	double value;
	nn << expr;
	
	while( nn >> token ){
		stringstream mm;
		if ( token == "+" ) {
			if( list->empty() ){
				success = false;
				return 0;
			}
			double temp2 = list->top();
			list->pop();
			if( list->empty() ){
				success = false;
				return 0;
			}
			double temp1 = list->top();
			list->pop();
			double sum = temp1 + temp2;
			list->push(sum);			
		} else if ( token == "-" ) {
			if( list->empty() ){
				success = false;
				return 0;
			}
			double temp2 = list->top();
			list->pop();
			if( list->empty() ){
				return 0;
			}
			double temp1 = list->top();
			list->pop();
			double subt = temp1 - temp2;
			list->push(subt);
		} else if ( token == "/" ) {
			if( list->empty() ){
				success = false;
				return 0;
			}
			double temp2 = list->top();
			list->pop();
			if( list->empty() ){
				success = false;
				return 0;
			}
			double temp1 = list->top();
			list->pop();
			double divis = temp1 / temp2;
			list->push(divis);
		} else if ( token == "*" ) {
			if( list->empty() ){
				success = false;
				return 0;
			}
			double temp2 = list->top();
			list->pop();
			if( list->empty() ){
				success = false;
				return 0;
			}
			double temp1 = list->top();
			list->pop();
			double mult = temp1 * temp2;
			list->push(mult);
		} else {
			mm << token;
			mm >> value;
			list->push(value);
		}
	}
	return list->top();

}

int main(int argc, char* argv[])
{
	if( argc != 3 ){
		cout << "Error. Need more arguments on the command line." << endl;
		return 0;
	}

	ifstream ifile(argv[1]);
	if( !ifile.is_open() ){
		cout << "Error. The file you entered is invalid." << endl;
	}

	string temp;
	int numLines = 0;
	while( getline(ifile,temp) ){
		stringstream ss;
		ss << temp;
		numLines++;
	}


	string* lines = new string[numLines];
	
	int i = 0;
	ifstream file(argv[1]);

	while ( getline(file,temp) ){
		stringstream bc;
		bc << temp;
		lines[i] = temp;
		i++;
	}

	ofstream outfile;
	outfile.open("postfix.out");

	bool success;

	for(int b = 0; b < numLines; b++){
		double checker = calculate(lines[b], success);
		if( checker == 0){
			outfile << "Invalid." << endl;
		} else {
			outfile << checker << endl;
		}

	}
	
	file.close();
	ifile.close();
	outfile.close();






}