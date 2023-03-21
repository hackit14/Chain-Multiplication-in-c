#include<stdio.h>
#include<math.h>
#include<limits.h>

int main()
{

    
    int a[]={1,2,3,4,3};
    int n=sizeof(a)/sizeof(a[0]);

    int m[n][n];
    int j,temp,min;

    for(int i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            m[i][j]=0;
        }
    }

    for(int d=1;d<n-1;d++)
    {
        for(int i=1;i<n-d;i++)
        {
            j=i+d;

            min=INT_MAX;

            for(int k=i;k<=j-1;k++)
            {
                temp=m[i][k]+m[k+1][j]+a[i-1]*a[k]*a[j];

                if(temp<min)
                {
                    min=temp;
                }
            }
            m[i][j]=min;
        }
    }
    printf("%d",m[1][n-1]);
}
