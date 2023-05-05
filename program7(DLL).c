#include<stdio.h>
#include<malloc.h>


struct dnode
{
    int data ;
	struct dnode * next ;
	struct dnode *prev ;
};


void append(struct dnode**,int) ;
void addatbeg(struct dnode**,int) ;
void addafter(struct dnode*,int,int) ;
void display(struct dnode*) ;
int count(struct dnode*) ;
void delete(struct dnode**,int) ;


void main( )

{
    int i,ele,x,j=1;
	struct node *p ;
	p = NULL ;
	while(j==1)
	{
     printf("Enter choice: \n1.Append \n2.Add at beginning \n3.Add middle \n4.Delete \n5.Display \n6.Count \n");
	 scanf("%d",&i);
	 switch(i)
	 {
	     case 1:
        {
            printf("\nEnter element to add at last:\n");
            scanf("%d",&ele);
            append(&p,ele);
            printf("The list is as follows:\n");
            display(p);
            break;
        }
      case 2:
          {
              printf("\nEnter element to add at beginning:\n");
              scanf("%d",&ele);
              addatbeg(&p,ele);
              printf("the list is as follows:\n");
              display(p);
              break;
          }
     case 3:
          {

              printf("\nEnter position where element is to be added:\n Enter element:\n");
              scanf("%d%d",&ele,&x);
              addafter(p, ele, x) ;
              printf("the list is as follows:\n");
              display(p);
              break;
          }
     case 4:
          {

              printf("\nEnter element to be deleted:\n");
              scanf("%d",&ele);
              delete(&p,ele) ;
              printf("The list is as follows:\n");
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
            count(p);
            break;
        }
    }
	printf("\nDo you want to continue :\nYES:1\nNO:0\n");
	scanf("%d",&j);
  }
}


void append(struct dnode**s,int num)


{
	struct dnode *r, *q = *s ;
    if(*s == NULL)
	{
		*s = malloc ( sizeof ( struct dnode ) ) ;
		(*s)->prev=NULL;
		(*s)->data=num;
		(*s)-> next=NULL;
	}
	else
	{
		while(q->next!= NULL )
			{
			    q=q->next ;
			}
        r = malloc(sizeof(struct dnode));
		r->data=num;
		r-> next=NULL;
		r->prev=q;
		q->next=r;

    }

}


void addatbeg(struct dnode**s,int num)


{
	struct dnode *q ;

	q = malloc(sizeof(struct dnode));
	q->prev=NULL;
	q->data=num;
	q->next=*s;

	(*s)->prev=q;
	*s=q ;
}


void addafter(struct dnode *q,int loc,int num)


{
	struct dnode *temp;
	int i;
	for(i = 0;i < loc;i++)
	{
		q=q->next;

		if(q == NULL)
		{
			printf("\nThere are less than %d elements\n",loc);
			return ;
		}
	}

	q=q->prev ;
	temp=malloc(sizeof( struct dnode)) ;
	temp->data=num;
	temp->prev=q;
	temp->next=q->next;
	temp->next->prev=temp;
	q->next=temp;
}


void delete(struct dnode **s,int num)


{
	struct dnode*q=*s ;
	while(q!= NULL)
	{
		if(q->data==num)
		{
			if(q==*s)
			{
				*s=(*s)->next ;
				(*s)->prev=NULL ;
			}
			else
			{
				if(q ->next==NULL)
					q->prev->next=NULL;
				else
				{
					q->prev->next=q->next;
					q->next->prev=q->prev;
				}
				free(q);
			}
			return;
		}
		q=q->next;
	}
	printf("\n%d not found.",num);
}


void display(struct dnode *q)


{
	while(q!= NULL)
	{
		printf("%d ",q->data) ;
        q=q->next ;
	}
}


int count(struct dnode*q)


{
	int c=0;
	while(q!=NULL)
	{
		q=q->next;
		c++;
	}
  return c;
}

