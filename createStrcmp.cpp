#include <iostream>
#include <string>
using namespace std;

int strcmp_case_insensitive(const string& X, const string& Y, int maxChars = -1)
{
    // edge cases
    if (maxChars == 0) return 0; // If maximum number of characters is zero, strings are equal
    if (maxChars < 0) maxChars = min(static_cast<int>(X.length()), static_cast<int>(Y.length())); // Compare entire strings if maxChars is negative
    
    
    maxChars = min(maxChars, min(static_cast<int>(X.length()), static_cast<int>(Y.length()))); 
    
    // convert both strings to lowercase and compare up to maxChars characters
    string lowerX = X.substr(0, maxChars);
    string lowerY = Y.substr(0, maxChars);
    for (char& c : lowerX)
        c = tolower(c);
    for (char& c : lowerY)
        c = tolower(c);
    
    int i; 
    for (i = 0; i < maxChars; ++i) {
        if (lowerX[i] != lowerY[i])
            return lowerX[i] - lowerY[i];
    }
    
    // If the loop completes without returning, the strings are equal up to maxChars characters
    return X.length() - Y.length();
}

int main()
{
    string str1, str2;
    int maxChars;
    
    cout << "Enter the first string: ";
    getline(cin, str1);
    
    cout << "Enter the second string: ";
    getline(cin, str2);
    
    cout << "Enter the maximum number of characters to compare: ";
    cin >> maxChars;
    
    int result = strcmp_case_insensitive(str1, str2, maxChars);
    if (result < 0)
        cout << "The comparison of \"" << str1 << "\" and \"" << str2 << "\" returns -1." << endl;
    else if (result == 0)
        cout << "The comparison of \"" << str1 << "\" and \"" << str2 << "\" returns 0." << endl;
    else
        cout << "The comparison of \"" << str1 << "\" and \"" << str2 << "\" returns 1." << endl;
    
    return 0;
}
