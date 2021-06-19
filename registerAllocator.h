//
// Created by Idan Fischman on 18/06/2021.
//

#ifndef INC_236360_HW5_REGISTERALLOCATION_H
#define INC_236360_HW5_REGISTERALLOCATION_H

#include <string>
#include <sstream>
#include "Types.h"
#include <unordered_map>

using namespace std;

class RegisterAllocator {
private:
    unsigned int counter;
    unordered_map<string, string> varToRegMapping;
    unordered_map<string, string> varToStackMap;
    string getVarStackReg(string var);
public:
    string getNextRegisterName(int increment = 1) {
        this->counter += increment;
        stringstream s1;
        s1 << "%t" << this->counter;
        return s1.str();
    }
    RegisterAllocator() : counter(0) {}
    void createRegister(Node *node, string value, string id);
    string getCurrentRegisterName() {
        return getNextRegisterName(0);
    }
    string createArithmeticCode(Node *left_node, Node *right_node, string op);
    string getVarRegister(string var) {
        return this->varToRegMapping[var];
    }
    void addVariable(int position, const string& varName) {
        stringstream reg;
        reg << "%" << position;
        this->varToRegMapping[varName] = reg.str();
    }
    // returning the register that assigned the cmp
    string emitCmpCode(string left, string right, string op);
    void functionProlog();
    void funcionEpilog();
    string functionGetVarReg(string var);
    void storeVar(string var, string value);
    void loadVar(string var);
};


#endif //INC_236360_HW5_REGISTERALLOCATION_H
