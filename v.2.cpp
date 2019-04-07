#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void greentext(){SetConsoleTextAttribute(hConsole, 2);  };
void whitetext(){SetConsoleTextAttribute(hConsole, 15);  };
void redtext(){SetConsoleTextAttribute(hConsole,  4);  };
void bluetext(){SetConsoleTextAttribute(hConsole, 11);  };
void yellowtext(){SetConsoleTextAttribute(hConsole, 14);  };
void darktext(){SetConsoleTextAttribute(hConsole, 8);  };


string Servicecharges1("*****");
string Servicecharges2("*****");
string Servicecharges3("*****");
string Servicecharges4("*****");
int checkinDate(00);
int checkinMonth(00);
int checkinYear(00);
int checkoutDate(00);
int checkoutMonth(00);
int checkoutYear(00);
double TotalPrice(0.00);
double TotalServicecharges(0.00);
 
bool MenuLoop = true;
string name("*****");    
string surname("*****");
int address1(00);
string address2("*****");
string address3("*****");
string address4("*****");
string postcode("*****");
string tel("00");
int creditcardSelection;
string creditcardType("*****");
string creditcard("****"); 

void resetMemberDetails(){
    name = "*****";
    surname = "*****";
    address1 = 00;
    address2 = "*****";
    address3 = "*****";
    address4 = "*****";
    postcode = "*****";
    tel = "00";
    creditcard = "****";
    creditcardType = "*****";
}

void MemberForm(){
    system ("cls");
    bluetext();
    cout << "\n\t\t\t      Member Details\n";
    whitetext();
    cout << "\t________________________________________________________________\n\n";
    cout << "\tMember Form   \t";
    cout << "\t  Member : ";
    if (name != "*****"){greentext();};   
    cout << name << " ";                  
    whitetext();                          
    if (surname != "*****"){greentext();};
    cout << surname << "\n";
    whitetext();
    cout << "\t\t\t";
    cout << "\t Address : ";
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
    cout << "\t\t\t   Telephone : ";
    if (tel != "00"){greentext();};
    cout << tel;
    whitetext();
    cout << "\n";
    cout << "\t________________________________________________________________\n\n";
    cout << "\t\t           Credit card : ";
    if (creditcard != "****"){greentext();};
    cout << creditcard;
    whitetext();
    cout << "\n\t\t         Credit card Type : ";
    if(creditcard == "No"){
        greentext();
        creditcardType = "No";
    }
    if (creditcardType != "*****"){greentext();};
    cout << creditcardType;
    whitetext();
    cout << "\n\t________________________________________________________________\n\n";
    cout << "\n";
}

