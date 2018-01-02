#include<iostream>
#include<string>
#include<map>

using namespace std;

enum {NIL,NODE};

bool complete(map<int,int> T)
{
	if( T.find(0) == T.end())
		return false;

	map<int,int>::iterator j = T.begin();

	for(++j; j != T.end() ; ++j)
		if(T.find( (j->first - 1)/2) == T.end() )
			return false;
	return true;
}


int read_node(int &v, int &ind)
{
	char c;
	cin>>c>>c;

		if(c == ')')
		{
			v = -1; ind = -1;
			return NIL;
		}
		else
		{

			cin.putback(c);
			cin>>v>>c>>c;
			ind = 0;
			if(c != ')')
			{
				int i=0;
				do 
					if(c == 'L')
						ind = ind * 2 + 1;
					else 
						ind = (ind + 1) *2;
				while(cin>>c && ( c == 'L' || c == 'R'));
			}
			
			return NODE;
		}
}

int main()
{

	int v,i,n;
	char t;
	bool c;	
	map<int,int> T;

	while(cin>>t)
	{
		cin.putback(t);
		T.clear();

		c = true;

		while( read_node(v,i) != NIL)
		{	
			if( T.find(i) != T.end())
			{
				c = false;
			}
			else 
				T[i] = v;
		}

		c = c & complete(T);

		if( c )
		{
			map<int,int>::iterator j = T.begin();
			cout<<j->second;
			for(++j; j != T.end() ; ++j)
					cout<<" "<<j->second;
			cout<<endl;
		}
		else cout<<"not complete"<<endl;
	}	
}
