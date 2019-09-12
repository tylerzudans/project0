/*
 *  CSCI 442, Operating Systems, Fall 2019
 *
 *  Project 0
 *  File: part_1.cpp
 *
 *  Author: 
 *      
 */
//*************************************************************************************

#include <iostream>
#include <string>
#include <errno.h>
#include <fstream>
#include <getopt.h>
#include <vector>
#include <math.h>


using namespace std;

void display_help(){
    cout<<("-o, --output\nOutput the sum value into a file named output_part_1\n\n-h, --help\nDisplay a help message about the program and its flags, then exit\n\n-m, --mod [ARGUMENT]\nA positive integer must follow this flag, which is the integer constant c discussed above")<<endl;
}

void display_invalid(){
    cout<<"Invalid Input:\n Use -h flag for help"<<endl;
}

int aquireSum(string fileName, int c){
    vector<int> numbers;
    try{
        //File IO to Vector
        ifstream numberFile(fileName, ifstream::in);
        if(!numberFile.is_open()){ 
            cout << "Failed to open file, confirm file name";
            return -1;
            }
        string word;
        while(numberFile >> word){//Add numbers in file to vector
            numbers.push_back(stoi(word));
            //cout <<word<<endl;
        }
        numberFile.close();

        //Summation process
        int sum = 0;
        for(int i = 0; i<numbers.size();i++){
            sum+= pow(numbers.at(i),(i%c));
        }
        return sum;
    }
    catch (const ifstream::failure& e) {
        cout << "Exception opening/reading file, please input a valid file";
        return -1;
    }
    return 0;
}


int main(int argc, char** argv) {
    int flags, opt;
    int c = 4;//4 specified as default in project
    string inputFileName = "";
    string OUTPUT_FILE = "output_part_1.txt";
    

    //Implement fullword options later
    static struct option long_options[] = {
        {"help",     no_argument, 0,  'h' },
        {"mod",  required_argument,       0,  'm' },
        {"output",  no_argument, 0,  'o' }
    };
    
    bool console_out = true;
    while ((opt = getopt_long(argc, argv, "ohm:",long_options,NULL)) != -1) {
        switch (opt) {
            case 'o':
                console_out = false;
                cout << "outputting to " << OUTPUT_FILE << endl;
                break;
            case 'h':
                display_help();
                break;
            case 'm':
                //set new modulus with int c
                c = atoi(optarg); 
                break;
            default: /* '?' */
                display_invalid();
                break;
        }
    }
    inputFileName = argv[argc-1];//last arguement is assumed to be text file
    cout << "Reading From File Name: " << inputFileName << endl;
    int sum = aquireSum(inputFileName,c);
    if(console_out){
        cout << "Sum: " << sum <<endl;
    }
    else{
        //Write to file
        cout << "Writing to File . . ." << endl;
        ofstream myfile;
        myfile.open ("output_part_1.txt");
        myfile << sum;
        myfile.close();
        cout << "File Written" << endl;
    }
    return sum;
    
}


