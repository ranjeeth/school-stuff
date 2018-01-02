#include<iostream>

int main()
{
	long long int N;
	int t;
	std::string ans;

	//for(int i=1; (i <= 26*26+26) && (N = i); ++i)
	while(std::cin>>N)
	{
		ans = "";
		while(N > 0)		
		{
			t = (N-1)%26;
			N = (N-1)/26;
			//std::cout<<t<<std::endl;
			ans += 'A'+t;
		}
		
		for(int i=0, j=ans.length()-1; i < j; ++i,--j)
		{
			char t = ans[i];
			ans[i] = ans[j];
			ans[j] = t;
		}
		
		std::cout<<ans<<std::endl;
	}
	
	
}
