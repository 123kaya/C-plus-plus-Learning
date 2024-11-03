//朴素法筛素数

void prime(int n){
	//遍历2-n
	for(int i=2; i<=n; i++){
		//存储素数
		if(!st[i]){
			primes[ans++]=i;
			
			//素数的倍数为非素数 
			for(int j=i*2; j<=n; j+=i){
				st[j]=true;
			}
		} 
	} 
} 


//线性筛法
void get_prime(int n){
	//遍历2-n 
	for(int i=2; i<=n; i++){
		
		//存储素数
		if(!st[i]){
			primes[ans++]=i;
		} 
		
		//遍历已经得到的素数
		//i从2-n, 遍历了primes的全部倍数
		for(int j=0; primes[j]<=n/i; j++){
			st[primes[j]*i]=true;
			
			/*i是primes[j]的k倍(i=primes[j]*k)，则此时rt=primes[j+k]*i,
			rt在将来可以被primes[j]筛掉，则不用primes[j+k]来筛 
		    优点：避免重复遍历rt，提高算法速度 
			 
			*/  
			if(i%primes[j]==0)break;
		} 
	} 
}
 
