#include<stdio.h>
#include<malloc.h>

struct node
{
	int data ;
	struct node * link ;
};


void append(struct node **,int);
void addatbeg(struct node **,int);
void addafter(struct node *,int,int);
void display(struct node *);
int count(struct node *);
void delete(struct node **,int);


void main( )

{
    int i,ele,x,j=1;
	struct node *p ;
	p = NULL ;

	while(j==1)
	{
     printf("Enter Choice:  \n1.Append \n2.Add at Beginning \n3.Add Middle \n4.Delete \n5.Display \n6.Count \n");
	 scanf("%d",&i);
	 printf("\nNumber of elements in the Singly Linked List = %d",count(p));

	 switch(i)
	 {
	     case 1:
        {
            printf("\nEnter element to add at last:\n");
            scanf("%d",&ele);
            append(&p,ele);
            printf("\nThe list is :\n");
            display(p);
            break;
        }
      case 2:
          {
              printf("\nEnter element to Add at Beginning:\n");
              scanf("%d",&ele);
              addatbeg(&p,ele);
              printf("\nThe list is :\n");
              display(p);
              break;
          }
     case 3:
          {
            printf("\nEnter number to add anywhere in between\n");
            scanf("%d",&ele);
            printf("\nEnter the location where you want to insert a number\n");
            scanf("%d",&x);
            addafter(p,ele,x);
            display(p);
            break;
          }
     case 4:
          {
              printf("\nEnter element to be deleted:\n");
              scanf("%d",&ele);
              delete(&p,ele) ;
               printf("\nThe list is :\n");
              display(p);
              break;
          }
     case 5:
          {
              printf("\nThe list is :\n");
             display(p);
             break;
          }
     case 6:
        {
            printf("\nNumber of elements in list are:%d",count(p));
        }
	}
	printf("\nDo you want to continue : \nYES:1 \nNO:0\n");
	scanf("%d",&j);
  }
}


void append(struct node **q,int num)


{
	struct node *temp,*r;
	if(*q == NULL)
	{
		temp=malloc(sizeof(struct node));
		temp->data=num;
		temp->link=NULL;
		*q = temp ;
	}
	else
	{
		temp = *q ;
		while(temp -> link != NULL )
			temp=temp->link;
		    r=malloc(sizeof(struct node));
		    r->data=num;
		    r->link=NULL;
		    temp->link=r;
	}
}


void addatbeg(struct node **q,int num)


{
	struct node *temp;
    temp = malloc(sizeof(struct node));
    temp->data=num;
	temp->link=*q;
	*q = temp;
}


void addafter(struct node *q,int loc,int num)


{
	struct node *temp, *r;
	int i;
	temp = q;

    r=malloc(sizeof(struct node));
	r->data=num;

	for(i = 0;i < loc;i++)
	{
		temp=temp->link;
		if(temp == NULL)
		{
			printf("\nCan't insert %d elements in list",loc);
			return;
		}
	}


	r->link=temp->link;
	temp->link=r;
}


void delete(struct node **q,int num)


{
	struct node *old, *temp;
	temp = *q;

	while(temp != NULL)
	{
		if(temp->data==num)
		{

			if(temp == *q)
				*q=temp->link;
            else
				old->link=temp->link;
                free(temp);
			return;
		}
        else
		{
			old=temp;
			temp=temp->link;
		 }
	}

	printf ("\nElement %d not found\n",num);
}


void display(struct node *q)


{
	printf("\n") ;

	while (q != NULL)
	{
		printf("%d ",q -> data) ;
		q=q->link;
	}
}


int count(struct node * q)


{
	int c = 0;
    while(q != NULL)
	{
		q=q->link;
		c++;
	}
    return c;
}

