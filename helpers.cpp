#include "helpers.h"
using namespace std;
// basic methods for spell checking taken from Peter Norvig
// niave appoach to limit memory usage 

WordFrequ::WordFrequ(string p,int freq){
	word = p;
	frequency = freq;
}
WordFrequ::WordFrequ(){
	word = "<empty>";
	frequency = -1;
}
Dictionary::Dictionary(){
	length = -1;
}
Dictionary::Dictionary(string path){
	pathName = path;
	fstream in(path);
	string line = "--";
	string Last ="--";
	bool isAlpha = true; 
  	
 	int count = 0,j=0;
 	ifAlphebetical[j] = 0;
 	j++;
  	while(getline(in, line)){ //read data from file object and put it into string.
        
        int strcmp = Last[0]-line[0];
        if(strcmp >0 && count>0){
        	isAlpha = false;
        }
        if(strcmp <0 && count>0){
        	ifAlphebetical[j] = count;
        	j++;
        }
        Last = line;
    	count++;
    }
  	in.close();
  	if(!isAlpha){
  		for(int i = 0; i< 26;i++){
  			ifAlphebetical[i] = -1;
  		}
  	}
  	//else{
  	// 	//cout <<"\talphebetically\n";
  	// 	for(int i = 0; i< 26;i++){
  	// 		cout << ifAlphebetical[i]<<endl;
  	// 	}
  	// }
  	length = count; 
  	
}
bool Dictionary::isFound(string inputword){
	return findIndex(inputword)>-1;
}
int Dictionary::findIndex(string inputword){
	fstream in(pathName);
	string levitate = "--";
	int indexSearch = -1; 
	if(ifAlphebetical[0]==-1){
		for(int i =0;i<length;i++){
			getline(in, levitate);
			if(levitate.compare(inputword)==0){
				indexSearch = i;
				break;
			}
		}
	}
	else{
		string a = inputword;
		transform(a.begin(), a.end(), a.begin(), ::tolower); 
		int index = int(a[0])-97;
		int startline = ifAlphebetical[index]; 
	 	for(int i =0;i<startline;i++){
			getline(in, levitate);
		}
	 	for(int i = startline+1; i<length;i++){
			getline(in, levitate);
			if(levitate.compare(inputword)==0){
				indexSearch = i;
				break;
			}
		}
	}
	in.close();
	return indexSearch; 
}
int Dictionary::getStartIndex(string word){
	if(ifAlphebetical[0]==-1){
		return -1;
	}
	else{
		string a = word;
		transform(a.begin(), a.end(), a.begin(), ::tolower); 
		int index = int(a[0])-97;
		int startline = ifAlphebetical[index]; 
		return startline+1;
	} 
}