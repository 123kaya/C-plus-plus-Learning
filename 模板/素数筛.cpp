//���ط�ɸ����

void prime(int n){
	//����2-n
	for(int i=2; i<=n; i++){
		//�洢����
		if(!st[i]){
			primes[ans++]=i;
			
			//�����ı���Ϊ������ 
			for(int j=i*2; j<=n; j+=i){
				st[j]=true;
			}
		} 
	} 
} 


//����ɸ��
void get_prime(int n){
	//����2-n 
	for(int i=2; i<=n; i++){
		
		//�洢����
		if(!st[i]){
			primes[ans++]=i;
		} 
		
		//�����Ѿ��õ�������
		//i��2-n, ������primes��ȫ������
		for(int j=0; primes[j]<=n/i; j++){
			st[primes[j]*i]=true;
			
			/*i��primes[j]��k��(i=primes[j]*k)�����ʱrt=primes[j+k]*i,
			rt�ڽ������Ա�primes[j]ɸ��������primes[j+k]��ɸ 
		    �ŵ㣺�����ظ�����rt������㷨�ٶ� 
			 
			*/  
			if(i%primes[j]==0)break;
		} 
	} 
}
 
