#include <iostream>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include <sstream>
#include <fstream>
#include <ctime>
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void greentext(){SetConsoleTextAttribute(hConsole, 2);  };
void whitetext(){SetConsoleTextAttribute(hConsole, 15);  };
void redtext (){SetConsoleTextAttribute(hConsole,  4);  };
void bluetext (){SetConsoleTextAttribute(hConsole, 11);  };
void yellowtext (){SetConsoleTextAttribute(hConsole, 14);  };
void darktext (){SetConsoleTextAttribute(hConsole, 8);  };

bool MenuLoop = true;
string name ("*****");    
string surname ("*****");
int address1 (00);
string address2 ("*****");
string address3 ("*****");
string address4 ("*****");
string postcode ("*****");
string tel ("00");
int membershipSelection;
string membershipType("*****");
string creditcard("****"); 

void resetMemberDetails(){
    name =     "*****";
     surname =  "*****";
     address1 = 00;
     address2 = "*****";
     address3 = "*****";
     address4 = "*****";
     postcode = "*****";
     tel = "00";
     creditcard = "****";
     membershipType   = "*****";
}
void MemberForm(){
 
    system ("cls");
    bluetext();
    cout << "\t\t\t      Member Details\n";
    whitetext();
    cout << "\t________________________________________________________________\n\n";
    cout << "\tMember Form   \t";
    cout << "\t  Member: ";
    if (name != "*****"){greentext();};   // If the field is not the default
    cout << name << " ";                  // value use green text, then
    whitetext();                          // revert back to white text.
    if (surname != "*****"){greentext();};
    cout << surname << "\n";
    whitetext();
    cout << "\t\t\t";
    cout << "\t Address: ";
    if (address1 != 00){greentext();};
    cout << address1 << " ";
    whitetext();
    if (address2 != "*****"){greentext();};
    cout << address2 << "\n";
    whitetext();
    cout << "\t\t";
    cout << "\t\t          ";
    if (address3 != "*****"){greentext();};
    cout << address3 << "\n";
    whitetext();
    cout << "\t\t\t\t          ";
    if (address4 != "*****"){greentext();};
    cout << address4 << "\n";
    whitetext();
    cout << "\t\t\t\t          ";
    if (postcode != "*****"){greentext();};
    cout << postcode << "\n";
    whitetext();
    cout << "\t\t\t   Telephone: ";
    if (tel != "00"){greentext();};
    cout << tel;
    whitetext();
    cout << "\n";
    cout << "\t________________________________________________________________\n\n";
    cout << "\t\t           Credit card: ";
    if (creditcard != "****"){greentext();};
    cout << creditcard;
    whitetext();
    cout << "\n\t\t         Membership Type: ";
    if (membershipType != "*****"){greentext();};
    cout << membershipType;
    whitetext();
    
    whitetext();
    cout << "\n\t________________________________________________________________\n\n";
    cout << "\n";
};
 void savefile(){
    string saveFileName;
    stringstream out;
    out << name << " " << surname;
    saveFileName = out.str();
    ofstream myfile;                                  //Save file structure
    myfile.open (saveFileName.c_str(), ios::out);
    myfile << name << "\n";
    myfile << surname << "\n";
    myfile << address1 << "\n";
    myfile << address2 << "\n";
    myfile << address3 << "\n";
    myfile << address4 << "\n";
    myfile << postcode << "\n";
    myfile << tel<< "\n";
    myfile << creditcard << "\n";
    myfile << membershipType << "\n";
    
    myfile.close();
    MemberForm();
    greentext();
    cout << "\tDetails have been saved\n\n\t";
    whitetext();
    system ("pause");
    }
    // Main Menu choice 1
