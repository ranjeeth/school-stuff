#include<iostream>
#include<cstdio>

double h[100000];
int s[100000];
int top,t,i;
double max, area;

int main()
{
	int n;
	while(std::cin >> n && n > 0)
	{
		for(i=0; i < n ; ++i)
				std::cin>>h[i];
		top = -1;
		max = -1;
		for(i=0; i < n || (top >= 0); ++i)	
		{
			if(top == -1)
			{	
				s[++top] = i;
				continue;
			}
			t = s[top];
			if ((i == n) || h[i] < h[t])
			{	
					area = (i-t)*h[t];
					--top;
					if(top >= 0)
						area +=  (t - s[top]-1)*h[t];
					else 
						area += t * h[t];
					if(area > max)
						max = area;
					--i;
					continue;
			}
			else if(h[i] > h[t])
			{
				s[++top] = i;
				continue;
			}
			else
				s[top] = i;
		}
		printf("%.0f\n",max);	
	}
}
