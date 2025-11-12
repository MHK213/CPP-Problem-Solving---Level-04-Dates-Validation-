# C++ Problem Solving - Level 04 (Dates & Validation)

This repository contains **65 fully-documented C++ problems** from **Level 04** of my problem-solving journey.  
The focus of this level is **Dates, Validation, and String Manipulation** — solving common real-world problems using structured and reusable code.

---

## Topics Covered
-  Date Structures (`stDate`, `stPeriod`)  
-  Leap Year Checks  
-  Date Validation  
-  Date Comparisons (Before, Equal, After)  
-  Period Overlap & Days Counting  
-  String Manipulation (`SplitString`, `ReplaceWordInString`)  
-  Formatting Dates with Custom Patterns  
-  Console Input / Output Handling  

---


- Each file is a **self-contained C++ solution**.  
- All functions are documented using `@brief`, `@param`, and `@return` tags.  
- Problem descriptions are included at the top of each file.  

---

## Learning Outcomes

 By completing this level, I improved in:
 - Writing clean, documented C++ code
 - Using enums, structs, and functions effectively
 - Mastering date-related algorithms
 - Building reusable utility functions

## Example Problem

**Problem 65 - Format Date**

```cpp
string FormateDate(stDate Date, string DateFormat = "dd/mm/yyyy") {
    string FormattedDateString = DateFormat;
    FormattedDateString = ReplaceWordInString(FormattedDateString, "dd", to_string(Date.Day));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "mm", to_string(Date.Month));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "yyyy", to_string(Date.Year));
    return FormattedDateString;
}

---

---

This repo is part of my learning journey in C++.
⭐ If you like this project, give it a star on GitHub!
