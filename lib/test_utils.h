/** Contains test macros. Do not alter this file.
@file test_utils.h
@author Hong Tai Wei
*/

#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#define INJECT(input, stmt)   \
  {                           \
    streambuf *backup;        \
    istringstream oss(input); \
    backup = cin.rdbuf();     \
    cin.rdbuf(oss.rdbuf());   \
    stmt;                     \
    cin.rdbuf(backup);        \
  }

#define EXPECT_CHECK_ANSWER(stmt, actual_correct, expected_success, \
                            expected_correct)                       \
  {                                                                 \
    bool actual_success = stmt;                                     \
    EXPECT_EQ(actual_success, expected_success);                    \
    EXPECT_EQ(actual_correct, expected_correct);                    \
  }

#define EXPECT_CHECK_ANSWERS(stmt, actual_num_correct, expected_success, \
                             expected_num_correct)                       \
  {                                                                      \
    bool actual_success = stmt;                                          \
    EXPECT_EQ(actual_success, expected_success);                         \
    EXPECT_EQ(actual_num_correct, expected_num_correct);                 \
  }

#endif  // TEST_UTILS_H