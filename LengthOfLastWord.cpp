#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int LengthOfLastWord(string s) {
	int length = 0;
	int i = s.length() - 1;
	while (i >= 0 && (s[i] == ' ' || ispunct(s[i]))) {
		i--;
	}
	while (i >= 0 && s[i] != ' ') {
		length++;
		i--;
	}
	return length;
}
int main()
{
	string s = "This is an example string . ";
	string k = "Another string . too ,";
	string a = "This is an example string. ";

	cout << LengthOfLastWord(s) << '\n';
	cout << LengthOfLastWord(k) << '\n';
	cout << LengthOfLastWord(a) << '\n';

}
