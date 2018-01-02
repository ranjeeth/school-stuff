#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int binSrch( vector<string> &V , string & key)
{	
	int l = 0, h = V.size()-1,m;
	while( l <= h)
	{
		m = (l + h)/2;
		if( V[m] > key)
			h = m - 1;
		else if( V[m] < key)
			l = m + 1;
		else return m;
	}

	return -1;
}

int main()
{
	vector<string> StopWords,KeyWords,UKeyWords;
	vector< vector<string> > Titles;


	string sw,kw;
	while(cin>>sw && sw != "::")
		StopWords.push_back(sw);

	sort(StopWords.begin(),StopWords.end());


	string title, pkw;
	vector<string> wlist;
	while(getline(cin,title))
	{
		wlist.clear();	
		for(int i=0; i < title.length(); ++i) if(title[i] >= 'A' && title[i] <= 'Z') title[i] = title[i] - 'A' + 'a';

		if(title.length() > 0)
		{
			istringstream ist(title);
			while(ist>>pkw)
			{
				wlist.push_back(pkw);
				if(binSrch(StopWords,pkw) == -1)
					KeyWords.push_back(pkw);
			}
			Titles.push_back(wlist);
		}

		
	}
	
	sort(KeyWords.begin(), KeyWords.end());	
	vector<string>::iterator  juniq = unique(KeyWords.begin(), KeyWords.end());
	KeyWords.erase(juniq, KeyWords.end());

	string uc;

	for(int i=0; i < KeyWords.size()  ; ++i)
	{
		uc = KeyWords[i];
		for(int j=0; j < uc.length(); ++j)
				if(uc[j] >= 'a' && uc[j] <= 'z') uc[j] = uc[j] - 'a' + 'A';
		UKeyWords.push_back(uc);
	}

	for(int i=0; i < KeyWords.size() ; ++i)
		for(int j=0; j < Titles.size(); ++j)
			for(int k=0; k < Titles[j].size(); ++k)
				if(Titles[j][k] == KeyWords[i])
				{
					if(k == 0)
						cout<<UKeyWords[i];
					else cout<<Titles[j][0];

					for(int p=1; p < Titles[j].size() ; ++p)
					{
						if( k == p)
							cout<<" "<<UKeyWords[i];
						else cout<<" "<<Titles[j][p];
					}
					cout<<endl;
				}		
}
