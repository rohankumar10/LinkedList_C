#include<stdio.h>
#include<stdlib.h>

struct node{
        int info;
        struct node *next;
};
struct node *new1;
struct node *start=NULL;
struct node *last=NULL;

void insert(int);
void print();
void specin();

void main()
{
        int i=1;
        int values;
        while(i<=5){
                printf("enter the values: ");
                scanf("%d",&values);
                insert(values);
                i++;
        }
	print();
	specin();
	printf("\nNew List is\n");
        print();
}

void insert(int values)
{
        new1=(struct node*)malloc(sizeof(struct node));
        new1->info=values;
        new1->next=NULL;
        if(start==NULL){
                start=new1;
                last=new1;
        }
        else{
                last->next=new1;
                last=new1;
        }
}

void print()
{
        new1=start;
        while(new1->next!=NULL){
                printf("%d\t",new1->info);
                new1=new1->next;
        }
        printf("%d",new1->info);
}

void specin()
{	
	int data,location;
	printf("\nenter the data and location: ");
	scanf("%d %d",&data,&location);
	new1=(struct node*)malloc(sizeof(struct node));
        new1->info=data;
        new1->next=NULL;
	if(location==1){
		new1->next=start->next;
		start=new1;	
	}
	else{
		struct node *previous;
		previous=start;
		int count=1;
		while(count<location-1 && previous->next!=NULL){
			previous=previous->next;
			count++;
		}
		new1->next=previous->next;
		previous->next=new1;
	}
}
