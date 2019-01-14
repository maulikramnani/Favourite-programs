#include<iostream.h>
#include<conio.h>


void main()         //Starting_main_function

{
clrscr();
     cout<<"\t\t***************************************************\n";
	cout<<"\t\t\tElectronic configuration calculator\n";
	cout<<"\t\t***************************************************\n";
	int n, s1, s2, p2, s3, p3, s4, d3, p4, s5, d4, p5, s6, f4, d5, p6, s7, f5, d6, p7;
	cout<<"\n Enter atomic number :";
	cin>>n;

	if (n<=2)
	 s1=n;
	else if (n>2)
	      s1=2;

	if (n<=4 && n>=2)
	 s2=n-2;
	else if (n<2)
	 s2=0;
	else
	 if (n>4)
	      s2=2;

	if (n<=10 && n>=4)
	      p2=(n-4);
	else if (n<4)
	      p2=0;
	else
	      if (n>10)
	      p2=6 ;

	if (n<=12 && n>=10)
	      s3=n-10;
	else if (n<10)
	      s3=0;
	else
	      if (n>12)
	      s3=2;

	if (n<=18 && n>=12)
	      p3=n-12;
	else if (n<12)
	      p3=0;
	else
	      if (n>18)
	      p3=6;

	if (n<=20 && n>=18)
	      s4=n-18;
	else if (n<18)
	       s4=0;
	else
	      if(n>20)
	      s4=2;

	if (n<=30 && n>=20)
	      d3=n-20;
	else if (n<20)
	      d3=0;
	else
	      if (n>30)
	      d3=10;

	if (n<=36 && n>=30)
	      p4=n-30;
	else if (n<30)
	      p4=0;
	else
	      if(n>36)
	      p4=6;

	if (n<=38 && n>=36)
	      s5=n-36;
	else if (n<36)
	      s5=0;
	else
	      if(n>38)
	      s5=2;

	if (n<=48 && n>=38)
	      d4=n-38;
	else if (n<38)
	      d4=0;
	else
	      d4=10;

	if (n<=54 && n>=48)
	      p5=n-48;
	else if (n<48)
	      p5=0;
	else
	      if (n>54)
	      p5=6;

	if (n<=56 && n>=54)
	      s6=n-54;
	else if (n<54)
	      s6=0;
	else
	      if (n>56)
	      s6=2;
	if (n<=70 &&  n>=56)
	      f4=n-56;
	else if (n<56)
	      f4=0;
	else
	      if(n>70)
	      f4=14;

	if (n<=80 && n>=70)
	      d5=n-70;
	else if (n<70)
	      d5=0;
	else
	      if (n>80)
	      d5=10;

	if (n<=86 && n>=80)
	      p6=n-80;
	else if (n<80)
	      p6=0;
	else
	      p6=6;

	if (n<=88 && n>=86)
	      s7=n-86;
	else if (n<86)
	      s7=0;
	else
	      if(n>88)
	      s7=2;

	if(n<=102 && n>=88)
	      f5=n-88;
	else if (n<88)
	      f5=0;
	else
	      if (n>102)
	      f5=14;

	if (n<=112 && n>=102)
	      d6=n-102;
	else if (n<102)
	      d6=0;
	else
	       if(n>112)
	       d6=10;

	if (n<=118 && n>=112)
	      p7=n-112;

	else if (n<112)
	      p7=0;
	else
	      if (n>118)
	      p7=6;


	      cout<<"\n\n 1s: "<<s1<<"\n 2s: "<<s2<<"\n 2p: "<<p2<<"\n 3s :"<<s3<<"\n 3p :"<<p3<<"\n 4s :"<<s4;
	      cout<<"\n 3d :"<<d3<<"\n 4p :"<<p4<<"\n 5s :"<<s5<<"\n 4d :"<<d4<<"\n 5p :"<<p5<<"\n 6s :"<<s6<<"\n 4f :"<<f4;
	      cout<<"\n 5d :"<<d5<<"\n 6p :"<<p6<<"\n 7s :"<<s7<<"\n 5f :"<<f5<<"\n 6d :"<<d6<<"\n 7p :"<<p7;

	      cout<<"\n\n\n\n\n";

	 getch();
}    //Main_function_Completed
