
#include "BO.h"

#ifdef TEST_BO
/* Driver program */

int main(int argc, char * argv[]) 
{	
	BO bo;
	bo.shiftAnd("ababab", "ababxabababababa"); 
	return 0;
}
#endif