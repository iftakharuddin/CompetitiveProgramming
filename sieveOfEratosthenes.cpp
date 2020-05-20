const int MXN = 1e6+5;
int isPrime[MXN];

void sieve(){
	isPrime[0] = isPrime[1] = 0;
	for (int i = 2; i < MXN; ++i)
		isPrime[i] = 1;
	for (int i = 2; i*i <= MXN; ++i)
	{
		if(isPrime[i]){
			for (int j = i*i; j < MXN; j += i)
			{
				isPrime[j] = 0;
			}
		}
	}
}
