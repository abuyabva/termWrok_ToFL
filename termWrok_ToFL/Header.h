#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;
bool recognaizer(string s);
bool isInDictionary(char c);
void inputAllLexemes(string s);
int findInSeparators(char c);
int findInOfficialWords(string s);
bool isLetter(char letter);//  �����
bool isDigit(char number);//  �����
bool isIdentifier(string s);//  �������������
bool isBinaryNumber(string s);//  ��������
bool isOctalNumber(string s);//  ������������
bool isDecimalNumber(string s);//  ����������
bool isHexadecimalNumber(string s);//  �����������������
bool isIntegerNumber(string s);//  �����
bool isNumericString(string s);//  �������� ������
bool isExponent(string s);//  �������
bool isFloatNumber(string s);//  ��������������
bool isNumber(string s);//  �����
bool isBooleanConstant(string s);//  ���������� ���������
bool isFactor(string s);//  ���������
bool isTerm(string s);//  ���������
bool isOperand(string s);//  �������
bool isExpression(string s);//  ���������
bool isType(string s);//  ���
bool isOperator(string s);
bool isCompound(string s);//  ���������
bool isConditional(string s);//  ��������
bool isFixedCycle(string s);//  ��������������_�����
bool isAssignment(string s);//  ������������
bool isConditionalCycle(string s);//  �������� ����
bool isInput(string s);//  ����
bool isOutput(string s);//  �����
bool isDescription(string s);//  ��������
bool isProgram(string s);//  ��������
bool isInOfficialWords(string s);
int findInIdentifiers(string s);
int findInNumbers(string s);
void inputLexemesFile();
bool identifiersChek();//  �������� ��������
int findIdentifier(string s);
struct Lexeme {
	int numOfTable;
	int numInTable;
	string value;
};
struct IdTable {
	bool described;
	string type;
	string value;
};
struct doubleOperationTable {
	string operation;
	string leftType;
	string rightType;
};
vector <doubleOperationTable> expressionsTable;
vector <IdTable> identifiers;
vector <Lexeme> allLexemes;
vector <string> allNumbers;
vector <string> allIdentifiers;
vector <string> officialWords;
vector <char> separators;