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
 		cout<<"Вас вiтає програма Записник, будь ласка, виберiть операцiю з списку :"<<endl
 		<<"1 - Ввести данi в записник"<<endl
 		<<"2 - Показати всi записи"<<endl
		<<"3 - Пошук"<<endl
		<<"4 - Очистка бази даних"<<endl
		<<"5 - Редагувати базу"<<endl
 		<<"9 - Пiдключення iншого файлу"<<endl
		<<"0 - Вихiд"<<endl<<endl;
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

