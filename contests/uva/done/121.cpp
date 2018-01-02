#include<iostream>
#include<math.h>


using namespace std;


int skew(float w, float h)
{

	int n = (int)floor(w);
	int m = 1 + (int) floor( (h - 1)/ (sqrt(0.75f)) );	

	//cout<<n<<" "<<m<<endl;	
	if( w - n >= 0.5 )
	{
		return n * m;
	}
	else
	{
		//floor of m/2 by default
		return n*m - m/2;	
	}

}

int main()
{
	float a,b;
	int p,q,r,m;
	bool s;

	while(cin>>a>>b)
	{
		// find the number of pipes that can be fit
		// with the three arrangements 
		p = (int)(floor(a) * floor(b));
		q = skew(a,b);
		r = skew(b,a);


		//find max and print
		m =  p < q ? q : p;
		m =  m < r ? r : m;

		cout<<m<<" ";
		if(p != m)
			cout<<"skew";
		else 
			cout<<"grid";
		cout<<endl;			
	}
	
}
