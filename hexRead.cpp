
#include"hexRead.h"


void Hex::fileProcess(string filename){

    std::ifstream file(filename);
    std::string line;

     // Read the file
    while (std::getline(file, line)){ 
    interpret(line);
    }
}
void Hex::interpret(string line){

    std::stringstream ss;
    ss << line;

    string operation;
    string operand1;
    string operand2;
    string operand3;

    //get the variables from the txt file
    ss >> operation >> operand1 >> operand2 >> operand3;

    //choose the operation
    if(operation == "ADD"){
        add(operand1, operand2, operand3);
    }
    else if (operation == "AND"){
        Aand(operand1, operand2, operand3);
    }
    else if (operation == "ASR"){
        asr(operand1, operand2);
    }
    else if (operation == "LSR"){
        lsr(operand1, operand2);
    }
    else if (operation == "LSL"){
        lsl(operand1, operand2);
    }
    else if (operation == "ORR"){
        orr(operand1, operand2, operand3);
    }
    else if (operation == "SUB"){
        sub(operand1, operand2, operand3);
    }
    else if (operation == "XOR"){
        xorR(operand1, operand2, operand3);
    }
    else if (operation == "MOV"){
        mov(operand1, operand2);
    }
    else{
        throw runtime_error("Invalid operation"); //give runtime error if operation is something different
    }

}



uint32_t* Hex::RegPtr(string reg){

    std::transform(reg.begin(), reg.end(), reg.begin(), ::toupper);

    if(reg == "R0"){
        return &r0;
    }
    else if(reg == "R1"){
        return &r1;
    }
    else if(reg == "R2"){
        return &r2;  
    }
    else if(reg == "R3"){
        return &r3;
    }
    else if(reg == "R4"){
        return &r4;
    }
    else if(reg == "R5"){
        return &r5;
    }
    else if(reg == "R6"){
        return &r6;
    }
    else if(reg == "R7"){
        return &r7;
    }
    else{
        throw std::runtime_error("Invalid register");
    }
}

uint32_t Hex::immediateInt(string Immediate){ //Immediate to integer
    std::string remove = Immediate.substr(1, std::string::npos);

    return std::stoul(remove, nullptr, 16);
}


void Hex::add(string Rd, string Rn, string Rm){

    uint32_t operand1 = *RegPtr(Rn); // operand 1

    uint32_t operand2 = *RegPtr(Rm); // operand 2

    uint32_t* result = RegPtr(Rd); // stores the result

    *result = operand1 + operand2; // add operation

    cout << "ADD " << Rd << ", " << Rn << ", " << Rm << "\n" << 
    hex << "The ADD of Ox" << operand1 << " and Ox" << operand2 << " is Ox" << *result << endl;
}



void Hex::Aand(string Rd, string Rn, string Rm){

    uint32_t operand1 = *RegPtr(Rn);

    uint32_t operand2 = *RegPtr(Rm);

    uint32_t* result = RegPtr(Rd);

    *result = operand1 & operand2; // And operation

    cout << "AND " << Rd << ", " << Rn << ", " << Rm << "\n" << 
    hex << "The AND of Ox" << operand1 << " and Ox" << operand2 << " is Ox" << *result << endl;
}


void Hex::asr(string Rd, string Rn){

     uint32_t tempOperand = *RegPtr(Rn);
   
    uint32_t operand1 = tempOperand;
    
    int32_t* toSigned = reinterpret_cast<int32_t*>(&operand1);
    *toSigned = *toSigned >> 1; 

    // make the result unsigned
    uint32_t* tounsigned = reinterpret_cast<uint32_t*>(toSigned);
    
   
    uint32_t* result = RegPtr(Rd); // store result

    *result = *tounsigned;

    cout << "ASR " << Rd << ", " << Rn << "\n" << 
    hex << "The ASR of Ox" << operand1 << " is Ox" << *result << endl;
}

void Hex::lsr(string Rd, string Rn){

    uint32_t operand1 = *RegPtr(Rn);

    uint32_t* result = RegPtr(Rd);

    *result = operand1 >> 1; //Lsr operation

    cout << "LSR " << Rd << ", " << Rn << "\n" << 
    hex << "The LSR of Ox" << operand1 << " is Ox" << *result << endl;
}


void Hex::lsl(string Rd, string Rn){

     uint32_t operand1 = *RegPtr(Rn);

    uint32_t* result = RegPtr(Rd);

    *result = operand1 << 1; //Lsl operation

    cout << "LSL " << Rd << ", " << Rn << "\n" << 
    hex << "The LSL of Ox" << operand1 << " is Ox" << *result << endl;

}
void Hex::orr(string Rd, string Rn, string Rm){

    uint32_t operand1 = *RegPtr(Rn);

    uint32_t operand2 = *RegPtr(Rm);

    uint32_t* result = RegPtr(Rd);

    *result = operand1 | operand2; //Or operation

    cout << "OR " << Rd << ", " << Rn << ", " << Rm << "\n" << 
    hex << "The OR of Ox" << operand1 << " and Ox" << operand2 << " is Ox" << *result << endl;
}
    
void Hex::sub(string Rd, string Rn, string Rm){

    uint32_t operand1 = *RegPtr(Rn);

    uint32_t operand2 = *RegPtr(Rm);

    uint32_t* result = RegPtr(Rd);

    *result = operand1 - operand2; // subtract

    cout << "SUB " << Rd << ", " << Rn << ", " << Rm << "\n" << 
    hex << "The SUB of Ox" << operand1 << " and Ox" << operand2 << " is Ox" << *result << endl;
}


void Hex::xorR(string Rd, string Rn, string Rm){

    uint32_t operand1 = *RegPtr(Rn);

    uint32_t operand2 = *RegPtr(Rm);

    uint32_t* result = RegPtr(Rd);

    *result = operand1 ^ operand2; //xor operation

    cout << "XOR " << Rd << ", " << Rn << ", " << Rm << "\n" << 
    hex << "The XOR of Ox" << operand1 << " and Ox" << operand2 << " is Ox" << *result << endl;
}



void Hex::mov(string Rd, string Immediate){

    uint32_t* result = RegPtr(Rd);

    *result = immediateInt(Immediate); // move the immediate value to the Rd

    std::cout << "MOV " << Rd << ", " << Immediate << "\n" <<
    hex << "The result of MOV is 0x" <<  *result << endl;
}