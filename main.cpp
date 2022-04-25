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
     char section[SEATS]={0}, response;
     int classPrice;
     unsigned int seat_num = 0,seats_available=0,first_class = 0;

     // intialize seats 
     int_seats(section,SEATS);
do{
startMenu:
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
                    cout<<"\n\t\t\t There are "<<seats_available<<" seats available,"
                    <<" Please select your seat"<<endl;
                    seat_map(section);
               }

                     first_class = count_first_class(section);
                    cout<<"\t\t\tThere are "<<first_class<<" first class seats"<<endl;
                    cout<<"\t\t\tThere are "<<seats_available - first_class<<" economy class seats"<<endl;
                    cout<<"\n\t\t\tEnter the row and seat number: ";

                    seat_choice:
                    response ='y';
                    cin>>seat_num;
                           if ((seat_num >0 && seat_num <= 30) && first_class == 0){
                                cout<<"\t\t\tFirst class seats are already full. Would you like to have an economy class?(y/n): ";
                            cin>>response;
                            if(response == 'y'){
                                cout<<"\n\t\t\tPlease enter seat numbers from 31 - 100: ";
                                goto seat_choice;
                            }
                            else{
                                    cout<<"\n\t\t\tHave a happy day!";
                                goto startMenu;
                            }
                    }


                    if(section[seat_num-1] =='o')
                    {
                         section[seat_num-1] = 'x';
                         seats_available--;
                         classPrice=price(seat_num);
                    printTicket(seat_num,classPrice);

                    }
                    else
                    {    system("cls");
                    cout<<"\t\t\t**************************************"<<endl;
                           cout<<"\t\t\t\t\tSORRY!\n"
                            <<"\t\t\tTHAT SEAT IS TAKEN PICKE A DIFFERENT SEAT."<<endl;
                           cout<<"\t\t\tSeats 1-30 are for First Class.\n";
                           cout<<"\t\t\tROW 31-100  are for Economy Class.\n";
                   cout<<"\t\t\t**************************************"<<endl;
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


