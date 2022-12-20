#include <iostream>
#include <windows.h>
#include<conio.h>
using namespace std;
class Bank{
	private:
		string username, password;
		string username1, password1;
		int all;
		struct person{
			string name, email,ID;
			int contact, cash;
		}person[100];
		
public:
	Bank(){
		all=0;
}
void choice();
void start();
void signUp();
void login();
void Data();
void show();
void update();
void search();
void transactions();
void del();
};
int main(int argc, char** argv) {
	cout<<"\t\t\t\t\t\t\5BANKING  MANAGEMENT  SYSTEM\5"<<endl;
	Bank b;
	b.start();
	b.signUp();
	b.login();
}
	void Bank::choice(){
	char ch;
	while(true){
	cout<<"\n\t\t\t\5PRESS\5"<<endl;
	cout<<"1. Create new account"<<endl;
	cout<<"2. View customber history"<<endl;
	cout<<"3. update information of existing account"<<endl;
	cout<<"4. cheek the details of the existing account"<<endl;
	cout<<"5. For transactions"<<endl;
	cout<<"6. Remove existing account"<<endl;
	cout<<"7. Exit page"<<endl;		
	ch=getch();
	system("cls");
	switch(ch){
		case '1':
			Bank::Data();
			break;
		case '2':
			Bank::show();
			break;	
		case '3':
			Bank::update();
			break;
		case '4':
			Bank::search();
			break;
		case '5':
			Bank::transactions();
			break;
		case '6':
			Bank::del();
			break;	
		case '7':
			exit(0);
			break;
		default:
			cout<<"aInvalid input"<<endl;
			break;					
	}	
		}
	}
