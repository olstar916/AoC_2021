#include <iostream>
// to read file inputs ifstream does cause errors for some reason
#include <fstream> 
// for casting string to int
# include <sstream>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::stringstream;
using std::stoi;

int main() {
    //How many triple measurements from the input file are larger than their predecessor triple
    stringstream ss;
    string line;
    ifstream myInputFile("sonar_sweep_input.txt");
    int counter = 0;
    if (myInputFile.is_open()) {
        bool beginChecks = false;
        int startup = 0;
        int firstDepth = 0;
        int secondDepth = 0;
        int thirdDepth = 0;
        int fourthDepth = 0;

        int currentTriple;
        int nextTriple;

        while (getline(myInputFile, line)) {
            fourthDepth = stoi(line);
            if (startup < 4){
                switch (startup){
                    // durchlaueft immer die cases, aber der niedrigste bleibt unveraendert startup wird alle 4 mal getroffen
                    case 0: firstDepth = stoi(line);
                    case 1: secondDepth = stoi(line);
                    case 2: thirdDepth = stoi(line);
                    case 3: fourthDepth = stoi(line);
                    startup++;
                    if (startup == 4){
                        beginChecks = true;
                    }
                }
            }
            if (beginChecks){
                currentTriple = firstDepth + secondDepth + thirdDepth;
                nextTriple = secondDepth + thirdDepth + fourthDepth;
                if (currentTriple < nextTriple){
                    counter = counter + 1;
                    cout << "counter: " << counter << endl;
                }
                firstDepth = secondDepth;
                secondDepth = thirdDepth;
                thirdDepth = fourthDepth;
            }
        }
    }
    cout << "counter: " << counter << endl;
    return 0;
}