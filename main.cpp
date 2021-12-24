#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "helpers.h"
#include "spck.h"
using namespace std;
int DEBUG = 0;

void printMenu(string word, string comment,vector<WordFrequ> Guesses){
	// let user know the word wasnt recognized
	cout<<"\"" <<word<<"\""<<" was not recognized in: \""<<comment<<"\"\n";
	// loops through each possibilities and prints them for the user
	// creates a menu for the user to debug with
	for(unsigned int i = 0; i<Guesses.size();i++){
		cout << Guesses[i].word<<"\t"<<i<<"||\t";
	}

	cout << "other\t"<< Guesses.size()<<endl;
}// functio outputs to the screen

vector<string>  getword(string line){// function parses for user
	string word = "";
	string rest = "";
	// object to hold word and rest of line
	vector<string> lineout;
	// checks for non null string
	if (line.size()>0){
		// checks for leading space
		if (line[0]==' '){
			line = line.substr(1,line.size());
			// cout<<"starts with a space"<<endl;
		}
		// finds first space still gets caught on double space
		int wordind = line.find(" ");
		if (wordind ==-1){
				wordind = line.size();
		}
		// check for weather no more spaces
		else{
			rest = line.substr(wordind+1);
		}
		word = line.substr(0,wordind);
	}
	lineout.push_back(word);
	lineout.push_back(rest);
	return lineout;
}

string spellCheckStep(string word,string fullL){
	SpellCheck dislexia("dicList.txt","freqList.txt");
	Dictionary oxy("dicList.txt");

	string wordout = word;
	// if word is not in Dictionary and the word is not of size 0
	if(!oxy.isFound(word)&&word.size()>0){
		// create a list of possibilities for the words
		vector<WordFrequ> possibilities = dislexia.sortedList(word);
		if(DEBUG)cout<<"number of choices:"<<possibilities.size()<<endl;
		int selection = 0;
		printMenu(word, fullL ,possibilities);
		//user input
		cin >> selection;
		// if user selected one of the possibilities
		if(selection < int(possibilities.size()+1) && selection >= 0){// checks for the user input
			// outputs a the selected correction
				// if other input
				if(selection == int(possibilities.size())){
					string newOption;
					cout<<"Correction: ";
					cin>>newOption;
					wordout = newOption;
				}
				// if picked from a list
				else wordout = possibilities[selection].word;
		}
	}
	return wordout;
}
string correct(string line){
	string fullL = line;
	vector<string> words = getword(fullL);
	string correctedLine="";
	// goes through all words
	while(words[1].size()>0){
		if(DEBUG)cout<<words[0]<<endl;
		correctedLine= correctedLine + " "+ spellCheckStep(words[0],fullL);
		words = getword(words[1]);
	}
	correctedLine= correctedLine + " "+ spellCheckStep(words[0],fullL);
	return correctedLine;
}

// main runner
int main(){
	cout<< "here\n";
	string misspelling = "th quock brwon fxo jmps ovr the lzay dog";
	cout<<"the misspelling is : "<<misspelling<<endl;
	string fixed_string = correct(misspelling);
	cout<<"the misspelling is : "<<fixed_string<<endl;
	cout<< "Done!!!!\n";
	return 0;
}
