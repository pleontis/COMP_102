#include <stdio.h>
#include <stdlib.h>


struct list{
int value;
struct list*next;
};

struct list* createList(int n);
void displayList(struct list*);
struct list * findAndPushBack(int n, struct list * node);
void freeList(struct list * node);
int main()
{
    int  Number,num_search;
    struct list*head=NULL;

    printf("How many integers do you want to insert in the list: ");
    scanf("%d",&Number);

    head=createList(Number);

    displayList(head); //Printing the list

    printf("\nPlease enter the integer you want to search:");
    scanf("%d", &num_search);

    head=findAndPushBack(num_search,head); //Searching for the integer that user typed
    printf("\nNow the list is: ");
    displayList(head); //Printing the new list after the searching

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
        while(p!=NULL)
        {
            printf("%d->", p->value);
            p=p->next;
        }
    }
}
struct list* findAndPushBack(int value,struct list*head){

    struct list* node=head;
    struct list* temp;
    struct list* last;


    while(value!=node->value && node->next!=NULL)
    node=node->next;

    if(node->next==NULL)
    {
        if(node->value!=value) //pointer (node) is at last node
        {
            printf("\nSorry, integer %d was not found\n", value); //Node wasn't found, list stays the same
            return head;
        }
        else
        {
            printf("\nThe node with value %d was found and it is placed at last position\n", value); //Node is at last position. List stays the same
            return head;
        }
    }
    else
    {
        printf("\nThe node with value %d was found\n", value); //Node was found
        temp=head;
        last=head;


        if(node->next->value<value){
            printf("Value of the next node is smaller than %d", value); //The list stays the same
            return head;
        }

        if(node==head) //Node is the first of the list
        {

            while(last->next!=NULL)
            last=last->next; //finding the last node

            last->next=node;
            head=node->next;
            node->next=NULL;
            return head;
        }

        while(temp->next!=node)
            temp=temp->next; //Finding the previous node

        while(last->next!=NULL)
            last=last->next; //finding the last node

        last->next=node;
        temp->next=node->next;
        node->next=NULL;

        return head;
    }

}
void freeList(struct list*head){
    struct list * p;
    p=head;
    if(head==NULL) //Empty list
        return;

    while(head!=NULL){
        head=head->next;
        free(p);
    }
}
