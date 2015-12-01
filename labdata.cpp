#include<iostream>
#include<stdio.h>
#include <string.h>
using namespace std;
 int main()
 {
     FILE *fp;
     fp=fopen("lena.pgm","r");
     char ch;
     int i,j,x[520][520];
     for(i=0;i<512;i++ )
     {
         for(j=0;j<512;j++)
         {
             fscanf(fp,"%c",&ch);
             x[i][j]=(int)ch;
             printf("%c",x[i][j]);
         }
     }
     fclose(fp);
     return 0;
 }
