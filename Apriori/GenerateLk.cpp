#include "Apriori.h"



Lk GenLk(Ck &c, Lk &l, transaction &t){
	cout << "LK ���� ���� " << endl;
	Lk Candidate;
	Lk nextL;
	int csize = c.size();
	int lsize = l.size();
	int lisize = c[0].size()-1;
	// ���� Ž���� ���ؼ� c �߿��� min_sup�̻��� ���� ����.

	//pruning ���� ����
	//c �߿��� ������ ���� 2���� ���Ե� k-1 subset �� l�� ���ԵǾ����� ���� ���� ������.
	/*cout << "pruning ���� " << endl;
	vector<int> CheckPruning;
	if (lsize!=0)  
	for (int i = 0; i < csize; i++){ // ������ Candidate�� ��� ���غ���.
		int setcheck = 0;
		int subsetcheck = 0;
		for (int pos = 0; pos < lisize+1; pos++){ //��� k-1 subset�� �ĺ������Ѵ�. ��� �ڿ� �� �� �� �ϳ��� ������ ���� �����Ƿ� ����.
			int temp = 0;
			for (int j = 0; j < lsize; j++){
				// ���� Ž���� ���� �ϳ��ϳ� ����. ��� subset�� lk�� ���ԵǾ� �ִٸ� �ĺ��� ���� �� �ִ�. �� �� pos�� �ִ� ���� ���� ���� �κ�����.
				subsetcheck = 0;
				temp = 0;
				int temp2 = 0;
				while (temp2 < lisize){ // �񱳸� �����Ѵ�. lisize������ ���Ұ� ��� ������ �� subset�� ���, ���� temp==pos�̸� ��������.
					if (temp == pos)
						temp++;
					else if (c[i].at(temp) != l[j].at(temp2)){ //���� �ٸ� ���� ���� ���Ұ� ������ ���� l�� ���Ѵ�.
						break;
					}
					else if (temp == lisize){ // ���� ������ ���ұ��� ���ٸ�  subsetcheck = 1�� �־��ش�.
						subsetcheck = 1;
					}
					else{ // ���� ���Ұ� ���ٸ� ���� ���Ҹ� ���Ѵ�.
						temp++;
						temp2++;
					}
				}
				if (subsetcheck == 1) // ���� ������ ���ұ��� ���ٸ� �׸� �����ϰ� ���� pos���� ã�ƺ���. �ƴ϶�� ���� li���� ã�ƺ���.
					break;
			}
			if (subsetcheck == 0) // ���� subsetcheck�� 0�̸�(subset�� �ٸ��� �ִٸ�) ����, 1�̸� ���� pos���� ���غ�
				break;
			else if (pos > lisize - 2) // ���� pos�� 2���� ������ ������ ���Ҹ� ���� subset���� ��� ���ٸ� 1�� �־��ش�.
			{
				setcheck = 2;
				break;
			}
		}

		if (setcheck == 2)
			CheckPruning.push_back(1);
		else
			CheckPruning.push_back(0);
	}
	else
	for (int i = 0; i < csize; i++)
		CheckPruning.push_back(1);
	// Lk �� support�� ���� min_sup �̻��� ���� lk�� �־��ش�.
	// Candidate�� �� �ִ� ���� sup�� ���� �ȴ�.
	cout << "pruning �� " << endl;*/
	cout << "��ĵ DB ���� candidate ������ : " << csize<< endl;

	for (int i = 0; i < csize; i++){
		//sup��	���� ���� ����Ž������ �����Ѵ�. ScanDB�� �̿��ؼ� ����
		if (Scan(c[i], t)/*&&CheckPruning[i]*/){
			nextL.push_back(c[i]);
		}
	}
	cout << "��ĵ DB ��" << endl;
	if (nextL.size() == 0){
		cout << "���̻� Frequent�� item�� �������� �ʽ��ϴ�." << endl;
	}
	else{
		cout << "LK ����" << endl;
	}
	CoutMaximal(l, nextL);// Maximal itemset�� ���ϰ� ��� ���.
	return nextL;
}