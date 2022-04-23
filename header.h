#define MAX_NAME_LENGTH 50
#define MAX_BIRTHDATE_LENGTH 20
#define MAX_SEX_LENGTH 10
#define MAX_PASSPORTNUMBER_LENGTH 30
#define MAX_FROM_LENGTH 25
#define MAX_TO_LENGTH 25
#define SEATS 100


void menu();
void profile();
 void printTicket(int seat_num,int classPrice );
 unsigned int price(int flightClassRow);
  void int_seats(char array[SEATS],int elements);
  void seat_map(char seats[SEATS]);
  unsigned int count_seats(char seats[SEATS]);
  unsigned int count_economy(char seats[30]);
