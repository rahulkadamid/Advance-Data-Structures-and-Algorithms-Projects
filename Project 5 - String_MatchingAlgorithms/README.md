# Project 5 - String_MatchingAlgorithms

## Data Structures and Algorithms Used:
1. AhoCorasick
2. BitOriented
3. BoyerMoore
4. KnuthMorrisPratt
5. RabinKarp
6. SuffixTree

### Part 1:
![image](https://user-images.githubusercontent.com/19743074/37562392-4f0e5948-2a3d-11e8-82fc-0bc19750beac.png)

As seen from chart above, the Boyer-Moore algorithm performs best among the three, while 
Rabin-Karp algorithm performs worst and about constant time. 
Performance of Knuth-Morris-Pratt algorithm is about average among three algorithms. 

### Part 2:
Bit-Oriented Approach:	  	->      Total Time: 1545

Aho-Chorasick Algorithm: 	->      Total Time: 1315

From above timings, we can conclude that Aho-Chorasick Algorithm performs better than its counterpart Bit-Oriented Approach.

### Part 3:
![image](https://user-images.githubusercontent.com/19743074/37562400-76e8cade-2a3d-11e8-9185-d6066c6d079a.png)

Above chart concludes that Suffix Tree beats the performance of all three algorithms - Boyer-Moore algorithm, Rabin-Karp algorithm and Knuth-Morris-Pratt algorithm.
Hence, Building a Suffix Tree is considered best approach for String Matching.
