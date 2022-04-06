
#include"hexRead.h"

void Hex::fileProcess(string filename){

    std::ifstream file(filename);
    std::string line;

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

    ss >> operation >> operand1 >> operand2 >> operand3;

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
        throw runtime_error("Invalid operation");
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



void Hex::add(string Rd, string Rn, string Rm){

    uint32_t operand1 = *RegPtr(Rn);

    uint32_t operand2 = *RegPtr(Rm);

    uint32_t* result = RegPtr(Rd);

    *result = operand1 + operand2;

    cout << "ADD " << Rd << ", " << Rn << ", " << Rm << "\n" << 
    hex << "The ADD of Ox" << operand1 << " and Ox" << operand2 << " is Ox" << *result << endl;
}



void Hex::Aand(string Rd, string Rn, string Rm){

    uint32_t operand1 = *RegPtr(Rn);

    uint32_t operand2 = *RegPtr(Rm);

    uint32_t* result = RegPtr(Rd);

    *result = operand1 & operand2;

    cout << "AND " << Rd << ", " << Rn << ", " << Rm << "\n" << 
    hex << "The AND of Ox" << operand1 << " and Ox" << operand2 << " is Ox" << *result << endl;
}


void Hex::asr(string Rd, string Rn){
    
}

void Hex::lsr(string Rd, string Rn){

    uint32_t operand1 = *RegPtr(Rn);

    uint32_t* result = RegPtr(Rd);

    *result = operand1 >> 1;

    cout << "LSR " << Rd << ", " << Rn << "\n" << 
    hex << "The LSR of Ox" << operand1 << " is Ox" << *result << endl;
}


void Hex::lsl(string Rd, string Rn){

     uint32_t operand1 = *RegPtr(Rn);

    uint32_t* result = RegPtr(Rd);

    *result = operand1 << 1;

    cout << "LSL " << Rd << ", " << Rn << "\n" << 
    hex << "The LSL of Ox" << operand1 << " is Ox" << *result << endl;

}
void Hex::orr(string Rd, string Rn, string Rm){

    uint32_t operand1 = *RegPtr(Rn);

    uint32_t operand2 = *RegPtr(Rm);

    uint32_t* result = RegPtr(Rd);

    *result = operand1 | operand2;

    cout << "OR " << Rd << ", " << Rn << ", " << Rm << "\n" << 
    hex << "The OR of Ox" << operand1 << " and Ox" << operand2 << " is Ox" << *result << endl;
}
    
void Hex::sub(string Rd, string Rn, string Rm){

    uint32_t operand1 = *RegPtr(Rn);

    uint32_t operand2 = *RegPtr(Rm);

    uint32_t* result = RegPtr(Rd);

    *result = operand1 - operand2;

    cout << "SUB " << Rd << ", " << Rn << ", " << Rm << "\n" << 
    hex << "The SUB of Ox" << operand1 << " and Ox" << operand2 << " is Ox" << *result << endl;
}


void Hex::xorR(string Rd, string Rn, string Rm){

    uint32_t operand1 = *RegPtr(Rn);

    uint32_t operand2 = *RegPtr(Rm);

    uint32_t* result = RegPtr(Rd);

    *result = operand1 ^ operand2;

    cout << "XOR " << Rd << ", " << Rn << ", " << Rm << "\n" << 
    hex << "The XOR of Ox" << operand1 << " and Ox" << operand2 << " is Ox" << *result << endl;
}


uint32_t Hex::immediateInt(string Immediate){
    std::string remove = Immediate.substr(1, std::string::npos);

    return std::stoul(remove, nullptr, 16);
}

void Hex::mov(string Rd, string Immediate){

    uint32_t* result = RegPtr(Rd);

    *result = immediateInt(Immediate);

    std::cout << "MOV " << Rd << ", " << Immediate << "\n" <<
    hex << "The result of MOV is 0x" <<  *result << endl;
}