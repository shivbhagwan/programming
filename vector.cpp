#include<iostream>
#include<vector>
using namespace std;
void display(vector <int> &v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }
}
int main()
{
    vector<int> v;
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    display(v);
    cout<<v.size()<<endl;
    vector<int> ::iterator itr;
    itr=v.begin();
    cout<<*itr<<endl;
    itr+=2;
    v.insert(itr,11);
    display(v);
    v.erase(v.begin()+1,v.begin()+3);
cout<<"after erase"<<endl;
display(v);

}
