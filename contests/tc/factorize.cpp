#include<iostream>
#include<cmath>


void find_factors(int n)
{
	//for(int i=2; n != 1 ; ++i)
	for(int i=2; i <= sqrt(n) ; ++i)
	{
		if(n%i == 0)
		{
			std::cout<<i<<" ";
			n /= i;
			--i;
		}
	}
	if(n > 1)
		std::cout<<n<<" ";
	std::cout<<std::endl;
}


int main()
{
	int n; 

	while(std::cin>>n && n > 0)
	{
		find_factors(n);
	}
}
