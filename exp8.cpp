#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main() {
    // Input and output file names
    string inputFileName = "input.txt";
    string outputFileName = "output.txt";

    // Input and output file streams
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    // Check if files are open
    if (!inputFile.is_open()) {
        cerr << "Error opening input file!" << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cerr << "Error opening output file!" << endl;
        return 1;
    }

    char ch;
    while (inputFile.get(ch)) {
        // Check if the character is not a whitespace character
        if (!isspace(static_cast<unsigned char>(ch))) {
            outputFile.put(ch);
        }
    }

    // Close the files
    inputFile.close();
    outputFile.close();

    cout << "Whitespace characters removed and contents saved to " << outputFileName << endl;

    return 0;
}
