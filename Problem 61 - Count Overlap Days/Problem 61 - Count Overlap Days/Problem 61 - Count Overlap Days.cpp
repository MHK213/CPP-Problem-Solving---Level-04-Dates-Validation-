/**
 * @brief Console-based program to calculate the overlap in days between two periods.
 *
 * ## Problem Description:
 * Given two time periods defined by start and end dates, this program determines
 * how many days overlap between them. If the periods do not overlap, the result is zero.
 *
 *  * ## Example:
 * Input:
 *   Period 1: 01/01/2024 -> 10/01/2024
 *   Period 2: 05/01/2024 -> 15/01/2024
 *
 * Output:
 *   Overlap Days Count is : 5
 *
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
 * @brief Checks if the given date is the last day of its month.
 * @param Date The date to check.
 * @return True if it is the last day, otherwise false.
 */
bool IsLastDay(stDate Date) {
    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

/**
 * @brief Checks if the given month is the last month (December).
 * @param Month The month number (1–12).
 * @return True if December, otherwise false.
 */
bool IsLastMonth(short Month) {
    return (Month == 12);
}

/**
 * @brief Increases a given date by one day, adjusting month and year as needed.
 * @param Date The input date.
 * @return The next calendar date.
 */
stDate IncreaseDateByOneDay(stDate Date) {

    if (IsLastDay(Date)) {
        if (IsLastMonth(Date.Month)) {
            Date.Day = 1;
            Date.Month = 1;
            Date.Year++;
        }
        else {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else {
        Date.Day++;
    }

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

/**
 * @brief Gets the difference in days between two dates.
 *
 * @param Date1 Starting date
 * @param Date2 Ending date
 * @param IncludeEndDay Whether to include the last day in the difference
 * @return Number of days between Date1 and Date2
 */
short GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false) {

    short Days = 0;

    while (IsDate1BeforeDate2(Date1, Date2)) {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }

    return (IncludeEndDay == true) ? Days + 1 : Days;
}

/**
 * @brief Calculates the length of a period in days.
 * @param Period A start and end date.
 * @param IncludeEndDay If true, the length includes the end date.
 * @return Length of the period in days.
 */
int PeriodLengthInDays(stPeriod Period, bool IncludeEndDay = false) {
    return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDay);
}

/**
 * @brief Counts how many days overlap between two periods.
 *
 * Algorithm:
 * - If periods do not overlap -> return 0.
 * - Otherwise:
 *   - Choose the shorter period for iteration.
 *   - Traverse day by day, checking if each day exists inside the other period.
 *   - Count and return the number of overlapping days.
 *
 * @param Period1 First period.
 * @param Period2 Second period.
 * @return Number of overlapping days.
 */
int CountOverlapDays(stPeriod Period1, stPeriod Period2) {
    int Period1Length = PeriodLengthInDays(Period1, true);
    int Period2Length = PeriodLengthInDays(Period2, true);
    int OverlapDays = 0;

    if (!IsOverlapPeriods(Period1, Period2))
        return 0;

    if (Period1Length < Period2Length) {
        while (CompareDates(Period1.StartDate, Period1.EndDate) != 1) {
            if (IsDateInPeriod(Period2, Period1.StartDate))
                OverlapDays++;

            Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
        }
    }
    else {
        while (CompareDates(Period2.StartDate, Period2.EndDate) != 1) {
            if (IsDateInPeriod(Period1, Period2.StartDate))
                OverlapDays++;

            Period1.StartDate = IncreaseDateByOneDay(Period2.StartDate);
        }
    }

    return OverlapDays;
}

int main()
{

    cout << "Enter Period 1:\n";
    stPeriod Period1 = ReadPeriod();

    cout << "\nEnter Period 2:\n";
    stPeriod Period2 = ReadPeriod();

    cout << "\nOverlap Days Count is : " << CountOverlapDays(Period1, Period2) << endl;

    return 0;
}