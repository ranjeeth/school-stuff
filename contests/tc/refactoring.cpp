#include<iostream>
#include<cmath>


class Refactoring
{
public :
int refactor(int n);
void rec_refactor(int n, int f0, int *m);
};

void Refactoring::rec_refactor(int n, int f0, int* m)
{
     if(n == 1)
     {
           *m = *m + 1;
           return;
     }
     for(int i=f0; i <= sqrt(n); ++i)
     {
        if(n%i == 0)
        {
           rec_refactor(n/i, i, m);
        }
     }
     rec_refactor(1,n,m);
     return;
}

int Refactoring::refactor(int n)
{
       int m=0;
       rec_refactor(n, 2, &m);
       return m-1;
}



int main()
{

	Refactoring R;
	int n;
	while(std::cin>>n && n > 0)
	{ 
		std::cout<<R.refactor(n)<<std::endl;
	}

}
