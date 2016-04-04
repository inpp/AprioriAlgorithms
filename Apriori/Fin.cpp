#include "Apriori.h"


int FileRead(string filename){

	ifstream fin; // 파일 입력

	fin.open(filename); // 우선 input file을 읽는다.
	if (fin.is_open() == false){ // 오픈이 안 되는 경우 에러메시지 발생.
		cout << "input file open error." << endl;
		return 0;
	}

	int a;
	char tempstring;

	while (!fin.eof()){ // 파일 입력 후 배열에 저장.
		vector<int> trans;
		do{
			fin >> a;
			trans.push_back(a); //저장
			fin.get(tempstring); // 개행문자인지 확인
		} while (tempstring != 10 && !fin.eof());

		t.push_back(trans);
	}

	//input의 각 itemset을 정렬.
	for (int i = 0; i < (int)t.size(); i++)
		sort(t[i].begin(), t[i].end());

	fin.close();

	return 1;
};