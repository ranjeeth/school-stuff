#include<stdio.h>
#include<math.h>

int main(){

	//double handles this!!. very funny :)
	double n,p;
  	while( scanf("%lf %lf",&n,&p) == 2 )
	{
	    printf("%.lf\n",floor(pow(p,1.0/n)+0.5));
	}

} 
