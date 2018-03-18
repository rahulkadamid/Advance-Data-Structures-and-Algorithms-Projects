
#include "BM.h"

using namespace std;

#ifdef TEST_BM

/* Driver program */
int main()
{	
	BM bm;
	string txt = "ABCAABCD";
	string pat = "ABC";
	bm.search(txt, pat);
	return 0;
}

#endif