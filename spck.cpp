
#include "spck.h"
using namespace std;
SpellCheck::SpellCheck(string Dicpath,string frequPath){
	DictionaryLocation = Dicpath;
	FrequencyListLoc = frequPath;
	Dictionary k(DictionaryLocation);
	oxy = k;
}
void SpellCheck::makeFrequencyList(string bigTextLoc){
	fstream in(bigTextLoc);
	WordFrequ Freelist[oxy.length];
	string line; 
	while(getline(in, line,' ')){
		int foundHere = oxy.findIndex(line);
		cout<<line<<"-";
        if(foundHere>-1){
			Freelist[foundHere].word = line;
			Freelist[foundHere].frequency ++;
        }
	}
	in.close();

	ofstream freqList;
	freqList.open(FrequencyListLoc);
	for(int i =0;i<oxy.length;i++){
		if(Freelist[i].frequency != -1){
			freqList<<Freelist[i].word<<"-"<<Freelist[i].frequency<<"\n";
			cout<<Freelist[i].word<<"-"<<Freelist[i].frequency<<"\n";
		}
	}
	freqList.close();
}
vector<string> SpellCheck::getEdit1(string badWord){
	string letters = "abcdefghijklmnopqrstuvwxyz";
	int strLength = badWord.size();
	vector<string> deletions;
	vector<string> transposes;
	vector<string> replace;
	vector<string> insert;  
	for(int i = 0; i<strLength;i++){
		//deletions
		string newStringdel = badWord;
		string newStringtrans = badWord;
		string newStringinsert = badWord;
		newStringdel.replace(i,1,"");
		deletions.push_back(newStringdel);
		//transpositions 
		//each letter before
		if(i<strLength-1){
			string a(1,newStringtrans[i]); 
			string b(1,newStringtrans[i+1]); 
			//cout<<a<<"\t"<<b<<endl;
			newStringtrans.replace(i,1,b);
			newStringtrans.replace(i+1,1,a);
			transposes.push_back(newStringdel);
		}
		//instertions 
		for(int k =0;k<26;k++){
			string newInsert = badWord;
			string insertletter(1,letters[k]);
			newInsert.insert(i,insertletter);
			insert.push_back(newInsert);
			//cout<<newInsert<<" ";
		}
		//replacements
		for(int k =0;k<26;k++){
			string newReplace = badWord;
			string repletter(1,letters[k]);
			newReplace.replace(i,1,repletter);
			replace.push_back(newReplace);
			//cout<<newReplace<<" ";
		}
		//cout<<"\n";
		//cout<<newStringdel<<endl;
		//cout<<newStringtrans<<endl;
	}
	for(int k =0;k<26;k++){
			string newInsert = badWord;
			string insertletter(1,letters[k]);
			newInsert.insert(strLength,insertletter);
			insert.push_back(newInsert);
			//cout<<newInsert<<" ";
	}
	vector<string>OKWords;
	for(unsigned int i = 0;i<deletions.size();i++){
		if(oxy.isFound(deletions[i])){
			OKWords.push_back(deletions[i]);
		}
	}
	for(unsigned int i = 0;i<insert.size();i++){
		if(oxy.isFound(insert[i])){
			OKWords.push_back(insert[i]);
		}
	}
	for(unsigned int i = 0;i<replace.size();i++){
		if(oxy.isFound(replace[i])){
			OKWords.push_back(replace[i]);
		}
	}
	for(unsigned int i = 0;i<transposes.size();i++){
		if(oxy.isFound(transposes[i])){
			OKWords.push_back(transposes[i]);
		}
	}
	return OKWords;
}

vector<WordFrequ> SpellCheck::makeFrequencyListInt(vector<string>){
	vector<WordFrequ> FreqList;
	cout<< "check";
	return FreqList;
}
/*
class SpellCheck{
	public:
		SpellCheck(string Dicpath,string textPath);
		wordFrequ* makeFrequencyList();
		string * getEdit1(string badWord);
		string * getEdit2(string badWord);
		string * possiblilities(string badWord);
		float confidence(string word,dictionary Length);
		string  correction(string badWord);
	private:
		wordFrequ * ccat; 
		string DictionaryLocation;
		string BigTextReferanceLocation; 
		string * edit1;
		string * edit2;
}; 

*/