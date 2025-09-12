/**
 * @brief Problem 58 - Level 04 : Is Overlap Periods
 *
 * This program checks whether two time periods overlap.
 *
 * Features:
 * - Defines two structures:
 *   - stDate   -> Represents a single calendar date.
 *   - stPeriod -> Represents a time interval (start date, end date).
 * - Provides functions to:
 *   - Compare dates (Before, Equal, After).
 *   - Read single dates and periods from the user.
 *   - Detect if two periods overlap.
 *
 * Logic of overlap:
 * - Two periods overlap unless:
 *   - Period1 ends before Period2 starts, OR
 *   - Period2 ends before Period1 starts.
 *
 * Example:
 * Input:
 *   Period1: 01/01/2025 -> 10/01/2025
 *   Period2: 05/01/2025 -> 15/01/2025
 * Output:
 *   Yes, Periods Overlap
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
 * @brief Checks if two periods overlap.
 *
 * Overlap occurs if:
 * - Period1 does NOT end before Period2 starts,
 * - AND Period2 does NOT end before Period1 starts.
 *
 * @param Period1 The first period.
 * @param Period2 The second period.
 * @return True if periods overlap, otherwise false.
 */
bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2) {
    
    if ((CompareDates(Period1.EndDate, Period2.StartDate) == -1) || (CompareDates(Period2.EndDate, Period1.StartDate) == -1))
        return false;
    else
        return true;
}

int main()
{

    cout << "Enter Period 1:\n";
    stPeriod Period1 = ReadPeriod();

    cout << "\nEnter Period 2:\n";
    stPeriod Period2 = ReadPeriod();

    if (IsOverlapPeriods(Period1, Period2))
        cout << "\nYes, Periods Overlap\n";
    else
        cout << "\nNo, Periods Not Overlap\n";
    
    return 0;
}