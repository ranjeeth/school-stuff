#include<iostream>
#include<list>
#include<vector>
#include<algorithm>

using namespace std;


struct triple{int xmin,height,xmax;};


//straight forward : maintain an active building list and a full building list
// search at break points and update the lists
int main()
{
	list<triple> BT,ABT;
	triple a;
	vector<int> bp;

	while(cin>>a.xmin>>a.height>>a.xmax)
	{
		BT.push_back(a);
		bp.push_back(a.xmin);
		bp.push_back(a.xmax);
	}

	sort(bp.begin(),bp.end());
	vector<int>::iterator end = unique(bp.begin(),bp.end());

	int curr;
	
	for(vector<int>::iterator i = bp.begin(); i != end ; ++i)
	{
		int x = *i;
		for(list<triple>::iterator j = BT.begin() ; j != BT.end() && j->xmin == x;)
			{
				ABT.push_back(*j);
				list<triple>::iterator t;
				t = j;
				++j;
				BT.erase(t);
			}
		for(list<triple>::iterator j = ABT.begin() ; j != ABT.end();)
				if(j->xmax == x)
				{
					list<triple>::iterator t;
					t = j;
					++j;
					ABT.erase(t);
				}
				else ++j;
		int max = 0;
		for(list<triple>::iterator j = ABT.begin() ; j != ABT.end();++j)
			if(j->height > max)
				max = j->height;
		if(max != curr)
			cout<<x<<" "<<max<<" ";
		curr = max;
	}	
	cout<<endl;
}

