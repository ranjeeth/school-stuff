#include<iostream>
#include<string>
using namespace std;

inline int stacktop(int a, int * top)
{
	while(top[a] != -1)
		a = top[a];
	return a;
}

inline void clear(int a, int *top, int *bottom)
{
	int t;
	while(top[a] != -1)
	{	
		t = a;		
		bottom[top[a]] = -1;
		a = top[a];
		top[t] = -1;
	}
}

inline void move(int a,int b,int * top, int * bottom)
{
	top[b] = a;
	if(bottom[a] != -1)
		top[bottom[a]] = -1;	
	bottom[a] = b;
}


int main()
{
	int nBlocks;
	cin>>nBlocks;
	
	int *top,*bottom;	
	top = new int [nBlocks];	//blocks above and below each block	
	bottom = new int [nBlocks];
	for(int i=0; i < nBlocks ; ++i) top[i] = bottom[i] = -1;
	
	string mpq,ovon;
	int a,b;
	
	while( cin>>mpq && mpq != "quit")
	{
		cin>>a>>ovon>>b;
		if(a == b || stacktop(a,top) == stacktop(b,top))
				continue;
		if(mpq == "move")
				clear(a,top,bottom);
		if(ovon == "onto")
				clear(b,top,bottom);
		move(a,stacktop(b,top),top,bottom);	
	}
	
	for(int i=0; i < nBlocks ; ++i)
	{
		cout<<i<<":";
		if(bottom[i] == -1)
		{
			int a = i;
			cout<<" "<<a;
			while(top[a] != -1)
			{
				cout<<" "<<top[a];
				a = top[a];
			}	
		}
		cout<<endl;
	}

	delete [] top;
	delete [] bottom;	

}
