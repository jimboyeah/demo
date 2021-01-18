#include <iostream>
using namespace std;

struct listNode {
    int value;
    listNode * next;

    listNode(): next(nullptr) {} // 链表节点默认构造函数
    listNode(int theValue): value(theValue), next(nullptr) {
        // listNode();
    }

    listNode * addNode(int value) {
        listNode *n = new listNode(value);
        n->next = this;
        return n;
    }
};

int main() {

    listNode * node = new listNode(0);

    node = node->addNode(1)->addNode(2)->addNode(3)->addNode(4);

    int indexNode = 0;
    while (node != nullptr) {
        cout << "链表节点 " << indexNode << ": " << node->value << " @" << node << endl;
        node = node->next;
        indexNode++;
    }

    return 0;
}

/*
struct listNode{
    int value;
    listNode *next;
    
    listNode():next(nullptr){}//默认构造函数
    listNode(int theValue):value(theValue),next(nullptr){}//带参构造函数
};
  
int main() 
{ 

    listNode *head = NULL, *node = NULL, *pListEnd = NULL;
    
    node = new listNode(1);
    head = node;//链表头指针
    pListEnd = node;//链表尾指针
    
    node = new listNode(2);
    pListEnd->next = node;//链表的尾节点的next指针指向新的node
    pListEnd = pListEnd->next;//链表的尾节点指针后移到新的尾节点

    node = new listNode(3);
    pListEnd->next = node;//链表的尾节点的next指针指向新的node
    pListEnd = pListEnd->next;//链表的尾节点指针后移到新的尾节点
    
    listNode *pNode = head;
    int indexNode = 0;
    while(pNode != nullptr){
        cout<< "链表节点 "<< indexNode << "的值: "<<pNode->value << " @" << pNode <<endl; 
        pNode = pNode->next;
        indexNode++;
    }
    
    return 0; 
}
*/