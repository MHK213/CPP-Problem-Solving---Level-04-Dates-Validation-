/**
 * @brief Program to calculate the length of a period (number of days) between two dates.
 *
 * The program reads two dates representing a period (start and end), then calculates
 * the difference in days between them. It supports leap years, month boundaries,
 * and includes an option to count the end date in the result.
 *
 * Key Concepts:
 * - Date representation using structures.
 * - Incrementing dates correctly considering leap years.
 * - Calculating differences between two dates.
 * - Optional inclusion of the end day in the result.
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
 * @brief Increases a date by one day.
 * @param Date The current date.
 * @return The updated date.
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

int main()
{

    cout << "Enter Period 1:\n";
    stPeriod Period1 = ReadPeriod();

    cout << "\nPeriod Length is: " << PeriodLengthInDays(Period1);
    cout << "\nPeriod Length (Including End Date) is: " << PeriodLengthInDays(Period1, true) << endl;

    return 0;
}