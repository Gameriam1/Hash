#include <iostream>
#include <fstream>
#include <unordered_map>
#include <istream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    ifstream namefile("Files/Names.txt");
    ifstream infile("Files/Assignments.txt");

   // infile.open("Files/Assignments.txt");
    vector<string> names;
    vector<string> assignments;
    vector<string> NoDupes;
    unordered_map<string,bool> duplicates;
    string nameline;
    string line;

    while(getline(namefile,nameline)) {

        namefile >> nameline;
        while (!namefile.eof()) { // for names
            string temp;
            namefile >> temp;
            names.push_back(temp);
         //   cout << temp << endl;
        }
    }


    while(getline(infile,line)) {

        infile >>line;
        while (!infile.eof()){
            string temp;
            infile >> temp;
            assignments.push_back(temp);
            //cout << temp << endl;
        }

    }

    for(int i = 0; i <assignments.size(); i++)
    {
        string s(assignments[i]);
        s.erase(remove(s.begin(), s.end(), '_A'), s.end());

        cout <<  s;
        cout << endl;


        if(!duplicates[assignments[i]]){
            NoDupes.push_back(assignments[i]);
            duplicates[assignments[i]] = true;
        }
    }

    for(int i = 0; i <NoDupes.size(); i++){


      //  cout << NoDupes[i]<< endl;
    }

/*
cout << "Names    Missing Assignments";
    for(int k =0;k<names.size(); k++)
    {
        cout << names[k] << "   burgers"  <<endl;
    }
*/
    return 0;
}
