#include<iostream>
#include <string>
#include <sstream>
#include<fstream>
#include "hexRead.h"

using namespace std;


int main(){

    std::string filename;

    std::ifstream inFile("hex.txt"); //open the txt file

    if(!inFile){
        std::cerr << "Can not open the file!" << std::endl; // send an error message
    }

    Hex hex; //Instantiate the class

    hex.fileProcess(filename);

    inFile.close();
    
    return 0;

}