#include <iostream>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include <sstream>
#include <fstream>
#include <ctime>
using namespace std;
 
// Changes colour of text
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int greentext(){SetConsoleTextAttribute(hConsole, 2);  };
int whitetext(){SetConsoleTextAttribute(hConsole, 15);  };
int redtext (){SetConsoleTextAttribute(hConsole,  4);  };
int bluetext (){SetConsoleTextAttribute(hConsole, 11);  };
int yellowtext (){SetConsoleTextAttribute(hConsole, 14);  };
int darktext (){SetConsoleTextAttribute(hConsole, 8);  };
 
// Global Variables that need to be accessible throughout the different functions
 
bool MenuLoop = true;
string name ("*****");    
string surname ("*****");
int address1 (00);
string address2 ("*****");
string address3 ("*****");
string address4 ("*****");
string postcode ("*****");
string tel ("00");
int creditcardSelection;
string creditcardType("*****");
string creditcard("****"); 
 
// Global activity variables
string activity ("*****");
int activityDate(00);
int activityMonth(00);
int activityYear(00);
double activityPrice(0.00);
 
//Activity Prices
double sportsHall = 30.00;
double sauna = 3.00;
double swimmingPool = 3.50;
double fitnessSuite = 4.50;
double fitnessClassBeginner = 5.50;
double fitnessClassAdvanced = 7.00;
double badminton = 10.00;
double fiveASide = 35.00;
 
// Resets variables to default values
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
     creditcardType   = "*****";
 
     activity = "*****";
     activityDate = 00;
     activityMonth = 00;
     activityYear = 00;
     activityPrice = 00;
};
 
// Booking form that displays booking variables
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
    if (creditcardType != "*****"){greentext();};
    cout << creditcardType;
    whitetext();
    cout << "\n\t\t                Activity: ";
    if (activity != "*****"){greentext();};
    cout << activity;
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
 
// Booking function that saves booking details to a file
void bookingScript(){
double discount;
int activityChoice;
char confirmationSave;
 
    if (creditcardType == "GSB"){
        discount = 0.9;
    };
    if (creditcardType == "KTB"){
        discount = 0.85;
    };
    if (creditcardType == "SCB"){
        discount = 0.6;
    };
    if (creditcardType == "No"){
        discount = 1.0;
    };
 
 
    bookingForm();
    cout << "Please select an activity:\n\n";
    cout << "1 - Sports Hall\n";
    cout << "2 - Sauna\n";
    cout << "3 - Swimming Pool\n";
    cout << "4 - Fitness Suite\n";
    cout << "5 - Fitness Class (Beginner)\n";
    cout << "6 - Fitness Class (Advanced)\n";
    cout << "7 - Badminton\n";
    cout << "8 - Five a Side Football\n>";
    cin >> activityChoice;
 
    // Price Calculations for members
    if (activityChoice == 1){activity = "Sports Hall"; activityPrice = sportsHall * discount;};
    if (activityChoice == 2){activity = "Sauna"; activityPrice = sauna * discount;};
    if (activityChoice == 3){activity = "Swimming Pool"; activityPrice = swimmingPool * discount;};
    if (activityChoice == 4){activity = "Fitness Suite"; activityPrice = fitnessSuite * discount;};
    if (activityChoice == 5){activity = "Fitness Class (Beginner)"; activityPrice = fitnessClassBeginner * discount;};
    if (activityChoice == 6){activity = "Fitness Class (Advanced)"; activityPrice = fitnessClassAdvanced * discount;};
    if (activityChoice == 7){activity = "Badminton"; activityPrice = badminton * discount;};
    if (activityChoice == 8){activity = "Five a Side Football"; activityPrice = fiveASide * discount;};
 
    // Free activity's for silver and gold members
    if (activityChoice == 3 && creditcardType == "GSB"){activityPrice = 0;};
    if (activityChoice == 3 && creditcardType == "KTB"){activityPrice = 0;};
    if (activityChoice == 2 && creditcardType == "SCB"){activityPrice = 0;};
 
    bookingForm();
 
        cout << "\tPlease enter Booking Date(DD): ";
    cin >> activityDate;
    while (cin.fail() ||   activityDate > 31 || activityDate < 1){//Catches invalid date
        cin.clear(); cin.ignore();
        cout << "\n\tPlease enter a valid date (1-31): ";
        cin >> activityDate;
    };
    bookingForm();
    cout << "\tPlease enter Booking Month(MM): ";
    cin >> activityMonth;
    while (cin.fail() || activityMonth > 12 || activityMonth < 1){//Catches invalid month
        cin.clear(); cin.ignore();
        cout << "\n\tPlease enter a valid month (1-12): ";
        cin >> activityMonth;}
    bookingForm();
    cout << "\tPlease enter Booking Year(YY): ";
    cin >> activityYear;
    while (cin.fail() || activityYear > 99 || activityYear < 1){//Catches invalid year
        cin.clear(); cin.ignore();
        cout << "\n\tPlease enter a valid Year (1-99): ";
        cin >> activityYear;}
    bookingForm();
 
    cout << "Is this information correct? <Y/N>";
    cin >> confirmationSave;
    if (confirmationSave == 'y' || confirmationSave == 'Y') {

    string saveBookingName;
    stringstream out;
    out << name << " " << surname << ".booking";
    saveBookingName = out.str();
 
    ofstream myfile;                                  //Save file structure
    myfile.open (saveBookingName.c_str(), ios::out);
    myfile << name << "\n";
    myfile << surname << "\n";
    myfile << creditcardType << "\n";
    myfile << activity << "\n";
    myfile << activityDate << "\n";
    myfile << activityMonth << "\n";
    myfile << activityYear << "\n";
    myfile << activityPrice;
    myfile.close();
    bookingForm();
    greentext();
    cout << "\tBooking have been saved\n\n\t";
    whitetext();
    };
    system ("pause");
};
 
