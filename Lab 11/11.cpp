#include<stdio.h>
#include<iostream>
#include<iomanip>
using namespace std;
FILE *f;
const int n = 4;
void inp(){
	char group[6];
	int numbers,numberp,numberb;
    f = fopen("f.txt", "wt");
    
	for (int i = 0; i < n; i++){
		cout<<"Enter group: ";
        cin>>group;
        fwrite(&group, sizeof(group), 1, f);
		cout<<"Enter number of students: ";
		cin>>numbers;
		fwrite(&numbers, sizeof(numbers), 1, f);
		cout << "Enter number of subjects: ";
		cin >>numberp;
		fwrite(&numberp, sizeof(numberp), 1, f);
		numberb=numbers*numberp;
		fwrite(&numberb, sizeof(numberb), 1, f);
        cout << endl;
	
	}
	fclose(f);
}


void read(){
	f = fopen("f.txt", "rt");
	if (!f){ cout << "Open error\n"; system("pause"); exit(0); }
	char group[6];
	int numbers,numberp,numberb;
	for(int i=0;i<n;i++){
	cout<<"# :" <<i+1<<endl;
    fread(&group, sizeof(group), 1, f);
    cout<<"Group : "<<group<<endl;
    fread(&numbers, sizeof(numbers), 1, f);
    cout<<"Students : "<<numbers<<endl;
    fread(&numberp, sizeof(numberp), 1, f);
    cout<<"Subjects : "<<numberp<<endl;
    fread(&numberb, sizeof(numberb), 1, f);
    cout<<"Books : "<<numberb<<endl; 
}
}

void clear(){
	remove("f.txt");
}

int main(){

    int c;
    do{
	cout<<endl << "Menu"<<endl;
    cout << "1.Input information and write it into the file"<<endl<< "2.Read Information from file"<<endl<<"3.Clear file"<<endl;
	cin >> c;
	switch (c){
	case 1: system("cls"); inp(); break;
	case 2: system("cls"); read(); break;
	case 3: system("cls"); clear(); break;
	}}
	while(1);
    system("pause");
}
