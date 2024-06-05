#ifndef CPP2_S21_CONTAINERS_1_SRC_S21_VECTOR_H
#define CPP2_S21_CONTAINERS_1_SRC_S21_VECTOR_H

#include <initializer_list>
#include <iostream>
#include <utility>

namespace s21 {

template <typename T>
class Vector {
 public:
  // определение типов
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;
  // CLASS ITERATOR
  class Iterator {
   public:
    Iterator(T* p) : point_(p) {}

    Iterator& operator++() {
      ++point_;
      return *this;
    }
    Iterator& operator+(size_t val) {
      point_ += val;
      return *this;
    }
    void s21advance(Iterator& a, size_t val) { a.point_ += val; }

    Iterator& operator--() {
      --point_;
      return *this;
    }

    T& operator*() { return *point_; }

    bool operator==(const Iterator& b) const { return *point_ == *b.point_; }

    bool operator!=(const Iterator& b) const { return *point_ != *b.point_; }

   private:
    T* point_;
  };
  // CLASS CONST_ITERATOR
  class ConstIterator {
   public:
    ConstIterator(T* p) : point_(p) {}

    ConstIterator& operator++() {
      ++point_;
      return *this;
    }
    ConstIterator& operator--() {
      --point_;
      return *this;
    }

    void s21advance_const(ConstIterator& a, size_t val) const {
      a.point_ += val;
    }

    T& operator*() const { return *point_; }

    bool operator==(const ConstIterator& b) const {
      return *point_ == *b.point_;
    }

    bool operator!=(const ConstIterator& b) const {
      return *point_ != *b.point_;
    }

   private:
    T* point_;
  };

  // публичные методы для взаимодействия с классом
  //  constructors
  Vector() : m_size_(0U), m_capacity_(0U), arr_(nullptr) {}

  explicit Vector(size_t n)
      : m_size_(n), m_capacity_(n), arr_(n ? new T[n]() : nullptr) {}

  Vector(std::initializer_list<value_type> const& items)
      : m_size_(items.size()),
        m_capacity_(items.size()),
        arr_(items.size() ? new T[items.size()] : nullptr) {
    int i = 0;
    for (auto it = items.begin(); it != items.end(); ++it) {
      arr_[i] = *it;
      ++i;
    }
  }

  Vector(const Vector& v)
      : m_size_(v.m_size_),
        m_capacity_(v.m_capacity_),
        arr_(new T[v.m_size_]()) {
    for (size_type i = 0; i < v.m_size_; ++i) {
      arr_[i] = v.arr_[i];
    }
  }

  Vector(Vector&& v) : m_size_(v.m_size_), m_capacity_(v.m_capacity_) {
    arr_ = v.arr_;
    v.arr_ = nullptr;
    v.m_size_ = 0;
    v.m_capacity_ = 0;
  }

  // destructor
  ~Vector() { clear(); }

  // operators
  Vector& operator=(const Vector& v) {
    clear();
    m_size_ = v.m_size_;
    m_capacity_ = v.m_capacity_;
    arr_ = new T[v.m_size_]();
    for (size_type i = 0; i < v.m_size_; ++i) {
      arr_[i] = v.arr_[i];
    }
    return *this;
  }

  Vector& operator=(Vector&& v) {
    if (this != &v) {
      clear();
      m_size_ = v.m_size_;
      m_capacity_ = v.m_capacity_;
      arr_ = v.arr_;
      v.arr_ = nullptr;
      v.m_size_ = 0;
      v.m_capacity_ = 0;
    }
    return *this;
  }

  // references
  T& at(size_t pos) {
    if (pos >= m_size_) {
      throw std::out_of_range("ERROR! Wrong position");
    }
    return arr_[pos];
  }

  T& at(size_t pos) const {
    if (pos >= m_size_) {
      throw std::out_of_range("ERROR! Wrong position");
    }
    return arr_[pos];
  }

  T& operator[](size_t pos) { return arr_[pos]; }

  T& operator[](size_t pos) const { return arr_[pos]; }

  const T& front() const { return arr_[0]; }

  const T& back() const { return arr_[m_size_ - 1]; }

  T* data() { return arr_; }

  // iterators
  Iterator begin() { return Iterator(arr_); }
  Iterator end() { return arr_ ? Iterator(arr_ + m_size_) : nullptr; }
  ConstIterator cbegin() const { return ConstIterator(arr_); }
  ConstIterator cend() const {
    return arr_ ? ConstIterator(arr_ + m_size_) : nullptr;
  }

