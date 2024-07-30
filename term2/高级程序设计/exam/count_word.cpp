# include <string>
# include <fstream>

# include "exam11.cpp"
# include <self/functional.h>

using namespace fp;
using namespace std;
using namespace util;

List<string> split_helper(string content, string so_far, List<string> result, auto splitter) {
    if ( content.length() == 0 ) {
        if ( so_far != "" )
            result.append(so_far);
        return result;
    }
    else if ( splitter(content.substr(0, 1)) ) {
        result.append(content.substr(0, 1));
        if ( so_far != "" ) {
            result.append(so_far);
        }
        return split_helper(content.substr(1), "", result, splitter);
    }
    else
        return split_helper(content.substr(1), so_far + content.substr(0, 1), result, splitter);
}

List<string> split_by(string content, auto splitter) {
    return split_helper(content, "", List<string>(), splitter);
}

string readfile(string filepath) {
    string content = "", line = "";
    ifstream file(filepath);
    while ( getline(file, line) )
        content = content + line + "\n";
    int a = 1, b = 1;
    return content;
}

int get_val(Trie some, string key) {
    const int *res = nullptr;
    if ( res = some.Get(key) )
        return *res;
    return -1;
}

void print_dict(const shared_ptr<const TrieNode> tree, int level = 0, string so_far = "") {
    for ( auto &it : tree->children_ )
    {
        if ( it.second->is_value_node_ ) {
            print("level = ", level, "key :", so_far + it.first, "val :", *(dynamic_cast<const TrieNodeWithValue *>(it.second.get())->value_));
        } else {
            print_dict(it.second, level + 1, so_far + it.first);
        }
    }
}


int main(const int arg_number, const char **arg_value) {
    string content = readfile(arg_value[1]);
    auto tokens = split_by(content, [=] (auto x) {
            return x == "\n"
            || x == " "
            || x == "<"
            || x == ">"
            || x == "("
            || x == ")"
            || x == "{"
            || x == "}"
            || x == "["
            || x == "]"
            || x == "'"
            || x == "'"
            || x == "\""
            || x == ","
            || x == ":"
            || x == "."
            || x == "!"
            || x == "#"
            || x == "$"
            || x == "="
            || x == ";";
        });
    auto trie = Trie();
    print(tokens.count([=] (string x) {return x == ")";}));
    for ( const auto &it : tokens )
    {
        // print(it);
        if ( trie.Get(it) ) {
            trie = trie.Put(it, get_val(trie, it) + 1);
            // print(*trie.Get(it));
        } else {
            trie = trie.Put(it, 1);
        }
    }
    print_dict(trie.GetRoot());
    // print_node(trie.GetRoot());
}
