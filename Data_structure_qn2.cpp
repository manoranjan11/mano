#include <iostream>
#include<stdio.h>
#include <stdlib.h>

int main()
{   
	int tube[100]={0};
	int a=1,choice,i=-1;
	while(a)
	{   
		std::cout<<"\n1.Add\n2.Remove\n3.Exit";
		std::cout<<"\nEnter the opton :";
		std::cin>>choice;
		switch(choice)
		{
			case 1: if(i==100)
				    std::cout<<"\nTube is full.";
				    else
				    {tube[++i]=1;
				     std::cout<<"\nOne person is added.";
				    }
                                    std::cout<<"\nNo. of people inside = "<<i+1;
				    break;
			case 2: if(i<0)
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
