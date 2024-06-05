#include <gtest/gtest.h>

#include <array>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

#include "s21_containersplus.h"

struct Students {
  std::string name;
  std::string position;
  std::string birth;
};

TEST(Queue_Constructor, test_1) {
  s21::Queue<int> Q21;
  std::queue<int> Q;
  EXPECT_EQ(Q21.size(), Q.size());
  EXPECT_EQ(Q21.empty(), Q.empty());
}

TEST(Queue_Constructor, test_2) {
  s21::Queue<int> Q21 = {99, 88, 11, 77};
  EXPECT_EQ(Q21.back(), 77);
  EXPECT_EQ(Q21.front(), 99);
}

TEST(Queue_Constructor, test_3) {
  s21::Queue<float> Q21 = {9.9, 8.8, 1.1, 7.7};
  s21::Queue<float> Q211 = Q21;
  EXPECT_EQ(Q21.size(), Q211.size());
  EXPECT_EQ(Q21.back(), Q211.back());
  EXPECT_EQ(Q21.front(), Q211.front());
  Q21.pop();
  Q211.pop();
  EXPECT_EQ(Q21.size(), Q211.size());
  EXPECT_EQ(Q21.front(), Q211.front());
}

TEST(Queue_Constructor, test_4) {
  s21::Queue<char> Q21 = {'h', 'e', 'l', 'l', 'o'};
  s21::Queue<char> Q211(std::move(Q21));
  s21::Queue<char> Q213 = {'h', 'e', 'l', 'l', 'o'};
  EXPECT_TRUE(Q21.empty());
  s21::Queue<char> Q212;
  Q212 = std::move(Q213);
  EXPECT_TRUE(Q213.empty());
  EXPECT_EQ(Q211.front(), 'h');
}

TEST(Queue_Push_pop, test_5) {
  s21::Queue<int> Q21;
  std::queue<int> Q;
  Q21.push(77);
  Q21.push(88);
  Q21.push(99);
  Q.push(77);
  Q.push(88);
  Q.push(99);
  EXPECT_EQ(Q21.size(), Q.size());
  EXPECT_EQ(Q21.back(), Q.back());
  EXPECT_EQ(Q21.front(), Q.front());
  Q21.pop();
  Q.pop();
  EXPECT_EQ(Q21.size(), Q.size());
  EXPECT_EQ(Q21.front(), Q.front());
}

TEST(Queue_Swap, test_6) {
  s21::Queue<float> Q21 = {9.9, 8.8, 1.1, 7.7};
  s21::Queue<float> Q211 = {0.9, 0.8, 0.1, 0.7, 0.5};
  s21::Queue<float> Q2 = {9.9, 8.8, 1.1, 7.7};
  s21::Queue<float> Q22 = {0.9, 0.8, 0.1, 0.7, 0.5};
  Q21.swap(Q211);

  EXPECT_EQ(Q21.size(), Q22.size());
  EXPECT_EQ(Q21.back(), Q22.back());
  EXPECT_EQ(Q211.front(), Q2.front());
  EXPECT_EQ(Q21.front(), Q22.front());
  EXPECT_EQ(Q211.back(), Q2.back());
}

TEST(Queue_Front_back, test_7) {
  s21::Queue<int> Q21;
  EXPECT_ANY_THROW(Q21.front());
  EXPECT_ANY_THROW(Q21.back());
  EXPECT_ANY_THROW(Q21.pop());
}

TEST(Queue_Struct, test_8) {
  Students stu0;
  stu0.birth = {"December"};
  stu0.name = {"Name0"};
  Students stu1;
  stu1.name = {"Name1"};
  s21::Queue<Students> Q;
  Q.push(stu0);
  Q.push(stu1);
  EXPECT_EQ(Q.front().name, "Name0");
  EXPECT_EQ(Q.front().birth, "December");
  EXPECT_EQ(Q.back().name, "Name1");
  Q.pop();
  EXPECT_EQ(Q.back().name, "Name1");
}

TEST(Queue_insert_many_back, test_9) {
  s21::Queue<int> Q1 = {99, 88, 11, 77};
  Q1.insert_many_back(33, 66, 77, 88, 101, 123, 123456);
  EXPECT_EQ(Q1.back(), 123456);
  Q1.pop();
  EXPECT_EQ(Q1.front(), 88);
}

TEST(stack_Constructor, test_10) {
  s21::Stack<int> S21;
  std::stack<int> S;
  EXPECT_EQ(S21.size(), S.size());
  EXPECT_EQ(S21.empty(), S.empty());
}

TEST(stack_Constructor, test_11) {
  s21::Stack<int> S21 = {99, 88, 11, 77};
  EXPECT_EQ(S21.top(), 77);
}

TEST(stack_Constructor, test_12) {
  s21::Stack<float> S21 = {9.9, 8.8, 1.1, 7.7};
  s21::Stack<float> S211 = S21;
  EXPECT_EQ(S21.size(), S211.size());
  EXPECT_EQ(S21.top(), S211.top());
  S21.pop();
  S211.pop();
  EXPECT_EQ(S21.size(), S211.size());
  EXPECT_EQ(S21.top(), S211.top());
}

TEST(stack_Constructor, test_13) {
  s21::Stack<char> S21 = {'h', 'e', 'l', 'l', 'o'};
  s21::Stack<char> S211(std::move(S21));
  s21::Stack<char> S213 = {'h', 'e', 'l', 'l', 'o'};
  EXPECT_TRUE(S21.empty());
  s21::Stack<char> S212;
  S212 = std::move(S213);
  EXPECT_TRUE(S213.empty());
  EXPECT_EQ(S211.top(), 'o');
}

TEST(stack_Push_pop, test_14) {
  s21::Stack<int> S21;
  std::stack<int> S;
  S21.push(77);
  S21.push(88);
  S21.push(99);
  S.push(77);
  S.push(88);
  S.push(99);
  EXPECT_EQ(S21.size(), S.size());
  EXPECT_EQ(S21.top(), S.top());
  S21.pop();
  S.pop();
  EXPECT_EQ(S21.size(), S.size());
  EXPECT_EQ(S21.top(), S.top());
}

TEST(stack_Swap, test_15) {
  s21::Stack<float> S21 = {9.9, 8.8, 1.1, 7.7};
  s21::Stack<float> S211 = {0.9, 0.8, 0.1, 0.7, 0.5};
  s21::Stack<float> S2 = {9.9, 8.8, 1.1, 7.7};
  s21::Stack<float> S22 = {0.9, 0.8, 0.1, 0.7, 0.5};
  S21.swap(S211);

  EXPECT_EQ(S21.size(), S22.size());
  EXPECT_EQ(S21.top(), S22.top());
  EXPECT_EQ(S211.top(), S2.top());
}

TEST(stack_Front_back, test_16) {
  s21::Stack<int> S21;
  EXPECT_ANY_THROW(S21.top());
  EXPECT_ANY_THROW(S21.pop());
}

TEST(stack_Struct, test_17) {
  Students stu0;
  stu0.birth = {"December"};
  stu0.name = {"Name0"};
  Students stu1;
  stu1.name = {"Name1"};
  stu1.birth = {"May"};
  s21::Stack<Students> S;
  S.push(stu0);
  S.push(stu1);
  EXPECT_EQ(S.top().birth, "May");
  EXPECT_EQ(S.top().name, "Name1");
  S.pop();
  EXPECT_EQ(S.top().name, "Name0");
}

TEST(stack_insert_many_front, test_18) {
  s21::Stack<int> S1 = {99, 88, 11, 77};
  S1.insert_many_front(33, 66, 77, 88, 101, 123, 123456);
  EXPECT_EQ(S1.top(), 123456);
  S1.pop();
  EXPECT_EQ(S1.top(), 123);
}

TEST(Array_Constructor, test_19) {
  s21::Array<int, 0> A21;
  std::array<int, 0> A;
  EXPECT_EQ(A21.size(), A.size());
  EXPECT_EQ(A21.empty(), A.empty());
}

TEST(Array_Constructor, test_20) {
  s21::Array<int, 4> A21 = {99, 88, 11, 77};
  EXPECT_EQ(A21.back(), 77);
  EXPECT_EQ(A21.front(), 99);
  s21::Array<int, 4> A11 = {1, 2, 3, 4};
  EXPECT_EQ(A11.back(), 4);
  EXPECT_EQ(A11.front(), 1);
}

TEST(Array_Constructor, test_21) {
  s21::Array<float, 4> A21 = {9.9, 8.8, 1.1, 7.7};
  s21::Array<float, 4> A211 = A21;
  EXPECT_EQ(A21.size(), A211.size());
  EXPECT_EQ(A21.back(), A211.back());
  EXPECT_EQ(A21.front(), A211.front());
}

TEST(Array_Constructor, test_22) {
  s21::Array<char, 5> A21 = {'h', 'e', 'l', 'l', 'o'};
  s21::Array<char, 5> A211(std::move(A21));
  s21::Array<char, 5> A213 = {'h', 'e', 'l', 'l', 'o'};
  EXPECT_TRUE(A21.empty());
  s21::Array<char, 5> A212;
  A212 = std::move(A213);
  EXPECT_TRUE(A213.empty());
  EXPECT_EQ(A211.back(), 'o');
}

TEST(Array_Swap, test_23) {
  s21::Array<float, 4> A21 = {9.9, 8.8, 1.1, 7.7};
  s21::Array<float, 4> A211 = {0.9, 0.8, 0.1, 0.7};
  s21::Array<float, 4> A2 = {9.9, 8.8, 1.1, 7.7};
  s21::Array<float, 4> A22 = {0.9, 0.8, 0.1, 0.7};
  A21.swap(A211);

  EXPECT_EQ(A21.size(), A22.size());
  EXPECT_EQ(A21.max_size(), A22.max_size());
  EXPECT_EQ(A21.front(), A22.front());
  EXPECT_EQ(A211.front(), A2.front());
  EXPECT_FLOAT_EQ(A21.at(2), 0.1);
}

TEST(Array_Fill, test_24) {
  s21::Array<int, 5> A21;
  A21.fill(999);
  EXPECT_EQ(A21.front(), 999);
  EXPECT_EQ(A21.back(), 999);
}

TEST(Array_throw, test_25) {
  s21::Array<int, 0> A21;
  EXPECT_ANY_THROW(A21.back());
  EXPECT_ANY_THROW(A21.front());
  EXPECT_ANY_THROW(A21.fill(3));
  s21::Array<int, 4> A11;
  EXPECT_ANY_THROW(A11.at(5));
}

TEST(Array_iterator, test_26) {
  s21::Array<int, 5> A21 = {99, 88, 11, 77};
  auto it = A21.begin();
  EXPECT_EQ(*it, 99);
  s21::Array<int, 5> Array;
  for (s21::Array<int, 5>::iterator it = Array.begin(); it != Array.end();
       ++it) {
    Array.fill(25);
  }
  EXPECT_EQ(Array.front(), 25);
  auto qwer = A21.data();
  EXPECT_EQ(*qwer, 99);
  std::array<int, 5> AS = {99, 88, 11, 77};
  auto wert = AS.data();
  EXPECT_EQ(*wert, 99);
}

TEST(Array_maxsize, test_27) {
  s21::Array<int, 3> A21;
  std::array<int, 3> A;
  EXPECT_EQ(A21.max_size(), A.max_size());
}

//________________________________________________LIST_____________________
TEST(LIST, case1) {
  s21::List<int> s21_list_int;
  s21::List<double> s21_list_double;
  s21::List<std::string> s21_list_string;

  EXPECT_EQ(s21_list_int.size(), 0U);
  EXPECT_EQ(s21_list_double.size(), 0U);
  EXPECT_EQ(s21_list_string.size(), 0U);
}

TEST(LIST, case2) {
  s21::List<int> s21_list_int(5);
  s21::List<double> s21_list_double(5);
  s21::List<std::string> s21_list_string(5);

  EXPECT_EQ(s21_list_int.size(), 5U);
  EXPECT_EQ(s21_list_double.size(), 5U);
  EXPECT_EQ(s21_list_string.size(), 5U);
}

TEST(LIST, case3) {
  EXPECT_THROW(s21::List<int> s21_list_int(0), std::out_of_range);
  EXPECT_THROW(s21::List<double> s21_list_double(0), std::out_of_range);
  EXPECT_THROW(s21::List<std::string> s21_list_string(0), std::out_of_range);
}

TEST(LIST, case4) {
  s21::List<int> s21_list_int{1, 4, 8, 9};
  s21::List<double> s21_list_double{1.4, 4.8, 8.9, 9.1};
  s21::List<std::string> s21_list_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_list_int.size(), 4U);
  EXPECT_EQ(s21_list_int.front(), 1);

  EXPECT_EQ(s21_list_double.size(), 4U);
  EXPECT_EQ(s21_list_double.front(), 1.4);

  EXPECT_EQ(s21_list_string.size(), 4U);
  EXPECT_EQ(s21_list_string.front(), "Hello");
}

TEST(LIST, case5) {
  s21::List<int> s21_list_ref_int{1, 4, 8, 9};
  s21::List<int> s21_list_res_int(s21_list_ref_int);

  s21::List<double> s21_list_ref_double{1.4, 4.8, 8.9, 9.1};
  s21::List<double> s21_list_res_double(s21_list_ref_double);

  s21::List<std::string> s21_list_ref_string{"Hello", ",", "world", "!"};
  s21::List<std::string> s21_list_res_string(s21_list_ref_string);

  EXPECT_EQ(s21_list_res_int.size(), 4U);
  EXPECT_EQ(s21_list_res_int.front(), 1);

  EXPECT_EQ(s21_list_res_double.size(), 4U);
  EXPECT_EQ(s21_list_res_double.front(), 1.4);

  EXPECT_EQ(s21_list_res_string.size(), 4U);
  EXPECT_EQ(s21_list_res_string.front(), "Hello");
}

TEST(LIST, case6) {
  s21::List<int> s21_list_ref_int{1, 4, 8, 9};
  s21::List<int> s21_list_res_int = s21_list_ref_int;

  s21::List<double> s21_list_ref_double{1.4, 4.8, 8.9, 9.1};
  s21::List<double> s21_list_res_double = s21_list_ref_double;

  s21::List<std::string> s21_list_ref_string{"Hello", ",", "world", "!"};
  s21::List<std::string> s21_list_res_string = s21_list_ref_string;

  EXPECT_EQ(s21_list_res_int.size(), 4U);
  EXPECT_EQ(s21_list_res_int.front(), 1);

  EXPECT_EQ(s21_list_res_double.size(), 4U);
  EXPECT_EQ(s21_list_res_double.front(), 1.4);

  EXPECT_EQ(s21_list_res_string.size(), 4U);
  EXPECT_EQ(s21_list_res_string.front(), "Hello");
}

TEST(LIST, case7) {
  s21::List<int> s21_list_ref_int;
  s21::List<int> s21_list_res_int = s21_list_ref_int;

  s21::List<double> s21_list_ref_double;
  s21::List<double> s21_list_res_double = s21_list_ref_double;

  s21::List<std::string> s21_list_ref_string;
  s21::List<std::string> s21_list_res_string = s21_list_ref_string;

  EXPECT_EQ(s21_list_res_int.size(), 0U);
  EXPECT_EQ(s21_list_res_double.size(), 0U);
  EXPECT_EQ(s21_list_res_string.size(), 0U);
}

