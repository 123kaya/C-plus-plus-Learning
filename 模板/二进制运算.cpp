#include<bits/stdc++.h>
using namespace std;


//�õ����λ,��������������1���ɵ��� 
int lowbit(int& x){
	return x&-x;
} 

//ȡ��������8λ������Ϊ�� 
 /*
 ԭ����01011000 
 ��ȡ����10100111
 �ټ�һ��10101000 ��Ϊ-x 
 */  
 
 //��ȥ���һλ1
 int lowbit_elimination(int& x){
 	return x&(x-1);
 } 
 
 //�ж������������Ƿ��෴
 bool f=( (a^b)<0 )
/*
������㣬�������λΪ1�����Ų�ͬ�������õ���ֵ 
*/
 
