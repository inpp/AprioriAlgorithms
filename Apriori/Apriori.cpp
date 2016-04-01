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
	ofstream fout; // 파일 출력
	ifstream fin; // 파일 입력
	list<Ck> ck; // Ck 할당.
	list<Lk> lk; // Lk 할당.

	list<map<int, int>> t; // transaction 저장.

	int item;

	fin.open("input.txt"); // 우선 input file을 읽는다.
	if (fin.is_open() == false){ // 오픈이 안 되는 경우 에러메시지 발생.
		cout << "input file open error." << endl;
		return 0;
	}


	int a = 30;
	char tempstring[100];

	int temp = 0; // 개행마다 입력.
	while (!fin.eof()){ // 파일 입력 후 배열에 저장.
		fin.getline(tempstring);
	}

	fin.close;
	//ck.push_back()




	return 0;
}
