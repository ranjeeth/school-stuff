#include<iostream>
#include<cmath>

const int MAX = 1000;
bool primes[MAX];

void run_sieve()
{
	for(int i=2; i < MAX; ++i) primes[i] = 1;
	primes[0] = primes[1] = 0;

	for(int i=2; i <= sqrt(MAX); ++i)
		if(primes[i])
		{
			for(int j=i; j*i < MAX; ++j)
				primes[i*j] = 0;
		}
}




void goldbach(int n)
{
	for(int i = 2; i <= n/2; ++i)	
	{
		if(primes[i] && primes[n-i])
			std::cout<<n<<" = "<<i<<"+"<<n-i<<std::endl;
	}
	
}



int main()
{
	run_sieve();
	int n;
	while(std::cin>>n && n >= 4)
	{
		goldbach(n);
	}
}
