#include<iostream>
#include<math.h>

using namespace std;
int main()
{
    int p=cout.width(10);
    cout<<"VALUE";

    cout.width(15);
    cout<<"SQRT_OF_VALUE"<<endl;
    cout.setf(ios::showpoint);
    cout.precision(3);
    for(int i=1;i<=6;i++)
    {
        cout.width(8);

        cout<<i;

        cout.width(13);
        cout.setf(ios::scientific,ios::left);
        cout<<sqrt(i)<<endl;
    }





    return 0;
}
