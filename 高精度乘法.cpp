#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int a[10000000000], b[10000000000], c[10000000000];
#define asd int main()

asd {
	
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	for (int i = 0; i < s1.length(); i++)
		a[i] = s1[i] - '0';
	for (int i = 0; i < s2.length(); i++)
		b[i] = s2[i] - '0';
	for (int i = 0; i <= s1.length(); i++)

		for (int j = 0; j <= s2.length(); j++) {
			c[i + j] += a[i] * b[j];
			if (c[i + j] >= 10) {
				c[i + j + 1] += c[i + j] / 10;
				c[i + j] %= 10;
			}
		}
	int p = 0;
	for (int i = s1.length() + s2.length(); i >= 0; i--)

		if (c[i]) {
			p = i;
			break;
		}
	for (int i = p; i >= 0; i--)
		printf("%d", c[i]);
	return 0;
}
