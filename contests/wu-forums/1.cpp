#include<iostream>
#include<cstdlib>
#include<ctime>


int swap(int * a, int  * b)
{
	int t = *a; *a = *b; *b = t;
}

int partition(int * a, int l, int r)
{
	int pi = l + (r-l+1)/2;
	int p = a[pi];
	
	swap(a+pi, a+r);
	int i=l-1,j=0;
	for(j=l; j <= r-1; ++j)	
	{
		if(a[j] < p)
		{
			i = i + 1;
			swap(a+i, a+j);
		}
	}
	i = i + 1;
	swap(a+i,a+r);
	return i;
}

void quick_sort(int * a, int l, int r)
{
	if(l >= r)
		return;
	int m = partition(a,l,r);
	quick_sort(a,l,m-1);
	quick_sort(a,m+1,r);	
}

void reverse(int *a, int l, int r)
{
	int i=l,j=r;
	while(i < j)
	{
		swap(a+i, a+j);
		++i; --j;
	} 
}

void rotate(int * a, int n, int k)
{
	reverse(a,0,k-1);
	reverse(a,k,n-1);
	reverse(a,0,n-1);	
}

int rotated_binary_search(int *a, int l, int r, int k)
{

	while( l <= r)
	{
		int m = (l + r)/2;
		if( a[l] < a[r])	
		{
			if(a[m] < a[k])
				l = m + 1;
			else if( a[m] > a[k])
				r = m - 1;
			else return m;
		}
		else
		{
			if(a[m] == a[k])
				return m;

			if( a[m] < a[r])
			{
				if( a[m] < a[k])
				{
					if(a[r] >= a[k])
						l = m + 1;
					else
						r = m - 1;
				}		
				else
					r = m - 1;
			} 
			else
			{
				if( a[m] > a[k])
				{
					if(a[l] <= a[k])
						r = m - 1;
					else
						l = m + 1;
				}
				else
					l = m + 1;		
			}	
		}
	}

	return -1;

}

int main()
{
	int n=0, r=0, k=0;

	srand(time(NULL));	

	
	while(std::cin >> n && n > 0)
	{
		
	int a[n];
	r = rand()%n;
	k = rand()%n;
	

	bool USE_UNIQUE_ELEMENTS = true;
	if (USE_UNIQUE_ELEMENTS) // unique elements 
	{
		
		for(int i=0; i < n; ++i)
			a[i] = i;		
		for(int i=0; i < n; ++i)
			swap(a+i, a + rand()%(n-i) + i);
	
	}
	else // random elements
	{
		for(int i=0; i < n; ++i)
			a[i] = rand()%n; //std::cin>>a[i];
	}



	for(int i=0; i < n; ++i)
		std::cout<<a[i]<<" ";
	std::cout<<std::endl;

	quick_sort(a,0,n-1);
	
	for(int i=0; i < n; ++i)
		std::cout<<a[i]<<" ";
	std::cout<<std::endl;
	
	rotate(a, n, r);	
	
	for(int i=0; i < n; ++i)
		std::cout<<a[i]<<" ";
	std::cout<<std::endl;

	int ki = -1;
	ki = rotated_binary_search(a, 0, n-1, k);
	std::cout<<"("<<n<<","<<r<<") : "<<k<<" --> "<<ki<<std::endl;
	}
}
