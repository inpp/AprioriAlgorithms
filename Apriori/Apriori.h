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

// Ck�� Lk Ŭ���� ����.
typedef vector<int> itemset;
typedef vector<itemset> Ck;
typedef vector<itemset> Lk;
typedef vector<vector<int> > transaction;


//min_sup ��  ���ϱ�
extern int min_sup;
extern unordered_map<string, int> Sup_Freq;
extern int tsize;
extern vector<int> tisize;
extern transaction t;
extern ofstream f;

//�Լ� ���� �κ�
int FileRead(string filename);
Ck GenCk(Lk &l);
Lk GenLk(Ck &c, Lk &l);
Ck GenC1(vector<vector<int> > t);
int Scan(itemset &Cd, int a);
void CoutOutput(Lk lk);


#endif