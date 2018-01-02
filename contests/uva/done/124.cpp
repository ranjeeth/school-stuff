#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>


using namespace std;


int R[26][26];
int N[26];

vector<string> S;

void insert(string &s, int k, string &v, int n)
{
	if(k == n)
	{	
		S.push_back(s);
		return;
	}

	int key = v[k];
	bool r;
	for(int p = 0; p <= k; ++p)
	{
		r = true;		
		for(int j=0; j < p ; ++j)
			if( R[ N[ key - 'a'] ][ N[ s[j] - 'a' ] ] == 1)
				r = false;

		for(int j = p ; j < k ; ++j)
			if( R[ N[s[j] - 'a'] ][ N[ key - 'a'] ] == 1)
				r = false;
		if(r)
		{
			for(int j = k; j > p ; --j)
				s[j] = s[j-1];
			s[p] = key;
			
			insert(s,k+1,v,n);
			
			for(int j=p; j < k ; ++j)
				s[j] = s[j+1];
			s[k] = key;		
		}	
	}	
}

//one of the stupid solutions that  I could conjure up
int main()
{
	string vline,cline;
	char a,b,c;
	int n,na,nb,nc;

	int ncase = 0;

	while(getline(cin,vline))
	{
		if(vline.length() == 0)
			break;

		if(ncase > 0)
			cout<<endl;
		++ncase; 

		for(int i=0; i < 26 ; ++i)
			for(int j=0; j < 26 ; ++j)
				R[i][j] = 0;
		
		S.clear();
		string v;
		istringstream vstr(vline);
		n = 0;
		while(vstr>>a)
		{
			na = a - 'a';
			N[na] = n++;
			v.push_back(a);
		}
		getline(cin,cline);
		istringstream cstr(cline);
		while(cstr>>b>>c)
		{
			nb = N[b - 'a'];
			nc = N[c - 'a'];

			R[ nb ][ nc ] = 1;
			for(int i=0; i < n ; ++i)
			{
				if (R[ i ][ nb ] == 1)
					R[ i ][ nc ] = 1;
				if( R[ nc ][ i] == 1)
					R[ nb ][ i ] = 1;
			}	
		}

		string s = v;
		sort(v.begin(), v.end());	
		insert(s, 0, v, n);
		sort(S.begin(),S.end());
		for(int i=0; i < S.size() ; ++i)
			cout<<S[i]<<endl;		
	}		
}
