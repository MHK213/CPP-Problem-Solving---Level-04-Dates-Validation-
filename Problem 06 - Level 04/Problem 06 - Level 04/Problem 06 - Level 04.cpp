/**
 * @brief Number of Days in a Month (Short Logic)
 *
 * This program reads a year and a month from the user and calculates
 * the number of days in that month. It uses an array-based approach
 * for simplicity, with a special case for February in leap years.
 *
 * Example:
 * Input: Year = 2024, Month = 2
 * Output: Number Of Days in Month [2024] is 29
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

    short arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : arr[Month - 1];

}

int main() {
    short Year = ReadYear();
    short Month = ReadMonth();

    cout << "Number Of Days in Month [" << Year << "] is " << NumberOfDaysInAMonth(Month, Year) << endl;

    return 0;
}