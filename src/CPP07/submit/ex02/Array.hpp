#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "cstddef"
#include <iostream>
#include <stdexcept>

template <typename T> class Array
{
    private:
        T *_array;
        unsigned int _size;

    public:
        Array()
            : _array(new T[0]())
            , _size(0)
        {}

        Array(const Array<T> &other)
        {
            _array = NULL;
            _size = 0;
            *this = other;
        }

        Array(unsigned int n)
            : _array(new T[n]())
            , _size(n)
        {}

        virtual ~Array()
        {
            delete[] _array;
        }

        Array<T> &operator=(const Array<T> &rhs)
        {
            if (this != &rhs)
            {
                delete[] this->_array;
                this->_size = rhs._size;
                this->_array = new T[rhs._size];
                for (unsigned int i = 0; i < _size; i++)
                    this->_array[i] = rhs._array[i];
            }
            return *this;
        }

        T &operator[](int index)
        {
            if (index < 0 || (unsigned int)index >= _size)
                throw std::exception();
            return _array[index];
        }

        const T &operator[](int index) const
        {
            if (index < 0 || (unsigned int)index >= _size)
                throw std::exception();
            return _array[index];
        }

        const unsigned int &size(void) const
        {
            return _size;
        }
};

#endif // ARRAY_HPP
