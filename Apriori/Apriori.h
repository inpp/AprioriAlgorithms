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
typedef vector<int> itemset;
typedef vector<itemset> Ck;
typedef vector<itemset> Lk;

//�Լ� ���� �κ�
int FileRead(vector<vector<int>> &t);
Ck GenCk(Lk &l);
Lk GenLk(Ck &c, Lk &l);
Ck GenC1(vector<vector<int>> t);

#endif