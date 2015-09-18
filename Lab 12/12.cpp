#include<iostream>
#include<stdio.h>
#include<iomanip>
using namespace std;

FILE *f;
const int n = 4;
struct book{
	char group[6];
	int numbers;
	int numberp;
	int numberb;
}a[n];


void inp(book a[n]){
	f = fopen("f.dat", "wb");
	int c = 0;
	for (int i = 0; i < n; i++){
		cout<<"Enter group: ";
        cin>>a[i].group;
		cout<<"Enter number of students: ";
		cin>>a[i].numbers;
		cout << "Enter number of subjects: ";
		cin >> a[i].numberp;
		a[i].numberb=a[i].numbers*a[i].numberp;
		cout << endl;
		fwrite(&a[i], sizeof(book), 1, f);
		c++;
	}
	fclose(f);
}


void read(book a[n]){
	f = fopen("f.dat", "rb");
	if (!f){ cout << "Open error\n"; system("pause"); exit(0); }
	int i = 0;
	
	cout << setw(3) << "#" << setw(10) << "Group" << setw(15) << "Students"		<< setw(15) << "Subjects" << setw(15)<< "Books" <<endl;
	while (fread(&a[i], sizeof(book), 1, f)){

		cout << setw(3) << i + 1 << setw(10) << a[i].group <<setw(15)<< a[i].numbers << setw(15)<< a[i].numberp << setw(15) << a[i].numberb << endl;
		i++;
	}
	
}

void find(book a[n]){
     char group1[6];
     bool flag=false;
     cout<<"Enter group to find: "<<endl;
     cin>>group1;
     cout << setw(3) << "#" << setw(10) << "Group" << setw(15) << "Students"		<< setw(15) << "Subjects" << setw(15)<< "Books" <<endl;
     for(int i=0;i<n;i++){
     if(strcmp(group1,a[i].group)==0){
     cout << setw(3) << i + 1 << setw(10) << a[i].group <<setw(15)<< a[i].numbers << setw(15)<< a[i].numberp << setw(15) << a[i].numberb << endl;
     flag=true;
     }                                 
            }
     if(flag==false)
     cout<<"No information about this group"<<endl;
     }

void equal(book a[n]){
     int count=0;
     for(int i=0;i<n;i++){
             for(int j=0+i;j<n;j++){
                              if(a[i].numberb==a[j].numberb && strcmp(a[j].group,a[i].group)!=0){
                                                             count+=2;
                                                             cout<<a[i].group<<" = "<<a[j].group<<endl;}
     
     
     
     }}
     
     cout<<"Groups with equal numbers of books: "<<count<<endl;
     
     
     }

void clear(){
	remove("f.dat");
}

int main(){
    int c;
    do{
	cout << "Menu"<<endl;
    cout << "1 - Input infomation"<<endl<<"2 - Read & show information"<<endl<<"3 - Find group"<<endl<<"4 - Find groups with equal number of books"<<endl<<"5 - Clear file"<<endl;
	cin >> c;
	switch (c){
	case 1: system("cls"); inp(a); break;
	case 2: system("cls"); read(a); break;
	case 3: system("cls"); find(a);  break;
	case 4: system("cls"); equal(a);  break;
	case 5: system("cls"); clear(); cout << "Files are cleaned" << endl; break;
	}}
	while(1);
    system("pause");
return 0;
}
