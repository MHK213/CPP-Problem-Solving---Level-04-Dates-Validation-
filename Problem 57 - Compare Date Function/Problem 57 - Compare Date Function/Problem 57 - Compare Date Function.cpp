/**
 * @brief Problem 57 - Level 04 : Compare Dates Function
 *
 * This program compares two dates and determines their order:
 * - Before (-1)  -> Date1 occurs before Date2.
 * - Equal  (0)   -> Both dates are the same.
 * - After  (1)   -> Date1 occurs after Date2.
 *
 * Features:
 * - Reads two dates from the user (day, month, year).
 * - Uses helper functions:
 *   - IsDate1BeforeDate2()
 *   - IsDate1EqualToDate2()
 *   - CompareDates() -> returns an enum value (Before, Equal, After).
 * - Displays the comparison result as an integer.
 *
 * Example:
 * Input:
 *   Date1: 15/9/2025
 *   Date2: 10/9/2025
 * Output:
 *   Compare Result: 1
 */

#include <iostream>

using namespace std;

enum enCompareDate { Before = -1, Equal = 0, After = 1};

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
 * @brief Compares two dates.
 *
 * Logic:
 * - Returns Before (-1) if Date1 < Date2,
 * - Returns Equal  (0) if Date1 == Date2,
 * - Returns After  (1) if Date1 > Date2.
 *
 * @param Date1 The first date.
 * @param Date2 The second date.
 * @return An enum value representing the comparison result.
 */
enCompareDate CompareDates(stDate Date1, stDate Date2) {

    if (IsDate1BeforeDate2(Date1, Date2))
        return Before;
    else if (IsDate1EqualToDate2(Date1, Date2))
        return Equal;
    else
        return After;

}

int main()
{
    cout << "Enter Date 1:\n";
    stDate Date1 = ReadFullDate();

    cout << "\n\nEnter Date 2:\n";
    stDate Date2 = ReadFullDate();

    cout << "\nCompare Result: " << CompareDates(Date1, Date2) << endl;
    return 0;
}