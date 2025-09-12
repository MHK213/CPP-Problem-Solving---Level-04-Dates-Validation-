/***************************************************************
 * Problem 65 - Level 04 : Format Date
 *
 * Description:
 * This program reads a date string in the format "dd/mm/yyyy",
 * converts it into a structured `stDate`, and allows printing
 * the date in multiple formats by replacing placeholders in a
 * format string.
 *
 * Supported placeholders:
 *   - "dd"   -> day
 *   - "mm"   -> month
 *   - "yyyy" -> year
 */

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
 * @brief Replaces all occurrences of a substring inside a string.
 *
 * Example:
 *   ReplaceWordInString("dd/mm/yyyy", "dd", "10")
 *   -> "10/mm/yyyy"
 *
 * @param S1 Original string.
 * @param StringToReplace Substring to search for.
 * @param sReplaceTo Replacement string.
 * @return New string with all replacements applied.
 */
string ReplaceWordInString(string S1, string StringToReplace, string sRepalceTo) {
    short pos = S1.find(StringToReplace);

    while (pos != std::string::npos) {

        S1 = S1.replace(pos, StringToReplace.length(), sRepalceTo);
        pos = S1.find(StringToReplace);
    } 
    return S1;
}

/**
 * @brief Formats a date according to a given format string.
 *
 * Placeholders:
 *   - "dd"   replaced by Date.Day
 *   - "mm"   replaced by Date.Month
 *   - "yyyy" replaced by Date.Year
 *
 * Example:
 *   FormateDate({10,12,2025}, "yyyy-dd-mm") -> "2025-10-12"
 *
 * @param Date The date structure to format.
 * @param DateFormat The format string (default "dd/mm/yyyy").
 * @return Formatted date string.
 */
string FormateDate(stDate Date, string DateFormat = "dd/mm/yyyy") {
    string FormattedDateString = "";
    FormattedDateString = ReplaceWordInString(DateFormat, "dd", to_string(Date.Day));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "mm", to_string(Date.Month));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "yyyy", to_string(Date.Year));
    return  FormattedDateString; }

int main()
{

    string sDate = ReadFullDate();
    stDate Date = StringToDate(sDate, "/");

    cout << "\n" << FormateDate(Date, "dd/mm/yyyy") << endl;
    cout << "\n" << FormateDate(Date, "yyyy/dd/mm") << endl;
    cout << "\n" << FormateDate(Date, "mm/dd/yyyy") << endl;
    cout << "\n" << FormateDate(Date, "mm-dd-yyyy") << endl;
    cout << "\n" << FormateDate(Date, "dd-mm-yyyy") << endl;
    cout << "\n" << FormateDate(Date, "Day:dd, Month:mm, Year:yyyy") << endl;

    return 0;
}