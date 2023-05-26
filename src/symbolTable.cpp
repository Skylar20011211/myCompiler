#include"symbolTable.hpp"
#include"AST.hpp"
using namespace std;
void SymbolTable::insert(const string* name, llvm::AllocaInst* input, vector<AST::Exp*>* dim) {
	auto symbol = table.find(*name);
	auto ar = array.find(*name);
	//table里找到的一定能在array里找到
	if (symbol == table.end()) {
		auto new_stack = stack<llvm::AllocaInst*>();
		new_stack.push(input);
		table.emplace(*name, new_stack);
		auto array_stack = stack<vector<AST::Exp*>*>();
		array_stack.push(dim);
		array.emplace(*name, array_stack);
	}
	else {
		symbol->second.push(input);
		ar->second.push(dim);
	}
}

void SymbolTable::remove(const vector<string*>& removeList) {
	for (auto& str : removeList) {
		auto symbol_map = table.find(*str);
		if (symbol_map->second.size() == 1)table.erase(symbol_map);
		else symbol_map->second.pop();
	}
}

llvm::AllocaInst* SymbolTable::find(const string* name) {
	auto iter = table.find(*name);
	if (iter == table.end()) return nullptr;
	return iter->second.top();
}

vector<AST::Exp*>* SymbolTable::find_dim(const string* name) {
	auto iter = array.find(*name);
	if (iter == array.end()) return nullptr;
	return iter->second.top();
}