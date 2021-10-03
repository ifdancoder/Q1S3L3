#pragma once

#include <iostream>

class OwnContainer
{
public:
    class OwnIterator {
    private:
        int* ptr;
    public:
        OwnIterator(int* val = nullptr) {
            ptr = val;
        }
        OwnIterator& operator++();
        OwnIterator operator++(int);
        bool operator==(OwnIterator const& other) const;
        bool operator!=(OwnIterator const& other) const;
        int& operator*();
    };

    OwnContainer(std::initializer_list<int> values);

    OwnIterator begin();
    OwnIterator end();
private:
    const size_t size;
    std::unique_ptr<int[]> data;
};