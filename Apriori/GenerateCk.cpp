#include "Apriori.h"

Ck GenCk(Lk &l){
	Ck Candidate;
	int lsize = l.size();
	if (lsize == 0)
		return Candidate;
	int lisize = l[0].size();

	for (int i = 0; i < lsize; i++){
		for (int j = i + 1; j < lsize; j++){
			// ���� Ž���� ���� �ϳ��ϳ� ����. ���� ���Ҵ� ��� ���� ������ ���Ҹ� �ٸ��ٸ� �ĺ��� ���� �� �ִ�.
			int temp = 0;
			int check = 0;
			
			while (temp<lisize - 1){
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
				if (l[j].at(lisize - 1) > l[i].at(lisize - 1)){ // ������ ���� �̿� ���� �־���.
					Frequent = l[i];
					Frequent.push_back(l[j].at(lisize - 1));
					Candidate.push_back(Frequent);
				}
				else{
					Frequent = l[j];
					Frequent.push_back(l[i].at(lisize - 1));
					Candidate.push_back(Frequent);
				}
			}
		}
	}

	return Candidate;
}

Ck GenC1(transaction t){
	map<int, int> C1;
	int tsize = t.size();
	for (int i = 0; i < tsize; i++){
		int tsize2 = t[i].size();
		for (int j = 0; j < tsize2; j++)
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
