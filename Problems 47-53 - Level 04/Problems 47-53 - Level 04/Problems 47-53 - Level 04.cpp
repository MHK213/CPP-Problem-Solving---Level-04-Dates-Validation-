#pragma warning (disable : 4996)

#include <iostream>
#include <ctime>

using namespace std;

/**
 * @struct stDate
 * @brief Represents a calendar date.
 */
struct stDate {
    short Day, Month, Year;
};

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
 * @brief Gets the current system date.
 */
stDate GetSystemDate() {

    stDate Date;

    time_t t = time(0);
    tm* now = localtime(&t);

    Date.Year = now->tm_year + 1900;
    Date.Month = now->tm_mon + 1;
    Date.Day = now->tm_mday;

    return Date;
}

/**
 * @brief Gregorian Calendar formula to calculate day of the week.
 *
 * Uses Zeller’s congruence to compute day order:
 * 0 = Sunday, 1 = Monday, …, 6 = Saturday
 *
 * @param Day   Day of the month.
 * @param Month Month (1–12).
 * @param Year  Full year.
 * @return Day order (0–6).
 */
short GregorianCalendar(short Day, short Month, short Year) {

    int a = (14 - Month) / 12;
    int y = Year - a;
    int m = Month + 12 * a - 2;

    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

/**
 * @brief Overload: Calculates the day of the week for a date structure.
 * @param Date The date.
 * @return The day order (0–6).
 */
short GregorianCalendar(stDate Date) {

    return GregorianCalendar(Date.Day, Date.Month, Date.Year);
}

/**
 * @brief Converts a day number to its corresponding weekday name.
 *
 * @param DayNumber Day order (0–6).
 * @return The name of the day (Sunday–Saturday).
 */
string DayName(short DayNumber) {
    string arrDaysOfWeek[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

    return arrDaysOfWeek[DayNumber];
}

/**
 * @brief Checks if a date is the end of the week (Saturday).
 * @param Date The date to check.
 * @return true if the date is Saturday, false otherwise.
 */
bool IsEndOfWeek(stDate Date) {
    return GregorianCalendar(Date) == 6;
}

/**
 * @brief Checks if a date falls on a weekend (Friday or Saturday).
 * @param Date The date to check.
 * @return true if the date is Friday or Saturday, false otherwise.
 */
bool IsWeekEnd(stDate Date) {
    return (GregorianCalendar(Date) == 5 || GregorianCalendar(Date) == 6);
}

/**
 * @brief Checks if a date is a business day (Sunday–Thursday).
 * @param Date The date to check.
 * @return true if the date is a business day, false otherwise.
 */
bool IsBusinessDay(stDate Date) {
    return (!IsWeekEnd(Date));
}

/**
 * @brief Calculates the number of days remaining until the end of the week.
 * @param Date The date.
 * @return Number of days left until Saturday.
 */
short DaysUntilTheEndOfWeek(stDate Date) {
    return 6 - GregorianCalendar(Date);
}

/**
 * @brief Calculates the number of days remaining until the end of the month.
 * @param Date The date.
 * @return Number of days left until the last day of the month.
 */
short DaysUntilTheEndOfMonth(stDate Date) {
    return NumberOfDaysInAMonth(Date.Month, Date.Year) - Date.Day;
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
 * @brief Calculates the number of days remaining until the end of the year.
 * @param Date The date.
 * @return Number of days left until December 31st of the same year.
 */
short DaysUntilTheEndOfYear(stDate Date) {
    short YearDays = (IsLeapYear(Date.Year)) ? 366 : 365;
    return YearDays - NumberOfDaysFromTheBeginningOfTheYear(Date.Day, Date.Month, Date.Year);
    
}

int main()
{
    
    stDate Date = GetSystemDate();

    cout << "Today is " << DayName(GregorianCalendar(Date)) << " , " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    cout << "\nIs It End Of Week?\n";
    if (IsEndOfWeek(Date))
        cout << "Yes, It is End of Week.\n";
    else
        cout << "No, Not End of Week.\n";

    cout << "\nIs It WeekEnd?\n";
    if (IsWeekEnd(Date))
        cout << "Yes, It is a WeekEnd.\n";
    else
        cout << "No, Not a WeekEnd.\n";

    cout << "\nIs It Business Day?\n";
    if (IsBusinessDay(Date))
        cout << "Yes, It is a Business Day.\n";
    else
        cout << "No, Not a Business Day.\n";

    cout << "\nDays Until end of week : " << DaysUntilTheEndOfWeek(Date) << " Day(s)";
    cout << "\nDays Until end of Month : " << DaysUntilTheEndOfMonth(Date) << " Day(s)";
    cout << "\nDays Until end of Year : " << DaysUntilTheEndOfYear(Date) << " Day(s)" << endl;

    return 0;
}