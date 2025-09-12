/**
 * @brief Program to check if a given date falls within a specified period.
 *
 * The program reads a period (start and end dates) and another date,
 * then determines if the date lies strictly inside the period.
 *
 * Key Concepts:
 * - Date comparison (before, equal, after).
 * - Using an enum for clearer comparison results.
 * - Validating whether a date is inside a given interval.
 */

#include <iostream>

using namespace std;

/**
 * @enum enCompareDate
 * @brief Represents the comparison result between two dates.
 */
enum enCompareDate { Before = -1, Equal = 0, After = 1 };

/**
 * @struct stDate
 * @brief Represents a calendar date.
 */
struct stDate {
    short Day, Month, Year;
};

/**
 * @struct stPeriod
 * @brief Represents a date interval with start and end dates.
 */
struct stPeriod {
    stDate StartDate;
    stDate EndDate;
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
 * @brief Reads a time period (start and end dates).
 * @return A period structure with both dates set.
 */
stPeriod ReadPeriod() {

    stPeriod Period;

    cout << "\nEnter Start Date :\n";
    Period.StartDate = ReadFullDate();

    cout << "\nEnter End Date :\n";
    Period.EndDate = ReadFullDate();

    return Period;
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

/**
 * @brief Checks if a given date is within a period.
 *
 * A date is considered inside the period if:
 * - It is strictly after the start date, and
 * - It is strictly before the end date.
 *
 * @param Period The date interval.
 * @param Date The date to check.
 * @return True if the date lies within the period, false otherwise.
 */
bool IsDateInPeriod(stPeriod Period, stDate Date) {

    return (CompareDates(Period.StartDate, Date) == Before && CompareDates(Period.EndDate, Date) == After);
}

int main()
{

    cout << "Enter Period 1:\n";
    stPeriod Period = ReadPeriod();

    cout << "\nEnter Date to Check:\n";
    stDate Date = ReadFullDate();

    if (IsDateInPeriod(Period, Date))
        cout << "\nYes, Date is Within Period\n";
    else
        cout << "\nNo, Date is Not Within Period\n";

    return 0;
}