// Membership Form that displays membership variables
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
    cout << "\n\t\t         Credit card Type: ";
    if(creditcard == "No"){
        greentext();
        creditcardType = "No";
    }
    cout << creditcardType;
    whitetext();
    cout << "\n\t________________________________________________________________\n\n";
    cout << "\n";
};
 
// Save function for saving member details to a file
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
    myfile << creditcardType << "\n";
    
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
    cout << "\tPlease enter Telephone Number: ";
    //cin >> ws;
    getline (cin, tel);
    while (cin.fail()){ //Handles character in integer variable
        cin.clear();
        cin.ignore();
        cout << "\tPlease enter Telephone Number: ";
        cin >> tel;
    };
    MemberForm();
    cout << "\tCould you have credit card? <Yes/No>";
    cin >> creditcard;
    MemberForm();
    if(creditcard == "Yes"){
        cout << "\tPlease enter Credit card Type:\n\t1 - GSB\n\t2 - KTB\n\t3 - SCB\n\t> : ";
        cin >> creditcardSelection;
        switch (creditcardSelection){
            case 1 :
                creditcardType = "GSB";
                break;
            case 2 :
                creditcardType = "KTB";
                break;
            case 3 :
                creditcardType = "SCB";
                break;
        }
    }   
    
    MemberForm();
    
    cout << "\tSave these details to a file? <Y/N> ";
 
    //Confirmation before saving a file
    cin >> saveYN;
    if (saveYN == 'y' || saveYN == 'Y'){
        savefile();
    };
};
 
// Main Menu choice 2
void createBooking(){
 
    char confirm;
    system ("cls");
    char filebooking [100];
    ifstream file_ptr;
    cout << "\n\t\t\t\tCreate a Booking\n\n";
    system ("dir/b *.");
    cout << "\n\n\tPlease type the name of the member you\n";
    cout << "\twish to create a booking for as it appears above OR\n";
    cout << "\ttype z (Lower case) to return to main menu: ";
    cin.ignore();
    gets (filebooking);
    if (filebooking[0]  != 'z'){
 
    file_ptr.open(filebooking,ios::in);
   // char in_char;
    while(!file_ptr)
        {
        cout << "Member does not exist\n";
        gets (filebooking);
        file_ptr.open(filebooking,ios::in);
        }
        getline(file_ptr, name);
        getline(file_ptr, surname);
        file_ptr >> address1;
        getline(file_ptr, address2); // Duplicate required to eliminate
        getline(file_ptr, address2); // empty field bug when using string after integer.
        getline(file_ptr, address3);
        getline(file_ptr, address4);
        getline(file_ptr, postcode);
        getline(file_ptr, tel);
        getline(file_ptr, creditcardType); // Duplicate required to eliminate
        getline(file_ptr, creditcardType); // empty field bug when using string after integer.
 

        MemberForm();
 
        greentext();
        whitetext();
 
        file_ptr.close();
 
    cout << "\n\tCreate booking for this member? <Y/N>";
    cin >> confirm;
    if (confirm == 'y' || confirm == 'Y'){
 
        bookingScript();
        };
    };
};
 
