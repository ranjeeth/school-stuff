#include<cstdio>

int main()
{
        char c;
        int rem,m,n,ans;
        while( (scanf("%c",&c) == 1 ) && (c != '#') )
        {
                rem=0;
                while(c!='\n')
                {
                        m = c>=0 ? c : 256+c;

                        rem=(rem*256+m)%34943;

			scanf("%c",&c);	
                }

                rem=(((long long int)rem)*256*256)%34943;

                ans = rem==0?0:34943-rem;

		printf("%2.2X %2.2X\n",ans/256,ans%256);
        }

}

