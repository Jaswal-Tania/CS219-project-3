#include<iostream>
#include <string>
#include <sstream>
#include<fstream>
#include "hexRead.h"

using namespace std;


int main(){

    std::string filename;

    std::ifstream inFile("hex.txt"); 

    if(!inFile){
        std::cerr << "Can not open the file!" << std::endl; 
    }


    Hex hex;

    hex.fileProcess(filename);

    inFile.close();
    
    return 0;

}