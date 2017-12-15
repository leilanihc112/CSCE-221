/*Leilani Horlander-Cruz
leilanihc112
CSCE 221-506
leilanihc112@tamu.edu*/
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;
int main() {
regex pattern{ R"(<a href="(.*).ppt">(.*)</a>)" };
ifstream in;
vector<string> to_search;
string temp;
smatch matches;
int i = 0;
in.open("stroustrup.txt");
while (getline(in, temp)) {
	to_search.push_back(temp);
}
for (size_t i = 0; i < to_search.size(); i++)
{
	if (regex_search(to_search[i], matches, pattern)) {
		cout << matches[1]<<".ppt" << endl;
	}
}
return 0;
}