TEST(LIST, case8) {
  s21::List<int> s21_list_ref_int{1, 4, 8, 9};
  s21::List<int> s21_list_res_int = std::move(s21_list_ref_int);

  s21::List<double> s21_list_ref_double{1.4, 4.8, 8.9, 9.1};
  s21::List<double> s21_list_res_double = std::move(s21_list_ref_double);

  s21::List<std::string> s21_list_ref_string{"Hello", ",", "world", "!"};
  s21::List<std::string> s21_list_res_string = std::move(s21_list_ref_string);

  EXPECT_EQ(s21_list_ref_int.size(), 0U);
  EXPECT_EQ(s21_list_res_int.size(), 4U);
  EXPECT_EQ(s21_list_res_int.front(), 1);

  EXPECT_EQ(s21_list_ref_double.size(), 0U);
  EXPECT_EQ(s21_list_res_double.size(), 4U);
  EXPECT_EQ(s21_list_res_double.front(), 1.4);

  EXPECT_EQ(s21_list_ref_string.size(), 0U);
  EXPECT_EQ(s21_list_res_string.size(), 4U);
  EXPECT_EQ(s21_list_res_string.front(), "Hello");
}

TEST(LIST, case9) {
  s21::List<int> s21_list_ref_int{1, 4, 8, 9};
  s21::List<int> s21_list_res_int;
  s21_list_res_int = std::move(s21_list_ref_int);

  s21::List<double> s21_list_ref_double{1.4, 4.8, 8.9, 9.1};
  s21::List<double> s21_list_res_double;
  s21_list_res_double = std::move(s21_list_ref_double);

  s21::List<std::string> s21_list_ref_string{"Hello", ",", "world", "!"};
  s21::List<std::string> s21_list_res_string;
  s21_list_res_string = std::move(s21_list_ref_string);

  EXPECT_EQ(s21_list_ref_int.size(), 0U);
  EXPECT_EQ(s21_list_res_int.size(), 4U);
  EXPECT_EQ(s21_list_res_int.front(), 1);

  EXPECT_EQ(s21_list_ref_double.size(), 0U);
  EXPECT_EQ(s21_list_res_double.size(), 4U);
  EXPECT_EQ(s21_list_res_double.front(), 1.4);

  EXPECT_EQ(s21_list_ref_string.size(), 0U);
  EXPECT_EQ(s21_list_res_string.size(), 4U);
  EXPECT_EQ(s21_list_res_string.front(), "Hello");
}

TEST(LIST, case10) {
  s21::List<int> a = {43, 43, 43, 5};
  s21::List<int> b = {1};
  a = std::move(b);
  EXPECT_EQ(a.back(), 1);
}

TEST(LIST, case11) {
  size_t n = 1e4;
  s21::List<int> lst(n);
  EXPECT_EQ(lst.size(), n);
  EXPECT_TRUE(lst.max_size() != 0);
  lst.pop_back();
  lst.pop_front();
  EXPECT_EQ(lst.size(), (n - 2));
  int back = lst.back();
  int front = lst.front();
  EXPECT_EQ(back, 0);
  EXPECT_EQ(front, 0);
}

TEST(LIST, case12) {
  s21::List<double> lst = {1.032, 2.320,    3.0,   4.0,   5.0,
                           6.0,   7.000043, 8.324, 9.343, 10.0};
  EXPECT_EQ(lst.size(), 10U);
  double front = lst.front();
  EXPECT_DOUBLE_EQ(front, 1.032);
  lst.pop_front();
  double new_front = lst.front();
  EXPECT_DOUBLE_EQ(new_front, 2.320);
  lst.pop_back();
  double back = lst.back();
  EXPECT_DOUBLE_EQ(back, 9.343);
  EXPECT_EQ(lst.size(), 8U);
  lst.clear();
  EXPECT_EQ(lst.size(), 0U);
}

TEST(LIST, case13) {
  s21::List<double> lst = {1.032, 2.32,     3.0,   4.0,   5.0,
                           6.0,   7.000043, 8.324, 9.343, 10.0};
  s21::List<double> lst_cpy(lst);
  EXPECT_EQ(lst_cpy.size(), 10U);
  double front = lst_cpy.front();
  EXPECT_DOUBLE_EQ(front, 1.032);
  lst_cpy.pop_front();
  double new_front = lst_cpy.front();
  EXPECT_DOUBLE_EQ(new_front, 2.320);
  double back = lst_cpy.back();
  EXPECT_DOUBLE_EQ(back, 10.0);
  lst_cpy.pop_back();
  back = lst_cpy.back();
  EXPECT_DOUBLE_EQ(back, 9.343);
  EXPECT_EQ(lst_cpy.size(), 8U);
}

TEST(LIST, case14) {
  s21::List<double> lst = {1.032, 2.32,     3.0,   4.0,   5.0,
                           6.0,   7.000043, 8.324, 9.343, 10.0};
  s21::List<double> lst_cpy(std::move(lst));
  EXPECT_EQ(lst_cpy.size(), 10U);
  double front = lst_cpy.front();
  EXPECT_DOUBLE_EQ(front, 1.032);
  lst_cpy.pop_front();
  double new_front = lst_cpy.front();
  EXPECT_DOUBLE_EQ(new_front, 2.320);
  double back = lst_cpy.back();
  EXPECT_DOUBLE_EQ(back, 10.0);
  lst_cpy.pop_back();
  back = lst_cpy.back();
  EXPECT_DOUBLE_EQ(back, 9.343);
  EXPECT_EQ(lst_cpy.size(), 8U);
  EXPECT_EQ(lst.size(), 0U);
}

TEST(LIST, case15) {
  std::list<int> orig_list = {};
  s21::List<int> lst = {};
  auto orig_itr_end = orig_list.end();
  auto itr_end = lst.end();
  EXPECT_EQ(*orig_itr_end, *itr_end);
}

TEST(LIST, case16) {
  std::list<int> orig_list;
  s21::List<int> lst;
  auto orig_itr = orig_list.end();
  auto itr = lst.end();
  EXPECT_EQ(*orig_itr, *itr);
}

TEST(LIST_PUSH_FRONT, case1) {
  s21::List<int> s21_list_int{1, 4, 8, 9};
  s21::List<double> s21_list_double{1.4, 4.8, 8.9, 9.1};
  s21::List<std::string> s21_list_string{"Hello", ",", "world", "!"};

  s21_list_int.push_front(33);
  s21_list_double.push_front(33.0);
  s21_list_string.push_front("33");

  EXPECT_EQ(s21_list_int.size(), 5U);
  EXPECT_EQ(s21_list_int.front(), 33);

  EXPECT_EQ(s21_list_double.size(), 5U);
  EXPECT_EQ(s21_list_double.front(), 33.0);

  EXPECT_EQ(s21_list_string.size(), 5U);
  EXPECT_EQ(s21_list_string.front(), "33");
}

TEST(LIST_PUSH_FRONT, case2) {
  s21::List<int> s21_list_int;
  s21::List<double> s21_list_double;
  s21::List<std::string> s21_list_string;

  s21_list_int.push_front(33);
  s21_list_double.push_front(33.0);
  s21_list_string.push_front("33");

  EXPECT_EQ(s21_list_int.size(), 1U);
  EXPECT_EQ(s21_list_int.front(), 33);

  EXPECT_EQ(s21_list_double.size(), 1U);
  EXPECT_EQ(s21_list_double.front(), 33.0);

  EXPECT_EQ(s21_list_string.size(), 1U);
  EXPECT_EQ(s21_list_string.front(), "33");
}

TEST(LIST_PUSH_FRONT, case3) {
  s21::List<int> s21_list_int{1};
  s21::List<double> s21_list_double{1.0};
  s21::List<std::string> s21_list_string{"1"};

  s21_list_int.push_front(33);
  s21_list_double.push_front(33.0);
  s21_list_string.push_front("33");

  EXPECT_EQ(s21_list_int.size(), 2U);
  EXPECT_EQ(s21_list_int.front(), 33);

  EXPECT_EQ(s21_list_double.size(), 2U);
  EXPECT_EQ(s21_list_double.front(), 33.0);

  EXPECT_EQ(s21_list_string.size(), 2U);
  EXPECT_EQ(s21_list_string.front(), "33");
}

TEST(LIST_PUSH_FRONT, case4) {
  s21::List<int> lol = {1, 2, 10, 3, 4, 6, 43};
  std::list<int> lol_orig = {1, 2, 10, 3, 4, 6, 43};
  lol.push_front(21);
  lol_orig.push_front(21);
  auto itr_orig = lol_orig.begin();
  for (auto itr = lol.begin(); itr != lol.end(); itr++) {
    EXPECT_EQ(*itr, *itr_orig);
    itr_orig++;
  }

  s21::List<int> lol1;
  std::list<int> lol_orig1;
  lol1.push_front(21);
  lol_orig1.push_front(21);
  auto itr_orig1 = lol_orig1.begin();
  for (auto itr1 = lol1.begin(); itr1 != lol1.end(); itr1++) {
    EXPECT_EQ(*itr1, *itr_orig1);
    itr_orig1++;
  }
}

TEST(LIST_PUSH_BACK, case1) {
  s21::List<int> s21_list_int{1, 4, 8, 9};
  s21::List<double> s21_list_double{1.4, 4.8, 8.9, 9.1};
  s21::List<std::string> s21_list_string{"Hello", ",", "world", "!"};

  s21_list_int.push_back(33);
  s21_list_double.push_back(33.0);
  s21_list_string.push_back("33");

  EXPECT_EQ(s21_list_int.size(), 5U);
  EXPECT_EQ(s21_list_int.back(), 33);

  EXPECT_EQ(s21_list_double.size(), 5U);
  EXPECT_EQ(s21_list_double.back(), 33.0);

  EXPECT_EQ(s21_list_string.size(), 5U);
  EXPECT_EQ(s21_list_string.back(), "33");
}

TEST(LIST_PUSH_BACK, case2) {
  s21::List<int> s21_list_int;
  s21::List<double> s21_list_double;
  s21::List<std::string> s21_list_string;

  s21_list_int.push_back(33);
  s21_list_double.push_back(33.0);
  s21_list_string.push_back("33");

  EXPECT_EQ(s21_list_int.size(), 1U);
  EXPECT_EQ(s21_list_int.back(), 33);

  EXPECT_EQ(s21_list_double.size(), 1U);
  EXPECT_EQ(s21_list_double.back(), 33.0);

  EXPECT_EQ(s21_list_string.size(), 1U);
  EXPECT_EQ(s21_list_string.back(), "33");
}

TEST(LIST_PUSH_BACK, case3) {
  s21::List<int> s21_list_int{1};
  s21::List<double> s21_list_double{1.0};
  s21::List<std::string> s21_list_string{"1"};

  s21_list_int.push_back(33);
  s21_list_double.push_back(33.0);
  s21_list_string.push_back("33");

  EXPECT_EQ(s21_list_int.size(), 2U);
  EXPECT_EQ(s21_list_int.back(), 33);

  EXPECT_EQ(s21_list_double.size(), 2U);
  EXPECT_EQ(s21_list_double.back(), 33.0);

  EXPECT_EQ(s21_list_string.size(), 2U);
  EXPECT_EQ(s21_list_string.back(), "33");
}

TEST(LIST_POP_FRONT, case1) {
  s21::List<int> s21_list_int{1, 4, 8, 9};
  s21::List<double> s21_list_double{1.4, 4.8, 8.9, 9.1};
  s21::List<std::string> s21_list_string{"Hello", ",", "world", "!"};

  s21_list_int.pop_front();
  s21_list_double.pop_front();
  s21_list_string.pop_front();

  EXPECT_EQ(s21_list_int.size(), 3U);
  EXPECT_EQ(s21_list_int.front(), 4);

  EXPECT_EQ(s21_list_double.size(), 3U);
  EXPECT_EQ(s21_list_double.front(), 4.8);

  EXPECT_EQ(s21_list_string.size(), 3U);
  EXPECT_EQ(s21_list_string.front(), ",");
}

TEST(LIST_POP_FRONT, case2) {
  s21::List<int> s21_list_int{1};
  s21::List<double> s21_list_double{1.0};
  s21::List<std::string> s21_list_string{"1"};

  s21_list_int.pop_front();
  s21_list_double.pop_front();
  s21_list_string.pop_front();

  EXPECT_EQ(s21_list_int.size(), 0U);
  EXPECT_EQ(s21_list_double.size(), 0U);
  EXPECT_EQ(s21_list_string.size(), 0U);
}

TEST(LIST_POP_FRONT, case3) {
  s21::List<int> lol = {1, 2, 10, 3, 4, 6, 43};
  std::list<int> lol_orig = {1, 2, 10, 3, 4, 6, 43};
  lol.pop_front();
  lol_orig.pop_front();
  auto itr_orig = lol_orig.begin();
  for (auto itr = lol.begin(); itr != lol.end(); itr++) {
    EXPECT_EQ(*itr, *itr_orig);
    itr_orig++;
  }
}

TEST(LIST_POP_BACK, case1) {
  s21::List<int> s21_list_int{1, 4, 8, 9};
  s21::List<double> s21_list_double{1.4, 4.8, 8.9, 9.1};
  s21::List<std::string> s21_list_string{"Hello", ",", "world", "!"};

  s21_list_int.pop_back();
  s21_list_double.pop_back();
  s21_list_string.pop_back();

  EXPECT_EQ(s21_list_int.size(), 3U);
  EXPECT_EQ(s21_list_int.back(), 8);

  EXPECT_EQ(s21_list_double.size(), 3U);
  EXPECT_EQ(s21_list_double.back(), 8.9);

  EXPECT_EQ(s21_list_string.size(), 3U);
  EXPECT_EQ(s21_list_string.back(), "world");
}

TEST(LIST_POP_BACK, case2) {
  s21::List<int> s21_list_int{1, 2};
  s21::List<double> s21_list_double{1.0, 2.0};
  s21::List<std::string> s21_list_string{"1", "2"};

  s21_list_int.pop_back();
  s21_list_double.pop_back();
  s21_list_string.pop_back();

  EXPECT_EQ(s21_list_int.size(), 1U);
  EXPECT_EQ(s21_list_double.size(), 1U);
  EXPECT_EQ(s21_list_string.size(), 1U);
}

TEST(LIST_FRONT, case1) {
  s21::List<int> s21_list_int{1, 4, 8, 9};
  s21::List<double> s21_list_double{1.4, 4.8, 8.9, 9.1};
  s21::List<std::string> s21_list_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_list_int.front(), 1);
  EXPECT_EQ(s21_list_double.front(), 1.4);
  EXPECT_EQ(s21_list_string.front(), "Hello");
}

TEST(LIST_FRONT, case2) {
  s21::List<char> lol = {'l', 'o', 'l'};
  std::list<char> lol_orig = {'l', 'o', 'l'};
  EXPECT_EQ(lol.front(), lol_orig.front());
}

TEST(back, case1) {
  s21::List<int> s21_list_int{1, 4, 8, 9};
  s21::List<double> s21_list_double{1.4, 4.8, 8.9, 9.1};
  s21::List<std::string> s21_list_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_list_int.back(), 9);
  EXPECT_EQ(s21_list_double.back(), 9.1);
  EXPECT_EQ(s21_list_string.back(), "!");
}

