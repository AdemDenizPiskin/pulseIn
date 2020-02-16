#include <iostream>
#include <cstdlib>

using namespace std;

//nb: neighboors, indicies : n,e,s,w
class list 
{
	public:
	class node *data;
	class list *next;
};

class node
{
	public:
	
	class node *nb[4];
	bool iswall[4];
	node()
	{
		int i;
		
		for(i=0;i<4;i++)
			nb[i]=NULL;
			
		for(i=0;i<4;i++)
			iswall[i]=1;
	} ;
	
	node(class list *begin)
	{

		class list *mark=begin;
		int i=0;
		while(mark!=NULL)
		{
			nb[i]=mark->data;
			iswall[i]=1;
			mark=mark->next;
			i++;
		}
		for(;i<4;i++)
		{
			nb[i]=NULL;
			iswall[i]=1;
		}

	};
	
	node(class list *begin, bool *wall_arr)
	{
				class list *mark=begin;
		int i=0;
		while(mark!=NULL)
		{
			nb[i]=mark->data;
			iswall[i]=wall_arr[i];
			mark=mark->next;
			i++;
		}
		for(;i<4;i++)
		{
			nb[i]=NULL;
			iswall[i]=wall_arr[i];
		}
	};
	
};

char num2dir(int dir)
{
	switch(dir)
	{
		case 0: 
		return 'n';
	case 1:
		return 'e';
	case 2:
		return 's';
	case 3:
		return 'w';
	}
}
void cre_l(class list *element,class node *dat)//Create an element of list containing data dat
{
	element->next=(class list*)malloc(sizeof(class list));
	element->next->data=dat;
	element->next->next=NULL;
}
void cre_n(class node *start,int dir)
{
//	cout<<"Starting cre_n on node: "<<start<<endl;

	int i;
	start->nb[dir]=(class node *)malloc(sizeof(class node));
	
	for(i=0;i<4;i++)
		start->nb[dir]->iswall[i]=1;
		
	for(i=0;i<4;i++)
		start->nb[dir]->nb[i]=NULL;

	start->nb[dir]->nb[(dir+2)%4]=start;
//	cout<<"Printing list of nb: "<<start->nb[dir]<<endl;
//	for(i=0;i<4;i++)
//		cout<<start->nb[dir]->nb[i]<<endl;
//		cout<<"Printing list of nb: "<<start<<endl;
//	for(i=0;i<4;i++)
//		cout<<start->nb[i]<<endl;
//	cout<<"Cre_l finished succsesfully"<<endl;

}


void cre_grid(int dim1, int dim2, class node *start)//dim1:x, dim2: y
{

//	for(int i=0;i<4;i++)
//		cout<<start->nb[i]<<endl;
	int i,j;
	class node *mark=start;
	class node *mark2=start;
	class node *mark3=start;
	for(i=0;i<dim2;i++)
	{
		for(j=0;j<dim1-1;j++)
		{
			cre_n(mark,1);

			mark=mark->nb[1];
			if(i>0)
				{
					mark3=mark3->nb[1];
					mark->nb[0]=mark3;
					mark3->nb[2]=mark;
					
				}
		}
		
		if(i<dim2-1)
		{
			cre_n(mark2,2);	
			mark2=mark2->nb[2];
			mark=mark2;
			mark3=mark2->nb[0];
		}

	}
}

void print_grid(int dim1, int dim2,class node *begin)//begin is northwestern corner
{
	class node *mark=begin;
	class node *mark2=begin;
	int i,j,k;
	
	for(i=0;i<dim2;i++)
	{
		for(j=0;j<dim1;j++)
		{
			printf("Cord: (%d,%d): addres: %x \n\n",j,i,mark);
			for(k=0;k<4;k++)
			{
				cout<<"k="<<k<<"\t\t"<<mark->nb[k]<<endl;
			}
			mark=mark->nb[1];
		}
		mark2=mark2->nb[2];
		mark=mark2;
	}
}

main()
{
	int i;
	class node bruh;
	class node *test=&bruh;
	
	
	
	cre_grid(3,3,test);
	print_grid(3,3,test);

	
}
