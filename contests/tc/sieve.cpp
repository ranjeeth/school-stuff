#include<iostream>
#include<cmath>


const int MAX = 10000;
bool primes[MAX];


int run_sieve()
{
	for(int i=2; i < MAX; ++i)
		primes[i] = 1;

	for(int i=2; i <= sqrt(MAX); ++i)
		if(primes[i])			
		{
			for(int j=i; i*j < MAX; ++j)	//+ not using division.. start from i
				primes[i*j] = 0;		
		}
}

int main()
{

	run_sieve();
	for(int i=2; i < MAX; ++i)
		if(primes[i])
		{
			std::cout<<i<<std::endl;
		}
}
