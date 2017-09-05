#pragma once

namespace libre_ds
{
    class Node;

    template <typename T>
    class LinkedList
    {
    public:
        //////////////////////////////////////////////////////////////////////////

        class iterator
        {
            friend class LinkedList;

        public:
            inline T operator*()
            {
                return node->data;
            }

            inline iterator operator++()
            {
                node = node->next;
                return iterator(node);
            }

            inline iterator operator++(int)
            {
                iterator iter(node);
                node = node->next;
                return iter;
            }

            inline bool operator==(iterator other)
            {
                return node == other.node;
            }

            inline bool operator!=(iterator other)
            {
                return !(*this == other);
            }

        private:
            iterator(Node* n) { node = n; }

            Node* node;
        };

        //////////////////////////////////////////////////////////////////////////

        inline LinkedList()
            : mHead(nullptr), mTail(nullptr), mLength(0)
        { }

        inline ~LinkedList() { clear(); }

        //////////////////////////////////////////////////////////////////////////

        inline void add(T element)
        {
            Node* n = new Node;
            n->data = element;

            if (mLength == 0)
            {
                mHead = mTail = n;
            }
            else
            {
                mTail->next = n;
                mTail = n;
            }

            mLength++;
        }

        inline iterator begin() { return iterator(mHead); }
        inline iterator end() { return iterator(nullptr); }
        inline bool isEmpty() { return mLength == 0; }

        inline void clear()
        {
            Node* n = mHead;

            while (n != nullptr)
            {
                Node* temp = n;
                n = n->next;
                delete temp;
            }

            mHead = mTail = nullptr;
            mLength = 0;
        }

    private:
        struct Node
        {
            T data;
            Node* next = nullptr;
        };
        
        Node* mHead;
        Node* mTail;

        int mLength;
    };
}
