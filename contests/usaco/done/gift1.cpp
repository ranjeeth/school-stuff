/*
ID: ranjith1
PROG: gift1
*/

#include<iostream>
#include<fstream>
#include<string>
#include<map>

using namespace std;

 
int main()
{
	ifstream istr; istr.open("gift1.in");	
	int n; istr>>n;		
	string name[n]; 
	int net[n];
	map<string,int> vertex;
	for(int i=0; i < n ; ++i)
	{
		istr>>name[i];
		vertex.insert(make_pair(name[i],i));	
		net[i] = 0;
	}
	string Ustr,Vstr;
	int mU,nU,mV;
	for(int i=0; i < n ; ++i)
	{
		istr>>Ustr>>mU>>nU;
		if(nU)
			mV = (mU - mU%nU)/nU;	
		net[ vertex[Ustr] ] -= mV * nU; 
		for(int j=0; j < nU; ++j)
		{
			istr>>Vstr; 
			net[ vertex[Vstr] ] += mV;
		}	
	}
	istr.close();
		
	ofstream ostr; ostr.open("gift1.out");
	for(int i=0; i < n ; ++i)
	{
		ostr<<name[i]<<" "<<net[vertex[name[i]]]<<endl;
	}
	ostr.close();
}
