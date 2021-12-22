#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "algs.h"
using namespace std;

int main(){
	vector <int> randomList{412,1234,124212,112,90,21,1234,2134,1,3,4};
	cout<<"\t\tBEFORE___________________\n\n";
	for (unsigned int i =0;i<randomList.size();i++){
		cout<<randomList[i]<<"-";
	}
	
	vector <int> sortedList = classicAlgs().MergeSortedlist<int>(randomList);
	
	cout<<"\n\t\tAfter___________________\n\n";
	for (unsigned int i =0;i<sortedList.size();i++){
		cout<<sortedList[i]<<"-";
	}
	cout<<"\n";
	return 0; 
}