void Bank::start(){
	char arr[]={'B','A','N','K',' ','M','A','N','A','G','E','M','E','N','T',' ','S','Y','S','T','E','M'};
	cout<<"\n\n\n\n\n\n\t\t\t\t";
	for(int i=0; i<24; i++){
		cout<<arr[i];
		Sleep(40);
	}
	Sleep(1000);
	system("cls");
	}
	void Bank::signUp(){
	cout<<"\n\n\t\t\tBank Management System"<<endl;
	cout<<"\n\t\t SIGN UP"<<endl;
	cout<<"\t\t\t Enter Username:";
	cin>>username;
	cout<<"\t\tEnter password:";
	cin>>password;
	cout<<"\t\tYour new id iscreating please wait";
	for(int i=0; i<5; i++)
	{
	cout<<".";
	Sleep(100);	
		}	
	}
	void Bank::login(){
		system("cls");
		cout<<"\n\n\t\t LOGIN"<<endl;
		cout<<"\t\tEnter Username:";
		cin>>username1;
		cout<<"\t\tEnter password";
		if(username==username1&&password==password1){
			system("cls");
			Bank::choice();
		}
		else
		if(username!=username1&&password!=password1){
		cout<<"\t\t\aInvalid username please try again";
		Sleep(3000);
		Bank::login();	
		}
		else
		if(username==username1&&password!=password1){
		cout<<"\t\t\aInvalid username please try again";
		Sleep(3000);
		Bank::login();	
	}
	else
	  {
	  	cout<<"\t\t\taInvalid username and password please try again";
	  	Sleep(3000);
	  	Bank::login();
	  }
		
	}
	void Bank::Data(){
		cout<<"\nEnter data of person"<<endl<<endl;
		cout<<"Enter Name: ";
		cin>>person[all].name;
		cout<<"Enter ID: ";
		cin>>person[all].ID;
		cout<<"Enter Contacts: ";
		cin>>person[all].contact;
		cout<<"Enter Email: ";
		cin>>person[all].email;
		cout<<"Enter Cash: ";
		cin>>person[all].cash;
		all++;
	}
	void Bank::show(){
		for(int i=0; i<all; i++)
		{
	cout<<"\nData of person "<<i+1<<endl;
	cout<<"Name: "<<person[i].name<<endl;
	cout<<"ID: "<<person[i].ID<<endl;
	cout<<"Contact: "<<person[i].contact<<endl;
	cout<<"Email: "<<person[i].email<<endl;
	cout<<"Cash: "<<person[i].cash<<endl;
		}
	}
	void Bank::update(){
		string id;
		cout<<"Enter ID of person for update"<<endl;
		cin>>id;
		for(int i=0; i<all; i++)
		{
			if(id==person[i].ID){
		cout<<"\nPrevious data of person "<<i+1<<endl;
		cout<<"Name: "<<person[i].name<<endl;
		cout<<"ID: "<<person[i].ID<<endl;
		cout<<"contact: "<<person[i].contact<<endl;
		cout<<"Email: "<<person[i].email<<endl;	
		cout<<"Cash: "<<person[i].cash<<endl;
		cout<<"Enter new data"<<endl<<endl;
		cout<<"Enter Name: ";
		cin>>person[i].name;
		cout<<"Enter ID: ";
		cin>>person[i].ID;
		cout<<"Enter Contact: ";
		cin>>person[i].contact;
		cout<<"Enter Email: ";
		cin>>person[i].email;
		cout<<"Enter Cash: ";
		cin>>person[i].cash;
		cout<<"Your required data is updated"<<endl;
		break;
			}
			if(i==all-1){
				cout<<"No such record found"<<endl;
			}
		}
		
	}
	void Bank::search(){
		string id;
		cout<<"Enter ID of person for check"<<endl;
		cin>>id;
		for(int i=0; i<all; i++)
		{
			if(id==person[i].ID){
			cout<<"\nData of person"<<i+1<<endl;
			cout<<"Name: "<<person[i].name<<endl;
			cout<<"ID: "<<person[i].ID<<endl;
			cout<<"Contact: "<<person[i].contact<<endl;
			cout<<"Email: "<<person[i].email<<endl;
			cout<<"Cash: "<<person[i].cash<<endl;
			break;
			}
			if(i==all-1){
			cout<<"No such record is found"<<endl;	
			}
		}
	}
	void Bank::transactions(){
		string id;
		char ch;
		int cash;
		cout<<"Enter id of person which you want to transaction"<<endl;
		cin>>id;
		for(int i=0; i<all; i++)
		{
			cout<<":Name "<<person[i].name<<endl;
			cout<<":ID "<<person[i].ID<<endl;
			cout<<":Contact "<<person[i].contact<<endl;
			cout<<":Email "<<person[i].email<<endl;
			cout<<"\nExisting Cash "<<person[i].cash<<endl;
			cout<<"\npress 1 to deposit cash"<<endl;
			cout<<"\npress 2 to withdraw cash"<<endl;
			ch=getch();
			switch(ch){
				case '1':
					cout<<"Enter cash which you want to deposit"<<endl;
					cin>>cash;
					person[i].cash+=cash;
					cout<<"New amount is "<<person[i].cash<<endl;
					break;
				case '2':
					back:
				    cout<<"Enter cash which you want to withdraw"<<endl;
					cin>>cash;
					if(cash>person[i].cash){
						cout<<"Your existing cash is just "<<person[i].cash<<endl;
						Sleep(3000);
						goto back;
					}	
					person[i].cash-=cash;
					cout<<"New amount is "<<person[i].cash<<endl;
					break;
					default:
						cout<<"\aInvalid Input"<<endl;
			}
		}
	}
	void Bank::del(){
		if(all==0){
			char ch;
			cout<<"Press 1 to remove specific record"<<endl;
			cout<<"Press 2 to remove full record"<<endl;
			ch=getch();
			if(ch=='1'){
				string id;
				cout<<"Enter id of person which you want to remove"<<endl;
				cin>>id;
				for(int i=0; i<all; i++){
					if(id==person[i].ID){
					for(int j=i; j<all; j++)
					{
						person[j].name=person[j++].name;
						person[j].ID=person[j++].ID;
						person[j].email=person[j++].email;
						person[j].contact=person[j++].contact;
						person[j].cash=person[j++].cash;
						all--;
						cout<<"Your required record is deleted"<<endl;
						break;
						}	
					}
					if(i==all-1){
						cout<<"No such record is found"<<endl;
					}
				}
			}
			else if(ch=='2'){
				all=0;
				cout<<"All record is deleted"<<endl;
			}
			else
			{
				cout<<"\aInvalid input"<<endl;
			}
		}
		else
		{
			cout<<"No data is enterd"<<endl;
		}
	}

	
	

