#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <vector>

using namespace std;

static int min_sup = 50;

class Ck{
public:	
	int support = 0;
	map<int, int> itemset;
};

class Lk{
public:
	map<int, int> itemset;
};


int main(){
	ofstream fout; // ���� ���
	ifstream fin; // ���� �Է�
	list<Ck> ck; // Ck �Ҵ�.
	list<Lk> lk; // Lk �Ҵ�.

	list<map<int, int>> t; // transaction ����.

	int item;

	fin.open("input.txt"); // �켱 input file�� �д´�.
	if (fin.is_open() == false){ // ������ �� �Ǵ� ��� �����޽��� �߻�.
		cout << "input file open error." << endl;
		return 0;
	}


	int a = 30;
	char tempstring[100];

	int temp = 0; // ���ึ�� �Է�.
	while (!fin.eof()){ // ���� �Է� �� �迭�� ����.
		fin.getline(tempstring);
	}

	fin.close;
	//ck.push_back()




	return 0;
}
