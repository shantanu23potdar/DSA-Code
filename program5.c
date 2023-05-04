#include <stdio.h>

struct node
{
	int data ;
	struct node * link ;

} ;

void append( struct node **, int ) ;
void addatbeg( struct node **, int ) ;
void addafter( struct node *, int, int ) ;
void display( struct node * ) ;
int count( struct node * ) ;
void delete( struct node **, int ) ;

void main( )

{
    int i,ele,x,j=1;
	struct node *p ;
	p = NULL ;
	while(j==1)
	{
     printf("enter choice:\n1.append\n2.add at beginning\n3.add after\n4.delete\n5.display\n6.count\n");
	 scanf("%d",&i);
	 printf ( "No. of elements in the Linked List = %d", count ( p ) ) ;
	 switch(i)
	 { case 1:
        {
            printf("\nenter element in the list(will be added at last):\n");
	         scanf("%d",&ele);
	         append(&p,ele);
	         printf("the list is as follows:\n");
            display(p);
            break;
        }
      case 2:
          {
              printf("\nenter element to add at beginning:\n");
              scanf("%d",&ele);
              addatbeg(&p,ele);
              printf("the list is as follows:\n");
              display(p);
              break;
          }
     case 3:
          {
              printf("\nenter position where element is to be added:\nenter element:\n");
              scanf("%d%d",&ele,&x);
              addafter ( p, ele, x ) ;
              printf("the list is as follows:\n");
              display(p);
              break;
          }
     case 4:
          {
              printf("\nenter element to be deleted:\n");
              scanf("%d",&ele);
              delete (&p,ele) ;
              printf("the list is as follows:\n");
              display(p);
              break;
          }
     case 5:
          {
             printf("\nthe list is:\n");
             display(p);
             break;
          }
     case 6:
        {
            printf("\nno. of elements in list are:%d",count(p));
        }
	}
	printf("\ndo you want to continue :\nif yes press:1\nif no press:0\n");
	scanf("%d",&j);
  }
}


void append ( struct node **q, int num )


{
	struct node *temp, *r ;
	if ( *q == NULL )
	{
		temp = malloc ( sizeof ( struct node ) ) ;
		temp -> data = num ;
		temp -> link = NULL ;
		*q = temp ;
	}
	else
	{
		temp = *q ;
		while ( temp -> link != NULL )
			temp = temp -> link ;
		r = malloc ( sizeof ( struct node ) ) ;
		r -> data = num ;
		r -> link = NULL ;
		temp -> link = r ;
	}
}


void addatbeg ( struct node **q, int num )


{
	struct node *temp ;


	temp = malloc ( sizeof ( struct node ) ) ;

	temp -> data = num ;
	temp -> link = *q ;
	*q = temp ;
}


void addafter ( struct node *q, int loc, int num )


{
	struct node *temp, *r ;
	int i ;
	temp = q ;

	for ( i = 1; i < loc ; i++ )
	{
		temp = temp -> link ;
		if ( temp == NULL )
		{
			printf ( "\nThere are less than %d elements in list", loc ) ;
			return ;
		}
	}

	r = malloc ( sizeof ( struct node ) ) ;
	r -> data = num ;
	r -> link = temp -> link ;
	temp -> link = r ;
}


void delete ( struct node **q, int num )


{
	struct node *old, *temp ;
	temp = *q ;

	while ( temp != NULL )
	{
		if ( temp -> data == num )
		{

			if ( temp == *q )
				*q = temp -> link ;


			else
				old -> link = temp -> link ;


			free ( temp ) ;
			return ;
		}

		else
		{
			old = temp ;
			temp = temp -> link ;
		 }
	}

	printf ( "\nElement %d not found\n", num ) ;
}


void display ( struct node *q )


{
	printf ( "\n" ) ;


	while ( q != NULL )
	{
		printf ( "%d ", q -> data ) ;
		q = q -> link ;
	}
}


int count ( struct node * q )


{
	int c = 0 ;

	while ( q != NULL )
	{
		q = q -> link ;
		c++ ;
	}

	return c ;
}

