#include<iostream>
#include<iomanip>
#include <ctime>

using namespace std;
#define MAX_NAME_LENGTH 50
#define MAX_BIRTHDATE_LENGTH 20
#define MAX_SEX_LENGTH 10
#define MAX_PASSPORTNUMBER_LENGTH 30
#define MAX_FROM_LENGTH 25
#define MAX_TO_LENGTH 25
#define ROWS 10
#define COLUMNS 10

   // GLOBAL VARIABLES
 char fullname[MAX_NAME_LENGTH];
 char birthdate[MAX_BIRTHDATE_LENGTH];
 char sex[MAX_SEX_LENGTH];
 char passportNumber[MAX_PASSPORTNUMBER_LENGTH];
 char answer;

  // FUNCTION DECLARATION
  void menu();
  void profile();
  void printTicket(int rowNumber,int seatNumber, int classPrice );
 unsigned int price(int flightClassRow);
  void int_seats(char array[][COLUMNS],int elements);
  void seat_map(char seats[ROWS][COLUMNS]);
  unsigned int count_seats(char seats[ROWS][COLUMNS]);



   int main()
   {
     char section[ROWS][COLUMNS]={0};
     int classPrice;
     unsigned int row=0,seat=0,seats_available=0;

     // intialize seats with random values of 'x' or 'o'
     int_seats(section,ROWS);
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
               cout<<"\t\t\tROW 1 - 3  are for First Class.\n";
               cout<<"\t\t\tROW 4 - 10  are for Economy Class.\n";
               
               if(seats_available==0)
               {
                    cout<<"\t\t\tsorry. this flight is full."<<endl;
                    cout<<"\t\t\tNext flight leaves in 3 hours." << endl;

               }
               else
               {     seatMap:
                    cout<<"\n\t\t\tThere are "<<seats_available<<" seats available,"
                    <<" Pleas select your seat"<<endl;
                    seat_map(section);
               }
                    cout<<"\n\t\t\tEnter the row and seat number: ";
                    cin>>row>>seat;
                    cin.ignore(100,'\n');

                    if(section[row-1][seat -1]=='o')
                    {
                         section[row-1][seat -1] = 'x';
                         seats_available--;
                         classPrice=price(row);
                    printTicket(row,seat,classPrice);
                         
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


void menu()
   {
     system("cls");
    cout <<"\n\n\t\t\t\t=== === === === === \n";
    cout<<"\t\t\t\t||  STAR AIRLINE  ||\n";
    cout <<"\t\t\t\t=== === === === === \n";
    

    cout<<"\n\n\t\t\twelcome to Star Airline online ticket service."<<endl;
    cout<<"\t\t\t----------------------------------------------\n";
    cout<<"\t\t\t[1] book a ticket\n";
    cout<<"\t\t\t[2] for Exit..";
    return;
    }



 void profile()
  {    
    system("cls");
    cout <<"\n\n\t\t\t\t=== === === === === \n";
    cout<<"\t\t\t\t||  STAR AIRLINE  ||\n";
    cout <<"\t\t\t\t=== === === === === \n\n";
        
      cin.ignore();
        
        cout<<"\t\t\tpleas enter your full name: ";
        cin.getline(fullname,MAX_NAME_LENGTH);

        cout<<"\t\t\tpleas enter your birthdate D/M/Y: ";
        cin.getline(birthdate,MAX_BIRTHDATE_LENGTH);

        cout<<"\t\t\tpleas enter sex: ";
        cin.getline(sex,MAX_SEX_LENGTH);

        cout<<"\t\t\tpleas enter your passportNumber: ";
        cin.getline(passportNumber,MAX_PASSPORTNUMBER_LENGTH);

      return;
  }


 unsigned int count_seats(char seats[ROWS][COLUMNS])
 {
    unsigned int seat_count = 0;
    for(int i=0; i<ROWS; i++)
   {
        for(int j=0; j<COLUMNS; j++)
       {
            if(seats[i][j] == 'o')
           {
              seat_count++;
           }
       }
   }
    return seat_count;
 }


 void seat_map(char seats[ROWS][COLUMNS])
 {
    unsigned int i,j;
    cout<<"\t\t\tSeat Map\n"<<endl<<endl;

    cout<<"\t\t\tSeat  ";
    for(j=0;j<COLUMNS;j++)
   {
        if(j==5)
         { 
            cout<<"  ";
         }
        cout<<setw(2)<<j+1;
    }
    cout<<endl<<endl;
    for(i=0;i<ROWS;i++)
     {
        if(i==3)
          { cout<<"\n";}
        cout<<"\t\t\tRow";
        cout<<setw(1)<<i+1;
         
        cout<<"  ";
        for(j=0;j<COLUMNS;j++)
       {
          if(j==5)
           { 
              cout<<"  ";
           }

          cout<<setw(2)<<seats[i][j];
       }
        cout<<endl;
     }

    return;
 }


  void int_seats(char array[][COLUMNS],int elements)
 {
    for(int i=0; i< elements;i++) 
   {
       for(int j=0; j<COLUMNS; j++)
       {
           if(rand()%2 ==0 )
           {
              array[i][j] ='o';
           }
           else
           {
              array[i][j] ='o';
           }
       }
   }
    return;
  }



 void printTicket(int rowNumber,int seatNumber, int classCost )
 {
     system("cls");
     int totalPrice;
     char tripType;
     string className;

     className=(rowNumber <= 3 ? "First Class" :"Economy Class") ;

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
   cout<<"\t\t\tSeat Number    : "<<"R"<<rowNumber<<","<<"C"<<seatNumber<<endl;
   cout<<"\t\t\tclass          : "<<className<<endl;
   cout<<"\t\t\tTripType       : "<<tripType<<" Way Trip"<<endl;
   cout<<"\t\t\tPrice          : "<<totalPrice<<endl;
   cout<<"\n\t\t\tHave a nive trip :) \n";

    return;
 }
 

 unsigned int price(int flightClassRow)
 {
   int price;

     if(flightClassRow <= 3)
     {
       price =7500;
     }
     else
     {
       price=5000;
     }
     return price;
 }

 

 