TEST(swap, case1) {
  s21::List<int> s21_list_ref_int{1, 4, 8, 9};
  s21::List<int> s21_list_res_int{12, 13};

  s21::List<double> s21_list_ref_double{1.4, 4.8, 8.9, 9.1};
  s21::List<double> s21_list_res_double{11.0, 12.0, 13.0};

  s21::List<std::string> s21_list_ref_string{"Hello", ",", "world", "!"};
  s21::List<std::string> s21_list_res_string{"12", "13", "14", "15"};

  s21_list_ref_int.swap(s21_list_res_int);
  s21_list_ref_double.swap(s21_list_res_double);
  s21_list_ref_string.swap(s21_list_res_string);

  EXPECT_EQ(s21_list_ref_int.size(), 2U);
  EXPECT_EQ(s21_list_ref_int.front(), 12);
  EXPECT_EQ(s21_list_res_int.size(), 4U);
  EXPECT_EQ(s21_list_res_int.front(), 1);

  EXPECT_EQ(s21_list_ref_double.size(), 3U);
  EXPECT_EQ(s21_list_ref_double.front(), 11.0);
  EXPECT_EQ(s21_list_res_double.size(), 4U);
  EXPECT_EQ(s21_list_res_double.front(), 1.4);

  EXPECT_EQ(s21_list_ref_string.size(), 4U);
  EXPECT_EQ(s21_list_ref_string.front(), "12");
  EXPECT_EQ(s21_list_res_string.size(), 4U);
  EXPECT_EQ(s21_list_res_string.front(), "Hello");
}

TEST(swap, case2) {
  s21::List<int> s21_list_ref_int{1, 4, 8, 9};
  s21::List<int> s21_list_res_int;

  s21::List<double> s21_list_ref_double{1.4, 4.8, 8.9, 9.1};
  s21::List<double> s21_list_res_double;

  s21::List<std::string> s21_list_ref_string{"Hello", ",", "world", "!"};
  s21::List<std::string> s21_list_res_string;

  s21_list_ref_int.swap(s21_list_res_int);
  s21_list_ref_double.swap(s21_list_res_double);
  s21_list_ref_string.swap(s21_list_res_string);

  EXPECT_EQ(s21_list_ref_int.size(), 0U);
  EXPECT_EQ(s21_list_res_int.size(), 4U);
  EXPECT_EQ(s21_list_res_int.front(), 1);

  EXPECT_EQ(s21_list_ref_double.size(), 0U);
  EXPECT_EQ(s21_list_res_double.size(), 4U);
  EXPECT_EQ(s21_list_res_double.front(), 1.4);

  EXPECT_EQ(s21_list_ref_string.size(), 0U);
  EXPECT_EQ(s21_list_res_string.size(), 4U);
  EXPECT_EQ(s21_list_res_string.front(), "Hello");
}

TEST(sort, case1) {
  s21::List<int> s21_list_int{8, 1, 4, 9};
  s21::List<double> s21_list_double{9.1, 1.4, 4.8, 8.9};
  s21::List<std::string> s21_list_string{"hello", "there", "21", "school"};

  s21_list_int.sort();
  s21_list_double.sort();
  s21_list_string.sort();

  EXPECT_EQ(s21_list_int.front(), 1);
  EXPECT_EQ(s21_list_double.front(), 1.4);
  EXPECT_EQ(s21_list_string.front(), "21");
}

TEST(sort, case2) {
  s21::List<int> s21_list_int{8};
  s21::List<double> s21_list_double{9.1};
  s21::List<std::string> s21_list_string{"hello"};

  s21_list_int.sort();
  s21_list_double.sort();
  s21_list_string.sort();

  EXPECT_EQ(s21_list_int.front(), 8);
  EXPECT_EQ(s21_list_double.front(), 9.1);
  EXPECT_EQ(s21_list_string.front(), "hello");
}

TEST(merge, case1) {
  s21::List<int> s21_list_ref_int{1, 4, 8, 9};
  s21::List<int> s21_list_res_int{12, 13};

  s21::List<double> s21_list_ref_double{1.4, 4.8, 8.9, 9.1};
  s21::List<double> s21_list_res_double{11.0, 12.0, 13.0};

  s21::List<std::string> s21_list_ref_string{"Hello", ",", "world", "!"};
  s21::List<std::string> s21_list_res_string{"12", "13", "14", "15"};

  s21_list_res_int.merge(s21_list_ref_int);
  s21_list_res_double.merge(s21_list_ref_double);
  s21_list_res_string.merge(s21_list_ref_string);

  EXPECT_EQ(s21_list_ref_int.size(), 0U);
  EXPECT_EQ(s21_list_res_int.size(), 6U);
  EXPECT_EQ(s21_list_res_int.front(), 1);

  EXPECT_EQ(s21_list_ref_double.size(), 0U);
  EXPECT_EQ(s21_list_res_double.size(), 7U);
  EXPECT_EQ(s21_list_res_double.front(), 1.4);

  EXPECT_EQ(s21_list_ref_string.size(), 0U);
  EXPECT_EQ(s21_list_res_string.size(), 8U);
  EXPECT_EQ(s21_list_res_string.front(), "12");
}

TEST(merge, case2) {
  s21::List<int> s21_list_ref_int{1, 4, 8, 9};
  s21::List<int> s21_list_res_int;

  s21::List<double> s21_list_ref_double{1.4, 4.8, 8.9, 9.1};
  s21::List<double> s21_list_res_double;

  s21::List<std::string> s21_list_ref_string{"Hello", ",", "world", "!"};
  s21::List<std::string> s21_list_res_string;

  s21_list_res_int.merge(s21_list_ref_int);
  s21_list_res_double.merge(s21_list_ref_double);
  s21_list_res_string.merge(s21_list_ref_string);

  EXPECT_EQ(s21_list_ref_int.size(), 0U);
  EXPECT_EQ(s21_list_res_int.size(), 4U);
  EXPECT_EQ(s21_list_res_int.front(), 1);

  EXPECT_EQ(s21_list_ref_double.size(), 0U);
  EXPECT_EQ(s21_list_res_double.size(), 4U);
  EXPECT_EQ(s21_list_res_double.front(), 1.4);

  EXPECT_EQ(s21_list_ref_string.size(), 0U);
  EXPECT_EQ(s21_list_res_string.size(), 4U);
  EXPECT_EQ(s21_list_res_string.front(), "Hello");
}

TEST(merge, case3) {
  s21::List<int> lol = {1, 2, 10, 3, 4, 6, 43};
  std::list<int> lol_orig = {1, 2, 10, 3, 4, 6, 43};
  s21::List<int> list_merge = {2, 5, 7, 9};
  std::list<int> list_merge_orig = {2, 5, 7, 9};
  lol.sort();
  lol_orig.sort();
  lol.merge(list_merge);
  lol_orig.merge(list_merge_orig);
  auto itr_orig = lol_orig.begin();
  for (auto itr = lol.begin(); itr != lol.end(); itr++) {
    EXPECT_EQ(*itr, *itr_orig);
    itr_orig++;
  }
}

TEST(reverse, case1) {
  s21::List<int> s21_list_int{1, 4, 8, 9};
  s21::List<double> s21_list_double{1.4, 4.8, 8.9, 9.1};
  s21::List<std::string> s21_list_string{"Hello", ",", "world", "!"};

  s21_list_int.reverse();
  s21_list_double.reverse();
  s21_list_string.reverse();

  EXPECT_EQ(s21_list_int.front(), 9);
  EXPECT_EQ(s21_list_double.front(), 9.1);
  EXPECT_EQ(s21_list_string.front(), "!");
}

TEST(reverse, case2) {
  s21::List<int> s21_list_int{1};
  s21::List<double> s21_list_double{1.4};
  s21::List<std::string> s21_list_string{"Hello"};

  s21_list_int.reverse();
  s21_list_double.reverse();
  s21_list_string.reverse();

  EXPECT_EQ(s21_list_int.front(), 1);
  EXPECT_EQ(s21_list_double.front(), 1.4);
  EXPECT_EQ(s21_list_string.front(), "Hello");
}

TEST(unique, case1) {
  s21::List<int> s21_list_int{1, 1, 4, 4, 8, 8, 8, 9, 9, 9, 9, 9};
  s21::List<double> s21_list_double{1.4, 4.8, 1.4, 4.8, 8.9, 9.1,
                                    1.4, 4.8, 8.9, 8.9, 9.1};
  s21::List<std::string> s21_list_string{"Hello", ",",     "Hello", ",",
                                         "world", ",",     "world", "!",
                                         "!",     "world", "!"};

  s21_list_int.unique();
  s21_list_double.unique();
  s21_list_string.unique();

  EXPECT_EQ(s21_list_int.size(), 4U);
  EXPECT_EQ(s21_list_double.size(), 10U);
  EXPECT_EQ(s21_list_string.size(), 10U);
}

TEST(unique, case2) {
  s21::List<int> s21_list_int{1, 4, 8, 9};
  s21::List<double> s21_list_double{1.4, 4.8, 8.9, 9.1};
  s21::List<std::string> s21_list_string{"Hello", ",", "world", "!"};

  s21_list_int.unique();
  s21_list_double.unique();
  s21_list_string.unique();

  EXPECT_EQ(s21_list_int.size(), 4U);
  EXPECT_EQ(s21_list_double.size(), 4U);
  EXPECT_EQ(s21_list_string.size(), 4U);
}

TEST(unique, case3) {
  s21::List<int> s21_list_int;
  s21::List<double> s21_list_double;
  s21::List<std::string> s21_list_string;

  s21_list_int.unique();
  s21_list_double.unique();
  s21_list_string.unique();

  EXPECT_EQ(s21_list_int.size(), 0U);
  EXPECT_EQ(s21_list_double.size(), 0U);
  EXPECT_EQ(s21_list_string.size(), 0U);
}

TEST(size, case1) {
  s21::List<int> s21_list_int{1, 4, 8, 9};
  s21::List<double> s21_list_double{1.4, 4.8, 8.9, 9.1};
  s21::List<std::string> s21_list_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_list_int.size(), 4U);
  EXPECT_EQ(s21_list_double.size(), 4U);
  EXPECT_EQ(s21_list_string.size(), 4U);
}

TEST(size, case2) {
  s21::List<int> s21_list_int;
  s21::List<double> s21_list_double;
  s21::List<std::string> s21_list_string;

  EXPECT_EQ(s21_list_int.size(), 0U);
  EXPECT_EQ(s21_list_double.size(), 0U);
  EXPECT_EQ(s21_list_string.size(), 0U);
}

TEST(max_size, case1) {
  s21::List<int> s21_list_int{1, 4, 8, 9};
  std::list<int> std_list_int{1, 4, 8, 9};

  s21::List<double> s21_list_double{1.4, 4.8, 8.9, 9.1};
  std::list<double> std_list_double{1.4, 4.8, 8.9, 9.1};

  s21::List<std::string> s21_list_string{"Hello", ",", "world", "!"};
  std::list<std::string> std_list_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_list_int.max_size(), std_list_int.max_size());
  EXPECT_EQ(s21_list_double.max_size(), std_list_double.max_size());
  EXPECT_EQ(s21_list_string.max_size(), std_list_string.max_size());
}

TEST(LIST_EMPTY, case1) {
  s21::List<int> s21_list_int{1, 4, 8, 9};
  s21::List<double> s21_list_double{1.4, 4.8, 8.9, 9.1};
  s21::List<std::string> s21_list_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_list_int.empty(), 0);
  EXPECT_EQ(s21_list_double.empty(), 0);
  EXPECT_EQ(s21_list_double.empty(), 0);
}

TEST(LIST_EMPTY, case2) {
  s21::List<int> s21_list_int;
  s21::List<double> s21_list_double;
  s21::List<std::string> s21_list_string;

  EXPECT_EQ(s21_list_int.empty(), 1);
  EXPECT_EQ(s21_list_double.empty(), 1);
  EXPECT_EQ(s21_list_double.empty(), 1);
}

TEST(LIST_EMPTY, case3) {
  s21::List<int> lol;
  std::list<int> lol_orig;
  EXPECT_EQ(lol.front(), lol_orig.front());
}

TEST(LIST_EMPTY, case4) {
  s21::List<int> lol;
  std::list<int> lol_orig;
  EXPECT_EQ(lol.back(), lol_orig.back());
}

TEST(LIST_EMPTY, case5) {
  std::list<int> orig_list(5);
  s21::List<int> lst(5);
  auto orig_itr = orig_list.end();
  auto itr = lst.end();
  EXPECT_EQ(*orig_itr, *itr);
}

TEST(LIST_INSERT, case1) {
  s21::List<int> s21_list_int{1, 4, 8, 9};
  s21::List<double> s21_list_double{1.4, 4.8, 8.9, 9.1};
  s21::List<std::string> s21_list_string{"Hello", ",", "world", "!"};

  auto it_int = s21_list_int.begin();
  it_int = s21_list_int.insert(it_int, 13);
  it_int += 2;
  it_int = s21_list_int.insert(it_int, 13);
  EXPECT_EQ(s21_list_int.front(), 13);
  EXPECT_EQ(*(s21_list_int.begin() + 2), 13);

  auto it_double = s21_list_double.begin();
  it_double = s21_list_double.insert(it_double, 21.0);
  it_double += 2;
  it_double = s21_list_double.insert(it_double, 21.0);
  EXPECT_EQ(s21_list_double.front(), 21.0);
  EXPECT_EQ(*(s21_list_double.begin() + 2), 21.0);

  auto it_string = s21_list_string.begin();
  it_string = s21_list_string.insert(it_string, "HI");
  it_string += 2;
  it_string = s21_list_string.insert(it_string, "HI");
  EXPECT_EQ(s21_list_string.front(), "HI");
  EXPECT_EQ(*(s21_list_string.begin() + 2), "HI");
}

TEST(LIST_INSERT, case2) {
  s21::List<int> s21_list_int;
  s21::List<double> s21_list_double;
  s21::List<std::string> s21_list_string;

  auto it_int = s21_list_int.begin();
  it_int = s21_list_int.insert(it_int, 13);
  EXPECT_EQ(s21_list_int.front(), 13);

  auto it_double = s21_list_double.begin();
  it_double = s21_list_double.insert(it_double, 21.0);
  EXPECT_EQ(s21_list_double.front(), 21.0);

  auto it_string = s21_list_string.begin();
  it_string = s21_list_string.insert(it_string, "HI");
  EXPECT_EQ(s21_list_string.front(), "HI");
}

TEST(LIST_INSERT, case3) {
  s21::List<int> s21_list_int{1};
  s21::List<double> s21_list_double{1.0};
  s21::List<std::string> s21_list_string{"1"};

  auto it_int = s21_list_int.begin();
  it_int = s21_list_int.insert(it_int, 13);
  EXPECT_EQ(s21_list_int.front(), 13);

  auto it_double = s21_list_double.begin();
  it_double = s21_list_double.insert(it_double, 21.0);
  EXPECT_EQ(s21_list_double.front(), 21.0);

  auto it_string = s21_list_string.begin();
  it_string = s21_list_string.insert(it_string, "HI");
  EXPECT_EQ(s21_list_string.front(), "HI");
}

