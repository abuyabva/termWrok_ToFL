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
bool isLetter(char letter);//  буква
bool isDigit(char number);//  цифра
bool isIdentifier(string s);//  идентификатор
bool isBinaryNumber(string s);//  двоичное
bool isOctalNumber(string s);//  восьмиричное
bool isDecimalNumber(string s);//  десятичное
bool isHexadecimalNumber(string s);//  шестнадцатиричное
bool isIntegerNumber(string s);//  целое
bool isNumericString(string s);//  числовая строка
bool isExponent(string s);//  порядок
bool isFloatNumber(string s);//  действительное
bool isNumber(string s);//  число
bool isBooleanConstant(string s);//  логическая константа
bool isFactor(string s);//  множитель
bool isTerm(string s);//  слагаемое
bool isOperand(string s);//  операнд
bool isExpression(string s);//  выражение
bool isType(string s);//  тип
bool isOperator(string s);
bool isCompound(string s);//  составной
bool isConditional(string s);//  условный
bool isFixedCycle(string s);//  фиксированного_цикла
bool isAssignment(string s);//  присваивание
bool isConditionalCycle(string s);//  условный цикл
bool isInput(string s);//  ввод
bool isOutput(string s);//  ввыод
bool isDescription(string s);//  описание
bool isProgram(string s);//  програма
bool isInOfficialWords(string s);
int findInIdentifiers(string s);
int findInNumbers(string s);
void inputLexemesFile();
bool identifiersChek();//  проверка описаний
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