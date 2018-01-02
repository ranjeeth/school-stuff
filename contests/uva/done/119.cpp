
#include<iostream>
#include<string>
#include<map>

using namespace std;

 
int main()
{
	int n,ic=0; 
	while(cin>>n)
	{	
		if(ic > 0) cout<<endl;
		++ic;	
		string name[n]; 
		int net[n];
		map<string,int> vertex;
		for(int i=0; i < n ; ++i)
		{
			cin>>name[i];
			vertex.insert(make_pair(name[i],i));	
			net[i] = 0;
		}
	
		string Ustr,Vstr;
		int mU,nU,mV;
		for(int i=0; i < n ; ++i)
		{
			cin>>Ustr>>mU>>nU;
			//net[ vertex[Ustr] ] = mU; ??
			if(nU)
				mV = (mU - mU%nU)/nU;	
			net[ vertex[Ustr] ] -= mV * nU; 
			for(int j=0; j < nU; ++j)
			{
				cin>>Vstr; 
				net[ vertex[Vstr] ] += mV;
			}	
		}
		
		for(int i=0; i < n ; ++i)
		{
			cout<<name[i]<<" "<<net[vertex[name[i]]]<<endl;
		}
	}
}