TEST(LIST_INSERT, case4) {
  s21::List<int> lol;
  std::list<int> lol_orig;
  auto itr = lol.begin();
  auto itr_orig = lol_orig.begin();
  itr = lol.insert(itr, 21);
  itr_orig = lol_orig.insert(itr_orig, 21);
  EXPECT_EQ(*itr, *itr_orig);

  s21::List<int> lol1 = {1, 2, 3, 4, 6, 43};
  std::list<int> lol_orig1 = {1, 2, 3, 4, 6, 43};
  auto itr1 = lol1.begin();
  auto itr_orig1 = lol_orig1.begin();
  itr1 = lol1.insert(itr1, 21);
  itr_orig1 = lol_orig1.insert(itr_orig1, 21);
  auto end1 = lol1.end();
  auto end_orig1 = lol_orig1.end();
  while (itr1 != end1 && itr_orig1 != end_orig1) {
    EXPECT_EQ(*itr1, *itr_orig1);
    itr1++;
    itr_orig1++;
  }

  s21::List<int> lol2 = {1, 2, 3, 4, 6, 44};
  std::list<int> lol_orig2 = {1, 2, 3, 4, 6, 44};
  auto itr2 = lol2.end();
  auto itr_orig2 = lol_orig2.end();
  itr2 = lol2.insert(itr2, 21);
  itr_orig2 = lol_orig2.insert(itr_orig2, 21);
  while (itr2 != lol2.begin() && itr_orig2 != lol_orig2.begin()) {
    EXPECT_EQ(*itr2, *itr_orig2);
    itr2--;
    itr_orig2--;
  }
}

TEST(LIST_SPLICE, case1) {
  s21::List<int> s21_list_ref_int{3, 5};
  s21::List<int> s21_list_res_int{1, 4, 8, 9};

  s21::List<double> s21_list_ref_double{5.6, 7.1};
  s21::List<double> s21_list_res_double{1.4, 4.8, 8.9, 9.1};

  s21::List<std::string> s21_list_ref_string{"Hi"};
  s21::List<std::string> s21_list_res_string{"Hello", ",", "world", "!"};

  auto it_int = s21_list_res_int.begin();
  s21_list_res_int.splice(it_int, s21_list_ref_int);
  EXPECT_EQ(*(s21_list_res_int.begin()), 3);
  EXPECT_EQ(*(s21_list_res_int.begin() + 1), 5);

  auto it_double = s21_list_res_double.begin();
  s21_list_res_double.splice(it_double, s21_list_ref_double);
  EXPECT_EQ(*(s21_list_res_double.begin()), 5.6);
  EXPECT_EQ(*(s21_list_res_double.begin() + 1), 7.1);

  auto it_string = s21_list_res_string.begin();
  s21_list_res_string.splice(it_string, s21_list_ref_string);
  EXPECT_EQ(*(s21_list_res_string.begin()), "Hi");
}

TEST(LIST_SPLICE, case2) {
  s21::List<int> s21_list_ref_int;
  s21::List<int> s21_list_res_int{1, 4, 8, 9};

  s21::List<double> s21_list_ref_double;
  s21::List<double> s21_list_res_double{1.4, 4.8, 8.9, 9.1};

  s21::List<std::string> s21_list_ref_string;
  s21::List<std::string> s21_list_res_string{"Hello", ",", "world", "!"};

  auto it_int = s21_list_res_int.begin();
  s21_list_res_int.splice(it_int, s21_list_ref_int);
  EXPECT_EQ(*(s21_list_res_int.begin()), 1);

  auto it_double = s21_list_res_double.begin();
  s21_list_res_double.splice(it_double, s21_list_ref_double);
  EXPECT_EQ(*(s21_list_res_double.begin()), 1.4);

  auto it_string = s21_list_res_string.begin();
  s21_list_res_string.splice(it_string, s21_list_ref_string);
  EXPECT_EQ(*(s21_list_res_string.begin()), "Hello");
}

TEST(LIST_SPLICE, case3) {
  s21::List<int> s21_list_ref_int{1, 4, 8, 9};
  s21::List<int> s21_list_res_int;

  s21::List<double> s21_list_ref_double{1.4, 4.8, 8.9, 9.1};
  s21::List<double> s21_list_res_double;

  s21::List<std::string> s21_list_ref_string{"Hello", ",", "world", "!"};
  s21::List<std::string> s21_list_res_string;

  auto it_int = s21_list_res_int.begin();
  s21_list_res_int.splice(it_int, s21_list_ref_int);
  EXPECT_EQ(*(s21_list_res_int.begin()), 1);

  auto it_double = s21_list_res_double.begin();
  s21_list_res_double.splice(it_double, s21_list_ref_double);
  EXPECT_EQ(*(s21_list_res_double.begin()), 1.4);

  auto it_string = s21_list_res_string.begin();
  s21_list_res_string.splice(it_string, s21_list_ref_string);
  EXPECT_EQ(*(s21_list_res_string.begin()), "Hello");
}

TEST(LIST_EMPLACE_BACK, case1) {
  s21::List<int> our = {1, 2, 7, 8, 9};
  our.emplace_back(4, 5, 6);
  EXPECT_EQ(our.back(), 6);
}

TEST(LIST_EMPLACE_BACK, case2) {
  s21::List<int> our;
  our.emplace_back(4, 5, 6);
  EXPECT_EQ(our.back(), 6);
  EXPECT_EQ(our.front(), 4);
}

TEST(LIST_EMPLACE_FRONT, case1) {
  s21::List<int> our{1, 2, 7, 8, 9};
  our.emplace_front(4, 5, 6);
  EXPECT_EQ(our.front(), 6);
}

TEST(LIST_EMPLACE_FRONT, case2) {
  s21::List<int> our;
  our.emplace_front(4, 5, 6);
  EXPECT_EQ(our.front(), 6);
  EXPECT_EQ(our.back(), 4);
}
TEST(LIST_ITERATOR, case1) {
  s21::List<int> lol = {1, 2, 3, 4, 6, 43};
  std::list<int> lol_orig = {1, 2, 3, 4, 6, 43};
  unsigned int n = lol.size();
  unsigned int n_orig = lol_orig.size();
  EXPECT_EQ(n, n_orig);
  auto itr = lol.begin();
  auto itr_orig = lol_orig.begin();
  auto end = lol.end();
  auto end_orig = lol_orig.end();
  while (itr != end && itr_orig != end_orig) {
    EXPECT_EQ(*itr, *itr_orig);
    itr++;
    itr_orig++;
  }
}

TEST(LIST_ITERATOR, case2) {
  s21::List<int> lol = {1, 2, 3, 4, 6, 43};
  std::list<int> lol_orig = {1, 2, 3, 4, 6, 43};
  unsigned int n = lol.size();
  unsigned int n_orig = lol_orig.size();
  EXPECT_EQ(n, n_orig);
  auto itr = lol.end();
  auto itr_orig = lol_orig.end();
  auto end = lol.begin();
  auto end_orig = lol_orig.begin();
  while (true) {
    if (itr == end && itr_orig == end_orig) {
      break;
    }
    EXPECT_EQ(*itr, *itr_orig);
    itr--;
    itr_orig--;
  }
}

TEST(LIST_ITERATOR, case3) {
  s21::List<int> lol = {1, 2, 3, 4, 6, 43};
  auto itr = lol.begin() + 1;
  EXPECT_EQ(*itr, 2);
}

TEST(LIST_ITERATOR, case4) {
  s21::List<int> lol = {1, 2, 3, 4, 6, 43};
  auto itr = lol.end() - 1;
  EXPECT_EQ(*itr, 43);
}

TEST(LIST_ITERATOR, case5) {
  s21::List<int> lol = {1, 2, 3, 4, 6, 43};
  auto itr = lol.end();
  itr -= 1;
  EXPECT_EQ(*itr, 43);
}

//________________________________________________VECTOR___________________
TEST(Vector_Constructor_def, test_1) {
  s21::Vector<int> V21;
  std::vector<int> V;
  EXPECT_EQ(V21.size(), V.size());
  EXPECT_EQ(V21.empty(), V.empty());
}

TEST(Vector_Constructor_param, test_2) {
  s21::Vector<double> V21(5);
  std::vector<double> V(5);
  EXPECT_EQ(V21.size(), V.size());
  for (s21::Vector<double>::Iterator i = V21.begin(); i != V21.end(); ++i) {
    for (std::vector<double>::iterator j = V.begin(); j != V.end(); ++j) {
      EXPECT_DOUBLE_EQ(*i, *j);
    }
  }
}

