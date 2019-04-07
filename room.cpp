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
void room(int , int );
//void detailroom(int);

int main(){
    int a,c1,c2;
    cout << " A : ";
    cin >> a;
    cout << " C : ";
    cin >> c2;
    cout << "------------------------------------  \n";
    room(a,c2);

}


void room(int b,int s){





	int j = 0;
    if(b<=2 && s<=2) j = 2;
    if(b>2 && b<=4 && s<=2) j = 3;
    int i = 0;
    redtext ();
    if (j != 3) cout << "***** Appropriate rooms. *****\n";
    whitetext();
            cout << "1.";
            cout << " Standard Studio \n";
            cout << "   - Price per night : 600 Baht\n";
            cout << "   - 2 Single bed or 1 Queen Sized  \n";
            cout << "   - Non-smoking  \n";
            cout << "   - Private Bathroom  \n";
            cout << "   ------------------------------------  \n";
            cout << "2.";
            cout << " Deluxe Studio \n"; 
            cout << "   - Price per night : 900 Baht\n";
            cout << "   - 1 king bed  \n";
            cout << "   - Balcony/terrace  \n";
            cout << "   - City view  \n";
            cout << "   - Non-smoking  \n";
            cout << "   - Private Bathroom  \n";
            cout << "   ------------------------------------  \n";
        
     if (j == 3){
         redtext ();
         cout << "***** Appropriate rooms. *****\n"; 
         whitetext();
         cout << "1.";
     }else{
         cout << "3.";
     }
				cout << " Standard Family \n";
                cout << "   - Price per night : 1200 Baht\n";
                cout << "   - 1 king bed and 1 bunk bed   \n";
                cout << "   - Balcony/terrace  \n";
                cout << "   - City view  \n";
                cout << "   - Non-smoking  \n";
                cout << "   - Private Bathroom  \n";
                cout << "   ------------------------------------  \n";
			}