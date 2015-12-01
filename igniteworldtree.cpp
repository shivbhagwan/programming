#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
struct node* left;
int data;
struct node* right;
};
int count;
struct node* newnode(int key)
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp->data=key;
    temp->left=temp->right=NULL;
    return temp;
};
void printthisnode(struct node*href,int i)
{
    if(href==NULL)
    {
        return;
    }
    if(i==1)
{


        cout<<href->data<<" ";
        count=count*href->data;

}
else{
        printthisnode(href->left,i-1);
        printthisnode(href->right,i-1);
}
}
int depth(struct node* href)
{
    if(href==NULL)
        return 0;
    else
    {
        if(depth(href->left)>=depth(href->right))
        {
            return 1+depth(href->left);
        }
        else
            return 1+depth(href->right);
    }
}
void levelorder(struct node* href)
{
    int i,j=0;
    for(i=1;i<=depth(href);i++)
    {
        count=1;
        printthisnode(href,i);
        cout<<endl;
        j=j+count;
    }
    cout<<"level oreder ans="<<j<<endl;
}
int main()
{
    struct node* root=(struct node*)malloc(sizeof(struct node));
    root=newnode(10);
    root->left=newnode(20);
    root->right=newnode(30);
    root->left->left=newnode(40);
    root->left->right=newnode(50);
    root->right->left=newnode(60);
    root->right->right=newnode(70);
levelorder(root);












    return 0;
}

