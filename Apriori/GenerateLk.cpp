#include "Apriori.h"

Lk GenLk(Ck &c, Lk &l){
	Lk Candidate;
	Lk nextL;
	int csize = c.size();
	int lsize = l.size();
	int lisize = c[0].size()-1;
	// ���� Ž���� ���ؼ� c �߿��� min_sup�̻��� ���� ����.

	int a = c[0].size();

	for (int i = 0; i < csize; i++){
		//sup��	���� ���� ����Ž������ �����Ѵ�. ScanDB�� �̿��ؼ� ����
		if (Scan(c[i], a)/*&&CheckPruning[i]*/){
			nextL.push_back(c[i]);
		}
	}
	if (nextL.size() == 0){
		cout << l[0].size() << "���� ū k���� ������ Frequent�� item�� �������� �ʽ��ϴ�." << endl;
	}
	else{
		cout << "L" << nextL[0].size() << "���� " << nextL.size() << endl;
	}
	return nextL;
}