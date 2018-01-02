#include<iostream>

long expmodulo(long a, long b, long c) {
	long long x=1, y=a;
	while(b > 0) {
		if (b%2) {
			x = (x*y)%c;
		}
		y = (y*y) % c;
		b /= 2;
	}
	return x;
}


int main() {
	std::cout << expmodulo(2, 4, 5) << std::endl;
	std::cout << expmodulo(2, 5, 5) << std::endl;
}
