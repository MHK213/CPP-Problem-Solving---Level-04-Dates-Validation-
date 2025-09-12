/**
 * @brief Print a Month Calendar
 *
 * This program reads a year and a month from the user and prints
 * a formatted calendar for that month, aligned with weekdays
 * (Sunday–Saturday).
 *
 * The program:
 * - Uses Zeller’s congruence to calculate the first weekday of the month.
 * - Adjusts for leap years when printing February.
 *
 * Example:
 * Input: Year = 2024, Month = 9
 * Output:
 *
 *   _______________Sep_______________
 *
 *   Sun  Mon  Tue  Wed  Thu  Fri  Sat
 *    1    2    3    4    5    6    7
 *    8    9   10   11   12   13   14
 *   15   16   17   18   19   20   21
 *   22   23   24   25   26   27   28
 *   29   30
 *   _________________________________
 */

#include <iostream>

using namespace std;

/**
 * @brief Reads a year from the user.
 * @return The year entered by the user.
 */
short ReadYear() {
    short Year = 0;
    cout << "Please enter a Year? ";
    cin >> Year;
    return Year;
}

/**
 * @brief Reads a month from the user.
 * @return The month entered by the user.
 */
short ReadMonth() {
    short Month = 0;
    cout << "Please Enter a Month? ";
    cin >> Month;
    return Month;
}

string MonthName(short MonthNumber) {
    string arrMonths[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

    return arrMonths[MonthNumber - 1];
}

/**
 * @brief Determines if a year is a leap year (one line of code).
 *
 * A year is a leap year if:
 * - It is divisible by 400, OR
 * - It is divisible by 4 but not divisible by 100.
 *
 * @param Year The year to check.
 * @return True if the year is a leap year, otherwise false.
 */
bool IsLeapYear(short Year) {
    return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}

/**
 * @brief Gets the number of days in a given month and year (short logic).
 *
 * Uses a fixed array of month lengths and adjusts for February
 * if the year is a leap year.
 *
 * @param Month The month number (1–12).
 * @param Year The year (used for leap year check in February).
 * @return The number of days in the specified month.
 */
short NumberOfDaysInAMonth(short Month, short Year) {

    if (Month <= 0 || Month > 12)
        return 0;

    short arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : arr[Month - 1];

}

/**
 * @brief Gregorian Calendar formula to calculate day of the week.
 *
 * Uses Zeller’s congruence to compute day order:
 * 0 = Sunday, 1 = Monday, …, 6 = Saturday
 *
 * @param Day   Day of the month.
 * @param Month Month (1–12).
 * @param Year  Full year.
 * @return Day order (0–6).
 */
short GregorianCalendar(short Day, short Month, short Year) {

    int a = (14 - Month) / 12;
    int y = Year - a;
    int m = Month + 12 * a - 2;

    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

/**
 * @brief Prints the calendar for a given month and year.
 * @param Month The month number (1–12).
 * @param Year The year.
 */
void PrintMonthCalendar(short Month, short Year) {
    
    short Current = GregorianCalendar(1, Month, Year);
   short NumberOfDays = NumberOfDaysInAMonth(Month, Year);

   printf("\n  _______________%s_______________\n\n",
        MonthName(Month).c_str());

    printf ("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    short i;
    for (i = 0; i < Current; i++) {
        printf("     ");
    }

    for (int j = 1; j <= NumberOfDays; j++) {
        printf("%5d", j);

        if (++i == 7) {
            i = 0;
            printf("\n");
        }
    }
    printf("\n  _________________________________\n");
}


int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();
    
    PrintMonthCalendar(Month, Year);

    cout << endl;
    
    return 0;
}