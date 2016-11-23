#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";

    
    // Declare second integer, double, and String variables.
    int i2;
    double d2;
    string s2;
    // Read and save an integer, double, and String to your variables.
    getline(cin, s2);
    i2 = atoi(s2.c_str());
    getline(cin, s2);
    d2 = atof(s2.c_str());
    getline(cin, s2);
cout << s2 << endl;
    // Print the sum of both integer variables on a new line.
    cout << i + i2 << endl;
    // Print the sum of the double variables on a new line.
    cout.precision(1);
    cout << d + d2 << endl;
    // Concatenate and print the String variables on a new line
    // The 's' variable above should be printed first.
    cout << s + s2 << endl;

}
