#include<bits/stdc++.h>
using namespace std;

class bank{
		char name[100];
		char address[200];
		char acc_type;
		int balance;
	public:
		//This class will have the following major functions
		void open_account();
		void add_money();
		void withdraw_money();
		void show_account();
		
};

void bank :: open_account(){
	cout<<"Enter your full name ::"<<endl;
	cin.ignore();
	cin.getline(name,100);
	cout<<"Enter your address details"<<endl;
	cin.ignore();
	cin.getline(address,200);
	cout<<"Select they type of account you want to open"<<endl;
	cout<<"For saving account type s and for current press c ";
	cin>>acc_type;
	cout<<"Enter the amount for deposit"<<endl;
	cin>>balance;
}

void bank :: add_money(){
	
	int amt;
	cout<<"Enter how much amount you want to deposit"<<endl;
	cin>>amt;
	cin.ignore();
	balance+=amt;
	cout<<"Current balance for your account is   "<<balance<<endl;
}

void bank :: show_account(){
	cout<<"Your Full Name  \t"<<name<<endl;
	cout<<"Your Address \t"<<address<<endl;;
	cout<<"Your Account Type \t"<<acc_type<<endl;
	cout<<"Your account balance \t"<<balance<<endl;
}

void bank::withdraw_money(){
	int amount;
	cout<<"Enter the amount you want to withdraw"<<endl;
	cin>>amount;
	if(balance<amount){
		cout<<"Not sufficient balance for this amount , try a lower amount than"<<balance<<endl;
	}
	else{
		cout<<amount<<" has been debited from your account"<<endl;
		balance = balance -amount;
		cout<<"current balance is "<<balance;
	}
}
int main(){
	
	while(1){
		
		int choice;
		bank obj;
		cout<<"Enter 1 to open a new account"<<endl;
		cout<<"Enter 2 to deposit money in your account"<<endl;
		cout<<"Enter 3 to withdraw money "<<endl;
		cout<<"Enter 4 to display the account details"<<endl;
		cout<<"Enter 5 to exit"<<endl;
		
		
		cin>>choice;
		switch(choice){
			case 1:
				obj.open_account();
				break;
			case 2:
				obj.add_money();
				break;
			case 3:
				obj.withdraw_money();
				break;
			case 4:
				obj.show_account();
				break;
			default:
				cout<<"Exiting the process"<<endl;
				return 0;
		}
}
	
	return 0;
}
