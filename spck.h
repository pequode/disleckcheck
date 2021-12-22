#ifndef SPCK_H
#define SPCK_H

#include <string>
#include <iostream>
#include<bits/stdc++.h> 
#include <fstream>
#include "spck.h"
#include "helpers.h"
#include "algs.h"
// basic methods for spell checking taken from Peter Norvig
// niave appoach to limit memory usage 

class SpellCheck{
	public:
		SpellCheck();
		SpellCheck(std::string Dicpath,std::string frequPath);
		void makeFrequencyList(std::string bigTextLoc);
		std::vector<WordFrequ> makeFrequencyListInt(std::vector<std::string>a);
		std::vector<std::string> getEdit1(std::string badWord);
		// string * getEdit2(string badWord);
		std::vector<WordFrequ> sortedList(std::string badWord);
	private:
		Dictionary oxy; 
		std::string DictionaryLocation;
		std::string FrequencyListLoc;
		std::string freqDelim = "-";
};
#endif
