#include<stdio.h>
    #include<conio.h>
    #include<stdlib.h>
    #include<dos.h>
    #include<time.h>

    #define right 0
    #define left 1
    #define up 2
    #define down 3


    /* Global Declaration */

    int x[100],y[100],i,length=6,score=0,l_k=right,eat=0,xf,yf;
    char ch;

    /* Declaration of Functions */

    void Food(void);
    void Food1(void);
    void Food2(void);
    void rectangle(int x, int y, int l,int b,int bgcolor ,int fgcolor);
    void fillcolor(int x1, int y1,int x2,int y2,int color1,int color2);
    void rectangle1(int x,int y,int l, int b,int bgcolor ,int fgcolor);
    void Level1(void);
    void Level2(void);
    void Level3(void);
    void Level4(void);
    void Instruction(void);
    void Start(void);
    void main()
    {
     clrscr();
     Start();
     Instruction();
     Level1();
     getch();
    }
    /* Level 2 */

    void Level2(void)
    {
    clrscr();

    /* Positioning the snake initally */

    for(i=length-1;i>=0;i--)
    {
    x[i]=25-i;
    y[i]=15;
    }

    /*************************************/
    START:
    textcolor(4);
    textbackground(0);
    gotoxy(65,3);
    cprintf("Û");
    rectangle(1,1,60,24,0,4);
    rectangle1(63,13,78,18,0,4);
    rectangle1(63,1,78,6,0,4);
    rectangle1(63,7,78,12,0,4);
    rectangle1(63,19,78,24,0,4);
    textcolor(15);
    textbackground(4);
    gotoxy(66,3);
    cprintf("SNAKE GAME ");
    gotoxy(67,8);
    cprintf(" LEVEL ");
    gotoxy(70,10);
    cprintf("2");
    gotoxy(67,14);
    cprintf(" SCORE ");
    gotoxy(65,3);

    /*********************************/



    while(1)  /* Infinite Loop    */
    {
    while(kbhit()==0) /* Do Nothing */
    {
    gotoxy(69,16);
    cprintf("%d",score);
    textcolor(15);
    textbackground(0);
    for(i=length-1;i>0;i--)
    {
    x[i]=x[i-1];
    y[i]=y[i-1];
    }
    /* Snake Structure */

    for(i=length-1;i>=0;i--)
    {
    gotoxy(x[i],y[i]);
    printf("|");
    }
    gotoxy(x[0],y[0]);
    printf("O");
    gotoxy(x[length-1],y[length-1]);
    printf(" ");
    Food();
    if(l_k==right || l_k==left)
    {
    delay(80);
    }
    if(l_k==up || l_k==down)
    {
    delay(130);
    }
    /* Hit the Wall */

    if(x[0]==1 || x[0]==60 || y[0]==1 || y[0]==24)
    {
    delay(1000);
    gotoxy(65,21);
    cprintf("  GAME OVER  ");
    gotoxy(65,3);
    delay(1000);
    exit(0);
    }
    if(l_k==right)
    {
    x[0]++;
    }
    if(l_k==left)
    {
    x[0]--;
    }
    if(l_k==up)
    {
    y[0]--;
    }
    if(l_k==down)
    {
    y[0]++;
    }
    /* Hit yourself */
    for(i=length-1;i>1;i--)
    {
    if(x[0]==x[i] && y[0]==y[i])
    {
    textcolor(4);
    textbackground(0);
    delay(1000);
    gotoxy(65,21);
    cprintf("  GAME OVER  ");
    gotoxy(65,3);
    delay(1000);
    exit(0);
    }
    }
    }
    ch=getch();
    if(ch==32)
    {
    textcolor(4);
    textbackground(0);
    gotoxy(65,21);
    cprintf("Û PAUSED... Û");
    while(kbhit()==0)
    gotoxy(65,21);
    printf("  ");
    textcolor(15);
    textbackground(0);
    clrscr();
    goto START;
    }
    if(ch==27)
    {
    textcolor(4);
    textbackground(0);
    delay(1000);
    gotoxy(65,21);
    cprintf(" GAME OVER ");
    gotoxy(65,3);
    delay(1000);
    exit(0);
    }
    else if(ch==72 && l_k!=down)
    l_k=up;
    else if(ch==80 && l_k!=up)
    l_k=down;
    else if(ch==77 && l_k!=left)
    l_k=right;
    else if(ch==75 && l_k!=right)
    l_k=left;
    gotoxy(65,3);
    if(score==180)
    {
    delay(30);
    clrscr();
    gotoxy(27,12);
    printf("Level 2 has been completed.");
    delay(2000);
    Level3();
    }
    }
    }

    /* Level 1 */

    void Level1(void)
    {
    clrscr();

    /* Positioning the snake initally */

    for(i=length-1;i>=0;i--)
    {
    x[i]=25-i;
    y[i]=15;
    }

    /*************************************/
    START:
    textcolor(4);
    textbackground(0);
    gotoxy(65,3);
    cprintf("Û");
    rectangle1(1,1,60,24,0,4);
    rectangle1(63,13,78,18,0,4);
    rectangle1(63,1,78,6,0,4);
    rectangle1(63,7,78,12,0,4);
    rectangle1(63,19,78,24,0,4);
    textcolor(15);
    textbackground(4);
    gotoxy(66,3);
    cprintf("SNAKE GAME ");
    gotoxy(67,8);
    cprintf(" LEVEL ");
    gotoxy(70,10);
    cprintf("1");
    gotoxy(67,14);
    cprintf(" SCORE ");
    gotoxy(65,3);

    /*********************************/



    while(1)  /* Infinite Loop    */
    {
    while(kbhit()==0) /* Do Nothing */
    {
    gotoxy(69,16);
    cprintf("%d",score);
    textcolor(15);
    textbackground(0);
    for(i=length-1;i>0;i--)
    {
    x[i]=x[i-1];
    y[i]=y[i-1];
    }
    /* Snake Structure */

    for(i=length-1;i>=0;i--)
    {
    gotoxy(x[i],y[i]);
    printf("|");
    }
    gotoxy(x[0],y[0]);
    printf("O");
    gotoxy(x[length-1],y[length-1]);
    printf(" ");
    Food();
    if(l_k==right || l_k==left)
    {
    delay(80);
    }
    if(l_k==up || l_k==down)
    {
    delay(130);
    }
    /****************************/

    if(x[0]==1)
    {
    rectangle1(1,1,60,24,0,4);
    x[0]=59;
    }
    if(x[0]==60)
    {
    rectangle1(1,1,60,24,0,4);
    x[0]=2;
    }
    if(y[0]==1)
    {
    rectangle1(1,1,60,24,0,4);
    y[0]=23;
    }
    if(y[0]==24)
    {
    rectangle1(1,1,60,24,0,4);
    y[0]=2;
    }
    /*******************************/

    if(l_k==right)
    {
    x[0]++;
    }
    if(l_k==left)
    {
    x[0]--;
    }
    if(l_k==up)
    {
    y[0]--;
    }
    if(l_k==down)
    {
    y[0]++;
    }
    /* Hit yourself */
    for(i=length-1;i>1;i--)
    {
    if(x[0]==x[i] && y[0]==y[i])
    {
    textcolor(4);
    textbackground(0);
    delay(1000);
    gotoxy(65,21);
    cprintf("  GAME OVER  ");
    gotoxy(65,3);
    delay(1000);
    exit(0);
    }
    }
    }
    ch=getch();
    if(ch==32)
    {
    textcolor(4);
    textbackground(0);
    gotoxy(65,21);
    cprintf("Û PAUSED... Û");
    while(kbhit()==0)
    gotoxy(65,21);
    printf("  ");
    textcolor(15);
    textbackground(0);
    clrscr();
    goto START;
    }
    if(ch==27)
    {
    textcolor(4);
    textbackground(0);
    delay(1000);
    gotoxy(65,21);
    cprintf(" GAME OVER ");
    gotoxy(65,3);
    delay(1000);
    exit(0);
    }
    else if(ch==72 && l_k!=down)
    l_k=up;
    else if(ch==80 && l_k!=up)
    l_k=down;
    else if(ch==77 && l_k!=left)
    l_k=right;
    else if(ch==75 && l_k!=right)
    l_k=left;
    gotoxy(65,3);
    if(score==90)
    {
    delay(30);
    clrscr();
    gotoxy(27,12);
    printf("Level 1 has been completed.");
    delay(2000);
    Level2();
    }
    }
    }


    /* Level 3 */

     void Level3(void)
    {
    int t;
    textcolor(15);
    textbackground(0);
    clrscr();

    /* Positioning the snake initally */

    for(i=length-1;i>=0;i--)
    {
    x[i]=25-i;
    y[i]=15;
    }

    /*************************************/
    START:
    textcolor(4);
    textbackground(0);
    gotoxy(65,3);
    cprintf("Û");
    rectangle1(1,1,60,24,0,4);
    rectangle1(63,13,78,18,0,4);
    rectangle1(63,1,78,6,0,4);
    rectangle1(63,7,78,12,0,4);
    rectangle1(63,19,78,24,0,4);
    for(t=10;t<=50;t++)
    {
    gotoxy(t,6);
    printf("_");
    gotoxy(t,12);
    printf("_");
    gotoxy(t,18);
    printf("_");
    }
    textcolor(15);
    textbackground(4);
    gotoxy(66,3);
    cprintf("SNAKE GAME ");
    gotoxy(67,8);
    cprintf(" LEVEL ");
    gotoxy(70,10);
    cprintf("3");
    gotoxy(67,14);
    cprintf(" SCORE ");
    gotoxy(65,3);

    /*********************************/



    while(1)  /* Infinite Loop    */
    {
    while(kbhit()==0) /* Do Nothing */
    {
    gotoxy(69,16);
    cprintf("%d",score);
    textcolor(15);
    textbackground(0);
    for(i=length-1;i>0;i--)
    {
    x[i]=x[i-1];
    y[i]=y[i-1];
    }
    /* Snake Structure */

    for(i=length-1;i>=0;i--)
    {
    gotoxy(x[i],y[i]);
    printf("O");
    }
    gotoxy(x[0],y[0]);
    printf("|");
    gotoxy(x[length-1],y[length-1]);
    printf(" ");
    Food1();
    if(l_k==right || l_k==left)
    {
    delay(80);
    }
    if(l_k==up || l_k==down)
    {
    delay(130);
    }
    /****************************/

    if(x[0]==1)
    {
    rectangle1(1,1,60,24,0,4);
    x[0]=59;
    }
    if(x[0]==60)
    {
    rectangle1(1,1,60,24,0,4);
    x[0]=2;
    }
    if(y[0]==1)
    {
    rectangle1(1,1,60,24,0,4);
    y[0]=23;
    }
    if(y[0]==24)
    {
    rectangle1(1,1,60,24,0,4);
    y[0]=2;
    }
    /********* Hits The Wall **********/
    if((x[0]>=10&&x[0]<=50&&y[0]==6) || (x[0]>=10&&x[0]<=50&&y[0]==12) || (x[0]>=10&&x[0]<=50&&y[0]==18))
    {
    textcolor(4);
    textbackground(0);
    delay(1000);
    gotoxy(65,21);
    cprintf("  GAME OVER  ");
    gotoxy(65,3);
    delay(1000);
    exit(0);
    }
    /*******************************/

    if(l_k==right)
    {
    x[0]++;
    }
    if(l_k==left)
    {
    x[0]--;
    }
    if(l_k==up)
    {
    y[0]--;
    }
    if(l_k==down)
    {
    y[0]++;
    }
    /* Hit yourself */
    for(i=length-1;i>1;i--)
    {
    if(x[0]==x[i] && y[0]==y[i])
    {
    textcolor(4);
    textbackground(0);
    delay(1000);
    gotoxy(65,21);
    cprintf("  GAME OVER  ");
    gotoxy(65,3);
    delay(1000);
    exit(0);
    }
    }
    }
    ch=getch();
    if(ch==32)
    {
    textcolor(4);
    textbackground(0);
    gotoxy(65,21);
    cprintf("Û PAUSED... Û");
    while(kbhit()==0)
    gotoxy(65,21);
    printf("  ");
    textcolor(15);
    textbackground(0);
    clrscr();
    goto START;
    }
    if(ch==27)
    {
    textcolor(4);
    textbackground(0);
    delay(1000);
    gotoxy(65,21);
    cprintf(" GAME OVER ");
    gotoxy(65,3);
    delay(1000);
    exit(0);
    }
    else if(ch==72 && l_k!=down)
    l_k=up;
    else if(ch==80 && l_k!=up)
    l_k=down;
    else if(ch==77 && l_k!=left)
    l_k=right;
    else if(ch==75 && l_k!=right)
    l_k=left;
    gotoxy(65,3);
    if(score==270)
    {
    delay(30);
    clrscr();
    gotoxy(27,12);
    printf("Level 3 has been completed.");
    delay(2000);
    Level4();
    }
    }
    }

    /* Level 4 */

    void Level4(void)
    {
    int t;
    textcolor(15);
    textbackground(0);
    clrscr();

    /* Positioning the snake initally */

    for(i=length-1;i>=0;i--)
    {
    x[i]=45-i;
    y[i]=15;
    }

    /*************************************/
    START:
    textcolor(4);
    textbackground(0);
    gotoxy(65,3);
    cprintf("Û");
    rectangle1(1,1,60,24,0,4);
    rectangle1(63,13,78,18,0,4);
     rectangle1(63,1,78,6,0,4);
    rectangle1(63,7,78,12,0,4);
    rectangle1(63,19,78,24,0,4);
    for(t=5;t<=12;t++)
    {
    gotoxy(10,t);
    printf("³");
    gotoxy(50,t);
    printf("³");
    }
    for(t=17;t<=21;t++)
    {
    gotoxy(20,t);
    printf("³");
    }
    for(t=40;t<=55;t++)
    {
     gotoxy(t,18);
     printf("_");
    }
    for(t=20;t<=40;t++)
    {
     gotoxy(t,7);
     printf("_");
    }
    textcolor(15);
    textbackground(4);
    gotoxy(66,3);
    cprintf("SNAKE GAME ");
    gotoxy(67,8);
    cprintf(" LEVEL ");
    gotoxy(70,10);
    cprintf("4");
    gotoxy(67,14);
    cprintf(" SCORE ");
    gotoxy(65,3);

    /*********************************/



    while(1)  /* Infinite Loop    */
    {
    while(kbhit()==0) /* Do Nothing */
    {
    gotoxy(69,16);
    cprintf("%d",score);
    textcolor(15);
    textbackground(0);
    for(i=length-1;i>0;i--)
    {
    x[i]=x[i-1];
    y[i]=y[i-1];
    }
    /* Snake Structure */

    for(i=length-1;i>=0;i--)
    {
    gotoxy(x[i],y[i]);
    printf("O");
    }
    gotoxy(x[0],y[0]);
    printf("|");
    gotoxy(x[length-1],y[length-1]);
    printf(" ");
    Food2();
    if(l_k==right || l_k==left)
    {
    delay(80);
    }
    if(l_k==up || l_k==down)
    {
    delay(130);
    }
    /****************************/

    if(x[0]==1)
    {
    rectangle1(1,1,60,24,0,4);
    x[0]=59;
    }
    if(x[0]==60)
    {
    rectangle1(1,1,60,24,0,4);
    x[0]=2;
    }
    if(y[0]==1)
    {
    rectangle1(1,1,60,24,0,4);
    y[0]=23;
    }
    if(y[0]==24)
    {
    rectangle1(1,1,60,24,0,4);
    y[0]=2;
    }
    /*************** Hits  the Wall *******************/

    if((x[0]==10 && (y[0]>=5 && y[0]<=12)) || (x[0]==50 && (y[0]>=5 && y[0]<=12)) || (x[0]==20 && (y[0]>=17 && y[0]<=21)) )
    {
    textcolor(4);
    textbackground(0);
    delay(1000);
    gotoxy(65,21);
    cprintf("  GAME OVER  ");
    gotoxy(65,3);
    delay(1000);
    exit(0);
    }

    if(((x[0]>=40 && x[0]<=55) && y[0]==18) ||  ((x[0]>=20 && x[0]<=40) && y[0]==7))
    {
    textcolor(4);
    textbackground(0);
    delay(1000);
    gotoxy(65,21);
    cprintf("  GAME OVER  ");
    gotoxy(65,3);
    delay(1000);
    exit(0);
    }
    /*******************************/


    if(l_k==right)
    {
    x[0]++;
    }
    if(l_k==left)
    {
    x[0]--;
    }
    if(l_k==up)
    {
    y[0]--;
    }
    if(l_k==down)
    {
    y[0]++;
    }
    /* Hit yourself */
    for(i=length-1;i>1;i--)
    {
    if(x[0]==x[i] && y[0]==y[i])
    {
    textcolor(4);
    textbackground(0);
    delay(1000);
    gotoxy(65,21);
    cprintf("  GAME OVER  ");
    gotoxy(65,3);
    delay(1000);
    exit(0);
    }
    }
    }
    ch=getch();
    if(ch==32)
    {
    textcolor(4);
    textbackground(0);
    gotoxy(65,21);
    cprintf("Û PAUSED... Û");
    while(kbhit()==0)
    gotoxy(65,21);
    printf("  ");
    textcolor(15);
    textbackground(0);
    clrscr();
    goto START;
    }
    if(ch==27)
    {
    textcolor(4);
    textbackground(0);
    delay(1000);
    gotoxy(65,21);
    cprintf(" GAME OVER ");
    gotoxy(65,3);
    delay(1000);
    exit(0);
    }
    else if(ch==72 && l_k!=down)
    l_k=up;
    else if(ch==80 && l_k!=up)
    l_k=down;
    else if(ch==77 && l_k!=left)
    l_k=right;
    else if(ch==75 && l_k!=right)
    l_k=left;
    gotoxy(65,3);
    }
    }

    void Food(void)
    {
    if(eat==0)
    {
    srand(time(NULL));  /* Initializes random number generator  */
    xf=(rand()%(20))+4;  /* Generates random number */
    yf=(rand()%(21))+3;
    eat=1;
    }
    if((xf==1 || xf==60) || (yf==1 || yf==24))
    {
    xf=3;
    yf=3;
    }
    gotoxy(xf,yf);
    printf("M");
    gotoxy(65,3);
    if((xf==x[0]) && (yf==y[0]))
    {
    sound(2000);
    delay(30);
    nosound();
    score=score+9;
    length++;
    eat=0;
    }
    }

    void Food1(void)
    {
    if(eat==0)
    {
    srand(time(NULL));  /* Initializes random number generator  */
    xf=(rand()%(20))+4;  /* Generates random number */
    yf=(rand()%(21))+3;
    eat=1;
    }
    if((xf>=10&&xf<=50&&yf==6) || (xf>=10&&xf<=50&&yf==12) || (xf>=10&&xf<=50&&yf==18) || (xf==1 || xf==60) || (yf==1 || yf==24))
    {
    xf=5;
    yf=3;
    }
    gotoxy(xf,yf);
    printf("M");
    gotoxy(65,3);
    if((xf==x[0]) && (yf==y[0]))
    {
    sound(2000);
    delay(30);
    nosound();
    score=score+9;
    length++;
    eat=0;
    }
    }
    void Food2(void)
    {

    if(eat==0)
    {
    srand(time(NULL));  /* Initializes random number generator  */
    xf=(rand()%(20))+4;  /* Generates random number */
    yf=(rand()%(21))+3;
    eat=1;
    }
    if((xf==1 || xf==60) || (yf==1 || yf==24))
    {
    xf=6;
    yf=3;
    }

    if((xf==10 && (yf>=5 && yf<=12)) || (xf==50 && (yf>=5 && yf<=12)) || (xf==20 && (yf>=17 && yf<=21)) )
    {
    xf=5;
    yf=2;

    }

    if(((xf>=40 && xf<=55) && yf==18) ||  ((xf>=20 && xf<=40) && yf==7))
    {
    xf=3;
    yf=2;

    }



    gotoxy(xf,yf);
    printf("M");
    gotoxy(65,3);
    if((xf==x[0]) && (yf==y[0]))
    {
    sound(2000);
    delay(30);
    nosound();
    score=score+9;
    length++;
    eat=0;
    }
    }

    void Start(void)
    {
    clrscr();
    fillcolor(3,3,76,23,10,0);
    rectangle(2,2,78,24,6,6);
    rectangle(3,2,77,24,6,6);
    textcolor(WHITE);
    textbackground(RED);
    gotoxy(35,5);
    cprintf(" SNAKE GAME ");
    gotoxy(30,10);
    cprintf("Designed and Programmed by:");
    gotoxy(35,14);
    cprintf("Maulik Ramnani &");
    gotoxy(35,16);
    cprintf("Riya Ramnani");
    gotoxy(30,22);
    cprintf("Press Any key to Continue...");
    gotoxy(2,2);
    getch();
    textbackground(BLACK);
    textcolor(WHITE);
    }
    /* Instruction for the game */

    void Instruction(void)
    {
	 clrscr();
	 fillcolor(3,3,76,23,10,0);
	 rectangle(2,2,78,24,6,6);
	 rectangle(3,2,77,24,6,6);
	 textcolor(WHITE);
	 textbackground(RED);
	gotoxy(23,11);
	cprintf("Use the arrow keys to change direction.");
	gotoxy(23,13);
	cprintf("Press 'Spacebar' to PAUSE and 'Esc' to");
	gotoxy(23,15);
	cprintf("EXIT.");
	gotoxy(27,18);
	cprintf("Press ENTER to continue...");
	gotoxy(2,2);
	getch();
	textcolor(15);
	textbackground(0);
    }
    void rectangle(int x,int y,int l, int b,int bgcolor ,int fgcolor)
    {
    int i,j,k,m;
    textbackground(bgcolor);
    textcolor(fgcolor);
    gotoxy(x,y);
    cprintf("%c",201);
    for(i=x+1;i<=l-1;i++)
    {
    gotoxy(i,y);
    cprintf("%c",205);
    }
    gotoxy(l,y);
    cprintf("%c",187);
    for(j=y+1;j<=b-1;j++)
    {
    gotoxy(l,j);
    cprintf("%c",186);
    }
    gotoxy(l,b);
    cprintf("%c",188);
    for(k=l-1;k>=x+1;k--)
    {
    gotoxy(k,b);
    cprintf("%c",205);
    }
    gotoxy(x,b);
    cprintf("%c",200);
    for(m=b-1;m>=y+1;m--)
    {
    gotoxy(x,m);
    cprintf("%c",186);
    }
    }


    void rectangle1(int x,int y,int l, int b,int bgcolor ,int fgcolor)
    {
    int i,j,k,m;
    textbackground(bgcolor);
    textcolor(fgcolor);
    gotoxy(x,y);
    cprintf("%c",218);
    for(i=x+1;i<=l-1;i++)
    {
    gotoxy(i,y);
    cprintf("%c",196);
    }
    gotoxy(l,y);
    cprintf("%c",191);
    for(j=y+1;j<=b-1;j++)
    {
    gotoxy(l,j);
    cprintf("%c",179);
    }
    gotoxy(l,b);
    cprintf("%c",217);
    for(k=l-1;k>=x+1;k--)
    {
    gotoxy(k,b);
    cprintf("%c",196);
    }
    gotoxy(x,b);
    cprintf("%c",192);
    for(m=b-1;m>=y+1;m--)
    {
    gotoxy(x,m);
    cprintf("%c",179);
    }
    }



    void fillcolor(int x1, int y1,int x2,int y2,int color1,int color2)
    {
    int i,j;
    textbackground(color1);
    textcolor(color2);
    for(i=x1;i<=x2;i++)
    {
    for(j=y1;j<=y2;j++)
    {
    gotoxy(i,j);
    cprintf("±");
    }
    }
    }
