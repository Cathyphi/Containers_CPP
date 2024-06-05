#ifndef S21_CONTAINERS_1_SRC_S21_MAP_H_
#define S21_CONTAINERS_1_SRC_S21_MAP_H_

#include "s21_tree.h"

namespace s21 {

template <class Key, class Type, typename Comparator = std::less<Key>>
class Map {
 public:
  // Внутриклассовые переопределения типов:
  // тип ключа словаря (первого параметра шаблона)
  using key_type = Key;
  // тип значения элемента словаря (второго параметра шаблона)
  using mapped_type = Type;
  // тип элемента словаря
  using value_type = std::pair<key_type, mapped_type>;
  // тип ссылки на элемент словаря
  using reference = value_type &;
  // тип константной ссылки на элемент словаря
  using const_reference = const value_type &;
  // компаратор словаря
  struct MapComparator {
    bool operator()(const_reference op1, const_reference op2) const noexcept {
      return cmp_(op1.first, op2.first);
    }
    Comparator cmp_;
  };
  // тип бинарного дерева для словаря
  using tree_type = AVLTree<value_type, MapComparator>;
  // итератор для словаря
  using iterator = typename tree_type::iterator;
  // константный итератор для словаря
  using const_iterator = typename tree_type::const_iterator;
  // тип размера контейнера
  using size_type = std::size_t;

  // Основные публичные методы для взаимодействия с классом:
  // конструктор по умолчанию
  Map() {
    tree_ = new tree_type();
    if (tree_ == nullptr) throw std::bad_alloc();
  }
  // конструктор c инициализацией через список
  Map(std::initializer_list<value_type> const &items) {
    tree_ = new tree_type(items, true);
    if (tree_ == nullptr) throw std::bad_alloc();
  }
  // конструктор копирования
  Map(const Map &other) {
    tree_ = new tree_type(*other.tree_);
    if (tree_ == nullptr) throw std::bad_alloc();
  }
  // конструктор переноса
  Map(Map &&other) noexcept { *tree_ = std::move(*other.tree_); }
  // присваивание копированием
  Map &operator=(const Map &other) {
    if (this != &other) {
      *tree_ = *other.tree_;
    }
    return *this;
  }
  // присваивание переносом
  Map &operator=(Map &&other) noexcept {
    if (this != &other) {
      *tree_ = std::move(*other.tree_);
    }
    return *this;
  }
  // деструктор
  ~Map() {
    delete tree_;
    tree_ = nullptr;
  }

  // Публичные методы для доступа к элементам класса:
  // доступ к указанному элементу через at
  mapped_type &At(const key_type &key) {
    value_type value(key, mapped_type{});
    iterator it = tree_->Find(value);
    if (it == tree_->End())
      throw std::out_of_range("No elements with key");
    else
      return (*it).second;
  }
  // доступ к указанному элементу через []
  mapped_type &operator[](const key_type &key) { return At(key); }

  // Публичные методы для итерирования по элементам класса:
  // возвращает итератор на начало контейнера
  iterator Begin() noexcept { return tree_->Begin(); }
  // возвращает константный итератор на начало контейнера
  const_iterator Begin() const noexcept {
    return const_iterator(tree_->Begin());
  }
  // возвращает итератор на конец контейнера
  iterator End() noexcept { return tree_->End(); }
  // возвращает константый итератор на конец контейнера
  const_iterator End() const noexcept { return const_iterator(tree_->End()); }

  // Публичные методы для доступа к информации о наполнении контейнера:
  // проверяет, пустой ли контейнер
  bool Empty() const noexcept { return (tree_ == nullptr || tree_->Empty()); }
  // возвращает количество элементов контейнера
  size_type Size() const noexcept { return tree_->Size(); }
  // возвращает максимально допустимое количество элементов в контейнере
  size_type Max_Size() const noexcept { return tree_->Max_Size(); }

  // Публичные методы для изменения контейнера:
  // очистка содержимого контейнера
  void Clear() const noexcept { tree_->Clear(); }
  // вставка в контейнер элемента со значением value
  std::pair<iterator, bool> Insert(const value_type &value) const {
    return tree_->Insert(value, true);
  }
  // вставка в контейнер элемента со значениями key и obj
  std::pair<iterator, bool> Insert(const key_type &key,
                                   const mapped_type &obj) const {
    return tree_->Insert(value_type{key, obj});
  }
  // вставляет элемент или присваивает новое значение текущему элементу
  std::pair<iterator, bool> Insert_Or_Assign(const key_type &key,
                                             const mapped_type &obj) const {
    iterator it = tree_->Find(value_type{key, obj});
    if (it != tree_->End()) {
      (*it).second = obj;
      return {it, false};
    } else
      return tree_->Insert(value_type{key, obj}, true);
  }
  // удаляет элемент из заданной позиции
  void Erase(iterator pos) const noexcept { tree_->Erase(pos); }
  // обменивает содержимое контейнера с other
  void Swap(Map &other) const noexcept { tree_->Swap(*other.tree_); }
  // объединяет дерево с элементами другого дерева
  void Merge(Map &other) const noexcept { tree_->Merge(*other.tree_, true); }

  // Публичные методы, осуществляющие просмотр контейнера:
  // проверка наличия в контейнере элемента с ключом key
  bool Contains(const key_type &key) const noexcept {
    value_type value(key, mapped_type{});
    return tree_->Contains(value);
  }

 private:
  tree_type *tree_;  // бинарное дерево словаря
};

}  // namespace s21

#endif  // S21_CONTAINERS_1_SRC_S21_MAP_H_
