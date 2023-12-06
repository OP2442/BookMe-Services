#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
using namespace std;

void welcome()
{
    cout<<"\t\t\t\t+----+----+---+-++--+++----+++--++-+---+----+"<<endl;
    cout<<"\t\t\t\t\tWELCOME TO BRAMPTONAUTOPROS"<<endl;
    cout<<"\t\t\t\t+----+----+---+-++--+++----+++--++-+---+----+"<<endl;
}


void price()
{
    cout<<"\t\t\t\t\t\t--++--=PRICES=--++--\n\n"<<endl;
    cout<<"\t\t\t\t1) Exterior Ceramic Hand Wash----------------->     $70"<<endl;
    cout<<"\t\t\t\t2) Interior Express Detail-------------------->     $50"<<endl;
    cout<<"\t\t\t\t3) Interior Shampoo Detail-------------------->     $250"<<endl;
    cout<<"\t\t\t\t4) Engine Bay Detail-------------------------->     $30"<<endl;
    cout<<"\t\t\t\t5) Interior & Exterior Express Detail--------->     $80"<<endl;
    cout<<"\t\t\t\t6) Interior & Exterior Shampoo Detail--------->     $300"<<endl;
    cout<<"\t\t\t\t7) Paint Correction--------------------------->     ~$300"<<endl;
    cout<<"\t\t\t\t8) Ceramic Coating---------------------------->     $400+"<<endl;

}


void booking()
{
    string Fname,Lname, time, month;
    int jan, feb;
    char service;
    ofstream obj1;

    obj1.open("APPT.txt", ios::out);

    cout<<"Enter First Name"<<endl;
    cin>>Fname;
    cout<<"Enter Last Name"<<endl;
    cin>>Lname;

    obj1<<Fname<<" "<<Lname<<": ";

    entry:
    cout<<"\t\t\t\t\t\t--++--=PRICES=--++--\n\n"<<endl;
    cout<<"\t\t\t\tA) Exterior Ceramic Hand Wash----------------->     $70"<<endl;
    cout<<"\t\t\t\tB) Interior Express Detail-------------------->     $50"<<endl;
    cout<<"\t\t\t\tC) Interior Shampoo Detail-------------------->     $250"<<endl;
    cout<<"\t\t\t\tD) Engine Bay Detail-------------------------->     $30"<<endl;
    cout<<"\t\t\t\tE) Interior & Exterior Express Detail--------->     $80"<<endl;
    cout<<"\t\t\t\tF) Interior & Exterior Shampoo Detail--------->     $300"<<endl;
    cout<<"\t\t\t\tG) Paint Correction--------------------------->     ~$300"<<endl;
    cout<<"\t\t\t\tH) Ceramic Coating---------------------------->     $400+"<<endl;
    cout<<"\nWhat Detailing Service Are You Interested In? (Input the letter)"<<endl;
    cin>>service;

    switch(service)
    {
    case 'a':
    case 'A':
        obj1<<"Exterior Ceramic Hand Wash";
        break;

    case 'b':
    case 'B':
        obj1<<"Interior Express Detail";
        break;

    case 'c':
    case 'C':
        obj1<<"Interior Shampoo Detail";
        break;

    case 'd':
    case 'D':
        obj1<<"Engine Bay Detail";
        break;

    case 'e':
    case 'E':
        obj1<<"Interior & Exterior Express Detail";
        break;

    case 'f':
    case 'F':
        obj1<<"Interior & Exterior Shampoo Detail";
        break;

    case 'g':
    case 'G':
        obj1<<"Paint Correction";
        break;

    case 'h':
    case 'H':
        obj1<<"Ceramic Coating";
        break;

    default:
        cout<<"Invalid Entry, Try Again"<<endl;
        goto entry;
    }

    pick:
    cout<<"What Month Would You Like To Book Your Appt In (Jan or Feb)"<<endl;
    cin>>month;

    if(month == "Feb"|| month == "feb")
    {
        cout<<"Pick Your Date (1-29)"<<endl;
        cin>>feb;

        if(feb<1 || feb>29)
        {
            cout<<"Invalid Entry, Try Again"<<endl;
            goto pick;
        }
    }
    else if (month == "Jan"|| month == "jan")
    {
        cout<<"Pick Your Date (1-31)"<<endl;
        cin>>jan;

        if(jan<1 || jan>31)
        {
            cout<<"Invalid Entry, Try Again"<<endl;
            goto pick;
        }
    }
    else
    {
        cout<<"Invalid Entry, Try Again"<<endl;
        goto pick;
    }

    obj1<<" - "<<month;
    if (month == "Feb" || month == "feb")
    {
        obj1<<" "<<feb;
    }
    else if (month == "Jan"|| month == "jan")
    {
        obj1<<" "<<jan;
    }

    cout<<"What time would you like to book your appointment? (10AM - 7PM in 30 minute increments - Use Colon (:))"<<endl;
    cin>>time;

    cout<<"YOU HAVE NOW BOOKED AN APPOINMENT WITH BRAMPTONAUTOPROS"<<endl;
    system("pause");

    obj1<<" @ "<<time<<endl;
    obj1<<"----------------------------------"<<endl;
}

void review()
{
    ofstream obj;
    double stars;
    string name;
    string in;

    obj.open("Reviews.txt", ios::app);

    cout<<"Thank You For Deciding To Leave A Review"<<endl;
    cout<<"Enter Your First Name: ";
    cin>>name;

    redo:
    cout<<"\nHow Many Stars Would You Like To Rate Our Service (0.5 - 5 stars)"<<endl;
    cin>>stars;

    if (stars<0.5 || stars>5)
    {
        cout<<"invalid Entry"<<endl;
        goto redo;

    }

    cout<<"Would You Like To Tell Us Anything? (Things We Did Good, Areas Of Improvement)"<<endl;
    cin.ignore();
    getline(cin, in);


    obj<<name<<" ";
    obj<<stars<<" Stars"<<endl;
    obj<<"Review: "<<in<<endl;
    obj<<"--------------------"<<endl;


    obj.close();

}


int main()
{
    string name, time, car, jan, feb;
    int a;

    while(a!=4)
    {
    menu:
    welcome();


    cout<<"\n~What Are You Interested In Doing Today~"<<endl;
    cout<<"\n1. Prices"<<endl;
    cout<<"\n2. Booking Appointment"<<endl;
    cout<<"\n3. Leaving A Review"<<endl;
    cout<<"\n4. Exit/Done"<<endl<<endl;

    cin>>a;

    system ("cls");


    switch (a)
   {
        case 1:
            price();
            char choice;
            cout<<"\n\nWould You Now Like To Book An Appointment (Y/N)"<<endl;
            cin>>choice;
            system("cls");
            if (choice=='y'||choice=='Y')
            {
                booking();
                system("cls");
                goto menu;
            }

            else
            {
                system("cls");
                goto menu;
            }

        case 2:
            booking();
            system("cls");
            goto menu;
        case 3:
            review();
            system("cls");
            goto menu;
        case 4:
            cout<<"Thank You For Choosing BramptonAutoPros!"<<endl;
            exit(0);



        }





    return 0;
    }
}
