#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

int main(int argc, char *argv[]) {


    if (argc < 2) {
        cout << "Error: No input file provided" << endl;
        return 1;
    }

    // open the input file
    ifstream inputFile;
    inputFile.open(argv[1], ifstream::in);

    if ( inputFile.fail() ) {
        cout << "File " << argv[1] << " not found, please try again." 
	<< endl;
        return -1;
    }

    set<string> outString;
    string input;
    // open an output file
    ofstream outputFile;
    outputFile.open("output.txt", ofstream::out);

    // read the input file write it to the output file
/*    while ( inputFile.peek() != EOF ) {
        //getline(inputFile, outString);
        outString.insert(input);
	//outputFile << outString << endl;
	//outputFile.write(outString, "file.txt");
    }
*/
    inputFile.close();
    outputFile.close();

//    cout << "A new file named " << argv[1] 
//	<< "_set.txt has been created."
//	<< endl;

    return 0;
}
