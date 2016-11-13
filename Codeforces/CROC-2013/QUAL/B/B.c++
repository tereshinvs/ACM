#include <iostream>
#include <string>
#include <cctype>

using namespace std;

enum {
	OUT_WORD, IN_WORD, IN_QUOTE
};

int main() {
	int state = OUT_WORD;
	char c;
	string cur_lexem;
	cur_lexem.reserve(200000);
	while (cin.get(c))
		switch (state) {
			case OUT_WORD:
				if (c == '"')
					state = IN_QUOTE;
				else if (ispunct(c) || isalpha(c)) {
					state = IN_WORD;
					cur_lexem += c;
				}
				break;
			case IN_WORD:
				if (isspace(c)) {
					state = OUT_WORD;
					cout << "<" << cur_lexem << ">" << endl;
					cur_lexem = "";
				} else if (ispunct(c) || isalpha(c))
					cur_lexem += c;
				break;
			case IN_QUOTE:
				if (c == '"') {
					state = OUT_WORD;
					cout << "<" << cur_lexem << ">" << endl;
					cur_lexem = "";
				} else
					cur_lexem += c;
				break;
			default:
				break;
		}
}