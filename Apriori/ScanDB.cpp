#include "Apriori.h"

int Scan(itemset &Cd, Lk &l, transaction &t){
	int sup = 0;
	//아이템셋에서 transaction마다 비교해보면서 전체 다 들어있는 것을 찾는다.
	for (int i = 0; i < t.size(); i++){
		int itempos = 0;
		int transactionpos = 0;
		while (transactionpos<t[i].size()){
			if (Cd[itempos] == t[i].at(transactionpos)){
				if (itempos == Cd.size() - 1){
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