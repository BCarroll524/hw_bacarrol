#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <map>
#include <cctype>
#include "../prob2/llistint.h"


//to compile
//
//	g++ -g -o main main.cpp ../prob2/llistint.cpp
//	./main pages.txt output.txt The fox onion 104



using namespace std;

string change(string word, int& hyphen){
	
	int size = word.size();
	while( ispunct(word[0]) ){
		word.erase(0,1);
	}
	while( ispunct( word[ size-1 ] ) ){
		word.erase(size-1,size);
	}


	stringstream ss;
	ss << word;
	int count = 0;
	int isFalse = 0;

	char letter;

	while( count < word.size() ){
		ss >> letter;
		if( ispunct(letter) ){
			if( letter == '-' ){
				hyphen = 1;
				count++;
				continue;
			} else if( count == 0 || count == (word.size()-1) ){
				word.erase(count, count+1);
				isFalse = 0;
				count++;
			} else {
				word.erase(count,count);
				isFalse = 1;
			}
			
		} else {
			letter = tolower(letter);
			word[count] = letter; 
			count++;
		}
		
	}
	if( isFalse == 1 ){
		return "false";
	}
	return word;
}


int main(int argc, char* argv[])
{


	if( argc < 3 ){
		cout << "Error. Need more arguments on the command line." << endl;
		return 0;
	}

	ifstream ifile(argv[1]);
	if( !ifile.is_open() ){
		cout << "Error. The file you entered is invalid." << endl;
	}
		
	map<string, LListInt> mapList;

	int pageNumber = 1;
	string temp;
	string word;
	
	while( getline(ifile,temp) ){
		stringstream ss;
		ss << temp;

		while(ss){
			ss >> word;
			if( word.size() < 2){
				cout << "FOUND WORD LESS THAN TWO CHARACTERS" << endl;
				cout << mapList.find(word)->first << endl;
				continue;
			} else if( word == "<pagebreak>" ){
				pageNumber++;
				continue;
			}
			int hyphen = 0;
			string part;
			string otherPart;
			word = change(word, hyphen);
			if( word == "false" ){
				continue;
			}

			if( hyphen == 1 ){
				cout << "SUCCESS" << endl;
				char c;
				int count = 0;
				int tracker = 0;
				while( count < word.size() ) {
					c = word[count];
					if( c == '-' ){
						part = word.substr(tracker, count);
						if( mapList.count(part) == 0 ){

							LListInt * AList = new LListInt();
							AList->push_back(pageNumber);
							mapList.insert( pair<string, LListInt>(part, *AList));

						} else {

							for(int i = 0; i < mapList.find(part)->second.size(); i++){

								if( mapList.find(part)->second.get(i) != pageNumber ){

									mapList.find(part)->second.insert(mapList.find(part)->second.size(), pageNumber);
								}
							}
						}
						tracker = count;
					}
					count++;
				}
				otherPart = word.substr(tracker+1, word.size()-1);
				if( mapList.count(otherPart) == 0 ){

					LListInt * AList = new LListInt();
					AList->push_back(pageNumber);
					mapList.insert( pair<string, LListInt>(otherPart, *AList));

				} else {

					for(int i = 0; i < mapList.find(otherPart)->second.size(); i++){

						if( mapList.find(otherPart)->second.get(i) != pageNumber ){

							mapList.find(otherPart)->second.insert(mapList.find(otherPart)->second.size(), pageNumber);
						}
					}
				}
				cout << mapList.find(part)->first << endl;
				cout << mapList.find(otherPart)->first << endl;
			}
						
									


			
			//can use for loop if it a word with a hyphen in it		

			if( mapList.count(word) == 0 ){

				LListInt * AList = new LListInt();
				AList->push_back(pageNumber);
				mapList.insert( pair<string, LListInt>(word, *AList));

			} else {

				for(int i = 0; i < mapList.find(word)->second.size(); i++){

					if( mapList.find(word)->second.get(i) != pageNumber ){

						mapList.find(word)->second.insert(mapList.find(word)->second.size(), pageNumber);
					}
				}
			}
			//cout << mapList.find(word)->first << endl;
			
			
		}
		
	}

	ofstream outfile;
	outfile.open("output.txt");


	for( int i = 3; i < argc; i++ ){
		int num = 0;
		string word = change(argv[i], num);
		if( mapList.count(word) == 0 )
		{
			outfile << "None." << endl;
		} else {

			for(int j = 0; j < mapList.find(word)->second.size(); j++)
			{
				int place = mapList.find(word)->second.get(j);
				outfile << place << " ";
			}
			outfile << endl;
		}
	}


	ifile.close();
	outfile.close();


}
