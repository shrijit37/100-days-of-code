// A line formed by a child from n stones of two colors, blue and green. The stones were picked up by the child randomly and he formed a line from those initially. As the child loves green color the most, he started moving the green stone forward to blue stones. Each stone move forward per second.

// Assume that the stones arranged in 1 to n sequentially, position 1 treated as prior. If at some time X a blue stone is on i-th position and a green stone is on the (i+1)-th position, then at X+1 time green stone will have i-th position and blue stone will have (i+1)-th position. X is in seconds.

// You have given the initial sequence of stones. Predict the sequence after t seconds.

// Input Format
// The first line contains two integers n and t (1 ≤ n, t ≤ 50), number of stones and time after which you have predict the sequence.
// The next line contains the string s, which represents the initial sequence. ‘B’ as blue stone and ‘G’ as green stone.
// Output Format
// A single string that denotes the sequence after t seconds.

// Constraints
// 1 ≤ n, t ≤ 50
// Sample Input 1 
// 5 1
// BGGBG
// Sample Output 1 
// GBGGB
// Sample Input 2 
// 5 2
// BGGBG
// Sample Output 2 
// GGBGB
// Sample Input 3 
// 4 1
// GGGB
// Sample Output 3 
// GGGB


#include<bits/stdc++.h>
using namespace std;

int main