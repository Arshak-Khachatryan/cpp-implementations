#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST
#include <iostream>

template <typename T>
class DLList{
public:
    using val_type = T;
    using val_ref = T&;
    using ptr_val = T*;
    using const_ref_val = const T&;
    using size_type = std::size_t;
private:
    struct Node{
            Node* next;
            Node* prev;
            T val;
            Node(const_ref_val val = val_type(),Node* next = nullptr,Node* prev = nullptr):val(val),next(next),prev(prev){};
        };
public:
        //constructors
        DLList();
        DLList(size_type len);
        DLList(size_type count,const_ref_val val);
        DLList(const DLList<val_type>& rhv);
        DLList(DLList<val_type>&& rhv);
        DLList(std::initializer_list<val_type> arr);

        ~DLList();
        void clear();
        bool empty()const;

        //operators
        DLList<val_type>& operator=(const DLList<val_type>& ob);
        DLList<val_type>& operator=(DLList<val_type>&& ob);

        //aystex karox e linel dzer govazdy
        size_type _size()const;
        void push_back(const_ref_val val);
        void pop_back();
        void push_front(const_ref_val val);
        void pop_front();
        void insert(const_ref_val val,size_type pos);
        void insert(const DLList<val_type>& other,size_type pos);
        void del(size_type pos);
        bool search(const_ref_val val)const;
        void reverse(); //videon nayenq || recursion el
        
        bool hasCycle()const;
        size_type getStartPoint()const;
        void sort(); //margeov aysinq recursion
private:
    Node* getMiddleElement()const;
private:
    Node* head;
    Node* tail;
};

#endif