/**
 * @brief Problem 56 - Level 04 : IsDate1AfterDate2
 *
 * This program compares two dates and checks if the first date (Date1)
 * occurs after the second date (Date2).
 *
 * Features:
 * - Reads two dates from the user (day, month, year).
 * - Compares them using three helper functions:
 *   - IsDate1BeforeDate2()
 *   - IsDate1EqualToDate2()
 *   - IsDate1AfterDate2()
 * - Prints whether Date1 is after Date2.
 *
 * Example:
 * Input:
 *   Date1: 15/9/2025
 *   Date2: 10/9/2025
 * Output:
 *   Yes, Date 1 is After Date 2
 */

#include <iostream>

using namespace std;

/**
 * @struct stDate
 * @brief Represents a calendar date.
 */
struct stDate {
    short Day, Month, Year;
};

/**
 * @brief Reads a day from the user.
 * @return The day entered by the user.
 */
short ReadDay() {
    short Day = 0;

    cout << "Please enter a day? ";
    cin >> Day;

    return Day;
}

/**
 * @brief Reads a month from the user.
 * @return The month entered by the user.
 */
short ReadMonth() {
    short Month = 0;

    cout << "Please enter a month? ";
    cin >> Month;

    return Month;
}

/**
 * @brief Reads a year from the user.
 * @return The year entered by the user.
 */
short ReadYear() {
    short Year = 0;

    cout << "Please enter a year? ";
    cin >> Year;

    return Year;
}

/**
 * @brief Reads a full date (day, month, year).
 * @return A date structure with all values set.
 */
stDate ReadFullDate() {
    stDate Date;

    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
}

/**
 * @brief Checks if Date1 is earlier than Date2.
 * @param Date1 The first date.
 * @param Date2 The second date.
 * @return True if Date1 < Date2, otherwise false.
 */
bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

/**
 * @brief Checks if Date1 is equal to Date2.
 * @param Date1 The first date.
 * @param Date2 The second date.
 * @return True if Date1 == Date2, otherwise false.
 */
bool IsDate1EqualToDate2(stDate Date1, stDate Date2) {
    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

/**
 * @brief Checks if Date1 is after Date2.
 *
 * Implemented as:
 *   NOT (Date1 < Date2 OR Date1 == Date2).
 *
 * @param Date1 The first date.
 * @param Date2 The second date.
 * @return True if Date1 > Date2, otherwise false.
 */
bool IsDate1AfterDate2(stDate Date1, stDate Date2) {
    return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualToDate2(Date1, Date2));
}

int main()
{
    cout << "Enter Date 1:\n";
    stDate Date1 = ReadFullDate();

    cout << "\n\nEnter Date 2:\n";
    stDate Date2 = ReadFullDate();

    if (IsDate1AfterDate2(Date1, Date2))
        cout << "\nYes, Date 1 is After Date 2\n";
    else
        cout << "\nNo, Date 1 is Not After Date 2\n";

    return 0;
}