#include "trie.h"
#include <string>

#include <self/functional.h>

using namespace std;
using namespace util;

bool trashNode(const shared_ptr<const TrieNode> pnode) {
    return pnode->children_.size() == 0 && !pnode->is_value_node_;
}

int *get_helper(const shared_ptr<const TrieNode> pnode, const string key) {
    // print("pnode->is_value_node_ = ", pnode->is_value_node_);
    if ( key.length() == 0 ) {
        return nullptr;
    } else if ( key.length() == 1 && pnode->children_.count(key.at(0)) == 0 ) {
        return nullptr;
    } else if ( key.length() == 1 && pnode->children_.count(key.at(0)) != 0 ) {
        const auto ptr = pnode->children_.find(key.at(0));
        const auto with_val_ptr = dynamic_cast<const TrieNodeWithValue *>(ptr->second.get());
        if ( with_val_ptr )
            return with_val_ptr->value_.get();
    } else if ( pnode->children_.count(key.at(0)) != 0 ) {
        auto it = pnode->children_.find(key.at(0));
        return get_helper(it->second, key.substr(1));
    }
    return nullptr;
}

const int *Trie::Get(std::string key) const {
    // 你需要在字典树中寻找对应了键，如果不存在则返回 nullptr
    // 如果你找到了对应节点，你可以使用 `dynamic_cast` 尝试将其转化为 `const
    // TrieNodeWithValue *`. 如果转化不成功，则其不存在值，返回
    // nullptr。否则可以通过转化后的指针访问 value.
    if ( this->GetRoot() == nullptr )
        return nullptr;
    return get_helper(this->GetRoot(), key);
}


shared_ptr<const TrieNode> put_helper(const shared_ptr<const TrieNode> pnode, const string key, int value) {
    // print("key = ", key, "value = ", value);
    // auto node_ptr = (pnode->is_value_node_) ? dynamic_cast<const TrieNodeWithValue *>(pnode.get())->Clone() : pnode->Clone();
    auto node_ptr = pnode->Clone();
    // print("children.size() = ", node_ptr->children_.size());
    if ( key.length() == 1 ) {
        auto node_with_val = TrieNodeWithValue(make_shared<int>(value));
        if ( node_ptr->children_.count(key.at(0)) != 0 ) {
            auto old_children = node_ptr->children_[key.at(0)]->children_;
            node_with_val = TrieNodeWithValue(old_children, make_shared<int>(value));
        }
        node_with_val.is_value_node_ = true;
        node_ptr->children_[key.at(0)] = make_shared<const TrieNodeWithValue>(node_with_val);
        return node_ptr;
    } else if ( node_ptr->children_.count(key.at(0)) == 0 ) {
        auto subnode_ptr = make_shared<const TrieNode>(TrieNode(map<char, shared_ptr<const TrieNode>>()));
        node_ptr->children_[key.at(0)] = put_helper(subnode_ptr, key.substr(1), value);
        return node_ptr;
    } else if ( !(node_ptr->children_[key.at(0)]->is_value_node_) ) {
        auto subnode_ptr = make_shared<const TrieNode>(TrieNode(node_ptr->children_[key.at(0)]->children_));
        node_ptr->children_[key.at(0)] = put_helper(subnode_ptr, key.substr(1), value);
        return node_ptr;
    }

    auto subnode_ptr = make_shared<const TrieNodeWithValue>(
            TrieNodeWithValue(node_ptr->children_[key.at(0)]->children_,
            make_shared<int>(
                *(dynamic_cast<const TrieNodeWithValue *>(
                        node_ptr->children_[key.at(0)].get())->value_))));
    node_ptr->children_[key.at(0)] = put_helper(subnode_ptr, key.substr(1), value);
    return node_ptr;
}

Trie Trie::Put(std::string key, int value) const {
    // 如果对应 key 的节点已经存在，你需要新建（复制）节点
    // 你可以使用 make_shared<int> 来创建一个 value 对应的智能指针
    if ( this->GetRoot() == nullptr ) {
        // print("in put");
        return Trie(put_helper(make_shared<const TrieNode>(TrieNode()), key, value));
    }
    else
        return Trie(put_helper(this->GetRoot(), key, value));
}

shared_ptr<const TrieNode> remove_helper(const shared_ptr<const TrieNode> pnode, const string key) {
    auto node_ptr = pnode->Clone();
    if ( key.length() == 1 ) {
        auto it = node_ptr->children_.find(key.at(0));
        if ( nullptr == it->second ) {
            node_ptr->children_.erase(it);
            return node_ptr;
        } else if ( it->second->children_.size() == 0 ) {
            node_ptr->children_.erase(it);
            return node_ptr;
        }
        auto old_children = it->second->children_;
        auto new_node = TrieNode(old_children);
        node_ptr->children_[key.at(0)] = make_shared<const TrieNode>(new_node);
        return node_ptr;
    } else {
        auto new_chilren = pnode->children_;
        new_chilren[key.at(0)] = remove_helper(new_chilren[key.at(0)], key.substr(1));
        if ( trashNode(new_chilren[key.at(0)]) ) {
            new_chilren.erase(new_chilren.find(key.at(0)));
        }
        node_ptr->children_ = new_chilren;
        return node_ptr;
    }
}

Trie Trie::Remove(std::string key) const {
    // 遍历节点并删除键对应的值
    // 删除值后你需要将节点转化为 `TrieNode`
    // 请删除既没有子节点也没有值的 TrieNode
    if ( this->Get(key) == nullptr ) {
        return Trie(this->root_);
    }
    auto root = remove_helper(this->GetRoot(), key);
    if ( trashNode(root) )
        return Trie(nullptr);
    return Trie(root);
}

void print_node(const shared_ptr<const TrieNode> tree, int level = 0) {
    // print("is_value_node_  = ", (tree.get()) ? tree->is_value_node_ : -1, "size = ", tree->children_.size());
    for ( auto &it : tree->children_ )
    {
        for ( int i = 0; i < level * 4; i += 1 )
            std::cout << ' ';
        if ( it.second->is_value_node_ )
            util::print(it.first, *(dynamic_cast<const TrieNodeWithValue *>(it.second.get())->value_));
        else
            util::print(it.first);
        print_node(it.second, level + 1);
    }
}

void BasicRemoveTest1() {
    auto trie = Trie();
    // Put something
    trie = trie.Put("te", 23);
    trie = trie.Put("test", 2333);
    trie = trie.Remove("test");
    trie = trie.Remove("te");
    trie = trie.Put("te", 123);
    trie = trie.Put("tet", 1);
    trie = trie.Put("tea", 2);
    trie = trie.Put("teb", 3);
    trie = trie.Put("tec", 4);
    print_node(trie.GetRoot());
}

// int main(const int arg_number, const char **arg_value) {
    // util::print(sizeof(TrieNode));
    // util::print(sizeof(TrieNodeWithValue));
    // BasicRemoveTest1();
    // return 0;
// }
