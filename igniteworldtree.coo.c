#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
struct node* left;
int data;
struct node* right;
};
void printtree(struct node*href)
{
    if(href==NULL)
    {
        return;
    }
    while(href!=NULL)
    {
        cout<<href->data;
        printtree(href->left);
        printtree(href->right);
    }
}
int main()
{
    struct node* root;
    root->data=10;








    return 0;
}
