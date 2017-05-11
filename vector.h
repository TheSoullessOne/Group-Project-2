#ifndef VECTOR_H
#define VECTOR_H

template <class T>
class vector
{
    int size_v;
    T*  elem;
    int space;      // size+free_space

public:
    vector()
    {
        size_v = 0;
        elem = nullptr;
        space = 0;
    }

    explicit vector(int yup)
        :   size_v{yup}, elem{new double[yup]}, space{yup}
    {
        for (int i = 0; i < size_v; ++i)    {
            elem[i] = 0;
        }

    }

    // copy constructor
    vector(const vector& other)
        :   size_v{other.size_v}, elem{new double[other.size_v]}, space{other.size_v}
    {
        copy(other.elem, other.elem + size_v, elem);
    }

    // copy assignment
    vector& operator=(const vector& other)
    {
        double* temp = new double[other.size_v];
        copy(other.elem, other.elem + size_v, elem);
        delete[] elem;
        elem = temp;
        size_v = other.size_v;
        return *this;
    }

    // move constructor
    vector(const vector&& other)
    {
        this->size_v = other.size_v;
        this->elem   = other.elem;
        this->space  = other.space;
        other.size_v = 0;
        delete elem;
        other.space = 0;
    }

    // move assignment
    vector& operator=(const vector&& other)
    {

    }

    // destructor
    ~vector()
    {
        delete[] elem;
    }

    // access: return reference
    T& operator[] (int n)
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

    // current available space
    int capacity() const
    {
        return space;
    }

    // grow
    void resize(int newSize)
    {
        reserve(newSize);
        for(int i =0; i < newSize; ++i) {
            elem[i] = 0;
        }
        size_v = newSize;
    }

    // add element
    void push_back(double d)
    {
        // start with 5 elements
        if(space == 0)  {
            reserve(5);
        }
        else if(size_v == space)
        {
            reserve(2 * space);
        }
        elem[size_v] = d;
        ++size_v;
    }

    // get more space
    void reserve(int newAlloc)
    {
        if(newAlloc <= space)   {
            return;
        }
        double* temp = new double[newAlloc];
        for(int i = 0; i < size_v; ++i) {
            temp[i] = elem[i];
        }
        delete[] elem;
        elem = temp;
        space = newAlloc;
    }

    using iterator = T*;
    using const_iterator = T*;

    // points to first element
    iterator begin()
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

    // points to one beyond the last element
    iterator end()
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

    // insert a new element v before p
    iterator insert(iterator p, const T& v)
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

    // remove element pointed to by p
    iterator erase(iterator p)
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
};

#endif // VECTOR_H
