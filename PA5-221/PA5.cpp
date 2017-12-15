/*
Leilani Horlander-Cruz
523008771
leilanihc112
CSCE 221-506
leilanihc112@tamu.edu
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <regex>
#include <unordered_map>

using namespace std;

struct record {
	string UIN;
	string grade;
};

ifstream openFile(string fileName){
	ifstream input;
	input.open(fileName);
	return input;
}

ofstream outFile(string fileName) {
	ofstream output;
	output.open(fileName);
	return output;
}

int main() {
	const string file1 = "input.csv";
	const string file2 = "roster.csv";
	const string file3 = "output.csv";
	ifstream input = openFile(file1);
	regex pattern{R"(,(\d{9}),(\d{2}))"};
	vector<string> to_search;
	string temp;
	smatch matches;
	unordered_map<string,record> records;
	record tempRecord;
	int i = 0;
	while (getline(input, temp)) 
	{
		to_search.push_back(temp);
	}
	for (int i = 0; i < to_search.size(); i++)
	{
		if (regex_search(to_search[i], matches, pattern)) 
		{
			tempRecord.UIN = matches[1];
			tempRecord.grade = matches[2];
			records.insert(pair<string, record>(tempRecord.UIN,tempRecord));
		}
	}
	int minimum = 0;
	int maximum = 0;
	for (unsigned i = 1; i < records.bucket_count(); i++)
	{
		if (records.bucket_size(i) < minimum)
			minimum = records.bucket_size(i);
		else if (records.bucket_size(i) > maximum)
			maximum = records.bucket_size(i);
	}
	cout << "minimum length of linked lists: " << minimum << endl;
	cout << "maximum length of linked lists: " << maximum << endl;
	cout << "average length of linked lists: " << records.load_factor() << endl;

	ifstream input2 = openFile(file2);
	ofstream output = outFile(file3);
	regex pattern2{R"(,(\d{9}))"};
	vector<string> to_search2, UINs;
	smatch matches2;
	while (getline(input2, temp)) 
	{
		to_search2.push_back(temp);
	}
	for (int i = 0; i < to_search2.size(); i++)
	{
		if (regex_search(to_search2[i], matches2, pattern2)) 
		{
			UINs.push_back(matches2[1]);
		}
	}
	unordered_map<string,record>::iterator it;
	for (int i = 0; i < UINs.size(); i++)
	{
		it = records.find(UINs[i]);
		if (it == records.end()) 
		{
			output << to_search2[i] << endl;
		}
		else 
		{
			output << to_search2[i] << it->second.grade << "," << endl;
		}
	}
	return 0;
}
