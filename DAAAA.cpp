#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

void showOption();
bool validMonth (int month);
bool validYear (int year);
bool leapYear (int year);
bool validDay (int year, int month, int day);
void getData (int& month, int& day, int& year);
void easterDate (int& month, int& day, int& year);
int daysBetween (int month1, int day1, int month2, int day2, int year);
int dayOfYear (int day, int month, int year);

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

int main()
{
    int option;
    int day, month, year;
    int easterDay, easterMonth;
    int day1, day2, month1, month2;

    bool repeat = false;

    showOption();

    cout << "please enter your option: ";
    cin >> option;
    cout << "" << endl;

    switch (option)
    {
        case 1:

            do
            {
                getData(month, day, year);

                validDay(year, month, day);

                if(validDay(year, month, day) == true)
                {
                    cout << "month " << month << " day " << day << " year " << year << endl;
                    cout << " " << endl;
                    cout << "They day of the year based on the date you entered is "<< dayOfYear(day, month, year) << endl;
                    cout << " " << endl;
                }
                else
                {

                    cout << "it is not a valid date." << endl;
                }


                cout << "do you still want to continue?" << endl;
                cout << "0 = no.     1 = yes.     ";
                cin >> repeat;
                cout << " " << endl;

            } while(repeat);

            break;
        case 2:

            do
            {

                cout << "do you still want to continue?" << endl;
                cout << "0 = no.     1 = yes.     ";
                cin >> repeat;

            } while(repeat);

            break;

        case 3:

            do
            {

                cout << "do you still want to continue?" << endl;
                cout << "0 = no.     1 = yes.     ";
                cin >> repeat;

            } while(repeat);

            break;
    }

}

void showOption()
{
    cout << " ------------------MENU------------------ " << endl;
    cout << " 1) Day of the year." << endl;
    cout << " 2) Date of Easter day." << endl;
    cout << " 3) Number of days between 2 days entered." << endl;
    cout << "" << endl;
    cout << "" << endl;
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

bool leapYear (int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    else
        return false;
}

void getData (int& month, int& day, int& year)
{
    cout << "enter the number of year: ";
            cin >> year;
            cout << "" << endl;
            cout << "enter the number of month: ";
            cin >> month;
            cout << "" << endl;
            cout << "enter the number of day: ";
            cin >> day;
            cout << "" << endl;
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

    if(validDay(year, month, day))
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