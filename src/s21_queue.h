#ifndef CPP2_S21CONTAINERS_1_SRC_S21_QUEUE_H
#define CPP2_S21CONTAINERS_1_SRC_S21_QUEUE_H

#include <initializer_list>
#include <iostream>

namespace s21 {

template <typename T>
class Queue {
 public:
  // определение типов
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;

  // default constructor, creates empty Queue
  Queue() : arr_(nullptr), count_(0) {}

  // initializer list constructor, creates Queue initizialized using
  // std::initializer_list
  Queue(std::initializer_list<T> const& items) {
    arr_ = new value_type[items.size()];
    int i = 0;
    for (auto it = items.begin(); it != items.end(); ++it) {
      arr_[i] = *it;
      ++i;
    }
    count_ = items.size();
  }
  // copy constructor
  Queue(const Queue& q) {
    count_ = q.count_;
    try {
      arr_ = new value_type[count_];
      for (int i = 0; i < count_; ++i) arr_[i] = q.arr_[i];
    } catch (std::bad_alloc& e) {
      std::cout << e.what() << std::endl;
    }
  }

  // move constructor
  Queue(Queue&& q) : count_(q.count_) {
    arr_ = q.arr_;
    q.arr_ = nullptr;
    q.count_ = 0;
  }

  // destructor
  ~Queue() {
    if (count_ > 0) delete[] arr_;
  }

  // assignment operator overload for moving object
  Queue& operator=(Queue&& q) {
    if (this != &q) {
      count_ = 0;
      delete[] arr_;
      count_ = q.count_;
      arr_ = q.arr_;
      q.count_ = 0;
      q.arr_ = nullptr;
    }
    return *this;
  }
  // operator реализует присваивание объектов типа Queue
  Queue& operator=(const Queue& other) {
    T* p2;  // указатель на дополнительную память
    try {
      p2 = new value_type[other.count_];
      if (count_ > 0) delete[] arr_;
      arr_ = p2;
      count_ = other.count_;
      for (int i = 0; i < count_; ++i) arr_[i] = other.arr_[i];
    } catch (std::bad_alloc& e) {
      // если память не выделилась
      std::cout << e.what() << std::endl;
    }
    return *this;
  }
  // публичные методы для доступа к элементам класса:
  const_reference front() {
    if (count_ == 0) {
      throw "Queue is empty";
    }
    return arr_[0];
  }

  const_reference back() {
    if (count_ == 0) {
      throw "Queue is empty";
    }
    return arr_[count_ - 1];
  }

  // публичные методы для доступа к информации о наполнении контейнера:
  bool empty() {  // true если очередь пуста
    return count_ == 0;
  }

  size_type size() { return count_; }

  // публичные методы для изменения контейнера
  void push(const T& value) {
    value_type* p2;
    p2 = arr_;
    try {
      arr_ = new value_type[count_ + 1];
      for (int i = 0; i < count_; ++i) arr_[i] = p2[i];
      arr_[count_] = value;
      ++count_;
      if (count_ > 1) delete[] p2;
    } catch (std::bad_alloc& e) {
      // если память не выделена
      std::cout << e.what() << std::endl;
      arr_ = p2;  // вернуть старый указатель на arr_
    }
  }

  void pop() {
    if (count_ == 0) throw "Collection is empty";
    value_type* p2;
    p2 = new value_type[count_ - 1];
    count_--;
    for (int i = 0; i < count_; ++i)
      p2[i] = arr_[i + 1];  // копируются все кроме первого элемента
    if (count_ > 0) delete[] arr_;
    arr_ = p2;
  }

  void swap(Queue& other) {
    Queue tmp = *this;
    *this = other;
    other = tmp;
  }

  template <typename... Args>
  void insert_many_back(Args&&... args) {
    value_type* p2;
    p2 = arr_;
    arr_ = new value_type[count_ + (sizeof...(Args))];
    for (int i = 0; i < count_; ++i) arr_[i] = p2[i];
    ((arr_[count_++] = args), ...);
    delete[] p2;
  }

 private:
  value_type* arr_;  // динамический масссив
  int count_;  // количество элементов в очереди
};
}  // namespace s21
#endif  // CPP2_S21CONTAINERS_1_SRC_S21_QUEUE_H
