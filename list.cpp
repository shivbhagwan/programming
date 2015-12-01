#include<iostream>
#include<list>
using namespace std;
void display(list <int> &v)
{
    list<int>::iterator it;
    for(it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<" ,";
    }
}
int main()
{
    list<int> v;
    list<int> v1;
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(70);
    v1.push_back(50);
    v1.push_back(40);
    cout<<"first list"<<endl;
    display(v);
    cout<<"\nsecond list"<<endl;
    display(v1);
    v.merge(v1);

    display(v);


}

