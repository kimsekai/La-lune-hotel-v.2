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
int day(00);
int month(00);
int year(00);
int day2(00);
int month2(00);
int year2(00);
int DAY(00);
double TotalPrice(0.00);
double TotalServicecharges(0.00);
const int january = 31;
const int february = 28;
const int leapYearFeb = 29;
const int march = 31;
const int april = 30;
const int may = 31;
const int june =30;
const int july = 31;
const int august = 31;
const int september = 30;
const int october = 31;
const int november = 30;
const int decemebr = 31;
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

int stdroom[3] = {101,102,103} ;
int delroom[3] = {201,202,203} ;
int famroom[3] = {301,302,303} ;
int roomSelection;
string roomType("*****");

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

void resetBookingDetails(){
    Servicecharges1 = "*****";
    Servicecharges2 = "*****";
    Servicecharges3 = "*****";
    Servicecharges4 = "*****";
    TotalServicecharges = 00;
    day= 00;
    month = 00;
    year = 00;
    day2= 00;
    month2 = 00;
    year2 = 00;
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
bool leapYear (int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    else
        return false;
}
bool validMonth (int month)
{
    if (month > 0 || month < 13)
        return true;
    else
        return false;
}

bool validYear (int year)
{
    if (year > 1582)
        return true;
    else
        return false;
}
 void getData1 (int& day, int& month, int& year)
{
   whitetext();
    cout << "\n\t\t          Check in Date: ";
    if (day != 00){greentext();};
    cout << day << "/" << month << "/" << year;   
}

bool validDay (int year, int month, int day)
{
    if(year > 1582)
    {
        if(validMonth(month))
        {
            if((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month || 8) || (month == 10) || (month || 12))
            {
                if((day > 0) || (day < 32))
                    return true;
                else
                    return false;
            }
            if((month == 4) || (month == 6) || (month == 9) || (month == 11))
            {
                if((day > 0) || (day < 31))
                    return true;
                else
                    return false;
            }
            if(month == 2)
            {
                if((day > 0) || (day < 29))     
                    return true;
                else
                    return false;
            }
            if((leapYear(year)))
            {
                if((month == 2) && ((day > 0) || (day < 30)))
                    return true;
                else
                    return false;
            }
        }
    }
}


int dayOfYear (int day, int month, int year)
{
    int dayTotal = 0;

    if(validDay(day, month, year))
    {
        if(month == 1)
        {
            dayTotal = 0 + day;
        }

        if(month == 2)
        {
            dayTotal = january + day;
        }

        if((month == 3) && (year > 1582))
        {
            dayTotal = january + february + day;

            if((month == 3) && (year > 1582) && (leapYear(year)))
            {
                dayTotal = january + leapYearFeb + day;
            }
        }

        if((month == 4) && (year > 1582))
        {
            dayTotal = january + february + march + day;

            if((month == 4) && (year > 1582) && (leapYear(year)))
            {
                dayTotal = january + leapYearFeb + march + day;
            }
        }

        if((month == 5) && (year > 1582))
        {
            dayTotal = january + february + march + april + day;

            if((month == 5) && (year > 1582) && (leapYear(year)))
            {
                dayTotal = january + leapYearFeb + march + april + day;
            }
        }

        if((month == 6) && (year > 1582))
        {
            dayTotal = january + february + march + april + may + day;

            if((month == 6) && (year > 1582) && (leapYear(year)))
            {
                dayTotal = january + leapYearFeb + march + april + may + day;
            }
        }

        if((month == 7) && (year > 1582))
        {
            dayTotal = january + february + march + april + may + june + day;

            if((month == 7) && (year > 1582) && (leapYear(year)))
            {
                dayTotal = january + leapYearFeb + march + april + may + june + day;
            }
        }

        if((month == 8) && (year > 1582))
        {
            dayTotal = january + february + march + april + may + june + july + day;

            if((month == 8) && (year > 1582) && (leapYear(year)))
            {
                dayTotal = january + leapYearFeb + march + april + may + june + july + day;
            }
        }

        if((month == 9) && (year > 1582))
        {
            dayTotal = january + february + march + april + may + june + july + august 
                       + day;

            if((month == 9) && (year > 1582) && (leapYear(year)))
            {
                dayTotal = january + leapYearFeb + march + april + may + june + july + august 
                       + day;
            }
        }

        if((month == 10) && (year > 1582))
        {
            dayTotal = january + february + march + april + may + june + july + august 
                       + september + day;

            if((month == 10) && (year > 1582) && (leapYear(year)))
            {
                dayTotal = january + leapYearFeb + march + april + may + june + july + august
                       + september + day;
            }
        }

        if((month == 11) && (year > 1582))
        {
            dayTotal = january + february + march + april + may + june + july + august 
                       + september + october + day;

            if((month == 11) && (year > 1582) && (leapYear(year)))
            {
                dayTotal = january + leapYearFeb + march + april + may + june + july + august 
                       + september + october + day;
            }
        }

        if((month == 12) && (year > 1582))
        {
            dayTotal = january + february + march + april + may + june + july + august
                       + september + october + november + day;

            if((month == 5) && (year > 1582) && (leapYear(year)))
            {
                dayTotal = january + leapYearFeb + march + april + may + june + july + august
                       + september + october + november + day;
            }
        }
    }

    return dayTotal;
}
bool leapYear2 (int year2)
{
    if ((year2 % 4 == 0 && year2 % 100 != 0) || (year2 % 400 == 0))
        return true;
    else
        return false;
}
bool validMonth2 (int month2)
{
    if (month2 > 0 || month2 < 13)
        return true;
    else
        return false;
}

bool validYear2 (int year2)
{
    if (year2 > 1582)
        return true;
    else
        return false;
}
 
 void getData2 (int& day2, int& month2, int& year2)
{
   whitetext();
    cout << "\n\t\t          Check out Date: ";
    if (day2 != 00){greentext();};
    cout << day2 << "/" << month2<< "/" << year2;   
}

bool validDay2 (int year2, int month2, int day2)
{
    if(year2 > 1582)
    {
        if(validMonth2(month2))
        {
            if((month2 == 1) || (month2 == 3) || (month2 == 5) || (month2 == 7) || (month2 || 8) || (month2 == 10) || (month2 || 12))
            {
                if((day2 > 0) || (day2 < 32))
                    return true;
                else
                    return false;
            }
            if((month2 == 4) || (month2 == 6) || (month2 == 9) || (month2 == 11))
            {
                if((day2 > 0) || (day2 < 31))
                    return true;
                else
                    return false;
            }
            if(month2 == 2)
            {
                if((day2 > 0) || (day2 < 29))     
                    return true;
                else
                    return false;
            }
            if((leapYear2(year2)))
            {
                if((month2 == 2) && ((day2 > 0) || (day2 < 30)))
                    return true;
                else
                    return false;
            }
        }
    }
}


int dayOfYear2 (int day2, int month2, int year2)
{
    int dayTotal2 = 0;

    if(validDay2(day2, month2, year2))
    {
        if(month2 == 1)
        {
            dayTotal2 = 0 + day2;
        }

        if(month2 == 2)
        {
            dayTotal2 = january + day2;
        }

        if((month2 == 3) && (year > 1582))
        {
            dayTotal2 = january + february + day2;

            if((month2 == 3) && (year2 > 1582) && (leapYear(year2)))
            {
                dayTotal2 = january + leapYearFeb + day2;
            }
        }

        if((month2 == 4) && (year2 > 1582))
        {
            dayTotal2 = january + february + march + day2;

            if((month2 == 4) && (year2 > 1582) && (leapYear(year2)))
            {
                dayTotal2 = january + leapYearFeb + march + day2;
            }
        }

        if((month2 == 5) && (year2 > 1582))
        {
            dayTotal2 = january + february + march + april + day2;

            if((month2 == 5) && (year2 > 1582) && (leapYear(year2)))
            {
                dayTotal2 = january + leapYearFeb + march + april + day2;
            }
        }

        if((month2 == 6) && (year2 > 1582))
        {
            dayTotal2 = january + february + march + april + may + day2;

            if((month2 == 6) && (year2 > 1582) && (leapYear(year2)))
            {
                dayTotal2 = january + leapYearFeb + march + april + may + day2;
            }
        }

        if((month2 == 7) && (year2 > 1582))
        {
            dayTotal2 = january + february + march + april + may + june + day2;

            if((month2 == 7) && (year2 > 1582) && (leapYear(year2)))
            {
                dayTotal2 = january + leapYearFeb + march + april + may + june + day2;
            }
        }

        if((month2 == 8) && (year2 > 1582))
        {
            dayTotal2 = january + february + march + april + may + june + july + day2;

            if((month2 == 8) && (year2 > 1582) && (leapYear(year2)))
            {
                dayTotal2 = january + leapYearFeb + march + april + may + june + july + day2;
            }
        }

        if((month2 == 9) && (year2 > 1582))
        {
            dayTotal2 = january + february + march + april + may + june + july + august 
                       + day2;

            if((month2 == 9) && (year > 1582) && (leapYear(year2)))
            {
                dayTotal2 = january + leapYearFeb + march + april + may + june + july + august 
                       + day2;
            }
        }

        if((month2 == 10) && (year2 > 1582))
        {
            dayTotal2 = january + february + march + april + may + june + july + august 
                       + september + day2;

            if((month2 == 10) && (year2 > 1582) && (leapYear(year2)))
            {
                dayTotal2 = january + leapYearFeb + march + april + may + june + july + august
                       + september + day2;
            }
        }

        if((month2 == 11) && (year2 > 1582))
        {
            dayTotal2 = january + february + march + april + may + june + july + august 
                       + september + october + day2;

            if((month2 == 11) && (year2 > 1582) && (leapYear(year2)))
            {
                dayTotal2 = january + leapYearFeb + march + april + may + june + july + august 
                       + september + october + day2;
            }
        }

        if((month2 == 12) && (year2 > 1582))
        {
            dayTotal2 = january + february + march + april + may + june + july + august
                       + september + october + november + day2;

            if((month2 == 5) && (year2 > 1582) && (leapYear(year2)))
            {
                dayTotal2 = january + leapYearFeb + march + april + may + june + july + august
                       + september + october + november + day2;
            }
        }
    }

    return dayTotal2;
}

void calculateall(){
    getData1(day , month,  year); 
    validDay(day, month, year);
    getData2(day2 , month2,  year2); 
    validDay2(day2, month2, year2);
    if(validDay2(day2, month2, year2) && validDay(day, month, year)== true)
                {   
                    whitetext();
                    cout<<"\n\t\t          For how many nights: ";
                    greentext();
                    DAY = dayOfYear2(day2, month2, year2)-dayOfYear(day, month, year);
                    if(DAY>=0 and DAY<=1)
                    cout<<DAY<<" night";
                    else if(DAY>1)
                     cout<<DAY<<" nights";
                    
                }
    
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
    calculateall();
    whitetext();
    cout << "\n\t\t         Room Type: ";
    if (roomType != "*****"){greentext();};
    cout << roomType;
    whitetext();
    cout << "\n\t\t          Total Price: ";
    if (TotalPrice != 00.00){greentext();};
    cout << TotalPrice;
    whitetext();
    cout << "\n\t________________________________________________________________\n\n";
    cout << "\n";

}; 

void bookingScript(){
    string saveYN;
    double discount;
    char confirmationSave;
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
    bookingForm();

    cout << "\tPlease enter  Start Date(DD): ";
    cin >> day;
    while (cin.fail() || day > 31 || day< 1){//Catches invalid date
        cin.clear(); cin.ignore();
        cout << "\n\tPlease enter a valid date (1-31): ";
        cin >> day;
    };

    bookingForm();
    cout << "\tPlease enter Start Month(MM): ";
    cin >>month;
    while (cin.fail() || month > 12 ||month< 1){//Catches invalid month
        cin.clear(); cin.ignore();
        cout << "\n\tPlease enter a valid month (1-12): ";
        cin >> month;}
     bookingForm();
    cout << "\tPlease enter  Start Year(YY): ";
    cin >> year ;
    while (cin.fail() || year > 9999 || year < 1000){//Catches invalid year
        cin.clear(); cin.ignore();
        cout << "\n\tPlease enter a valid Year : ";
        cin >> year ;}
     bookingForm();
    cout << "\tPlease enter  End Date(DD): ";
    cin >> day2;
    while (cin.fail() || day2 > 31 || day2 < 1){
        cin.clear(); cin.ignore();
        cout << "\n\tPlease enter a valid date (1-31): ";
        cin >>day2;}
     bookingForm();
    cout << "\tPlease enter  End Month(MM): ";
    cin >>  month2;
    while (cin.fail() || month2 > 12 ||  month2 < 1){
        cin.clear(); cin.ignore();
        cout << "\n\tPlease enter a valid month (1-12): ";
        cin >>  month2;}
     bookingForm();
    cout << "\tPlease enter  End Year(YY): ";
    cin >> year2;
    while (cin.fail() || year2> 9999 ||year2 < 1000){
        cin.clear(); cin.ignore();
        cout << "\n\tPlease enter a valid year : ";
        cin >> year2;}
     bookingForm(); 
    
    cout << "\tWhat kind of room do you want?\n";
    cout << "\t1 - Standard Studio\n";
    cout << "\t2 - Deluxe Studio\n";
    cout << "\t3 - Standard Family\n";
    cout << "\t> : ";
    cin >> roomSelection;
    switch(roomSelection){
        case 1 :
            roomType = "Standard Studio";
            break;
        case 2 :
            roomType = "Deluxe Studio";
            break;
        case 3 :
            roomType = "Standard Family";
            break;
    }
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
    myfile << creditcard << "\n";
    myfile << creditcardType << "\n";
    myfile << Servicecharges1 << "\n";
    myfile << Servicecharges2 << "\n";
    myfile << Servicecharges3 << "\n";
    myfile << Servicecharges4 << "\n";
    myfile << TotalServicecharges << "\n";
    myfile << day << "\n";
    myfile << month << "\n";
    myfile << year << "\n";
    myfile << day2 << "\n";
    myfile << month2 << "\n";
    myfile << year2 << "\n";
    myfile << DAY << "\n";
    myfile.close();
    bookingForm();
    greentext();
    cout << "\tBooking have been saved\n\n\t";
    whitetext();
    }
    system ("pause");
 
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
    myfile << roomType << "\n";

    myfile.close();
    MemberForm();
    greentext();
    cout << "\tDetails have been saved\n\n\t";
    whitetext();
    system ("pause");
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
    cout<<"\t\t\t\t    La-lune-hotel  ";
    cout<<"\n \t\t\t____________________________________";
    cout<<"\n\t\t\t\tChiang Mai,Chiang Mai  ";
    cout<<"\n\t\t\t\t    Tel :-023658966 ";
    cout<<"\n--------------------------------------------------------------------------------\n";
 	cout<<"\n      Customer name : "<<name<<" "<<surname;     
    cout<<"\n                              ";     
    cout<<"\n      Stayed for "<<DAY<<" days";     
    cout<<"\n      Room charges(Per day)    : "<<"100";     
    cout<<"\n      Room charges(Total)    : "<<"1000";     
     
    cout<<"\n      Total service hanges charges   : "<<"140";     
    cout<<"\n                          Ser.tax % = 5%";     
    cout<<"\n                          Ser.tax   ="<<"25000";     
    cout<<"\n      Bill Amount >>>>>> Rs "<<"25000";     
    cout<<"\n                              ";     
    cout<<"\n      ***THANK YOU FOR COMING***";     
    cout<<"\n      Visit Again !"; 
    /*char filename [100];
    ifstream file_ptr;
    cout << "\n\t\t\t\tSaved Bookings:\n\n";
    system ("dir/b *.booking");
    gets (filename);
    if (filename[0]  != 'z'){
 
    file_ptr.open(filename,ios::in);
   // char in_char;
        getline(file_ptr, name);
        getline(file_ptr, surname);
 
        getline(file_ptr, creditcard); 
        getline(file_ptr, creditcardType);
        getline(file_ptr, Servicecharges1);
        getline(file_ptr, Servicecharges2);
        getline(file_ptr, Servicecharges3);
        getline(file_ptr, Servicecharges4);
        file_ptr >> TotalServicecharges;
        file_ptr >>checkinDate;
        file_ptr >>checkinMonth;
        file_ptr >> checkoutDate;
        file_ptr >> checkoutMonth;
        file_ptr >> checkoutYear;
        file_ptr >> TotalPrice;
 
        bookingForm();
        greentext();
        whitetext();
 
        file_ptr.close();
    }*/
    system ("pause");
}  
void Showbillpaymentscript(){
    Showbillpayment();
}


