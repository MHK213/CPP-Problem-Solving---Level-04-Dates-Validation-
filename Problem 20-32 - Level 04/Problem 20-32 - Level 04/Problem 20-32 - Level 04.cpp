/**
 * @brief Demonstrates increasing dates by days, weeks, months, years, decades, centuries, and millennia.
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

stDate IncreaseDateByXDays(stDate Date, int NumberOfDays) {

    for (int i = 0; i < NumberOfDays; i++) {
        Date = IncreaseDateByOneDay(Date);
    }

    return Date;
}

stDate IncreaseDateByOneWeek(stDate Date) {

    Date = IncreaseDateByXDays(Date, 7);

    return Date;
}

stDate IncreaseDateByXWeeks(stDate Date, int NumberOfWeeks) {

    for (int i = 0; i < NumberOfWeeks; i++) {
        Date = IncreaseDateByOneWeek(Date);
    }

    return Date;
}

stDate IncreaseDateByOneMonth(stDate Date) {

    if (IsLastMonth(Date.Month)) {
        Date.Month = 1;
        Date.Year++;
    }
    else {
        Date.Month++;
    }

    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

    if (NumberOfDaysInCurrentMonth < Date.Day)
        Date.Day = NumberOfDaysInCurrentMonth;

    return Date;
}

stDate IncreaseDateByXMonths(stDate Date, int NumberOfMonths) {

    for (int i = 0; i < NumberOfMonths; i++) {
        Date = IncreaseDateByOneMonth(Date);
    }

    return Date;
}

stDate IncreaseDateByOneYear(stDate Date) {

    Date.Year++;
    return Date;
}

stDate IncreaseDateByXYears(stDate Date, int NumberOfYears) {
    for (int i = 0; i < NumberOfYears; i++) {
        Date = IncreaseDateByOneYear(Date);
    }

    return Date;
}

stDate IncreaseDateByXYearsFaster(stDate Date, int NumberOfYears) {

    Date.Year += NumberOfYears;

    return Date;
}

stDate IncreaseDateByOneDecade(stDate Date) {
    
    Date = IncreaseDateByXYearsFaster(Date, 10);

    return Date;
}

stDate IncreaseDateByXDecades(stDate Date, int NumberOfDecades) {
    for (int i = 0; i < NumberOfDecades; i++) {
        Date = IncreaseDateByOneDecade(Date);
    }

    return Date;
}

stDate IncreaseDateByXDecadesFaster(stDate Date, int NumberOfDecades) {

    Date.Year += (NumberOfDecades * 10);

    return Date;
}

stDate IncreaseDateByOneCentury(stDate Date) {

    Date = IncreaseDateByXDecadesFaster(Date, 10);

    return Date;
}

stDate IncreaseDateByOneMillennium(stDate Date) {

    for (int i = 0; i < 10; i++) {
        Date = IncreaseDateByOneCentury(Date);
    }
    return Date;
}

int main()
{

    stDate Date = ReadFullDate();

    Date = IncreaseDateByOneDay(Date);
    cout << "\n01 - adding one day is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    int Number = 10;

    Date = IncreaseDateByXDays(Date, Number);
    cout << "02 - adding " << Number << " day is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByOneWeek(Date);
    cout << "03 - adding One Week is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXWeeks(Date, Number);
    cout << "04 - adding " << Number << " Weeks is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByOneMonth(Date);
    cout << "05 - adding One Month is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Number = 5;

    Date = IncreaseDateByXMonths(Date, Number);
    cout << "06 - adding " << Number << " Months is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByOneYear(Date);
    cout << "07 - adding One Year is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Number = 10;

    Date = IncreaseDateByXYears(Date, Number);
    cout << "08 - adding " << Number << " Years is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXYearsFaster(Date, Number);
    cout << "09 - adding " << Number << " Years (faster) is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByOneDecade(Date);
    cout << "10 - adding One Decade is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXDecades(Date, Number);
    cout << "11 - adding " << Number << " Decades is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXDecadesFaster(Date, Number);
    cout << "12 - adding " << Number << " Decades (faster) is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByOneCentury(Date);
    cout << "13 - adding One Century is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByOneMillennium(Date);
    cout << "14 - adding One Millennium is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;


    return 0;
}