TEST(Vector_Constructor_list, test_3) {
  s21::Vector<int> V21({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
  std::vector<int> V({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
  EXPECT_EQ(V21.size(), V.size());
  for (int i = 0; i < 11; ++i) {
    EXPECT_EQ(V21.at(i), V.at(i));
  }
}

TEST(Vector_Copy_Constructor, test_4) {
  s21::Vector<float> V21({0.01, 0.1, 0.2, 0.3, 0.4});
  s21::Vector<float> V21_copy(V21);
  std::vector<float> V({0.01, 0.1, 0.2, 0.3, 0.4});
  std::vector<float> V_copy(V);
  EXPECT_EQ(V21.size(), V21_copy.size());
  EXPECT_EQ(V21_copy.size(), V_copy.size());
  for (int i = 0; i < 5; ++i) {
    EXPECT_FLOAT_EQ(V21_copy[i], V[i]);
  }
}

TEST(Vector_Operator_assignment, test_5) {
  s21::Vector<char> V21(5);
  V21.push_back('H');
  V21.push_back('E');
  V21.push_back('L');
  V21.push_back('L');
  V21.push_back('0');
  s21::Vector<char> V21_a;
  V21_a = V21;
  EXPECT_EQ(V21.size(), V21_a.size());
  for (int i = 0; i < 5; ++i) {
    EXPECT_EQ(V21.at(i), V21_a.at(i));
  }
  EXPECT_EQ(V21.front(), V21_a.front());
  EXPECT_EQ(V21.back(), V21_a.back());
}

TEST(Vector_move, test_6) {
  s21::Vector<int> V21;
  s21::Vector<int> V21_move;
  for (int i = 0; i < 100; ++i) {
    V21.push_back(i);
  }
  V21_move = std::move(V21);
  EXPECT_EQ(V21.size(), 0);
  EXPECT_EQ(V21_move.size(), 100);
}

TEST(Vector_move_1, test_7) {
  s21::Vector<double> V21_move({0.11, -0.09876, 9.89, -98765, 0101});
  s21::Vector<double> V21_move_assig(std::move(V21_move));
  EXPECT_EQ(V21_move.size(), 0);
  EXPECT_EQ(V21_move_assig.size(), 5);
}

TEST(Vector_front_back, test_8) {
  s21::Vector<char> V21;
  char mass[] = {'S', 'C', 'H', 'O', 'O', 'L', '_', '2', '1'};
  for (int i = 0; i < 9; ++i) {
    V21.push_back(mass[i]);
  }
  EXPECT_EQ(V21.front(), 'S');
}

TEST(Vector_at_const, test_9) {
  s21::Vector<int> V21{0, 1, 2};
  for (int i = 0; i < 3; ++i) EXPECT_EQ(V21.at(i), i);
  V21.at(0) = 5;
}

TEST(Vector_capacity, test_10) {
  s21::Vector<float> V21({8.0001, 8.00002, 8.00003});
  EXPECT_EQ(V21.capacity(), 3);
  V21.reserve(6);
  EXPECT_EQ(V21.capacity(), 6);
  EXPECT_EQ(V21.max_size(), 6);
  V21.shrink_to_fit();
  EXPECT_EQ(V21.capacity(), 3);
}

TEST(Vector_insert, test_11) {
  s21::Vector<double> V21({1.1, 2.2, 3.3, 4.4, 5.5});
  s21::Vector<double>::Iterator z = V21.begin();
  z.s21advance(z, 4);
  --z;
  V21.insert(z, 0.01);
  double mass[] = {1.1, 2.2, 0.01, 3.3, 4.4, 5.5};
  for (int i = 0; i < 6; ++i) {
    EXPECT_DOUBLE_EQ(mass[5], V21.at(5));
  }
  EXPECT_EQ(V21.size(), 6);
}

TEST(Vector_pop_back, test_12) {
  s21::Vector<double> V21;
  for (int i = 0; i < 100; ++i) {
    V21.push_back(i / 13);
  }
  EXPECT_EQ(V21.size(), 100);
  for (int i = 0; i < 100; ++i) {
    V21.pop_back();
  }
  EXPECT_EQ(V21.empty(), true);
}

TEST(Vector_data, test_13) {
  s21::Vector<int> V21({0, 1, 2});
  EXPECT_EQ(*(V21.data()), 0);
  EXPECT_EQ(*(V21.data() + 1), 1);
  EXPECT_EQ(*(V21.data() + 2), 2);
}

TEST(Vector_erase, test_14) {
  s21::Vector<char> V21({'T', 'R', 'U', 'E'});
  s21::Vector<char>::Iterator z = V21.begin();
  z.s21advance(z, 1);
  V21.erase(z);
  char mass[] = {'T', 'U', 'E'};
  int j = 0;
  for (s21::Vector<char>::Iterator i = V21.begin(); i != V21.end(); ++i) {
    EXPECT_EQ(*i, mass[j++]);
  }
}

TEST(Vector_swap, test_15) {
  s21::Vector<double> V21({0.001, 0.002, 0.003, 0.004, 0.005});
  s21::Vector<double> V21_swap({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
  V21.swap(V21_swap);
  EXPECT_EQ(V21.size(), 10);
  EXPECT_EQ(V21_swap.size(), 5);
  for (int i = 0; i < 10; ++i) {
    EXPECT_DOUBLE_EQ(V21[i], i + 1);
  }
}

TEST(Vector_Swap, test_16) {
  s21::Vector<int> vec_1{0, 1, 2};
  s21::Vector<int> vec_2{0, 1, 2, 3, 4, 5};
  vec_1.swap(vec_2);
  EXPECT_EQ(vec_1.size(), 6);
  EXPECT_EQ(vec_1.capacity(), 6);
  EXPECT_EQ(vec_2.size(), 3);
  EXPECT_EQ(vec_2.capacity(), 3);
  std::cout << vec_2.capacity() << std::endl;
  int i = 0;
  for (auto it = vec_1.begin(); it != vec_1.end(); ++it) {
    EXPECT_EQ(*it, i);
    ++i;
  }
  i = 0;
  for (auto it = vec_2.begin(); it != vec_2.end(); ++it) {
    EXPECT_EQ(*it, i);
    ++i;
  }
}

TEST(Vector_emplace, test_17) {
  s21::Vector<char> V21({'m', 'o', 'm'});
  s21::Vector<char>::ConstIterator i = V21.cbegin();
  i.s21advance_const(i, 2);
  --i;
  s21::Vector<char>::Iterator res = V21.emplace(i, 'O', 'O', 'O');
  EXPECT_EQ(*res, 'O');
  char mass[] = "mOOOom";
  s21::Vector<char>::ConstIterator j = V21.cbegin();
  int k = 0;
  for (j = V21.cbegin(); j != V21.cend(); ++j) {
    EXPECT_EQ(mass[k++], *j);
  }
}

TEST(Vector_Emplace, test_18) {
  s21::Vector<int> V21{3, 4, 5};
  s21::Vector<int>::ConstIterator pos_1 = V21.cbegin();
  s21::Vector<int>::Iterator pos_res = V21.emplace(pos_1, 0, 1, 2);
  EXPECT_EQ(*pos_res, 0);
  int i = 0;
  for (auto it = V21.begin(); it != V21.end(); ++it) {
    EXPECT_EQ(*it, i);
    ++i;
  }
  EXPECT_EQ(V21.size(), 6);
}

TEST(Vector_emplace_back, test_19) {
  s21::Vector<float> V21{6.10996586,         9.35366153,
                         6.03359578,         15.592931823342404,
                         15.462214061191307, 19.80303716128794,
                         19.91960806659459};
  V21.emplace_back(0.6312659793400986, 0.9704219134108379,
                   0.00036539975574878536);
  float mass[] = {6.10996586,         9.35366153,
                  6.03359578,         15.592931823342404,
                  15.462214061191307, 19.80303716128794,
                  19.91960806659459,  0.6312659793400986,
                  0.9704219134108379, 0.00036539975574878536};
  int j = 0;
  for (s21::Vector<float>::Iterator i = V21.begin(); i != V21.end(); ++i) {
    EXPECT_FLOAT_EQ(*i, mass[j++]);
  }
}

TEST(Vector_Emplace_back, test_20) {
  s21::Vector<int> V21;
  V21.emplace_back(0, 1, 2, 3, 4, 5);
  int i = 0;
  for (auto it = V21.begin(); it != V21.end(); ++it) {
    EXPECT_EQ(*it, i);
    ++i;
  }
  EXPECT_EQ(V21.size(), 6);
}

TEST(Vector_const_at, test_21) {
  const s21::Vector<int> V21({0, 1, 2, 3, 4, 5});
  for (int i = 0; i < 6; ++i) {
    EXPECT_EQ(V21.at(i), i);
  }
}

TEST(Vector_const_sk, test_22) {
  const s21::Vector<char> V21({'A', 'B', 'O', 'B', 'A'});
  char mass[] = {'A', 'B', 'O', 'B', 'A'};
  for (int i = 0; i < 5; ++i) {
    EXPECT_EQ(mass[i], V21[i]);
  }
}

TEST(Vector_iterator, test_23) {
  s21::Vector<int> V21({10, 9, 8, 7, 6});
  s21::Vector<int>::Iterator i = V21.begin();
  for (s21::Vector<int>::Iterator j = V21.begin(); j != V21.end(); ++j) {
    if (i == j) {
      EXPECT_EQ(V21.at(0), *i);
    }
  }
}

TEST(Vector_iterator_const, test_24) {
  const s21::Vector<int> V21({10, 9, 8, 7, 6});
  s21::Vector<int>::ConstIterator i = V21.cbegin();
  for (s21::Vector<int>::ConstIterator j = V21.cbegin(); j != V21.cend(); ++j) {
    if (i == j) {
      EXPECT_EQ(V21.at(0), *i);
    }
  }
}

TEST(Vectoe_at_ERROR, test_25) {
  s21::Vector<double> V21;
  EXPECT_ANY_THROW(V21.at(2));
}

TEST(Vector_at_const_ERROR, test_26) {
  const s21::Vector<double> V21;
  EXPECT_ANY_THROW(V21.at(2));
}
//________________________________________________MAP

using pis = std::pair<int, std::string>;
using pcs = std::pair<char, std::string>;
using pss = std::pair<std::string, std::string>;
using pii = std::pair<int, int>;

TEST(map, default_constructor) {
  s21::Map<int, std::string> int_map;
  s21::Map<char, std::string> char_map;
  s21::Map<std::string, std::string> string_map;
  EXPECT_EQ(true, int_map.Empty());
  EXPECT_EQ(true, char_map.Empty());
  EXPECT_EQ(true, string_map.Empty());
}

TEST(map, initializer_list) {
  s21::Map<int, std::string> int_map{pis(4, "ba"), pis(5, "bo"), pis(6, "bu")};
  s21::Map<char, std::string> char_map{pcs('l', "lleter"), pcs('p', "proud"),
                                       pcs('a', "akademy")};
  s21::Map<std::string, std::string> string_map{
      pss("word", "wow?"), pss("hello", "world"), pss("it's hard", "not easy")};
  EXPECT_EQ(false, int_map.Empty());
  EXPECT_EQ(false, char_map.Empty());
  EXPECT_EQ(false, string_map.Empty());
}

TEST(map, copy_constructor) {
  s21::Map<int, std::string> int_map{pis(4, "ba"), pis(5, "bo"), pis(6, "bu")};
  s21::Map<char, std::string> char_map{pcs('l', "lleter"), pcs('p', "proud"),
                                       pcs('a', "akademy")};
  s21::Map<std::string, std::string> string_map{
      pss("word", "wow?"), pss("hello", "world"), pss("it's hard", "not easy")};

  s21::Map<int, std::string> int_map_cpy(int_map);
  s21::Map<char, std::string> char_map_cpy = char_map;
  s21::Map<std::string, std::string> string_map_cpy = string_map;
  EXPECT_EQ(false, int_map_cpy.Empty());
  EXPECT_EQ(false, char_map_cpy.Empty());
  EXPECT_EQ(false, string_map_cpy.Empty());
}

TEST(map, move_constructor_2) {
  s21::Map<int, std::string> int_map = {pis(1, "hello")};
  s21::Map<char, std::string> char_map = {pcs('l', "lleter"), pcs('p', "proud"),
                                          pcs('a', "akademy")};
  s21::Map<std::string, std::string> string_map{
      pss("word", "wow?"), pss("hello", "world"), pss("it's hard", "not easy")};
  string_map = std::move(
      s21::Map<std::string, std::string>{pss("hello world", "friens")});
  EXPECT_EQ(false, int_map.Empty());
  EXPECT_EQ(false, char_map.Empty());
  EXPECT_EQ(false, string_map.Empty());
}

TEST(map, destructor) {
  s21::Map<int, std::string> int_map{pis(4, "ba"), pis(5, "bo"), pis(6, "bu")};
  s21::Map<char, std::string> char_map = {pcs('l', "lleter"), pcs('p', "proud"),
                                          pcs('a', "akademy")};
  s21::Map<std::string, std::string> string_map{
      pss("word", "wow?"), pss("hello", "world"), pss("it's hard", "not easy")};
  int_map.~Map();
  char_map.~Map();
  string_map.~Map();
  EXPECT_EQ(true, int_map.Empty());
  EXPECT_EQ(true, char_map.Empty());
  EXPECT_EQ(true, string_map.Empty());
}

TEST(map, at) {
  s21::Map<int, int> tree = {pii(20, 1), pii(10, 1), pii(30, 56), pii(80, 1),
                             pii(5, 1)};
  std::map<int, int> tree1 = {pii(20, 1), pii(10, 1), pii(30, 56), pii(80, 1),
                              pii(5, 1)};

  EXPECT_EQ(tree.At(30), tree1.at(30));
}

TEST(map, braces) {
  s21::Map<int, int> tree = {pii(20, 1), pii(10, 1), pii(30, 56), pii(80, 1),
                             pii(5, 1)};
  std::map<int, int> tree1 = {pii(20, 1), pii(10, 1), pii(30, 56), pii(80, 1),
                              pii(5, 1)};
  EXPECT_EQ(tree[10], tree1[10]);
  EXPECT_EQ(tree[30], tree1[30]);
}

TEST(map, assignconstuctor) {
  s21::Map<int, std::string> int_map1{pis(4, "ba"), pis(5, "bo"), pis(6, "bu")};
  s21::Map<int, std::string> int_map2{pis(7, "the"), pis(8, "zi"),
                                      pis(9, "oi")};
  std::map<int, std::string> intmap1{pis(4, "ba"), pis(5, "bo"), pis(6, "bu")};
  std::map<int, std::string> intmap2{pis(7, "the"), pis(8, "zi"), pis(9, "oi")};
  int_map1 = int_map2;
  intmap1 = intmap2;
  auto itter = intmap1.begin();
  for (auto it = int_map1.Begin(); it != int_map1.End(); ++it) {
    EXPECT_EQ((*it).first, (*itter).first);
    EXPECT_EQ((*it).second, (*itter).second);
    ++itter;
  }
}

TEST(iterators3, begin_end) {
  s21::Map<int, std::string> int_map =
      s21::Map<int, std::string>{pis(8, "ba"), pis(9, "bo"), pis(10, "bu")};
  std::map<int, std::string> intmap =
      std::map<int, std::string>{pis(8, "ba"), pis(9, "bo"), pis(10, "bu")};
  auto itter = intmap.begin();

  for (auto it = int_map.Begin(); it != int_map.End(); ++it) {
    EXPECT_EQ((*it).first, (*itter).first);
    EXPECT_EQ((*it).second, (*itter).second);
    ++itter;
  }
  itter = --intmap.end();
  for (auto it = --int_map.End(); it != int_map.End(); --it) {
    EXPECT_EQ((*it).first, (*itter).first);
    EXPECT_EQ((*it).second, (*itter).second);
    --itter;
  }
  std::map<int, std::string> inttmap;
  s21::Map<int, std::string> inttmap1;
  s21::Map<int, std::string>::const_iterator itconst = int_map.Begin();
  std::map<int, std::string>::const_iterator itconststd = intmap.begin();
  EXPECT_EQ((*itconst).first, (*itconststd).first);
  EXPECT_EQ((*itconst).second, (*itconststd).second);
}

TEST(capasity3, size_empty) {
  s21::Map<int, std::string> int_map{pis(4, "ba"), pis(5, "bo"), pis(6, "bu")};
  std::map<int, std::string> intmap = {pis(4, "ba"), pis(5, "bo"),
                                       pis(6, "bu")};

  s21::Map<char, std::string> char_map = {pcs('l', "lleter"), pcs('p', "proud"),
                                          pcs('a', "akademy")};
  std::map<char, std::string> charmap = {pcs('l', "lleter"), pcs('p', "proud"),
                                         pcs('a', "akademy")};

  s21::Map<std::string, std::string> string_map{
      pss("word", "wow?"), pss("hello", "world"), pss("it's hard", "not easy")};
  std::map<std::string, std::string> stringmap{
      pss("word", "wow?"), pss("hello", "world"), pss("it's hard", "not easy")};

  EXPECT_EQ(false, int_map.Empty());
  EXPECT_EQ(false, char_map.Empty());
  EXPECT_EQ(false, string_map.Empty());
  EXPECT_EQ(intmap.size(), int_map.Size());
  EXPECT_EQ(charmap.size(), char_map.Size());
  EXPECT_EQ(stringmap.size(), string_map.Size());
  int_map.Max_Size();
}

TEST(map, erase) {
  s21::Map<int, std::string> int_map{pis(4, "ba"), pis(5, "bo"), pis(6, "bu")};
  std::map<int, std::string> intmap = {pis(4, "ba"), pis(5, "bo"),
                                       pis(6, "bu")};
  s21::Map<char, std::string> char_map = {pcs('l', "lleter"), pcs('p', "proud"),
                                          pcs('a', "akademy")};
  std::map<char, std::string> charmap = {pcs('l', "lleter"), pcs('p', "proud"),
                                         pcs('a', "akademy")};

  s21::Map<std::string, std::string> string_map{
      pss("word", "wow?"), pss("hello", "world"), pss("it's hard", "not easy")};
  std::map<std::string, std::string> stringmap{
      pss("word", "wow?"), pss("hello", "world"), pss("it's hard", "not easy")};

  int_map.Erase(int_map.Begin());
  intmap.erase(intmap.begin());

  char_map.Erase(char_map.Begin());
  charmap.erase(charmap.begin());

  string_map.Erase(string_map.Begin());
  stringmap.erase(stringmap.begin());

  auto it1 = intmap.begin();
  EXPECT_EQ(intmap.size(), int_map.Size());
  for (auto it = int_map.Begin(); it != int_map.End(); ++it) {
    EXPECT_EQ((*it).first, (*it1).first);
    EXPECT_EQ((*it).second, (*it1).second);
    ++it1;
  }

  auto it2 = charmap.begin();
  EXPECT_EQ(charmap.size(), char_map.Size());
  for (auto it = char_map.Begin(); it != char_map.End(); ++it) {
    EXPECT_EQ((*it).first, (*it2).first);
    EXPECT_EQ((*it).second, (*it2).second);
    ++it2;
  }

  auto it3 = stringmap.begin();
  EXPECT_EQ(stringmap.size(), string_map.Size());
  for (auto it = string_map.Begin(); it != string_map.End(); ++it) {
    EXPECT_EQ((*it).first, (*it3).first);
    EXPECT_EQ((*it).second, (*it3).second);
    ++it3;
  }
}

TEST(map, insert_clear) {
  s21::Map<int, std::string> int_map{pis(4, "ba"), pis(5, "bo"), pis(6, "bu")};
  std::map<int, std::string> intmap = {pis(4, "ba"), pis(5, "bo"),
                                       pis(6, "bu")};

  s21::Map<char, std::string> char_map = {pcs('l', "lleter"), pcs('p', "proud"),
                                          pcs('a', "akademy")};
  std::map<char, std::string> charmap = {pcs('l', "lleter"), pcs('p', "proud"),
                                         pcs('a', "akademy")};

  s21::Map<std::string, std::string> string_map{
      pss("word", "wow?"), pss("hello", "world"), pss("it's hard", "not easy")};
  std::map<std::string, std::string> stringmap{
      pss("word", "wow?"), pss("hello", "world"), pss("it's hard", "not easy")};

  auto pair_int_map = int_map.Insert(pis(8, "mine"));
  auto pairintmap = intmap.insert(pis(8, "mine"));
  auto pair_char_map = char_map.Insert(pcs('t', "life"));
  auto paircharmap = charmap.insert(pcs('t', "life"));
  auto pair_string_map = string_map.Insert(pss("angle", "stable"));
  auto pairstringmap = stringmap.insert(pss("angle", "stable"));
  EXPECT_EQ((*(pair_int_map.first)).first, (*(pairintmap.first)).first);
  EXPECT_EQ((*(pair_char_map.first)).first, (*(paircharmap.first)).first);
  EXPECT_EQ((*(pair_string_map.first)).first, (*(pairstringmap.first)).first);
  EXPECT_EQ((*(pair_int_map.first)).second, (*(pairintmap.first)).second);
  EXPECT_EQ((*(pair_char_map.first)).second, (*(paircharmap.first)).second);
  EXPECT_EQ((*(pair_string_map.first)).second, (*(pairstringmap.first)).second);
  auto pair_int_map1 = int_map.Insert(pis(8, "hw"));
  auto pairintmap1 = intmap.insert(pis(8, "hw"));
  auto pair_char_map1 = char_map.Insert(pcs('t', "flag"));
  auto paircharmap1 = charmap.insert(pcs('t', "flag"));
  auto pair_string_map1 = string_map.Insert(pss("angle", "wiget"));
  auto pairstringmap1 = stringmap.insert(pss("angle", "wiget"));

  EXPECT_EQ(pair_int_map1.second, pairintmap1.second);
  EXPECT_EQ(pair_char_map1.second, paircharmap1.second);
  EXPECT_EQ(pair_string_map1.second, pairstringmap1.second);

  EXPECT_EQ(false, int_map.Empty());
  EXPECT_EQ(false, char_map.Empty());
  EXPECT_EQ(false, string_map.Empty());
  int_map.Clear();
  intmap.clear();
  char_map.Clear();
  charmap.clear();
  string_map.Clear();
  stringmap.clear();
  EXPECT_EQ(intmap.empty(), int_map.Empty());
  EXPECT_EQ(charmap.empty(), char_map.Empty());
  EXPECT_EQ(stringmap.empty(), string_map.Empty());
}

TEST(map, swap) {
  s21::Map<int, std::string> int_map{pis(4, "ba"), pis(5, "bo"), pis(6, "bu")};
  s21::Map<int, std::string> int_map1{pis(3, "arr"), pis(9, "say")};

  std::map<int, std::string> intmap = {pis(4, "ba"), pis(5, "bo"),
                                       pis(6, "bu")};
  std::map<int, std::string> intmap1 = {pis(3, "arr"), pis(9, "say")};

  s21::Map<char, std::string> char_map = {pcs('l', "lleter"), pcs('p', "proud"),
                                          pcs('a', "akademy")};
  s21::Map<char, std::string> char_map1 = {pcs('w', "wou"), pcs('t', "time")};

  std::map<char, std::string> charmap = {pcs('l', "lleter"), pcs('p', "proud"),
                                         pcs('a', "akademy")};
  std::map<char, std::string> charmap1 = {pcs('w', "wou"), pcs('t', "time")};

  s21::Map<std::string, std::string> string_map{
      pss("word", "wow?"), pss("hello", "world"), pss("it's hard", "not easy")};
  s21::Map<std::string, std::string> string_map1{
      pss("wine", "wah?"), pss("hollo", "prise"), pss("till", "tram"),
      pss("scorge", " monster")};

  std::map<std::string, std::string> stringmap{
      pss("word", "wow?"), pss("hello", "world"), pss("it's hard", "not easy")};
  std::map<std::string, std::string> stringmap1{
      pss("wine", "wah?"), pss("hollo", "prise"), pss("till", "tram"),
      pss("scorge", " monster")};

  int_map.Swap(int_map1);
  intmap.swap(intmap1);

  char_map.Swap(char_map1);
  charmap.swap(charmap1);

  string_map.Swap(string_map1);
  stringmap.swap(stringmap1);

  auto it1 = intmap.begin();
  EXPECT_EQ(intmap.size(), int_map.Size());
  for (auto it = int_map.Begin(); it != int_map.End(); ++it) {
    EXPECT_EQ((*it).first, (*it1).first);
    EXPECT_EQ((*it).second, (*it1).second);
    ++it1;
  }
  auto it2 = charmap.begin();
  EXPECT_EQ(charmap.size(), char_map.Size());
  for (auto it = char_map.Begin(); it != char_map.End(); ++it) {
    EXPECT_EQ((*it).first, (*it2).first);
    EXPECT_EQ((*it).second, (*it2).second);
    ++it2;
  }

  auto it3 = stringmap.begin();
  EXPECT_EQ(stringmap.size(), string_map.Size());
  for (auto it = string_map.Begin(); it != string_map.End(); ++it) {
    EXPECT_EQ((*it).first, (*it3).first);
    EXPECT_EQ((*it).second, (*it3).second);
    ++it3;
  }
}

TEST(map, merge) {
  s21::Map<int, std::string> int_map{pis(4, "ba"), pis(5, "bo"), pis(6, "bu")};
  s21::Map<int, std::string> int_map1{pis(3, "arr"), pis(9, "say")};

  std::map<int, std::string> intmap = {pis(4, "ba"), pis(5, "bo"),
                                       pis(6, "bu")};
  std::map<int, std::string> intmap1 = {pis(3, "arr"), pis(9, "say")};

  s21::Map<char, std::string> char_map = {pcs('l', "lleter"), pcs('p', "proud"),
                                          pcs('a', "akademy")};
  s21::Map<char, std::string> char_map1 = {pcs('w', "wou"), pcs('t', "time")};

  std::map<char, std::string> charmap = {pcs('l', "lleter"), pcs('p', "proud"),
                                         pcs('a', "akademy")};
  std::map<char, std::string> charmap1 = {pcs('w', "wou"), pcs('t', "time")};

  s21::Map<std::string, std::string> string_map{
      pss("word", "wow?"), pss("hello", "world"), pss("it's hard", "not easy")};
  s21::Map<std::string, std::string> string_map1{
      pss("wine", "wah?"), pss("hollo", "prise"), pss("till", "tram"),
      pss("scorge", " monster")};

  std::map<std::string, std::string> stringmap{
      pss("word", "wow?"), pss("hello", "world"), pss("it's hard", "not easy")};
  std::map<std::string, std::string> stringmap1{
      pss("wine", "wah?"), pss("hollo", "prise"), pss("till", "tram"),
      pss("scorge", " monster")};

  int_map.Merge(int_map1);
  intmap.merge(intmap1);

  char_map1.Merge(char_map);
  charmap1.merge(charmap);

  string_map.Merge(string_map1);
  stringmap.merge(stringmap1);

  auto it1 = intmap.begin();
  EXPECT_EQ(intmap.size(), int_map.Size());
  for (auto it = int_map.Begin(); it != int_map.End(); ++it) {
    EXPECT_EQ((*it).first, (*it1).first);
    EXPECT_EQ((*it).second, (*it1).second);
    ++it1;
  }
  auto it2 = charmap1.begin();
  EXPECT_EQ(charmap1.size(), char_map1.Size());
  for (auto it = char_map1.Begin(); it != char_map1.End(); ++it) {
    EXPECT_EQ((*it).first, (*it2).first);
    EXPECT_EQ((*it).second, (*it2).second);
    ++it2;
  }

  auto it3 = stringmap.begin();
  EXPECT_EQ(stringmap.size(), string_map.Size());
  for (auto it = string_map.Begin(); it != string_map.End(); ++it) {
    EXPECT_EQ((*it).first, (*it3).first);
    EXPECT_EQ((*it).second, (*it3).second);
    ++it3;
  }
}

TEST(map, contains) {
  s21::Map<int, std::string> int_map = {pis(4, "ba"), pis(5, "bo"),
                                        pis(6, "bu")};
  s21::Map<char, std::string> char_map{pcs('l', "lleter"), pcs('p', "proud"),
                                       pcs('a', "akademy")};
  s21::Map<std::string, std::string> string_map{
      pss("word", "wow?"), pss("hello", "world"), pss("it's hard", "not easy")};

  EXPECT_EQ(int_map.Contains(6), true);
  EXPECT_EQ(char_map.Contains('l'), true);
  EXPECT_EQ(string_map.Contains("it's hard"), true);

  EXPECT_EQ(int_map.Contains(777), false);
  EXPECT_EQ(char_map.Contains('H'), false);
  EXPECT_EQ(string_map.Contains("dummy"), false);
}

TEST(assign, assign1) {
  s21::Map<int, int> tree = {pii(20, 1),  pii(10, 1),  pii(30, 1),  pii(80, 1),
                             pii(5, 1),   pii(16, 1),  pii(108, 1), pii(110, 1),
                             pii(120, 1), pii(130, 1), pii(107, 1), pii(106, 1),
                             pii(105, 1), pii(17, 1),  pii(18, 1),  pii(19, 1),
                             pii(21, 1),  pii(22, 1),  pii(34, 1),  pii(35, 1),
                             pii(36, 1),  pii(40, 1),  pii(50, 1),  pii(60, 1)};
  tree.Insert_Or_Assign(999, 22);
  std::map<int, int> tree1 = {
      pii(20, 1),  pii(10, 1),  pii(30, 1),  pii(80, 1),  pii(5, 1),
      pii(16, 1),  pii(108, 1), pii(110, 1), pii(120, 1), pii(130, 1),
      pii(107, 1), pii(106, 1), pii(105, 1), pii(17, 1),  pii(18, 1),
      pii(19, 1),  pii(21, 1),  pii(22, 1),  pii(34, 1),  pii(35, 1),
      pii(36, 1),  pii(40, 1),  pii(50, 1),  pii(60, 1)};
  tree1.insert_or_assign(999, 22);

  EXPECT_EQ(tree.At(19), tree1.at(19));
  tree.Insert_Or_Assign(999, 36);
  tree1.insert_or_assign(999, 36);
  EXPECT_EQ(tree.At(999), tree1.at(999));
}

//____________________________________________MULTISET

s21::Multiset<int> mset_create() {
  return s21::Multiset<int>{1, 2, 3, 3, 4, 5};
}

TEST(multiset, default_constructor1) {
  s21::Multiset<int> int_set;
  s21::Multiset<char> char_set;
  s21::Multiset<std::string> string_set;
  EXPECT_EQ(1, int_set.Empty());
  EXPECT_EQ(1, char_set.Empty());
  EXPECT_EQ(1, string_set.Empty());
}

TEST(multiset, initializer_list_1) {
  s21::Multiset<int> int_set{4, 5, 5, 5, 6, 2, 2, 2, 4, 3, 1, 17, 10};
  s21::Multiset<char> char_set = {'l', 'p', 'h', 'a', 'd', 'z',
                                  'c', 'r', 'o', 'o', 'f'};
  s21::Multiset<std::string> string_set{"arrow", "word",      "hello",
                                        "hello", "it's hard", "arrow"};
  EXPECT_EQ(false, int_set.Empty());
  EXPECT_EQ(false, char_set.Empty());
  EXPECT_EQ(false, string_set.Empty());
}

TEST(multiset, copy_constructor_1) {
  s21::Multiset<int> int_set{4, 5, 5, 5, 6, 2, 2, 2, 4, 3, 1, 17, 10};
  s21::Multiset<char> char_set = {'l', 'p', 'h', 'a', 'd', 'z',
                                  'c', 'r', 'o', 'o', 'f'};
  s21::Multiset<std::string> string_set{"arrow", "word",      "hello",
                                        "hello", "it's hard", "arrow"};
  s21::Multiset<int> int_set_cpy(int_set);
  s21::Multiset<char> char_set_cpy = char_set;
  s21::Multiset<std::string> string_set_cpy = string_set;
  EXPECT_EQ(false, int_set_cpy.Empty());
  EXPECT_EQ(false, char_set_cpy.Empty());
  EXPECT_EQ(false, string_set_cpy.Empty());
}

TEST(multiset, move_constructor_1) {
  s21::Multiset<int> int_set1 = mset_create();
  s21::Multiset<int> int_set(std::move(s21::Multiset<int>{18, 20}));
  s21::Multiset<char> char_set = s21::Multiset<char>{
      'l', 'p', 'h', 'a', 'p', 'd', 'z', 'c', 'r', 'o', 'f',
  };
  s21::Multiset<std::string> string_set = s21::Multiset<std::string>{
      "arrow", "word", "hello", "it's hard", "arrow"};
  string_set = std::move(s21::Multiset<std::string>{"hello world"});
  EXPECT_EQ(false, int_set1.Empty());
  EXPECT_EQ(false, char_set.Empty());
  EXPECT_EQ(false, string_set.Empty());
}

TEST(multiset, destructor_1) {
  s21::Multiset<int> int_set{4, 5, 5, 5, 6, 2, 2, 2, 4, 3, 1, 17, 10};
  s21::Multiset<char> char_set = {'l', 'p', 'h', 'a', 'd', 'z',
                                  'c', 'r', 'o', 'o', 'f'};
  s21::Multiset<std::string> string_set{"arrow", "word",      "hello",
                                        "hello", "it's hard", "arrow"};

  int_set.~Multiset();
  char_set.~Multiset();
  string_set.~Multiset();
  EXPECT_EQ(true, int_set.Empty());
  EXPECT_EQ(true, char_set.Empty());
  EXPECT_EQ(true, string_set.Empty());
}

TEST(multiset, assignconstuctor1) {
  s21::Multiset<int> int_set1{4, 5, 5, 5, 5, 6};
  s21::Multiset<int> int_set2{7, 8, 9, 9, 9, 9, 9};
  std::multiset<int> intset1{4, 5, 5, 5, 5, 6};
  std::multiset<int> intset2{7, 8, 9, 9, 9, 9, 9};
  int_set1 = int_set2;
  intset1 = intset2;
  auto itter = intset1.begin();
  for (auto it = int_set1.Begin(); it != int_set1.End(); ++it) {
    EXPECT_EQ(*it, *itter);
    ++itter;
  }
}

TEST(multiset, begin_end1) {
  s21::Multiset<int> int_set =
      s21::Multiset<int>{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  std::set<int> intset = std::set<int>{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

  auto itter = intset.begin();

  for (auto it = int_set.Begin(); it != int_set.End(); ++it) {
    EXPECT_EQ(*it, *itter);
    ++itter;
  }
  itter = --intset.end();
  for (auto it = --int_set.End(); it != int_set.End(); --it) {
    EXPECT_EQ(*it, *itter);
    --itter;
  }
  s21::Multiset<int>::const_iterator itconst = int_set.Begin();
  std::multiset<int>::const_iterator itconststd = intset.begin();
  EXPECT_EQ(*itconst, *itconststd);
}

TEST(multiset, Size_Empty1) {
  s21::Multiset<int> int_set{4, 5, 5, 5, 6, 2, 2, 2, 4, 3, 1, 17, 10};
  s21::Multiset<char> char_set = {'l', 'p', 'h', 'a', 'd', 'z',
                                  'c', 'r', 'o', 'o', 'f'};
  s21::Multiset<std::string> string_set{"arrow", "word",      "hello",
                                        "hello", "it's hard", "arrow"};
  std::multiset<int> intset{4, 5, 5, 5, 6, 2, 2, 2, 4, 3, 1, 17, 10};
  std::multiset<char> charset = {'l', 'p', 'h', 'a', 'd', 'z',
                                 'c', 'r', 'o', 'o', 'f'};
  std::multiset<std::string> stringset{"arrow", "word",      "hello",
                                       "hello", "it's hard", "arrow"};

  EXPECT_EQ(false, int_set.Empty());
  EXPECT_EQ(false, char_set.Empty());
  EXPECT_EQ(false, string_set.Empty());
  EXPECT_EQ(intset.size(), int_set.Size());
  EXPECT_EQ(charset.size(), char_set.Size());
  EXPECT_EQ(stringset.size(), string_set.Size());
  int_set.Max_Size();
}

TEST(multiset, insert_clear1) {
  s21::Multiset<int> int_set{4, 5, 5, 5, 6, 2, 2, 2, 4, 3, 1, 17, 10};
  s21::Multiset<char> char_set = {'l', 'p', 'h', 'a', 'd', 'z',
                                  'c', 'r', 'o', 'o', 'f'};
  s21::Multiset<std::string> string_set{"arrow", "word",      "hello",
                                        "hello", "it's hard", "arrow"};
  std::multiset<int> intset{4, 5, 5, 5, 6, 2, 2, 2, 4, 3, 1, 17, 10};
  std::multiset<char> charset = {'l', 'p', 'h', 'a', 'd', 'z',
                                 'c', 'r', 'o', 'o', 'f'};
  std::multiset<std::string> stringset{"arrow", "word",      "hello",
                                       "hello", "it's hard", "arrow"};

  auto it_int_set = int_set.Insert(8);
  auto itintset = intset.insert(8);
  auto it_char_set = char_set.Insert('t');
  auto itcharset = charset.insert('t');
  auto it_string_set = string_set.Insert("angle");
  auto itstringset = stringset.insert("angle");

  EXPECT_EQ(*(it_int_set), *(itintset));
  EXPECT_EQ(*(it_char_set), *(itcharset));
  EXPECT_EQ(*(it_string_set), *(itstringset));

  auto it_int_set1 = int_set.Insert(8);
  auto itintset1 = intset.insert(8);
  auto it_char_set1 = char_set.Insert('t');
  auto itcharset1 = charset.insert('t');
  auto it_string_set1 = string_set.Insert("angle");
  auto itstringset1 = stringset.insert("angle");
  EXPECT_EQ(*(it_int_set1), *(itintset1));
  EXPECT_EQ(*(it_char_set1), *(itcharset1));
  EXPECT_EQ(*(it_string_set1), *(itstringset1));

  EXPECT_EQ(false, int_set.Empty());
  EXPECT_EQ(false, char_set.Empty());
  EXPECT_EQ(false, string_set.Empty());
  int_set.Clear();
  intset.clear();
  char_set.Clear();
  charset.clear();
  string_set.Clear();
  stringset.clear();
  EXPECT_EQ(intset.empty(), int_set.Empty());
  EXPECT_EQ(charset.empty(), char_set.Empty());
  EXPECT_EQ(stringset.empty(), string_set.Empty());
}

TEST(multiset, erase1) {
  s21::Multiset<int> int_set{4, 5, 5, 5, 6, 2, 2, 2, 4, 3, 1, 17, 10};
  s21::Multiset<char> char_set = {'l', 'p', 'h', 'a', 'd', 'z',
                                  'c', 'r', 'o', 'o', 'f'};
  s21::Multiset<std::string> string_set{"arrow", "word",      "hello",
                                        "hello", "it's hard", "arrow"};
  std::multiset<int> intset{4, 5, 5, 5, 6, 2, 2, 2, 4, 3, 1, 17, 10};
  std::multiset<char> charset = {'l', 'p', 'h', 'a', 'd', 'z',
                                 'c', 'r', 'o', 'o', 'f'};
  std::multiset<std::string> stringset{"arrow", "word",      "hello",
                                       "hello", "it's hard", "arrow"};
  int_set.Erase(int_set.Begin());
  intset.erase(intset.begin());

  char_set.Erase(char_set.Begin());
  charset.erase(charset.begin());

  string_set.Erase(string_set.Begin());
  stringset.erase(stringset.begin());

  auto it1 = intset.begin();
  EXPECT_EQ(intset.size(), int_set.Size());
  for (auto it = int_set.Begin(); it != int_set.End(); ++it) {
    EXPECT_EQ(*it, *it1);
    ++it1;
  }
  auto it2 = charset.begin();
  EXPECT_EQ(charset.size(), char_set.Size());
  for (auto it = char_set.Begin(); it != char_set.End(); ++it) {
    EXPECT_EQ(*it, *it2);
    ++it2;
  }

  auto it3 = stringset.begin();
  EXPECT_EQ(stringset.size(), string_set.Size());
  for (auto it = string_set.Begin(); it != string_set.End(); ++it) {
    EXPECT_EQ(*it, *it3);
    ++it3;
  }
}

TEST(multiset, swap1) {
  s21::Multiset<int> int_set = {4, 5, 6, 2, 4, 3, 1, 17, 10};
  s21::Multiset<int> int_set1 = {88, 99};
  std::multiset<int> intset = {4, 5, 6, 2, 4, 3, 1, 17, 10};
  std::multiset<int> intset1 = {88, 99};

  s21::Multiset<char> char_set = {'l', 'p', 'h', 'a', 'd', 'd',
                                  'z', 'c', 'r', 'o', 'f'};
  s21::Multiset<char> char_set1 = {'R', 'P', 'P', 'O', 'O'};

  std::multiset<char> charset = {'l', 'p', 'h', 'a', 'd', 'd',
                                 'z', 'c', 'r', 'o', 'f'};
  std::multiset<char> charset1 = {'R', 'P', 'P', 'O', 'O'};

  s21::Multiset<std::string> string_set = {"word", "hello", "it's hard",
                                           "arrow"};
  s21::Multiset<std::string> string_set1 = {"everebody", "likes", "cakes"};

  std::multiset<std::string> stringset = {"word", "hello", "it's hard",
                                          "arrow"};
  std::multiset<std::string> stringset1 = {"everebody", "likes", "cakes"};

  int_set.Swap(int_set1);
  intset.swap(intset1);

  char_set.Swap(char_set1);
  charset.swap(charset1);

  string_set.Swap(string_set1);
  stringset.swap(stringset1);

  auto it1 = intset.begin();
  EXPECT_EQ(intset.size(), int_set.Size());
  for (auto it = int_set.Begin(); it != int_set.End(); ++it) {
    EXPECT_EQ(*it, *it1);
    ++it1;
  }
  auto it2 = charset.begin();
  EXPECT_EQ(charset.size(), char_set.Size());
  for (auto it = char_set.Begin(); it != char_set.End(); ++it) {
    EXPECT_EQ(*it, *it2);
    ++it2;
  }

  auto it3 = stringset.begin();
  EXPECT_EQ(stringset.size(), string_set.Size());
  for (auto it = string_set.Begin(); it != string_set.End(); ++it) {
    EXPECT_EQ(*it, *it3);
    ++it3;
  }
}

TEST(multiset, merge1) {
  s21::Multiset<int> int_set = {4, 5, 6, 2, 4, 3, 1, 17, 10};
  s21::Multiset<int> int_set1 = {88, 99};
  std::multiset<int> intset = {4, 5, 6, 2, 4, 3, 1, 17, 10};
  std::multiset<int> intset1 = {88, 99};

  s21::Multiset<char> char_set = {'l', 'p', 'h', 'a', 'd', 'd',
                                  'z', 'c', 'r', 'o', 'f'};
  s21::Multiset<char> char_set1 = {'R', 'P', 'P', 'O', 'O'};

  std::multiset<char> charset = {'l', 'p', 'h', 'a', 'd', 'd',
                                 'z', 'c', 'r', 'o', 'f'};
  std::multiset<char> charset1 = {'R', 'P', 'P', 'O', 'O'};

  s21::Multiset<std::string> string_set = {"word", "hello", "it's hard",
                                           "arrow"};
  s21::Multiset<std::string> string_set1 = {"everebody", "likes", "cakes"};

  std::multiset<std::string> stringset = {"word", "hello", "it's hard",
                                          "arrow"};
  std::multiset<std::string> stringset1 = {"everebody", "likes", "cakes"};

  int_set.Merge(int_set1);
  intset.merge(intset1);

  char_set1.Merge(char_set);
  charset1.merge(charset);

  string_set.Merge(string_set1);
  stringset.merge(stringset1);

  auto it1 = intset.begin();
  EXPECT_EQ(intset.size(), int_set.Size());
  for (auto it = int_set.Begin(); it != int_set.End(); ++it) {
    EXPECT_EQ(*it, *it1);
    ++it1;
  }
  auto it2 = charset1.begin();
  EXPECT_EQ(charset1.size(), char_set1.Size());
  for (auto it = char_set1.Begin(); it != char_set1.End(); ++it) {
    EXPECT_EQ(*it, *it2);
    ++it2;
  }

  auto it3 = stringset.begin();
  EXPECT_EQ(stringset.size(), string_set.Size());
  for (auto it = string_set.Begin(); it != string_set.End(); ++it) {
    EXPECT_EQ(*it, *it3);
    ++it3;
  }
}

TEST(multiset, find1) {
  s21::Multiset<int> int_set{4, 5, 5, 5, 6, 2, 2, 2, 4, 3, 1, 17, 10};
  s21::Multiset<char> char_set = {'l', 'p', 'h', 'a', 'd', 'z',
                                  'c', 'r', 'o', 'o', 'f'};
  s21::Multiset<std::string> string_set{"arrow", "word",      "hello",
                                        "hello", "it's hard", "arrow"};
  std::multiset<int> intset{4, 5, 5, 5, 6, 2, 2, 2, 4, 3, 1, 17, 10};
  std::multiset<char> charset = {'l', 'p', 'h', 'a', 'd', 'z',
                                 'c', 'r', 'o', 'o', 'f'};
  std::multiset<std::string> stringset{"arrow", "word",      "hello",
                                       "hello", "it's hard", "arrow"};

  auto it_int_set = int_set.Find(10);
  auto it_intset = intset.find(10);

  auto it_char_set = char_set.Find('p');
  auto it_charset = charset.find('p');

  auto it_string_set = string_set.Find("hello");
  auto it_stringset = stringset.find("hello");

  EXPECT_EQ(*(it_int_set), *(it_intset));
  EXPECT_EQ(*(it_char_set), *(it_charset));
  EXPECT_EQ(*(it_string_set), *(it_stringset));

  EXPECT_EQ(int_set.Contains(10), true);
  EXPECT_EQ(char_set.Contains('z'), true);
  EXPECT_EQ(string_set.Contains("arrow"), true);

  EXPECT_EQ(int_set.Contains(777), false);
  EXPECT_EQ(char_set.Contains('H'), false);
  EXPECT_EQ(string_set.Contains("dummy"), false);
}

TEST(multiset, count1) {
  s21::Multiset<int> int_set{4, 5, 5, 5, 6, 2, 2, 2, 4, 3, 1, 17, 10};
  std::multiset<int> intset{4, 5, 5, 5, 6, 2, 2, 2, 4, 3, 1, 17, 10};
  s21::Multiset<int> int_set1;
  std::multiset<int> intset2;

  EXPECT_EQ(int_set.Count(2), intset.count(2));
  EXPECT_EQ(int_set.Count(10), intset.count(10));
  EXPECT_EQ(int_set.Count(387), intset.count(387));
  EXPECT_EQ(int_set1.Count(387), intset2.count(387));
}

TEST(multiset, lower_bound) {
  s21::Multiset<int> int_set{4, 5, 5, 5, 6, 2, 2, 2, 4, 3, 1, 17, 10};
  std::multiset<int> intset{4, 5, 5, 5, 6, 2, 2, 2, 4, 3, 1, 17, 10};
  auto it = int_set.Lower_Bound(5);
  auto it1 = intset.lower_bound(5);
  for (; it != int_set.End(); ++it) {
    EXPECT_EQ(*it, *it1);
    ++it1;
  }

  auto it2 = int_set.Lower_Bound(1);
  auto it3 = intset.lower_bound(1);
  EXPECT_EQ(*it2, *it3);
}

TEST(multiset, upper_bound) {
  s21::Multiset<int> int_set{4, 5, 5, 5, 6, 2, 2, 2, 4, 3, 1, 17, 10};
  std::multiset<int> intset{4, 5, 5, 5, 6, 2, 2, 2, 4, 3, 1, 17, 10};
  auto it = int_set.Upper_Bound(5);
  auto it1 = intset.upper_bound(5);
  for (; it != int_set.End(); ++it) {
    EXPECT_EQ(*it, *it1);
    ++it1;
  }
  auto it2 = int_set.Upper_Bound(10);
  auto it3 = intset.upper_bound(10);
  EXPECT_EQ(*it2, *it3);
}

TEST(multiset, testemplace1) {
  s21::Multiset<int> int_set{4, 5, 5, 5, 6, 2, 2, 2, 4, 3, 1, 17, 10};
  int_set.Emplace(11, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20);

  EXPECT_EQ(int_set.Size(), 24);
}

TEST(multiset, range) {
  s21::Multiset<int> int_set{4, 5, 5, 5, 6, 2, 2, 2, 4, 3, 1, 17, 10};
  std::multiset<int> intset{4, 5, 5, 5, 6, 2, 2, 2, 4, 3, 1, 17, 10};
  std::pair<std::multiset<int>::iterator, std::multiset<int>::iterator> range =
      intset.equal_range(5);
  std::pair<s21::Multiset<int>::iterator, s21::Multiset<int>::iterator> range1 =
      int_set.Equal_Range(5);
  auto it1 = range.first;
  auto it2 = range.second;
  auto it3 = range1.first;
  for (; it1 != it2; ++it1, ++it3) {
    EXPECT_EQ(*it1, *it3);
  }
}

//________________________________________________SET

TEST(set, default_constructor) {
  s21::Set<int> a;
  s21::Set<char> b;
  s21::Set<std::string> c;
  EXPECT_EQ(true, a.Empty());
  EXPECT_EQ(true, b.Empty());
  EXPECT_EQ(true, c.Empty());
}

TEST(set, initializer_list) {
  s21::Set<int> a{4, 5, 6, 2, 4, 3, 1, 17, 10};
  s21::Set<char> b{'l', 'p', 'h', 'a', 'd', 'z', 'c', 'r', 'o', 'f'};
  s21::Set<std::string> c{"word", "hello", "it's hard", "arrow"};

  EXPECT_EQ(false, a.Empty());
  EXPECT_EQ(false, b.Empty());
  EXPECT_EQ(false, c.Empty());
}

TEST(set, copy_constructor) {
  s21::Set<int> a{4, 5, 6, 2, 4, 3, 1, 17, 10};
  s21::Set<char> b{'l', 'p', 'h', 'a', 'd', 'z', 'c', 'r', 'o', 'f'};
  s21::Set<std::string> c{"word", "hello", "it's hard", "arrow"};
  s21::Set<int> aa(a);
  s21::Set<char> bb(b);
  s21::Set<std::string> cc(c);
  EXPECT_EQ(false, a.Empty());
  EXPECT_EQ(false, b.Empty());
  EXPECT_EQ(false, c.Empty());
  EXPECT_EQ(false, aa.Empty());
  EXPECT_EQ(false, bb.Empty());
  EXPECT_EQ(false, cc.Empty());
}

TEST(set, move_constructor) {
  s21::Set<int> a = s21::Set<int>{1, 2, 3, 4, 5};
  s21::Set<int> aa(std::move(a));

  s21::Set<char> b =
      s21::Set<char>{'l', 'p', 'h', 'a', 'd', 'z', 'c', 'r', 'o', 'f'};
  s21::Set<char> bb(std::move(b));

  s21::Set<std::string> c =
      s21::Set<std::string>{"word", "hello", "it's hard", "arrow"};
  s21::Set<std::string> cc(std::move(c));
  EXPECT_EQ(true, a.Empty());
  EXPECT_EQ(true, b.Empty());
  EXPECT_EQ(true, c.Empty());
  EXPECT_EQ(false, aa.Empty());
  EXPECT_EQ(false, bb.Empty());
  EXPECT_EQ(false, cc.Empty());
}

TEST(set, move_constructor_2) {
  s21::Set<int> int_set1 = s21::Set<int>{1, 2, 3, 4, 5};
  s21::Set<int> int_set(std::move(s21::Set<int>{18, 20}));
  s21::Set<char> char_set = s21::Set<char>{
      'l', 'p', 'h', 'a', 'd', 'z', 'c', 'r', 'o', 'f',
  };
  s21::Set<std::string> string_set =
      s21::Set<std::string>{"word", "hello", "it's hard", "arrow"};
  string_set = std::move(s21::Set<std::string>{"hello world"});
  EXPECT_EQ(false, int_set1.Empty());
  EXPECT_EQ(false, int_set.Empty());
  EXPECT_EQ(false, char_set.Empty());
  EXPECT_EQ(false, string_set.Empty());
}

TEST(set, destructor) {
  s21::Set<int> a = s21::Set<int>{4, 5, 6, 2, 4, 3, 1, 17, 10};
  s21::Set<char> b =
      s21::Set<char>{'l', 'p', 'h', 'a', 'd', 'z', 'c', 'r', 'o', 'f'};
  s21::Set<std::string> c =
      s21::Set<std::string>{"word", "hello", "it's hard", "arrow"};
  a.~Set();
  b.~Set();
  c.~Set();
  EXPECT_EQ(true, a.Empty());
  EXPECT_EQ(true, b.Empty());
  EXPECT_EQ(true, c.Empty());
}

TEST(set, assignconstuctor) {
  s21::Set<int> a{4, 5, 6};
  s21::Set<int> aa{7, 8, 9};
  std::set<int> b{4, 5, 6};
  std::set<int> bb{7, 8, 9};
  a = aa;
  b = bb;
  auto j = b.begin();
  for (auto i = a.Begin(); i != a.End(); ++i, ++j) {
    EXPECT_EQ(*i, *j);
  }
}

TEST(set, begin_end) {
  s21::Set<int> a = s21::Set<int>{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  std::set<int> b = std::set<int>{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

  auto j = b.begin();
  for (auto i = a.Begin(); i != a.End(); ++i, ++j) {
    EXPECT_EQ(*i, *j);
  }

  j = --b.end();
  for (auto i = --a.End(); i != a.End(); --i, --j) {
    EXPECT_EQ(*i, *j);
  }

  s21::Set<int>::const_iterator itconst = a.Begin();
  std::set<int>::const_iterator itconststd = b.begin();
  EXPECT_EQ(*itconst, *itconststd);
}

TEST(set, size_empty) {
  s21::Set<int> a = {4, 5, 6, 2, 4, 3, 1, 17, 10};
  std::set<int> aa = {4, 5, 6, 2, 4, 3, 1, 17, 10};

  s21::Set<char> b = {'l', 'p', 'h', 'a', 'd', 'z', 'c', 'r', 'o', 'f'};
  std::set<char> bb = {'l', 'p', 'h', 'a', 'd', 'z', 'c', 'r', 'o', 'f'};

  s21::Set<std::string> c = {"word", "hello", "it's hard", "arrow"};
  std::set<std::string> cc = {"word", "hello", "it's hard", "arrow"};

  EXPECT_EQ(false, a.Empty());
  EXPECT_EQ(false, b.Empty());
  EXPECT_EQ(false, c.Empty());
  EXPECT_EQ(a.Size(), aa.size());
  EXPECT_EQ(b.Size(), bb.size());
  EXPECT_EQ(c.Size(), cc.size());
  a.Max_Size();
}

TEST(set, insert_1) {
  s21::Set<char> s21_set_1 = {'a', 'c', 'd'};
  s21::Set<char> s21_set_2 = {'a', 'c', 'd', 'b'};

  s21_set_1.Insert('b');
  s21_set_1.Insert('a');
  auto it1 = s21_set_1.Begin();
  auto it2 = s21_set_2.Begin();
  while (it1 != s21_set_1.End()) {
    EXPECT_EQ(*it1, *it2);
    ++it1, ++it2;
  }
  EXPECT_EQ(s21_set_1.Size(), s21_set_2.Size());
}

TEST(set, insert_2) {
  s21::Set<char> s21_set;

  s21_set.Insert('b');
  s21_set.Insert('b');
  s21_set.Insert('b');

  EXPECT_EQ(s21_set.Size(), size_t(1));
}

TEST(set, insert_3) {
  s21::AVLTree<float> s21_set;
  std::set<float> std_set;

  s21_set.Insert(0.0000000000000000000000000000000000000000001, true);
  s21_set.Insert(0.000000000000000000000000000000000000000000099, true);
  std_set.insert(0.0000000000000000000000000000000000000000001);
  std_set.insert(0.000000000000000000000000000000000000000000099);

  EXPECT_EQ(s21_set.Size(), std_set.size());
}

TEST(set, insert_clear) {
  s21::Set<int> a = {4, 5, 6, 2, 4, 3, 1, 17, 10};
  std::set<int> aa = {4, 5, 6, 2, 4, 3, 1, 17, 10};
  s21::Set<char> b = {'l', 'p', 'h', 'a', 'd', 'z', 'c', 'r', 'o', 'f'};
  std::set<char> bb = {'l', 'p', 'h', 'a', 'd', 'z', 'c', 'r', 'o', 'f'};
  s21::Set<std::string> c = {"word", "hello", "it's hard", "arrow"};
  std::set<std::string> cc = {"word", "hello", "it's hard", "arrow"};

  auto pair_int_set = a.Insert(8);
  auto pairintset = aa.insert(8);

  auto pair_char_set = b.Insert('t');
  auto paircharset = bb.insert('t');

  auto pair_string_set = c.Insert("angle");
  auto pairstringset = cc.insert("angle");

  EXPECT_EQ(*(pair_int_set.first), *(pairintset.first));
  EXPECT_EQ(*(pair_char_set.first), *(paircharset.first));
  EXPECT_EQ(*(pair_string_set.first), *(pairstringset.first));

  auto pair_int_set1 = a.Insert(8);
  auto pairintset1 = aa.insert(8);
  auto pair_char_set1 = b.Insert('t');
  auto paircharset1 = bb.insert('t');
  auto pair_string_set1 = c.Insert("angle");
  auto pairstringset1 = cc.insert("angle");

  EXPECT_EQ(pair_int_set1.second, pairintset1.second);
  EXPECT_EQ(pair_char_set1.second, paircharset1.second);
  EXPECT_EQ(pair_string_set1.second, pairstringset1.second);

  EXPECT_EQ(false, a.Empty());
  EXPECT_EQ(false, b.Empty());
  EXPECT_EQ(false, c.Empty());
  a.Clear();
  aa.clear();
  b.Clear();
  bb.clear();
  c.Clear();
  cc.clear();
  EXPECT_EQ(a.Empty(), aa.empty());
  EXPECT_EQ(b.Empty(), bb.empty());
  EXPECT_EQ(c.Empty(), cc.empty());
}

TEST(set, rehash_and_insert_in_collision) {
  s21::Set<std::string> s21_set;
  std::unordered_set<std::string> std_set;
  s21_set.Insert("asd");
  s21_set.Insert("asa");
  s21_set.Insert("asf");
  s21_set.Insert("asg");
  s21_set.Insert("ash");
  s21_set.Insert("aqw");
  s21_set.Insert("fgh");
  s21_set.Insert("ghf");
  s21_set.Insert("dghfg");
  s21_set.Insert("dghfdsg");
  s21_set.Insert("dghfgfsadfsd");
  s21_set.Insert("dghfgfsadfsdasd");
  s21_set.Insert("dghfgfsadfsasdasdd");
  s21_set.Insert("dghfgfsadfsdasdasd");
  s21_set.Insert("dghfgfdsasadfdsasasdsadsad");
  s21_set.Insert("dghdsafgfsadfdsasasdsadsad");
  s21_set.Insert("ådsdghfgfsadfdsasasdsadsad");
  s21_set.Insert("dghfgfsadfdsasasdsaddsasad");
  s21_set.Insert("dghfgfsadfdsasassadadsadsad");
  s21_set.Insert("dghfgfsadfdsasdasasdsadsad");
  s21_set.Insert("dghasdaasdfgfsadfsasdsadsad");
  s21_set.Insert("asddghfgfsadfsasaß∂asdsadsad");
  s21_set.Insert("dghfgfsadfasdsasdsadsad");
  s21_set.Insert("dghfgfsadfsasdsadsad");
  s21_set.Insert("dghfgfsasdadfsasdsadsad");
  s21_set.Insert("asdsadadghfgfsadfsasdsadsad");
  std_set.insert("asd");
  std_set.insert("asa");
  std_set.insert("asf");
  std_set.insert("asg");
  std_set.insert("ash");
  std_set.insert("aqw");
  std_set.insert("fgh");
  std_set.insert("ghf");
  std_set.insert("dghfg");
  std_set.insert("dghfdsg");
  std_set.insert("dghfgfsadfsd");
  std_set.insert("dghfgfsadfsdasd");
  std_set.insert("dghfgfsadfsasdasdd");
  std_set.insert("dghfgfsadfsdasdasd");
  std_set.insert("dghfgfdsasadfdsasasdsadsad");
  std_set.insert("dghdsafgfsadfdsasasdsadsad");
  std_set.insert("ådsdghfgfsadfdsasasdsadsad");
  std_set.insert("dghfgfsadfdsasasdsaddsasad");
  std_set.insert("dghfgfsadfdsasassadadsadsad");
  std_set.insert("dghfgfsadfdsasdasasdsadsad");
  std_set.insert("dghasdaasdfgfsadfsasdsadsad");
  std_set.insert("asddghfgfsadfsasaß∂asdsadsad");
  std_set.insert("dghfgfsadfasdsasdsadsad");
  std_set.insert("dghfgfsadfsasdsadsad");
  std_set.insert("dghfgfsasdadfsasdsadsad");
  std_set.insert("asdsadadghfgfsadfsasdsadsad");
  for (auto i : std_set) {
    EXPECT_TRUE(s21_set.Find(i) != s21_set.End());
  }
  EXPECT_EQ(s21_set.Size(), std_set.size());
}

TEST(set, erase) {
  s21::Set<int> int_set = {4, 5, 6, 2, 4, 3, 1, 17, 10};
  std::set<int> intset = {4, 5, 6, 2, 4, 3, 1, 17, 10};
  s21::Set<char> char_set = {'l', 'p', 'h', 'a', 'd', 'z', 'c', 'r', 'o', 'f'};
  std::set<char> charset = {'l', 'p', 'h', 'a', 'd', 'z', 'c', 'r', 'o', 'f'};
  s21::Set<std::string> string_set = {"word", "hello", "it's hard", "arrow"};
  std::set<std::string> stringset = {"word", "hello", "it's hard", "arrow"};

  int_set.Erase(int_set.Begin());
  intset.erase(intset.begin());

  char_set.Erase(char_set.Begin());
  charset.erase(charset.begin());

  string_set.Erase(string_set.Begin());
  stringset.erase(stringset.begin());

  auto it1 = intset.begin();
  EXPECT_EQ(intset.size(), int_set.Size());
  for (auto it = int_set.Begin(); it != int_set.End(); ++it) {
    EXPECT_EQ(*it, *it1);
    ++it1;
  }
  auto it2 = charset.begin();
  EXPECT_EQ(charset.size(), char_set.Size());
  for (auto it = char_set.Begin(); it != char_set.End(); ++it) {
    EXPECT_EQ(*it, *it2);
    ++it2;
  }

  auto it3 = stringset.begin();
  EXPECT_EQ(stringset.size(), string_set.Size());
  for (auto it = string_set.Begin(); it != string_set.End(); ++it) {
    EXPECT_EQ(*it, *it3);
    ++it3;
  }
}

TEST(set, swap) {
  s21::Set<int> int_set = {4, 5, 6, 2, 4, 3, 1, 17, 10};
  s21::Set<int> int_set1 = {88, 99};
  std::set<int> intset = {4, 5, 6, 2, 4, 3, 1, 17, 10};
  std::set<int> intset1 = {88, 99};

  s21::Set<char> char_set = {'l', 'p', 'h', 'a', 'd', 'z', 'c', 'r', 'o', 'f'};
  s21::Set<char> char_set1 = {'R', 'P', 'O'};

  std::set<char> charset = {'l', 'p', 'h', 'a', 'd', 'z', 'c', 'r', 'o', 'f'};
  std::set<char> charset1 = {'R', 'P', 'O'};

  s21::Set<std::string> string_set = {"word", "hello", "it's hard", "arrow"};
  s21::Set<std::string> string_set1 = {"everebody", "likes", "cakes"};

  std::set<std::string> stringset = {"word", "hello", "it's hard", "arrow"};
  std::set<std::string> stringset1 = {"everebody", "likes", "cakes"};

  int_set.Swap(int_set1);
  intset.swap(intset1);

  char_set.Swap(char_set1);
  charset.swap(charset1);

  string_set.Swap(string_set1);
  stringset.swap(stringset1);

  auto it1 = intset.begin();
  EXPECT_EQ(intset.size(), int_set.Size());
  for (auto it = int_set.Begin(); it != int_set.End(); ++it) {
    EXPECT_EQ(*it, *it1);
    ++it1;
  }

  auto it2 = charset.begin();
  EXPECT_EQ(charset.size(), char_set.Size());
  for (auto it = char_set.Begin(); it != char_set.End(); ++it) {
    EXPECT_EQ(*it, *it2);
    ++it2;
  }

  auto it3 = stringset.begin();
  EXPECT_EQ(stringset.size(), string_set.Size());
  for (auto it = string_set.Begin(); it != string_set.End(); ++it) {
    EXPECT_EQ(*it, *it3);
    ++it3;
  }
}

TEST(set, merge) {
  s21::Set<int> int_set = {4, 5, 6, 2, 4, 3, 1, 17, 10};
  s21::Set<int> int_set1 = {88, 99};
  std::set<int> intset = {4, 5, 6, 2, 4, 3, 1, 17, 10};
  std::set<int> intset1 = {88, 99};

  s21::Set<char> char_set = {'l', 'p', 'h', 'a', 'd', 'z', 'c', 'r', 'o', 'f'};
  s21::Set<char> char_set1 = {'R', 'P', 'O'};

  std::set<char> charset = {'l', 'p', 'h', 'a', 'd', 'z', 'c', 'r', 'o', 'f'};
  std::set<char> charset1 = {'R', 'P', 'O'};

  s21::Set<std::string> string_set = {"word", "hello", "it's hard", "arrow"};
  s21::Set<std::string> string_set1 = {"everybody", "likes", "cakes"};

  std::set<std::string> stringset = {"word", "hello", "it's hard", "arrow"};
  std::set<std::string> stringset1 = {"everybody", "likes", "cakes"};

  int_set.Merge(int_set1);
  intset.merge(intset1);

  char_set1.Merge(char_set);
  charset1.merge(charset);

  string_set.Merge(string_set1);
  stringset.merge(stringset1);

  auto it1 = intset.begin();
  EXPECT_EQ(intset.size(), int_set.Size());
  for (auto it = int_set.Begin(); it != int_set.End(); ++it) {
    EXPECT_EQ(*it, *it1);
    ++it1;
  }

  auto it2 = charset1.begin();
  EXPECT_EQ(charset1.size(), char_set1.Size());
  for (auto it = char_set1.Begin(); it != char_set1.End(); ++it) {
    EXPECT_EQ(*it, *it2);
    ++it2;
  }

  auto it3 = stringset.begin();
  EXPECT_EQ(stringset.size(), string_set.Size());
  for (auto it = string_set.Begin(); it != string_set.End(); ++it) {
    EXPECT_EQ(*it, *it3);
    ++it3;
  }
}

TEST(set, find) {
  s21::Set<int> int_set = {4, 5, 6, 2, 4, 3, 1, 17, 10};
  std::set<int> intset = {4, 5, 6, 2, 4, 3, 1, 17, 10};

  s21::Set<char> char_set = {'l', 'p', 'h', 'a', 'd', 'z', 'c', 'r', 'o', 'f'};

  std::set<char> charset = {'l', 'p', 'h', 'a', 'd', 'z', 'c', 'r', 'o', 'f'};

  s21::Set<std::string> string_set = {"word", "hello", "it's hard", "arrow"};

  std::set<std::string> stringset = {"word", "hello", "it's hard", "arrow"};

  auto it_int_set = int_set.Find(10);
  auto it_intset = intset.find(10);

  auto it_char_set = char_set.Find('p');
  auto it_charset = charset.find('p');

  auto it_string_set = string_set.Find("hello");
  auto it_stringset = stringset.find("hello");

  EXPECT_EQ(*(it_int_set), *(it_intset));
  EXPECT_EQ(*(it_char_set), *(it_charset));
  EXPECT_EQ(*(it_string_set), *(it_stringset));

  EXPECT_EQ(int_set.Contains(10), true);
  EXPECT_EQ(char_set.Contains('z'), true);
  EXPECT_EQ(string_set.Contains("arrow"), true);

  EXPECT_EQ(int_set.Contains(777), false);
  EXPECT_EQ(char_set.Contains('H'), false);
  EXPECT_EQ(string_set.Contains("dummy"), false);
}

TEST(set, emplace) {
  s21::Set<int> a = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  auto v = a.Emplace(11, 12, 13, 14, 15, 16, 17, 18, 19, 20);

  for (size_t i = 0; i < v.size(); ++i) {
    EXPECT_EQ(*v[i].first, *a.Find(*v[i].first));
  }
}

TEST(set, insert_erase_find_empty) {
  s21::Set<int> tree{0};
  for (int i = 0; i < 10000; i++) {
    tree.Insert(i);
  }
  for (int i = 5000; i < 10000; i++) {
    tree.Erase(tree.Find(i));
  }
  for (int i = 0; i < 5000; i++) {
    tree.Erase(tree.Find(i));
  }
  EXPECT_EQ(tree.Empty(), true);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
