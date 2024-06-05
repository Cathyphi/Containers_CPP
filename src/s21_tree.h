#ifndef S21_CONTAINERS_1_SRC_S21_TREE_H
#define S21_CONTAINERS_1_SRC_S21_TREE_H

#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <vector>

namespace s21 {

template <typename Key, typename Comparator = std::less<Key>>
class AVLTree {
 protected:
  struct AVLTreeNode;
  struct AVLTreeIterator;
  struct AVLTreeIteratorConst;

 public:
  // Внутриклассовые переопределения типов:
  // тип ключевого элемента в узле дерева
  using key_type = Key;
  // тип ссылки на элемент
  using reference = key_type &;
  // тип ссылки на элемент (константный)
  using const_reference = const key_type &;
  // внутренний класс для обычных итераторов (неконстантых)
  using iterator = AVLTreeIterator;
  // внутренний класс для константных итераторов
  using const_iterator = const AVLTreeIteratorConst;
  // тип размера контейнера
  using size_type = std::size_t;
  // тип размера высоты узла
  using height_type = int;
  // внутренний класс дерева
  using tree_type = AVLTree;
  // внутренний класс узла дерева
  using tree_node = AVLTreeNode;

  // Основные публичные методы для взаимодействия с классом:
  // конструктор по умолчанию
  AVLTree() : head_(nullptr), size_(0U) {
    end_ = new tree_node;
    if (end_ == nullptr) throw std::bad_alloc();
  }
  // конструктор c инициализацией через список
  AVLTree(std::initializer_list<key_type> const &items, bool unique)
      : AVLTree() {
    for (auto item : items) {
      Insert(item, unique);
    }
  }
  // конструктор копирования
  AVLTree(const tree_type &other) : AVLTree() {
    head_ = CopyTree(other.head_, nullptr);
    size_ = other.size_;
  }
  // конструктор переноса
  AVLTree(tree_type &&other) : AVLTree() { Swap(other); }
  // присваивание копированием
  tree_type &operator=(const tree_type &other) {
    if (this != &other) {
      Clear();
      head_ = CopyTree(other.head_, nullptr);
      size_ = other.size_;
    }
    return *this;
  }
  // присваивание переносом
  tree_type &operator=(tree_type &&other) noexcept {
    if (this != &other) {
      Clear();
      Swap(other);
    }
    return *this;
  }
  // деструктор
  ~AVLTree() {
    Clear();
    delete end_;
    end_ = nullptr;
  }

  // Публичные методы для итерирования по элементам класса:
  // возвращает итератор на начало контейнера
  iterator Begin() noexcept {
    return (head_ == nullptr ? End() : iterator(FirstLeftNode(head_), this));
  }
  const_iterator Begin() const noexcept {
    return const_iterator(head_ == nullptr ? End() : FirstLeftNode(head_),
                          this);
  }
  // возвращает итератор на конец контейнера (после последнего элемента)
  iterator End() noexcept { return iterator(end_, this); }
  const_iterator End() const noexcept { return const_iterator(end_, this); }

  // Публичные методы для доступа к информации о наполнении контейнера:
  // проверяет, пустой ли контейнер
  bool Empty() const noexcept { return size_ == 0; }
  // возвращает количество элементов в контейнере
  size_type Size() const noexcept { return size_; }
  // возвращает максимальное допустимое количество элементов в контейнере
  size_type Max_Size() const noexcept {
    size_type result = std::numeric_limits<size_type>::max() / 2;
    result -= sizeof(tree_type);
    result -= sizeof(tree_node);
    result /= sizeof(tree_node);
    return result;
  }

