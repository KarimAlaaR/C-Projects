#include<iostream>
#include<string>
#include<cstdlib>
#include<sstream>
#include<complex>

using namespace std;
int number_rows(string matrix);
int number_column(string matrix);
void convert(string matrix,complex<float> q[100][100],int rows);
void convert2(complex<float> tot[100][100],int rows,int column);
void sum(complex<float> matrix1[100][100],complex<float> matrix2[100][100],int rows,int column);
void subtract(complex<float> matrix1[100][100],complex<float> matrix2[100][100],int rows,int column);
void Multiply (complex<float> matrix1[100][100],complex<float> matrix2[100][100],int rows,int column,int column2);
int main()
{

    string matrix1;
    string matrix2;
    getline(cin,matrix1);
int rows=number_rows(matrix1);
int column=number_column(matrix1);
complex<float> matrix12[100][100];
convert(matrix1,matrix12,rows);
     string opp;
getline(cin,opp);
if(opp[0]=='+'||opp[0]=='-'||opp[0]=='*')
{
     complex<float> matrix21[100][100];
     getline(cin,matrix2);
      int rows2=number_rows(matrix2);
int column2=number_column(matrix2);
if(opp[0]=='+')
{
        if(rows==rows2&&column==column2)
        {
        convert(matrix2,matrix21,rows);
        sum(matrix12,matrix21,rows,column);
        }
        else
    cout<<"ERROR";

}

     else if(opp[0]=='*')
{
    if(column==rows2)
    {
      convert(matrix2,matrix21,rows2);
      Multiply(matrix12,matrix21,rows,column,column2);
    }
else
      cout<<"ERROR";
}
else if(opp[0]=='-')
    {
   if(rows==rows2&&column==column2)
    {
        convert(matrix2,matrix21,rows);
   subtract(matrix12,matrix21,rows,column);
    }
else
    cout<<"ERROR";
    }
    else
    cout<<"ERROR";

}

    return 0;
}
void convert(string matrix,complex<float> q[100][100],int rows)
{

matrix.erase(0,1);
     string v ,c,m;
     int b,n;
     float real,imag;
    for(int i=0;i<rows;i++)
{
        for(int x=0;x<matrix.length();x++)
            {
            if(matrix[x]==';'||matrix[x]==']')
                {
                c=matrix.substr(0,x+1);
                if(matrix[x]!=']')
                    {
                     matrix=matrix.substr(x+1,matrix.size()-(x+1));
                    }
                break;
                }
            }
                n=0;
                b=0;
 for(int j=0;j<c.length();j++)
{
   if(c[j]==' '||c[j]==';'||c[j]==']')
    {
              v=c.substr(b,j-b);
              for(int k=0;k<v.length();k++)
              {
                  real=atof(v.c_str());
                  q[i][n].real(real);
                  if(v[k]=='+'||v[k]=='-')
                    m=v.substr(k);
                    imag=atof(m.c_str());
                   q[i][n].imag(imag);
              }

 b=j+1;
 n++;
    }
}
}

}
void convert2(complex<float> tot[100][100],int rows,int column)
{
   cout<<"[";
    for(int i=0;i<rows;i++)
        {
        for(int j=0;j<column;j++)
        {
             if(tot[i][j].real()!=0)
            cout<<tot[i][j].real();
            if(tot[i][j].imag()>0)
            {

                if(tot[i][j].real()==0)
                cout<<tot[i][j].imag()<<"i";
                else
                   cout<<"+"<<tot[i][j].imag()<<"i";
            }
            else if(tot[i][j].imag()<0)
                cout<<tot[i][j].imag()<<"i";
                if(tot[i][j].real()==0&&tot[i][j].imag()==0)
                    cout<<0;

            if(j<column-1)
            cout<<" ";
        }
        if(i<rows-1)
       cout<<";";
        }
    cout<<"]";
}
int number_rows(string matrix)
{
  int count=0,rows;
    for(int i=0;i<matrix.length();i++)
        {
        if(matrix[i]==';')
        {
            count++;
        }
        }
    rows=count+1;
    return rows;
}
int number_column(string matrix)
{
   int column,count2=0;
     for(int i=0;i<matrix.length();i++)
        {
        if(matrix[i]==' ')
            count2++;
            if(matrix[i]==';')
                break;
        }
    column=count2+1;
    return column;
}
void sum(complex<float> matrix1[100][100],complex<float> matrix2[100][100],int rows,int column)
{
         complex<float> sum[100][100];
 for(int i=0;i<rows;i++)
 {
    for(int j=0;j<column;j++)
   {
        sum[i][j]=matrix1[i][j]+matrix2[i][j];
   }
 }
 convert2(sum,rows,column);
}
void subtract(complex<float> matrix1[100][100],complex<float> matrix2[100][100],int rows,int column)
{
         complex<float> subtract[100][100];
 for(int i=0;i<rows;i++)
 {
    for(int j=0;j<column;j++)
   {
        subtract[i][j]=matrix1[i][j]-matrix2[i][j];
   }
 }
 convert2(subtract,rows,column);
}
void Multiply (complex<float> matrix1[100][100],complex<float> matrix2[100][100],int rows,int column,int column2)
{
    complex<float> Multiply[100][100];
   for (int i=0;i<rows;i++)
    {
        for(int j=0;j<column2;j++)
        {
            Multiply[i][j]=0;
        }
    }
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<column2;j++)
        {
            for(int k=0;k<column;k++)
            {
                 Multiply[i][j]+=matrix1[i][k]*matrix2[k][j];
            }
        }
    }
    convert2(Multiply,rows,column2);
}
