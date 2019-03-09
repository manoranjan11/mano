#include <iostream>                                             //header files
#include<stdio.h>
#include <stdlib.h>
using namespace std;

struct node							//structure initialisation
{ string url;
  struct node *next;	
}*p;

node* end = NULL;

void newurl()
{
  string url;
  cout<<"Enter the url : ";
  cin>>url;
  p = new node;							//dynamic allocation
  p->url = url;
  if(end == NULL)
   p->next =  NULL;
  else
   p->next = end;

   end = p;		
}

void previous()
{
	if(end==NULL)
		cout<<"can't go still further!!!";
	else
	   {p=end; 
        end=end->next;
        delete p;
       }
}

int main()
{ 
	int opt;
	while(1)
	{
		cout<<"\n\n\"FOO Browser\"!\n\n\n";
		
		
        if(end!=NULL)
	         cout<<"Welcome to "<<end->url;
		 
	cout<<"\n1.Enter the Url\n2.previous\n3.Exit\n";
	cout<<"Enter the option:";
	
	cin>>opt;

		switch(opt)
		{ case 1: newurl();
				  break;
		  case 2: previous();
				  break;
	  	  case 3: exit(0);
	  	  default: cout<<"\nEnter values from 1 to 3!";
		  		  
	    }
    }	
return 0;
}
