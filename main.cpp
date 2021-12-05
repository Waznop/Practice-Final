/** Driver for the Pokemon math quiz program.
@file main.cpp
@author Hong Tai Wei
*/

#include <iostream>
#include "poke_quiz.h"
using namespace std;

int main() {
  vector<char> valid_ops = {'+', '-', '*', '/', '%'};
  vector<int> xs;
  vector<char> ops;
  vector<int> ys;
  vector<int> answers;
  int n = 5;
  srand(time(0));

  cout << "Welcome to the Pokemon Math Quiz!\n"
          "Please answer the following questions using:\n"
          "\tpi (+1), ka (-1) and chu (submit answer)\n";
  cout << endl;

  for (int i = 0; i < n; i++) {
    xs.push_back(rand() % 10);
    ops.push_back(valid_ops[rand() % valid_ops.size()]);
    ys.push_back(rand() % 10);
    cout << i + 1 << ". " << xs[i] << " " << ops[i] << " " << ys[i] << " = ?"
         << endl;
    answers.push_back(get_answer());
    cout << "You answered: " << answers[i] << endl;
    cout << endl;
  }

  int num_correct = 0;
  if (check_answers(xs, ops, ys, answers, num_correct)) {
    cout << "You got " << num_correct << " answers right!" << endl;
  } else {
    cout << "Invalid test..." << endl;
  }

  cout << endl;
  cout << "Here are the numbers that appeared >1x: ";
  set<int> freq = frequent_numbers({xs, ys, answers});
  for (int el : freq) {
    cout << el << " ";
  }
  cout << endl;
}