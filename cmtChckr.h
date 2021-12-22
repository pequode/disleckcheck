#ifndef CMTCHCKR_H
#define CMTCHCKR_H

#include <string>
#include <iostream>
#include<bits/stdc++.h> 
#include <fstream>
// a class to run my spell checking program 
#include "spck.h"
class Comment{
	public:
		Comment();
		Comment(std::string ms, std::string me,std::string s){
			multiLinestart=ms;
			multiLineend=me;
			singleLine=s;
		}
		std::string multiLinestart;
		std::string multiLineend;  
		std::string singleLine;
};
class CommentChecker
{
	public:
		CommentChecker(){
			goodByDic = SpellCheck(path1,makeFrequency);
			python = Comment(std::string("\"\"\""),std::string("\"\"\""),std::string("#"));
			cCppJava = Comment(std::string("/*"),std::string("*/"),std::string("#"));
		}
		void runRecusively(std::string startPath);
		void checkFile(std::string path);
	private:
		std::string path1 = "dicList.txt";
		std::string largeText ="mobytxt.txt";
		std::string makeFrequency = "freqList.txt";
		SpellCheck goodByDic;
		Comment python;
		Comment cCppJava;

};
#endif