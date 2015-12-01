#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct node{
int data;
struct node * next;
};
void printlinklist(struct node*href)
{
    if(href==NULL)
    {
        cout<<"list is empty"<<endl;
        return;
    }
    else{
        while(href!=NULL)
        {
            cout<<href->data<<endl;
            href=href->next;
        }
        return;
    }

}
void insertatstart(struct node**href,int data)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=*href;
    *href=temp;
}
void insertatend(struct node**href,int data)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    struct node*last=*href;
    if(last==NULL)
    {
        *href=temp;
        return;
    }
    else
    {
        while(last->next!=NULL)
        {
            last=last->next;
        }
        last->next=temp;
        return;
    }
}
void insertafteragivennode(struct node*href,int data)
{
    if(href==NULL)
    {
        cout<<"can't null previous node"<<endl;
        return;
    }
    else {
        struct node* temp=(struct node*)malloc(sizeof(struct node));
        temp->data=data;
        temp->next=href->next;
        href->next=temp;
        return;


    }
}
void deletenode(struct node**href,int key)
{
    struct node*temp=*href,*prev;
    prev=NULL;
    if(temp!=NULL&&temp->data==key)
    {

        *href=temp->next;
         free(temp);
        return;

    }
    while(temp!=NULL&&temp->data!=key)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        cout<<"given value node is not available in the list"<<endl;
        return;
    }

    prev->next=temp->next;
    free(temp);
    return;
}
int lengthoflist(struct node*href)
{
    int i=0;
    if(href==NULL)
        return i;
    else
    {
        while(href!=NULL)
        {
            i++;
            href=href->next;
        }
        return i;
    }
}
void searchelementinlist(struct node*href,int key)
{
    if(href==NULL)
    {
        cout<<"list is empty"<<endl;
        return;
    }
    else if(href!=NULL&&href->data==key)
    {
        cout<<"your element is at head of the list"<<endl;
        return;
    }
    else
    {
        int i=1;
        while(href!=NULL&&href->data!=key)
        {
            i++;
            href=href->next;
        }
        if(href==NULL)
        {
            cout<<"element is not in list"<<endl;
            return;
        }
        cout<<"element "<<key<<"  is at "<<i<<"th position"<<endl;
            return;
    }
}
void reverselinklist(struct node**href)
{
    struct node*prev=NULL;
    struct node* current=*href;
    struct node* next1;
    while(current!=NULL)
    {
        next1=current->next;
        current->next=prev;
        prev=current;
        current=next1;
    }
    *href=prev;
}
void nthnode(struct node*href,int n)
{
    int i=n;
    if(href==NULL)
    {
        cout<<"list is empty"<<endl;
        return;
    }
    else
    {
        while(href!=NULL&&n>1)
        {
            href=href->next;
            n--;
        }
        if(href==NULL)
        {
            cout<<"exceed the limit"<<endl;
            return;
        }
        cout<<"your "<<i<<"th element is="<<href->data<<endl;
        return;
    }
}
void nthelementfromlast(struct node* href,int n)
{
    int i=n,j=n;
    struct node*first=href,*second=href;
    if(href==NULL)
    {
        cout<<"list is empty"<<endl;
        return;
    }
    while(second!=NULL&&n>0)
    {
        second=second->next;
        n--;
    }
    if(second==NULL&&n>0)
    {
        cout<<"there are not sufficient element"<<endl;
        return;
    }
    while(second!=NULL&&i>1)
    {
        second=second->next;
        first=first->next;
        i--;
    }
    cout<<j<<"th element from last is="<<first->data<<endl;
    return;
}
void deletenodeatposition(struct node*href)
{
    struct node*temp=href->next;
    href->data=temp->data;
    href->next=temp->next;
    free(temp);
}
void deletewholelist(struct node**href)
{
    struct node*current=*href;
    struct node*next1;
    while(current!=NULL)
    {
        next1=current->next;
        free(current);
        current=next1;
    }
    *href=NULL;
}
int main()
{
    struct node* head=(struct node*)malloc(sizeof(struct node ));
    head->data=10;
    head->next=NULL;
    insertatstart(&head,20);
    insertatstart(&head,30);
    insertatstart(&head,40);
    insertatstart(&head,50);
    insertafteragivennode(head->next->next,25);
    insertatstart(&head,60);
    insertatstart(&head,70);
    insertatend(&head,5);
    deletenode(&head,25);
    printlinklist(head);
    int i;
    i=lengthoflist(head);
    cout<<"length of the list is equal to="<<i<<endl;
    searchelementinlist(head,20);
    nthnode(head,4);
    reverselinklist(&head);
    printlinklist(head);
    nthnode(head,4);
    nthelementfromlast(head,8);
    deletenodeatposition(head->next->next);
    printlinklist(head);
    deletewholelist(&head);
    printlinklist(head);
    return 0;
}
