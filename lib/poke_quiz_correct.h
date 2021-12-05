/** Correct implementations of poke_quiz.h. Do not alter this file.
@file poke_quiz_correct.h
@author Hong Tai Wei
*/

#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

#ifndef POKE_QUIZ_CORRECT_H
#define POKE_QUIZ_CORRECT_H

int get_answer_correct();

bool check_answer_correct(int x, char op, int y, int answer, bool& correct);

bool check_answers_correct(const vector<int>& xs, const vector<char>& ops,
                           const vector<int>& ys, const vector<int>& answers,
                           int& num_correct);

set<int> frequent_numbers_correct(const vector<vector<int>>& number_lists);

#endif  // POKE_QUIZ_CORRECT_H