//include some libraries and header file
#include "header.h"
#include <iostream>
#include<iomanip>
#include <ctime>


using namespace std;

//global variables
#define MAX_NAME_LENGTH 50
#define MAX_BIRTHDATE_LENGTH 20
#define MAX_SEX_LENGTH 10
#define MAX_PASSPORTNUMBER_LENGTH 30
#define MAX_FROM_LENGTH 25
#define MAX_TO_LENGTH 25
#define SEATS 100
#define COLUMNS 10

/*calling external variables
- the extern keyword helps the cpp compiler to understand that the variable
called upon this is from an external c++ module.
*/
 extern char birthdate[MAX_BIRTHDATE_LENGTH];
 extern char sex[MAX_SEX_LENGTH];
 extern char passportNumber[MAX_PASSPORTNUMBER_LENGTH];
 extern char answer;
 extern char fullname[MAX_NAME_LENGTH];

// FUNCTION DEFINITIONS

// THE MENU 
void menu()
   {

     system("cls");
    cout <<"\n\n\t\t\t\t=== === === === === \n";
    cout<<"\t\t\t\t||  STAR AIRLINE  ||\n";
    cout <<"\t\t\t\t=== === === === === \n";

    cout<<"\n\n\t\t\tWelcome to Star Airline online ticket service."<<endl;
    cout<<"\t\t\t----------------------------------------------\n";
    cout<<"\t\t\tPlease reply with\n";
    cout<<"\t\t\t1. To book a ticket\n";
    cout<<"\t\t\t2. To for Exit..";
    return;
    }

// TAKES THE USER INFORMATION
 void profile()
  {

    system("cls");
    cout <<"\n\n\t\t\t\t=== === === === === \n";
    cout<<"\t\t\t\t||  STAR AIRLINE  ||\n";
    cout <<"\t\t\t\t=== === === === === \n\n";

      cin.ignore();

        cout<<"\t\t\tPlease enter your full name: ";
        cin.getline(fullname,MAX_NAME_LENGTH);

        cout<<"\t\t\tPlease enter your birthdate D/M/Y: ";
        cin.getline(birthdate,MAX_BIRTHDATE_LENGTH);

        cout<<"\t\t\tPlease enter sex: ";
        cin.getline(sex,MAX_SEX_LENGTH);

        cout<<"\t\t\tPlease enter your passportNumber: ";
        cin.getline(passportNumber,MAX_PASSPORTNUMBER_LENGTH);

      return;
  }

// COUNTS THE TOTAL SEATS AVAILABLE
 unsigned int count_seats(char seats[SEATS])
 {
    unsigned int seat_count = 0;
    for(int i=0; i<SEATS; i++)
   {

            if(seats[i] == 'o')
           {
              seat_count++;
           }

   }
    return seat_count;
 }

// COUNTS FIRST CLASS SEATS THAT ARE AVAILABLE
 unsigned int count_first_class(char seats[30])
 {
    unsigned int seat_count = 0;
    for(int i=0; i<30; i++)
   {

            if(seats[i] == 'o')
           {
              seat_count++;
           }

   }
    return seat_count;
 }

// PRINTS A MAP OF THE SECTION(SEATS) IN 10X10
 void seat_map(char seats[SEATS])
 {
    unsigned int i,j;
    cout<<"\t\t\tSEAT MAP\n"<<endl<<endl;

    cout<<"\t\t\tSEAT \t";

    for(j=0; j<COLUMNS; j++)
      {
        if(j==5)
         {
            cout<<"  ";
         }
        cout<<setw(4)<<j+1;
      }
    cout<<endl<<endl;

    for(i=0; i<10; i++)
     {
          if(i==3)
            { 
             cout<<"\n";
             }

        cout<<"\t\t\t";
        cout<<setw(2)<<(i)*10 + 1 <<"-"<<(i+1)*10 ;

        cout<<"\t";
          for(j=0; j<COLUMNS; j++)
           {
               if(j==5)
               {
               cout<<"  ";
               }

             cout<<setw(4)<<seats[i*10 + j];
            }
        cout<<endl;
     }
    return;
   }

 //INITIALIZEZ THE SEATS WITH "O". "O" REPRESENTS AVAILABLE AND "X" REPRESENTS SOLD
  void int_seats(char array[SEATS], int elements)
  {
    for(int i=0; i< elements ; i++)
     {
       array[i] ='o';
     }
    return;
  }

//DETERMINES CLASS PRICE
unsigned int price(int flightSeatNumber)
  {
     int price;

     if(flightSeatNumber <= 30)
         {
            price = 7500;
         }
     else
         {
            price = 5000;
         }

     return price;
  }


// PRINT TICKET WITH SOME NECESSARY INFORMATIONS
 void printTicket(int seat_num, int classCost )
 {
     system("cls");
     int totalPrice;
     char tripType;
     string className;

     className=(seat_num <= 30 ? "First Class" :"Economy Class") ;

     new_trip_type:
    cout <<"\n\n\t\t\t\t=== === === === === \n";
    cout<<"\t\t\t\t||  STAR AIRLINE  ||\n";
    cout <<"\t\t\t\t=== === === === === \n\n";
    cout<<"\t\t\tTrip Type\n";
    cout<<"\t\t\t-------------\n";
    cout<<"\t\t\tPleas select trip type: \n";
    cout<<"\t\t\t[1] for one way trip\n";
    cout<<"\t\t\t[2] for two way trip\n";
    cout<<"\t\t\tEnter... ";
    cin>>tripType;

     if( tripType == '1' )
         {
           totalPrice = classCost;
         }

     else
         {
              if ( tripType == '2' )
               {
                  totalPrice = (classCost*2);
               }

              else
               {
                  system("cls");
                  cout<<"\t\t\tINVALID CHARACTER!, TRY AGIN";
                  goto new_trip_type;
               }
         }

    time_t now = time(0);
    char* date_time = ctime(&now);
   
    system("cls");
    cout <<"\n\n\t\t\t\t=== === === === === \n";
    cout<<"\t\t\t\t||  STAR AIRLINE  ||\n";
    cout <<"\t\t\t\t=== === === === === \n\n";
    cout<<"\t\t\t"<<date_time<<endl;
    cout<<"\t\t\tTicket of reservation\n";
    cout<<"\t\t\t------------------------------\n";

    cout<<"\t\t\tFull Name      : "<<fullname<< endl;
    cout<<"\t\t\tBirth Date     : "<<birthdate<< endl;
    cout<<"\t\t\tSex            : "<<sex<< endl;
    cout<<"\t\t\tPassport Number: "<<passportNumber<< endl;
    cout<<"\t\t\tSeat Number    : "<<"SN"<<seat_num<<endl;
    cout<<"\t\t\tclass          : "<<className<<endl;
    cout<<"\t\t\tTripType       : "<<tripType<<" Way Trip"<<endl;
    cout<<"\t\t\tPrice          : "<<totalPrice<<endl;
    cout<<"\n\t\t\tHave a nive trip :) \n";

      return;
   }




