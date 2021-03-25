///////////////////
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


int isUpper = 0;	//global variable, holds how many uppercase letters are in word that's being searched for


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:	convertToLower(string word, int length)
// RETURN TYPE:		string
// DESCRIPTION:		This function recieves the word being searched for (string word) and the length of that word (length) as
//					parameters.  The function then converts that word into all lowercase letters (string wordLower), returning  
//					it to the calling function findMatch().  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string convertToLower(string word, int length){


	string wordLower;		//holds lowercase version of word
	char lower[length];		//array which holds individual characters that make up word (needed to evaluate case of each letter)

	for(int y = 0; y < length; y++){	//convert the word we're searching for to an array of chars called lower[]
		lower[y] = word.at(y);			//extract each character from word and put in lower[]
	}

	//create lowercase version of the word being searched for
	for(int x = 0; x < length; x++){
				
		if(isupper(lower[x])){				//if the character is uppercase
			lower[x] = tolower(lower[x]);	//convert to lowercase
			isUpper++;						//keep track of how many uppercase letters have been found
		}
		wordLower = wordLower + lower[x];	//concatenate into new all-lowercase version of word
	}

	return wordLower;		//return lowercase version of word
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:	isValid(string word, int length, int size)
// RETURN TYPE: 	boolean
// DESCRIPTION: 	This function determines the validity of the word being searched for.  The word cannot have any numbers or
//					special characters, and must be less than or equal to the size of the array letters.  This function returns
//					a boolean, AlphaValid, which is true if the search word is valid, and false if it is invalid.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool isValid(string word, int length, int size){	//check if the word being searched for contains invalid characters

    bool AlphaValid;					//true if word is valid, false if not valid
    char Theword[length];				//array which holds each character of the word being searched for

    for(int y = 0; y < length; y++) {
		Theword[y] = word.at(y);		//extract each character of word into array Theword
	}

	for (int x = 0; x < length; x++){
        if (isalpha(Theword[x])){		//check each character for non-alphbetical characters
            AlphaValid = true;			//if alphabetical, AlphaValid = true
        }
    	else{
            AlphaValid = false;			//if not alphabetical, AlphaValid = false
            x = length;					//exits the for-loop as soon as non-alphabetical character is found

			cout << "Word " << word << " contains invalid characters." << endl;
        }            
    }


	if(length > size){					//check the length of the word compared to size
		AlphaValid = false;
		cout << "Word " << word << " is " << (length-size) << " character(s) too long." << endl;
	}

    return AlphaValid;					//return true if size and characters of word are valid, false if invalid
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// FUNCTION NAME:	findMatch(vector<Location *> * locations, char *letters, int size, string word)
// RETURN TYPE:		integer
// DESCRIPTION:		This function searches for a word in the grid (2-D array).  When a match is found, a new object, loc (class
//					Location) is created, with members ptr, horizontal, and score.  Ptr holds the location where the word is 
//					found, horizontal is true or false depending on if the match is horizontal or not, and score is the
//					individual word score.  The function returns an integer, totalScore, which is the sum total of all of the
//					individual word scores.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int findMatch(vector<Location *> * locations, char *letters, int size, string word) {
/* In genericTests():
			vector<Location *> locations;
			char letters1[4][4] = { { 'a', 'c', 'g', 't' },
									{ 'a', 'c', 't', 'g' },
									{ 'a', 'c', 'g', 't' },
									{ 'a', 'c', 't', 'g' } };				*/

	//cout << "letters:" << letters << endl;

	int totalScore = 0;			//cumulative score
	int count = 0;				//counts how many matches there are
	float score = 0;			//individual word score

	bool horizBool = false;		//true if match is horizontal, false if vertical/no match
	int length = word.size();	//size of the word we are searching for
	int offset;					//offset of start of test word

	char c;						//temporary character in for loop
	string temp;				//temporary string in for loop
	string wordLower;			//holds lowercase version of the word being searched for

	int vert_offset = 0;            // Vertical offset to go through the cols for vertical check
	

	cout << endl << "word: " << word << "   length: " << length << endl;

	if(bool validWord = isValid(word, length, size)){ 		//perform searches only if word is valid (proper length and characters)

		/////////////////////////////////////////HORIZONTAL SEARCH///////////////////////////////////////////////

		for(int i = 0; i < size; i++){		//go through the rows

			for(int j = 0; j < (size - length + 1); j++){	//go through the cols

				// form word
				offset = (i * size) + j;			// starting position in letters
				for(int k = 0; k < length; ++k){
					c = letters[offset + k];		//extract a character c, from letters
					temp = temp + c;				//concatenate c with temp, which holds a possible match for comparison
																	
				}
				
				//get the lowercase version of the word being searched for
				wordLower = convertToLower(word, length);
				
				if((temp == word) || (temp == wordLower)){		//if temp is an exact match to word, or the all-lowercase version of word
					cout << " horizontal match! ";
					count++;


					Location * loc = new Location();		//new dynamic object called loc
					horizBool = true;						//horizontal match = true						

					//score the match
					score = (((100.0/length)/2.0) * isUpper) + ((100.0/length) * (length - isUpper));
					
					cout << "found at row:" << i << " column:" << j << endl;
					

					//dynamic object loc holds address of a match, horizBool, and score
					loc->ptr = &letters[offset];	//if a match is found, save the (beginning of the) location of the match to loc->ptr
					loc->horizontal = horizBool;	//if a horizontal match is found, horizBool = true
					loc->score = score;				//score of the individual match

					locations->push_back( loc );	//push_back (add) another object, loc, to the locations vector
					totalScore += loc->score;		//sum up all the scores to get a total score
				}
				temp = "";						//reset temp string
				wordLower = "";					//reset lowercase word string
				isUpper = 0;					//reset uppercase letter counter


			}	//end for loop
		}	//end for loop

		

	///////////////////////////////////////////////VERTICAL SEARCH////////////////////////////////////////////////////


		for(int i = 0; i < size ; i++){		//go through the rows

			for(int j = 0; j < size ; j++){	 //go through the cols

				// form word
				offset = (i * size) + j;			// starting position in letters
				for(int k = 0; k < length; ++k)
				{
					c = letters[offset + vert_offset];		//extract a character c, from letters
					temp = temp + c;				        //concatenate c with temp, which holds a possible match for comparison
					vert_offset += size;                  	// Addition of size to stay in the same col and go to the next line (vertical path)
				}

				//get the lowercase version of the word being searched for
				wordLower = convertToLower(word, length);

				if ( ( temp == word ) || ( temp == wordLower ) ){		//if temp is an exact match to word, or the all-lowercase version of word
					
					cout << " vertical match! ";
					
					count++ ;
				
					Location * loc = new Location();		//new dynamic object called loc
					
					horizBool = false ;						//horizontal match = false

					//score the match
					score = ( ( ( 100.0/length ) /2.0) * isUpper) + ( ( 100.0/length ) * ( length - isUpper ) );

					cout << "found at row:" << i << " column:" << j << endl;


					//dynamic object loc holds address of a match, horizBool, and score
					loc->ptr = &letters[offset];	//if a match is found, save the (beginning of the) location of the match to loc->ptr					
					loc->horizontal = horizBool;	//if a vertical match is found, horizBool = false					
					loc->score = score;				//score of the individual match					
					locations->push_back( loc );	//push_back (add) another object, loc, to the locations vector
					
					totalScore += loc->score;		//sum up all the scores to get a total score
				
				}
				
				temp = "";						//reset temp string		
				wordLower = "";					//reset lowercase word string				
				isUpper = 0;					//reset uppercase letter counter				
				vert_offset = 0;				//reset vertical offset


			}	//end for loop

		}	//end for loop
	}	//end if
	else{
		totalScore = -1;
	}

	if(totalScore == 0)
		cout << " match not found. " << endl;

	cout << endl << "count: " << count << " total score: " << totalScore << endl << endl;

	return totalScore;
}
