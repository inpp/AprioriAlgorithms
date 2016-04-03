#include "Apriori.h"

int Scan(itemset &Cd, int Cdsize){
	int sup = 0; 
	//아이템셋에서 transaction마다 비교해보면서 전체 다 들어있는 것을 찾는다.

	for (int i = 0; i < tsize; i++){
		int itempos = 0;
		for(int j=0;j<tisize[i];j++){
			if (Cd[itempos] < t[i][j])
				break;
			else if (Cd[itempos] == t[i][j]){
				if (itempos == Cdsize - 1){
					sup++;
					break;
				}
				else{
					itempos++;
				}
			}
		}
	}

	if (sup >= min_sup){
		string key;
		for (int i = 0; i < Cdsize; i++){
			ostringstream ostr;
			ostr << Cd[i];
			key+=ostr.str();
			if(i<Cdsize-1)
				key += ',';
		}
		//cout << key << "sup : " << sup/5 << endl;
		Sup_Freq.insert(unordered_map<string, int>::value_type(key, sup));
		return 1;
	}
	else
		return 0;
}