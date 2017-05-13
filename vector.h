#ifndef VECTOR_H
#define VECTOR_H
#include <algorithm>
#include <Qdebug>
#include <QObject>

template <class T>
class vector
{

    int size_v;
    T* elem;
    int space;      // size+free_space

public:
    vector() : size_v{0}, space{0}
    {
//        size_v = 0;
        elem = new T[0];
//        space = 0;
    }
    explicit vector(int yup)
        :   size_v{yup}, elem{new T[yup]}, space{yup}
    {
        for (int i = 0; i < size_v; ++i)    {
            elem[i] = 0;
        }

    }
    vector(const vector& other)                   // copy constructor
        :   size_v{other.size_v}, elem{new T[other.size_v]}, space{other.size_v}
    {
        std::copy(other.elem, other.elem + size_v, elem);
    }
    vector& operator=(const vector& other)		// copy assignment
    {
        T* temp = new T[other.size_v];
        std::copy(other.elem, other.elem + size_v, elem);
        delete[] elem;
        elem = temp;
        size_v = other.size_v;
        return *this;
    }
    vector(const vector&& other)				// move constructor
    {
        this->size_v = other.size_v;
        this->elem   = other.elem;
        this->space  = other.space;
        other.size_v = 0;
        delete elem;
        other.space = 0;
    }
    vector& operator=(const vector&& other)	// move assignment
    {
        delete[] this->elem;
        this->size_v = 0;
        this->space = 0;
        T* temp = new T[other.size_v];
        std::copy(other.elem, other.elem + size_v, elem);
        delete[] elem;
        elem = temp;
        size_v = other.size_v;
        return *this;
    }
    ~vector()						// destructor
    {
        delete[] elem;
    }

    T& operator[] (int n)				// access: return reference
    {
        return elem[n];
    }
//    const T& operator[] (int n)			// access: return reference
//    {
//        return elem[n];
//    }
    int size() const					// the current size
    {
        return size_v;
    }
    int capacity() const				// current available space
    {
        return space;
    }
    void resize(int newSize)			// grow
    {
        reserve(newSize);
        for(int i = 0; i < newSize; ++i) {
            elem[i] = 0;
        }
        size_v = newSize;
    }
    void push_back(T d)			// add element
    {
        if (space == 0){
            reserve(8);					// start with space for 8 elements
        }
        else if (size_v == space)
        {
            reserve(2*space);	// get more space
        }
        elem[size_v] = d;							// add d at end
        ++size_v;
    }
    void reserve(int newAlloc)			// get more space
    {
        if(newAlloc <= space)   {
            return;
        }
        T* temp = new T[newAlloc];
        for(int i = 0; i < size_v; ++i) {
            temp[i] = elem[i];
        }
        delete[] elem;
        elem = temp;
        space = newAlloc;
    }
    using iterator = T*;
    using const_iterator = T*;
    iterator begin()			// points to first element
    {
        if(size_v == 0) {
            return nullptr;
        }
        return &elem[0];
    }
    const_iterator begin() const
    {
        if(size_v == 0) {
            return nullptr;
        }
        return &elem[0];
    }
    iterator end()			// points to one beyond the last element
    {
        if(size_v == 0) {
            return nullptr;
        }
        return &elem[size_v];
    }
    const_iterator end() const
    {
        if(size_v == 0) {
            return nullptr;
        }
        return &elem[size_v];
    }
    iterator insert(iterator p, const T& v)// insert a new element v before p
    {
        int index = p - begin();
        if(size() == capacity())    {
            reserve(size() == 0 ? 8 : 2 * size());
        }
        ++size_v;
        iterator temp = begin() + index;
        for(iterator pos = end() - 1; pos != temp; --pos)   {
            *pos = *(pos - 1);
        }
        *(begin() + index) = v;
        return temp;
    }
    iterator erase(iterator p)		  // remove element pointed to by p
    {
        if(p == end())  {
            return p;
        }
        for(iterator pos = p + 1; pos != end(); ++pos)  {
            *(pos - 1) = *pos;
        }
        delete (end() - 1);
        --size_v;
        return p;
    }
    void clear()
    {
        for(int i = 0; i < this->size(); ++i)
        {
            elem[i] = nullptr;
        }
        resize(0);
    }
};

#endif // VECTOR_H
