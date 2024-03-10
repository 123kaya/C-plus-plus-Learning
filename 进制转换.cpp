#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
typedef long long ll;
int Innum;
int Outnum;
string In;
string Out = "";

ll To_10(){
	ll num = 0;
	int len = In.length();
	for(int i = len-1; i >= 0; i--){
		if(In[i] == '0'||In[i] == '1'||
           In[i] == '2'||In[i] == '3'||In[i] == '4'||
		   In[i] == '5'||In[i] == '6'||In[i] == '7'||
		   In[i] == '8'||In[i] == '9'){
		   	num += (In[i]-'0')*pow(Innum,len-i-1);
		   }
		else if(In[i] == 'A'||In[i] == 'B'||
		In[i] == 'C'||In[i] == 'D'||In[i] == 'E'||
		In[i] == 'F'){
			num += (In[i]-'A'+10)*pow(Innum,len-1-i);//需要注意使用len-i-1
			//而不是i
		}
	}
	return num;
}

void To_Out(ll num){
	int yu;

	while(num != 0){
		yu = num % Outnum;
		num/= Outnum;
		if(yu <= 9) Out += yu+'0';
		else{
			Out += (yu+'A'-10);
		}
	}
}
int main(){
	cin >> Innum >> In >> Outnum;
	ll num = To_10();
	//cout << num << endl;
	To_Out(num);
	reverse(Out.begin(),Out.end());
	cout << Out << endl;
	return 0;
}
