#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;


int minAmtInd(int amount[],int n)
{   int minInd=0;
	for(int i =1;i<n;i++)
		if(amount[i]<amount[minInd])
			minInd=i;
	return minInd;	
}

int maxAmtInd(int amount[],int n)
{	int maxInd=0;
	for(int i =1;i<n;i++)
		if(amount[i]>amount[maxInd])
			maxInd=i;
	return maxInd;
} 

void splitwise(int amount[],int n)
{
	int mCredit = maxAmtInd(amount,n), mDebit = minAmtInd(amount,n);  //Indexes of minimum and maximum values in amount[]
	if(amount[mCredit]==0 && amount[mDebit]==0)
		return;
	int min=(-amount[mDebit]<amount[mCredit])? -amount[mDebit] :amount[mCredit]; // Find the minimum of two amounts
	amount[mCredit] -= min; 
    amount[mDebit] += min;
    cout <<"\nPerson "<<mDebit+1<<" pays "<<min<<" to "<<"Person "<<mCredit+1;
    splitwise(amount,n);
}

int main()
{
	int n,i,j;
	cout<<"Enter the no. of friends : ";
	cin>>n;
	int transac[n][n];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			transac[i][j]=0;

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		    {if(i!=j)
		    	{cout<<"\nAmount that person "<<i+1<<" has to pay person "<<j+1<<" : ";
			     cin>>transac[i][j];
			    }
		    }
	//Calculate the net amount to be paid to person 'i+1', and stores it in amount[i]
	int amount[n]={0};
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			amount[i]+=(transac[j][i] - transac[i][j]);      //credits of (i+1) - debts of (i+1)

	splitwise(amount,n);

	return 0;
}
