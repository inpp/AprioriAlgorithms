#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <vector>

using namespace std;

int FileRead(vector<vector<int>> &t){

	ifstream fin; // ���� �Է�

	fin.open("input.txt"); // �켱 input file�� �д´�.
	if (fin.is_open() == false){ // ������ �� �Ǵ� ��� �����޽��� �߻�.
		cout << "input file open error." << endl;
		return 0;
	}

	int a;
	char tempstring;
	int row = 0; // ���ึ�� �������Ѽ� �����ϴ� ���� �ٲ�..

	while (!fin.eof()){ // ���� �Է� �� �迭�� ����.
		vector<int> transaction;
		do{
			int column = 0; //������ŭ ������.
			fin >> a;
			transaction.push_back(a); //����
			column++;
			fin.get(tempstring); // ���๮������ Ȯ��
		} while (tempstring != 10 && !fin.eof());

		t.push_back(transaction);
		row++; // ���� ���� / ���� ���� ������ ������ �ǹ�
	}

	fin.close();

	return 1;
};