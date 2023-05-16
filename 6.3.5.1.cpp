#include <iostream>

class Tree {
public:
    virtual void draw() const = 0;
};

class Tree1 : public Tree {
public:
    void draw() const override {
        std::cout << "Drawing 1:\n";
        std::cout << "/\\\n";
        std::cout << "//\\\\\n";
    }
};

class Tree2 : public Tree {
public:
    void draw() const override {
        std::cout << "Drawing 2:\n";
        std::cout << "/\\\n";
        std::cout << "/**\\\n";
    }
};

class Tree3 : public Tree {
public:
    void draw() const override {
        std::cout << "Drawing 3:\n";
        std::cout << "/\\\n";
        std::cout << "/++\\\n";
    }
};

int main() {
    Tree* treeTable[3];

    Tree1 tree1;
    Tree2 tree2;
    Tree3 tree3;

    treeTable[0] = &tree1;
    treeTable[1] = &tree2;
    treeTable[2] = &tree3;

    for (int i = 0; i < 3; i++) {
        treeTable[i]->draw();
    }

    return 0;
}
