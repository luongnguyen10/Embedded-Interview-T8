#include "date.h"

void displayDayofWeek(int count){
    int dayOfWeek = count %7;
    printf("So ngay: %d\n", count);
    // printf("Ngay trong tuan %d\n", dayOfWeek);
    printf("Today is: ");
    char Week[] = "SatSunMonTueWedThuFri";

    for (int i = dayOfWeek * 3 ; i != (dayOfWeek * 3 + 3 ); i++) {
        printf("%c",Week[i]);
    }
}

/*
* Function: isLeapYear
* Description: Check the input is the leap year or not
* Input:
*   year - int
* Output:
*   returns 1 - is the leap year
*           0 - not leap year
*/

int isLeapYear(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 ==0) ? 1 : 0;
}

/*
* Function: countDayinMonth
* Description: Calculate the days in the months
* Input:
*   dateCurrent - Date
* Output:
*   returns sum - total days in the months before the finded day
*/
int countDayinMonth(Date dateCurrent){
                          //T1, T2  T3  T4  T5  T6  T7  T8  T9  T10 T11 T12
    int weekDaynotleap[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int weekDayisleap[]  = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int sum = 0;
    if (isLeapYear(dateCurrent.year) == 1){
        for (int i = 0; i < (dateCurrent.month-1); i++){
            sum += weekDayisleap[i];
        }
    }
    else {
        for (int i = 0; i < (dateCurrent.month-1); i++){
            sum += weekDaynotleap[i];
        }
    }
    return sum;
}

/*
* Function: numberOfDays
* Description: Find the the Days in the week by Sum of between dateCurrent and dateOrigin then divide to 7 
* Input:
*   dateCurrent - Date
*   dateOrigin  - Date
* Output:
*   returns - the Days in the week
*/
int numberOfDays(Date dateOrigin, Date dateCurrent){
    int result = 0;
    int flat = 0; 
    if (dateCurrent.year == dateOrigin.year) {
        if (dateCurrent.month == dateOrigin.month){
            result = dateCurrent.day - dateOrigin.day +1;
        }
        else if (dateCurrent.month > dateOrigin.month){
            result = countDayinMonth(dateCurrent)+dateCurrent.day-1;
        }
        else flat+=1;
    }
    else if (dateCurrent.year > dateOrigin.year ){
        int countLeapYear = 0;
        for (int i = dateOrigin.year; i < dateCurrent.year; i++){
            if (isLeapYear(i) == 1) countLeapYear++;
        }
        int countDayinYears = countLeapYear+365*(dateCurrent.year - dateOrigin.year);
        printf("So nam nhuan giua 2 nam: %d\n", countLeapYear);
        // printf("So ngay trong nam%d\n", countDayinYears);

        if (dateCurrent.month == dateOrigin.month){
            result = countDayinYears + (dateCurrent.day - dateOrigin.day)+1;
        }
        else if (dateCurrent.month > dateOrigin.month){
            // printf("So ngay trong thang\n%d\n", countDayinMonth(dateCurrent));
            result = countDayinYears + countDayinMonth(dateCurrent) + dateCurrent.day-1;
        }
        else flat+=1;
    }
    else flat+=1;

    if (flat == 0) return result;
    else {
        printf("Cannot Calculate!\n");
        return 0;
    }
} 