  Iterator insert(Iterator pos, const_reference value) {
    Vector<T>::Iterator i_end = end();
    int return_pos = 0;
    if (m_size_ + 1 > m_capacity_) reserve(m_size_ * 2);
    size_type news = capacity();
    T* newarr = new T[news];
    int j = 0;
    for (Vector<T>::Iterator i = begin(); i != pos; ++i) {
      newarr[j++] = *i;
    }
    newarr[j++] = value;
    return_pos = j;
    for (Vector<T>::Iterator i = pos; i != i_end; ++i) {
      newarr[j++] = *i;
    }
    delete[] arr_;
    arr_ = newarr;
    ++m_size_;
    Vector<T>::Iterator i = begin() + return_pos;
    return i;
  }

  // capacity
  bool empty() { return (m_size_ == 0); }

  size_type size() { return m_size_; }

  size_type max_size() { return m_capacity_; }

  void reserve(size_t size) {
    if (size <= m_capacity_) return;
    moving(size);
  }

  size_type capacity() { return m_capacity_; }

  void shrink_to_fit() {
    if (m_size_ == m_capacity_) return;
    moving(m_size_);
  }

  Vector& moving(size_t size) {
    T* newarr = new T[size];
    size_type s = m_size_;
    for (size_type i = 0; i < s; ++i) {
      newarr[i] = arr_[i];
    }
    clear();
    arr_ = std::move(newarr);
    m_size_ = s;
    m_capacity_ = size;
    return *this;
  }

  // modifiers
  void clear() {
    if (arr_ != nullptr) {
      delete[] arr_;
      m_capacity_ = 0;
    }
    m_size_ = 0;
  }

  void erase(Iterator pos) {
    T* newarr = new T[m_size_ - 1];
    int j = 0;
    for (Vector<T>::Iterator i = begin(); i != pos; ++i) {
      newarr[j] = *i;
      ++j;
    }
    for (Vector<T>::Iterator i = pos + 1; i != end(); ++i) {
      newarr[j] = *i;
      ++j;
    }
    delete[] arr_;
    arr_ = newarr;
    --m_size_;
  }

  void push_back(const_reference value) {
    if (m_capacity_ == m_size_) {
      if (!m_size_) {
        reserve(1);
      } else {
        reserve(m_size_ * 2);
      }
    }
    arr_[m_size_++] = value;
  }

  void pop_back() {
    if (m_size_ > 0) --m_size_;
  }

  void swap(Vector& other) {
    size_t tmp_capacity = m_capacity_, tmp_size = m_size_;
    if (m_size_ != other.size()) {
      (m_size_ < other.size()) ? reserve(other.size()) : other.reserve(m_size_);
    }
    T* tmp_arr = arr_;
    m_size_ = other.m_size_;
    m_capacity_ = other.m_capacity_;
    arr_ = other.data();
    other.m_size_ = tmp_size;
    other.m_capacity_ = tmp_capacity;
    other.arr_ = tmp_arr;
  }

  // bonus
  template <typename... Args>
  Iterator emplace(ConstIterator pos, Args&&... args) {
    Vector<T>::ConstIterator i_end = cend();
    int return_pos = 0;
    if (m_size_ + (sizeof...(Args)) > m_capacity_)
      reserve(m_size_ + (sizeof...(Args)));
    size_t news = capacity();
    T* newarr = new T[news];
    int j = 0;
    for (s21::Vector<T>::ConstIterator i = cbegin(); i != pos; ++i) {
      newarr[j++] = *i;
    }
    return_pos = j;
    ((newarr[j++] = args), ...);
    for (s21::Vector<T>::ConstIterator i = pos; i != i_end; ++i) {
      newarr[j++] = *i;
    }
    delete[] arr_;
    arr_ = newarr;
    m_size_ += (sizeof...(Args));
    Vector<T>::Iterator result = begin();
    return result + return_pos;
  }

  template <typename... Args>
  void emplace_back(Args&&... args) {
    ([&] { push_back(args); }(), ...);
  }

 private:
  size_t m_size_;
  size_t m_capacity_;
  T* arr_;
};

}  // namespace s21

#endif /* CPP2_S21_CONTAINERS_1_SRC_S21_VECTOR_H */
