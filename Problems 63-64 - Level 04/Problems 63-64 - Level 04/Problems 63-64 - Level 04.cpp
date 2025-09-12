/***************************************************************
 * Problem 63 / 64 - Level 04 : Read / Print Date String
 *
 * Description:
 * This program reads a date in the format "dd/mm/yyyy",
 * parses it into a structured `stDate` type, and prints out
 * both the separated components and the reconstructed string.
 *
 * Key Features:
 *  - Read a full date as a string
 *  - Split string by delimiter
 *  - Convert string -> date structure
 *  - Convert date structure -> string
 ***************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * @struct stDate
 * @brief Represents a calendar date.
 */
struct stDate {
    int Day, Month, Year;
};

/**
 * @brief Reads a full date as a string in the format dd/mm/yyyy.
 *
 * Prompts the user to enter a date and reads it as a single string.
 *
 * @return The entered date string.
 */
string ReadFullDate() {
    string Date = "";

    cout << "Please Enter Date dd/mm/yyyy? ";
    getline(cin >> ws, Date);

    return Date;
}

/**
 * @brief Splits a string into substrings by a given delimiter.
 *
 * Example: SplitString("10/12/2025", "/") -> {"10", "12", "2025"}
 *
 * @param Text The input string.
 * @param delim The delimiter used for splitting.
 * @return Vector of substrings.
 */
vector <string> SplitString(string Text, string delim) {

    vector <string> vString{};
    short pos = 0;
    string sWord;

    while ((pos = Text.find(delim)) != std::string::npos) {
        sWord = Text.substr(0, pos);
        if (sWord != "")
            vString.push_back(sWord);
        Text.erase(0, pos + delim.length());
    }
    if (Text != "")
        vString.push_back(Text);

    return vString;
}

/**
 * @brief Converts a date string into a stDate structure.
 *
 * Example: StringToDate("10/12/2025", "/") -> {10, 12, 2025}
 *
 * @param Text Date string in the format dd/mm/yyyy.
 * @param delim The delimiter used in the date string.
 * @return stDate structure with day, month, year set.
 */
stDate StringToDate(string Text, string delim) {
    vector <string> vDate = SplitString(Text, delim);
    stDate Date;

    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);

    return Date;
}

/**
 * @brief Converts a stDate structure into a string.
 *
 * Example: {10, 12, 2025} -> "10/12/2025"
 *
 * @param Date The date structure.
 * @return The formatted date string.
 */
string DateToString(stDate Date) {
    return to_string(Date.Day) + '/' + to_string(Date.Month) + "/" + to_string(Date.Year);
}

int main()
{

    string sDate = ReadFullDate();
    stDate Date = StringToDate(sDate, "/");

    cout << "\nDay: " << Date.Day;
    cout << "\nMonth: " << Date.Month;
    cout << "\nYear: " << Date.Year << endl;
    
    cout << "\nYou Entered: " << DateToString(Date) << endl;

    return 0;
}