  // Публичные методы для изменения контейнера:
  // удаляет содержимое контейнера
  void Clear() noexcept {
    Destroy(head_);
    head_ = nullptr;
    size_ = 0;
  }
  // вставляет в контейнер ключевой элемент
  std::pair<iterator, bool> Insert(const key_type &key, bool unique) {
    tree_node *node = new tree_node(key);
    if (node == nullptr) throw std::bad_alloc();
    bool flag = InsertNode(head_, node, unique);
    std::pair<iterator, bool> result = {
        iterator(flag == true ? node : nullptr, this), flag};
    if (flag == false) delete node;
    return result;
  }
  // удаляет элемент на определенной позиции
  void Erase(iterator pos) noexcept { RemoveNode(head_, *pos); }
  // обменивает содержимое одного контейнера на содержимое контейнера other
  void Swap(tree_type &other) noexcept {
    std::swap(head_, other.head_);
    std::swap(size_, other.size_);
  }
  // объединяет дерево с элементами другого дерева
  void Merge(tree_type &other, bool unique) {
    if (this != &other) {
      iterator pos = other.Begin();
      while (pos != other.End()) {
        if (Insert(*pos, unique).second == true) {
          other.Erase(pos);
          pos = other.Begin();
        } else {
          ++pos;
        }
      }
    }
  }
  // размещает список ключевых значений в контейнер
  template <typename... Args>
  std::vector<std::pair<iterator, bool>> Emplace(bool unique, Args &&...args) {
    std::vector<std::pair<iterator, bool>> result;
    for (auto key : {std::forward<Args>(args)...}) {
      tree_node *node = new tree_node(std::move(key));
      if (node == nullptr) throw std::bad_alloc();
      bool res = InsertNode(head_, node, unique);
      if (res == false) {
        delete node;
        node = nullptr;
      }
      result.push_back({iterator(node, this), res});
    }
    return result;
  }

  // Публичные методы, осуществляющие просмотр контейнера:
  // поиск элемента конейнера с ключом key
  iterator Find(const_reference key) noexcept {
    tree_node *node = NodeSearch(head_, key);
    return iterator(node, this);
  }
  // проверка наличия в контейнере элемента с ключом key
  bool Contains(const key_type &key) noexcept {
    return Find(key) != iterator(end_, this);
  }

 protected:
  // Создание узлов дерева копирование узлов из другого дерева
  tree_node *CopyTree(const tree_node *root, tree_node *parent) {
    tree_node *node = nullptr;
    if (root != nullptr) {
      node = new tree_node(root->key_);
      node->hеight_ = root->hеight_;
      node->parent_ = parent;
      try {
        if (root->left_ != nullptr) node->left_ = CopyTree(root->left_, node);
        if (root->right_ != nullptr)
          node->right_ = CopyTree(root->right_, node);
      } catch (...) {
        Destroy(node);
        throw std::bad_alloc();
      }
    }
    return node;
  }

  // Рекурсивно удаляет все узлы и освобождает память
  void Destroy(tree_node *root) noexcept {
    if (root != nullptr) {
      Destroy(root->left_);
      Destroy(root->right_);
      delete root;
    }
  }

  // Возвращает самый первый левый узел дерева
  tree_node *FirstLeftNode(tree_node *root) const noexcept {
    if (root == nullptr) return nullptr;
    if (root->left_ == nullptr) return root;
    return FirstLeftNode(root->left_);
  }

  // Возвращает самый последний правый узел дерева
  tree_node *LastRightNode(tree_node *root) const noexcept {
    if (root == nullptr) return nullptr;
    if (root->right_ == nullptr) return root;
    return LastRightNode(root->right_);
  }

  // Поиск узла дерева с ключом key
  tree_node *NodeSearch(tree_node *root, const_reference key) const noexcept {
    if (root == nullptr) return end_;
    if (!cmp_(key, root->key_) && !cmp_(root->key_, key)) return root;
    return (cmp_(key, root->key_) ? NodeSearch(root->left_, key)
                                  : NodeSearch(root->right_, key));
  }

  // Поиск ближайшего узла, ключ которого не меньше заданного ключа
  tree_node *LowerBoundNode(const_reference key) const noexcept {
    tree_node *begin = head_;
    tree_node *res = end_;
    while (begin != nullptr) {
      if (!cmp_(begin->key_, key)) {
        res = begin;
        begin = begin->left_;
      } else {
        begin = begin->right_;
      }
    }
    return res;
  }

  // Поиск ближайшего узла, ключ которого больше заданного ключа
  tree_node *UpperBoundNode(const_reference key) const noexcept {
    tree_node *begin = head_;
    tree_node *res = end_;
    while (begin != nullptr) {
      if (cmp_(key, begin->key_)) {
        res = begin;
        begin = begin->left_;
      } else {
        begin = begin->right_;
      }
    }
    return res;
  }

  // Возвращает узел, следующий за текущим узлом
  tree_node *NextNode(tree_node *node) const noexcept {
    if (node == LastRightNode(head_)) return end_;
    if (node == end_) return FirstLeftNode(head_);
    if (node != nullptr) {
      if (node->right_ != nullptr)
        node = FirstLeftNode(node->right_);
      else {
        tree_node *parent = node->parent_;
        while (parent != nullptr && parent->right_ == node) {
          node = parent;
          parent = node->parent_;
        }
        node = parent;
      }
    }
    return (node == nullptr ? end_ : node);
  }

