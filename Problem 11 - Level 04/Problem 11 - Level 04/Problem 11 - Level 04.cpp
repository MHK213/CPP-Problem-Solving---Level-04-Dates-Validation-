/**
 * @brief Convert between date and day order in a year.
 *
 * This program:
 * 1. Reads a date (day, month, year) from the user.
 * 2. Calculates the number of days from January 1st up to that date.
 * 3. Converts the calculated day order back into a full date.
 *
 * Features:
 * - Leap years handled correctly (29 days in February).
 * - Supports bidirectional conversion between date and day order.
 *
 * Example:
 * Input:  15/3/2024
 * Output: Day order = 75
 *         Date for day order 75 = 15/3/2024
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
 * @brief Checks if a given year is a leap year.
 * @param Year The year to check.
 * @return True if the year is a leap year, otherwise false.
 */
bool IsLeapYear(short Year) {
    return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}

/**
 * @brief Gets the number of days in a given month.
 * @param Month The month (1–12).
 * @param Year The year (to check leap year for February).
 * @return The number of days in the month.
 */
short NumberOfDaysInAMonth(short Month, short Year) {

    if (Month <= 0 || Month > 12)
        return 0;

    short arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : arr[Month - 1];

}

/**
 * @brief Calculates the number of days elapsed since Jan 1 of the given year.
 * @param Day The day of the month.
 * @param Month The month (1–12).
 * @param Year The year.
 * @return The number of days from January 1st up to the given date.
 */
short NumberOfDaysFromTheBeginningOfTheYear(short Day, short Month, short Year) {
    short NumberOfDays = 0;

    for (short i = 1; i < Month; i++) {
        NumberOfDays += NumberOfDaysInAMonth(i, Year);
    }

    NumberOfDays += Day;

    return NumberOfDays;
}

/**
 * @brief Converts a day order in a year back to a full date.
 *
 * Example: Day order = 75, Year = 2024 -> 15/3/2024
 *
 * @param DayOrder The day number (1–365 or 366).
 * @param Year The year.
 * @return A date (day, month, year).
 */
stDate DateFromDayOrderInAYear(short RemainingDays, short Year) {
    
    stDate Date;

    Date.Year = Year;
    Date.Month = 1;
    Date.Day = 0;

    while (true) {

        short NumberOfDays = NumberOfDaysInAMonth(Date.Month, Year);

        if (RemainingDays >= NumberOfDays) {
            RemainingDays -= NumberOfDays;
            Date.Month++;
        }
        else {
            Date.Day = RemainingDays;
            break;
        }
    }

    return Date;

}

int main()
{
    short Day = ReadDay();
    short Month = ReadMonth();
    short Year = ReadYear();

    short NumberOfDays = NumberOfDaysFromTheBeginningOfTheYear(Day, Month, Year);

    cout << "Number Of Days From The Beginnig Of The Year is " << NumberOfDays << endl;

    stDate Date;
    Date = DateFromDayOrderInAYear(NumberOfDays, Year);
    
    cout << "Date for [" << NumberOfDays << "] is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;;

    return 0;
}