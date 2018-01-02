#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
#include<ctype.h>

using namespace std;
struct term
{
	int coeff,x_exp,y_exp;
};

bool cmp (const term &a, const term &b)
{
	if(a.x_exp > b.x_exp )
			return true;
	else if(a.x_exp == b.x_exp)
			return (a.y_exp < b.y_exp);
	else return false;
}


int read_sign(istringstream & istr)
{
	char c;
	if(!(istr>>c))
		return 0;
	if( c == '+')
		return 1;
	else if( c == '-')
		return -1;
	else
	{
		istr.putback(c);
		return 1;	
	}
}

int read_num(istringstream & istr)
{
	int n;
	char c;
	if(!(istr>>c))
		return 1;
	if(isdigit(c))
	{	
		istr.putback(c);
		n = 0;
		while(istr>>c)
		{
			if(isdigit(c))
				n = n * 10 + (c - '0');
			else
			{
				istr.putback(c);
				break;
			}
		}
	}
	else
	{
		n = 1;
		istr.putback(c);
	}
	return n;	
}

bool read_var(char &var, istringstream & istr)
{
	char c;
	if(!(istr>>c))
		return false;	
	if(c == 'x' || c == 'y')
	{
		var = c;
		return true;
	}
	else
	{
		istr.putback(c);
		return false;
	}
}

bool read_term(term &t, istringstream &istr)
{
	int exp,sign,coeff,x_exp=0,y_exp=0;
	char var;

	//read the sign
	sign = read_sign(istr);
	if(sign == 0)
		return false;

	coeff = read_num(istr);

	if(read_var(var,istr))
		{
			if(var == 'x')
				x_exp = read_num(istr);
			else if(var == 'y')
				y_exp = read_num(istr);	
		}

	if(read_var(var,istr))
		{
			if(var == 'x')
				x_exp = read_num(istr);
			else if(var == 'y')
				y_exp = read_num(istr);	
		}

	t.coeff = sign * coeff;
	t.x_exp = x_exp;
	t.y_exp = y_exp;

	return true;
}

void print_dig(int m, ostringstream &ostr1, ostringstream &ostr2)
{
	if( m == 0)
		return;
	else print_dig(m/10, ostr1, ostr2);
	ostr1<<" ";
	ostr2<<m%10;
}

void print_term(ostringstream &ostr1, ostringstream & ostr2, term &t)
{
	if(t.x_exp > 0 || t.y_exp > 0)
	{
		if(t.coeff != 1 && t.coeff != -1)
		{
			int m = (t.coeff > 0) ? t.coeff : -1 * t.coeff;
			print_dig(m, ostr1, ostr2);
		}
	}
	else
	{
		int m = (t.coeff > 0) ? t.coeff : -1 * t.coeff;
		print_dig(m, ostr1, ostr2);	
	}

	if(t.x_exp > 0)
	{
		ostr1<<" "; ostr2<<"x";
		if(t.x_exp != 1)
			print_dig(t.x_exp, ostr2, ostr1);
	}
	
	if(t.y_exp > 0)
	{
		ostr1<<" "; ostr2<<"y";
		if(t.y_exp != 1)
			print_dig(t.y_exp, ostr2, ostr1);
	}
}

void display( vector<term> &p )
{
	string line1, line2;
	ostringstream ostr1(line1),ostr2(line2);

	if( p[0].coeff < 0)
	{
		ostr1<<" "; ostr2<<"-";
	}
	print_term(ostr1, ostr2, p[0]);
	for(int i=1; i < p.size(); ++i)
	{
		ostr1<<"   ";
		if( p[i].coeff < 0)
			ostr2<<" - ";
		else ostr2<<" + ";
		print_term(ostr1, ostr2, p[i]);
	}

	cout<<ostr1.str()<<endl;
	cout<<ostr2.str()<<endl;
}

void read_poly( vector<term> &p)
{
	string line; cin>>line;
	istringstream istr(line);
	term t;

	//read term by term
	while(read_term(t,istr))
		p.push_back(t);	
}



//Sick Problem : I dont like this one
int main()
{
	vector<term> p1,p2,p3,prod;
	term t;
	char c;

	while( cin>>c && c != '#')	
	{
		cin.putback(c);

		// read polynomials 
		read_poly(p1);
		read_poly(p2);
		

		//multiply and avoid duplication of similar terms
		for(int i=0; i < p1.size(); ++i)
			for(int j=0; j < p2.size(); ++j)
			{
				t.coeff = p1[i].coeff * p2[j].coeff;
				t.x_exp = p1[i].x_exp + p2[j].x_exp;
				t.y_exp = p1[i].y_exp + p2[j].y_exp;

				bool done = false;
				for(int k=0; k < p3.size() && !done ; ++k)
					if( p3[k].x_exp == t.x_exp && p3[k].y_exp == t.y_exp)
					{
						p3[k].coeff += t.coeff;
						done = true;
					}

				if(!done)
					p3.push_back(t);
			}

		//remove zero terms
		for(int i=0; i < p3.size(); ++i)
		{
			if(p3[i].coeff != 0)
				prod.push_back(p3[i]);	
		}
		
		sort( prod.begin(), prod.end(), cmp);
		display(prod);	
		prod.clear();
		p3.clear();
		p1.clear();
		p2.clear();
	}
}
