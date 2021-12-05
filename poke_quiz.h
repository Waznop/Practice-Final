/** Header file for poke_quiz.cpp. Do not alter this file.
@file poke_quiz.h
@author Hong Tai Wei
*/

#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

#ifndef POKE_QUIZ_H
#define POKE_QUIZ_H

// Converts Pikachu's speech into numbers.
int get_answer();

// Sets whether the answer to a math question is correct.
// Returns whether the question is valid.
bool check_answer(int x, char op, int y, int answer, bool& correct);

// Sets the number of correct answers to a series of math questions.
// Returns whether the input arguments are valid.
bool check_answers(const vector<int>& xs, const vector<char>& ops,
                   const vector<int>& ys, const vector<int>& answers,
                   int& num_correct);

// Returns a set of numbers that appear more than once in an input 2D vector.
set<int> frequent_numbers(const vector<vector<int>>& number_lists);

#endif  // POKE_QUIZ_H