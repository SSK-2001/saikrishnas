#include<string>
class Calender//CREATING A CALENDER CLASS
{
public:
    int dayNumber(int day,int month,int year);
    char * getMonthName(int monthNumber);
    int numberOfDays(int monthNumber,int year);
    void printCalendar(int year,int month);
    Calender(){}
    void setYearMonth(int mon,int ye)const
    {
        this->month=mon;
        this->year=ye;
    }
private:
    int day,monthNumber,days,current;
    mutable int year,month;
    char * months[13] = {" ","January", "February", "March",
                       "April", "May", "June",
                       "July", "August", "September",
                       "October", "November", "December"
                      };
   static int firstDayOfMonth[12];

};

