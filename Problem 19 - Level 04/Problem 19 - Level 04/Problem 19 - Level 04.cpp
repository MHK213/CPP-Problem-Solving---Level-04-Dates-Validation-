/**
 * @brief Program to calculate the difference in days between two dates,
 *        returning a negative number if Date1 > Date2.
 *
 * Example:
 *   Date1 = 01/01/2025, Date2 = 05/01/2025 -> Diff = 4
 *   Date1 = 05/01/2025, Date2 = 01/01/2025 -> Diff = -4
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
 * @brief Checks if Date1 is earlier than Date2.
 * @param Date1 The first date.
 * @param Date2 The second date.
 * @return True if Date1 < Date2, otherwise false.
 */
bool IsDate1LessThanDate2(stDate Date1, stDate Date2) {
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
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
 * @brief Swaps two dates (pass by reference).
 */
void SwapDates(stDate& Date1, stDate& Date2) {
    stDate TempDate;

    TempDate.Year = Date1.Year;
    TempDate.Month = Date1.Month;
    TempDate.Day = Date1.Day;

    Date1.Year = Date2.Year;
    Date1.Month = Date2.Month;
    Date1.Day = Date2.Day;

    Date2.Year = TempDate.Year;
    Date2.Month = TempDate.Month;
    Date2.Day = TempDate.Day;
}

/**
 * @brief Gets the difference in days (negative if Date1 > Date2).
 *
 * @param Date1 First date
 * @param Date2 Second date
 * @param IncludeEndDay Whether to count the last day
 * @return Signed number of days
 */
short GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false) {

    short Days = 0;
    short SwapFlagValue = 1;

    if (!IsDate1LessThanDate2(Date1, Date2)) {
        SwapDates(Date1, Date2);
        SwapFlagValue = -1;
    }


    while (IsDate1LessThanDate2(Date1, Date2)) {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }

    return (IncludeEndDay == true) ? ++Days * SwapFlagValue : Days * SwapFlagValue;

}

int main()
{

    stDate Date1 = ReadFullDate();
    cout << endl;
    stDate Date2 = ReadFullDate();


    cout << "\nDifference is : " << GetDifferenceInDays(Date1, Date2) << " Days(s)" << endl;
    cout << "\nDifference (Inculding End Day) is : " << GetDifferenceInDays(Date1, Date2, true) << " Days(s)" << endl;

    return 0;
}