#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <vector>

using namespace std;

static int min_sup = 50;

//함수 선언
int FileRead(vector<vector<int>> &t);


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

	list<Ck> ck; // Ck 할당.
	list<Lk> lk; // Lk 할당.

	vector<vector<int>> t; // transaction 저장.
	map<int, int> itemset;

	int item;

	if (!FileRead(t)) // input.txt 입력.
		return 0;

	//ck.push_back()




	return 0;
}
