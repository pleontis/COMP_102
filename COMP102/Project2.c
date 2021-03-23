#include <stdio.h>
#include <stdlib.h>


struct list{
int value;
struct list*next;
};

struct list* createList(int n);
void displayList(struct list*);
int checkMOduloOfSum(struct list * node);
void freeList(struct list*node);

int main()
{
    int  Number;
    struct list*head=NULL;

    printf("How many integers do you want to insert in the list: ");
    scanf("%d",&Number);

    head=createList(Number);

    displayList(head); //Printing the list
    printf("\n");

    checkMOduloOfSum(head);

    freeList(head);


    return 0;
}

struct list* createList(int n){
int i=0;
struct list*head=NULL, *temp=NULL, *p=NULL;

for(i=0;i<n;i++)
{
    temp=(struct list*)malloc(sizeof(struct list));
    printf("Enter value of Node %d :", i+1);
    scanf("%d",&temp->value);
    temp->next=NULL;

   if(head==NULL)  //If list is empty
    {
        head=temp;
    }
    else //If list is not empty, attach new node at the end
    {
        p=head;
        while(p->next!=NULL)
        p=p->next;

    p->next=temp;

    }
}
return head;
}
void displayList(struct list* head){
    struct list*p=NULL;
    if(head==NULL)
    printf("Empty List");
    else
    {
        p=head;
        printf("\n");
        while(p!=NULL)
        {
            printf("%d->", p->value);
            p=p->next;
        }
    }
}
int checkMOduloOfSum(struct list*node){

int sum;

if(node==NULL)
    return 0;

    sum=checkMOduloOfSum(node->next);

    if(sum%node->value==0)
        printf(" %d[%d](YES) ", node->value ,sum);
    else
        printf(" %d[%d](NO) ", node->value ,sum);

    return sum+node->value;
}

void freeList(struct list* head){
struct list * p;
p=head;
if(head==NULL) //Empty list
    return 0;
while(head->next!=NULL){
    head=head->next;
free(p);
}

}
