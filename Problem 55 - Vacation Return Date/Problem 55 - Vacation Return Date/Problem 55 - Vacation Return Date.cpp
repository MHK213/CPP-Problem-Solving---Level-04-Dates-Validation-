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
 * @brief Checks if a date falls on a weekend (Friday or Saturday).
 * @param Date The date to check.
 * @return true if the date is Friday or Saturday, false otherwise.
 */
bool IsWeekEnd(stDate Date) {
    return (GregorianCalendar(Date) == 5 || GregorianCalendar(Date) == 6);
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
 * @return The new date incremented by one day.
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
 * @brief Reads the number of vacation days from the user.
 * @return The number of vacation days entered.
 */
short ReadVacationDays() {
    short VacationDays = 0;

    cout << "\nPlease enter vacation days? ";
    cin >> VacationDays;

    return VacationDays;
}

/**
 * @brief Calculates the vacation return date.
 *
 * The function counts down vacation days while skipping weekends.
 * Once vacation days are used up, it adjusts the return date forward
 * to the next weekday if it falls on a weekend.
 *
 * @param FromDate      The vacation start date.
 * @param VacationDays  The number of vacation days.
 * @return The date when the vacation ends (return date).
 */
stDate CalculateVacationReturnDate(stDate FromDate, short VacationDays) {
    while (VacationDays > 0) {
        if (!IsWeekEnd(FromDate))
            VacationDays--;

        FromDate = IncreaseDateByOneDay(FromDate);
    }

    while (IsWeekEnd(FromDate)) {
        FromDate = IncreaseDateByOneDay(FromDate);
    }

    return FromDate;
}

int main()
{

    cout << "Vacation Starts:\n";
    stDate StartDate = ReadFullDate();

    short VacationDays = ReadVacationDays();

    stDate ReturnDate = CalculateVacationReturnDate(StartDate, VacationDays);

    cout << "\nReturn Date : " << DayName(GregorianCalendar(ReturnDate)) << " , " << ReturnDate.Day << "/" << ReturnDate.Month << "/" << ReturnDate.Year << endl;

    return 0;
}