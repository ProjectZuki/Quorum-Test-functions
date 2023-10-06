/// @brief This program counts the number of times each word occurs in a file.
/// @author Willie Alcaraz

#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>
#include <vector>

using namespace std;

int main () {
    // file variables
    ifstream inFile;
    // hard code input file for testing if necessary
    string filename = "input0.txt";

    // loop until file is opened
    while (!inFile.is_open()) {

        cout << filename << endl;
        inFile.open(filename.c_str());
        // prompt if input file failure
        if (!inFile.is_open()) {
            cout << "Error opening file." << endl;
            cout << "Enter filename: ";
            cin >> filename;
        }
        // repeat if necessary
    }

    // input contents of file to map
    map<string, int> wordCount;
    string word;
    while (inFile >> word) {
        wordCount[word]++;
    }

    // output words, along with number of occurences per word
    cout << setw(15) << left << "Word" << setw(15) << "Count" << endl;

    // use iterator for map, iterate through each existing word
    map<string, int>::iterator iter = wordCount.begin();
    while (iter != wordCount.end()) {
        cout << setw(15) << left << iter->first << setw(15) << iter->second << endl;
        iter++;
    }

    // close file
    inFile.close();

    return 0;
}