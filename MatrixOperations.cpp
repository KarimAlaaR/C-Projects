#include<iostream>
#include<string>
#include<cstdlib>
#include<sstream>
#include<math.h>
using namespace std;
void convert(string matrix,float q[100][100],int rows);
int number_rows(string matrix);
int number_column(string matrix);
void sum(float matrix1[100][100],float matrix2[100][100],int rows,int column);
void convert2(float tot[100][100],int rows,int column);
void subtract(float matrix1[100][100],float matrix2[100][100],int rows,int column);
void Multiply (float matrix1[100][100],float matrix2[100][100],int rows,int column,int column2);
void power(float matrix1[100][100],int n,int rows,int column);
void transpose(float matrix1[100][100],int rows,int column);
float determinant(float matrix1[100][100],int n);
int main()
{
    string matrix1;
    string matrix2;
    getline(cin,matrix1);
int rows=number_rows(matrix1);
int column=number_column(matrix1);
float matrix12[100][100];
convert(matrix1,matrix12,rows);
string opp;
getline(cin,opp);
if(opp[0]=='+'||opp[0]=='-'||opp[0]=='*'){
        float matrix21[100][100];
     getline(cin,matrix2);
      int rows2=number_rows(matrix2);
int column2=number_column(matrix2);
if(opp[0]=='+'){
        if(rows==rows2&&column==column2){
        convert(matrix2,matrix21,rows);
    sum(matrix12,matrix21,rows,column);}
else
    cout<<"ERROR";
}
else if(opp[0]=='-'){
   if(rows==rows2&&column==column2){
        convert(matrix2,matrix21,rows);
   subtract(matrix12,matrix21,rows,column);}
else
    cout<<"ERROR";}
        else if(opp[0]=='*'){
                if(column==rows2){
convert(matrix2,matrix21,rows2);
Multiply(matrix12,matrix21,rows,column,column2);}
else
      cout<<"ERROR";  }
}
else if(opp[0]=='^'){
    float n ;
    cin>>n;
    int x=n;
if(column==rows){
    if(n>0&&n-x==0){
        power(matrix12,n,rows,column);
    }
    else
        cout<<"ERROR";

}
else{
    cout<<"ERROR";
}
}
else if(opp[0]=='T'){
        int count=0;
        int y=column-1;
        for(int i=0;i<matrix1.length();i++){
            if(matrix1[i]==' '){
                count++;
            }
            if(matrix1[i]==';'||matrix1[i]==']'){
                if(count==y)
                    count=0;
                else{
                    cout<<"ERROR";
                    break;
                }
            }
            if(matrix1[i]==']')
                  transpose(matrix12,rows,column);
        }
}
else if(opp[0]=='D'){
        if(rows==column){
        int n=column;
    float deter=determinant(matrix12,n);
    cout<<deter;}
    else
    cout<<"ERROR";
}
else{
    cout<<"ERROR";
}

    return 0;
}

void convert(string matrix,float q[100][100],int rows)
{

matrix.erase(0,1);
     string v ,c;
     int b,n;
    for(int i=0;i<rows;i++){
        for(int x=0;x<matrix.length();x++){
            if(matrix[x]==';'||matrix[x]==']'){
                c=matrix.substr(0,x+1);
                if(matrix[x]!=']'){
                matrix=matrix.substr(x+1,matrix.size()-(x+1));}
                break;}}
                n=0;
                b=0;
        for(int j=0;j<c.length();j++){
               if(c[j]==' '||c[j]==';'||c[j]==']'){
                v=c.substr(b,j-b);
            q[i][n]=atof(v.c_str());
 b=j+1;
 n++;}}}

}

int number_rows(string matrix){
  int count=0,rows;
    for(int i=0;i<matrix.length();i++){
        if(matrix[i]==';'){
            count++;
            }
}
    rows=count+1;
    return rows;
}
int number_column(string matrix){
   int column,count2=0;
     for(int i=0;i<matrix.length();i++){
        if(matrix[i]==' ')
            count2++;
            if(matrix[i]==';')
                break;}
    column=count2+1;
    return column;
}
void sum(float matrix1[100][100],float matrix2[100][100],int rows,int column){
          float sum[100][100];
 for(int i=0;i<rows;i++){
    for(int j=0;j<column;j++){
        sum[i][j]=matrix1[i][j]+matrix2[i][j];
 }}
 convert2(sum,rows,column);
         }

void convert2(float tot[100][100],int rows,int column){
    string ans;
    ostringstream ss;
    ss<<"[";
    for(int i=0;i<rows;i++){
        for(int j=0;j<column;j++){
            ss<<tot[i][j];
            if(j<column-1)
            ss<<" ";
        }
        if(i<rows-1)
        ss<<";";
    }
    ss<<"]";
    ans=ss.str();
    cout<<ans;
}
void subtract(float matrix1[100][100],float matrix2[100][100],int rows,int column){
     float subtract[100][100];
 for(int i=0;i<rows;i++){
    for(int j=0;j<column;j++){
        subtract[i][j]=matrix1[i][j]-matrix2[i][j];
 }}
 convert2(subtract,rows,column);
         }

void Multiply (float matrix1[100][100],float matrix2[100][100],int rows,int column,int column2){
    float Multiply[100][100];
   for (int i=0;i<rows;i++){
        for(int j=0;j<column2;j++){
            Multiply[i][j]=0;
        }
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<column2;j++){
            for(int k=0;k<column;k++){
                 Multiply[i][j]+=matrix1[i][k]*matrix2[k][j];
            }
        }
    }
    convert2(Multiply,rows,column2);
}
void power(float matrix1[100][100],int n,int rows,int column){
float matrix2[100][100];
    float Multiply[100][100];
   for (int i=0;i<rows;i++){
        for(int j=0;j<column;j++){
            Multiply[i][j]=0;
        }
    }

for(int i=0;i<rows;i++){
    for(int j=0;j<column;j++){
       matrix2[i][j]= matrix1[i][j];
    }
}
for(int l=0;l<n-1;l++){

    for(int i=0;i<rows;i++){
        for(int j=0;j<column;j++){
            for(int k=0;k<column;k++){
                 Multiply[i][j]+=matrix1[i][k]*matrix2[k][j];
            }
        }
    }

    for(int m=0;m<rows;m++){
    for(int o=0;o<column;o++){
       matrix2[m][o]= Multiply[m][o];
    }
}
for (int i=0;i<rows;i++){
        for(int j=0;j<column;j++){
            Multiply[i][j]=0;
        }
    }
    }
    convert2( matrix2,rows,column);
}
void transpose(float matrix1[100][100],int rows,int column){
    float matrix2[100][100];
    for(int i=0;i<column;i++){
        for(int j=0;j<rows;j++){
            matrix2[i][j]=matrix1[j][i];
        }
    }
    convert2( matrix2,column,rows);
}
float determinant(float matrix1[100][100],int n){
    float det=0,subtr[100][100];int b,q;
    if(n==2){
        det=(matrix1[0][0]*matrix1[1][1])-(matrix1[0][1]*matrix1[1][0]);
         return det;
    }
    else{
        for(int i=0;i<n;i++){
                q=0;
            for(int j=1;j<n;j++){
                b=0;
                for(int k=0;k<n;k++){
                        if(k==i)
                        continue;
                    subtr[q][b]=matrix1[j][k];
                b++;
                }
                q++;
            }
         det=det+(pow(-1,i)*matrix1[0][i]*determinant(subtr,n-1));
        }

    } return det;
}
