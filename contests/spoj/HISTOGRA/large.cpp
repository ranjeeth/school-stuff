#include<iostream>
#include<cstdio>


double h[100000];
struct sentry{ int index; int ngeq;};
struct sentry s[100000];
int top;
double max;

void push(int i, int n)
{ 
	++top;
	s[top].index = i;
	s[top].ngeq = n;
}

void pop()
{
	--top;
}

int main()
{
	int n;
	while(std::cin >> n && n > 0)
	{
		for(int i=0; i < n ; ++i)
				std::cin>>h[i];
		top = -1;
		max = -1;

		for(int i=0; i < n; ++i)	
		{
			if(top == -1)
			{
				push(i,0);
				continue;
			}
			if(h[i] > h[s[top].index])
			{
				push(i,0);
				continue;
			}

			if (h[i] < h[s[top].index])
			{	
				int p = 0;
				while(top >= 0 && h[i] < h[s[top].index])
				{
					int t = s[top].index;
					p += s[top].ngeq + 1;	
					double area = 0;
					area = (i-t)*h[t] + s[top].ngeq * h[t];
					pop();	
					if(area > max)
						max = area;
					//std::cout<<"popping : "<<t<<" height : "<<h[t]<<" area : "<<area<<std::endl;
				}
				
				if( (top < 0) || (top >= 0 && h[i] > h[s[top].index]))
				{
					//std::cout<<"pushing : "<<i<<" height : "<<h[i]<<" num greater : "<<p<<std::endl;
					push(i,p);
				}
				else if(h[i] == h[s[top].index])
				{
					s[top].index = i;
					s[top].ngeq += p + 1;
				}
			}
			else
			{
					s[top].index = i;
					s[top].ngeq += 1;
				
			}
		}
		
		while(top >= 0)
		{
			int t = s[top].index;
			double area = 0;
			area = (n-t)*h[t] + s[top].ngeq * h[t];
			pop();
			//std::cout<<"popping : "<<t<<" height : "<<h[t]<<" area : "<<area<<std::endl;
			if(area > max)
				max = area;
		}
		printf("%.0f\n",max);
		
	}
}
