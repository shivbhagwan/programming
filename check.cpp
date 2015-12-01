#include <iostream>
#include<fstream>
#include<iomanip>
using namespace std;

class test{
char name[10];
int code;
float cost;
public:
    void setdata();
    void getdata();
};
void test::setdata()
{
    cout<<"enter name"<<endl;
    cin>>name;
    cout<<"enter code"<<endl;
    cin>>code;
    cout<<"enter cost"<<endl;
    cin>>cost;
}
void test::getdata()
{
    cout<<setiosflags(ios::left)<<setw(10)<<name<<setiosflags(ios::right)<<setw(10)<<code<<setw(10)<<setprecision(5)<<cost<<endl;
}

int main() {
    test t[3];
    fstream file;
    file.open("rama",ios::in|ios::out);
    cout<<"Enter details for three students"<<endl;

    for(int i=0;i<3;i++)
    {
        t[i].setdata();
        file.write((char *)&t[i],sizeof(t[i]));
    }

    file.seekg(0);
    cout<<"Output"<<endl;
    for(int i=0;i<3;i++)
    {
        file.read((char *)&t[i],sizeof(t[i]));
        t[i].getdata();
    }
    file.close();

return 0;
}
