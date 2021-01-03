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
		SpellCheck(std::string Dicpath,std::string frequPath);
		// string * checkList(string badWord);
		void makeFrequencyList(std::string bigTextLoc);
		std::vector<WordFrequ> makeFrequencyListInt(std::vector<std::string>a);
		std::vector<std::string> getEdit1(std::string badWord);
		// string * getEdit2(string badWord);
		// float confidence(string word,dictionary Length);
		std::vector<WordFrequ> sortedList(std::string badWord);
	private:
		//wordFrequ * ccat;
		Dictionary oxy; 
		std::string DictionaryLocation;
		std::string FrequencyListLoc;
		std::string freqDelim = "-";
		// string * edit1;
		// string * edit2;
}; 

/*
import re
from collections import Counter

def words(text): return re.findall(r'\w+', text.lower())

WORDS = Counter(words(open('big.txt').read()))

def P(word, N=sum(WORDS.values())): 
    "Probability of `word`."
    return WORDS[word] / N

def correction(word): 
    "Most probable spelling correction for word."
    return max(candidates(word), key=P)

def candidates(word): 
    "Generate possible spelling corrections for word."
    return (known([word]) or known(edits1(word)) or known(edits2(word)) or [word])

def edits1(word):
    "All edits that are one edit away from `word`."
    letters    = 'abcdefghijklmnopqrstuvwxyz'
    splits     = [(word[:i], word[i:])    for i in range(len(word) + 1)]
    deletes    = [L + R[1:]               for L, R in splits if R]
    transposes = [L + R[1] + R[0] + R[2:] for L, R in splits if len(R)>1]
    replaces   = [L + c + R[1:]           for L, R in splits if R for c in letters]
    inserts    = [L + c + R               for L, R in splits for c in letters]
    return set(deletes + transposes + replaces + inserts)

def edits2(word): 
    "All edits that are two edits away from `word`."
    return (e2 for e1 in edits1(word) for e2 in edits1(e1))
*/
#endif
