#include<iostream.h>
#include<conio.h>

void main()
{
clrscr();
int n,a,b;
float strike,sum=0,sum1=0;
cout<<"enter the no. of matches played by you in cricket:";
cin>>n;
for(int i=1;i<=n;i++)
{
cout<<"no. of balls played in "<<i<<" match: ";
cin>>b;
sum=sum+b;
cout<<"no.of runs made by you in "<<i<<" match: ";
cin>>a;
sum1=sum1+a;
}
cout<<"\ntotal no. of balls played in "<<n<<" mathches="<<sum;
cout<<"\ntotal no. of runs made by you "<<n<<" matches="<<sum1;
strike=sum1/sum*100;
cout<<"\nyour strike rate of the tournament ="<<strike;
if(strike<=100)
cout<<"\nyou need to improve";
else
if(strike>100&&strike<=200)
cout<<"\nyour perfomance is good";
else
if(strike>200)
cout<<"\nyou are an awesome player";
else
cout<<"invalid details";
getch();
}