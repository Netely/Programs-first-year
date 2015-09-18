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
	
	cout<<"Назва файлу для опрацювання повинна мати розширення bin."<<endl;
	cout<<"Назва файлу :";
	cin>>fname;
	if ((f=fopen(fname,"rb+"))==NULL)
 	{
 	if ((f=fopen(fname,"wb+"))==NULL)
 	{
	cout<<"Неможливо створити файл!"<<endl;
	}
	cout<<"Файл створено!"<<endl;
 	}
}
void add_inf()
{
	setlocale(LC_ALL,"");
	fseek(f,0,SEEK_END);
	int k=1;
	cout<<"Скiльки записiв ви плануєте добавити?";
	cin>>k;
	for(;k>0;k--){
	struct zapus a;
	cout<<"Ввнесення запису"<<endl;
	cout<<"iм'я   :";cin>>a.name;
	cout<<"Прiзвище :"; cin>>a.sname;
	cout<<"Дата народження в форматi ДД.ММ.РР:"; cin>>a.dat;
	cout<<"Номер мобiльного телефону в форматi +380******* :"; cin>>a.number; 
	cout<<"Адресу :";fflush(stdin);gets(a.adress);cout<<endl;
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
	cout<<"Вмiст бази даних:"<<endl<<endl;
	cout<<setw(3)<<"#"<<setw(10)<<"Iм'я"<<setw(10)<<"Прiзвище"<<setw(17)<<"Дата народження"<<setw(15)<<"Мобiльний номер"<<setw(15)<<"Адреса"<<endl<<endl;
	while (!feof(f))
	{
		
		r=fread(&a,sizeof(a),1,f);
		if (r<1) break;cout<<setw(3)<<p+1;
		print(a);
		p++;
	}
	cout<<endl<<"У записнику "<<p<<" записiв!"<<endl<<endl;
}



     
void clear()
{
	setlocale(LC_ALL,"");
	fclose(f);
    remove(fname);
    cout<<"Файл успiшно видалено";
}

void searchbyname(){
     setlocale(LC_ALL,"");
 char name1[10];
 struct zapus a;
 int p,r;
 	p=0;
	cout<<"Введiть Iм'я : ";
	cin>>name1;
	cout<<endl;
	fseek(f,0,0);
	cout<<setw(3)<<"#"<<setw(10)<<"Iм'я"<<setw(10)<<"Прiзвище"<<setw(17)<<"Дата народження"<<setw(15)<<"Мобiльний номер"<<setw(15)<<"Адреса"<<endl<<endl;
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
	if (p==0) cout<<"Такого запису не знайдено!"<<endl;
	else cout<<endl<<"Знайдено "<<p<<" записiв!"<<endl<<endl;}
	
void searchbysname(){
     setlocale(LC_ALL,"");
 char name1[10];
 struct zapus a;
 int p,r;
 	p=0;
	cout<<"Введiть прiзвище : ";
	cin>>name1;
	cout<<endl;
	fseek(f,0,0);
	cout<<setw(3)<<"#"<<setw(10)<<"Iм'я"<<setw(10)<<"Прiзвище"<<setw(17)<<"Дата народження"<<setw(15)<<"Мобiльний номер"<<setw(15)<<"Адреса"<<endl<<endl;
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
	if (p==0) cout<<"Такого запису не знайдено!"<<endl;
	else cout<<endl<<"Знайдено "<<p<<" записiв!"<<endl<<endl;}
     
void searchbynumber(){
     setlocale(LC_ALL,"");
 char name1[10];
 struct zapus a;
 int p,r;
 	p=0;
	cout<<"Введiть номер : ";
	cin>>name1;
	cout<<endl;
	fseek(f,0,0);
	cout<<setw(3)<<"#"<<setw(10)<<"Iм'я"<<setw(10)<<"Прiзвище"<<setw(17)<<"Дата народження"<<setw(15)<<"Мобiльний номер"<<setw(15)<<"Адреса"<<endl<<endl;
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
	if (p==0) cout<<"Такого запису не знайдено!"<<endl;
	else cout<<endl<<"Знайдено "<<p<<" записiв!"<<endl<<endl;}

void search(){
int c;
cout<<"Пошук"<<endl<<"1.По iменi"<<endl<<"2.По прiзвищу"<<endl<< "3.По номеру мобiльного телефона"<<endl;
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
	cout << "Введiть прiзвище абонента, данi якого потребують редагування : ";
	cin >> temp;
	fseek(f,0,SEEK_SET);
	while (!feof(f))
	{
		if (strcmp(temp,a.sname)==0)
		        {
			    z:
			    	system("cls");
			    	
			    cout << "Що ви хочете замiнити?\n\n1 - Iм’я\n2 - Прiзвище\n3 - Дата народження\n4 - Номер телефону\n5 - Адресу\n0 - Вихiд\n";
				cin >> k;
				switch (k){
				case 1: cout << "Введiть нове iм’я      : "; cin>>w; strcpy(a.name, w);flag=true; break;
				case 2: cout << "Введiть нове прiзвище  : "; cin>>w; strcpy(a.sname, w);flag=true;break;				
				case 3: cout << "Введiть нову дн        : "; cin>>w; strcpy(a.dat, w);flag=true; break;
				case 4: cout << "Введiть новий номер    : "; cin>>w; strcpy(a.number, w);flag=true; break;
				case 5: cout << "Введiть нову адресу    : "; fflush(stdin);gets(w); strcpy(a.adress, w);flag=true; break;
				case 0: goto p;
				}
                goto z;
                p:k = ftell(f);
                fseek(f, k - sizeof(zapus), 0);
                fwrite(&a, sizeof(zapus), 1, f);
                fseek(f, sizeof(zapus), SEEK_CUR);
		        }	
		fread(&a, sizeof(zapus), 1, f); if(flag==true){cout << "Iнформацiю абонента змiнено!" << endl;show();flag=false;}
	}
	cout<<"Натиснiть будь-яку клавiшу для продовження.";
	getch();
	system("cls");
	}