void memberDetails(){
 
    char saveYN;
 
    MemberForm();
    cout << "\tPlease enter customers first name: ";
    cin >> ws;
    getline (cin, name);
    MemberForm();
    cout << "\tPlease enter customers surname: ";
    cin >> surname;
    MemberForm();
    cout << "\tPlease enter customers house number: ";
    cin >> address1;
                while (cin.fail()||  address1 < 1)  // Checks for invalid entry.
    {cin.clear(); cin.ignore();
    cout << "\n\tPlease enter a valid house number: "; cin >> address1;}
    MemberForm();
    cout << "\tPlease enter customers street: ";
    cin >> ws;                        // Allows the user to enter more than one word
    getline (cin, address2);          // in a string by allowing white spaces.
    MemberForm();
    cout << "\tPlease enter customer area: ";
    getline (cin, address3);
    MemberForm();
    cout << "\tPlease enter customer city: ";
    getline (cin, address4);
    MemberForm();
    cout << "\tPlease enter customer postcode: ";
    cin >> ws;
    getline (cin, postcode);
    MemberForm();
    cout << "\tPlease enter Daytime Telephone Number: ";
    //cin >> ws;
    getline (cin, tel);
    while (cin.fail()){ //Handles character in integer variable
        cin.clear();
        cin.ignore();
        cout << "\tPlease enter Daytime Telephone Number: ";
        cin >> tel;
    };
    MemberForm();
    cout << "\tPlease enter Evening Telephone Number: ";
    //cin >> ws;
    MemberForm();
    cout << "\tCould you have credit card? <Yes/No>";
    cin >> creditcard;
    MemberForm();
    cout << "\tPlease enter membership type:\n\t1 - GSB\n\t2 - KTB\n\t3 - SCB\n\t> : ";
    cin >> membershipSelection;
    switch (membershipSelection){
    case 1 :
        membershipType = "GSB";
        break;
    case 2 :
        membershipType = "KTB";
        break;
    case 3 :
        membershipType = "SCB";
        break;
    //default :
 
    };
    MemberForm();
    
    cout << "\tSave these details to a file? <Y/N> ";
 
    //Confirmation before saving a file
    cin >> saveYN;
    if (saveYN == 'y' || saveYN == 'Y'){
        savefile();
    };
};
void createBooking(){}
void billpayment(){}
void priceList(){}
void help(){}
void exit(){}
void mainMenu(){
 
    // Private variable used for menu selection
    int menuchoice;
 
    system ("cls");
 
    resetMemberDetails();
    bluetext();
    cout << "\t\t\t\tMain Menu\n\n";
    whitetext();
    cout << "\t\t1 - Add a new member\n\n";
    cout << "\t\t2 - View price list\n\n";
    cout << "\t\t3 - Create a new booking\n\n";
    cout << "\t\t4 - bill payment\n\n";
    cout << "\t\t5 - Help\n\n";
    cout << "\t\t6 - Exit\n\n\n";
    cout << "\t\t\tPlease choose an option: ";
    cin >> menuchoice;
 
    //Prevents a character entry from crashing the program
    while (cin.fail())
        {cin.clear();
        cin.ignore();
        cout << "\n\t\tPlease enter a valid number:"; cin >> menuchoice;
    };
 
    // Switch statement for menu selection
    switch (menuchoice){
 
        // Enter new member function
        case 1 :
            memberDetails();
            break;
        case 2 :
            createBooking();
            break;
 
        case 3 :
            billpayment();
            break;
 
        case 4 :
            priceList();
            break;
 
        case 5 :
            help();
            break;
 
        case 6 :
            exit();
            break;
 
        default:
            cout << "\n\tPlease enter a correct menu choice\n\n\t";
            system ("pause");
    };
};

void welcome(){
    bluetext();
    cout << "\n\n\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout <<       "\t\t\t@  ***********************************  @\n";
    cout <<       "\t\t\t@  *                                 *  @\n";
    cout <<       "\t\t\t@  *           WELCOME to            *  @\n";
    cout <<       "\t\t\t@  *         La-lune-hotel           *  @\n";
    cout <<       "\t\t\t@  *                                 *  @\n";
    cout <<       "\t\t\t@  ***********************************  @\n";
    cout <<       "\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    whitetext();
    cout <<       "\n\n\t\t\t\t>";
    cout << "   Main menu \n";
    greentext();
    cout << "\t\t      press enter in order to approach Main menu... ";
    cin.get(); 
}
int main(){
    welcome();
     while (MenuLoop == true){mainMenu();};      //Main menu loop
    return 0;
}

