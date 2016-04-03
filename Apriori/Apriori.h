#ifndef _Apriori_H
#define _Apriori_H

#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

//min_sup ��  ���ϱ�
extern int min_sup;
extern unordered_map<string, int> Sup_Freq;


// Ck�� Lk Ŭ���� ����.
typedef vector<int> itemset;
typedef vector<itemset> Ck;
typedef vector<itemset> Lk;
typedef vector<vector<int> > transaction;

//�Լ� ���� �κ�
int FileRead(vector<vector<int> > &t);
Ck GenCk(Lk &l);
Lk GenLk(Ck &c, Lk &l, transaction &t);
Ck GenC1(vector<vector<int> > t);
int Scan(itemset &Cd, transaction &t);
void CoutOutput(Lk lk, transaction t);


#endif