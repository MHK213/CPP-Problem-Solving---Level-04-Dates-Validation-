/**
 * @brief Print a Year Calendar
 *
 * This program reads a year from the user and prints the full calendar
 * (January–December) for that year.
 *
 * Features:
 * - Each month is printed using Zeller’s congruence to align weekdays.
 * - Leap years are handled correctly for February.
 * - Months are displayed sequentially with separators.
 *
 * Example (input = 2024):
 *
 *           Calendar - 2024
 *
 *   _______________Jan_______________
 *
 *   Sun  Mon  Tue  Wed  Thu  Fri  Sat
 *        1    2    3    4    5    6
 *    7    8    9   10   11   12   13
 *   ...
 *   _______________Feb_______________
 *   ...
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
 * @brief Gets the abbreviated name of a month.
 * @param MonthNumber The month number (1–12).
 * @return The 3-letter abbreviation of the month.
 */
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

    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

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

/**
 * @brief Prints the full year calendar.
 * @param Year The year.
 */
void PrintYearCalendar(short Year) {
    printf("\n  _________________________________\n\n");
    printf("           Calendar - %d", Year);
    printf("\n  _________________________________\n");

    for (short i = 1; i <= 12; i++) {
        PrintMonthCalendar(i, Year);
    }
}


int main()
{
    short Year = ReadYear();

    PrintYearCalendar(Year);

    cout << endl;

    return 0;
}