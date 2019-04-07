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

    char Parking ;
    double parkingCost ;
    do {
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
    do {
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
        }while (   internet != 'Y' && internet != 'y' && internet != 'N' && internet != 'n');


    char fitness;
    double fitnessCost ;
    do {
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
    do {
        bookingForm();
        cout << "Enter 'Y' for yes or 'N' for no for the following optional services:\n";
        cout << "Do you want a parking spot during your stay? "<<Parking<<"\n";
        cout << "Do you want a high speed internet during your stay? "<<internet<<"\n";
        cout << "Do you want to use of the fitness room during your stay? "<<fitness<<"\n";
        cout << "Do you want a breakfast during your stay? ";
        cin >> breakfast;
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
        else{
            cout << "You entered an invalid answer. Please enter 'Y' for yes or 'N' for no.";
        }
        } while (   breakfast != 'Y' && breakfast != 'y' && breakfast != 'N' && breakfast != 'n');


    
        
   
}
int main(){
    bookingScript();
}