#include<bits/stdc++.h>
using namespace std;


//得到最低位,即二进制最后面的1构成的数 
int lowbit(int& x){
	return x&-x;
} 

//取负数运算8位二进制为例 
 /*
 原数：01011000 
 先取反：10100111
 再加一：10101000 即为-x 
 */  
 
 //消去最后一位1
 int lowbit_elimination(int& x){
 	return x&(x-1);
 } 
 
 //判断两个数符号是否相反
 bool f=( (a^b)<0 )
/*
异或运算，负数最高位为1，符号不同的数异或得到负值 
*/
 
