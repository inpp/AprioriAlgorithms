#include "Apriori.h"

Lk GenLk(Ck &c, Lk &l){
	Lk Candidate;
	Lk nextL;
	
	// ���� Ž���� ���ؼ� c �߿��� min_sup�̻��� ���� ����.
	for (int i = 0; i < c.size(); i++){
		for (int j = i+1; j < c.size(); j++){
			// ���� Ž���� ���� �ϳ��ϳ� ����. ���� ���Ҵ� ��� ���� ������ ���Ҹ� �ٸ��ٸ� �ĺ��� ���� �� �ִ�.
			int temp = 0;
			int check = 0;
			while (temp<c[i].size()-1){
				if (c[i].at(temp) != c[j].at(temp)){
					temp++;
					check = 1;
					break;
				}
			}
			if (check == 0){ // ���� ��� k-1�� subset�� frequent�ϴٸ�, lk�� �ĺ��� �ִ´�.
				itemset Frequent = c[i];
				Frequent.push_back(c[j].at(c[j].size()-1));
				Candidate.push_back(Frequent);
			}
		}
	}
	
	cout << "test" << endl;
	for (int i = 0; i < Candidate.size(); i++){
		cout << Candidate[i].at(0) << " ";
		cout << Candidate[i].at(1) << endl;
	}
	// Lk �� support�� ���� min_sup �̻��� ���� lk�� �־��ش�.
	// Candidate�� �� �ִ� ���� sup�� ���� �ȴ�.
	for (int i = 0; i < Candidate.size(); i++){
		//sup�� ���� ���� ����Ž������ �����Ѵ�. ScanDB�� �̿��ؼ� ����
	}


	return nextL;
}