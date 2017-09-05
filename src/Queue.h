#pragma once

namespace libre_ds
{
    template <typename T>
    class Queue
    {
    public:
        //////////////////////////////////////////////////////////////////////////

        inline Queue()
            : mHead(nullptr), mTail(nullptr), mLength(0)
        { }

        inline ~Queue() { clear(); }

        //////////////////////////////////////////////////////////////////////////

        inline void push(T element)
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

        inline T pop()
        {
            if (isEmpty()) throw std::out_of_range("Attempted to pop from an empty Queue.");

            T element = mHead->data;
            Node* temp = mHead;
            mHead = mHead->next;
            
            delete temp;
            mLength--;
            
            return element;
        }

        inline int length() { return mLength; }
        inline bool isEmpty() { return mLength == 0; }

        inline void clear()
        {
            for (Node* n = mHead; n != nullptr;)
            {
                Node* next = n->next;
                delete n;
                n = next;
            }

            mHead = mTail = nullptr;
            mLength = 0;
        }

    private:
        struct Node
        {
            Node* next = nullptr;
            T data;
        };

        Node* mHead;
        Node* mTail;
        int mLength;
    };
}