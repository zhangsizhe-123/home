#include <bits/stdc++.h>
using namespace std;

void GJjia () {
	int a [ 10000 ], b [ 10000 ], c [ 10000 ];
	char s [ 10000 ];
	int i;
	cin >> s;
	int n = strlen ( s );
	for ( i = 0 ; i < n ; i++ ) {
		a [ i ] = s [ n - i - 1 ] - '0';
	}
	cin >> s;
	int m = strlen ( s );
	for ( i = 0 ; i < m ; i++ ) {
		b [ i ] = s [ m - i - 1 ] - '0';
	}
	int x = max ( n, m );
	for ( i = 0 ; i < x ; i++ ) {
		c [ i ] += a [ i ] + b [ i ];
		c [ i + 1 ] += c [ i ] / 10;
		c [ i ] %= 10;
	}
	if ( c [ x ] != 0 ) {
		++x;
	}
	for ( i = x - 1 ; i >= 0 ; i-- ) {
		printf ("%d", c [ i ] );
	}
}

int main() {
	GJjia ();
	return 0;
}