  // Возвращает узел, предыдущий относительного текущего узла
  tree_node *PrevNode(tree_node *node) const noexcept {
    if (node == end_) return LastRightNode(head_);
    if (node == FirstLeftNode(head_)) return end_;
    if (node != nullptr) {
      if (node->left_ != nullptr)
        node = LastRightNode(node->left_);
      else {
        tree_node *parent = node->parent_;
        while (parent != nullptr && parent->left_ == node) {
          node = parent;
          parent = node->parent_;
        }
        node = parent;
      }
    }
    return (node == nullptr ? FirstLeftNode(head_) : node);
  }

  // Вставка (рекурсивная) в дерево нового узла
  bool InsertNode(tree_node *root, tree_node *node, bool unique) noexcept {
    if (node == nullptr) return false;
    bool result = true;
    if (root == nullptr) {
      head_ = node;
      ++size_;
    } else {
      if (cmp_(node->key_, root->key_)) {
        if (root->left_ == nullptr) {
          root->left_ = node;
          node->parent_ = root;
          ++size_;
        } else
          result = InsertNode(root->left_, node, unique);
      } else if ((unique && cmp_(root->key_, node->key_)) || !unique) {
        if (root->right_ == nullptr) {
          root->right_ = node;
          node->parent_ = root;
          ++size_;
        } else
          result = InsertNode(root->right_, node, unique);
      } else
        result = false;
    }
    if (result == true) {
      UpdateHeight(root);
      Balance(root);
    }
    return result;
  }

  // Удаление узла из дерева
  void RemoveNode(tree_node *root, key_type key) noexcept {
    if (root == nullptr)
      return;
    else if (cmp_(key, root->key_))
      RemoveNode(root->left_, key);
    else if (cmp_(root->key_, key))
      RemoveNode(root->right_, key);
    else if (root->left_ == nullptr || root->right_ == nullptr) {
      tree_node *child = (root->right_ == nullptr ? root->left_ : root->right_);
      if (child != nullptr) {
        root->key_ = child->key_;
        root->hеight_ = child->hеight_;
        root->left_ = child->left_;
        root->right_ = child->right_;
        if (child->left_ != nullptr) (child->left_)->parent_ = root;
        if (child->right_ != nullptr) (child->right_)->parent_ = root;
        delete child;
      } else {
        tree_node *parent = root->parent_;
        if (parent != nullptr && parent->left_ == root) parent->left_ = nullptr;
        if (parent != nullptr && parent->right_ == root)
          parent->right_ = nullptr;
        if (root == head_) head_ = nullptr;
        delete root;
      }
      --size_;
    } else {
      tree_node *child = LastRightNode(root->left_);
      root->key_ = child->key_;
      RemoveNode(child, child->key_);
    }
    UpdateHeight(root);
    Balance(root);
  }

  // Получение высоты узла
  height_type GetHeight(tree_node *node) const noexcept {
    return (node == nullptr ? -1 : node->hеight_);
  }

  // Изменение высоты узла
  void UpdateHeight(tree_node *node) noexcept {
    if (node != nullptr) {
      node->hеight_ = 1 + (GetHeight(node->left_) > GetHeight(node->right_)
                               ? GetHeight(node->left_)
                               : GetHeight(node->right_));
    }
  }

  // Вычисление баланса узла
  height_type GetBalance(tree_node *node) const noexcept {
    return (node != nullptr ? GetHeight(node->right_) - GetHeight(node->left_)
                            : 0);
  }

  // Поворот направо
  void RightRotate(tree_node *node) noexcept {
    if (node->left_ != nullptr) std::swap(node->key_, (node->left_)->key_);
    tree_node *buffer = node->right_;
    node->right_ = node->left_;
    node->left_ = (node->left_ != nullptr ? (node->left_)->left_ : nullptr);
    if (node->left_ != nullptr) (node->left_)->parent_ = node;
    if (node->right_ != nullptr) {
      (node->right_)->left_ = (node->right_)->right_;
      if (buffer != nullptr) buffer->parent_ = node->right_;
      (node->right_)->right_ = buffer;
    }
    UpdateHeight(node->right_);
    UpdateHeight(node);
  }

