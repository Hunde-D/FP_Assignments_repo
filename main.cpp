#include<iostream>
#include<iomanip>
#include <ctime>
#include "header.h"
using namespace std;


   // GLOBAL VARIABLES
 char fullname[MAX_NAME_LENGTH];
 char birthdate[MAX_BIRTHDATE_LENGTH];
 char sex[MAX_SEX_LENGTH];
 char passportNumber[MAX_PASSPORTNUMBER_LENGTH];
 char answer;

  // FUNCTION DECLARATION



   int main()
   {
     char section[SEATS]={0};
     int classPrice;
     unsigned int seat_num = 0,seats_available=0;

     // intialize seats with random values of 'x' or 'o'
     int_seats(section,SEATS);
do{

     menu();
    char menuChoice;
   cin>>menuChoice;

         switch(menuChoice)
   {
        case '1':
               profile();

               seats_available = count_seats(section);

               int flightClass;
               system("cls");
               cout<<"\t\t\tpassenger class\n";
               cout<<"\t\t\t----------------\n";
               cout<<"\t\t\tSeats 1 - 30  are for First Class.\n";
               cout<<"\t\t\tSeats 31 - 100  are for Economy Class.\n";

               if(seats_available==0)
               {
                    cout<<"\t\t\tsorry. this flight is full."<<endl;
                    cout<<"\t\t\tNext flight leaves in 3 hours." << endl;

               }
               else
               {     seatMap:
                    cout<<"\n\t\t\tThere are "<<seats_available<<" seats available,"
                    <<" Please select your seat"<<endl;
                    seat_map(section);
               }


                    cout<<"there are "<<count_economy(section)<<" economy seats";
                    cout<<"\n\t\t\tEnter the row and seat number: ";
                    cin>>seat_num;
                    cin.ignore(100,'\n');

                    if(section[seat_num-1] =='o')
                    {
                         section[seat_num-1] = 'x';
                         seats_available--;
                         classPrice=price(seat_num);
                    printTicket(seat_num,classPrice);

                    }
                    else
                    {    system("cls");
                           cout<<"\t\t\t\t\tSORRY!\n"
                            <<"\t\t\tTHAT SEAT IS TAKEN PICKE A DIFFERENT SEAT."<<endl;
                           cout<<"\t\t\tROW 1 - 3  are for First Class.\n";
                           cout<<"\t\t\tROW 4 - 10  are for Economy Class.\n";
                         goto seatMap;
                    }
                    break;


       case '2':
              return 0;
              break;

      default:
          system("cls");
          cout <<"\n\n\t\t\t\t=== === === === === \n";
          cout<<"\t\t\t\t||  STAR AIRLINE  ||\n";
          cout <<"\t\t\t\t=== === === === === \n";
          cout<<"\n\t\t\tERROR! INVALID CHARACTER, TRY AGIN.";

     }

     cout<<"\n\t\t\tContinue? y/n.";
     cin>>answer;

 } while(answer == 'y'||answer == 'Y');

    return 0;


}


