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

string membershipType("*****");

 
// Global activity variables
string Servicecharges1 ("*****");
string Servicecharges2 ("*****");
string Servicecharges3 ("*****");
string Servicecharges4 ("*****");
int checkinDate(00);
int checkinMonth(00);
int checkinYear(00);
int checkoutDate(00);
int checkoutMonth(00);
int checkoutYear(00);
double TotalPrice(0.00);
double TotalServicecharges(0.00);
string extraservices("*****");
string creditcard("****"); 
 
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
    cout << "\n\t\t         Extra services: ";
    if (extraservices != "*****"){greentext();};
    cout << extraservices;
    whitetext();
    cout << "\n\t\t                Service charges: ";
    if (Servicecharges1 != "*****"){greentext();};
    cout << Servicecharges1;
    if (Servicecharges2 != "*****"){greentext();};
    cout <<"\n\t\t                                 "<<Servicecharges2;
    if (Servicecharges3 != "*****"){greentext();};
    cout <<"\n\t\t                                 "<<Servicecharges3;
    if (Servicecharges4 != "*****"){greentext();};
    cout <<"\n\t\t                                 "<<Servicecharges4;
    whitetext();
        cout << "\n\t\t          Total Service charges: ";
    if (TotalServicecharges != 00.00){greentext();};
    cout << TotalServicecharges;
    whitetext();
        cout << "\n\t\t           Check in Date: ";
    if (checkinDate != 00){greentext();};
    cout << checkinDate << "/" << checkinMonth << "/" << checkinYear;
    whitetext();
        cout << "\n\t\t           Check out Date: ";
    if (checkoutDate != 00){greentext();};
    cout << checkoutDate << "/" << checkoutMonth << "/" << checkoutYear;
    whitetext();
        cout << "\n\t\t          Total Price: ";
    if (TotalPrice != 00.00){greentext();};
    cout << TotalPrice;
    whitetext();
    cout << "\n\t________________________________________________________________\n\n";
    cout << "\n";
};
void bookingScript(){
    bookingForm();
    cout << "\tDo you want extra service?<Yes/No> ";
    cin >>extraservices;
}
int main(){
    bookingScript();
}