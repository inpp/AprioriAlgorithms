#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <vector>

using namespace std;

static int min_sup = 50;

//�Լ� ����
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

	list<Ck> ck; // Ck �Ҵ�.
	list<Lk> lk; // Lk �Ҵ�.

	vector<vector<int>> t; // transaction ����.
	map<int, int> itemset;

	int item;

	if (!FileRead(t)) // input.txt �Է�.
		return 0;

	//ck.push_back()




	return 0;
}
