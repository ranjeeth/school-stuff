#include<iostream>
#include<cstdio>
#include<math.h>
#include<stack>
#include<vector>
using namespace std;

# define PI		3.14159265358979323846

struct point
{	
	int x,y;
	float t;
};
inline bool cmp( point &a , point &b )
{
	if( a.y < b.y ) return true;
	else if(a.y == b.y) return (a.x > b.x);
		else return false;	
}
inline void swap( point &a, point &b){ point t = a; a = b; b = t;}
inline float angle( point &a, point &o)
{
	float dy = a.y - o.y, dx = a.x - o.x;
	if( dx == 0) return PI/2;
	else if( dx > 0) return atan(fabs(dy/dx));
	     else return  PI - atan( fabs(dy/dx) ) ;
}
inline int dist(point &a, point &b){ return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y); }
bool is_left(point &a, point &b, point &c)
{
	return  (((b.x - a.x) * (c.y - a.y) - (c.x - a.x)*( b.y - a.y))) > 0;
}

vector<point> convex_hull( vector<point> &k)
{
	//choose p0 as the point with miny (maxx in case of tie)
	for(int i = k.size()-1; i > 0;  --i)
		if( cmp(k[i],k[i-1]) ) swap(k[i],k[i-1]);
	// compute polar angles and sort on it
	k[0].t = 0; for(int i=1; i < k.size() ; ++i) k[i].t = angle(k[i],k[0]);
	for(int i=1; i < k.size()-1 ; ++i)
		for( int j=k.size()-1; j > i ; --j)
		{
			if( k[j].t < k[j-1].t)
				swap(k[j],k[j-1]);	
		}

	// eliminate duplicates
	vector<point> h;
	h.push_back(k[0]);
	for(int i=1,j=1; i < k.size(); ++i)
		if( k[i].t != h[j-1].t)
		{
			h.push_back(k[i]);
			j = j + 1;
		}
		else
			if( dist(k[i],h[0]) > dist(h[j-1],h[0]))
				h[j-1] = k[i];
	stack<point> S;
	S.push(h[0]);
	S.push(h[1]);
	point p1,p2;
	int i=2;
	while(i < h.size())
	{
		p1 = S.top(); S.pop();
		p2 = S.top(); S.push(p1);
		
		if(is_left(p2,p1,h[i]))
		{
			S.push(h[i]); 
			i = i + 1;
		}
		else S.pop();							
	}
	h.clear();
	while(S.empty() == false)
	{
		h.push_back(S.top());
		S.pop();
	}
	return h;
}

bool inside(vector<point> &h, point &p)
{
	for(int i=0; i < h.size(); ++i)
		if( is_left(h[i],h[(i+1)%h.size()],p))
			return false;
	return true;
}


float area( vector<point> & P)
{
	float a = 0;
	for(int i=0; i < P.size(); ++i)
		a += P[i].x * P[(i+1)%P.size()].y -  P[i].y * P[(i+1)%P.size()].x;
	a /= 2;
	return ( a >= 0) ? a : -a;
}

int main()
{
	int n;
	vector< vector<point> > H;
	vector<float> A;
	vector< point > k;
	point c;
	bool d[H.size()];
	float sum=0;
	while(cin>>n && n != -1)
	{
		for(int i=0; i < n ; ++i)
		{
			cin>>c.x>>c.y;
			k.push_back(c);
		}
		//find convex hull of each individual kingdom
		H.push_back( convex_hull(k) );
		k.clear();
	}

	for(int i=0; i < H.size(); ++i)
	{
		d[i] = false;
		A.push_back(area(H[i]));	
	}	

	while(cin>>c.x>>c.y)
	{
		//find which kingdoms are attacked
		for( int i=0; i < H.size(); ++i)
			d[i] = d[i] | inside(H[i],c);				
	}

	// print the sum of their areas
	for(int i=0; i < H.size(); ++i)
		if(d[i])
			sum += A[i];
	printf("%.2f\n",sum);	
}
