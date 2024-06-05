#ifndef S21_CONTAINERS_1_SRC_S21_MULTISET_H_
#define S21_CONTAINERS_1_SRC_S21_MULTISET_H_

#include "s21_tree.h"

namespace s21 {

template <typename Key, typename Comparator = std::less<Key>>
class Multiset : public AVLTree<Key, Comparator> {
 public:
  // Внутриклассовые переопределения типов:
  // тип элемента множества
  using key_type = typename AVLTree<Key, Comparator>::key_type;
  // итератор для множества
  using iterator = typename AVLTree<Key, Comparator>::iterator;
  // тип бинарного дерева для множества
  using tree_type = typename AVLTree<Key, Comparator>::tree_type;
  // тип размера контейнера
  using size_type = std::size_t;

  // конструктор по умолчанию
  Multiset() : tree_type() {}
  // конструктор c инициализацией через список
  Multiset(std::initializer_list<key_type> const &items)
      : tree_type(items, false) {}
  // вставляет во множество новый элемент
  iterator Insert(const key_type &key) {
    return tree_type::Insert(key, false).first;
  }
  // объединяет дерево с элементами другого дерева
  void Merge(tree_type &other) { tree_type::Merge(other, false); }
  // возвращает количество элементов с ключом, равным key
  size_type Count(const Key &key) noexcept {
    iterator lower_it = Lower_Bound(key);
    iterator upper_it = Upper_Bound(key);
    size_type k = 0;
    while (lower_it != upper_it && *lower_it == key) {
      ++lower_it;
      ++k;
    }
    return k;
  }
  // возвращает диапазон элементов, соответствующих определенному ключу
  std::pair<iterator, iterator> Equal_Range(const Key &key) noexcept {
    iterator first = Lower_Bound(key);
    iterator last = Upper_Bound(key);
    return std::pair<iterator, iterator>(first, last);
  }
  // возвращает итератор к первому элементу, значение которого не меньше
  // заданного ключа
  iterator Lower_Bound(const Key &key) noexcept {
    return iterator(tree_type::LowerBoundNode(key), this);
  }
  // возвращает итератор к первому элементу, значение которого больше заданного
  // ключа
  iterator Upper_Bound(const Key &key) noexcept {
    return iterator(tree_type::UpperBoundNode(key), this);
  }
  // размещает список значений во множество
  template <typename... Args>
  std::vector<std::pair<iterator, bool>> Emplace(Args &&...args) {
    return tree_type::Emplace(false, args...);
  }
};

}  // namespace s21

#endif  // S21_CONTAINERS_1_SRC_S21_MULTISET_H_