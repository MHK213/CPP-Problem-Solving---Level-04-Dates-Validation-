/**
 * @brief Number to Text Converter in C++
 *
 * This program reads an integer number from the user and converts it
 * into its English word representation using recursion.
 *
 * It handles numbers from 0 up to billions.
 *
 * Example:
 * Input: 12345
 * Output: "Twelve Thousand Three Hundred Forty Five"
 */

#include <iostream>

using namespace std;

/**
 * @brief Reads an integer number from the user.
 * @return The number entered by the user.
 */
int ReadNumber() {
    int Number = 0;

    cout << "Enter a Number? ";
    cin >> Number;

    return Number;
}

/**
 * @brief Converts a number into its English word representation.
 *
 * Handles numbers up to billions using recursion.
 *
 * @param Number Integer number to convert.
 * @return String containing the English representation of the number.
 */
string NumberToText(int Number) {

    if (Number == 0)
        return "";

    if (Number > 0 && Number <= 19) {
        string arr[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eigth", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
            "Fifteen", "Sixteen", "Seventeen", "Eigtheen", "Nineteen"};

        return arr[Number] + " ";
    }

    if (Number >= 20 && Number <= 99) {
        string arr[] = { "", "", "Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eigthy", "Ninety" };

        return arr[Number / 10] + " " + NumberToText(Number % 10);
    }

    if (Number >= 100 && Number <= 199)
        return "One Hundred " + NumberToText(Number % 100);

    if (Number >= 200 && Number <= 999)
        return NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);

    if (Number >= 1000 && Number <= 1999)
        return  "One Thousand " + NumberToText(Number % 1000);

    if (Number >= 2000 && Number <= 999999)
        return  NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);

    if(Number >= 1000000 && Number <= 1999999)
        return "One Million " + NumberToText(Number % 1000000);

    if (Number >= 2000000 && Number <= 9999999)
        return NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);

    if (Number >= 1000000000 && Number <= 1999999999)
        return"One billion " + NumberToText(Number % 1000000000);

    if (Number >= 2000000000)
        return NumberToText(Number / 1000000000) + "billions " + NumberToText(Number % 1000000000);
}

int main()
{
    int Number = ReadNumber();

    cout << NumberToText(Number) << endl;

    return 0;
}