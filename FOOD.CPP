#include <iostream.h>
#include <iomanip.h>
#include<conio.h>


// Function Prototypes
void showMenu();
void showFees(double, int);

int main()
{
clrscr();
    int choice; //To Hold Menu Choice
    double quantity = 1;




    //contants for menu choices
    const int hamburgerChoice = 1;
    const int hotdogChoice = 2;
    const int peanutsChoice = 3;
    const int popcornChoice = 4;
    const int sodaChoice = 5;
    const int chipsChoice = 6;
    const int waterChoice = 7;
    const int endOrderChoice = 8;

    //constants for menu prices
    const double hamburger = 6.00;
    const double hotdog = 4.50;
    const double peanuts = 3.75;
    const double popcorn = 5.50;
    const double soda = 2.80;
    const double chips = 1.00;
    const double water = 2.00;

    //set precision


    do
    {
	//display menu and get user choice
	showMenu();
	cin >> choice;

	//validate choice
	while (choice < hamburgerChoice || choice > endOrderChoice)
	{
	    cout << "Please enter a valid menu choice: ";
	    cin >> choice;
	}

	//if the user does not want to quit proceed
	if (choice != endOrderChoice)
	{

	    //display fees
	    switch (choice)
	    {
		case hamburgerChoice:
		    showFees(hamburger, quantity);
		    break;
		case hotdogChoice:
		    showFees(hotdog, quantity);
		    break;
		case peanutsChoice:
		    showFees(peanuts, quantity);
		    break;
		case popcornChoice:
		    showFees(popcorn, quantity);
		    break;
		case sodaChoice:
		    showFees(soda, quantity);
		    break;
		case chipsChoice:
		    showFees(chips, quantity);
		    break;
		case waterChoice:
		    showFees(water, quantity);
		    break;

	    }
		    }
    }
    while (choice != endOrderChoice);

    return 0;

}
//*************************************************************
//Definition of function showMenu which displays the menu    **
//*************************************************************

void showMenu()
{
    cout << "\n\t\tWelcome To Maulik Game Snacks" << endl;
    cout<<"\n\nMenu Choice\tFood\tPrice\n\n";
    cout << "1.\t Hamburger \t$6.00"<< endl;
    cout << "2.\t Hotdog \t$4.50" << endl;
    cout << "3.\t Peanuts \t$3.75" << endl;
    cout << "4.\t Popcorn \t$5.50" << endl;
    cout << "5.\tSoda \t\t$2.80" << endl;
    cout << "6.\tChips \t\t$1.00"<< endl;
    cout << "7.\tWater \t\t$2.00" << endl;
    cout << "8.\tEND ORDER\n" << endl;
    cout << "Please enter your menu choice: ";
}

//************************************************************
//Definition of function showFees which caculates the total **
//bill                                                      **
//************************************************************

void showFees(double itemCost, int quantity)
{
    double amtTendered;
    double totalBill = (itemCost * quantity);
    double taxRate = .065;
    double tipRate = .20;
    double tip = (totalBill * tipRate);
    double tax = (totalBill * taxRate);
    double amountDue = (totalBill + tax + tip);
    cout << "Total Bill: $" << totalBill << endl;
    cout << "Tax: $" << tax << endl;
    cout << "Tip: $" << tip << endl;
    cout << "Total Amount Due: $" << amountDue << endl;
    cout << "Enter ammount tendered: $";
    cin >> amtTendered;
    double changeDue = amtTendered - amountDue;
    cout << "Change Due: $" << changeDue << endl;
    cout<<"THANK YOU FOR COMING\n";
    cout<<"VISIT AGAIN";
    getch();
}
