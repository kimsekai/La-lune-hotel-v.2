#include <iostream>
using namespace std;

void room(int , int );
void detailroom(int);

int main(){
    int a,c1,c2;
    cout << " A : ";
    cin >> a;
    cout << " C : ";
    cin >> c2;
    room(a,c2);

}

void detailroom(int k){
    for(int i = 0; i < k; i++)
    {
        if (i == 1) {
            cout << " Standard Studio \n";
            cout << "   - Price per night : 600 Baht\n";
            cout << "   - 2 Single bed or 1 Queen Sized  \n";
            cout << "   - Non-smoking  \n";
            cout << "   - Private Bathroom  \n";
            cout << "   ------------------------------------  \n";
            }
        if (i == 2) {
            cout << " Deluxe Studio \n"; 
            cout << "   - Price per night : 900 Baht\n";
            cout << "   - 1 king bed  \n";
            cout << "   - Balcony/terrace  \n";
            cout << "   - City view  \n";
            cout << "   - Non-smoking  \n";
            cout << "   - Private Bathroom  \n";
            cout << "   ------------------------------------  \n";
            }
        if (i == 3) {
             cout << " Standard Family \n";
                cout << "   - Price per night : 1200 Baht\n";
                cout << "   - 1 king bed and 1 bunk bed   \n";
                cout << "   - Balcony/terrace  \n";
                cout << "   - City view  \n";
                cout << "   - Non-smoking  \n";
                cout << "   - Private Bathroom  \n";
                cout << "   ------------------------------------  \n";
            }
}
}

void room(int b,int s){
 int j = 0;
    if(b<=2&&s<=2){
        j = 2;
    }else if (b>2 && b<=4 && s<=2) {
        j = 3;
    }
    void detailroom(int j);
}