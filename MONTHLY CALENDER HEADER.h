
#include<iostream>
#include<string>
#include<stdlib.h>
#include<ctime>



bool isLeap(int year)//NON MEMBER FUNCTION
{
    if (year % 400 == 0 ||
                (year % 4 == 0 && year % 100 != 0))
            return true;
        else
            return false;


}

