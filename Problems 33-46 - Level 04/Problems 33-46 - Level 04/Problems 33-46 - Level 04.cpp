/**
 * @brief Decrease Date Problems - Level 04
 *
 * This program provides a set of utilities to manipulate calendar dates
 * by decreasing them by different units of time:
 * - Days
 * - Weeks
 * - Months
 * - Years
 * - Decades
 * - Centuries
 * - Millennia
 *
 * It supports handling leap years, month boundaries, and proper date
 * adjustments while subtracting time units.
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

stDate DecreaseDateByOneDay(stDate Date) {

    if (Date.Day == 1) {
        if (Date.Month == 1) {
            Date.Year--;
            Date.Month = 12;
            Date.Day = 31;
        }
        else {
            Date.Month--;
            Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
        }
    }
    else {
        Date.Day--;
    }

    return Date;
}

stDate DecreaseDateByXDays(stDate Date, int NumberOfDays) {

    for (int i = 0; i < NumberOfDays; i++) {
        Date = DecreaseDateByOneDay(Date);
    }

    return Date;
}

stDate DecreaseDateByOneWeek(stDate Date) {

    Date = DecreaseDateByXDays(Date, 7);

    return Date;
}

stDate DecreaseDateByXWeeks(stDate Date, int NumberOfWeeks) {

    for (int i = 0; i < NumberOfWeeks; i++) {
        Date = DecreaseDateByOneWeek(Date);
    }

    return Date;
}

stDate DecreaseDateByOneMonth(stDate Date) {

    if (Date.Month == 1) {
        Date.Month = 12;
        Date.Year--;
    }
    else {
        Date.Month--;
    }

    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

    if (NumberOfDaysInCurrentMonth < Date.Day)
        Date.Day = NumberOfDaysInCurrentMonth;

    return Date;
}

stDate DecreaseDateByXMonths(stDate Date, int NumberOfMonths) {

    for (int i = 0; i < NumberOfMonths; i++) {
        Date = DecreaseDateByOneMonth(Date);
    }

    return Date;
}

stDate DecreaseDateByOneYear(stDate Date) {

    Date.Year--;
    return Date;
}

stDate DecreaseDateByXYears(stDate Date, int NumberOfYears) {
    for (int i = 0; i < NumberOfYears; i++) {
        Date = DecreaseDateByOneYear(Date);
    }

    return Date;
}

stDate DecreaseDateByXYearsFaster(stDate Date, int NumberOfYears) {

    Date.Year -= NumberOfYears;

    return Date;
}

stDate DecreaseDateByOneDecade(stDate Date) {

    Date = DecreaseDateByXYearsFaster(Date, 10);

    return Date;
}

stDate DecreaseDateByXDecades(stDate Date, int NumberOfDecades) {
    for (int i = 0; i < NumberOfDecades; i++) {
        Date = DecreaseDateByOneDecade(Date);
    }

    return Date;
}

stDate DecreaseDateByXDecadesFaster(stDate Date, int NumberOfDecades) {

    Date.Year -= (NumberOfDecades * 10);

    return Date;
}

stDate DecreaseDateByOneCentury(stDate Date) {

    Date = DecreaseDateByXDecadesFaster(Date, 10);

    return Date;
}

stDate DecreaseDateByOneMillennium(stDate Date) {

    for (int i = 0; i < 10; i++) {
        Date = DecreaseDateByOneCentury(Date);
    }
    return Date;
}

int main()
{

    stDate Date = ReadFullDate();

    Date = DecreaseDateByOneDay(Date);
    cout << "\n01 - Subtraction one day is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    int Number = 10;

    Date = DecreaseDateByXDays(Date, Number);
    cout << "02 - Subtraction " << Number << " day is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    
    Date = DecreaseDateByOneWeek(Date);
    cout << "03 - Subtraction One Week is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    
    Date = DecreaseDateByXWeeks(Date, Number);
    cout << "04 - Subtraction " << Number << " Weeks is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    
    Date = DecreaseDateByOneMonth(Date);
    cout << "05 - Subtraction One Month is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    
    Number = 5;

    Date = DecreaseDateByXMonths(Date, Number);
    cout << "06 - Subtraction " << Number << " Months is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    
    Date = DecreaseDateByOneYear(Date);
    cout << "07 - Subtraction One Year is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    
    Number = 10;

    Date = DecreaseDateByXYears(Date, Number);
    cout << "08 - Subtraction " << Number << " Years is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    
    Date = DecreaseDateByXYearsFaster(Date, Number);
    cout << "09 - Subtraction " << Number << " Years (faster) is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    
    Date = DecreaseDateByOneDecade(Date);
    cout << "10 - Subtraction One Decade is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    
    Date = DecreaseDateByXDecades(Date, Number);
    cout << "11 - Subtraction " << Number << " Decades is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    
    Date = DecreaseDateByXDecadesFaster(Date, Number);
    cout << "12 - Subtraction " << Number << " Decades (faster) is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    
    Date = DecreaseDateByOneCentury(Date);
    cout << "13 - Subtraction One Century is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    
    Date = DecreaseDateByOneMillennium(Date);
    cout << "14 - Subtraction One Millennium is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;


    return 0;
}