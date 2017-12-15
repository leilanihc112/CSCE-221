/*Leilani Horlander-Cruz
leilanihc112
CSCE 221-506
leilanihc112@tamu.edu*/
#include <iostream>
#include <string>
#include <regex>
using namespace std;
int main() {
regex pattern{R"(<head>(.*)<title>)"};
regex pattern2{R"(</title>(.*)</head>)"};
string to_search = "<html><head>Wow such a header <title>This is a title</title> So top</head>Much body</html>";
smatch matches;
smatch matches2;
regex_search(to_search, matches, pattern);
regex_search(to_search, matches2, pattern2);
cout << matches[1] << " " << matches2[1] << endl;
return 0;
}
