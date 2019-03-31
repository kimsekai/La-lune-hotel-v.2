#include <iostream>
#include <windows.h>
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void greentext(){SetConsoleTextAttribute(hConsole, 2);  };
void whitetext(){SetConsoleTextAttribute(hConsole, 15);  };
void redtext (){SetConsoleTextAttribute(hConsole,  4);  };
void bluetext (){SetConsoleTextAttribute(hConsole, 11);  };
void yellowtext (){SetConsoleTextAttribute(hConsole, 14);  };
void darktext (){SetConsoleTextAttribute(hConsole, 8);  };

string name ("*****");    //Strings have default values so that the form can
string surname ("*****"); //be displayed with incomplete fields.
int address1 (00);
string address2 ("*****");
string address3 ("*****");
string address4 ("*****");
string postcode ("*****");
string telDay ("00");
string telEve("00");
int startDate(00);
int startMonth (00);
int startYear(00);
int endDate(00);
int endMonth(00);
int endYear(00);
int membershipNumber(00);
int membershipSelection;
string membershipType("*****");
string memberNotes("*****");
 
// Global activity variables
string typeofRoom ("*****");
int activityDate(00);
int activityMonth(00);
int activityYear(00);
double activityPrice(0.00);
 
void bookingForm(){
    system ("cls");
    bluetext();
    cout << "\t\t\t      Booking Details\n";
    whitetext();
    cout << "\t________________________________________________________________\n\n";
    cout << "\tBooking Form   \t";
    cout << "\t  Member: ";
    if (name != "*****"){greentext();};   // If the field is not the default
    cout << name << " ";                  // value use green text, then
    whitetext();                          // revert back to white text.
    if (surname != "*****"){greentext();};
    cout << surname << "\n";
    whitetext();
    cout << "\n\t\t         Membership Type: ";
    if (membershipType != "*****"){greentext();};
    cout << membershipType;
    whitetext();
    cout << "\n\t\t                Activity: ";
    if (typeofRoom != "*****"){greentext();};
    cout << typeofRoom;
    whitetext();
        cout << "\n\t\t           Activity Date: ";
    if (activityDate != 00){greentext();};
    cout << activityDate << "/" << activityMonth << "/" << activityYear;
    whitetext();
        cout << "\n\t\t          Activity Price: ";
    if (activityPrice != 00.00){greentext();};
    cout << activityPrice;
    whitetext();
    cout << "\n\t________________________________________________________________\n\n";
    cout << "\n";
};