// Main Menu choice 3
void openFile(){
 
 
    // Allows user to select the option of opening a booking file or a member file
    system ("cls");
    int fileMenuChoice;
    cout << "\t\tOpen a File\n\n";
    cout << "1 - Open a Member File\n\n";
    cout << "2 - Open a Booking File\n\n";
    cout << "Please select a file type to open:";
    cin >> fileMenuChoice;
 
    // Menu Option to open Member File
    if (fileMenuChoice == 1)
        {
    cout << "Open Member File";
    system ("cls");
    char filename [100];
    ifstream file_ptr;
    cout << "\n\t\t\t\tSaved Members:\n\n";
    system ("dir/b *.");
    cout << "\n\nPlease type the name of the member you\n";
    cout << "     wish to open as it appears above OR\n";
    cout << "     type z (Lower case) to return to main menu: ";
    cin.ignore();
    gets (filename);
    if (filename[0]  != 'z'){
 
    file_ptr.open(filename,ios::in);
   // char in_char;
    while(!file_ptr)
        {
        cout << "Member does not exist\n";
        gets (filename);
        file_ptr.open(filename,ios::in);
        }
        getline(file_ptr, name);
        getline(file_ptr, surname);
        file_ptr >> address1;
        getline(file_ptr, address2); // Duplicate required to eliminate
        getline(file_ptr, address2); // empty field bug when using string after integer.
        getline(file_ptr, address3);
        getline(file_ptr, address4);
        getline(file_ptr, postcode);
        getline(file_ptr, tel);
        getline(file_ptr, creditcardType); // Duplicate required to eliminate
        getline(file_ptr, creditcardType); // empty field bug when using string after integer.
        MemberForm();
        greentext();
        whitetext();
        file_ptr.close();
        system ("pause");
        };
    };
 
    // Menu Option to open Booking File
 
    if (fileMenuChoice == 2){
    {
    cout << "Open Booking File";
    system ("cls");
    char filename [100];
    ifstream file_ptr;
    cout << "\n\t\t\t\tSaved Bookings:\n\n";
    system ("dir/b *.booking");
    cout << "\n\nPlease type the name of the booking you\n";
    cout << "     wish to open as it appears above OR\n";
    cout << "     type z (Lower case) to return to main menu: ";
    cin.ignore();
    gets (filename);
    if (filename[0]  != 'z'){
 
    file_ptr.open(filename,ios::in);
   // char in_char;
    while(!file_ptr)
        {
        cout << "Member does not exist\n";
        gets (filename);
        file_ptr.open(filename,ios::in);
        }
        getline(file_ptr, name);
        getline(file_ptr, surname);
 
        getline(file_ptr, creditcardType); // Duplicate required to eliminate
        //getline(file_ptr, creditcardType); // empty field bug when using string after integer.
        getline(file_ptr, activity);
        file_ptr >> activityDate;
        file_ptr >> activityMonth;
        file_ptr >> activityYear;
        file_ptr >> activityPrice;
 
        //getline(file_ptr, activityDate);
        //getline(file_ptr, activityMonth);
        //getline(file_ptr, activityYear);
 
 
        bookingForm();
        greentext();
        whitetext();
 
        file_ptr.close();
        system ("pause");
        };
    };
    };
};
 
