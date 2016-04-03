#include "Apriori.h"

int Scan(itemset &Cd, transaction &t){
	int sup = 0; 
	//아이템셋에서 transaction마다 비교해보면서 전체 다 들어있는 것을 찾는다.
	int tsize = t.size();
	int Cdsize = Cd.size();
	for (int i = 0; i < tsize; i++){
		int itempos = 0;
		int transactionpos = 0;
		int tisize = t[i].size();
		while (transactionpos<tisize){
			if (Cd[itempos] == t[i].at(transactionpos)){
				if (itempos == Cdsize - 1){
					sup++;
					break;
				}
				else{
					itempos++;
					transactionpos++;
				}
			}
			else{
				if (Cd[itempos] < t[i].at(transactionpos))
					break;
				transactionpos++;
			}
		}
	}

	if (sup >= min_sup)
		return 1;
	else
		return 0;
}