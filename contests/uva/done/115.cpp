#include<iostream>
#include<map>
#include<vector>
#include<string>

using namespace std;
const int MAX = 300;

int is_ancestor(int a, int b, int *p)
{
	int d=0,t=b;
	while( t != -1)
	{
		if( p[t] == a)
			return d;
		else t = p[t];		
		d = d + 1;
	}
	return -1;	
}

bool cousins(int a, int b, int *p, int &m, int &o)
{
	int ta = a;
	int da = 0, db ;
	while( ta != -1)
	{
		if( (db = is_ancestor(p[ta],b,p) ) >= 0)
		{
			m = da;
			o = db;
			return true;
		}
		ta = p[ta];
		da = da + 1;	
	}		
	return false;
}

int main()
{
	map< string, int> names;
	string child,parent;
	int p[MAX];

	int n=0;
	// store parent-child information
	while((cin>>child>>parent) && ( child != "no.child" || parent != "no.parent") )
	{
		if(names.find(parent) == names.end())
		{
				names[parent] = n++;
				p[ names[parent] ] = -1;
		}
		if(names.find(child) == names.end() )
				names[child] = n++;
		p[ names[child] ] = names[parent];
	}

	string first,second;
	int f,s;
	int d,m,o;
	int k,j;
	while( cin>>first>>second)
	{
		if( (names.find(first) == names.end()) || (names.find(second) == names.end()) )
			cout<<"no relation"<<endl;
		else
		{
			//see if one is the ancestor of other
			f = names[first];
			s = names[second];
			if( (d = is_ancestor(f,s,p)) >= 0)
			{
				for(int i=1; i < d; ++i)
					cout<<"great ";
				if( d > 0) cout<<"grand ";
				cout<<"parent"<<endl;
			}
			else if( (d = is_ancestor(s,f,p)) >= 0)
			{
				for(int i=1; i < d; ++i)
					cout<<"great ";
				if( d > 0) cout<<"grand ";
				cout<<"child"<<endl;	
			}
			//see if there is a path in the underlying undirected tree
			else if( cousins(f,s,p,m,o) == true)
			{
				k = ( m < o ) ? m : o;
				j = ( m < o) ? o - m : m - o;
				
				if(k == 0 && j == 0)
					cout<<"sibling"<<endl;
				else
				{
					cout<<k<<" cousin";
					if( j > 0)
						cout<<" removed "<<j;
					cout<<endl;
				}				
			}	
			else cout<<"no relation"<<endl;
		}
	}
}
