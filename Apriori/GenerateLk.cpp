#include "Apriori.h"



Lk GenLk(Ck &c, Lk &l, transaction &t){
	Lk Candidate;
	Lk nextL;

	// ���� Ž���� ���ؼ� c �߿��� min_sup�̻��� ���� ����.

	//pruning ���� ����

	
	// Lk �� support�� ���� min_sup �̻��� ���� lk�� �־��ش�.
	// Candidate�� �� �ִ� ���� sup�� ���� �ȴ�.
	for (int i = 0; i < c.size(); i++){
		//sup�� 3���� ���� ����Ž������ �����Ѵ�. ScanDB�� �̿��ؼ� ����
		if (Scan(c[i], l, t)){
			nextL.push_back(c[i]);
		}
	}
	cout << "Print nextLk" << endl;
	for (int i = 0; i < nextL.size(); i++){
		for (int j = 0; j < nextL[i].size();j++){
			cout << nextL[i].at(j) << " ";
		}
		cout << endl;
	}
	if (nextL.size() == 0){
		cout << "k = " << l[0].size() << "�̻��� Frequent�� item�� �������� �ʽ��ϴ�." << endl;
	}

	return nextL;
}