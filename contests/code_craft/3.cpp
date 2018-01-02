#include<iostream>
#include<cstdio>
#include<math.h>
#include<stack>
#include<vector>
#include<map>
#include<algorithm>


using namespace std;


struct point
{	
	float x,y;
};


int main()
{
	int n;
	float slope;

	while( (cin>>n) && (n > 0) )
	{

		vector< point > P(n);	
		map<float, int> M;


		for(int i=0; i < n ; ++i)
			cin>>P[i].x>>P[i].y;

		int omax=0;
		for(int i=0; i < n-1 ; ++i)
		{
			M.clear();
			for(int j=0; j < n ; ++j)
			{

				if(j != i)
				{
					slope = (P[j].y - P[i].y) / ( P[j].x - P[i].x );	
					M[slope]++;
				}
			}
		
			int max = 0;	
			for(map<float,int>::iterator i = M.begin() ; i != M.end() ; ++i)
				if(max < i->second)
						max = i->second;
	
			if(omax < max)
				max = omax;
		}

		cout<<omax<<endl;
	}
}
