//             Вариант 30  -  331233
// операции группы отношения: NE | EQ | LT | LE | GT | GE
//                            !=   ==    <   <=    >   >=
// операции группы сложения: plus, min, or
// операции группы умножения: mult, div, and
// унарная операция: ~
// Выражения языка задаются правилами:
// <выражение>:: = <операнд>{ <операции_группы_отношения> <операнд> }
// <операнд>:: = <слагаемое>{ <операции_группы_сложения> <слагаемое> }
// <слагаемое>:: = <множитель>{ <операции_группы_умножения> <множитель> }
// <множитель>:: = <идентификатор> | <число> | <логическая_константа> |
// <унарная_операция> <множитель> | «(»<выражение>«)»
// <число>:: = <целое> | <действительное>
// <логическая_константа>:: = true | false
// Правила, определяющие идентификатор, букву и цифру :
// <идентификатор>:: = <буква>{ <буква> | <цифра> }
// <буква>:: = A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T |
// U | V | W | X | Y | Z | a | b | c | d | e | f | g | h | i | j | k | l | m | n | o | p
// q | r | s | t | u | v | w | x | y | z
// <цифра>:: = 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
// Правила, определяющие целые числа :
// <целое>:: = <двоичное> | <восьмеричное> | <десятичное> |
// <шестнадцатеричное>
// <двоичное>:: = { / 0 | 1 / } (B | b)
// < восьмеричное > :: = { / 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 / } (O | o)
// < десятичное > :: = { / <цифра> / }[D | d]
// <шестнадцатеричное>:: = <цифра>{ <цифра> | A | B | C | D | E | F | a | b |
//  c | d | e | f } (H | h)
//	Правила, описывающие действительные числа :
// <действительное>:: = <числовая_строка> <порядок> |
// [<числовая_строка>] . <числовая_строка>[порядок]
// <числовая_строка>:: = { / <цифра> / }
// <порядок>:: = (E | e)[+| -] <числовая_строка>
// <программа>::= {/(<опиcание>|<оператор>)(:|переход строки)/} end
// <оператор>::= <составной> | <присваивания> | <условный> | 
// <фиксированного_цикла> | <условного_цикла> | <ввода> |
// <вывода>
// <опиcание>::= {<идентификатор>{,<идентификатор>}:<тип>;}
// <тип>::= integer | real | boolean
// <составной>::= "{"<оператор>{;<оператор>}"}"
// <условный>::= if<выражение> then<оператор> [else <оператор>] end_else
// <присваивания> ::= [let] <идентификатор> = <выражение>
// <фиксированного_цикла>::=for"("[<выражение>];[<выражение>];[<выражение>]")" <оператор> 
// <условного_цикла>::= do while <выражение> <оператор> loop
// <ввода>::= input"("<идентификатор> {пробел <идентификатор>} ")"
// <вывода>::= output"("<выражение> {пробел <выражение> } ")"
// признак начала комментария: (*  
// признак конца комментария:    *)
// ключевые слова :== input, output, do while, loop, for, let, if, then, else, end_else, integer, real, boolean, end, true, false
// plus, min, or, mult, div, and, NE, EQ, LT, LE, GT, GQ, ~
// ограничители :== ;, :, {, }, [, ], (, ), =, ','
// числа :== ...
// идентификаторы :== ...
#include "Header.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream f;
	f.open("test.txt", ios::in);
	string s;
	while (!f.eof()) {
		s += f.get();
	}
	f.close();
	s.erase(s.size() - 1, s.size());
	cout << "Исходный файл: \n";
	cout << "------------------------------------------\n";
	cout << s << '\n';
	cout << "------------------------------------------\n";
	officialWords.resize(28);
	officialWords = { "input", "output", "do while", "loop", "for", "let", "if", "then", "else", "end_else", "integer", "real",
		"boolean", "end", "true", "false", "plus", "min", "or", "mult", "div", "and", "NE", "EQ", "LT", "LE", "GT", "GQ" };
	separators.resize(13);
	separators = { ';', ':', '{', '}', '[', ']', '(', ')', '=', ',' , ' ', '\n', '~' };
	bool l = recognaizer(s);
	if (l) {
		cout << "Данный файл принадлежит языку\n";
		inputAllLexemes(s);
		cout << "Все лексемы файла:\n";
		inputLexemesFile();
		ifstream ff;
		ff.open("lexemes.txt", ios::in);
		getline(ff, s);
		cout << s << '\n';
		cout << "(1) Служебные слова:\n";
		for (int i = 0; i < officialWords.size(); i++) {
			cout << i + 1 << ")" << officialWords[i] << " ";
		}
		cout << "\n(2) Ограничители:\n";
		cout << "1)';'  2)':'  3)'{'  4)'}'  5)'['  6) ']'  7)'('  8)')'  9)'='  10)','  11)' '  12)'/n'  13)'~'\n";
		cout << "(3) Числа:\n";
		for (int i = 0; i < allNumbers.size(); i++) {
			cout << i + 1 << ")" << allNumbers[i] << " ";
		}
		cout << "\nИдентификаторы:\n";
		for (int i = 0; i < allIdentifiers.size(); i++) {
			cout << i + 1 << ")" << allIdentifiers[i] << " ";
		}
		cout << '\n';
		s = "";
		for (int i = 0; i < allLexemes.size(); i++) {
			s += allLexemes[i].value;
		}
		bool p = isProgram(s);
		if (p) {
			cout << "\nСинтаксических ошибок нет\n";
			cout << "\nОбработка описаний:\n";
			if (identifiersChek()) {
				cout << "Ошибок в описании нет\n";
				cout << "\nОписанные идентификаторы:\n";
				for (int i = 0; i < identifiers.size(); i++) {
					cout << "Тип: " << identifiers[i].type << " - ";
					cout << identifiers[i].value << '\n';
				}
			}
			else {
				cout << "Присутствуют ошибки в опсании:\n";
				for (int i = 0; i < identifiers.size(); i++) {
					if (!identifiers[i].described) {
						cout << "Неописанный идентификатор: " << identifiers[i].value << '\n';
					}
				}
			}
		}
		else {
			cout << "\nВ файле присутствуют синтаксические ошибки\n";
		}
	}
	else {
		cout << "Данный файл не принадлежит языку\n";
	}
}
bool recognaizer(string s) {
	bool flag = true;
	for (int i = 0; i < s.size(); i++) {
		if (!isInDictionary(s[i])) {
			flag = false;
			cout << "Неопознанный символ: " << s[i] << '\n';
		}
	}
	return flag;
}
bool isInDictionary(char c) {
	if (isDigit(c)) {
		return true;
	}
	else if ((c == ';') || (c == ':') || (c == '{') || (c == '}') || (c == '[') || (c == '_') ||
		(c == ']') || (c == '(') || (c == ')') || (c == '=') || (c == ',') || (c == ' ') || (c == '*') || 
		(c == '+') || (c == '-') || (c == '\n')) {
		return true;
	}
	else if (isLetter(c)) {
		return true;
	}
	else
		return false;
}
void inputAllLexemes(string s) {
	bool flag = false;
	Lexeme x, y;
	string number = "", ident = "", check = "";
	for (int i = 0; i < s.size(); i++) {
		number = "", ident = "";
		if (i < s.size() - 1) {
			if ((s[i] == '(') && (s[i + 1] == '*')) {
				while ((s[i] != ')') || (s[i - 1] != '*') && (i < s.size())) {
					i++;
				}
				i++;
			}
		}
		if ((s[i] == ';') || (s[i] == ':') || (s[i] == '{') || (s[i] == '}') || (s[i] == '[') || (s[i] == ']') || 
			(s[i] == '(') || (s[i] == ')') || (s[i] == '=') || (s[i] == ',') || (s[i] == ' ') || (s[i] == '\n') || (s[i] == '~')) {
			x.numOfTable = 2;
			x.numInTable = findInSeparators(s[i]);
			x.value = s[i];
		}
		else if ((s[i] >= '0') && (s[i] <= '9')) {
			x.numOfTable = 3;
			while (i < s.size()) {
				number += s[i];
				if ((s[i] == 'O') || (s[i] == 'o') || (s[i] == 'B') || (s[i] == 'b') ||
					(s[i] == 'H') || (s[i] == 'h') || (s[i] == 'D') || (s[i] == 'd')) {
					if (findInNumbers(number) == -1) {
						allNumbers.push_back(number);
					}
					x.numInTable = findInNumbers(number);
					x.value = number;
					break;
				}
				else if (s[i] == '.') {
					i++;
					while ((((s[i] >= '0') && (s[i] <= '9')) || (s[i] == 'E') || (s[i] == 'e') || (s[i] == '+') || (s[i] == '-')) && (i < s.size())) {
						number += s[i];
						i++;
					}
					if (findInNumbers(number) == -1) {
						allNumbers.push_back(number);
					}
					x.numInTable = findInNumbers(number);
					x.value = number;
					break;
				}
				i++;
			}
		}
		else if (isLetter(s[i])) {
			while (((isLetter(s[i])) || (isDigit(s[i]))) && (i < s.size())) {
				ident += s[i];
				if ((ident.size() > 1) && (ident != "for")) {
					check = ident;
					check.erase(0, check.size() - 2);
					if ((check == "do") && (s[i + 1] == ' ') && (s[i + 2] == 'w') && (s[i + 3] == 'h') && (s[i + 4] == 'i') && (s[i + 5] == 'l') && (s[i + 6] == 'e')) {
						check = "do while";
						i += 6;
					}
					if (isInOfficialWords(check)) {
						y.numOfTable = 1;
						y.numInTable = findInOfficialWords(check);
						y.value = check;
						flag = true;
						ident = ident.erase(ident.size() - 2, ident.size());
						i++;
						break;
					}
				}
				if (ident.size() > 2) {
					check = ident;
					check.erase(0, check.size() - 3);
					if ((check == "end") && (s[i + 1] == '_')) {
						check = "end_else";
						i += 5;
					}
					if (isInOfficialWords(check)) {
						y.numOfTable = 1;
						y.numInTable = findInOfficialWords(check);
						y.value = check;
						flag = true;
						ident = ident.erase(ident.size() - 3, ident.size());
						i++;
						break;
					}
				}
				if (ident.size() > 3) {
					check = ident;
					check.erase(0, check.size() - 4);
					if (isInOfficialWords(check)) {
						y.numOfTable = 1;
						y.numInTable = findInOfficialWords(check);
						y.value = check;
						flag = true;
						ident = ident.erase(ident.size() - 4, ident.size());
						i++;
						break;
					}
				}
				if (ident.size() > 4) {
					check = ident;
					check.erase(0, check.size() - 5);
					if (isInOfficialWords(check)) {
						y.numOfTable = 1;
						y.numInTable = findInOfficialWords(check);
						y.value = check;
						flag = true;
						ident = ident.erase(ident.size() - 5, ident.size());
						i++;
						break;
					}
				}
				if (ident.size() > 5) {
					check = ident;
					check.erase(0, check.size() - 6);
					if (isInOfficialWords(check)) {
						y.numOfTable = 1;
						y.numInTable = findInOfficialWords(check);
						y.value = check;
						flag = true;
						ident = ident.erase(ident.size() - 6, ident.size());
						i++;
						break;
					}
				}
				if (ident.size() > 6) {
					check = ident;
					check.erase(0, check.size() - 7);
					if (isInOfficialWords(check)) {
						y.numOfTable = 1;
						y.numInTable = findInOfficialWords(check);
						y.value = check;
						flag = true;
						ident = ident.erase(ident.size() - 7, ident.size());
						i++;
						break;
					}
				}
				if (ident.size() > 7) {
					check = ident;
					check.erase(0, check.size() - 8);
					if (isInOfficialWords(check)) {
						y.numOfTable = 1;
						y.numInTable = findInOfficialWords(check);
						y.value = check;
						flag = true;
						ident = ident.erase(ident.size() - 8, ident.size());
						i++;
						break;
					}
				}
				i++;
			}
			i--;
			if (isInOfficialWords(ident)) {
				x.numOfTable = 1;
				x.numInTable = findInOfficialWords(ident);
			}
			else {
				x.numOfTable = 4;
				if ((findInIdentifiers(ident) == -1) && (ident != "")) {
					allIdentifiers.push_back(ident);
				}
				x.numInTable = findInIdentifiers(ident);
			}
			x.value = ident;
		}
		if (x.value != "") {
			allLexemes.push_back(x);
		}
		
		if (flag) {
			allLexemes.push_back(y);
			flag = false;
		}
	}
}
int findInOfficialWords(string s) {
	for (int i = 0; i < officialWords.size(); i++) {
		if (s == officialWords[i]) {
			return i + 1;
		}
	}
	return -1;
}
int findInSeparators(char c) {
	for (int i = 0; i < separators.size(); i++) {
		if (c == separators[i]) {
			return i + 1;
		}
	}
	return -1;
}
bool isLetter(char letter) {
	if (((letter >= 'A') && (letter <= 'Z')) || ((letter >= 'a') && (letter <= 'z')))
		return true;
	else
		return false;
}
bool isDigit(char number) {
	if ((number >= '0') && (number <= '9'))
		return true;
	else
		return false;
}
bool isIdentifier(string s) {
	if (isLetter(s[0])) {
		for (int i = 1; i < s.size(); i++) {
			if ((!isLetter(s[i])) && (!isDigit(s[i]))) {
				return false;
			}
		}
		if (isInOfficialWords(s)) {
			return false;
		}
		return true;
	}
	else {
		return false;
	}
}
int findInIdentifiers(string s) {
	for (int i = 0; i < allIdentifiers.size(); i++) {
		if (s == allIdentifiers[i]) {
			return i + 1;
		}
	}
	return -1;
}
bool isInOfficialWords(string s) {
	for (int i = 0; i < officialWords.size(); i++) {
		if (s == officialWords[i]) {
			return true;
		}
	}
	return false;
}
bool isBinaryNumber(string s) {
	for (int i = 0; i < s.size() - 1; i++) {
		if ((s[i] != '1') && (s[i] != '0')) {
			return false;
		}
	}
	if ((s[s.size() - 1] != 'B') && (s[s.size() - 1] != 'b')) {
		return false;
	}
	else {
		return true;
	}
}
bool isOctalNumber(string s) {
	for (int i = 0; i < s.size() - 1; i++) {
		if ((s[i] < '0') || (s[i] > '7')) {
			return false;
		}
	}
	if ((s[s.size() - 1] != 'O') && (s[s.size() - 1] != 'o')) {
		return false;
	}
	else {
		return true;
	}
}
bool isDecimalNumber(string s) {
	for (int i = 0; i < s.size() - 1; i++) {
		if (!isDigit(s[i])) {
			return false;
		}
	}
	if ((s[s.size() - 1] != 'D') && (s[s.size() - 1] != 'd')) {
		return false;
	}
	else {
		return true;
	}
}
bool isHexadecimalNumber(string s) {
	if (!isDigit(s[0]))
		return false;
	else {
		for (int i = 1; i < s.size() - 1; i++) {
			if ((isDigit(s[i])) || ((s[i] >= 'A') && (s[i] <= 'F')) || ((s[i] >= 'a') && (s[i] <= 'f'))) {
				continue;
			}
			else {
				return false;
			}
		}
		if ((s[s.size() - 1] != 'H') && (s[s.size() - 1] != 'h')) {
			return false;
		}
		else {
			return true;
		}
	}
}
bool isIntegerNumber(string s) {
	if ((isBinaryNumber(s)) || (isOctalNumber(s)) || (isDecimalNumber(s)) || (isHexadecimalNumber(s)))
		return true;
	else {
		
		return false;;
	}
}
bool isNumericString(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (!isDigit(s[i]))
			return false;
	}
	return true;
}
bool isExponent(string s) {
	string numericString = "";
	if ((s[0] != 'E') && (s[0] != 'e')) {
		return false;
	}
	if ((s[1] != '+') && (s[1] != '-') && (!isDigit(s[1]))) {
		return false;
	}
	if ((s[1] == '+') || (s[1] == '-')) {
		numericString = s.erase(0, 2);
		if (!isNumericString(numericString)) {
			return false;
		}
		else {
			return true;
		}
	}
	else {
		numericString = s.erase(0, 1);
		if (!isNumericString(numericString)) {
			return false;
		}
		else {
			return true;
		}
	}
}
bool isFloatNumber(string s) {
	string exponentialString = "";
	bool dot = false;
	if (!isDigit(s[0]))
		return false;
	else {
		int i = 1, locationOfdot;
		while (isDigit(s[i])) {
			i++;
		}
		for (int j = i; j < s.size(); j++) {
			if (s[j] == '.') {
				dot = true;
				locationOfdot = j;
				break;
			}
		}
		if (!dot)
			return false;
		else {
			if (locationOfdot != i) {
				for (int k = i; k < locationOfdot; k++) {
					exponentialString += s[k];
				}
				if (!isExponent(exponentialString))
					return false;
			}
			i = locationOfdot + 1;
			while (isDigit(s[i])) {
				i++;
			}
			exponentialString = "";
			for (int k = i; k < s.size(); k++) {
				exponentialString += s[k];
			}
			if ((!isExponent(exponentialString)) && (exponentialString != ""))
				return false;
			return true;
		}
	}
}
bool isNumber(string s) {
	if ((isIntegerNumber(s)) || (isFloatNumber(s))) {
		return true;
	}
	else
		return false;
}
int findInNumbers(string s) {
	for (int i = 0; i < allNumbers.size(); i++) {
		if (s == allNumbers[i]) {
			return i + 1;
		}
	}
	return -1;
}
bool isBooleanConstant(string s) {
	if ((s == "true") || (s == "false")) {
		return true;
	}
	else
		return false;
}
bool isFactor(string s) {
	if (s == "")
		return false;
	string expression = s, factor = s;
	expression = expression.erase(0, 1);
	expression = expression.erase(expression.size() - 1, expression.size());
	if ((isIdentifier(s)) || (isNumber(s)) || (isBooleanConstant(s)) || ((s[0] == '~') && (isFactor(factor.erase(0, 1)))) || ((s[0] == '(') && (s[s.size() - 1] == ')') && (isExpression(expression)))) {
		return true;
	}
	else
		return false;
}
bool isTerm(string s) {
	string factor = "";
	bool flag = false;
	if (s == "")
		return false;
	else {
		for (int i = 0; i < s.size(); i++) {
			factor += s[i];
			if (i > 3) {
				if (((s[i - 2] == 'd') && (s[i - 1] == 'i') && (s[i] == 'v')) ||
					((s[i - 2] == 'a') && (s[i - 1] == 'n') && (s[i] == 'd'))) {
					flag = true;
					factor = factor.erase(factor.size() - 3, factor.size());
					if (!isFactor(factor))
						return false;
					s = s.erase(0, factor.size() + 3);
					i = -1;
					factor = "";
				}
			}
			if (i > 4) {
				if ((s[i - 3] == 'm') && (s[i - 2] == 'u') && (s[i - 1] == 'l') && (s[i] == 't')) {
					flag = true;
					factor = factor.erase(factor.size() - 4, factor.size());
					if (!isFactor(factor))
						return false;
					s = s.erase(0, factor.size() + 3);
					i = -1;
					factor = "";
				}
			}
		}
		if (!flag) {
			if (isFactor(factor))
				return true;
			return false;
		}
		else {
			return true;
		}
			
	}
}
bool isOperand(string s) {
	string term = "";
	bool flag = false;
	if (s == "")
		return false;
	else {
		for (int i = 0; i < s.size(); i++) {
			term += s[i];
			if (i > 2) {
				if ((s[i - 1] == 'o') && (s[i] == 'r')) {
					flag = true;
					term = term.erase(term.size() - 2, term.size());
					if (!isTerm(term))
						return false;
					s = s.erase(0, term.size() + 2);
					i = -1;
					term = "";
				}
			}
			if (i > 3) {
				if ((s[i - 2] == 'm') && (s[i - 1] == 'i') && (s[i] == 'n')) {
					flag = true;
					term = term.erase(term.size() - 3, term.size());
					if (!isTerm(term))
						return false;
					s = s.erase(0, term.size() + 2);
					i = -1;
					term = "";
				}
			}
			if (i > 4) {
				if ((s[i - 3] == 'p') && (s[i - 2] == 'l') && (s[i - 1] == 'u') && (s[i] == 's')) {
					flag = true;
					term = term.erase(term.size() - 4, term.size());
					if (!isTerm(term))
						return false;
					s = s.erase(0, term.size() + 2);
					i = -1;
					term = "";
				}
			}
		}
		if (!flag) {
			if (isTerm(term))
				return true;
			return false;
		}
		else {
			return true;
		}
	}
}
bool isExpression(string s) {
	string operand = "";
	if (s == "")
		return false;
	else {
		for (int i = 0; i < s.size(); i++) {
			operand += s[i];
			if (i > 2) {
				if (((s[i - 1] == 'N') && (s[i] == 'E')) || 
					((s[i - 1] == 'E') && (s[i] == 'Q')) || 
					((s[i - 1] == 'L') && (s[i] == 'T')) || 
					((s[i - 1] == 'L') && (s[i] == 'E')) || 
					((s[i - 1] == 'G') && (s[i] == 'T')) || 
					((s[i - 1] == 'G') && (s[i] == 'E'))) {
					operand = operand.erase(operand.size() - 2, operand.size());
					if (!isOperand(operand))
						return false;
					s = s.erase(0, operand.size() + 2);
					i -= operand.size() + 2;
					operand = "";
				}
			}
		}
		if (isOperand(operand))
			return true;
		return false;
	}
}
bool isType(string s) {
	if ((s == "integer") || (s == "real") || (s == "boolean")) {
		return true;
	}
	else
		return false;
}
bool isCompound(string s) {
	string oper = "";
	if (s == "")
		return false;
	if ((s[0] == '{') && (s[s.size() - 1] == '}')) {
		s.erase(0, 1);
		s.erase(s.size() - 1, s.size());
		for (int i = 0; i < s.size(); i++) {
			oper += s[i];
			if (s[i] == ';') {
				oper = oper.erase(oper.size() - 1, oper.size());
				if (!isOperator(oper))
					return false;
				s = s.erase(0, oper.size() + 1);
				i = -1;
				oper = "";
			}
		}
		if (isOperator(oper))
			return true;
	}
	else
		return false;
}
bool isConditional(string s) {
	if (s == "")
		return false;
	if ((s[0] == 'i') && (s[1] == 'f')) {
		string expression = "", oper = "";
		bool flag = false;
		for (int i = 2; i < s.size(); i++) {
			expression += s[i];
			if (i > 7) {
				if ((s[i - 4] == ' ') && (s[i - 3] == 't') && (s[i - 2] == 'h') && (s[i - 1] == 'e') && (s[i] == 'n')) {
					expression = expression.erase(expression.size() - 5, expression.size());
					if (!isExpression(expression))
						return false;
					i++;
					while (s[i] != ' ') {
						oper += s[i];
						i++;
					}
					if (!isOperator(oper))
						return false;
					flag = true;
				}
			}
			if (flag) {
				if ((s[i - 4] == 'e') && (s[i - 3] == 'l') && (s[i - 2] == 's') && (s[i - 1] == 'e') && (s[i] == ' ')) {
					i ++;
					oper = "";
					while (s[i] != ' ') {
						oper += s[i];
						i++;
					}
					if (!isOperator(oper))
						return false;
					break;
				}
			}
		}
		if (!flag)
			return false;
		else {
			s = s.erase(0, s.size() - 8);
			if (s != "end_else")
				return false;
			else {
				return true;
			}
		}
	}
	return false;
}
bool isFixedCycle(string s) {
	if (s == "")
		return false;
	int countOfExpressions = 0;
	string expression = "", oper = "";
	bool find = false;
	for (int i = 0; i < s.size(); i++) {
		if ((i > 3) && (!find)) {
			if ((s[i - 4] == 'f') && (s[i - 3] == 'o') && (s[i - 2] == 'r') && (s[i - 1] == '(')) {
				while ((s[i] != ';') && (s[i] != ')') && (i < s.size())) {
					expression += s[i];
					i++;
				}
				if (!isExpression(expression))
					return false;
				if (s[i] == ';') {
					expression = "";
					i++;
					while ((s[i] != ';') && (s[i] != ')') && (i < s.size())) {
						expression += s[i];
						i++;
					}
					if (!isExpression(expression))
						return false;
					if (s[i] == ';') {
						expression = "";
						i++;
						while ((s[i] != ')') && (i < s.size())) {
							expression += s[i];
							i++;
						}
						if (!isExpression(expression))
							return false;
					}
				}
				find = true;
				if (i >= s.size() - 2)
					return false;
				i += 2;
			}
		}
		if (find) {
			oper += s[i];
		}
	}
	if (!isOperator(oper))
		return false;
	else {
		return true;
	}
}
bool isAssignment(string s) {
	if (s == "")
		return false;
	string ident = "", expression = "";
	bool flag = false;
	for (int i = 0; i < s.size(); i++) {
		if (i > 3) {
			if ((s[i - 4] == '[') && (s[i - 3] == 'l') && (s[i - 2] == 'e') && (s[i - 1] == 't') && (s[i] == ']')) {
				i++;
				while ((s[i] != '=') && (i < s.size())) {
					ident += s[i];
					i++;
				}
				if (!isIdentifier(ident))
					return false;
				i++;
				while (i < s.size()) {
					expression += s[i];
					i++;
				}
				if (!isExpression(expression))
					return false;
				flag = true;
			}
		}
	}
	if (!flag)
		return false;
	else {
		return true;
	}
}
bool isConditionalCycle(string s) {
	if (s == "")
		return false;
	string expression = "", oper = "";
	for (int i = 0; i < s.size(); i++) {
		if (i > 7) {
			if ((s[i - 8] == 'd') && (s[i - 7] == 'o') && (s[i - 6] == ' ') && (s[i - 5] == 'w') && (s[i - 4] == 'h') && (s[i - 3] == 'i') && (s[i - 2] == 'l') && (s[i - 1] == 'e')) {
				i++;
				while ((s[i] != ' ') && (i<s.size())) {
					expression += s[i];
					i++;
				}
				i++;
				if (!isExpression(expression))
					return false;
				while ((s[i] != ' ') && (i < s.size())) {
					oper += s[i];
					i++;
				}
				if (!isOperator(oper))
					return false;
				i++;
				if (s.size() != i + 4)
					return false;
				if ((s[i] == 'l') && (s[i + 1] == 'o') && (s[i + 2] == 'o') && (s[i + 3] == 'p')) {
					return true;
				}
				else
					return false;
			}
		}
	}
	return false;
}
bool isInput(string s) {
	if (s == "")
		return false;
	string ident = "";
	if (s[s.size() - 1] != ')')
		return false;
	for (int i = 0; i < s.size(); i++) {
		if (i > 5) {
			if ((s[i - 6] == 'i') && (s[i - 5] == 'n') && (s[i - 4] == 'p') && (s[i - 3] == 'u') && (s[i - 2] == 't') && (s[i - 1] == '(')) {
				while (i < s.size()) {
					ident += s[i];
					if (s[i] == ' ') {
						ident.erase(ident.size(), ident.size() - 1);
						if (!isIdentifier(ident))
							return false;
						ident = "";
					}
					i++;
				}
				ident.erase(ident.size() - 1, ident.size());
				if (!isIdentifier(ident))
					return false;
				else {
					return true;
				}
			}
		}
		
	}
	return false;
}
bool isOutput(string s) {
	if (s == "")
		return false;
	if (s[s.size() - 1] != ')')
		return false;
	string expression = "";
	for (int i = 0; i < s.size(); i++) {
		if (i > 6) {
			if ((s[i - 7] == 'o') && (s[i - 6] == 'u') && (s[i - 5] == 't') && (s[i - 4] == 'p') && (s[i - 3] == 'u') && (s[i - 2] == 't') && (s[i - 1] =='(')) {
				while (i < s.size()) {
					expression += s[i];
					if (s[i] == ' ') {
						expression.erase(expression.size(), expression.size() - 1);
						if (!isExpression(expression))
							return false;
						expression = "";
					}
					i++;
				}
				expression.erase(expression.size() - 1, expression.size());
				if (!isExpression(expression))
					return false;
				else {
					return true;
				}
			}
		}
	}
	return false;
}
bool isOperator(string s) {
	if (s == "")
		return false;
	if ((isCompound(s)) || (isConditional(s)) || (isAssignment(s)) || (isFixedCycle(s)) || (isConditionalCycle(s)) || (isInput(s)) || (isOutput(s))) {
		return true;
	}
	else {
		return false;
	}
}
bool isDescription(string s) {
	if (s == "")
		return false;
	string ident = "";
	for (int i = 0; i < s.size(); i++) {
		while ((s[i] != ',') && (s[i] != ':') && (s[i] != ';') && (i < s.size())) {
			ident += s[i];
			i++;
		}
		if ((s[i] == ',') || (s[i] == ':')) {
			if (!isIdentifier(ident)) {
				return false;
			}
			ident = "";
		}
		else if (s[i] == ';') {
			if (!isType(ident))
				return false;
			ident = "";
		}
	}
	if (s[s.size() - 1] != ';')
		return false;
	return true;
}
bool isProgram(string s) {
	bool find = false;
	bool result = false;
	if (s.size() <= 3)
		return false;
	if ((s[s.size() - 3] != 'e') && (s[s.size() - 2] != 'n') && (s[s.size() - 1] != 'd')) {
		cout << "Программа должна оканчиваться на ключевое слово 'end'\n";
		return false;
	}
	string op = "";
	op += s[0];
	for (int i = 1; i < s.size(); i++) {
		while (((s[i] != ':') || (s[i - 1] != ';')) && (s[i] != '\n') && (i < s.size())) {
			if (s[i] == ':') {
				if (isOperator(op)) {
					op = "";
					break;
				}
			}
			if (i > 0) {
				if ((s[i - 1] == '(') && (s[i] == '*')) {
					while ((s[i] != ')') || (s[i - 1] != '*')) {
						i++;
						if (i > s.size())
							return false;
					}
					if (i < s.size() - 2) {
						if (s[i + 1] == '\n') {
							i++;
						}
					}
					else
						return false;
					i++;
					op = "";
				}
			}
			op += s[i];
			i++;
		}
		if ((op != "") && (op != "end")) {
			if ((!isDescription(op)) && (!isOperator(op))) {
				cout << "Программа должна состоять из описаний и операторов\n";
				cout << "Неопознанная строка: " << op;
				return false;
			}
			else {
				find = true;
				op = "";
			}
		}
	}
	if (find) {
		return true;
	}
	else {
		cout << "В программе должно присутствовать как минимум одно описание или оператор\n";
		return false;
	}
}
void inputLexemesFile() {
	ofstream b;
	b.open("lexemes.txt", ios::out | ios::trunc);
	for (int i = 0; i < allLexemes.size(); i++) {
		b << '(' << allLexemes[i].numOfTable << ", " << allLexemes[i].numInTable << ") ";
	}
	b.close();
}
bool identifiersChek() {
	bool flag = true;
	IdTable x;
	x.described = false;
	for (int i = 0; i < allLexemes.size(); i++) {
		if (allLexemes[i].numOfTable == 4) {
			x.value = allLexemes[i].value;
			if (findIdentifier(x.value) == -1) {
				identifiers.push_back(x);
			}
		}
	}
	for (int i = 0; i < allLexemes.size(); i++) {
		vector <string> disId;
		int index;
		if (i < allLexemes.size() - 2) {
			if (allLexemes[i].numOfTable == 4) {
				if ((allLexemes[i + 1].numOfTable == 2) && (allLexemes[i + 1].numInTable == 10)) {
					disId.push_back(allLexemes[i].value);
					i++;
					while ((allLexemes[i].numOfTable != 2) || (allLexemes[i].numInTable != 2)) {
						if (allLexemes[i].numOfTable == 4) {
							disId.push_back(allLexemes[i].value);
						}
						i++;
					}
					i++;
					if (allLexemes[i].numInTable == 11) {
						x.type = "integer";
						for (int i = 0; i < disId.size(); i++) {
							index = findIdentifier(disId[i]);
							identifiers[index].type = "integer";
							if (identifiers[index].described) {
								cout << "Мнокократное описание идентификатора: " << identifiers[index].value << '\n';
								flag = false;
							}
							else
								identifiers[index].described = true;
						}
					}
					else if (allLexemes[i].numInTable == 12) {
						x.type = "real";
						for (int i = 0; i < disId.size(); i++) {
							index = findIdentifier(disId[i]);
							identifiers[index].type = "real";
							if (identifiers[index].described) {
								cout << "Мнокократное описание идентификатора: " << identifiers[index].value << '\n';
								flag = false;
							}
							else
								identifiers[index].described = true;
						}
					}
					else if (allLexemes[i].numInTable == 13) {
						x.type = "boolean";
						for (int i = 0; i < disId.size(); i++) {
							index = findIdentifier(disId[i]);
							identifiers[index].type = "boolean";
							if (identifiers[index].described) {
								cout << "Мнокократное описание идентификатора: " << identifiers[index].value << '\n';
								flag = false;
							}
							else
								identifiers[index].described = true;
						}
					}
				}
				else if ((allLexemes[i + 1].numOfTable == 2) && (allLexemes[i + 1].numInTable == 2)) {
					disId.push_back(allLexemes[i].value);
					i += 2;
					if (allLexemes[i].numInTable == 11) {
						x.type = "integer";
						for (int i = 0; i < disId.size(); i++) {
							index = findIdentifier(disId[i]);
							identifiers[index].type = "integer";
							if (identifiers[index].described) {
								cout << "Мнокократное описание идентификатора: " << identifiers[index].value << '\n';
								flag = false;
							}
							else
								identifiers[index].described = true;
						}
					}
					else if (allLexemes[i].numInTable == 12) {
						x.type = "real";
						for (int i = 0; i < disId.size(); i++) {
							index = findIdentifier(disId[i]);
							identifiers[index].type = "real";
							if (identifiers[index].described) {
								cout << "Мнокократное описание идентификатора: " << identifiers[index].value << '\n';
								flag = false;
							}
							else
								identifiers[index].described = true;
						}
					}
					else if (allLexemes[i].numInTable == 13) {
						x.type = "boolean";
						for (int i = 0; i < disId.size(); i++) {
							index = findIdentifier(disId[i]);
							identifiers[index].type = "boolean";
							if (identifiers[index].described) {
								cout << "Мнокократное описание идентификатора: " << identifiers[index].value << '\n';
								flag = false;
							}
							else
								identifiers[index].described = true;
						}
					}
				}
			}
			disId.clear();
		}
	}
	for (int i = 0; i < identifiers.size(); i++) {
		if (!identifiers[i].described) {
			flag = false;
		}
	}
	return flag;
}
int findIdentifier(string s) {
	for (int i = 0; i < identifiers.size(); i++) {
		if (identifiers[i].value == s) {
			return i;
		}
	}
	return -1;
}
// <оператор>:: = <составной> | <присваивания> | <условный> |
// <фиксированного_цикла> | <условного_цикла> | <ввода> |
// <вывода>
// <опиcание>::= {<идентификатор>{,<идентификатор>}:<тип>;}
// <тип>::= integer | real | boolean
// <составной>::= "{"<оператор>{;<оператор>}"}"
// <условный>::= if<выражение> then<оператор> [else <оператор>] end_else
// <присваивания> ::= [let] <идентификатор> = <выражение>
// <фиксированного_цикла>::=for"("[<выражение>];[<выражение>];[<выражение>]")" <оператор> 
// <условного_цикла>::= do while <выражение> <оператор> loop
// <ввода>::= input"("<идентификатор> {пробел <идентификатор>} ")"
// <вывода>::= output"("<выражение> {пробел <выражение> } ")"

// <выражение>:: = <операнд>{ <операции_группы_отношения> <операнд> }
// <операнд>:: = <слагаемое>{ <операции_группы_сложения> <слагаемое> }
// <слагаемое>:: = <множитель>{ <операции_группы_умножения> <множитель> }
// <множитель>:: = <идентификатор> | <число> | <логическая_константа> |
// <унарная_операция> <множитель> | «(»<выражение>«)»