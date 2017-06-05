
#include "AC.h"

#ifdef TEST_AC

void print(const char* str)
{
	//cout << "found substring " << str << "\n";
}

int main()
{
	AC ak;
	ak.addString("test");
	ak.addString("str");
	ak.addString("stri");
	ak.addString("strin");
	ak.addString("g");
	ak.addString("x");

	ak.init();
	ak.search("test string!", print);
	return 0;
}

#endif