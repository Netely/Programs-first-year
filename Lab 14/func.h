#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;
struct zapus{
       char name[10];
       char sname[10];
       char dat[9];
       char number[14];
       char adress[25];};
       
FILE * f;
char fname[20];

void fconnect()
{
	setlocale(LC_ALL,"");
	
	cout<<"����� ����� ��� ����������� ������� ���� ���������� bin."<<endl;
	cout<<"����� ����� :";
	cin>>fname;
	if ((f=fopen(fname,"rb+"))==NULL)
 	{
 	if ((f=fopen(fname,"wb+"))==NULL)
 	{
	cout<<"��������� �������� ����!"<<endl;
	}
	cout<<"���� ��������!"<<endl;
 	}
}
void add_inf()
{
	setlocale(LC_ALL,"");
	fseek(f,0,SEEK_END);
	int k=1;
	cout<<"��i���� �����i� �� ������� ��������?";
	cin>>k;
	for(;k>0;k--){
	struct zapus a;
	cout<<"��������� ������"<<endl;
	cout<<"i�'�   :";cin>>a.name;
	cout<<"��i����� :"; cin>>a.sname;
	cout<<"���� ���������� � ������i ��.��.��:"; cin>>a.dat;
	cout<<"����� ���i������ �������� � ������i +380******* :"; cin>>a.number; 
	cout<<"������ :";fflush(stdin);gets(a.adress);cout<<endl;
	fwrite(&a,sizeof(a),1,f);}
}
void print(struct zapus a){
	setlocale(LC_ALL,"");
	
	cout<<setw(10)<<a.name<<setw(10)<<a.sname<<setw(17)<<a.dat<<setw(15)<<a.number<<setw(15)<<a.adress<<endl;
	cout<<endl;
}
void show()
{
	setlocale(LC_ALL,"");
 struct zapus a;
 int p,r;
 	p=0;
	fseek(f,0,0);
	cout<<"��i�� ���� �����:"<<endl<<endl;
	cout<<setw(3)<<"#"<<setw(10)<<"I�'�"<<setw(10)<<"��i�����"<<setw(17)<<"���� ����������"<<setw(15)<<"���i����� �����"<<setw(15)<<"������"<<endl<<endl;
	while (!feof(f))
	{
		
		r=fread(&a,sizeof(a),1,f);
		if (r<1) break;cout<<setw(3)<<p+1;
		print(a);
		p++;
	}
	cout<<endl<<"� ��������� "<<p<<" �����i�!"<<endl<<endl;
}



     
void clear()
{
	setlocale(LC_ALL,"");
	fclose(f);
    remove(fname);
    cout<<"���� ���i��� ��������";
}

void searchbyname(){
     setlocale(LC_ALL,"");
 char name1[10];
 struct zapus a;
 int p,r;
 	p=0;
	cout<<"����i�� I�'� : ";
	cin>>name1;
	cout<<endl;
	fseek(f,0,0);
	cout<<setw(3)<<"#"<<setw(10)<<"I�'�"<<setw(10)<<"��i�����"<<setw(17)<<"���� ����������"<<setw(15)<<"���i����� �����"<<setw(15)<<"������"<<endl<<endl;
	while (!feof(f))
	{
		r=fread(&a,sizeof(a),1,f);
		if (r<1) break;
		if (strcmp(name1,a.name)==0)
		{
			cout<<setw(3)<<p+1;print(a);
			p++;
		}
	}
	if (p==0) cout<<"������ ������ �� ��������!"<<endl;
	else cout<<endl<<"�������� "<<p<<" �����i�!"<<endl<<endl;}
	
void searchbysname(){
     setlocale(LC_ALL,"");
 char name1[10];
 struct zapus a;
 int p,r;
 	p=0;
	cout<<"����i�� ��i����� : ";
	cin>>name1;
	cout<<endl;
	fseek(f,0,0);
	cout<<setw(3)<<"#"<<setw(10)<<"I�'�"<<setw(10)<<"��i�����"<<setw(17)<<"���� ����������"<<setw(15)<<"���i����� �����"<<setw(15)<<"������"<<endl<<endl;
	while (!feof(f))
	{
		r=fread(&a,sizeof(a),1,f);
		if (r<1) break;
		if (strcmp(name1,a.sname)==0)
		{
			cout<<setw(3)<<p+1;print(a);
			p++;
		}
	}
	if (p==0) cout<<"������ ������ �� ��������!"<<endl;
	else cout<<endl<<"�������� "<<p<<" �����i�!"<<endl<<endl;}
     
void searchbynumber(){
     setlocale(LC_ALL,"");
 char name1[10];
 struct zapus a;
 int p,r;
 	p=0;
	cout<<"����i�� ����� : ";
	cin>>name1;
	cout<<endl;
	fseek(f,0,0);
	cout<<setw(3)<<"#"<<setw(10)<<"I�'�"<<setw(10)<<"��i�����"<<setw(17)<<"���� ����������"<<setw(15)<<"���i����� �����"<<setw(15)<<"������"<<endl<<endl;
	while (!feof(f))
	{
		r=fread(&a,sizeof(a),1,f);
		if (r<1) break;
		if (strcmp(name1,a.number)==0)
		{
			cout<<setw(3)<<p+1;print(a);
			p++;
		}
	}
	if (p==0) cout<<"������ ������ �� ��������!"<<endl;
	else cout<<endl<<"�������� "<<p<<" �����i�!"<<endl<<endl;}

void search(){
int c;
cout<<"�����"<<endl<<"1.�� i���i"<<endl<<"2.�� ��i�����"<<endl<< "3.�� ������ ���i������ ��������"<<endl;
cin>>c;
switch(c){
case 1:searchbyname();  break;        
case 2:searchbysname(); break;         
case 3:searchbynumber(); break;
}
}
void redag()
{
	zapus a;
	int x,k;
    bool flag=false;
	char w[30],temp[25];
		show();
	cout << "����i�� ��i����� ��������, ���i ����� ���������� ����������� : ";
	cin >> temp;
	fseek(f,0,SEEK_SET);
	while (!feof(f))
	{
		if (strcmp(temp,a.sname)==0)
		        {
			    z:
			    	system("cls");
			    	
			    cout << "�� �� ������ ���i����?\n\n1 - I��\n2 - ��i�����\n3 - ���� ����������\n4 - ����� ��������\n5 - ������\n0 - ���i�\n";
				cin >> k;
				switch (k){
				case 1: cout << "����i�� ���� i��      : "; cin>>w; strcpy(a.name, w);flag=true; break;
				case 2: cout << "����i�� ���� ��i�����  : "; cin>>w; strcpy(a.sname, w);flag=true;break;				
				case 3: cout << "����i�� ���� ��        : "; cin>>w; strcpy(a.dat, w);flag=true; break;
				case 4: cout << "����i�� ����� �����    : "; cin>>w; strcpy(a.number, w);flag=true; break;
				case 5: cout << "����i�� ���� ������    : "; fflush(stdin);gets(w); strcpy(a.adress, w);flag=true; break;
				case 0: goto p;
				}
                goto z;
                p:k = ftell(f);
                fseek(f, k - sizeof(zapus), 0);
                fwrite(&a, sizeof(zapus), 1, f);
                fseek(f, sizeof(zapus), SEEK_CUR);
		        }	
		fread(&a, sizeof(zapus), 1, f); if(flag==true){cout << "I�������i� �������� ��i����!" << endl;show();flag=false;}
	}
	cout<<"������i�� ����-��� ����i�� ��� �����������.";
	getch();
	system("cls");
	}
