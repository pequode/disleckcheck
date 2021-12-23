#ifndef HELPERS_H
#define HELPERS_H

#include <string>
#include <iostream>
#include<bits/stdc++.h>
#include <fstream>
// basic methods for spell checking taken from Peter Norvig
// niave appoach to limit memory usage

class WordFrequ
{
	public:
		WordFrequ();
		WordFrequ(std::string k,int l);
		std::string word;
		int frequency;
		friend bool operator>(const WordFrequ& a, const WordFrequ& b) {
         return (a.frequency>b.frequency);
        }
        friend bool operator>=(const WordFrequ& a, const WordFrequ& b) {
         return (a.frequency>=b.frequency);
        }
        friend bool operator<(const WordFrequ& a, const WordFrequ& b) {
         return (a.frequency<b.frequency);
        }
        friend bool operator<=(const WordFrequ& a, const WordFrequ& b) {
         return (a.frequency<=b.frequency);
        }
        friend bool operator==(const WordFrequ& a, const WordFrequ& b) {
         return (a.frequency==b.frequency&&(b.word.compare(a.word)==0));
        }

};

class Dictionary{
	public:
		Dictionary();
		Dictionary(std::string path);// set path name veriable and check to see if its alphebetically, if yes then run find starts lines
		// else populate with garbage -1
		int getStartIndex(std::string word);
		bool isFound(std::string inputword); // returns 1 on success and 0 on fail
		int findIndex(std::string inputword);
		int length;
	private:
		std::string pathName;
		int  ifAlphebetical[26];
};

class Comment{
	public:
		Comment();// error in this case
		Comment(std::string singleLine);
		Comment(std::string singleLine, std::string multiLine1, std::string multiLine2);// set Comment char for single line
		// not a structure because I might want to move the searching element to this obj
		std::string sgln;
		std::string ml1;
		std::string ml2;
		bool hasMulti; 
};

#endif
