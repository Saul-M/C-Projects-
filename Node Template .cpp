#include <iostream> 
#include <string>
#include<vector>
using namespace std;

template<class type>
class Node {
private:
    type item;
    Node<type>* nextPtr;

public:
    //constructors
    Node();
    Node(type item);
    //in the book they were putting '&" right afte type and so thats what i didnt i know it means like the 
    //refernce of the address but like in terms if what its actually doing i dont know
    //i Know this is super late but i was wondering if you could helpe me 
    Node(type&, Node<type>*);

    //Accessor Methods
    void setItem(type&);
    type getItem();
    void setNextPtr(Node<type>*);
    Node<type>* getNextPtr();
    
};

template<class type>
void printLists(Node<type>* headPtr);
template<class type>
void popList(Node<type>* headPtr);
template<class type>
void deleteListItem(Node<type>* headPtr, Node<type>* curPtr);
template<class type>
void insertListItem(Node<type>* curNodePtr, Node<type>* newNodePtr);

int main(void) {


    Node<string>* headPtr = nullptr;
    //Node myNode;

    Node<string>* curNodePtr = nullptr;

    curNodePtr = new Node<string>("bill");
    headPtr = curNodePtr;

    curNodePtr->setNextPtr(new Node<string>("James"));
    curNodePtr = curNodePtr->getNextPtr();

    curNodePtr->setNextPtr(new Node<string>("Aubrey"));
    curNodePtr = curNodePtr->getNextPtr();

    curNodePtr->setNextPtr(new Node<string>("jorge"));
    curNodePtr = curNodePtr->getNextPtr();

    curNodePtr->setNextPtr(new Node<string>("saul"));
    curNodePtr = curNodePtr->getNextPtr();

    curNodePtr->setNextPtr(new Node<string>("henry"));
    curNodePtr = curNodePtr->getNextPtr();

    curNodePtr->setNextPtr(new Node<string>("paul"));
    curNodePtr = curNodePtr->getNextPtr();

    cout << "This is the starting link list" << endl;
    printLists(headPtr);
    cout << "This is the link list after a item is deleted" << endl;
    Node<string>* positionNode = headPtr->getNextPtr();
    deleteListItem(headPtr, positionNode);
    printLists(headPtr);
    cout << "This is the link list after the item is popped off" << endl;
    popList(headPtr);
    printLists(headPtr);
    cout << "This is the link list after a item is inserted" << endl;
    Node<string>* newNodeptr = new Node<string>("apple");
    insertListItem(positionNode, newNodeptr);
    printLists(headPtr);



    while (headPtr != nullptr) {
        curNodePtr = headPtr;
        headPtr = headPtr->getNextPtr();
        delete curNodePtr;

    }


    curNodePtr = headPtr; //both should be nullptr at the end

   // printLists(headPtr);

    return (0);
}
template<class type>
void printLists(Node<type>* beginningNodePtr) {

    Node<type>* tempNodePtr = beginningNodePtr;

    cout << "******************" << endl;
    if (tempNodePtr == nullptr) {
        cout << "List Empty" << endl;
    }
    else {
        while (tempNodePtr->getNextPtr() != nullptr) {

            cout << tempNodePtr->getItem() << endl;
            tempNodePtr = tempNodePtr->getNextPtr();

        };
        cout << tempNodePtr->getItem() << endl;

    }
    cout << "******************" << endl;

}
template<class type>
void popList(Node<type>* headPtr)
{
    Node<type>* currNode = headPtr;

    while (currNode->getNextPtr()->getNextPtr() != nullptr)
        currNode = currNode->getNextPtr()->getNextPtr();

    delete currNode->getNextPtr();
    currNode->setNextPtr(nullptr);


}
template<class type>
void deleteListItem(Node<type>* headPtr, Node<type>* curPtr)
{
    Node<type>* prevNode = headPtr;

    while (prevNode->getNextPtr() != nullptr && prevNode->getNextPtr() != curPtr)
        prevNode = prevNode->getNextPtr();

    if (prevNode->getNextPtr() == nullptr) {
        cout << "The node doesnt exist" << endl;
    }


    prevNode->setNextPtr(prevNode->getNextPtr()->getNextPtr());


    delete curPtr;
    return;

}
template<class type>
void insertListItem(Node<type>* curNodePtr, Node<type>* newNodePtr) {
    newNodePtr->setNextPtr(curNodePtr->getNextPtr());
    curNodePtr->setNextPtr(newNodePtr);
}


template<class type>
Node<type>::Node()
{
    setItem(""); //default to empty string
    setNextPtr(nullptr); //default to null pointer
}
template<class type>
Node<type>::Node(type arg)
{
    setItem(arg);
    setNextPtr(nullptr);
}
template<class type>
Node<type>::Node(type& arg, Node<type>* argPtr)
{
    setItem(arg);
    setNextPtr(argPtr);
}

template<class type>
void Node<type>::setItem(type& arg)
{
    item = arg;
}

template<class type>
type Node<type>::getItem()
{
    return item;
}
template<class type>
void Node<type>::setNextPtr(Node<type>* argPtr)
{
    nextPtr = argPtr;
}

template<class type>
Node<type>* Node<type>::getNextPtr()
{
    return nextPtr;
}