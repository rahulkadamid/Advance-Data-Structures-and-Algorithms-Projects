
#include "BO.h"

void BO::shiftAnd(string pattern, string text)
{
	int state = 0; int matchBit = 1;

	size_t pattern_length = pattern.length();

	for (size_t i = 1; i < pattern_length; ++i)
		matchBit <<= 1;

	vector<int> charactersInP;

	for (int i = 0; i <= 255; ++i)
		charactersInP.push_back(0);

	for (size_t i = 0, j = 1; i < pattern_length; ++i, j <<= 1)
		charactersInP[pattern[i]] |= j;

	//cout << "search: " << endl;
	int text_length = text.length();
	for (int i = 0; i < text_length; ++i)
	{
		state = ((state << 1) | 1) & charactersInP[text[i]];
		if ((matchBit & state) != 0)
		{
			/*cout << "match at: " << i - (int)pattern.length() + 1;
			cout << endl;;*/
		}
	}
}
