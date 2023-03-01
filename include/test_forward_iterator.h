// Please see:
//  https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp
//  https://stackoverflow.com/questions/3582608/how-to-correctly-implement-custom-iterators-and-const-iterators
//
#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>

namespace forward_iterator
{

    template <typename T>
    class fixed_array
    {
    public:
        using size_type = int;
        using iterator_category = std::forward_iterator_tag;
        
        template <typename D = T>
        class iterator
        {
        public:
            iterator(D* ptr) : ptr_(ptr) { }
            iterator operator++() { iterator i = *this; ptr_++; return i; }
            iterator operator++(int junk) { ptr_++; return *this; }
            D& operator*() { return *ptr_; }
            D* operator->() { return ptr_; }
            bool operator==(const iterator& rhs) { return ptr_ == rhs.ptr_; }
            bool operator!=(const iterator& rhs) { return ptr_ != rhs.ptr_; }

        private:
            D* ptr_;
        };

        using const_iterator = iterator<const T>;

        fixed_array(size_type size) : size_(size) {
            data_ = new T[size_];
        }

        size_type size() const { return size_; }

        T& operator[](size_type index)
        {
            assert(index < size_);
            return data_[index];
        }

        const T& operator[](size_type index) const
        {
            assert(index < size_);
            return const_cast<const T&>(data_[index]);
        }

        iterator<> begin()
        {
            return iterator(data_);
        }

        iterator<> end()
        {
            return iterator(data_ + size_);
        }

        const_iterator cbegin() const
        {
            return const_iterator(data_);
        }

        const_iterator cend() const
        {
            return const_iterator(data_ + size_);
        }

    private:
        T* data_;
        size_type size_;
    };


    int test_it()
    {
        fixed_array<double> point3d(3);
        point3d[0] = 2.3;
        point3d[1] = 3.2;
        point3d[2] = 4.2;

        for (fixed_array<double>::const_iterator i = point3d.cbegin(); i != point3d.cend(); i++)
        {
            std::cout << *i << " ";
        }
        std::cout << std::endl;

        for (auto i: point3d)
            std::cout << i << " ";
        
        std::cout << std::endl;

#if(0)
        std::vector<double> vec;
        std::copy(point3d.begin(), point3d.end(), std::back_inserter(vec));

        for (std::vector<double>::iterator i = vec.begin(); i != vec.end(); i++)
        {
            std::cout << *i << " ";
        }

        std::cout << std::endl;
#endif
        return 0;
    }

}