#include "Apriori.h"


int FileRead(string filename){

	ifstream fin; // ���� �Է�

	fin.open(filename); // �켱 input file�� �д´�.
	if (fin.is_open() == false){ // ������ �� �Ǵ� ��� �����޽��� �߻�.
		cout << "input file open error." << endl;
		return 0;
	}

	int a;
	char tempstring;

	while (!fin.eof()){ // ���� �Է� �� �迭�� ����.
		vector<int> trans;
		do{
			fin >> a;
			trans.push_back(a); //����
			fin.get(tempstring); // ���๮������ Ȯ��
		} while (tempstring != 10 && !fin.eof());

		t.push_back(trans);
	}

	//input�� �� itemset�� ����.
	for (int i = 0; i < (int)t.size(); i++)
		sort(t[i].begin(), t[i].end());

	fin.close();

	return 1;
};