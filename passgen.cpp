//#include "stdafx.h"
#include <iostream>
#include <cstdlib> //atoi
#include <ctime> //time
#include <string>
#include <string.h> //for strlen() on linux
#include <iomanip> //setw

using namespace std;
int l, s, n, u;
string a;

char uydur() {
	int len = 0;
	char nb[11] = "0123456789",
		lc[27] = "abcdefghijklmnopqrstuvywxz",
		uc[27] = "ABCDEFGHIJKLMNOPQRSTUVYWXZ",
		sb[16] = "+*_-.()/&#?[]!";
	if (l == 1) { for (int i = 0; i<26; i++) a += lc[i];  len += 26; }
	if (u == 1) { for (int i = 0; i<26; i++) a += uc[i];  len += 26; }
	if (n == 1) { for (int i = 0; i<10; i++) a += nb[i];  len += 10; }
	if (s == 1) { for (int i = 0; i<15; i++) a += sb[i];  len += 14; }
	return a[abs(rand() % len)];
}

int main(int argc, char *argv[]) {
	srand(time(NULL));
	if (argc == 1) {
		cout << "\n";
		cout << "  Usage: crpcn -[options] [numberofcharacters] [numberofpasswords]\n";
		cout << "       Options:\n";
		cout << "        -l   Include lowercase\n";
		cout << "        -u   Include uppercase\n";
		cout << "        -n   Include numbers\n";
		cout << "        -s   Include symbols";
		cout << "\n  "; for (int i = 0; i<20; i++) cout << "---"; cout << endl;
		cout << "    crpcn v0.1 ChrNolan52 | Nov 11 2017 GMT+3 04:03";
		cout << "\n  "; for (int i = 0; i<20; i++) cout << "---"; cout << "\n";
	}

	else if (argc == 4 && argv[1][0] == '-' && (argv[1][1] == 'l' || argv[1][1] == 'u' || argv[1][1] == 's' || argv[1][1] == 'n')) {
		for (int j = 1; j<strlen(argv[1]); j++) {
			
			if (argv[1][j] == 'l') l = 1;
			if (argv[1][j] == 'u') u = 1;
			if (argv[1][j] == 's') s = 1;
			if (argv[1][j] == 'n') n = 1;
			
		}

		int ks = atoi(argv[2]), sayi = atoi(argv[3]);
		string sifre;
		for (int j = 0; j<sayi; j++) {
			for (int i = 0; i<ks; i++) {
				sifre = uydur();
				cout << sifre;
			}
			cout << endl;
		}
		return  0;
	}
	else if (argc<4 && argc>1) cout << "Less than 3 parameter was given" << endl;
	else if (argc>4) cout << "Parameter limit (3) exceeded" << endl;
	else cout << "No option was given" << endl;
}
