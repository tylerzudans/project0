/*
 *  CSCI 442, Operating Systems, Fall 2019
 *
 *  Project 0
 *  File: part_2.cpp
 *
 *  Author: 
 *      
 */
//*************************************************************************************

#include <iostream>
#include <string.h>
#include <fstream>
#include <getopt.h>
#include <bitset>
#include <vector>

using namespace std;

string aquireText(string fileName){
    vector<int> numbers;
    string output = "";
    try{
        //File IO to Vector
        ifstream numberFile(fileName, ifstream::in);
        if(!numberFile.is_open()){ 
            cout << "Failed to open input file, confirm file name";
            return "";
            }
        string word;
        
        while(numberFile >> word){
            //Add chars to output
            bitset<8> bits = bitset<8>(word);
            char c = char(bits.to_ulong()/2);
            output+=c;


        }
        numberFile.close();
        return output;
        
    }
    catch (const ifstream::failure& e) {
        cout << "Exception opening/reading file, please input a valid file";
        return "";
    }
    return "";
}


int main(int argc, char** argv) {
    try{
        string inputFileName = argv[argc-2];
        string outputFileName = argv[argc-1];
   

    //Implement fullword options later
    string out_text = aquireText(inputFileName);
    if(out_text.empty()) return -1;//if input fails end program
    cout << "Reading From File Name: " << inputFileName << " into " << outputFileName << endl;
    
    //Write to file
    cout << "Writing . . ." << endl;
    ofstream myfile;
    myfile.open (outputFileName);
    if(!myfile.is_open()) cout << "Failed to build output file."<< endl;
    myfile << out_text;
    myfile.close();
    cout << "File Written" << endl;
    return 0;
    }
    catch(const std::out_of_range& e){
        cout << "Incorrect Format. Should look like: part_2 in.txt out.txt";
        return -1;
    }
    
}
