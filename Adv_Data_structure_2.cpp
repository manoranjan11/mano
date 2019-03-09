#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;


int minamti(int amount[],int n)
{   int mini=0;
	
        for(int i =1;i<n;i++)
		if(amount[i]<amount[mini])
			mini=i;
	return mini;	
}

int maxamti(int amount[],int n)
{	int maxi=0;
	
        for(int i =1;i<n;i++)
		if(amount[i]>amount[maxi])
			maxi=i;
	return maxi;
} 

void splitwise(int amount[],int n)
{
	int maxc = maxamti(amount,n), mind = minamti(amount,n);  //minimum and maximum values in amount
	
	if(amount[maxc]==0 && amount[mind]==0)
		return;
	
	int min = (-amount[mind]<amount[maxc])? - amount[mind] :amount[maxc]; //for finding the minimum of two amounts
	amount[maxc] -= min; 
    
	
    amount[mind] += min;
    cout <<"\nPerson "<<mind+1<<" pays "<<min<<" to "<<"Person "<<maxc+1;
    splitwise(amount,n);
}

int main()
{
	int n,i,j;
	cout<<"Enter the no. of people : ";
	cin>>n;
	int pay[n][n];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			pay[i][j]=0;

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		    {
			if(i!=j)
		    	{
				cout<<"\nAmount that person "<<i+1<<" has to pay person "<<j+1<<" : ";
			        cin>>pay[i][j];							//input from user
			    }
		    }
	
	int amt[n]={0};
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			amt[i]+=(pay[j][i] - pay[i][j]);      //credits - debits

	splitwise(amt,n);

	return 0;
}
