/**
 * @brief Number of Days, Hours, Minutes, and Seconds in a Month
 *
 * This program reads a year and a month from the user and calculates:
 * - Number of days in the given month
 * - Number of hours in that month
 * - Number of minutes in that month
 * - Number of seconds in that month
 *
 * Leap years are considered for February.
 *
 * Example:
 * Input: Year = 2024, Month = 2
 * Output:
 *   Number Of Days in Month    [2024] is 29
 *   Number Of Hours in Month   [2024] is 696
 *   Number Of Minutes in Month [2024] is 41760
 *   Number Of Seconds in Month [2024] is 2505600
 */

#include <iostream>
using namespace std;

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

/**
 * @brief Reads a year from the user.
 * @return The year entered by the user.
 */
short ReadYear() {
    short Year = 0;
    cout << "Enter a Year to check? ";
    cin >> Year;
    return Year;
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
 * @brief Gets the number of days in a given month and year.
 * @param Month The month number (1–12).
 * @param Year The year (used for leap year check in February).
 * @return The number of days in the specified month.
 */
short NumberOfDaysInAMonth(short Month, short Year) {
    if (Month <= 0 || Month > 12)
        return 0;

    if (Month == 2)
        return IsLeapYear(Year) ? 29 : 28;

    short arr[7] = { 1,3, 5, 7, 8, 10, 12 };
    for (short i : arr) {
        if (Month == i)
            return 31;
    }

    return 30;
}

/**
 * @brief Gets the number of hours in a given month and year.
 * @param Month The month number (1–12).
 * @param Year The year.
 * @return The number of hours in the specified month.
 */
short NumberOfHoursInAMonth(short Month, short Year) {
    return NumberOfDaysInAMonth(Month, Year) * 24;
}

/**
 * @brief Gets the number of minutes in a given month and year.
 * @param Month The month number (1–12).
 * @param Year The year.
 * @return The number of minutes in the specified month.
 */
int NumberOfMinutesInAMonth(short Month, short Year) {
    return NumberOfHoursInAMonth(Month, Year) * 60;
}

/**
 * @brief Gets the number of seconds in a given month and year.
 * @param Month The month number (1–12).
 * @param Year The year.
 * @return The number of seconds in the specified month.
 */
int NumberOfSecondsInAMonth(short Month, short Year) {
    return NumberOfMinutesInAMonth(Month, Year) * 60;
}

int main() {
    short Year = ReadYear();
    short Month = ReadMonth();

    cout << "Number Of Days in Month    [" << Year << "] is " << NumberOfDaysInAMonth(Month, Year) << endl;
    cout << "Number Of Hours in Month   [" << Year << "] is " << NumberOfHoursInAMonth(Month, Year) << endl;
    cout << "Number Of Minutes in Month [" << Year << "] is " << NumberOfMinutesInAMonth(Month, Year) << endl;
    cout << "Number Of Seconds in Month [" << Year << "] is " << NumberOfSecondsInAMonth(Month, Year) << endl;

    return 0;
}