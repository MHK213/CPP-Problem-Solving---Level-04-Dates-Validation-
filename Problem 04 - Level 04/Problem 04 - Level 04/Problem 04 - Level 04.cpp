/**
 * @brief Number of Days, Hours, Minutes, and Seconds in a Year
 *
 * This program reads a year from the user and calculates:
 * - Number of days in the year
 * - Number of hours in the year
 * - Number of minutes in the year
 * - Number of seconds in the year
 *
 * Leap years are considered in the calculation.
 *
 * Example:
 * Input: 2024
 * Output:
 *   Number Of Days in Year [2024] is 366
 *   Number Of Hours in Year [2024] is 8784
 *   Number Of Minutes in Year [2024] is 527040
 *   Number Of Seconds in Year [2024] is 31622400
 */

#include <iostream>
using namespace std;

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
 * @brief Gets the number of days in a given year.
 * @param Year The year to check.
 * @return 366 if leap year, otherwise 365.
 */
short NumberOfDaysInAYear(short Year) {
    return IsLeapYear(Year) ? 366 : 365;
}

/**
 * @brief Gets the number of hours in a given year.
 * @param Year The year to check.
 * @return Total hours in that year.
 */
short NumberOfHoursInAYear(short Year) {
    return NumberOfDaysInAYear(Year) * 24;
}

/**
 * @brief Gets the number of minutes in a given year.
 * @param Year The year to check.
 * @return Total minutes in that year.
 *
 * */
int NumberOfMinutesInAYear(short Year) {
    return NumberOfHoursInAYear(Year) * 60;
}

/**
 * @brief Gets the number of seconds in a given year.
 * @param Year The year to check.
 * @return Total seconds in that year.
 */
int NumberOfSecondsInAYear(short Year) {
    return NumberOfMinutesInAYear(Year) * 60;
}

int main() {
    short Year = ReadYear();

    cout << "Number Of Days in Year [" << Year << "] is " << NumberOfDaysInAYear(Year) << endl;
    cout << "Number Of Hours in Year [" << Year << "] is " << NumberOfHoursInAYear(Year) << endl;
    cout << "Number Of Minutes in Year [" << Year << "] is " << NumberOfMinutesInAYear(Year) << endl;
    cout << "Number Of Seconds in Year [" << Year << "] is " << NumberOfSecondsInAYear(Year) << endl;

    return 0;
}