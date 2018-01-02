#include<iostream>


int myatoi(const char * s)
{
	int val = 0;
	while(s && *s >= '0' && *s <= '9')
	{
		val = val * 10 + *s - '0';
		++s;
	}
	return val;
}

int main()
{
	std::string s;
	while(std::cin>>s)
	{
		std::cout<<myatoi(s.c_str())<<std::endl;
	}
}
