
#include "RK.h"

using namespace std;

#ifdef TEST_RK
/* Driver program */
int main()
{	
	RK rk;
	string txt = "GEEKS FOR GEEKS";
	string pat = "GEEK";
	int q = 101; // A prime number
	rk.search(pat, txt, q);
	return 0;
}

#endif