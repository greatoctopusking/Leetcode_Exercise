#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	int m;
	int res = 0;
	scanf("%d", &m);
	cin.ignore();
	while (m--) {
		res = 0;
		getline(cin, s);
		for (char c : s) {
			if ('0' <= c && c <= '9')res++;
		}
		printf("%d\n", res);
	}
	return 0;
}