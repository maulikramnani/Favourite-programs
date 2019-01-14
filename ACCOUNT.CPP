#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<time.h> //to obtain system time through time_t.
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>   //for 'delay' function.
#include<graphics.h>
//Struct That Stores All Details Of A Person
struct get_info
{
char eid;
int fno,randnum,i,pas,x,opt,thought,contacts;
char fname[20][20],name[10],id[20],gender,id1[20];
char city[30],state[30],country[30],hometown[30],rel[10],status[50];
char pass1[20],cont,dob[10],fone[11],bug[100],agree;
};
/*Function Definition for Delay Function*/
void d_lay()
{
clrscr();
cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\tLoading ";
for(int x=0;x<20;x++)
{
delay(100);
cout<<'\4' ;
}
clrscr();
}
/*Function Definition For Checking Duplicate e-mail ID's*/
void checkid(char c[20])
{
get_info F;
ifstream fin("db.dat",ios::binary);     //creating an ifstream object
while(fin.read((char*)&F,sizeof(F)))
if(strcmp(F.id,c)==0)
{
cout<<"\n\n\t\tSorry, The E-Mail ID Is Already In Use!";
delay(2000);
exit(0);
}
fin.close();
}
/*Function Definition for Deleting an Account*/
void deleter(char id[20])
{
get_info P;
ifstream finn("db.dat",ios::binary); //creating an ifstream object
if(!finn)
cout<<"\n\n\t\tDatabase Missing / Corrupt!";
else
{
ofstream fout("temp.dat",ios::binary|ios::app);   //creating a temporary ofstream object
while(finn.read((char*)&P,sizeof(P)))
{
if(strcmp(P.id,id)!=0)
fout.write((char*)&P,sizeof(P));
}
finn.close();
fout.close();
remove("db.dat");
rename("temp.dat","db.dat");
}
}
/* Main Function Definitions*/
void main()
{
textcolor(10);
textbackground(0);
ofstream fout("db.dat",ios::binary|ios::app);
get_info G;
char accept,id[20],passwd[20],agree,cont;
int opt;
time_t t; //t is time type variable now.
unsigned int seedval;
strcpy(G.status,"-");    /*Initialising values to default*/
G.thought=0;
G.contacts=0;
G.fno=0;
char cnfrm,pass2[20],verify[20],det;
clrscr();
cout<<"\n\n\n\n\n\n\t\t";
cout<<"\n\t                           \\|||//";
cout<<"\n\t     .-.________            (o o)             ________.-.";
cout<<"\n\t----/ \\_)_______) +---------(_)---------+ (_______(_/ \\----";
cout<<"\n\t   (    ()___ )    |Project Done By:     |  (___()    )";
cout<<"\n\t        ()__ )     |                     |    (__()";
cout<<"\n\t----\\___()_)      |Maulik & Riya        |      (_()___/----";
cout<<"\n\t                   +----------C++--------+";
cout<<"\n\n\n\n\t\t\tPress Any Key to Proceed!";
getch();
d_lay();
cout<<"\n\t\t\tDISCLAIMER";
cout<<"\n\t\t\t-_-_-_-_-_";
cout<<"\n\n  The Hook Is a service that offers free networking with no guarantees";
cout<<"\n  for uptime or performance and reserves the right to terminate accounts";
cout<<"\n  at any time for no specific reason. The Owners and operators of The Hook";
cout<<"\n  do not verify the information posted on the website and assume no liability";
cout<<"\n  for the accuracy of such information.";
cout<<"\n  The Hook reserves the right to judge what is acceptable use of the website ";
cout<<"\n  may be changed or deleted to ensure acceptable use without any liability";
cout<<"\n  assumed for such actions.";
cout<<"\n  By using this site your certify that:";
cout<<"\n\4You are at least 18 years of age.";
cout<<"\n\4You are using this site for personal reason and not for commercial gain.";
cout<<"\n\4You are using this site only when permitted by law.";
cout<<"\n  This release of liability shall be contrued briadly to provide";
cout<<"\n  a release and waiver to the maximum extent permissible under applicable";
cout<<"\n  law. I CERTIFY THAT I HAVE READ THIS DOCUMENT AND I FULLY UNDERSTAND";
cout<<"\n  ITS CONTENT. I AM AWARE THAT THIS IS A RELEASE OF LIABILITY AND A";
cout<<"\n  CONTRACT AND I AGREE TO IT OF MY OWN FREE WILL.";
cout<<"\n\n\tAccept & Proceed?(Y/N):  ";
cin>>accept;
if(accept=='Y' || accept=='y')
{
d_lay();
cout<<"\nhttps://www.TheHook.com/Home/";
cout<<"\n\n\n\n\n\t\t\tWelcome To The Hook!";
cout<<"\n\n\n\n\n\n\t\tWanna Login Or Signup?(L/S):  ";
cin>>det;
if(det=='L' || det=='l')
{
get_info I;
ifstream fin("db.dat",ios::binary);
d_lay();
cout<<"\nhttps://www.faceapp.com/login.php";
cout<<"\n\n\n\n\t\tEnter Your E-Mail ID:  ";
gets(id);
cout<<"\n\n\t\tEnter Your Password:  ";
gets(passwd);
if(!fin)
cout<<"\n\n\t\tDatabase Corrupt/Missing!";
else
{
d_lay();
while(fin.read((char*)&I,sizeof(I)))
if((strcmp(I.id,id)==0)&&(strcmp(I.pass1,passwd)==0)) //Traversing Through the file
{
ofstream O("online.dat",ios::binary|ios::app);
O.write((char*)&I,sizeof(I));
O.close();
fin.close();
do{
clrscr();
cout<<"\n\n\t\tWelcome to Your Profile "<<I.name<<"!";
cout<<"\n\t"<<"Name:"<<I.name<<"\n\t"<<"Date of Birth:"<<I.dob<<"\n\t"<<"Gender:"<<I.gender<<"\n\t"<<"E-Mail ID:"<<I.id<<"\n\t"<<"Contact Number:"<<I.fone;
cout<<"\n\tLives in: "<<I.city<<","<<I.state<<"["<<I.country<<"] ,Hometown:"<<I.hometown;
cout<<"\n\tRelationship Status:\t"<<I.rel;
cout<<"\n\t\tLast Thought Shared:\t"<<I.status;
cout<<"\n\t\tNumber of Thoughts Shared:"<<I.thought;
cout<<"\n\n\t\tHere are Your Options:";
cout<<"\n\t\t1)Share Your Thoughts...";
cout<<"\n\t\t2)View People Online...";
cout<<"\n\t\t3)Find A Friend!";
cout<<"\n\t\t4)Edit Your Account...";
cout<<"\n\t\t5)Delete Your Account...";
cout<<"\n\t\t6)View Your Friends...";
cout<<"\n\t\t7)Report A Bug...";
cout<<"\n\t\t8)About The Hook!";
cout<<"\n\t\t9)Acknowledgements...";
cout<<"\n\t\t10)View the License Agreement.";
cout<<"\n\t\t11)Logout...";
cout<<"\n\n\t\tEnter your Option:  ";
cin>>opt;
switch(opt)
{
case 1:
{
d_lay();
cout<<"\n\n\t\tWhat\'s On Your Mind?";
cout<<"\n\n\t\tPress \'ENTER\' to Share!\n\n\t\t";
gets(I.status);
I.thought+=1;
d_lay();
cout<<"\n\n\t\t";
puts(I.status);
cout<<"\n\n\t\tYour Thoughts Have Been Shared!";
break;
}
case 2:
{
d_lay();
get_info O;
ifstream c("online.dat",ios::binary);
if(!c)
cout<<"\n\n\t\tDatabase Missing/Corrupt!";
else
{
cout<<"\n\n\t\tFriend\'s Online! ";
while(c.read((char*)&O,sizeof(O)))
{
if(strcmp(I.id,O.id)!=0)
cout<<"\n\t\t"<<O.name<<" ["<<O.id<<"]";
}
c.close();
}
break;
}
case 3:
{
d_lay();
cout<<"\n\n\t\tEnter The E-Mail ID:  ";
gets(I.id1);
d_lay();
if(strcmp(I.id,I.id1)==0) //checking if the person has searched for himself
cout<<"\n\n\t\tOMG! That's You! (-_-)";
else
{
int flag=0;
char opt;
get_info P;
ifstream f("db.dat",ios::binary);
while(f.read((char*)&P,sizeof(P)))  //traversing through the file
if(strcmp(I.id1,P.id)==0)
{
cout<<"\n\t"<<"Name:"<<P.name<<"\n\t"<<"Date of Birth:"<<P.dob<<"\n\t"<<"Gender:"<<P.gender<<"\n\t"<<"E-Mail ID:"<<P.id<<"\n\t"<<"Contact Number:"<<P.fone;
cout<<"\n\tLives in: "<<P.city<<","<<P.state<<"["<<P.country<<"] ,Hometown:"<<P.hometown;
cout<<"\n\tRelationship Status:\t"<<P.rel;
cout<<"\n\n\t\tWanna Add This Person To Your Circle?\t";
cin>>opt;
if(opt=='y' || opt=='Y')
{
for(int i=0;i<I.fno;i++)
{
if(strcmp(I.fname[i],I.id1)==0)
flag++;
}
if(flag==0)
{
I.contacts++;
strcpy(I.fname[I.fno++],P.name);
cout<<"\n\n\t\tNumber of People in your Circle:"<<I.fno;
}
if(flag!=0)
cout<<"\n\n\t\tUser Already In The Circle!";
}
else
break;
}
f.close();
}
break;
}
case 4:
{
d_lay();
char choi;int c=0;
do{
clrscr();
cout<<"\n\n\t\tYou CANNOT Edit Your Name, DOB, Gender And ID!";
cout<<"\n\n\t\t1)Change Your Relationship Status!";
cout<<"\n\t\t2)Edit Your Phone Number!";
cout<<"\n\t\t3)Change Your Location Info!";
cout<<"\n\t\t4)Change Your Password!";
cout<<"\n\n\t\tEnter Your Choice:  ";
cin>>c;
if(c==1)
{
cout<<"\n\n\t\tEnter Your Relationship Status:  ";
gets(I.rel);
}
else if(c==2)
{
cout<<"\n\n\t\tEnter your New Phone Number:  ";
cin>>I.fone;
}
else if(c==3)
{
cout<<"\n\n\t\tLocation Info-";
cout<<"\n\n\t\tHometown: ";
gets(I.hometown);
cout<<"\n\t\tCurrent City:  ";
gets(I.city);
cout<<"\n\t\tState:  ";
gets(I.state);
cout<<"\n\t\tCountry:  ";
gets(I.country);
}
else if(c==4)
{
int flag=0;
char h[20],j[20],c[20];
do
{
if(flag==0)
cout<<"\n\n\t\tEnter Your Old Password:  ";
else
cout<<"\n\n\t\tPlease Enter Your Old Password Correctly:  ";
gets(c);
flag++;
}while(strcmp(I.pass1,c)==0);
cout<<"\n\n\t\tEnter your New Password:  ";
gets(h);
cout<<"\n\n\t\tRe-Enter your New Password:  ";
gets(j);
if(strcmp(h,j)==0)    //checking for password
strcpy(I.pass1,h);
else
cout<<"\n\n\t\tPassword Do Not Match!";
}
cout<<"\n\n\t\tDo You Wanna Continue Editting?(Y/N)";
cin>>choi;
}while(choi=='y' || choi=='Y');
break;
}
case 5:
{
d_lay();
char x;
cout<<"\n\n\t\tAre you Sure?\t";
cin>>x;
if(x=='y'||x=='Y')
{
deleter(I.id);
cout<<"\n\n\t\tAccount Successfully Deleted!";
cout<<"\n\t\tPlease Come Back Soon... ";
delay(2000);
exit(0);
}
else
break;
}
case 6:
{
cout<<"\n\t\tPeople In Your Circle:";
ifstream fn1("db.dat",ios::binary);
if(!fn1)
cout<<"\n\t\tDatabase Corrupt/Missing!";
else
{
get_info O;
while(fn1.read((char*)&O,sizeof(O)))
if(strcmp(O.id,I.id)==0)
for(int i=0;i<I.fno;i++)
cout<<"\n\n\t\t"<<I.fname[i];
get_info K;
ifstream f("db.dat",ios::binary);
ofstream fou("tmp.dat",ios::binary|ios::app);  //Displaying Friends
fou.write((char*)&G,sizeof(I));
while(f.read((char*)&K,sizeof(K)))
if(strcmp(I.id,K.id)!=0)
fou.write((char*)&K,sizeof(K));
f.close();
fou.close();
remove("db.dat");
rename("tmp.dat","db.dat");
}
fn1.close();
break;
}
case 7:
{
d_lay();
cout<<"\n\n\t\tExplain About The Bug Briefly:\n\n\t";
cout<<"\n\n\t\tPress \'ENTER\' To Submit!\n\n\t\t";
gets(I.bug);
d_lay();
cout<<"\n\n\t\tYour Report Has Been Submitted...";
cout<<"\n\n\t\tThank You!";
break;
}
case 8:
{
d_lay();
cout<<"\n                          .-----------------TTTT_-----_______";
cout<<"\n                        /''''''''''(______O] ----------____  \\______/]_";
cout<<"\n     __...---'\"""\_ --''                  www.TheHook.com     ___________@";
cout<<"\n |\'\'\'                   ._   _______________=---------\"\"\"\"\"\"\"\"";
cout<<"\n |                ..--\'\'|   l L |_l   |";
cout<<"\n |          ..--\'\'      .  /-___j '   \'";
cout<<"\n |    ..--\'\'           /  \,       \'\'";
cout<<"\n |--\'\'                /           `    \"";
cout<<"\n                      L__\'         \\    -";
cout<<"\n                                    -    \'-.";
cout<<"\n                                     \'.    /";
cout<<"\n\nThe Hook is a Social Networking Site still being worked on!";
break;
}
case 9:
{
d_lay();
cout<<"\n\nThe \"The Hook\" team Gratefully acknowledges Ms.Uma Arthi for her Inspiration";
cout<<"and Ms.Jaya for instilling the seeds of C++ in us!";
cout<<"\nThe team also acknowledges Mark Zuckerberg for, we were Inspired by him!";
break;
}
case 10:
{
d_lay();
cout<<"\t\tCopyright æ2011-2012æ The Codewriter Team.";
cout<<"\n\tEnd User Licence Agreement for The Hook. Please read carefully.;";
cout<<"\n\tBy using this website (or any site based on this site) you shall be deemed";
cout<<"to have accepted the terms and conditions set out below.";
cout<<"\n\tThe Hook is making this website freely available on the basis that";
cout<<"it is accepted as found and that the user checks its fitness for purpose prior to use.";
cout<<"\n\tThis website is provided 'as-is', without any express or implied warranties whatsoever.";
cout<<"In no event will the authors, partners or contributors be held liable for any damages,";
cout<<"claims or other liabilities direct or indirect, arising from the use/access of this website.";
cout<<"\n\tThe Hook will from time to time update the Site. However, The Hook accepts no obligation";
cout<<"to provide any support to users.";
cout<<"\n\n\t\t Read Our Full License T&C?(Y/N):  ";
cin>>agree;
if(agree=='y' || agree=='Y')
{
d_lay();
cout<<"\n\n  The Hook Is a service that offers free networking with no guarantees";
cout<<"\n  for uptime or performance and reserves the right to terminate accounts";
cout<<"\n  at any time for no specific reason. The Owners and operators of The Hook";
cout<<"\n  do not verify the information posted on the website and assume no liability";
cout<<"\n  for the accuracy of such information.";
cout<<"\n  The Hook reserves the right to judge what is acceptable use of the website ";
cout<<"\n  may be changed or deleted to ensure acceptable use without any liability";
cout<<"\n  assumed for such actions.";
cout<<"\n  By using this site your certify that:";
cout<<"\n\4You are at least 18 years of age.";
cout<<"\n\4You are using this site for personal reason and not for commercial gain.";
cout<<"\n\4You are using this site only when permitted by law.";
cout<<"\n  This release of liability shall be contrued briadly to provide";
cout<<"\n  a release and waiver to the maximum extent permissible under applicable";
cout<<"\n  law. I CERTIFY THAT I HAVE READ THIS DOCUMENT AND I FULLY UNDERSTAND";
cout<<"\n  ITS CONTENT. I AM AWARE THAT THIS IS A RELEASE OF LIABILITY AND A";
cout<<"\n  CONTRACT AND I AGREE TO IT OF MY OWN FREE WILL.";
}
break;
}
case 11:
{
get_info K,L;
ofstream h("tempo.dat",ios::binary|ios::app);
ifstream i("online.dat",ios::binary);
while(i.read((char*)&L,sizeof(L)))
if(strcmp(I.id,L.id)!=0)
h.write((char*)&L,sizeof(L));
h.close(); i.close();
remove("online.dat"); rename("tempo.dat","online.dat");
ifstream f("db.dat",ios::binary);
ofstream fou("tmp.dat",ios::binary|ios::app);
fou.write((char*)&I,sizeof(I));
while(f.read((char*)&K,sizeof(K)))
if(strcmp(I.id,K.id)!=0)
fou.write((char*)&K,sizeof(K));
f.close();
fou.close();
remove("db.dat");
rename("tmp.dat","db.dat");
clrscr();
cout<<"\n\n\n\n\n\n\n\t\t\tLogging Out ";
for(int x=0;x<20;x++)
{
delay(100);
cout<<'\4' ;
}
clrscr();
cout<<"\n\n\n\n\n\n\t\tLogged Out!";
delay(2000);
exit(0);
}
default :
{
cout<<"\n\n\t\tWrong Option!";
}
}
cout<<"\n\n\t\t Go to the Previous Menu?\t";
cin>>cont;
if(cont=='n'||cont=='N')
{                           //writing onto a file when a person comes out of a loop.
get_info K,L;
ofstream h("tempo.dat",ios::binary|ios::app);
ifstream i("online.dat",ios::binary);
while(i.read((char*)&L,sizeof(L)))
if(strcmp(I.id,L.id)!=0)
h.write((char*)&L,sizeof(L));
h.close();
i.close();
remove("online.dat");
rename("tempo.dat","online.dat");
ifstream f("db.dat",ios::binary);
ofstream fou("tmp.dat",ios::binary|ios::app);
fou.write((char*)&I,sizeof(I));
while(f.read((char*)&K,sizeof(K)))
if(strcmp(I.id,K.id)!=0)
fou.write((char*)&K,sizeof(K));
f.close();
fou.close();
remove("db.dat");
rename("tmp.dat","db.dat");
}
}while(cont=='y' || cont=='Y');
}
if((strcmp(I.id,id)!=0)&&(strcmp(I.pass1,passwd)!=0))
{
cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\tIncorrect ID And Password Combo!";
cout<<"\n\n\t\t\tPlease Try Again!";
delay(2000);
}
}
}
else if(det=='S' || det=='s')
{
d_lay();
seedval=((unsigned) time (&t)); //time(&t) function will initialize time variable t with system time.
srand(seedval); //seed the random no. generator.
cout<<"https://www.thehook.com/sign_up.php";
cout<<"\n\n\t\tYour Unique Network ID is:\t"<<" "<<rand()<<"-"<<rand()<<"-"<<rand()<<"-"<<rand()<<endl;
cout<<"\n\n\t\tEnter Your Name:  ";
gets(G.name);
cout<<"\n\n\t\tEnter Your Date Of Birth(DD/MM/YYYY):  ";
gets(G.dob);
cout<<"\n\n\t\tEnter Your Gender(M/F):  ";
cin>>G.gender;
cout<<"\n\n\t\tEnter Your E-Mail ID:  ";
gets(G.id);
cout<<"\n\n\t\tEnter Your Mobile Number:  ";
gets(G.fone);
cout<<"\n\n\t\tEnter Your Current City:  ";
gets(G.city);
cout<<"\n\n\t\tEnter The State:  ";
gets(G.state);
cout<<"\n\n\t\tEnter Your Nationality:  ";
gets(G.country);
cout<<"\n\n\t\tEnter Your Hometown:  ";
gets(G.hometown);
cout<<"\n\n\t\tRelationship Status:  ";
gets(G.rel);
cout<<"\n\n\t\tEnter a Password:  ";
gets(G.pass1);
cout<<"\n\n\t\tRe-enter your Password:  ";
gets(pass2);
if(strcmp(G.pass1,pass2)==0)
cout<<"\n\n\t\tPasswords Match \2";
else
{
d_lay();
cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\tPasswords Do Not Match!!";
delay(2000);
exit(0);
}
if(strcmp(G.pass1,pass2)==0)
{
cout<<"\n\n\t\tWe wont share ur account info with any third party!";
cout<<"\n\n\t\tCreate your Account(Y/N)?  ";
cin>>cnfrm;
}
if(cnfrm=='Y' || cnfrm=='y')
{
d_lay();
checkid(G.id);
char x[20],cx[20];
randomize();
for(int i=0;i<10;i++)
{
x[i]=random(26)+65;
if(i==2)
x[i]=random(26)+97;
if(i%2==0)
x[i]=random(26)+97;
if(i==2)
x[i]='&';
if(i==6)
x[i]='!';
x[9]='\0';
x[0]=random(26)+65;
}
cout<<"\n\n\t\tSecurity Check:";
cout<<"\n\t\t**************";
cout<<"\n\n\n\t\t";
puts(x);                              //checking for spams
cout<<"\n\n\tEnter the Captcha Displayed to Help us Prevent Spams:  ";
gets(cx);
clrscr();
if(strcmp(cx,x)==0)
{
fout.write((char*)&G,sizeof(G));
d_lay();
do{
clrscr();
cout<<"\n\n\t\tWelcome to Your Profile "<<G.name<<"!";
cout<<"\n\t"<<"Name:"<<G.name<<"\n\t"<<"Date of Birth:"<<G.dob<<"\n\t"<<"Gender:"<<G.gender<<"\n\t"<<"E-Mail ID:"<<G.id<<"\n\t"<<"Contact Number:"<<G.fone;
cout<<"\n\tLives in: "<<G.city<<","<<G.state<<"["<<G.country<<"] ,Hometown:"<<G.hometown;
cout<<"\n\n\t\tRelationship Status:\t"<<G.rel;
cout<<"\n\t\tLast Thought Shared:\t"<<G.status;
cout<<"\n\t\tNumber of Thoughts Shared:"<<G.thought;
cout<<"\n\n\t\tHere are Your Options:";
cout<<"\n\t\t1)Share Your Thoughts...";
cout<<"\n\t\t2)View People Online...";
cout<<"\n\t\t3)Find A Friend!";
cout<<"\n\t\t4)Edit Your Account..";
cout<<"\n\t\t5)Delete Your Account.";
cout<<"\n\t\t6)View Your Friends!";
cout<<"\n\t\t7)Report A Bug...";
cout<<"\n\t\t8)About The Hook!";
cout<<"\n\t\t9)Acknowledgements.";
cout<<"\n\t\t10)View the License Agreement.";
cout<<"\n\t\t11)Logout.";
cout<<"\n\n\t\tEnter your Option:  ";
cin>>opt;
switch(opt)
{
case 1:
{
d_lay();
cout<<"\n\n\t\tWhat\'s On Your Mind?";
cout<<"\n\n\t\tPress \'ENTER\' to Share!\n\n\t\t";
gets(G.status);
G.thought+=1;
d_lay();
cout<<"\n\n\t\t";
puts(G.status);
cout<<"\n\n\t\tYour Thoughts Have Been Shared!";
break;
}
case 2:
{
d_lay();
get_info O;
ifstream c("online.dat",ios::binary);
if(!c)
cout<<"\n\n\t\tDatabase Missing/Corrupt!";
else
{
cout<<"\n\n\t\tFriend\'s Online! ";
while(c.read((char*)&O,sizeof(O)))
{
if(strcmp(G.id,O.id)!=0)
cout<<"\n\t\t"<<O.name<<" ["<<O.id<<"]";
}
c.close();
}
break;
}
case 3:
{
d_lay();
cout<<"\n\n\t\tEnter The E-Mail ID:  ";
gets(G.id1);
d_lay();
if(strcmp(G.id,G.id1)==0)
cout<<"\n\n\t\tOMG! That's You! (-_-)";
else
{
int flag=0;
char opt;
get_info P;
ifstream f("db.dat",ios::binary);
while(f.read((char*)&P,sizeof(P)))
if(strcmp(G.id1,P.id)==0)
{
cout<<"\n\t"<<"Name:"<<P.name<<"\n\t"<<"Date of Birth:"<<P.dob<<"\n\t"<<"Gender:"<<P.gender<<"\n\t"<<"E-Mail GD:"<<P.id<<"\n\t"<<"Contact Number:"<<P.fone;
cout<<"\n\tLives in: "<<P.city<<","<<P.state<<"["<<P.country<<"] ,Hometown:"<<P.hometown;
cout<<"\n\tRelationship Status:\t"<<P.rel;
cout<<"\n\n\t\tWanna Add This Person To Your Circle?\t";
cin>>opt;
if(opt=='y' || opt=='Y')
{
for(int i=0;i<G.fno;i++)
{
if(strcmp(G.fname[i],G.id1)==0)
flag++;
}
if(flag==0)
{
G.contacts++;
strcpy(G.fname[G.fno++],P.name);
cout<<"\n\n\t\tNumber of People in your Circle:"<<G.fno;
}
if(flag!=0)
cout<<"\n\n\t\tUser Already Gn The Circle!";
}
else
break;
}
f.close();
}
break;
}
case 4:
{
d_lay();
char choi;int c=0;
do{
clrscr();
cout<<"\n\n\t\tYou CANNOT Edit Your Name, DOB, Gender And ID!";
cout<<"\n\n\t\t1)Change Your Relationship Status!";
cout<<"\n\t\t2)Edit Your Phone Number!";
cout<<"\n\t\t3)Change Your Location Info!";
cout<<"\n\t\t4)Change Your Password!";
cout<<"\n\n\t\tEnter Your Choice:  ";
cin>>c;
if(c==1)
{
cout<<"\n\n\t\tEnter Your Relationship Status:  ";
gets(G.rel);
}
else if(c==2)
{
cout<<"\n\n\t\tEnter your New Phone Number:  ";
cin>>G.fone;
}
else if(c==3)
{
cout<<"\n\n\t\tLocation Info-";
cout<<"\n\n\t\tHometown: ";
gets(G.hometown);
cout<<"\n\t\tCurrent City:  ";
gets(G.city);
cout<<"\n\t\tState:  ";
gets(G.state);
cout<<"\n\t\tCountry:  ";
gets(G.country);
}
else if(c==4)
{
int flag=0;
char h[20],j[20],c[20];
do
{
if(flag==0)
cout<<"\n\n\t\tEnter Your Old Password:  ";
else
cout<<"\n\n\t\tPlease Enter Your Old Password Correctly:  ";
gets(c);
flag++;
}while(strcmp(G.pass1,c)==0);
cout<<"\n\n\t\tEnter your New Password:  ";
gets(h);
cout<<"\n\n\t\tRe-Enter your New Password:  ";
gets(j);
if(strcmp(h,j)==0)
strcpy(G.pass1,h);
else
cout<<"\n\n\t\tPassword Do Not Match!";
}
cout<<"\n\n\t\tDo You Wanna Continue Editing?(Y/N)";
cin>>choi;
}while(choi=='y' || choi=='Y');
break;
}
case 5:
{
d_lay();
char x;
cout<<"\n\n\t\tAre you Sure?\t";
cin>>x;
if(x=='y'||x=='Y')
{
deleter(G.id);
cout<<"\n\n\t\tAccount Successfully Deleted...";
cout<<"\n\t\tPlease Come Back Soon! ";
delay(2000);
exit(0);
}
else
break;
}
case 6:
{
cout<<"\n\t\tPeople In Your Circle:";
ifstream fn1("db.dat",ios::binary);
if(!fn1)
cout<<"\n\t\tDatabase Corrupt/Missing!";
else
{
get_info O;
while(fn1.read((char*)&O,sizeof(O)))
if(strcmp(O.id,G.id)==0)
for(int i=0;i<G.fno;i++)
cout<<"\n\n\t\t"<<G.fname[i];
get_info K;
ifstream f("db.dat",ios::binary);
ofstream fou("tmp.dat",ios::binary|ios::app);
fou.write((char*)&G,sizeof(G));
while(f.read((char*)&K,sizeof(K)))
if(strcmp(G.id,K.id)!=0)
fou.write((char*)&K,sizeof(K));
f.close();
fou.close();
remove("db.dat");
rename("tmp.dat","db.dat");
}
fn1.close();
break;
}
case 7:
{
d_lay();
cout<<"\n\n\t\tExplain About The Bug Briefly!\n\n\t";
cout<<"\n\n\t\tPress \'ENTER\' To Submit!\n\n\t\t";
gets(G.bug);
d_lay();
cout<<"\n\n\t\tYour Report Has Been Submitted...";
cout<<"\n\n\t\tThank You!";
break;
}
case 8:
{
d_lay();
cout<<"\n                          .-----------------TTTT_-----_______";
cout<<"\n                        /''''''''''(______O] ----------____  \\______/]_";
cout<<"\n     __...---'\"""\_ --''                  www.TheHook.com     ___________@";
cout<<"\n |\'\'\'                   ._   _______________=---------\"\"\"\"\"\"\"\"";
cout<<"\n |                ..--\'\'|   l L |_l   |";
cout<<"\n |          ..--\'\'      .  /-___j '   \'";
cout<<"\n |    ..--\'\'           /  \,       \'\'";
cout<<"\n |--\'\'                /           `    \"";
cout<<"\n                      L__\'         \\    -";
cout<<"\n                                    -    \'-.";
cout<<"\n                                     \'.    /";
cout<<"\n\nThe Hook a Social Networking Site still being worked on!";
break;
}
case 9:
{
d_lay();
cout<<"\n\nThe The Hook team Gratefully acknowledges Ms.Uma Arthi for her Inspiration...and Ms.Jaya for instilling the seeds of C++ in us...";
cout<<"\nThe team also acknowledges Mark Zuckerberg for, we were Inspired by him....";
break;
}
case 10:
{
d_lay();
cout<<"\t\tCopyright æ2011-2012æ The Codewriter Team.";
cout<<"\n\tEnd User Licence Agreement for The Hook. Please read carefully.;";
cout<<"\n\tBy using this website (or any site based on this site) you shall be deemed";
cout<<"to have accepted the terms and conditions set out below.";
cout<<"\n\tThe Hook is making this website freely available on the basis that";
cout<<"it is accepted as found and that the user checks its fitness for purpose prior to use.";
cout<<"\n\tThis website is provided 'as-is', without any express or implied warranties whatsoever.";
cout<<"In no event will the authors, partners or contributors be held liable for any damages,";
cout<<"claims or other liabilities direct or indirect, arising from the use/access of this website.";
cout<<"\n\tThe Hook will from time to time update the Site. However, The Hook accepts no obligation";
cout<<"to provide any support to users.";
cout<<"\n\n\t\t Read Our Full License T&C.??\t";
cin>>agree;
if(agree=='y' || agree=='Y')
{
d_lay();
cout<<"\n\n  The Hook Is a service that offers free hosting with no guarrantees";
cout<<"\n  for uptime or performance and reserves the right to terminate accounts";
cout<<"\n  at any time for no specific reason. The Owners and operators of The Hook";
cout<<"\n  do not verify the information posted on the website and assume no liability";
cout<<"\n  for the accuracy of such information.";
cout<<"\n  The Hook reserves the right to judge what is acceptable use of the website ";
cout<<"\n  may be changed or deleted to ensure acceptable use without any liability";
cout<<"\n  assumed for such actions.";
cout<<"\n  By using this site your certify that:";
cout<<"\n\4You are at least 18 years of age.";
cout<<"\n\4You are using this site for personal reason and not for commercial gain.";
cout<<"\n\4You are using this site only when permitted by law.";
cout<<"\n  This release of liability shall be contrued briadly to provide";
cout<<"\n  a release and waiver to the maximum extent permissible under applicable";
cout<<"\n  law. I CERTIFY THAT I HAVE READ THIS DOCUMENT AND I FULLY UNDERSTAND";
cout<<"\n  ITS CONTENT. I AM AWARE THAT THIS IS A RELEASE OF LIABILITY AND A";
cout<<"\n  CONTRACT AND I AGREE TO IT OF MY OWN FREE WILL.";
}
break;
}
case 11:
{
get_info K,L;
ofstream h("tempo.dat",ios::binary|ios::app);
ifstream i("online.dat",ios::binary);
while(i.read((char*)&L,sizeof(L)))
if(strcmp(G.id,L.id)!=0)
h.write((char*)&L,sizeof(L));
h.close();
i.close();
remove("online.dat");
rename("tempo.dat","online.dat");
ifstream f("db.dat",ios::binary);
ofstream fou("tmp.dat",ios::binary|ios::app);
fou.write((char*)&G,sizeof(G));
while(f.read((char*)&K,sizeof(K)))
if(strcmp(G.id,K.id)!=0)
fou.write((char*)&K,sizeof(K));
f.close();
fou.close();
remove("db.dat");
rename("tmp.dat","db.dat");
clrscr();
cout<<"\n\n\n\n\n\n\n\t\t\tLogging Out ";
for(int x=0;x<20;x++)
{
delay(100);
cout<<'\4' ;}
clrscr();
cout<<"\n\n\n\n\n\n\t\tLogged Out!";
delay(2000);
exit(0);
break;
}
default :
{
cout<<"\n\n\t\tWrong Option!";
}
}
cout<<"\n\n\t\t Go to the Previous Menu(Y/N)?";
cin>>cont;
if(cont=='n'||cont=='N')
{
get_info K,L;
ofstream h("tempo.dat",ios::binary|ios::app);
ifstream i("online.dat",ios::binary);
while(i.read((char*)&L,sizeof(L)))
if(strcmp(G.id,L.id)!=0)
h.write((char*)&L,sizeof(L));
h.close(); i.close();
remove("online.dat");
rename("tempo.dat","online.dat");
ifstream f("db.dat",ios::binary);
ofstream fou("tmp.dat",ios::binary|ios::app);
fou.write((char*)&G,sizeof(G));
while(f.read((char*)&K,sizeof(K)))
if(strcmp(G.id,K.id)!=0)
fou.write((char*)&K,sizeof(K));
f.close();
fou.close();
remove("db.dat");
rename("tmp.dat","db.dat");
}
}while(cont=='y' || cont=='Y');
}
else
{
d_lay();
cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\tCaptcha Ain\'t Similar!";
cout<<"\n\n\t\t\tPlease Try Again!";
delay(2000);
exit(0);
}
}
else
{
d_lay();
cout<<"\n\n\n\n\n\n\n\n\n\t\t\tABORTING!!";
delay(2000);
exit(0);
}
}
else
{
d_lay();
cout<<"\n\n\n\n\n\n\n\n\n\t\t\tINVALID OPTION! ";
delay(2000);
exit(0);
}
}
else
{
d_lay();
cout<<"\n\n\n\n\n\n\n\t\t\tSorry, You Cannot Proceed Any Further!";
delay(2000);
exit(0);
}
fout.close();
}