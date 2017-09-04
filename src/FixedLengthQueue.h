#pragma once

#include <stdexcept>
/*#include <iostream>*/

namespace libre_ds
{
    template <typename T>
    class FixedLengthQueue
    {
    public:

        //////////////////////////////////////////////////////////////////////////

        inline FixedLengthQueue(int capacity)
            : mHead(0), mTail(0), mLength(0), mCapacity(capacity)
        {
            data = new T[mCapacity];
        }

        inline ~FixedLengthQueue()
        {
            delete[] data;
        }

        //////////////////////////////////////////////////////////////////////////

        inline void push(T element)
        {
            if (mLength != mCapacity)
            {
                data[mTail] = element;

                incrementAndWrap(mTail);
                mLength++;
            }
            else throw std::out_of_range("Attempted to push to a full FixedLengthQueue.");
        }

        inline T pop()
        {
            if (mLength != 0)
            {
                T element = data[mHead];

                incrementAndWrap(mHead);
                mLength--;

                return element;
            }
            else throw std::out_of_range("Attempted to pop from an empty FixedLengthQueue.");
        }

        inline int length() { return mLength; }
        inline int capacity() { return mCapacity; }
        inline bool isEmpty() { return mLength == 0; }
        inline bool isFull() { return mLength == mCapacity; }

        inline bool clear()
        {
            mHead = mTail = mLength = 0;
        }

        /*inline void show()
        {
            for (int i = 0; i < mCapacity; i++)
            {
                std::cout
                    << "["
                    << (i == mHead ? "H" : " ")
                    << data[i]
                    << (i == mTail ? "T" : " ")
                    << "]";
            }
            std::cout << endl;
        }*/

    private:
        int mLength, mCapacity;
        int mHead, mTail;
        T* data;

        inline void incrementAndWrap(int& x)
        {
            ++x %= mCapacity;
        }
    };
}
