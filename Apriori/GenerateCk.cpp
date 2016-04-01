#include "Apriori.h"

int GenCk(Ck c, Lk l){









	return 0;
}

vector<int> GenC1(vector<vector<int>> t){
	map<int, int> C1;

	for (int i = 0; i < (int)t.size(); i++){
		for (int j = 0; j < (int)t[i].size(); j++)
			C1.insert(map<int, int>::value_type(t[i].at(j), t[i].at(j)));
	}

	vector<int> returnc1;
	for (map<int, int>::iterator pos = C1.begin(); pos != C1.end(); pos++)
		returnc1.push_back(pos->first);

	return returnc1;
}