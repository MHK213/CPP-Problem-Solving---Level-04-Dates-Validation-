/**
 * @brief Leap Year Checker in C++
 *
 * This program reads a year from the user and checks
 * whether it is a leap year or not.
 *
 * A leap year is defined as:
 * - Divisible by 400, OR
 * - Divisible by 4 but not divisible by 100.
 *
 * Example:
 * Input: 2024
 * Output: "Yes, year [2024] is a Leap Year"
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
 * @brief Determines if a year is a leap year.
 *
 * A year is a leap year if:
 * - It is divisible by 400, OR
 * - It is divisible by 4 but not divisible by 100.
 *
 * @param Year The year to check.
 * @return True if the year is a leap year, otherwise false.
 */
bool IsLeapYear(short Year) {
    if (Year % 400 == 0)
        return true;
    else if (Year % 100 != 0)
        return false;
    else if (Year % 4 == 0)
        return true;
    else
        return false;
}

int main()
{
    short Year = ReadYear();

    if (IsLeapYear(Year))
        cout << "\nYes, year [" << Year << "] is a Leap Year\n";
    else
        cout << "\nNo, year [" << Year << "] is Not a Leap Year\n";

    return 0;
}