#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "spck.h"
#include "helpers.h"
using namespace std;

int main(){
	string path1 = "dicList.txt";
	string largeText ="mobytxt.txt";
	string makeFrequency = "wrdFreq.txt";
	string wordcheck = "sat";
	//char * freqEx = 'cat-7';
	//char * first = strtok(freqEx,'-'); 
	//char * last = strtok(NULL,'\n'); 
	//cout<< first <<"\t"<<last<<endl;
	SpellCheck dislexia(path1,makeFrequency);
	//dislexia.makeFrequencyList(largeText);
	vector<string>cow = dislexia.getEdit1(string("bel"));
	for(unsigned int i =0;i<cow.size();i++){
		cout<<cow[i]<<endl;
	}
	dislexia.makeFrequencyListInt(cow);
	cout<<"end\n";
	return 0;
}