  // Поворот налево
  void LeftRotate(tree_node *node) noexcept {
    if (node->right_ != nullptr) std::swap(node->key_, (node->right_)->key_);
    tree_node *buffer = node->left_;
    node->left_ = node->right_;
    node->right_ = (node->right_ != nullptr ? (node->right_)->right_ : nullptr);
    if (node->right_ != nullptr) (node->right_)->parent_ = node;
    if (node->left_ != nullptr) {
      (node->left_)->right_ = (node->left_)->left_;
      if (buffer != nullptr) buffer->parent_ = node->left_;
      (node->left_)->left_ = buffer;
    }
    UpdateHeight(node->left_);
    UpdateHeight(node);
  }

  // Балансирование дерева
  void Balance(tree_node *node) noexcept {
    height_type balance = GetBalance(node);
    if (balance == -2) {
      if (GetBalance(node->left_) == 1) LeftRotate(node->left_);
      RightRotate(node);
    } else if (balance == 2) {
      if (GetBalance(node->right_) == -1) RightRotate(node->right_);
      LeftRotate(node);
    }
  }

  // Класс для реализации узла АВЛ-дерева
  struct AVLTreeNode {
    // Конструктор по-умолчанию, для создания пустого узла
    AVLTreeNode()
        : parent_(nullptr),
          left_(nullptr),
          right_(nullptr),
          key_(key_type{}),
          hеight_(0) {}

    // Конструктор для создания узла со значением key
    AVLTreeNode(const key_type &key)
        : parent_(nullptr),
          left_(nullptr),
          right_(nullptr),
          key_(key),
          hеight_(0) {}

    // Конструктор для создания узла со значением key, используя move-семантику.
    AVLTreeNode(key_type &&key)
        : parent_(nullptr),
          left_(nullptr),
          right_(nullptr),
          key_(std::move(key)),
          hеight_(0) {}

    tree_node *parent_;  // указатель на родительский узел
    tree_node *left_;  // указатель на левый дочерний узел
    tree_node *right_;  // указатель на правый дочерний узел
    key_type key_;        // ключевое значение узла
    height_type hеight_;  // высота узла
  };
  // Класс обычных итераторов
  struct AVLTreeIterator {
    // дефолтный конструктор запрещен, т.к. пустой итератор не нужен
    AVLTreeIterator() = delete;

    // основной конструктор explicit, т.к. не нужны неявные преобразования
    explicit AVLTreeIterator(tree_node *node, tree_type *tree)
        : node_(node), tree_(tree) {}

    // получить ключевой элемент узла
    reference operator*() const noexcept { return node_->key_; }

    // равенство двух итераторов
    bool operator==(const iterator &other) const noexcept {
      return node_ == other.node_;
    }

    // неравенство двух итераторов
    bool operator!=(const iterator &other) const noexcept {
      return node_ != other.node_;
    }

    // префиксный переход к следующему узлу
    iterator &operator++() noexcept {
      node_ = tree_->NextNode(node_);
      return *this;
    }

    // постфиксный переход к следующему узлу
    iterator operator++(int) noexcept {
      iterator tmp{node_, tree_};
      ++(*this);
      return tmp;
    }

    // префиксный переход к предыдущему узлу
    iterator &operator--() noexcept {
      node_ = tree_->PrevNode(node_);
      return *this;
    }

    // постфиксный переход к предыдущему узлу
    iterator operator--(int) noexcept {
      iterator tmp{node_, tree_};
      --(*this);
      return tmp;
    }

    tree_node *node_;  // узел итератора
    tree_type *tree_;  // дерево итератора
  };
  // Класс константных итераторов
  struct AVLTreeIteratorConst : AVLTreeIterator {
    AVLTreeIteratorConst() = delete;

    explicit AVLTreeIteratorConst(const tree_node *node, const tree_type *tree)
        : node_(node), tree_(tree) {}

    AVLTreeIteratorConst(const iterator &other)
        : iterator(other.node_, other.tree_) {
      node_ = iterator::node_;
      tree_ = iterator::tree_;
    }

    const_reference operator*() const noexcept { return node_->key_; }

    const tree_node *node_;  // узел итератора
    const tree_type *tree_;  // дерево итератора
  };

  tree_node *head_;  // указатель на вершину дерева
  tree_node *end_;  // указатель на конец дерева (фиктивный узел)
  size_type size_;  // количество узлов в дереве
  Comparator cmp_;  // функция сравнения ключевых значений узлов
};

}  // namespace s21

#endif  // S21_CONTAINERS_1_SRC_S21_TREE_H