// Main Menu choice 4
void priceList(){
system ("cls");
cout << "\t\tPrice List\n\n";
 
    cout << "\t\t\t\tActivities\n\t";
    cout << "\t\t\tNone member  |  Bronze  |  Silver  |  Gold";
    cout << "\n\n\tSports Hall............   \x9c" << sportsHall << "\t        " << sportsHall * 0.9 << "\t   " << sportsHall * 0.85 << "   \t" << sportsHall * 0.6;
    cout << "\n\n\tSauna..................   \x9c" << sauna << "\t        " << sauna * 0.9 << "\t   " << sauna * 0.85 << "\t        " << sauna * 0.6;
    cout << "\n\n\tSwimming Pool..........   \x9c" << swimmingPool << "\t        " << swimmingPool * 0.9 << "\t   " << swimmingPool * 0.85 << "\t" << swimmingPool * 0.6;
    cout << "\n\n\tFitness Suite..........   \x9c" << fitnessSuite << "\t        " << fitnessSuite * 0.9 << "\t   " << fitnessSuite * 0.85 << "\t" << fitnessSuite * 0.6;
    cout << "\n\n\tFitness Class";
    cout << "\n\t    Beginner...........   \x9c" << fitnessClassBeginner << "\t        " << fitnessClassBeginner * 0.9 << "\t   " << fitnessClassBeginner * 0.85 << "\t" << fitnessClassBeginner * 0.6;
    cout << "\n\t    Advanced...........   \x9c" << fitnessClassAdvanced << "\t        " << fitnessClassAdvanced * 0.9 << "\t   " << fitnessClassAdvanced * 0.85 << "\t        " << fitnessClassAdvanced * 0.6;
    cout << "\n\n\tBadminton..............   \x9c" << badminton << "\t        " << badminton * 0.9 << "\t   " << badminton * 0.85 << "\t        " << badminton * 0.6;
    cout << "\n\n\tFive-A-Side Football...   \x9c" << fiveASide << "\t        " << fiveASide * 0.9 << "\t   " << fiveASide * 0.85 << "\t" << fiveASide * 0.6;
    cout << "\n\n\n\t";
 
system ("pause");
};
 
// Main Menu choice 5
void help(){
system ("cls");
cout << "\t\t\t\tHelp\n\n";
 
cout << "To enter a new member into the system, Choose option 1 from the Main Menu.\n";
cout << "Enter the new members details into the membership form and press Y to save once finished.\n\n\n";
 
cout << "To create a booking, select option 2 from the main menu.\n";
cout << "Enter the members name from the list OR enter 'None Member' if the customer is  not a member\n";
cout << "Enter the booking choices and then press Y to save the booking\n\n\n";
 
cout << "To open a member or booking file, choose option 3 at the main menu.\n";
cout << "Select option 1 to open a member file or option 2 to open a booking file\n";
cout << "Type the name of a file as it is displayed on the list to open and view it.\n\n\n";
 
cout << "To view a price list, select option 4 from the main menu.\n\n\n";
 
system ("pause");
};
 
// Main Menu choice 6
void exit(){
    MenuLoop = false;
//system ("cls");
//exit (0);
 
};
 
// Main Menu function
void mainMenu(){
 
    // Private variable used for menu selection
    int menuchoice;
 
    system ("cls");
 
    resetMemberDetails();
 
    cout << "\t\t\t\tMain Menu\n\n";
    cout << "\t\t1 - Add a new member\n\n";
    cout << "\t\t2 - Create a new booking\n\n";
    cout << "\t\t3 - Open a file\n\n";
    cout << "\t\t4 - View price list\n\n";
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
            openFile();
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
 
// Password function
void password(){
 
    string pass;
    int passCount = 0;
 
    cout << "\n\n\n\t\t\t\t******************\n";
    cout <<       "\t\t\t\t**Enter Password**\n";
    cout <<       "\t\t\t\t******************\n";
    cout <<       "\n\n\t\t\t\t>";
    cin  >> pass;                   //Promps user for password
 
    while (pass != "password")
    {
        passCount ++;
        redtext();
        cout << "\t\t\t\tPassword Incorrect!\n";
        if (passCount >= 3)                         //Three failed attemps exits program
        {
                redtext();
                cout << "\n\t\t\t\tLOGIN FAILED!";
                whitetext();
                exit(0);
        };
 
 
        whitetext();
        cout << "\t\t\t\tTry Again:\n\t\t\t\t>";
        cin >> pass;
 
        };
    greentext();
    cout << "\n\t\t\t\tPassword Accepted!\n\t\t\t\tPress any key to continue...";
    whitetext();
    cin.ignore();
    cin.get();
};
 
// Main function
int main()
{
 
    password();                                 //Password Screen
    while (MenuLoop == true){mainMenu();};      //Main menu loop
 
    return 0;
 
}