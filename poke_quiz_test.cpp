/** Test cases for functions defined in poke_quiz.h
@file poke_quiz_test.cpp
@author Hong Tai Wei
*/

#include "poke_quiz.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <vector>
#include "lib/test_utils.h"
using namespace std;
using ::testing::ContainerEq;

TEST(PokeQuizTest, GetAnswer) {
  string input;
  int expected_output;

  /*********************************************************/
  // Test case
  input = "pi pi pi pi chu";
  expected_output = 4;
  INJECT(input, EXPECT_EQ(get_answer(), expected_output));
  /*********************************************************/

  /*********************************************************/
  // Test case
  input = "ka ka chu";
  expected_output = -2;
  INJECT(input, EXPECT_EQ(get_answer(), expected_output));
  /*********************************************************/

  /*********************************************************/
  // Test case
  input = "pi pi ka chu";
  expected_output = 1;
  INJECT(input, EXPECT_EQ(get_answer(), expected_output));
  /*********************************************************/

  /*********************************************************/
  // Test case
  input = "chu";
  expected_output = 0;
  INJECT(input, EXPECT_EQ(get_answer(), expected_output));
  /*********************************************************/

  // Optional but encouraged: add more tests.
}

TEST(PokeQuizTest, CheckAnswer) {
  int x;
  char op;
  int y;
  int answer;
  bool correct = true;
  bool expected_success;
  bool expected_correct;

  /*********************************************************/
  // Test case
  x = 3;
  op = '*';
  y = 4;
  answer = 12;
  expected_success = true;
  expected_correct = true;
  EXPECT_CHECK_ANSWER(check_answer(x, op, y, answer, correct), correct,
                      expected_success, expected_correct);
  /*********************************************************/

  /*********************************************************/
  // Test case
  x = 3;
  op = 'x';
  y = 4;
  answer = 12;
  expected_success = false;
  EXPECT_CHECK_ANSWER(check_answer(x, op, y, answer, correct), correct,
                      expected_success, expected_correct);
  /*********************************************************/

  /*********************************************************/
  // Test case
  x = 3;
  op = '-';
  y = 4;
  answer = -2;
  expected_success = true;
  expected_correct = false;
  EXPECT_CHECK_ANSWER(check_answer(x, op, y, answer, correct), correct,
                      expected_success, expected_correct);
  /*********************************************************/

  /*********************************************************/
  // Test case
  x = 3;
  op = '%';
  y = 0;
  answer = 12;
  expected_success = false;
  EXPECT_CHECK_ANSWER(check_answer(x, op, y, answer, correct), correct,
                      expected_success, expected_correct);
  /*********************************************************/

  // Optional but encouraged: add more tests.     
}

TEST(PokeQuizTest, CheckAnswers) {
  vector<int> xs;
  vector<char> ops;
  vector<int> ys;
  vector<int> answers;
  int num_correct = 99;
  bool expected_success;
  int expected_num_correct;

  /*********************************************************/
  // Test case
  xs = {1, 4, 2, 7, 0};
  ops = {'+', '-', '*', '/', '%'};
  ys = {2, 9, 5, 5, 3};
  answers = {3, -5, 9, 1, 0};
  expected_success = true;
  expected_num_correct = 4;
  EXPECT_CHECK_ANSWERS(check_answers(xs, ops, ys, answers, num_correct),
                       num_correct, expected_success, expected_num_correct);
  /*********************************************************/

  /*********************************************************/
  // Test case
  xs = {1, 4, 2, 7};
  ops = {'+', '-', '*', '/', '%'};
  ys = {2, 9, 5, 5, 3};
  answers = {3, -5, 9, 1, 0};
  expected_success = false;
  EXPECT_CHECK_ANSWERS(check_answers(xs, ops, ys, answers, num_correct),
                       num_correct, expected_success, expected_num_correct);
  /*********************************************************/

  /*********************************************************/
  // Test case
  xs = {1, 4, 2, 7, 0};
  ops = {'+', '-', '*', '/', '%'};
  ys = {2, 9, 5, 0, 3};
  answers = {3, -5, 9, 1, 0};
  expected_success = false;
  EXPECT_CHECK_ANSWERS(check_answers(xs, ops, ys, answers, num_correct),
                       num_correct, expected_success, expected_num_correct);
  /*********************************************************/

  /*********************************************************/
  // Test case
  xs = {1, 4, 2, 7, 0};
  ops = {'+', '-', '*', '/', '%'};
  ys = {2, 9, 5, 5, 3};
  answers = {100, 100, 100, 100, 100};
  expected_success = true;
  expected_num_correct = 0;
  EXPECT_CHECK_ANSWERS(check_answers(xs, ops, ys, answers, num_correct),
                       num_correct, expected_success, expected_num_correct);
  /*********************************************************/

  // Optional but encouraged: add more tests. 
}

TEST(PokeQuizTest, FrequentNumbers) {
  vector<vector<int>> number_lists;
  set<int> expected_output;

  /*********************************************************/
  // Test case
  number_lists = {{1, 3, 4, 2}, {5, 6, 2, 1}};
  expected_output = {1, 2};
  EXPECT_THAT(frequent_numbers(number_lists), ContainerEq(expected_output));
  /*********************************************************/

  /*********************************************************/
  // Test case
  number_lists = {{1, 3, 4, 2}};
  expected_output = {};
  EXPECT_THAT(frequent_numbers(number_lists), ContainerEq(expected_output));
  /*********************************************************/

  /*********************************************************/
  // Test case
  number_lists = {{4, 3, 1}, {4, 3, 1}, {4, 3, 5}, {4, 3, 1}};
  expected_output = {1, 3, 4};
  EXPECT_THAT(frequent_numbers(number_lists), ContainerEq(expected_output));
  /*********************************************************/

  /*********************************************************/
  // Test case
  number_lists = {};
  expected_output = {};
  EXPECT_THAT(frequent_numbers(number_lists), ContainerEq(expected_output));
  /*********************************************************/

  // Optional but encouraged: add more tests. 
}