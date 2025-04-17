/*#include <iostream>
#include <string>
#include <unordered_map>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    int count;

    TrieNode() : count(0) {}
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() : root(new TrieNode()) {}

    void insert(const std::string& word) {
        TrieNode* node = root;

        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];

            node->count++;
        }
    }

    int countwords(const std::string& prefics) {
        TrieNode* node = root;
        for (char ch : prefics) {
            if (node->children.find(ch) == node->children.end()) {
                return 0;
            }
            node = node->children[ch];
        }
        return node->count;
    }
};

int main() {
    Trie tree;

    tree.insert("hide");
    tree.insert("hello");
    tree.insert("apple");
    tree.insert("ihihihi");
    tree.insert("idol");

    std::cout << "words with i - " << tree.countwords("i") << std::endl;

    return 0;
}*/

/*
#include <iostream>
#include <unordered_map>

struct TrieNode {
    std::unordered_map<char, TrieNode*> children;
    bool isEnd;
    TrieNode() : isEnd(false) {}
};

class TrieTree {
private:
    TrieNode* root;

    bool findword(TrieNode* node, const std::string& word, int index) {
        if (index == word.length()) {
            if (!node->isEnd) {
                return false;
            }
            node->isEnd = false;
            return node->children.empty();
        }

        auto it = node->children.find(word[index]);

        if (it == node->children.end()) {
            return false;
        }

        bool shoulddelete = findword(it->second, word, index + 1);
        
        if (shoulddelete) {
            delete it->second;
            node->children.erase(word[index]);
            return !node->isEnd && node->children.empty();
        }
        return false;
    }

    void clear(TrieNode* node) {
        for (auto& child : node->children) {
            clear(child.second);
        }
        delete node;
    }
public:
    TrieTree() : root(new TrieNode()) {}

    ~TrieTree() {
        clear(root);
    }

    void insert(const std::string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    bool search(const std::string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            node = node->children[ch];
        }
        return node->isEnd;
    }

    void remove(const std::string& word) {
        findword(root, word, 0);
    }

};

int main() {
    TrieTree trie;

    trie.insert("lol");
    trie.insert("heh");
    trie.insert("library");
    trie.insert("idol");

    std::cout << "lol exists " << trie.search("lol") << std::endl;

    trie.remove("idol");

    std::cout << "idol exists " << trie.search("idol") << std::endl;

    return 0;
}*/
/*
#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// Структура узла дерева Хаффмана
struct Node {
    char ch;           // Символ (для листьев)
    int freq;          // Частота
    Node* left, * right; // Дочерние узлы
    Node(char c, int f, Node* l = nullptr, Node* r = nullptr)
        : ch(c), freq(f), left(l), right(r) {
    }
};

// Компаратор для min-heap
struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq; // Меньшая частота — выше приоритет
    }
};

class Huffman {
private:
    Node* root; // Корень дерева Хаффмана
    unordered_map<char, string> codes; // Таблица кодов Хаффмана

    // Освобождение памяти для дерева
    void deleteTree(Node* node) {
        if (!node) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

    // Генерация кодов Хаффмана
    void generateCodes(Node* node, string code, unordered_map<char, string>& codes) {
        if (!node) return;
        if (!node->left && !node->right) {
            codes[node->ch] = code.empty() ? "0" : code; // Для одного символа код "0"
        }
        generateCodes(node->left, code + "0", codes);
        generateCodes(node->right, code + "1", codes);
    }

public:
    Huffman() : root(nullptr) {}

    ~Huffman() {
        deleteTree(root);
    }

    // б) Построение списка частот символов
    unordered_map<char, int> buildFrequencyList(const string& text) {
        unordered_map<char, int> freq;
        for (char ch : text) {
            freq[ch]++;
        }
        return freq;
    }

    // а) Построение дерева Хаффмана
    void buildHuffmanTree(const unordered_map<char, int>& freq) {
        // Создаём min-heap
        priority_queue<Node*, vector<Node*>, Compare> minHeap;

        // Добавляем узлы для каждого символа
        for (const auto& pair : freq) {
            minHeap.push(new Node(pair.first, pair.second));
        }

        // Строим дерево
        while (minHeap.size() > 1) {
            Node* left = minHeap.top(); minHeap.pop();
            Node* right = minHeap.top(); minHeap.pop();
            Node* parent = new Node('$', left->freq + right->freq, left, right);
            minHeap.push(parent);
        }

        // Сохраняем корень
        root = minHeap.empty() ? nullptr : minHeap.top();

        // Генерируем коды
        if (root) {
            generateCodes(root, "", codes);
        }
    }

    // в) Шифрование (сжатие)
    string compress(const string& text) {
        string compressed;
        for (char ch : text) {
            compressed += codes[ch];
        }
        return compressed;
    }

    // г) Дешифрование
    string decompress(const string& compressed) {
        string decompressed;
        Node* current = root;

        for (char bit : compressed) {
            if (bit == '0') {
                current = current->left;
            }
            else if (bit == '1') {
                current = current->right;
            }

            // Если достигнут лист
            if (current && !current->left && !current->right) {
                decompressed += current->ch;
                current = root; // Возвращаемся к корню
            }
        }

        return decompressed;
    }

    // д) Подсчёт коэффициента сжатия
    double compressionRatio(const string& original, const string& compressed) {
        // Размер исходного текста в битах (8 бит на символ)
        double originalBits = original.length() * 8;
        // Размер сжатого текста в битах (1 бит на символ в compressed)
        double compressedBits = compressed.length();

        if (compressedBits == 0) return 0.0; // Избегаем деления на 0
        return originalBits / compressedBits;
    }

    // Для отладки: вывод кодов
    void printCodes() {
        for (const auto& pair : codes) {
            cout << "'" << pair.first << "': " << pair.second << endl;
        }
    }
};

// Пример использования
int main() {
    Huffman huffman;

    // Пример текста
    string text = "hello world";

    // б) Построение списка частот
    auto freq = huffman.buildFrequencyList(text);
    cout << "Frequency list:" << endl;
    for (const auto& pair : freq) {
        cout << "'" << pair.first << "': " << pair.second << endl;
    }

    // а) Построение дерева Хаффмана
    huffman.buildHuffmanTree(freq);
    cout << "\nHuffman Codes:" << endl;
    huffman.printCodes();

    // в) Сжатие
    string compressed = huffman.compress(text);
    cout << "\nCompressed: " << compressed << endl;

    // г) Дешифрование
    string decompressed = huffman.decompress(compressed);
    cout << "Decompressed: " << decompressed << endl;

    // д) Коэффициент сжатия
    double ratio = huffman.compressionRatio(text, compressed);
    cout << "Compression ratio: " << ratio << endl;

    return 0;
}*/

#include <iostream>
#include <vector>
#include <algorithm>

struct Task {
    int start, end, index;
};

std::vector<int> selectTask(std::vector<Task>& tasks) {
    std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {return a.end < b.end; });

    std::vector<int> selected;
    int last_end = -1;

    for (const Task& task : tasks) {
        if (task.start >= last_end) {
            selected.push_back(task.index);
            last_end = task.end;
        }
    }
    return selected;
}

int main() {
    int n;
    std::cout << "enter the number of tasks ";
    std::cin >> n;

    std::vector<Task> tasks(n);
    std::cout << "enter the start and the end of tasks " << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> tasks[i].start >> tasks[i].end;
        tasks[i].index = i + 1;
    }

    std::vector<int> selected = selectTask(tasks);

    std::cout << "max number of tasks " << selected.size() << std::endl;
    std::cout << "indexes of tasks: " << std::endl;
    for (const int index : selected) {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    std::cout << "intervals of tasks: " << std::endl;
    for (const int index : selected) {
        int i = index - 1;
        std::cout << "task " << index << ":[ " << tasks[i].start << ", " << tasks[i].end << " ]\n";
    }
    
    return 0;
}
