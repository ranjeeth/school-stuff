#include<iostream>
#include<ctype.h>

using namespace std;

enum { LPAREN=1, RPAREN, NUMBER};
enum { NIL=1, LEAF, INTERNAL};

//parse routine
void get_token(int &tt, int &v)
{
	char c;
	while( (cin >> c) && isspace(c));
	if( c == '(')
	{		
		tt = LPAREN; v = c;
		return;
	}

	if( c == ')')
	{
		tt = RPAREN; v = c;
		return;
	}

	if( isdigit(c))
	{
		int r=0;
		while( isdigit(c) )
		{
			r = r * 10 + (c - '0');
			cin>>c;
		}
		cin.putback(c);
		tt = NUMBER; v = r;
		return; 
	}

	if( c == '-')
	{
		get_token(tt,v);
		v *= -1;
		return;	
	}	
}


bool  read_tree(int n, int *nt )
{
	int tt,v;
	int lnt, rnt;
	bool lp, rp; 
	
	get_token(tt,v);  // '('
		get_token(tt,v); // n or ')'
		//null tree
		if( tt == RPAREN)
		{
			*nt = NIL;
			return false;
		}
		else
		{
			* nt = INTERNAL; 

			int r = v;	
			lp = read_tree( n-r, &lnt);
			rp = read_tree( n-r, &rnt);
	
			get_token(tt,v);	// ')'
			//if leaf 	
			if( (lnt == NIL) && (rnt == NIL))
			{
				*nt = LEAF;
				return ( n == r);
			}
			else
				return (lp || rp);	
		}		
}

int main()
{
	int n,nt;

	while( cin >> n)
	{
		
		bool p = read_tree( n, &nt );	
		if( nt == NIL)
			cout<<"no"<<endl;
		else 
			if(p) cout<<"yes"<<endl;
			else cout<<"no"<<endl;	
	}	
}
