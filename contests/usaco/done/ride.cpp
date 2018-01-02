/*
ID: ranjith1
PROG: ride
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;


int main()
{
	ifstream istr; istr.open("ride.in");
	string UFO,GR; istr>>UFO>>GR; istr.close();

	int ufo=1,gr=1;
	for( int i=0; i < UFO.length(); ++i) ufo = ( ufo * ( UFO[i] - 'A' + 1) )%47;
	for( int i=0; i < GR.length(); ++i) gr = ( gr * ( GR[i] - 'A' + 1) )%47;
	

	ofstream ostr; ostr.open("ride.out");
	if(ufo == gr)
		ostr<<"GO"<<endl;
	else
		ostr<<"STAY"<<endl;
	ostr.close();
	
}
