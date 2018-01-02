#include<iostream>
#include<string>

using namespace std;
void insert( int *a, int j, int n);
void swap(int &a , int &b){ int t=a; a = b; b = t;}

void ins(int *a, int k, int j)
{
	int t = a[k]; 
		for(int i=k; i > j ; --i) 
			a[i] = a[i-1]; 
	a[j] = t;
}
void undo(int *a, int k, int j)
{
	int t = a[j]; 
		for(int i=j; i < k ; ++i) 
			a[i] = a[i+1]; a[k] = t; 
}

void insert( int *a, int k, int n)
{
	string indent; for(int i=0; i < k; ++i) indent += " ";		
	if(k == n)
		{ cout<<indent<<"writeln("; cout<<(char) ('a'+a[0]); for(int i=1; i < n ; ++i) cout<<","<<(char)('a'+a[i]); cout<<")"<<endl; return;}
	
	for(int j=k; j >= 0; --j)
	{

		//print necessary conditions
		if(j > 0)
		{
		if( j == k)
				cout<<indent<<"if "<<(char)(a[j-1] + 'a')<<" < "<<(char)('a' +  k)<<" then"<<endl;
		else
			cout<<indent<<"else "<<"if "<<(char)(a[j-1] + 'a')<<" < "<<(char)('a' + k)<<" then"<<endl;	
		}
		else cout<<indent<<"else"<<endl;

		//insert this element
		ins(a,k,j);	
		//continue with rest	
		insert(a,k+1,n);
		//restore the array
		undo(a,k,j);
	}	
}

int main()
{
	int m,n;
	cin>>m;
	for(int i=0; i < m ; ++i)
	{
		cin>>n;
		int a[n];

		if(i > 0) cout<<endl;
		cout<<"program sort(input,output);"<<endl;
		cout<<"var"<<endl;
		cout<<(char) ('a'); for(int i=1; i < n ; ++i) cout<<","<<(char)('a'+i); cout<<" : integer;"<<endl;
		cout<<"begin"<<endl;
		cout<<" readln("; cout<<(char) ('a'); for(int i=1; i < n ; ++i) cout<<","<<(char)('a'+i); cout<<");"<<endl;
	
		for(int j=0; j < n ; ++j) a[j] = j;
		
		//simulate insertion sort		
		insert(a,1,n);

		cout<<"end."<<endl;	
	}
}
