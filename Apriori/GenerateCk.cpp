#include "Apriori.h"

Ck GenCk(Lk &l){
	Ck Candidate;
	for (int i = 0; i < l.size(); i++){
		for (int j = i + 1; j < l.size(); j++){
			// ���� Ž���� ���� �ϳ��ϳ� ����. ���� ���Ҵ� ��� ���� ������ ���Ҹ� �ٸ��ٸ� �ĺ��� ���� �� �ִ�.
			int temp = 0;
			int check = 0;
			while (temp<l[i].size() - 1){
				if (l[i].at(temp) != l[j].at(temp)){
					check = 1;
					break;
				}
				else{
					temp++;
				}
			}
			if (check == 0){ // ���� ������ ���Ҹ� �ٸ��ٸ�, lk�� �ĺ��� �ִ´�.
				itemset Frequent = l[i];
				if (l[j].at(l[j].size() - 1) > l[i].at(l[i].size() - 1)){ // ������ ���� �̿� ���� �־���.
					Frequent = l[i];
					Frequent.push_back(l[j].at(l[j].size() - 1));
					Candidate.push_back(Frequent);
				}
				else if (l[j].at(l[j].size() - 1) < l[i].at(l[i].size() - 1)){
					Frequent = l[j];
					Frequent.push_back(l[i].at(l[i].size() - 1));
					Candidate.push_back(Frequent);
				}
			}
		}
	}


	return Candidate;
}

Ck GenC1(transaction t){
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
