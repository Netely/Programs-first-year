#include <iostream>
#include "func.h"
#include <stdlib.h>
#include <stdio.h>
using namespace std;



int main() 
{ 
	setlocale(LC_ALL,"");
	char k;
	fconnect();
	system("cls");
 	while(1){
 		cout<<"��� �i�� �������� ��������, ���� �����, �����i�� ������i� � ������ :"<<endl
 		<<"1 - ������ ���i � ��������"<<endl
 		<<"2 - �������� ��i ������"<<endl
		<<"3 - �����"<<endl
		<<"4 - ������� ���� �����"<<endl
		<<"5 - ���������� ����"<<endl
 		<<"9 - �i��������� i����� �����"<<endl
		<<"0 - ���i�"<<endl<<endl;
 		cin>>k;
 		switch(k)
 		{
        
		case '0': fclose(f); exit(0);
 		case '1': system("cls");add_inf();break;
		case '2': system("cls");show(); break;
      	case '3': system("cls");search(); break;
      	case '4': system("cls");clear();break;
      	case '5': system("cls");redag(); break;
      	case '9': system("cls");fconnect(); break;
 	 	}
 	}	
 	getch();
}

