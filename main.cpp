#include <stdio.h>
#include <stdlib.h>
#include <iostream>
//#include "cmtChckr.h"
#include "helpers.h"
#include "spck.h"
using namespace std;
Comment cpp("//","/*","*/");// defines cpp comments structure
Comment python("#","\"\"\"","\"\"\"");//defines comments for python
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
string spellCheckStep(string word,Dictionary oxy,	SpellCheck dislexia,string fullL){
	string wordout = word;
	cout<<"word not found function"<<endl;
	// if word is not in Dictionary and the word is not of size 0
	if(!oxy.isFound(word)&&word.size()>0){
		// create a list of possibilities for the words
		cout<<"word not found"<<endl;
		vector<WordFrequ> possibilities = dislexia.sortedList(word);
		cout<<possibilities.size()<<endl;
		int selection = 0;
		printMenu(word, fullL ,possibilities);
		//user input
		//cin >> selection;
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
		// do not make a change to the word
		else{
			wordout = word;
		}

	// if word in Dictionary
	}else{
			wordout = word;
	}
	return wordout;
}
string correctedComment(string line,int commentStart, string dicListP,string freqListP){
	string fullL = line;
	// creates a spell check obj from spk file
	SpellCheck dislexia(dicListP,freqListP);
	// creates a Dictionary object from the defined file, dic obj defined in helpers
	Dictionary oxy(dicListP);

	int sizeOfComment = cpp.sgln.size();
	string rest = fullL.substr(commentStart+sizeOfComment);//gets the comments without the comment char

	vector<string> words = getword(rest);
	string correctedLine="";
	int c = 0;
	// goes until rest not found
	while(words[1].size()>0 && c <20 ){
		c++;
		cout<<words[0]<<endl;
		correctedLine= correctedLine + " "+ spellCheckStep(words[0],oxy,dislexia,fullL);
		words = getword(words[1]);
	}
	// add back in the comment to the line
	// correctedLine= correctedLine + " "+ spellCheckStep(words[0],oxy,dislexia,fullL);
	string goodline = fullL.substr(0,commentStart+sizeOfComment);
	correctedLine = goodline+correctedLine;
	cout<<correctedLine<<endl;
	return correctedLine;
}
void checkFile(string fileToPath){
	// reads all of the file to be debuged in from the inpath
	string line;
	fstream in(fileToPath);
	string fullFile;

	int count =0;// emergency stop for debug purposes
	while(getline(in, line) && count < 100){
		// finds comments
		count+=1;
		int commentStart = line.find(cpp.sgln);
		int escapeChar = line.find('\\');
		cout<<commentStart<<" <-commentstart||Line-> "<<count<<"\n";
		string correctedline = "";
		if(commentStart>-1 && escapeChar==-1){// if it has a comment
			cout<<"checking spelling\n";
			correctedline =correctedComment(line,commentStart,"dicList.txt" ,"freqList.txt");
		}else{//if it doesnt have a comment
			correctedline = line;
			cout<<"not checking spelling\n";
		}
		fullFile = fullFile+correctedline+"\n";
	}
	//write changes to file
	cout<< fullFile;
	in.close();

	// ofstream rewriteFile;
	// rewriteFile.open(fileToPath+"edit");
	// rewriteFile<<fullFile;
	// rewriteFile.close();
	// //cout<<fullFile<<endl;
	// cout<<"\n\nend\n";
}
// main runner
int main(){
	cout<< "here\n";
	// checkFile("helpers.cpp");


	checkFile("testComments.h");
	cout<< "Done!!!!\n";
	return 0;
}
