// This program demonstrates various string manipulation operations in C++
// It uses a menu-driven approach and provides detailed comments for each function.

#include <iostream>
#include <string>
#include <algorithm> // For std::reverse, std::transform
#include <cctype>    // For std::toupper, std::tolower
using namespace std;

// Function to calculate the length of a string
int getStringLength(const string& str) {
    // The length() function returns the number of characters in the string
    return str.length();
}

// Function to copy one string to another
string copyString(const string& source) {
    // Simply return the source string (copy constructor is used)
    return source;
}

// Function to concatenate two strings
string concatenateStrings(const string& str1, const string& str2) {
    // The + operator concatenates two strings
    return str1 + str2;
}

// Function to compare two strings
bool compareStrings(const string& str1, const string& str2) {
    // Returns true if strings are equal, false otherwise
    return str1 == str2;
}

// Function to reverse a string
string reverseString(const string& str) {
    string rev = str; // Make a copy
    reverse(rev.begin(), rev.end()); // Use STL reverse
    return rev;
}

// Function to search for a substring in a string
int findSubstring(const string& str, const string& substr) {
    // find() returns the starting index or string::npos if not found
    size_t pos = str.find(substr);
    if (pos != string::npos)
        return static_cast<int>(pos);
    else
        return -1;
}

// Function to replace all occurrences of a character with another
string replaceChar(const string& str, char oldChar, char newChar) {
    string result = str;
    for (size_t i = 0; i < result.length(); ++i) {
        if (result[i] == oldChar)
            result[i] = newChar;
    }
    return result;
}

// Function to convert string to uppercase
string toUpperCase(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

// Function to convert string to lowercase
string toLowerCase(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// Function to count vowels and consonants in a string
void countVowelsConsonants(const string& str, int& vowels, int& consonants) {
    vowels = consonants = 0;
    for (char ch : str) {
        if (isalpha(ch)) {
            char lower = tolower(ch);
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u')
                ++vowels;
            else
                ++consonants;
        }
    }
}

// Function to check if a string is a palindrome
bool isPalindrome(const string& str) {
    int left = 0;
    int right = str.length() - 1;
    while (left < right) {
        // Ignore non-alphanumeric characters and case
        while (left < right && !isalnum(str[left])) ++left;
        while (left < right && !isalnum(str[right])) --right;
        if (tolower(str[left]) != tolower(str[right]))
            return false;
        ++left;
        --right;
    }
    return true;
}

// Function to display the menu
void displayMenu() {
    cout << "\n--- String Manipulation Menu ---\n";
    cout << "1. Calculate string length\n";
    cout << "2. Copy string\n";
    cout << "3. Concatenate strings\n";
    cout << "4. Compare strings\n";
    cout << "5. Reverse string\n";
    cout << "6. Find substring\n";
    cout << "7. Replace character\n";
    cout << "8. Convert to uppercase\n";
    cout << "9. Convert to lowercase\n";
    cout << "10. Count vowels and consonants\n";
    cout << "11. Check palindrome\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    string str1, str2;
    int choice;

    cout << "Enter the main string: ";
    getline(cin, str1);

    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); // Clear newline from input buffer

        switch (choice) {
            case 1: {
                // Calculate string length
                int len = getStringLength(str1);
                cout << "Length of the string: " << len << endl;
                break;
            }
            case 2: {
                // Copy string
                string copy = copyString(str1);
                cout << "Copied string: " << copy << endl;
                break;
            }
            case 3: {
                // Concatenate strings
                cout << "Enter another string to concatenate: ";
                getline(cin, str2);
                string result = concatenateStrings(str1, str2);
                cout << "Concatenated string: " << result << endl;
                break;
            }
            case 4: {
                // Compare strings
                cout << "Enter another string to compare: ";
                getline(cin, str2);
                if (compareStrings(str1, str2))
                    cout << "Strings are equal." << endl;
                else
                    cout << "Strings are not equal." << endl;
                break;
            }
            case 5: {
                // Reverse string
                string rev = reverseString(str1);
                cout << "Reversed string: " << rev << endl;
                break;
            }
            case 6: {
                // Find substring
                cout << "Enter substring to search: ";
                getline(cin, str2);
                int pos = findSubstring(str1, str2);
                if (pos != -1)
                    cout << "Substring found at position: " << pos << endl;
                else
                    cout << "Substring not found." << endl;
                break;
            }
            case 7: {
                // Replace character
                char oldChar, newChar;
                cout << "Enter character to replace: ";
                cin >> oldChar;
                cout << "Enter new character: ";
                cin >> newChar;
                string replaced = replaceChar(str1, oldChar, newChar);
                cout << "String after replacement: " << replaced << endl;
                break;
            }
            case 8: {
                // Convert to uppercase
                string upper = toUpperCase(str1);
                cout << "Uppercase string: " << upper << endl;
                break;
            }
            case 9: {
                // Convert to lowercase
                string lower = toLowerCase(str1);
                cout << "Lowercase string: " << lower << endl;
                break;
            }
            case 10: {
                // Count vowels and consonants
                int vowels, consonants;
                countVowelsConsonants(str1, vowels, consonants);
                cout << "Vowels: " << vowels << ", Consonants: " << consonants << endl;
                break;
            }
            case 11: {
                // Check palindrome
                if (isPalindrome(str1))
                    cout << "The string is a palindrome." << endl;
                else
                    cout << "The string is not a palindrome." << endl;
                break;
            }
            case 0: {
                cout << "Exiting program. Goodbye!" << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    } while (choice != 0);

    return 0;
}



// Here is a comprehensive C++ program for string manipulation.
// It includes a menu-driven interface and many functions for various string operations, such as:

// Length calculation
// Copying
// Concatenation
// Comparison
// Reversal
// Substring search
// Character replacement
// Case conversion
// Counting vowels/consonants
// Palindrome check
