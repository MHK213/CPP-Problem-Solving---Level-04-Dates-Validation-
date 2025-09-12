/**
 * @brief Day Name Finder in Gregorian Calendar
 *
 * This program reads a date (day, month, year) from the user
 * and calculates:
 * - The day order (0–6) using Gregorian Calendar formula
 * - The corresponding day name (Sunday–Saturday)
 *
 * Example:
 * Input: 2024-09-04
 * Output:
 *   Date      : 4/9/2024
 *   Day Order : 3
 *   Day Name  : Wednesday
 */

#include <iostream>

using namespace std;

/**
 * @brief Reads a year from the user.
 * @return The year entered by the user.
 */
short ReadYear() {
    short Year = 0;
    cout << "Please enter a Year? ";
    cin >> Year;
    return Year;
}

/**
 * @brief Reads a month from the user.
 * @return The month entered by the user.
 */
short ReadMonth() {
    short Month = 0;
    cout << "Please Enter a Month? ";
    cin >> Month;
    return Month;
}

/**
 * @brief Reads a day from the user.
 * @return The day entered by the user.
 */
short ReadDay() {
    short Day = 0;
    cout << "Please Enter a Day? ";
    cin >> Day;
    return Day;
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
 * @brief Converts a day number to its corresponding weekday name.
 *
 * @param DayNumber Day order (0–6).
 * @return The name of the day (Sunday–Saturday).
 */
string DayName(short DayNumber) {
    string arrDaysOfWeek[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

    return arrDaysOfWeek[DayNumber];
}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();
    short Day = ReadDay();

    short DayNumber = GregorianCalendar(Day, Month, Year);

    cout << "\nDate      : " << Day << "/" << Month << "/" << Year;
    cout << "\nDay Order : " << DayNumber;
    cout << "\nDay Name  : " << DayName(DayNumber) << endl;

    return 0;
}