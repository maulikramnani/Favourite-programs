#include<iostream.h>
#include<conio.h>
int main(){
clrscr();
float bal=25000.0,money;
char ch,ch1;
l1:
{
cout<<"#####  Welcome to MAULIK'S BANK OF INDIA  #####";
cout<<"\n press w. to withdraw ";
cout<<"\n press b. to check Balance";
cout<<"\n press d to deposit amount";
cout<<"\n press e to exit\n\t";
cin>>ch;
}
if(ch=='w')  {

	cout<<"\nenter money (in $) that you wanna withdraw: ";
	cin>>money;
	if(money>bal){
	cout<<"\a\nCan't withdraw....Insufficient balance";
	cout<<"\n For main menu press m or for exit press any other key";
	cin>>ch1;
	if(ch1=='m')
	goto l1;
	else
	return 0;
	}
	else{
	bal=bal-money;
	cout<<"\nWithdraw successfully";
	cout<<"\nRemaining balance is:"<<bal<<" $";
	cout<<"\npress m to go to main menu";
	cin>>ch1;

	if(ch1=='m')
	goto l1;
	else{
	cout<<"\nthanks for banking with us...";
	return 0;
	}
	}
	}else
	 if(ch=='b'){
	cout<<"your Balance is: "<<bal<<"$";
	cout<<"\npress m to go to main menu";
	cin>>ch1;

	if(ch1=='m')
	goto l1;
	else{
	cout<<"\nthanks for banking with us...";
	return 0;
	}

	}
	else if(ch=='d')
	{
	  cout<<"enter amount to transfer :";
	  cin>>money;
	  bal=money+bal;
	  cout<<"\nTransfer Succesfully";
	  cout<<"\n your balance is: "<<bal<<" $";
	  cout<<"\npress m to go to main menu";
	cin>>ch1;

	if(ch1=='m')
	goto l1;
	else{
	cout<<"\nthanks for banking with us...";
	return 0;
	}
	}
	else if(ch=='e')
	{
	cout<<"\nthanks for dealing with us";
	return 0;

	}

getch();
return 0;
}