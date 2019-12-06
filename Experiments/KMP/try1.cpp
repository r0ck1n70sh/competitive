#include <cstdio>
#include <bits/stdc++.h>

void computeLPSArray(char* pat, int M, int* lps);

void KMPSearch(char *pat, char *txt)
{
	int M= strlen(pat);
	int N= strlen(txt);

	int lps[M];

	computeLPSArray(pat, M, lps);
}
