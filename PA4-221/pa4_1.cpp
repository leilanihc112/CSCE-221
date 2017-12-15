/*Leilani Horlander-Cruz
leilanihc112
CSCE 221-506
leilanihc112@tamu.edu*/
#include <iostream>
#include <string>
#include <regex>
using namespace std;
int main() {
regex pattern{R"(\d\d)"};
regex pattern2{ "thanks" };
string to_search = "I would like the number 98"
" to be found and printed, thanks.";
smatch matches;
smatch matches2;
regex_search(to_search, matches, pattern);
for (auto match : matches) {
cout << match;
}
regex_search(to_search, matches2, pattern2);
for (auto match : matches2) {
	cout << " " << match << endl;
}
return 0;
}