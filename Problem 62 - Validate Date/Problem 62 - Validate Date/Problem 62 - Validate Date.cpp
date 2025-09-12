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
 * @brief Validates if a given date is a real calendar date.
 *
 * Rules:
 * - Year must be non-negative.
 * - Month must be between 1 and 12.
 * - Day must be between 1 and the maximum allowed in that month/year.
 *
 * @param Date The date to validate.
 * @return True if the date is valid, false otherwise.
 */
bool IsValidDate(stDate Date) {
    return (Date.Year >= 0 && (Date.Month > 0 && Date.Month < 13) && (Date.Day <= NumberOfDaysInAMonth(Date.Month, Date.Year) && Date.Day > 0));
}

int main()
{

    stDate Date = ReadFullDate();

    if (IsValidDate(Date))
        cout << "\nYes, Date is a Valide Date\n";
    else
        cout << "\nNo, Date is Not a Valide Date\n";

	return 0;
}