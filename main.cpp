#include <iostream>
#include<cstdio>
#include<cstdlib>

/**
* Author: Scott Gramig
* Referenced: Ali Nawkhas Murad
* Program: Doubly LinkedList implementation
**/

using namespace std;


/**
* @struct: object struct for each Node
* @vars: data, next, pre
**/
struct Node
{
    double data;
    Node *next, *pre;                    //pointers for nodes previous Node and next Node
    Node(double y)                      //constructor that accepts a double and initializes a Nodes previous and next
    {
        data = y;
        next = pre = NULL;               // initialize next and previous to NULL
    }
};

/**
* @class: doubly linked list data structure
* @vars: head, tail
* @methods: doublyLinkedList(), appendNodehead(double), appendNodetail(double),
*           dispNodesForward(), displayNodesReverse(), removeNode(double)
**/
class doublyLinkedList
{
    Node *head;                                  // head and tail pointers
    Node *tail;

    public:
        doublyLinkedList()
        {
            head = NULL;                         // initiate the head and tail to NULL because the LinkedList is empty right now
            tail = NULL;
        }
        void appendNodehead(double x);          // add node to head of linked list
        void appendNodetail(double x);          // add node to tail of linked list
        void dispNodesForward();                 // display nodes in forward order
        void dispNodeReverse();                  // display nodes in reverse order
        void removeNode(double x);              // if a node is == x then remove and fix pointers
};

/**
* appends a new node to the front of the LinkedList
**/
void doublyLinkedList::appendNodehead(double x)
{
    Node *n = new Node(x);                       // calls the Node constructor and creates a new Node
    if(head == NULL)                             // if no Nodes are in the LinkedList
    {
        head = n;                                 // set the head and tail to the brand new first Node
        tail = n;                                 // because that Node alone is the beginning and the ending Node in the LinkedList
    }else
    {
        head->pre = n;                            // if a Node already exists we set the head Nodes previous Node pointer to the new Node n
        n->next = head;                           // then set the new Nodes next pointer to the hold ead Node
        head = n;                                 // now make the new Node the head of the LinkedList
    }
}

/**
* appends a new node to the end of the LinkedList
**/
void doublyLinkedList::appendNodetail(double x)
{
    Node *n = new Node(x);                        // calls the Node constructor and creates a new Node
    if(tail == NULL)                              // if no Nodes are in the LinkedList yet
    {
        head = n;                                  // set the head and the tail of the new first Node
        tail = n;
    }else
    {
        tail->next = n;                            // if a Node already exists we set the tail Nodes next pointer to the new Node n
        n->pre = tail;                             // the set the new Nodes previous pointer to the old tail
        tail = n;                                  // now make the new Node the tail of the LinkedList
    }
}

/**
* Prints all Nodes forwardly
**/
void doublyLinkedList::dispNodesForward()
{
    Node *temp = head;                              // create temporary Node to start at the head of the list
    cout << "\n\nNodes in forward order: " << endl;
    while(temp != NULL)                            // while there are Nodes in the LinkedList continue
    {
        cout << temp->data << " ";                  // print data from Node
        temp = temp->next;                          // set temp to the next Node in list
    }
}

/**
* Prints all Nodes reversely
**/
void doublyLinkedList::dispNodeReverse()
{
    Node *temp = tail;                              // same as printing forward method but starting at the tail
    cout << "\n\nNodes in reverse order: " << endl;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->pre;                           // then we keep setting temp to the previous Node while there are Nodes in list
    }
}

/**
* Removes a Node with value x and links the list back together
**/
void doublyLinkedList::removeNode(double x)
{
    Node *tempPre = NULL, *tempDel = NULL, *tempNext = NULL;

    // check if it is head node
    if(head->data == x)
    {
        tempDel = head;                         //point to node to be deleted
        head = tempDel->next;                   //update fron with the next node in list
        delete tempDel;                        //get rid of the trash
        return;
    }

    tempPre = head;                             //set temp to head
    tempDel = head->next;                       //set node to delete to node next to head for traversal through list until node->data == x

    while(tempDel != NULL)                      //while tempDel != NULL which means traverse until the end of the linked list
    {
        if(tempDel->data == x)                  //if the node in list == x, the value to be removed
        {
            tempPre->next = tempDel->next;      //set previous next pointer to point to the (removing nodes next pointer
            tempNext = tempDel->next;
            tempNext->pre = tempDel->pre;       //set the node next to the removing nodes previous pointer to the removing nodes previous pointer

            if(tempDel == tail)
                tail = tempPre;

            delete tempDel;                    //clean up memory
            break;
        }
        tempPre = tempDel;                      // these two lines traverse
        tempDel = tempDel->next;                // the linked list
    }
}



int main()
{
    // create list object
    doublyLinkedList *list = new doublyLinkedList();

    //append nodes to tail of list
    for(int i = 1; i < 7; i++)
        list->appendNodetail(i*1);

    // display nodes forward and reverse order
    list->dispNodesForward();
    list->dispNodeReverse();

    //remove a node with a certain value
    cout << "\n\nRemove 2 from list..." << endl;
    list->removeNode(2);
    list->dispNodesForward();
    list->dispNodeReverse();

    return 0;
}
