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
    //How many measurements from the input file are larger than their predecessor
    stringstream ss;
    string line;
    ifstream myInputFile("sonar_sweep_input.txt");
    int counter = 0;
    if (myInputFile.is_open()) {
        bool firstValue = true;
        int currentDepth = 0;
        int nextDepth = 0;
        while (getline(myInputFile, line)) {
            if (firstValue){
                currentDepth = stoi(line);
                firstValue = false;
            }
            nextDepth = stoi(line);
            cout << "comparing " << currentDepth << " with " << nextDepth << endl;
            if (currentDepth < nextDepth){
                counter = counter + 1;
                cout << "counter: " << counter << endl;
            }
            currentDepth = nextDepth;
        }
        cout << "last depth" << nextDepth << endl;

    }
    cout << "counter: " << counter << endl;
    return 0;
}