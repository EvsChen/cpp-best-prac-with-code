#include <unordered_map>
#include <iostream>
#include <functional>
#include <optional>
#include <vector>

template<typename Key, typename Val>
class umap {
public:
  umap() {}
  virtual void insert(const Key& key, const Val& val) = 0;
  virtual std::optional<Val> get(const Key& key) = 0;
  virtual void remove(const Key& key) = 0;
  virtual size_t bucket_count() = 0;
  size_t size() { return size_; }

protected:
  double load_factor_ = 0.5;
  size_t size_ = 0;

private:
  virtual void rehash() = 0;
};

inline bool is_prime(int n) {
  if (n % 2 == 0) {
    return false;
  }
  for (int i = 3; i * i < n; i += 2) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

template<typename Key, typename Val>
struct ChainNode {
    ChainNode() {}
    ChainNode* next = nullptr;
    Key key;
    Val val;
};

template<typename Key, typename Val>
class umap_chain : public umap<Key, Val> {  

public:
  umap_chain() : umap<Key, Val>(), nodes(5, nullptr) {}

  void insert(ChainNode<Key, Val>* new_node) {
    if (this->size_ / static_cast<double>(nodes.size()) > this->load_factor_) {
      rehash();
    }
    this->size_++;
    auto key = new_node->key;
    auto val = new_node->val;
    auto hash = std::hash<Key>()(key);
    auto idx = hash % nodes.size();
    auto node = nodes[idx];
    while (node) {
      if (node->key == key) {
        node->val = val;
        return;
      }
      if (!node->next) {
        break;
      }
      node = node->next;
    }
    if (!nodes[idx]) {
      nodes[idx] = new_node;
    }
    else {
      node->next = new_node;
    }
  };
  
  void insert(const Key& key, const Val& val) override {
    auto new_node = new ChainNode<Key, Val>();
    new_node->key = key;
    new_node->val = val;
    insert(new_node);
  };

  std::optional<Val> get(const Key& key) override {
    auto hash = std::hash<Key>()(key);
    auto idx = hash % nodes.size();
    auto node = nodes[idx];
    while (node) {
      if (node->key == key) {
        return node->val;
      }
      node = node->next;
    }
    return {};
  }

  void remove(const Key& key) override {
    auto hash = std::hash<Key>()(key);
    auto idx = hash % nodes.size();
    auto node = nodes[idx];
    ChainNode<Key, Val>* prev = nullptr;
    while (node && node->key != key) {
      prev = node;
      node = node->next;
    }
    if (node) {
      this->size_--;
      if (prev) {
        prev->next = node->next;
        delete node;
      }
      else {
        delete nodes[idx];
        nodes[idx] = nullptr;
      }
    }
  }
  
  size_t bucket_count() override {
    return nodes.size();
  }

private:
  void rehash() override {
    auto target = 2 * nodes.size() + 1;
    while (!is_prime(target)) {
      target += 2;
    }
    std::vector<ChainNode<Key, Val>*> cur = nodes;
    nodes.clear();
    nodes.resize(target);
    this->size_ = 0;
    for (auto node : cur) {
      while (node) {
        insert(node);
        node = node->next;
      }
    }
  }

  std::vector<ChainNode<Key, Val>*> nodes;
};

void cnt_test() {
  std::unordered_map<int, int> map;
  size_t s = 1e7;
  auto cnt = map.bucket_count();
  auto load_factor = map.load_factor();
  std::cout << "New bucket count " << cnt << std::endl;
  std::cout << "New max load factor " << load_factor << std::endl; 
  for (size_t i = 0; i < s; i++) {
    map[i] = rand() % s; 
    if (map.bucket_count() != cnt) {
      cnt = map.bucket_count();
      load_factor = map.load_factor();
      std::cout << "New bucket count " << cnt << " at " << i << std::endl; 
      std::cout << "New max load factor " << load_factor << std::endl; 
    }    
  }
}

int main() {
  umap_chain<int, int> my_map;
  size_t s = 1e5;
  auto cnt = my_map.bucket_count();
  std::cout << "New bucket count " << cnt << std::endl;
  for (size_t i = 0; i < s; i++) {
    int val = rand() % s;
    my_map.insert(i, val);
    if (my_map.bucket_count() != cnt) {
      cnt = my_map.bucket_count();
      std::cout << "New bucket count " << cnt << std::endl;
    }
    assert(my_map.size() == i + 1);
    assert(my_map.get(i).has_value());
    assert(my_map.get(i).value() == val);
  }
  for (size_t i = 0; i < s; i++) {
    my_map.remove(i);
    assert(!my_map.get(i).has_value());
    assert(my_map.size() == s - i - 1);
  }
  return 0;
}