#include <stdio.h>
#include <stdlib.h>
#include <iostream>
//#include "cmtChckr.h"
#include "helpers.h"
#include "spck.h"
using namespace std;
void checkFile(string fileToPath){
	string path1 = "dicList.txt";
	//string largeText ="mobytxt.txt";
	string makeFrequency = "freqList.txt";
	string pythonBegin = string("\"\"\"");
	string pythonend = string("\"\"\"");
	string cCppJavaBegin = string("/*");
	string cCppJavaend = string("/*");
	string cCppJavasg = string("//");

	SpellCheck dislexia(path1,makeFrequency);
	Dictionary oxy(path1);
	string line;
	fstream in(fileToPath);
	string fullFile;
	while(getline(in, line)){
		int commentStart = line.find(cCppJavasg);
		if(commentStart>-1){
			int sizeOfComment = cCppJavasg.size();
			string k = line;
			string fin = k.substr(commentStart+sizeOfComment);
			

			int wordind = fin.find(string(" "));
			string rest = fin;
			string word = rest.substr(0,wordind);
			rest = rest.substr(wordind);
			string correctedLine;
			while(wordind>-1){
				if(!oxy.isFound(word)&&word.size()>0){
					vector<WordFrequ> possibilities = dislexia.sortedList(word);
					int selection = -1; 
					cout<<"\"" <<word<<"\""<<" was not recognized in: \""<<fin<<"\"\n";
					for(unsigned int d = 0; d<possibilities.size();d++){
						cout << possibilities[d].word<<"\t"<<d<<"||\t";
					}
					cout << "other\t"<< possibilities.size()<<endl;
					cin >> selection;
					if(selection<int(possibilities.size()+1)&&selection>=0){
						if(selection == int(possibilities.size())){
							string newOption; 
							cout<<"Correction: ";
							cin>>newOption;
							correctedLine= correctedLine+ " "+ newOption;
						}
						else correctedLine= correctedLine+ " "+ possibilities[selection].word; 
					}
					else{
						correctedLine= correctedLine+ " "+ word; 
					}

				}else{
				    correctedLine= correctedLine+ " "+ word; 
				}

				wordind = rest.find(string(" "));
			    word = rest.substr(0,wordind);
			    rest = rest.substr(wordind+1);
			}
			string goodline = k.substr(0,commentStart+sizeOfComment); 
			correctedLine = goodline+correctedLine;
			fullFile = fullFile+ correctedLine+"\n";	 
		}else{
			fullFile = fullFile+ line+"\n";
		}
		
	}
	in.close();
	ofstream rewriteFile;
	rewriteFile.open(fileToPath);
	rewriteFile<<fullFile;
	rewriteFile.close();
	//cout<<fullFile<<endl;
	cout<<"\n\nend\n";
}
int main(){
	
	string wordcheck = "sat";
	checkFile("spck.h");
	//char * freqEx = 'cat-7';
	//char * first = strtok(freqEx,'-'); 
	//char * last = strtok(NULL,'\n'); 
	//cout<< first <<"\t"<<last<<endl;
	//
	//dislexia.makeFrequencyList(largeText);
	//vector<string>cow = dislexia.getEdit1(string("aaron"));
	//for(unsigned int i =0;i<cow.size();i++){
	//	cout<<cow[i]<<endl;
	//}
	//vector<WordFrequ> listChoice = dislexia.sortedList(string("field"));
	//listChoice = dislexia.makeFrequencyListInt(cow);
	//for(unsigned int i =0;i<listChoice.size();i++){
	//	cout<<listChoice[i].word<<" "<<listChoice[i].frequency<<endl;
	//}
	//cout<<"end\n";
	return 0;
}