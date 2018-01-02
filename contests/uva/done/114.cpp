#include<iostream>
#include<vector>

using namespace std;

//these simplify checking collision with walls
enum { RIGHTWALL=0,UPWALL,LEFTWALL,DOWNWALL,BUMPER,FREE};
enum {RIGHT=0,UP,LEFT,DOWN};
struct bumper{ int c,v; };
struct pinball{ int x,y,d,l,s; };

int main()
{

	int m,n,cw,p; 
	cin>>m>>n>>cw>>p;

	int G[m+1][n+1];
	bumper B[m+1][n+1];

	//Set up the grid	
	for(int i=1; i <= m ; ++i )
		for(int j=1; j <= n ; ++j )
			G[i][j] = FREE;
			
	for(int i=1; i <= m ; ++i )
	{
		G[i][1] = DOWNWALL;
		G[i][n] = UPWALL;
	}
	
	for(int i=1; i <= n ; ++i )
	{
		G[1][i] = LEFTWALL;
		G[m][i] = RIGHTWALL;
	}

	int x,y;
	for(int i=0; i < p ; ++i) 
	{
		cin>>x>>y;
		G[x][y] = BUMPER; 
		cin>>B[x][y].v>>B[x][y].c;	
	}


	pinball ball;
	int newx,newy;
	int sum = 0,curr;

	while(cin>>ball.x>>ball.y>>ball.d>>ball.l)
	{
		ball.s = 0;
		
		while( ball.l > 0)
		{
			// find new pos
			newx = ball.x;
			newy = ball.y;
			switch(ball.d)
			{
				case RIGHT : newx += 1; break;
				case LEFT : newx -=  1; break;
				case UP : newy += 1; break;
				case DOWN : newy -= 1; break;	
			}

			ball.l = ball.l - 1;


			curr = G[newx][newy];	

			//did it collide (add score if the ball is still alive)
			if( (curr == BUMPER) && (ball.l > 0))
			{
				ball.s =  ball.s + B[newx][newy].v;
				ball.l =  ball.l - B[newx][newy].c;
				ball.d  = (ball.d + 3)% 4;
			}
			else if( ball.d == curr)	// check for walls . we 'enum'ed walls and dirs this way 
			{
				ball.d  =  (ball.d + 3)%4;
				ball.l = ball.l - cw;
			}
			else
			{
				ball.x = newx;
				ball.y = newy;
			}	
		}

		sum += ball.s;
		cout<<ball.s<<endl;	
	}
	cout<<sum<<endl;	
}
