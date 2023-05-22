#include<stdio.h>
#include<string.h>

int main()
{
    char x[101];
    char t[101];
       scanf("%s",x);
        scanf("%s",t);

    int size = strlen(x);
    
   int  j=0;
    for( int i = size-1; i>=0 ;i--)
    {
        if(t[j] != x[i])
        {
          printf("NO");
          return 0;
        }
        j++;
    }

    printf("YES");
}