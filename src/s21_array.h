#ifndef CPP2_S21CONTAINERS_1_SRC_S21_ARRAY_H
#define CPP2_S21CONTAINERS_1_SRC_S21_ARRAY_H

#include <initializer_list>
#include <iostream>

namespace s21 {

template <typename T, size_t N>
class Array {
 public:
  // внутриклассовое переопределение типов (типичное для стандартной библиотеки
  //  STL),
  //  принятое для удобства восприятия кода класса
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;
  using iterator = T*;  // объектная оболочка над указателем для взаимодействия
                        // с элементами контейнера
  using const_iterator = const T*;

  Array() {
    count_ = N;
    if (count_ != 0)
      arr_ = new value_type[count_];
    else
      arr_ = 0;
  }

  // initializer list constructor, creates Array initizialized using
  // std::initializer_list
  Array(std::initializer_list<value_type> const& items) {
    arr_ = new value_type[items.size()];
    int i = 0;
    for (auto it = items.begin(); it != items.end(); ++it) {
      arr_[i] = *it;
      ++i;
    }
    count_ = items.size();
  }

  // copy constructor
  Array(const Array& a) {
    count_ = a.count_;
    try {
      arr_ = new value_type[count_];
      for (int i = 0; i < count_; ++i) arr_[i] = a.arr_[i];
    } catch (std::bad_alloc& e) {
      std::cout << e.what() << std::endl;
    }
  }

  // move constructor
  Array(Array&& a) : count_(a.count_) {
    arr_ = a.arr_;
    a.arr_ = nullptr;
    a.count_ = 0;
  }

  // destructor
  ~Array() {
    if (count_ > 0) delete[] arr_;
  }

  // assignment operator overload for moving object
  Array& operator=(Array&& a) {
    if (this != &a) {
      count_ = 0;
      delete[] arr_;
      count_ = a.count_;
      arr_ = a.arr_;
      a.count_ = 0;
      a.arr_ = nullptr;
    }
    return *this;
  }

  // публичные методы для доступа к элементам класса
  reference at(size_type pos) {
    if (pos >= (size_t)count_)
      throw std::out_of_range("Incorrect position");
    else {
      return arr_[pos];
    }
  }

  reference operator[](size_type pos) { return arr_[pos]; }

  const_reference front() {
    if (count_ == 0) {
      throw "Array is empty";
    }
    return arr_[0];
  }

  const_reference back() {
    if (count_ == 0) {
      throw "Array is empty";
    }
    return arr_[count_ - 1];
  }

  iterator data() { return &arr_[0]; }
  //}    !!!!!!!!!!!!!

  // публичные методы для итерирования по элементам класса (доступ к итераторам)
  iterator begin() { return &arr_[0]; }

  iterator end() { return &arr_[count_]; }

  // публичные методы для доступа к информации о наполнении контейнера
  bool empty() { return count_ == 0; }  // true если очередь пуст

  size_type size() { return count_; }

  size_type max_size() { return count_; }

  // публичные методы для изменения контейнера
  void swap(Array& other) {
    std::swap(arr_, other.arr_);
    std::swap(count_, other.count_);
  }

  void fill(const_reference value) {
    if (count_ == 0) {
      throw "Array is empty";
    } else {
      for (int i = 0; i < count_; ++i) arr_[i] = value;
    }
  }

 private:
  value_type* arr_;
  int count_;
};
}  // namespace s21
#endif  // CPP2_S21CONTAINERS_1_SRC_S21_ARRAY_H
