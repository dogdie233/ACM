#pragma once
#ifndef BINARY_ANSWER_ITERATOR_HPP
#define BINARY_ANSWER_ITERATOR_HPP
#define _SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING

#include <iostream>
#include <iterator>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

enum class CheckResultType : ptrdiff_t {
    Failed = -1,
    YesIsAnswer = 0,
    Succeed = 1,
};

template <typename T>
struct CheckResult {
    CheckResultType type;
    T value;

    CheckResult() : type(CheckResultType::Failed), value() {}
    CheckResult(CheckResultType type, T value) : type(type), value(value) {}
    CheckResult(const CheckResult& other) : type(other.type), value(other.value) {}
    CheckResult& operator=(const CheckResult& other) {
        type = other.type;
        value = other.value;
        return *this;
    }
};

template <typename T>
class MyIterator : public iterator<random_access_iterator_tag, ptrdiff_t> {
private:
    typedef function<CheckResult<T>(size_t)> CheckFunc;
    const CheckFunc* checkFunc;
public:
    size_t index;
    CheckResult<T> result;

    MyIterator() = delete;
    MyIterator(const CheckFunc& checkFunc, size_t index) : checkFunc(&checkFunc), index(index), result(checkFunc(index)) {}

    explicit MyIterator(MyIterator* other) : checkFunc(other->checkFunc), index(other->index), result(other->result) {}
    MyIterator(const MyIterator& other) : checkFunc(other.checkFunc), index(other.index), result(other.result) {}

    MyIterator& operator=(const MyIterator& other) {
        checkFunc = other.checkFunc;
        index = other.index;
        result = other.result;
        return *this;
    }

    ptrdiff_t& operator*() {
        return reinterpret_cast<ptrdiff_t&>(result.type);
    }

    const ptrdiff_t& operator*() const {
        return reinterpret_cast<const ptrdiff_t&>(result.type);
    }

    MyIterator& operator++() { index++, result = (*checkFunc)(index); return *this; }
    MyIterator operator++(int) { MyIterator tmp(*this); operator++(); return tmp; }
    MyIterator& operator--() { index--, result = (*checkFunc)(index); return *this; }
    MyIterator operator--(int) { MyIterator tmp(*this); operator--(); return tmp; }

    MyIterator& operator+=(difference_type n) { index += n, result = (*checkFunc)(index); return *this; }
    MyIterator operator+(difference_type n) const { MyIterator tmp(*this); return tmp += n; }
    friend MyIterator operator+(difference_type n, const MyIterator& it) { return it + n; }
    MyIterator& operator-=(difference_type n) { index -= n, result = (*checkFunc)(index); return *this; }
    MyIterator operator-(difference_type n) const { MyIterator tmp(*this); return tmp -= n; }
    difference_type operator-(const MyIterator& other) const { return index - other.index; }

    bool operator==(const MyIterator& other) const { return index == other.index; }
    bool operator!=(const MyIterator& other) const { return index != other.index; }
    bool operator<(const MyIterator& other) const { return index < other.index; }
    bool operator>(const MyIterator& other) const { return index > other.index; }
    bool operator<=(const MyIterator& other) const { return index <= other.index; }
    bool operator>=(const MyIterator& other) const { return index >= other.index; }

    ptrdiff_t operator[](difference_type n) { return static_cast<ptrdiff_t>((*checkFunc)(index + n).type); }
};

#endif // BINARY_ANSWER_ITERATOR_HPP