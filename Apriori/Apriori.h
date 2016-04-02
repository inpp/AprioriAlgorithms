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
typedef vector<int> itemset;
typedef vector<itemset> Ck;
typedef vector<itemset> Lk;

//함수 선언 부분
int FileRead(vector<vector<int>> &t);
Ck GenCk(Lk &l);
Lk GenLk(Ck &c, Lk &l);
Ck GenC1(vector<vector<int>> t);

#endif