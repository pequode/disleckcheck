#ifndef ALGS_H
#define ALGS_H

#include <string>
#include <iostream>
#include<bits/stdc++.h> 
#include <fstream>
class classicAlgs
{
	public:
		template <typename T> 
		std::vector<T> MergeSortedlist(std::vector<T> List){
			if(List.size() == 1) {
				return List;
			}
			else{
				std::vector<T> subList1;
				std::vector<T> subList2; 
					unsigned int middle = List.size()/2;
					subList1 = List;
					subList1.resize(middle);
					for(unsigned int i =middle;i<List.size();i++){
						subList2.push_back(List[i]);
					}
					subList1 = MergeSortedlist<T>(subList1);
					subList2 = MergeSortedlist<T>(subList2);
				std::vector<T> newCombined = Merge<T>(subList1,subList2);
					return newCombined;
			}
		}	
		
	private:
		template <typename T> 
		std::vector<T> Merge(std::vector<T> List1,std::vector<T> List2){
			int NumList1 = List1.size();
			int NumList2 = List2.size();
			std::vector<T> Merged;	
			while(NumList1>0&&NumList2>0){
				int ind1 = List1.size()-NumList1;
				int ind2 = List2.size()-NumList2;
				if (List1[ind1]<List2[ind2]){
					Merged.push_back(List2[ind2]);
					NumList2 --;
				}
				else{
					Merged.push_back(List1[ind1]);
					NumList1 --;
				}
			}
			if(NumList1>0){
				for(int i =0;i<NumList1;NumList1--){
					int ind1 = List1.size()-NumList1;
					Merged.push_back(List1[ind1]);
				}
			}
			else if(NumList2>0){
				for(int i =0;i<NumList2;NumList2--){
					int ind2 = List2.size()-NumList2;
					Merged.push_back(List2[ind2]);
				}
			}
			return Merged;
		}
};

#endif