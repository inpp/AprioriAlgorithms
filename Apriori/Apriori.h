#ifndef _Apriori_H
#define _Apriori_H

#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

//min_sup ��  ���ϱ�
static int min_sup = 50;


// Ck�� Lk Ŭ���� ����.
class Ck{
public:
	vector<int> itemset;
};

class Lk{
public:
	vector<int> itemset;
};

//�Լ� ���� �κ�
int FileRead(vector<vector<int>> &t);
int GenCk(Ck c, Lk l);
vector<int> GenC1(vector<vector<int>> t);

#endif