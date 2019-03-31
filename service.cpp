#include <iostream>

using namespace std;

//double calcServiceCharge (double parkingCost, double internetCost,double fitnessCost,double breakfastCost);
//double calcTotalCharges (double baseCharges, double serviceCharges);
double calcServiceCharge(double a, double b,double c,double d){
    return a + b + c + d;
}

int main(){
    cout << "Enter 'Y' for yes or 'N' for no for the following optional services:\n";


    char Parking ;
    double parkingCost ;
    do {
        cout << "Do you want a parking spot during your stay? ";
        cin >> Parking;
        if (Parking == 'Y' || Parking == 'y'){
            parkingCost = 20;
            break;
        }
        else if (Parking == 'N' || Parking == 'n'){
            parkingCost = 0;
            break;
        }
        else{
            cout << "You entered an invalid answer. Please enter 'Y' for yes or 'N' for no.\n";
        }
        }while (Parking != 'Y' && Parking != 'y' && Parking != 'N' && Parking != 'n');


    char internet;
    double internetCost ;
    do {
        cout << "Do you want a high speed internet during your stay? ";
        cin >> internet;
        if (internet == 'Y' || internet == 'y'){
            internetCost = 50;
            break;
        }
        else if (internet == 'N' || internet == 'n'){
            internetCost = 0;
            break;
        }
        else{
            cout << "You entered an invalid answer. Please enter 'Y' for yes or 'N' for no.";
        } 
        }while (   internet != 'Y' && internet != 'y' && internet != 'N' && internet != 'n');


    char fitness;
    double fitnessCost ;
    do {
        cout << "Do you want to use of the fitness room during your stay? ";
        cin >> fitness;
        if (fitness == 'Y' || fitness == 'y'){
            fitnessCost = 20;
            break;
        }
        else if (fitness == 'N' || fitness == 'n'){
            fitnessCost = 0;
            break;
        }
        else{
            cout << "You entered an invalid answer. Please enter 'Y' for yes or 'N' for no.";
        }
        } while (   fitness != 'Y' && fitness != 'y' && fitness != 'N' && fitness != 'n');

    char breakfast;
    double breakfastCost ;
    do {
        cout << "Do you want a breakfast during your stay? ";
        cin >> breakfast;
        if (breakfast == 'Y' || breakfast == 'y'){
            breakfastCost = 50;
            break;
        }
        else if (breakfast == 'N' || breakfast == 'n'){
            breakfastCost = 0;
            break;
        }
        else{
            cout << "You entered an invalid answer. Please enter 'Y' for yes or 'N' for no.";
        }
        } while (   breakfast != 'Y' && breakfast != 'y' && breakfast != 'N' && breakfast != 'n');

        cout << " The Total service charges are : " << calcServiceCharge(parkingCost,internetCost,fitnessCost,breakfastCost);
   
return 0;
}

