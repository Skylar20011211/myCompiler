#ifndef SYMBOLTABLE_HPP
#define SYMBOLTABLE_HPP
#include <unordered_map>
#include <string>
#include <stack>
#include <vector>
#include <memory>
#include "AST.hpp"
#include "llvm/IR/Instructions.h"

using namespace std;

class SymbolTable {
private:
    unordered_map <string, stack<llvm::AllocaInst*>> table;
    unordered_map<string, stack<vector<AST::Exp*>*>> array;
public:
    void insert(const string* name, llvm::AllocaInst* input, vector<AST::Exp*>* dim);
    void remove(const vector<string*>& removeList);
    llvm::AllocaInst* find(const string* name);
    vector<AST::Exp*>* find_dim(const string* name);
};


#endif //COMPILER_SYMBOLTABLE_HPP