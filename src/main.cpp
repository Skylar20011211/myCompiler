#include <cassert>
#include <cstdio>
#include <iostream>
#include <memory>
#include <string>
#include <fstream>
#include"AST.hpp"
#include"CodeGen.hpp"
#include"myFlexer.hpp"

using namespace std;

// ���� lexer ������, �Լ� parser ����
// Ϊʲô������ sysy.tab.hpp ��? ��Ϊ��������û�� yyin �Ķ���
// ���, ��Ϊ����ļ����������Լ�д��, ���Ǳ� Bison ���ɳ�����
// ��Ĵ���༭��/IDE �ܿ����Ҳ�������ļ�, Ȼ�����㱨�� (��Ȼ���벻�����)
// ��������ܷ���, ���Ǹɴ�������ֿ����� dirty ��ʵ�ʺ���Ч���ֶ�

extern FILE* yyin;
extern int yyparse(AST::CompUnit* & Ast,  myFlexer&Flexer);


int main(int argc, const char* argv[]) {
	// ���������в���. ���Խű�/����ƽ̨Ҫ����ı������ܽ������²���:
	// compiler ģʽ �����ļ� -o ����ļ�
	int i;
	for (i = 0; i < argc; i++) {
		std::cout << "argv[" << i << "] = " << argv[i] << std::endl;
	}

	assert(argc == 2);
	auto input = argv[1];
	

  // �������ļ�, ����ָ�� lexer �ڽ�����ʱ���ȡ����ļ�
	ifstream*file=new ifstream(input);
	ifstream*sfile=file;
	myFlexer Flexflexer(sfile);

	// ���� parser ����, parser �������һ������ lexer ���������ļ���
	AST::CompUnit* Ast;
	auto ret = yyparse(Ast,Flexflexer);
	assert(!ret);

	// ��������õ��� AST, ��ʵ���Ǹ��ַ���
	Ast->Dump();

	Gen program_gen;
	program_gen.CompUnitGen(Ast);
}

