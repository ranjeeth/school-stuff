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
		int p = 0,t,ng;
		for(int i=0; i < n || (top >= 0); ++i)	
		{
			if(top == -1)
			{
				push(i,p);
				p = 0;
				continue;
			}
			t = s[top].index;
			ng = s[top].ngeq;
			if ((i == n) || h[i] < h[t])
			{	
					p += ng + 1;	
					double area = 0;
					area = (i-t+ng)*h[t];
					pop();	
					if(area > max)
						max = area;
					--i;
					continue;
			}
			else if(h[i] > h[t])
			{
				push(i,p);
				p = 0;
				continue;
			}
			else
			{
					s[top].index = i;
					s[top].ngeq += p + 1;
					p = 0;	
			}
		}
		printf("%.0f\n",max);	
	}
}
