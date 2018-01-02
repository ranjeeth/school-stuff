#include<iostream>
#include<string>
#include<climits>

using namespace std;

int main()
{

	string s;
	int E[26][26],L[26],D[26];
	int nv,sum=0;
	int p,q;
	
	while(cin>>s)
	{
		sum = 0;
		for(int i=0; i < 26 ; ++i) 
			{
				L[i] = -1; 
				D[i] = 0;
				for(int j=0; j < 26 ; ++j) 
					E[i][j] = INT_MAX;
			}
		nv = 0;
		do
		{	// read graph
			int u = s[0] - 'a', v = s[s.size()-1] - 'a';
			
			if(L[u] == -1)
				L[u] = nv++;
			if(L[v] == -1)
				L[v] = nv++;

			E[L[u]][L[v]] = E[L[v]][L[u]] = s.size();		
			++D[L[u]];
			++D[L[v]];
			sum += s.size();

		}while(cin>>s && s != "deadend");	


		p = -1; q = -1;
		for(int i=0; i < nv-1 ; ++i)
			if(D[i]%2)
			{
				p = i;
				break;
			}

		for(int i=nv-1; i > p ; --i)
			if(D[i]%2)
			{
				q = i;
				break;
			}

		
		if( p != -1)
		{
			//djikstra (very inefficeint but okay)	
			int d[nv],m[nv],f=0,min,minu,P[nv];	
			
			for(int i=0; i < nv; ++i)
			{
				d[i] = INT_MAX;
				m[i] = -1;
			}
			d[p] = 0;
				
			while( f != nv )
			{
				min = INT_MAX;
				for(int u=0; u < nv; ++u)
					if(m[u] == -1 && d[u] < min)
					{	
						min = d[u];
						minu = u;
					}
				
				++f;
				m[minu] = 1;

				for(int v=0; v < nv ; ++v)
					if( m[v] == -1 && E[minu][v] < INT_MAX)
					{
						if( d[v] > min + E[minu][v])
						{
							d[v] = min + E[minu][v];
							P[v] = minu;
						}
					}
			}

			cout<<sum+d[q]<<endl;
		}
		else
			cout<<sum<<endl;
			
	}	
}
