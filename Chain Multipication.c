#include<stdio.h>
#include<math.h>
#include<limits.h>

int main()
{
    int n; //Size of Array
    scanf("%d",&n);

    int a[n];
    
    int i,j,temp,min;

    for(i=0;i<n;i++) //Loop to get Array Elements
    {
        scanf("%d",&a[i]);
    }


    //Creating a Duplicate Array
    int dp[n][n];



    //Assigning 0 value in Duplicate Array
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            dp[i][j]=0;
        }
    }

    for(int d=1;d<n-1;d++) //difference loop
    {
        for(i=1;i<n-d;i++)
        {
            j=i+d;

            min=INT_MAX;

            for(int k=i;k<=j-1;k++)
            {
                temp=dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j];

                if(temp<min)
                {
                    min=temp;
                }
            }
            dp[i][j]=min;
        }
    }
    printf("Minimum number of multiplications is %d\n",dp[1][n-1]);
}
