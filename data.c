#include<stdio.h>

int main(){
    int k;
    int row,col,**x,**err,i,j,count;
    unsigned char c;
    char s1[3],c1,*s,*st;
    s = (char *)malloc(100);
    st = (char *)malloc(100);
    FILE *fp;
    fp = fopen("lena512.pgm","r");
    fscanf(fp,"%s\n",s1);
    fscanf(fp,"%c",&c);
    while(c=='#'){
        fscanf(fp,"%c",&c1);
        while(c1!='\n'){
            fscanf(fp,"%c",&c1);
        }
        fscanf(fp,"%c",&c);
    }

    ungetc(c,fp);

    fscanf(fp,"%d",&row);
    fscanf(fp,"%d",&col);
    fscanf(fp,"%s\n",s); /*discard 255*/

    x=(int**)malloc(row*(sizeof(int)));
    for(i=0;i<row;i++){
        x[i]=(int*)malloc(col*(sizeof(int)));
    }

    err=(int**)malloc(row*(sizeof(int)));
    for(i=0;i<row;i++){
        err[i]=(int*)malloc(col*(sizeof(int)));
    }

    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            fscanf(fp,"%c",&c);
            x[i][j]=(int)c;
        }
    }

    fclose(fp);

    fp = fopen("lena.txt","w");

    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            fprintf(fp,"%d ",x[i][j]);
        }
        fprintf(fp,"\n");
    }

    fclose(fp);

    fp = fopen("lena2.txt","w");

    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(j==0){
                err[i][j]=x[i][j];
            } else {
                err[i][j]=x[i][j]-x[i][j-1];
            }
        }
    }

    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            fprintf(fp,"%d ",err[i][j]);
        }
        fprintf(fp,"\n");
    }

    fclose(fp);

    fopen("lena4.txt","w");
    for(k=-255;k<=256;k++){
        count=0;
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                if(err[i][j] == k)count++;
            }
        }
        fprintf(fp,"%d  %d\n",k,count);
    }

    fclose(fp);



    /*printf("The format is ");
    puts(s1);*/
}