void savefile(){
    string saveFileName;
    stringstream out;
    out << name << " " << surname;
    saveFileName = out.str();
    ofstream myfile;                                  
    myfile.open(saveFileName.c_str(), ios::out);
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


 
void bookingForm(){
    system ("cls");
    bluetext();
    cout << "\t\t\t      Booking Details\n";
    whitetext();
    cout << "\t________________________________________________________________\n\n";
    cout << "\tBooking Form   \t";
    cout << "\t  Member: ";
    if (name != "*****"){greentext();};   
    cout << name << " ";                  
    whitetext();                         
    if (surname != "*****"){greentext();};
    cout << surname << "\n";
    whitetext();
    cout << "\n\t\t         Creditcard : ";
    if (creditcard  != "*****"){greentext();};
    cout << creditcard ;
    whitetext();
    cout << "\n\t\t         Creditcard Type: ";
    if (creditcardType  != "*****"){greentext();};
    cout << creditcardType ;
    whitetext();
    cout << "\n\t\t                Service charges: ";
    if (Servicecharges1 != "*****"){greentext();};
    cout << Servicecharges1;
    if (Servicecharges2 != "*****"){greentext();};
    cout <<"\n\t\t                                 " << Servicecharges2;
    if (Servicecharges3 != "*****"){greentext();};
    cout <<"\n\t\t                                 " << Servicecharges3;
    if (Servicecharges4 != "*****"){greentext();};
    cout <<"\n\t\t                                 " << Servicecharges4;
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
void savefile2(){
    string savefilebooking;
    stringstream out;
    out <<name<<" "<< surname;
     savefilebooking = out.str();
    ofstream mybooking;                                  
    mybooking.open(savefilebooking.c_str(), ios::out);
    mybooking << name << "\n";
    mybooking << surname << "\n";
    mybooking << creditcard << "\n";
    mybooking << creditcardType << "\n";
    mybooking << Servicecharges1 << "\n";
    mybooking << Servicecharges2 << "\n";
    mybooking << Servicecharges3 << "\n";
    mybooking << checkinDate << "\n";
    mybooking << checkoutDate << "\n";
    mybooking << TotalPrice << "\n";
    mybooking.close();
    bookingForm();
    greentext();
    cout << "\tDetails have been saved\n\n\t";
    whitetext();
    system ("pause");
}
void bookingScript(){
    string saveYN;
    double discount;
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
    char Parking ;
    double parkingCost ;
    do{
        bookingForm();
        cout << "Enter 'Y' for yes or 'N' for no for the following optional services:\n";
        cout << "Do you want a parking spot during your stay? ";
        cin >> Parking;
        if (Parking == 'Y' || Parking == 'y'){
            parkingCost = 20;
            Servicecharges1 = "a parking spot during your stay = 20";
            TotalServicecharges = parkingCost;
            break;
        }
        else if (Parking == 'N' || Parking == 'n'){
            parkingCost = 0;
            Servicecharges1 ="a parking spot during your stay = - ";
            TotalServicecharges = 0;
            break;
        }
        else{
            cout << "You entered an invalid answer. Please enter 'Y' for yes or 'N' for no.\n";
        }
    }while (Parking != 'Y' && Parking != 'y' && Parking != 'N' && Parking != 'n');
    char internet;
    double internetCost ;
    do{
        bookingForm();
        cout << "Enter 'Y' for yes or 'N' for no for the following optional services:\n";
        cout << "Do you want a parking spot during your stay? "<<Parking<<"\n";
        cout << "Do you want a high speed internet during your stay? ";
        cin >> internet;
        if (internet == 'Y' || internet == 'y'){
            internetCost = 50;
            Servicecharges2 = "high speed internet = 50";
            if(TotalServicecharges = parkingCost){
                TotalServicecharges = parkingCost+internetCost;
            }else{
                TotalServicecharges = internetCost;
            }
            break;
        }
        else if (internet == 'N' || internet == 'n'){
            internetCost = 0;
            Servicecharges2 = "high speed internet = -";
            if(TotalServicecharges = parkingCost){
                TotalServicecharges = parkingCost;
            }else{
                TotalServicecharges = 0;
            };
            break;
        }
        else{
            cout << "You entered an invalid answer. Please enter 'Y' for yes or 'N' for no.";
        } 
    }while (internet != 'Y' && internet != 'y' && internet != 'N' && internet != 'n');
    char fitness;
    double fitnessCost ;
    do{
        bookingForm();
        cout << "Enter 'Y' for yes or 'N' for no for the following optional services:\n";
        cout << "Do you want a parking spot during your stay? "<<Parking<<"\n";
        cout << "Do you want a high speed internet during your stay? "<<internet<<"\n";
        cout << "Do you want to use of the fitness room during your stay? ";
        cin >> fitness;
        if (fitness == 'Y' || fitness == 'y'){
            fitnessCost = 20;
            Servicecharges3 ="fitness room = 20";
             if(TotalServicecharges = parkingCost+internetCost){
                TotalServicecharges = parkingCost+internetCost+fitnessCost;
            }else if(TotalServicecharges = parkingCost){
                TotalServicecharges = parkingCost+fitnessCost;
            }else if(TotalServicecharges = internetCost){
                TotalServicecharges = internetCost+fitnessCost;
            }else{
                TotalServicecharges = fitnessCost;
            }
            break;
        }
        else if (fitness == 'N' || fitness == 'n'){
            fitnessCost = 0;
            Servicecharges3 ="fitness room = -";
             if(TotalServicecharges = parkingCost+internetCost){
                TotalServicecharges = parkingCost+internetCost;
            }else if(TotalServicecharges = parkingCost){
                TotalServicecharges = parkingCost;
            }else if(TotalServicecharges = internetCost){
                TotalServicecharges = internetCost;
            }else{
                TotalServicecharges = 0;
            }
            break;
        }
        else{
            cout << "You entered an invalid answer. Please enter 'Y' for yes or 'N' for no.";
        }
    } while (   fitness != 'Y' && fitness != 'y' && fitness != 'N' && fitness != 'n');
    char breakfast;
    double breakfastCost ;
    do{
        bookingForm();
        cout << "Enter 'Y' for yes or 'N' for no for the following optional services:\n";
        cout << "Do you want a parking spot during your stay? "<<Parking<<"\n";
        cout << "Do you want a high speed internet during your stay? "<<internet<<"\n";
        cout << "Do you want to use of the fitness room during your stay? "<<fitness<<"\n";
        cout << "Do you want a breakfast during your stay? ";
       if (breakfast == 'Y' || breakfast == 'y'){
            breakfastCost = 50;
            Servicecharges4 = "breakfast = 50";
            if(TotalServicecharges = parkingCost+internetCost+fitnessCost){
                TotalServicecharges = parkingCost+internetCost+fitnessCost+breakfastCost;
            }else if(TotalServicecharges = parkingCost+fitnessCost){
                TotalServicecharges = parkingCost+fitnessCost+breakfastCost;
            }else if(TotalServicecharges = internetCost+fitnessCost){
                TotalServicecharges = internetCost+fitnessCost+breakfastCost;
            }else if(TotalServicecharges = parkingCost+internetCost){
                TotalServicecharges = parkingCost+internetCost+breakfastCost;
                
            }else if(TotalServicecharges = fitnessCost){
                TotalServicecharges = fitnessCost+breakfastCost;
            }else if(TotalServicecharges = parkingCost){
                TotalServicecharges = parkingCost+breakfastCost;
            }else if(TotalServicecharges = internetCost){
                TotalServicecharges = internetCost+breakfastCost;
            }else{
                TotalServicecharges = breakfastCost;
            }
            break;
        }
        else if (breakfast == 'N' || breakfast == 'n'){
            breakfastCost = 0;
            Servicecharges4 = "breakfast = -";
            if(TotalServicecharges = parkingCost+internetCost+fitnessCost){
                TotalServicecharges = parkingCost+internetCost+fitnessCost;
            }else if(TotalServicecharges = parkingCost+fitnessCost){
                TotalServicecharges = parkingCost+fitnessCost;
            }else if(TotalServicecharges = internetCost+fitnessCost){
                TotalServicecharges = internetCost+fitnessCost;
            }else if(TotalServicecharges = parkingCost+internetCost){
                TotalServicecharges = parkingCost+internetCost;
                
            }else if(TotalServicecharges = fitnessCost){
                TotalServicecharges = fitnessCost;
            }else if(TotalServicecharges = parkingCost){
                TotalServicecharges = parkingCost;
            }else if(TotalServicecharges = internetCost){
                TotalServicecharges = internetCost;
            }else{
                TotalServicecharges = 0;
            }
            break;
        }
        } while (   breakfast != 'Y' && breakfast != 'y' && breakfast != 'N' && breakfast != 'n');


    
     bookingForm();
    cout << "\tSave these details to a file? <Yes/No> ";
    cin >> saveYN;
    if (saveYN == "Yes" || saveYN == "yes"){
        savefile2();
    }; 
}
 

void memberDetails(){
    string saveYN;
    MemberForm();
    cout << "\tPlease enter customers first name : ";
    cin >> ws;
    getline (cin, name);
    MemberForm();
    cout << "\tPlease enter customers surname : ";
    cin >> surname;
    MemberForm();
    cout << "\tPlease enter customers house number : ";
    cin >> address1;
    while (cin.fail()||  address1 < 1)  
    {cin.clear(); cin.ignore();
    cout << "\n\tPlease enter a valid house number : "; cin >> address1;}
    MemberForm();
    cout << "\tPlease enter customers street : ";
    cin >> ws;                        
    getline (cin, address2);         
    MemberForm();
    cout << "\tPlease enter customer area : ";
    getline (cin, address3);
    MemberForm();
    cout << "\tPlease enter customer city : ";
    getline (cin, address4);
    MemberForm();
    cout << "\tPlease enter customer postcode : ";
    cin >> ws;
    getline (cin, postcode);
    MemberForm();
    cout << "\tPlease enter Telephone Number : ";
    getline (cin, tel);
    while (cin.fail()){ 
        cin.clear();
        cin.ignore();
        cout << "\tPlease enter Telephone Number : ";
        cin >> tel;
    };
    MemberForm();
    cout << "\tCould you have credit card? <Yes/No> ";
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
    cout << "\tSave these details to a file? <Yes/No> ";
    cin >> saveYN;
    if (saveYN == "Yes" || saveYN == "yes"){
        savefile();
    };
};

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
    while(!file_ptr)
        {
        cout << "Member does not exist\n";
        gets (filebooking);
        file_ptr.open(filebooking,ios::in);
        }
        getline(file_ptr, name);
        getline(file_ptr, surname);
        file_ptr >> address1;
        getline(file_ptr, address2);
        getline(file_ptr, address2); 
        getline(file_ptr, address3);
        getline(file_ptr, address4);
        getline(file_ptr, postcode);
        getline(file_ptr, tel);
        getline(file_ptr,creditcard);
        getline(file_ptr, creditcardType);
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
} 
void Showbillpayment(){
    system ("cls");
    cout<<"\n________________________________________________________________________________\n";
    cout<<"\t\t\t\t Marriott Luxury Hotel ";
    cout<<"\n \t\t\t____________________________________";
    cout<<"\n\t\t\t\t Chandigarh , Punjab-070. ";
    cout<<"\n\t\t\t\t Tel :- 12253636 ";
    cout<<"\n--------------------------------------------------------------------------------\n";
    system ("pause");
}  
void Showbillpaymentscript(){
    Showbillpayment();
}


void billpayment(){
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
    while(!file_ptr)
        {
        cout << "Member does not exist\n";
        gets (filebooking);
        file_ptr.open(filebooking,ios::in);
        }
        getline(file_ptr, name);
        getline(file_ptr, surname);
        getline(file_ptr,creditcard);
        getline(file_ptr, creditcardType);
        getline(file_ptr, Servicecharges1);
        getline(file_ptr, Servicecharges2); 
        getline(file_ptr, Servicecharges3);
        
        bookingForm();
        greentext();
        whitetext();
        file_ptr.close();
    cout << "\n\tShow Bill Payment? <Y/N>";
    cin >> confirm;
    if (confirm == 'y' || confirm == 'Y'){
        Showbillpaymentscript();
        };
   
}    






}
void priceList(){}
void help(){}
void exit(){}
void mainMenu(){

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
    cout << "\t\t\tPlease choose an option : ";
    cin >> menuchoice;
    while (cin.fail())
        {cin.clear();
        cin.ignore();
        cout << "\n\t\tPlease enter a valid number :"; cin >> menuchoice;
    };
    switch (menuchoice){
        case 1 :
            memberDetails();
            break;
        case 2 :
            priceList();
            break;
        case 3 :
            createBooking();
            break;
        case 4 :
             billpayment();
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
    while (MenuLoop == true){mainMenu();};     
    return 0;
}
