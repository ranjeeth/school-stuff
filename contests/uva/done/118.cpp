#include<iostream>
#include<string>

enum{ FREE,SCENTED };
using namespace std;

int main()
{

	int B[51][51];
	int m,n;
	cin>>m>>n;
	for(int i=0; i <= m ; ++i)
		for(int j=0; j <= n ; ++j)
			B[i][j] = FREE;
	
	int x,y; char d;	
	bool lost;
	string cmd;
	while(cin>>x>>y>>d)
	{
	
		lost = false;
		cin>>cmd;	
		for(int i=0; i < cmd.size()  && !lost; ++i)
		{
			if(cmd[i] == 'R')
			{
				switch(d)
				{
					case 'N' : d = 'E'; break;
					case 'E' : d = 'S'; break;
					case 'S' : d = 'W'; break;
					case 'W' : d = 'N'; break;
				}
			}
			else if( cmd[i] == 'L')
			{
				switch(d)
				{
					case 'N' : d = 'W'; break;
					case 'E' : d = 'N'; break;
					case 'S' : d = 'E'; break;
					case 'W' : d = 'S'; break;
				}
			} 
			else 
			{
				int nx=x, ny=y;
				switch(d)
				{
					case 'N' : ny += 1; break;
					case 'E' : nx += 1; break;
					case 'S' : ny -= 1; break;
					case 'W' : nx -= 1; break;
				}	
				if( ( nx < 0 || nx > m) || (ny < 0 || ny > n))
				{
					if( B[x][y] != SCENTED)
					{
						B[x][y] = SCENTED;
						lost = true;
						cout<<x<<" "<<y<<" "<<d<<" LOST"<<endl;
					}
				}
				else
				{
					x = nx; y = ny;
				}
			}	
		}
		if(!lost)
			cout<<x<<" "<<y<<" "<<d<<endl;
			
	}		
}
