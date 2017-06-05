

#include <string>
#include "KMP.h"

using namespace std;

#ifdef TEST_KMP

// Driver program
int main()
{	
	KMP kmp;

	string txt = "ABABDABACDABABCABAB";
	string pat = "ABA";

	kmp.KMPSearch(pat, txt);

	return 0;
}

#endif