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

  set<string> wordSet;
  vector<string> wordVector;
  map<string, string> wordmap;
  string previous="";
  string wordstring;
  string state = "";
  srand(time(NULL));

  // read the input file into a string
  while ( inputFile.peek() != EOF ) {
    inputFile >> wordstring;
    //remove punctuation
    for(int i=0; i < wordstring.length(); i++)
    {
      if(ispunct(wordstring[i]))
      wordstring.erase(i,1);
    }
    //change to all lowercase
    for (int i = 0; i < wordstring.size(); i++)
    {
      wordstring[i] = tolower(wordstring[i]);
    }

  //PART 1
  wordSet.insert(wordstring);

  //PART 2
  wordVector.push_back(wordstring);

  //PART 3
  wordmap[previous] = wordstring;
  previous = wordstring;

}

// open an output file for part 1
ofstream outputFile1;
outputFile1.open("output1.txt", ofstream::out);
for (string s : wordSet)
{
 outputFile1 << s << endl;
}
outputFile1.close();

// open an output file for part 2
ofstream outputFile2;
outputFile2.open("output2.txt", ofstream::out);
for (string s : wordVector)
{
 outputFile2 << s << endl;
}
outputFile2.close();

// open an output file for part 3
ofstream outputFile3;
outputFile3.open("output3.txt", ofstream::out);
map<string, string>::iterator filemap;
for (filemap = wordmap.begin(); filemap != wordmap.end(); filemap++)
{
 outputFile3 << filemap->first << ", " << filemap->second << endl;
}
outputFile3.close();





cout << endl << "Part 4: " << endl;
for (int i = 0; i < 100; i++)
{
  cout << wordmap[state] << " ";
  state = wordmap[state];
}

cout << endl << endl << "Part 5: " << endl;
map< string, vector<string> > wordmap2;
string state2 = "";
for (vector<string>::iterator it=wordVector.begin(); it!=wordVector.end(); it++)
{
  wordmap2[state2].push_back(*it);
  state2 = *it;
}
vector<string>::iterator it=wordVector.begin();
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

cout << endl << endl << "Part 6: " << endl;
map< list<string>, vector<string> > wordmap3;
list<string> state3;
for (int i = 0; i < 2; i++)
state3.push_back("");

for (vector<string>::iterator it2=wordVector.begin(); it2!=wordVector.end(); it2++)
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

cout << endl << endl;
cout << "Words in this set: " << wordSet.size() << endl;
cout << "Words in this vector: " << wordVector.size() << endl;
cout << "Keys in this map: " << wordmap.size() << endl;

inputFile.close();

return 0;
}
