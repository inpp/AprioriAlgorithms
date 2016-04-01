#ifndef _Apriori_H
#define _Apriori_H

#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

//min_sup 값  정하기
static int min_sup = 50;


// Ck와 Lk 클래스 선언.
class Ck{
public:
	vector<int> itemset;
};

class Lk{
public:
	vector<int> itemset;
};

//함수 선언 부분
int FileRead(vector<vector<int>> &t);
int GenCk(Ck c, Lk l);
vector<int> GenC1(vector<vector<int>> t);

#endif