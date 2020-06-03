#include"MONTHLY CALENDER HEADER.h"
#include<ctime>
using namespace std;
/*
CODE DEVELOPED BY:SAIKRISHNA S
REGISTRATION NUMBER : 19BBS0086
LAST DATE MODIFIED:26:04:2020    17:04
TOPIC:CREATING A MONTHLY CALENDER
GROUP ID:1006
PROGRAMME:CBS1002
*/
class Calender//CREATING A CALENDER CLASS
{
public:
    int dayNumber(int day,int month,int year);
    string getMonthName(int monthNumber);
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
    string months[13] = {"","January", "February", "March",
                       "April", "May", "June",
                       "July", "August", "September",
                       "October", "November", "December"
                      };
   static int firstDayOfMonth[12];

};

//TO KNOW THAT THE FIRST DAY FALLS ON WHICH DAY W.R.T JAN1
// IF JAN 1 IS SUNDAY THEN FEB 1 WILL 3 DAYS AHEAD OF THAT
int Calender::firstDayOfMonth[12]= { 0, 3, 2, 5, 0, 3, 5, 1,4, 6, 2, 4 };
//DEFINING STATIC MEMBERS OUTSIDE THE CLASS
/*
 USE OF BOTH MEMBER AND NONMEMBER FUNCTIONS ARE DONE
 TO DIFFERENTIATE THEM MEMBER FUNCTIONS ARE DEFINED AS INLINE
*/
inline int Calender::dayNumber(int day,int month,int year)
{
     year -= month < 3;
    return ( year + year/4 - year/100 +
             year/400 + Calender::firstDayOfMonth[month-1] + day) % 7;//RETURNS THE DAYNUMBER OF CORRESSPONDING WEEK DAY
                                                                      //LIKE FOR EXAMPLE:
                                                                       /*
                                                                          0:SUNDAY
                                                                            1:MONDAY
                                                                              2:TUESDAY
                                                                                3:WEDNESDAY AND SO ON...
                                                                                                        */

}
inline string Calender::getMonthName(int monthNumber)
{
     return (months[monthNumber]);

}//RETURNS THE PARTICULAR MONTH NAME IN THE FORM OF A STRING

inline int Calender:: numberOfDays(int monthNumber,int year)
{
    /*
    THIS FUNCTION IS USED TO RETURN THE NUMBER OF DAYS IN A PARICULAR MONTH
    THAT HAS SPECIFIC RANGE
    FOR NONLEAP YEAR:28<=NUMBEROFDAYS<=31
    FOR LEAP YEAR:29<=NUMBEROFDAYS<=31
    */

        switch(monthNumber)
        {
        case 1:
            return (31);
            break;
        case 2:
            if (isLeap(year)==true)
            return (29);
        else
            return (28);

            break;
        case 3:
            return (31);
            break;
        case 4:
            return (30);
            break;
        case 5:
            return (31);
            break;
        case 6:
            return (30);
            break;
        case 7:
            return (31);
            break;
        case 8:
            return (31);
            break;
        case 9:
            return (30);
            break;
        case 10:
            return (31);
            break;
        case 11:
            return (30);
            break;
        case 12:
            return (31);
        break;
            default:cout<<"WRONG ENTRY PLEASE ENTER A VALID INPUT"<<endl;
        }

}
inline void Calender:: printCalendar(int year,int month)
{/*PRINTS A CALENDER FOR A GIVEN MONTH AND YEAR*/
    cout<<" **********************Calendar - "<< year<<"*****************************"<<endl;
    int days;
    int current = dayNumber (1, month, year);
    days = numberOfDays (month, year);
    cout<<"\n------------"<<getMonthName(month)<<"--------------\n"<<endl;
    cout<<"  SUN  MON  TUE  WED  THU  FRI  SAT\n"<<endl;
     // Print appropriate spaces
     int k;
     for (k = 0; k < current; k++)
            cout<<"     ";
     for (int j = 1; j <= days; j++)
        {printf("%5d", j);
         if (++k > 6)
            {
                k = 0;
                cout<<endl;
            }
        }

        if (k)
            cout<<"\n";

        current = k;

    return;

}
void ChooseBgroung()
{
    char choice;
    cout<<"ENTER A CHOICE TO CHANGE THE BACKGROUND COLOR FROM 1-8 BOTH INCLUSIVE"<<endl;
    cin>>choice;
    switch(choice)
    {
    case '0':
        system("Color 0F");
        break;
    case '1':
        system("Color 1F");
        break;
    case '2':
        system("Color 2F");
        break;
    case '3':
        system("Color 3F");
        break;
    case '4':
        system("Color 4F");
        break;
    case '5':
        system("Color 5F");
        break;
    case '6':
        system("Color 6F");
        break;
    case '7':
        system("Color 7F");
        break;
    case '8':
        system("Color 8F");
        break;


        default:system("Color FF");

    }


}
void Output()
{
    int year,month;
    cout<<"                  WELCOME  "<<endl;
    cout<<"             ENTER ANY PARTICULAR YEAR "<<endl;
    cin>>year;
    try//TO ELIMINATE THE EXISTANCE OF THE ZERO YEAR
    {
        if((year==0)||(year==00 )||(year==000)||(year== 0000  )||(year==00000))
        {
            throw "YOU HAVE ENTERED A WRONG ENTRY W.R.T YEAR FORMAT";
        }
        else
        {
             cout<<"please proceed"<<endl;
             cout<<"TO ENTER MONTH PRESS\n1:FOR JAN\n2:FOR FEB\n3:FOR MARCH\n4:FOR APRIL\n5:FOR MAY\n6:FOR JUNE\n7:FOR JULY\n8:AUGUST\n9:SEPTEMBER\n10:FOR OCTOBER\n11:FOR NOVEMBER\n12:FOR DECEMBER\n"<<endl;
             cin>>month;
             Calender obj;
			 obj.setYearMonth(month,year);
             obj.printCalendar(year,month);
        }

    }
    catch(...)
    {
        cout<<"WRONG FORMAT OF INPUT"<<endl;
    }


    time_t tt;


    struct tm * ti;


    time (&tt);


    ti = localtime(&tt);

    cout << "CURRENT DATAILS: "<< asctime(ti);

}
int main()//TESTING WITH MAIN FUNCTION
{
    ChooseBgroung();
    Output();
    return 0;
}