void billpayment(){
    char confirm;
system ("cls");
    char filename [100];
    ifstream file_ptr;
    cout << "\n\t\t\t\tSaved Bookings:\n\n";
    system ("dir/b *.booking");
    cout << "\n\n\tPlease type the name of the booking you\n";
    cout << "     \twish to open as it appears above OR\n";
    cout << "     \ttype z (Lower case) to return to main menu: ";
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
 
        getline(file_ptr, creditcard); 
        getline(file_ptr, creditcardType);
        getline(file_ptr, Servicecharges1);
        getline(file_ptr, Servicecharges2);
        getline(file_ptr, Servicecharges3);
        getline(file_ptr, Servicecharges4);
        file_ptr >> TotalServicecharges;
        file_ptr >>day;
        file_ptr >>month;
        file_ptr >>year;
        file_ptr >>day2;
        file_ptr >>month2;
        file_ptr >>year2;
        file_ptr>>DAY;
        file_ptr >> TotalPrice;
 
        bookingForm();
        greentext();
        whitetext();
 
        file_ptr.close();
        
      cout << "\n\tShow Bill payment? <Y/N>";
    cin >> confirm;
    if (confirm == 'y' || confirm == 'Y'){
        Showbillpaymentscript();
        };
    };
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
    resetBookingDetails();
    cout << "\t\t3 - Create a new booking\n\n";
    whitetext();
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