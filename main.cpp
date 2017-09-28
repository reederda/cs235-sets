#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <list>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {

    if (argc < 2) {
        cout << "Error: No input file provided" << endl;
        return 1;
    }

/************************ open the input file***********************/
    ifstream inputFile;
    inputFile.open(argv[1], ifstream::in);

    if ( inputFile.fail() ) {
        cout << "File " << argv[1] << " not found, please try again." 
	<< endl;
        return -1;
    }
/*******************************************************************/
   

    set<string> outString;
    vector<string> outVector;
    map<string, string> wordmap;
    string previous="";
    string input;
    string state = "";
    srand(time(NULL));
    // open an output file
    ofstream outputFile;
    outputFile.open("output.txt", ofstream::out);

    // read the input file into a string
    while ( inputFile.peek() != EOF ) {
	inputFile >> input;

    //remove punctuation
    for(int i=0; i < input.length(); i++)
     {
	if(ispunct(input[i]))
	input.erase(i,1);
     }

    //change to all lowercase
	for (int i = 0; i < input.size(); i++)
	{
           input[i] = tolower(input[i]);
	}
	//PART 1
	outString.insert(input);

	for (set<string>::iterator it=outString.begin(); 
	     *it!=*outString.end(); it++)
{
	cout << *it << endl;
	cout << *outString.begin();

	//outputFile << *it << endl;

}	

	//PART 2
	outVector.push_back(input);
	
	//PART 3
	wordmap[previous] = input;
	previous = input;



    
	cout << input << endl;
        //outString.insert(input);
	//outputFile << outString << endl;
	//outputFile.write(outString, "file.txt");
    }


//displays contents of map
/*	int i = 0;
	std::map<string,string>::iterator iters = wordmap.begin();
	while (i < wordmap.size())
{
	cout << (*iters).first << " " << (*iters).second << endl;
	std::advance(iters,1);
	i++;
}
*/

cout << endl << "Part 4: " << endl;
for (int i = 0; i < 100; i++)
{
	cout << wordmap[state] << " ";
	state = wordmap[state];
}
cout << endl;


cout << endl << "Part 5: " << endl;
map< string, vector<string> > wordmap2;
string state2 = "";
for (vector<string>::iterator it=outVector.begin(); it!=outVector.end(); it++)
{
	wordmap2[state2].push_back(*it);
	state2 = *it;

}


vector<string>::iterator it=outVector.begin();
	for (int i = 0; i < 6; i++)
{
	++it;
	if (i = 5)
	{
	for (int j = 0; j < wordmap2[*it].size(); j++)
	{
	cout << wordmap2[*it][j] << " ";
	}
	}
}

cout << endl;

cout << endl << "Part 6: " << endl;
map< list<string>, vector<string> > wordmap3;
list<string> state3;
for (int i = 0; i < 2; i++)
	state3.push_back("");

for (vector<string>::iterator it2=outVector.begin(); it2!=outVector.end(); it2++)
{
	wordmap3[state3].push_back(*it2);
	state3.push_back(*it2);
	state3.pop_front();
}

state3.clear();

for (int i = 0; i < 2; i++)
state3.push_back("");

for (int i = 0; i < 100; i++)
{
	int ind = rand() % wordmap3[state3].size();


	cout << wordmap3[state3][ind] << " ";
	state3.push_back(wordmap3[state3][ind]);
	state3.pop_front();
}
cout << endl;

//    cout << "A new file named " << argv[1] 
//	<< "_set.txt has been created."
//	<< endl;

cout << endl;
cout << "Words in this set: " << outString.size() << endl;
cout << "Words in this vector: " << outVector.size() << endl;
cout << "Keys in this map: " << wordmap.size() << endl;

    inputFile.close();
    outputFile.close();
    return 0;
}
