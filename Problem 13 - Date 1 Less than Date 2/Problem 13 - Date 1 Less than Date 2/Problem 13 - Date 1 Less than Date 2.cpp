/**
 * @brief Check if one date is earlier than another.
 *
 * The program:
 * 1. Reads two full dates (day, month, year).
 * 2. Compares them chronologically.
 * 3. Prints whether Date1 < Date2.
 *
 * Example:
 * Input:  Date1 = 5/1/2023, Date2 = 10/1/2023
 * Output: Yes, Date 1 is Less than Date 2
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
 * @brief Checks if Date1 is earlier than Date2.
 * @param Date1 The first date.
 * @param Date2 The second date.
 * @return True if Date1 < Date2, otherwise false.
 */
bool IsDate1LessThanDate2(stDate Date1, stDate Date2) {
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

int main()
{

    stDate Date1 = ReadFullDate();
    cout << endl << endl;
    stDate Date2 = ReadFullDate();
    
    if (IsDate1LessThanDate2(Date1, Date2))
        cout << "\nYes, Date 1 is Less than Date 2\n";
    else
        cout << "\nNo, Date 1 is Not Less than Date 2\n";

    return 0;
}