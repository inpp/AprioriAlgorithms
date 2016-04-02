#include "Apriori.h"

Ck GenCk(Lk l){









	return l;
}

Ck GenC1(vector<vector<int>> t){
	map<int, int> C1;
	for (int i = 0; i < (int)t.size(); i++){
		for (int j = 0; j < (int)t[i].size(); j++)
			C1.insert(map<int, int>::value_type(t[i].at(j), t[i].at(j)));
	}
	
	Ck returnc1;
	for (map<int, int>::iterator pos = C1.begin(); pos != C1.end(); pos++)
	{
		itemset tempis;
		tempis.push_back(pos->first);
		returnc1.push_back(tempis);
	}

	return returnc1;
}