#include<iostream>

using namespace std;
const int n=3;
void matrixc(int a[n][n],int b[n][n]){
     int c[n][n],temp;
     for(int i=0;i<n;i++){
             for(int j=0;j<n;j++){
                    c[i][j]=a[i][j]+b[i][j]; 
                     }}
     temp=c[0][1];
     c[0][1]=c[1][0];           
     c[1][0]=temp; 
      
     temp=c[0][2];
     c[0][2]=c[2][0];           
     c[2][0]=temp; 
     
     temp=c[1][2];
     c[1][2]=c[2][1];           
     c[2][1]=temp;     
     
     cout<<endl<<"Matrix c: "<<endl;
for(int i=0;i<n;i++){
cout<<endl;
        for(int j=0;j<n;j++){
                cout<<c[i][j]<<" ";
}}         
     }
