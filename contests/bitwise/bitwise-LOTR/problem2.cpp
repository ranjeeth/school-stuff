#include<iostream>


using namespace std;
int main()
{
	int k;
	cin>>k;
	int p,c = 0,s[k];
	
	s[0] = 0;
	
	for(int i = 1 ; i < k ; ++i)
		s[i] = i + s[i-1];

	
	int j = 1;
	int i = 0;
	
	
	do{
		
	while( (s[j] - s[i]) < k  && j < k)
		j++;	
	
	
	if(j == k)
		break;
	
	
	if((s[j] - s[i]) == k)
	{
		c++;
		j++;
	}
	
	else
		while((k -(s[j-1] - s[i])) < j )	
			i++;
	
	}while(j <= k/2 + 1);
	
	cout<<c<<endl;
}
