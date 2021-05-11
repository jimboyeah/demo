#include <iostream>
using namespace std;

struct listNode {
    int value;
    listNode * next;

    // 链表节点默认构造函数，显式使用 nullptr 初始化空指针
    listNode(): next(nullptr) { }
    listNode(int theValue): value(theValue), next(nullptr) {
        // listNode(); 
    }

    listNode * attachNode(int value) {
        listNode *n = new listNode(value);
        n->next = this;
        return n;
    }
};

int main() {

    listNode * node = new listNode(0);

    node = node->attachNode(1)->attachNode(2)->attachNode(3)->attachNode(4);

    int indexNode = 0;
    while (node != nullptr) {
        cout << "链表节点 " << indexNode << ": " << node->value << " @" << node << endl;
        node = node->next;
        indexNode++;
    }

    return 0;
}
