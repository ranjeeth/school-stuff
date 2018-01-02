#include<iostream>
#include<vector>

using namespace std;

const int MAX_LEN = 80 ;

//S[0 .. k - 1 ] is hard. Is S[0..k] hard??
bool isHard(int *S, int k)
{
  int max_len = (k + 1)/2;
  int matched_len;

  // length 1 was already tested
  for (int l = 2; l <= max_len; l++)
    {
    	 matched_len = 0;

	 for (int j = 0; j < l; j++)
		{
		  if ((k - j >= 0) && (k - j - l >= 0))
		    {
		      if (S[k - j] == S[k - j - l])
			  matched_len++;
		      else
			  break;
		    }
		  else
	     	 	break;
		}

       if (matched_len == l)
		return false;
    }
  return true;
}

void generate(int * S, int & nH, int k, int n, int L, int &len)
{
	//S[0..k-1] string so far constructed is hard.
	if (nH == n)
	{
		len = k;
		return ;
	}

	for(int i=0; (i < L)  && (nH < n) ; ++i)
	{
		S[k] = i;

		//checking for length one square
		if( (k - 1) >= 0 && S[k - 1] == i)
			continue; 

		if( isHard(S, k) )
		{
			++nH;
			generate(S, nH, k+1, n, L, len);
		}
	}	
}

int main()
{

	int n,L,nH,k,len;
	int S[MAX_LEN];

	while(cin>>n>>L && (n != 0 && L != 0))
	{
		for(int i=0; i < MAX_LEN; ++i)
				S[i] = 0;

		nH = 0;
		k = 0;
		// Find nth hard sequence ( generated in lexical order)
		generate(S, nH, k , n, L, len);
		
		//print it as necessary
		for(int i=0; i < len ; ++i)
		{
			if( i > 0 && i%64 == 0)
				cout<<endl;
			else if( i > 0 && i%4 == 0 )
				cout<<" ";
	
			cout<<(char)(S[i] + 'A');
		}	
		cout<<endl<<len<<endl;
	}
}
