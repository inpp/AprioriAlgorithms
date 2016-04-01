#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <vector>

using namespace std;

int FileRead(vector<vector<int>> &t){

	ifstream fin; // 파일 입력

	fin.open("input.txt"); // 우선 input file을 읽는다.
	if (fin.is_open() == false){ // 오픈이 안 되는 경우 에러메시지 발생.
		cout << "input file open error." << endl;
		return 0;
	}

	int a;
	char tempstring;
	int row = 0; // 개행마다 증가시켜서 저장하는 곳을 바꿈..

	while (!fin.eof()){ // 파일 입력 후 배열에 저장.
		vector<int> transaction;
		do{
			int column = 0; //개수만큼 저장함.
			fin >> a;
			transaction.push_back(a); //저장
			column++;
			fin.get(tempstring); // 개행문자인지 확인
		} while (tempstring != 10 && !fin.eof());

		t.push_back(transaction);
		row++; // 행의 개수 / 다음 번에 저장할 공간을 의미
	}

	fin.close();

	return 1;
};