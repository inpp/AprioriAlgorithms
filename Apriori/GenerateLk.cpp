#include "Apriori.h"



Lk GenLk(Ck &c, Lk &l){
	cout << "LK ���� ���� " << endl;
	Lk Candidate;
	Lk nextL;
	int csize = c.size();
	int lsize = l.size();
	int lisize = c[0].size()-1;
	// ���� Ž���� ���ؼ� c �߿��� min_sup�̻��� ���� ����.

	int a = c[0].size();
	cout << "��ĵ DB ���� candidate ������ : " << csize<< endl;

	for (int i = 0; i < csize; i++){
		//sup��	���� ���� ����Ž������ �����Ѵ�. ScanDB�� �̿��ؼ� ����
		if (Scan(c[i], a)/*&&CheckPruning[i]*/){
			nextL.push_back(c[i]);
		}
	}
	cout << "��ĵ DB ��" << endl;
	if (nextL.size() == 0){
		cout << "���̻� Frequent�� item�� �������� �ʽ��ϴ�." << endl;
	}
	else{
		cout << "LK ����" << nextL.size() << endl;
	}
	return nextL;
}