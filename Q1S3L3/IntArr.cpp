#include "IntArr.h"

OwnContainer::OwnContainer(std::initializer_list<int> values) : size(values.size()), data(new int[size]) {
    std::copy(values.begin(), values.end(), data.get());
}

OwnContainer::OwnIterator OwnContainer::begin() {
    return OwnIterator(data.get());
}

OwnContainer::OwnIterator OwnContainer::end() {
    return OwnIterator(data.get() + size);
}

OwnContainer::OwnIterator& OwnContainer::OwnIterator::operator++() {
    ptr++; return *this;
}

OwnContainer::OwnIterator OwnContainer::OwnIterator::operator++(int) {
    OwnIterator retval = *this;
    ++(*this);
    return retval;
}

bool OwnContainer::OwnIterator::operator==(OwnIterator const& other) const {
    return ptr == other.ptr;
}
bool OwnContainer::OwnIterator::operator!=(OwnIterator const& other) const {
    return !(*this == other);
}
int& OwnContainer::OwnIterator::operator*() {
    return *ptr;
}