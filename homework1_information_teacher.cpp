#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
struct teacher{
	int id,age,hour;
	float salary,rate;
    char name[10],sex[10],subject[10];
}temp;
void header(){
    cout<<setfill(' ')<<setw(20)<<"ID"<<setfill(' ')<<setw(15)<<"Name"<<setfill(' ')<<setw(15)<<"Gender"<<setfill(' ')<<setw(15)<<"Age"<<setfill(' ')<<setw(15)<<"Rate"<<setfill(' ')<<setw(15)<<"Hour"<<cout<<setfill(' ')<<setw(15)<<"Subject"<<setfill(' ')<<setw(15)<<"Salary"<<endl;
}
//float income(teacher a[50],int n){
//    int i;
//    for(i=0;i<n;i++){
//        cout<<"Input Salary = ";cin>>a[i].salary;
//    }
//    return a[i].salary;
//}
void input(teacher a[50],int n){
	int i;
	for(i=0;i<n;i++){
		cout<<"Input ID= ";cin>>a[i].id;
        cout<<"Input Name= ";cin>>a[i].name;
        cout<<"Input Gender= ";cin>>a[i].sex;
        cout<<"Input Age= ";cin>>a[i].age;
        cout<<"Input Rate= ";cin>>a[i].rate;
        cout<<"Input Hour= ";cin>>a[i].hour;
        cout<<"Input Subject= ";cin>>a[i].subject;
        cout<<"Input Salary= ";cin>>a[i].salary;
	}
}
void output(teacher *pt,int n){
	int i;
    header();
    for(i=0;i<n;i++){
		cout<<setfill(' ')<<setw(20)<<(pt+i)->id<<setfill(' ')<<setw(15)<<(pt+i)->name<<setfill(' ')<<setw(15)<<(pt+i)->sex<<setfill(' ')<<setw(15)<<(pt+i)->age<<setfill(' ')<<setw(15)<<(pt+i)->rate<<"%"<<setfill(' ')<<setw(15)<<(pt+i)->hour<<setfill(' ')<<setw(15)<<(pt+i)->subject<<setfill(' ')<<setw(15)<<(pt+i)->salary<<"$"<<endl;

    }
}
void sort(teacher a[50],int n){
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(a[i].id>a[j].id){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
			}
		}
	}
//    (b==1)?"Sort Success!\n":"Sort Fail!\n";
    cout<<"Sort Success..!"<<endl;
}
void search(teacher *pt,int n,char *Name){
	int i,b=0;
	for(i=0;i<n;i++){
		if(strcmp((pt+i)->name,Name)==0){
			b=1;
            cout<<setfill(' ')<<setw(20)<<(pt+i)->id<<setfill(' ')<<setw(15)<<(pt+i)->name<<setfill(' ')<<setw(15)<<(pt+i)->sex<<setfill(' ')<<setw(15)<<(pt+i)->age<<setfill(' ')<<setw(15)<<(pt+i)->rate<<"%"<<setfill(' ')<<setw(15)<<(pt+i)->hour<<setfill(' ')<<setw(15)<<(pt+i)->subject<<setfill(' ')<<setw(15)<<(pt+i)->salary<<"$"<<endl;
        }
	}
	if(b==0){
		cout<<"search not found! "<<endl;
	}	
}
int main(){
	struct teacher a[5];
	struct teacher *pt;
	int op,n,i;
	do{
		cout.setf(ios::right);
		cout.fill('=');
		cout.width(80);cout<<"!"<<endl;
        cout<<setfill(' ')<<setw(47)<<"0. Exit\n";
		cout<<setfill(' ')<<setw(60)<<"1. Input Information\n";
		cout<<setfill(' ')<<setw(50)<<"2. Output \n";
		cout<<setfill(' ')<<setw(47)<<"3. Sort\n";
		cout<<setfill(' ')<<setw(49)<<"4. Search\n";
        cout<<setfill(' ')<<setw(63)<<"5. Output Income < 150$\n";
        cout<<setfill(' ')<<setw(65)<<"6. Update 15% salary<100$\n";
		cout.setf(ios::right);
		cout.fill('=');
		cout.width(80);cout<<"!"<<endl;
		cout<<"choose one option: ";cin>>op;
		switch(op){
			case 1:{
				cout<<"Input N: ";cin>>n;
				input(a,n);
			}break;
			case 2:{
				output(a,n);
			}break;
			case 3:{
				sort(a,n);
			}break;
			case 4:{
				pt=a;
				char name[10];
				cout<<"Input name for search = ";cin>>name;
                header();
				search(pt,n,name);
			}break;
            case 5:{
                header();
                for(i=0;i<n;i++){
                    if(a[i].salary<150){
                        cout<<setfill(' ')<<setw(20)<<(pt+i)->id<<setfill(' ')<<setw(15)<<(pt+i)->name<<setfill(' ')<<setw(15)<<(pt+i)->sex<<setfill(' ')<<setw(15)<<(pt+i)->age<<setfill(' ')<<setw(15)<<(pt+i)->rate<<"%"<<setfill(' ')<<setw(15)<<(pt+i)->hour<<setfill(' ')<<setw(15)<<(pt+i)->subject<<setfill(' ')<<setw(15)<<(pt+i)->salary<<"$"<<endl;
                    }
                }
            }break;
            case 6:{
                int b=0;
                float update[10];
                header();
                for(i=0;i<n;i++){
                    if(a[i].salary<100){
                        b=1;
                        update[i]=(pt+i)->salary=a[i].salary*15/100+a[i].salary;
                        cout<<setfill(' ')<<setw(20)<<(pt+i)->id<<setfill(' ')<<setw(15)<<(pt+i)->name<<setfill(' ')<<setw(15)<<(pt+i)->sex<<setfill(' ')<<setw(15)<<(pt+i)->age<<setfill(' ')<<setw(15)<<(pt+i)->rate<<"%"<<setfill(' ')<<setw(15)<<(pt+i)->hour<<setfill(' ')<<setw(15)<<(pt+i)->subject<<setfill(' ')<<setw(15)<<update[i]<<"$"<<endl;
                    }
                }
                if(b==0){
                    cout<<"Salary > 100"<<endl;
                }
            }break;
			default:cout<<"Input again \n";
		}
	}while(op!=0);
	return 0;
}
