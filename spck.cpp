
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
			cout<<Freelist[i].word<<freqDelim<<Freelist[i].frequency<<"\n";
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
		}
		//replacements
		for(int k =0;k<26;k++){
			string newReplace = badWord;
			string repletter(1,letters[k]);
			newReplace.replace(i,1,repletter);
			replace.push_back(newReplace);
		}
	}
	for(int k =0;k<26;k++){
			string newInsert = badWord;
			string insertletter(1,letters[k]);
			newInsert.insert(strLength,insertletter);
			insert.push_back(newInsert);
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

vector<WordFrequ> SpellCheck::makeFrequencyListInt(vector<string>a){
	vector<WordFrequ> FreqList;
	fstream in(FrequencyListLoc);
	string line;
	while(getline(in, line)){
		string Beg;
		string fin;
		string lyn = line;
		int begind = lyn.find(freqDelim);
		Beg = lyn.substr(0,begind);
		fin = lyn.substr(begind+1);
		int freqnum = stoi(fin);
		WordFrequ temp(Beg,freqnum);
		FreqList.push_back(temp);
	}
	in.close();
	vector<WordFrequ> finalWF;
	// could have done this step in the while loop
	for(unsigned int i = 0; i< a.size();i++){
		bool found = false;
		for(unsigned int k =0;k<FreqList.size();k++){
			if (a[i].compare(FreqList[k].word)==0){
				finalWF.push_back(FreqList[k]);
				found = true;
				break;
			}
		}
		if (!found){
			WordFrequ oneInstance(a[i],-1);
			finalWF.push_back(oneInstance);
		}
	}
	return finalWF;
}

vector<WordFrequ> SpellCheck::sortedList(string badWord){
	vector<string> edits = getEdit1(badWord);
	vector<WordFrequ> unstortedWordFrequ = makeFrequencyListInt(edits);
	vector<WordFrequ> sortedList = classicAlgs().MergeSortedlist<WordFrequ>(unstortedWordFrequ);// merge sort uses too much memory because it is recursive 
	vector<WordFrequ>nonDuplicate;
	for(unsigned int i = 0; i<sortedList.size();i++){
		bool test = true;
		for(unsigned int k = 0;k<nonDuplicate.size();k++){
			 if (sortedList[i]==nonDuplicate[k]){
			 	test = false;
			 	break;
			 }
		}
		if(test){
			nonDuplicate.push_back(sortedList[i]);
		}

	}
	return nonDuplicate;
}
