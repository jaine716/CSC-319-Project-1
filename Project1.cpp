// Project1.cpp : 
// Jaine Perotti
// Riley Smith
// Levy Sanon
///////////////////

#include "Project1.h"
#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include <cmath>

using std::cout;
using std::endl;
using std::string;
using std::vector; 

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

//findMatch looks for word in the grid (2-d array) 
//locations holds everywhere you find the word
//word is word youre looking for
	
int findMatch(vector<Location *> * locations, char *letters, int size, string word) {
/* In genericTests():
			vector<Location *> locations;
			char letters1[4][4] = { { 'a', 'c', 'g', 't' },
									{ 'a', 'c', 't', 'g' },
									{ 'a', 'c', 'g', 't' },
									{ 'a', 'c', 't', 'g' } };				*/

	int totalScore = 0;		//cumulative score
	int count = 0;			//counts how many matches there are
	int score = 0;			//individual word score
	int line  = 0;			//line of a match
	int col = 0;			//column of a match

	bool horizBool = false;		//true if match is horizontal, false if vertical
	int length = word.size();	//size of the word we are searching for

	char c;			//temporary character in for loop
	string temp;	//temporary string in for loop

	Location * loc = new Location();		//new dynamic object called loc, Location class which has members ptr, horizontal, & score

	
	cout << endl << "word: " << word << "   length: " << length << endl;

	for(int i = 0; i < (size*size); i++){		//go through all 16 elements in letters (size=4)

		for(int j = 0; j < length; j++){


			if((i+j) > 15)		//don't go outside bounds of vector
				break;
					
			c = letters[i+j];
			temp = temp + c;

		// letters[i] ==> if int i/4 has no remainder, you're in a new row
		// I want to find a good way to stop the search from "running into" the next row
		//	if( (remainder((i+j),size) == 0) && ((i+j) != 0))		
		//		break;

		}	//end nested for

		if(temp == word){
			cout << " match! ";

			horizBool = true;
			line = i/size;
			score = 100;

			//0,4,8,12 => column 0; 1,5,9,13 => column 1; 2,6,10,14 => column 2; 3,7,11,15 => column 3
			if( (i == 0) || (i == 4) || (i == 8) || (i == 12) )
				col = 0;
			if ( (i == 1) || (i == 5) || (i == 9) || (i == 13) )
				col = 1;
			if ( (i == 2) || (i == 6) || (i == 10) || (i == 14) )
				col = 2;
			if ( (i == 3) || (i == 7) || (i == 11) || (i == 15) )
				col = 3;
			count++;

			cout << "found at line:" << line << " column:" << col <<  " count: " << count << endl;

			//if a match is found, save the (beginning of the) location of the match to loc->ptr
			loc->ptr = &letters[ (line * size) + col ]; //this will 't'
			//loc->ptr = &letters[i];
			loc->horizontal = horizBool;	
			loc->score = score;	

			//cout << loc->ptr << " " << loc->horizontal << " " << loc->score << endl;

			locations->push_back( loc );
			totalScore += loc->score;
			
		}	//end if statement

		//cout << temp << "  *  ";		//use this to print out temp as the vector is searched
		temp = "";						//reset temp string
		
	}	//end for loop

	cout << endl << "count: " << count << " total score: " << totalScore << endl << endl;


	return totalScore;
}
