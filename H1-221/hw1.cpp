// Leilani Horlander-Cruz
// CSCE 221-506
// HW 1 Binary Search Algorithm

#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

void Binary_Search(const vector<int> A, int n, int x)
{
	int low = 1, mid, high = n, c = 0;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (A[mid-1] < x) 
		{
			low = mid + 1;
			c++;
		}
		else if (A[mid-1] > x) 
		{
			high = mid - 1;
			c++;
		}
		else if (A[mid-1] == x) 
		{
			low = high + 1;
			c++;
		}
	}
	if (x == A[mid-1])
		cout << "The value is " << A[mid-1] << " and there were " << c << " comparisons.\n";
	else
		cout << "The value was not found in the vector.\n";
}

void Insert_Sort(vector<int>& n)
{
	int j, t, l;
	l = n.size();
	for (int i = 0; i < l; i++)
	{
		j = i;
		while (j > 0 && n[j] < n[j-1])
		{
			t = n[j];
			n[j] = n[j-1];
			n[j-1] = t;
			j--;
		}
	}
}

void Generate_Vector(vector<int>& n)
{
	int size;
    cout << "What is the nth element?" << endl;
    cin >> size;
	for (int i = 1; i <= size; i++) 
	{
		n.push_back(i);
	}
}

void Display_Vector(const vector<int>& n) {
	for (int i = 0; i < n.size(); i++)
	{
		cout << n[i] << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> n;
	int x;
	Generate_Vector(n);
	Insert_Sort(n);
	Display_Vector(n);
	cout << "What value do you want to search for?" << endl;
	cin >> x;
	int a = n.size();
	Binary_Search(n,a,x);
}