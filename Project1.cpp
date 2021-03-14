// Project1.cpp : 
// Jaine Perotti
// Riley Smith
// Levy Sanon
///////////////////

#include "Project1.h"

//locations : all the location where the word was found in letters
//letter	: matrix of char [size][size], where you look for the word
//size		: the size of the matrix: size X size
//word		: the word you are searching for
//
//the word can be either horizontally or vertically
//
// Location.score: each word you find in letters, can have a different score.
//                 each letter will have a score, that you sum to calculate the 
//                 score of the word you found in letters
//                 the score is based on 100%. 
//                 Each letter of word has a maximum score of 100 / word.length
//                 If the letter has the same case (uppercase, lowercase), the letter
//                 has 100 / word.length. If the case is not the case, it has (100 / word.length) / 2 for score.
//				   If the word you are searching for is 4 letters, each
//				   letter you match will be 25%. If a letter match, but not its case, it is 12.5%.
//
// If you find a word, its score > 50% to be added locations.
/*
	Grading       : 
	                10 unit tests x 7 pts each           = 70
					4 additional unit tests x 5 pts each = 20 -- must check additional cases
					program structure                    = 10
					total                                = 100
	Your grade will be calculated on the last test your program manage to successfully execute, based on the 
	order in Project1Test.
	
	Program that do not compile will receive a grade of 0.

	Submission    : one submission per team
*/

int findMatch(vector<Location *> * locations, char *letters, int size, string word) {
	int count = 0;
	//add your code here
	
	
	return count;
}
