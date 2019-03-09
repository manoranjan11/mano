#include <iostream>
#include<stdio.h>
#include <stdlib.h>								//header_files
using namespace std
int main()
{   
	int tube[100]={0};							//initialisation of variables
	int a=1,choice,i=-1;
	while(a)
	{   
		cout<<"\n1.Add\n2.Remove\n3.Exit";
		cout<<"\nEnter the option :";
		cin>>choice;
		switch(choice)							//getting choices
		{
			case 1: if(i==100)					//adding
				    cout<<"\nTube is full.";	
				    else
				    {tube[++i]=1;
				     cout<<"\n one person is added.";
				    }
                                     cout<<"\nNo. of people inside = "<<i+1;
				    break;
			case 2: if(i<0)						//removing
				    std::cout<<"\nThe Tube is empty.";
				    else
				    {tube[i--]=0;
				     std::cout<<"\nOne person is removed.";
				    }
                                    std::cout<<"\nNo. of people inside = "<<i+1;
				    break;
			case 3: exit(0);
			default : std::cout<<"\nEnter between 1 to 3.";         
		}

	}
	return 0;
}
