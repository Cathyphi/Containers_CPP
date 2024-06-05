#ifndef CPP2_S21CONTAINERS_1_SRC_S21_STACK_H
#define CPP2_S21CONTAINERS_1_SRC_S21_STACK_H

#include <initializer_list>
#include <iostream>

namespace s21 {

template <typename T>
class Stack {
 public:
  // определение типов
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;

  // default constructor, creates empty Queue
  Stack() : stack_(nullptr), count_(0) {}

  // initializer list constructor, creates Queue initizialized using
  // std::initializer_list
  Stack(std::initializer_list<T> const& items) {
    stack_ = new value_type[items.size()];
    int i = 0;
    for (auto it = items.begin(); it != items.end(); ++it) {
      stack_[i] = *it;
      ++i;
    }
    count_ = items.size();
  }
  // copy constructor
  Stack(const Stack& s) {
    count_ = s.count_;
    try {
      stack_ = new value_type[count_];
      for (int i = 0; i < count_; ++i) stack_[i] = s.stack_[i];
    } catch (std::bad_alloc& e) {
      std::cout << e.what() << std::endl;
      count_ = 0;  // создать пустую очередь
    }
  }
  // move constructor
  Stack(Stack&& s) : count_(s.count_) {
    stack_ = s.stack_;
    s.stack_ = nullptr;
    s.count_ = 0;
  }

  // destructor
  ~Stack() {
    if (count_ > 0) delete[] stack_;
  }

  // assignment operator overload for moving object
  Stack& operator=(Stack&& s) {
    if (this != &s) {
      count_ = 0;
      delete[] stack_;
      count_ = s.count_;
      stack_ = s.stack_;
      s.count_ = 0;
      s.stack_ = nullptr;
    }
    return *this;
  }
  // operator реализует присваивание объектов типа Queue
  Stack& operator=(const Stack& other) {
    value_type* p2;  // указатель на дополнительную память
    try {
      p2 = new value_type[other.count_];
      if (count_ > 0) delete[] stack_;
      stack_ = p2;
      count_ = other.count_;
      for (int i = 0; i < count_; ++i) stack_[i] = other.stack_[i];
    } catch (std::bad_alloc& e) {
      // если память не выделилась
      std::cout << e.what() << std::endl;
    }
    return *this;
  }
  // публичный метод для доступа к элементам класса:
  const_reference top() {
    if (count_ == 0) {
      throw "Queue is empty";
    }
    return stack_[count_ - 1];
  }

  // публичные методы для доступа к информации о наполнении контейнера:
  bool empty() {  // true если очередь пуста
    return count_ == 0;
  }

  size_type size() { return count_; }
  // публичные методы для изменения контейнера
  void push(const T& value) {
    value_type* p2;
    p2 = stack_;
    try {
      stack_ = new value_type[count_ + 1];
      for (int i = 0; i < count_; ++i) stack_[i] = p2[i];
      stack_[count_] = value;
      ++count_;
      if (count_ > 1) delete[] p2;
    } catch (std::bad_alloc& e) {
      // если память не выделена
      std::cout << e.what() << std::endl;
      stack_ = p2;  // вернуть старый указатель на arr_
    }
  }

  void pop() {
    if (count_ == 0) throw "Collection is empty";
    value_type* p2;
    p2 = new value_type[count_ - 1];
    --count_;
    for (int i = 0; i < count_; ++i) p2[i] = stack_[i];
    if (count_ > 0) delete[] stack_;
    stack_ = p2;
  }

  void swap(Stack& other) {
    Stack tmp = *this;
    *this = other;
    other = tmp;
  }

  template <typename... Args>
  void insert_many_front(Args&&... args) {
    value_type* p2;
    p2 = stack_;
    stack_ = new value_type[count_ + (sizeof...(Args))];
    for (int i = 0; i < count_; ++i) stack_[i] = p2[i];
    ((stack_[count_++] = args), ...);
    delete[] p2;
  }

 private:
  value_type* stack_;  // динамический массив-указатель на стек
  int count_;  // количество элементов в очереди
};
}  // namespace s21
#endif  // CPP2_S21CONTAINERS_1_SRC_S21_STACK_H
