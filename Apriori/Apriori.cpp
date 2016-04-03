#include "Apriori.h"

unordered_map<string, int> Sup_Freq;
int min_sup = 5;
int tsize;
vector<int> tisize;
transaction t; // database�� transaction ��� ����.

int main(){

	Ck ck; // Ck �Ҵ�.
	Lk lk; // Lk �Ҵ�.

	 

	if (!FileRead()) // input.txt �Է�.
		return 0;
	tsize = t.size();
	for (int i = 0; i < tsize; i++)
		tisize.push_back(t[i].size());
	//input �Է� �� C1 ����. C1�� Ư���� ����̹Ƿ� ���� �����Ѵ�.
	ck = GenC1(t);
	lk = GenLk(ck, lk);

	//Lk�� Ck�� ��������� ����
	while (lk.size() > 0){
		ck = GenCk(lk);
		lk = GenLk(ck, lk);
		if(lk.size()>0)CoutOutput(lk);// ��� ���.
	}

	
	return 0;
}