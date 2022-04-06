#ifndef HEXREAD_H
#define HEXREAD_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <bitset>
#include <algorithm>

using namespace std;

class Hex{

private:

    uint32_t r0 = 0;
    uint32_t r1 = 0;
    uint32_t r2 = 0;
    uint32_t r3 = 0;
    uint32_t r4 = 0;
    uint32_t r5 = 0;
    uint32_t r6 = 0;
    uint32_t r7 = 0;

public:
    void fileProcess(string filename);
    void interpret(string line);
    uint32_t* RegPtr(string reg);
    uint32_t immediateInt(string Immediate);

    void add(string Rd, string Rn, string Rm);
    void Aand(string Rd, string Rn, string Rm);
    void asr(string Rd, string Rn);
    void lsr(string Rd, string Rn);
    void lsl(string Rd, string Rn);
    void orr(string Rd, string Rn, string Rm);
    void sub(string Rd, string Rn, string Rm);
    void xorR(string Rd, string Rn, string Rm);
    void mov(string Rd, string Immediate);
};

#endif