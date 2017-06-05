
#include "ST.h"

using namespace std;
  
#ifdef TEST_ST
// driver program to test above functions
int main(int argc, char *argv[])
{	
	ST st;
    
	st.text = "GEEKSFORGEEKS$";

	st.buildSuffixTree();
    
	printf("Text: GEEKSFORGEEKS, Pattern to search: GEEKS");
    st.checkForSubString("GEEKS");

    printf("\n\nText: GEEKSFORGEEKS, Pattern to search: GEEK1");
    st.checkForSubString("GEEK1");
    
	printf("\n\nText: GEEKSFORGEEKS, Pattern to search: FOR");
    st.checkForSubString("FOR");
    
	//Free the dynamically allocated memory
    st.freeSuffixTreeByPostOrder(st.root);

	st.text = "AABAACAADAABAAABAA$";
	st.buildSuffixTree();
	printf("\n\nText: AABAACAADAABAAABAA, Pattern to search: AABA");
	st.checkForSubString("AABA");
	printf("\n\nText: AABAACAADAABAAABAA, Pattern to search: AA");
	st.checkForSubString("AA");
	printf("\n\nText: AABAACAADAABAAABAA, Pattern to search: AAE");
	st.checkForSubString("AAE");
	//Free the dynamically allocated memory
	st.freeSuffixTreeByPostOrder(st.root);


    return 0;
}

#endif