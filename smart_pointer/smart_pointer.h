#pragma once
#include <iostream>

template<typename T>
class unique_pointer
{
public:
    unique_pointer(T* ptr = nullptr) : m_ptr(ptr) {}
    // unique_pointer(const shared_pointer&) = delete;
    // unique_pointer& operator=(const shared_pointer) = delete;
    ~unique_pointer() {
        delete m_ptr;
    }

    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
    operator bool() const { return m_ptr; }

    // provide move constructor instead of copy constructor, the later one is banned automatically
    unique_pointer(unique_pointer&& rhs) noexcept
    {
        m_ptr = rhs.m_ptr;
        rhs.m_ptr = nullptr;
    }
    unique_pointer& operator=(unique_pointer&& rhs) noexcept
    {
        m_ptr = rhs.m_ptr;
        rhs.m_ptr = nullptr;
        return *this;
    }
private:
    T* m_ptr;
};

class share_count {
public:
    share_count() : _count(1) {}
    void add_count() {
        ++_count;
    }
    long reduce_count() {
        return --_count;
    }
    long get_count() const {
        return _count;
    }
private:
    long _count;
};

template <typename T>
class shared_pointer
{
public:
    shared_pointer(T* ptr = nullptr)
        : m_ptr(ptr)
    {
        if (ptr) {
            m_share_count = new share_count;
        }
    }
    ~shared_pointer()
    {
        if (m_ptr && m_share_count->reduce_count() == 0) {
            delete m_ptr;
            delete m_share_count;
            std::cout << "~shared_pointer\n";
        }
    }
    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
    operator bool() const { return m_ptr; }

    shared_pointer(const shared_pointer& rhs) noexcept
    {
        m_ptr = rhs.m_ptr;
        m_share_count = rhs.m_share_count;
        m_share_count->add_count();
    }
    shared_pointer& operator=(const shared_pointer& rhs) noexcept
    {
        m_ptr = rhs.m_ptr;
        m_share_count = rhs.m_share_count;
        m_share_count->add_count();
        return *this;
    }

    long use_count() const {
        if (m_ptr) {
            return m_share_count->get_count();
        }
        return 0;
    }
private:
    T* m_ptr;
    share_count* m_share_count;
};


class Type
{
public:
    int a = 1;
};

void test_uniptr()
{
    unique_pointer<Type> pointer(new Type);
    unique_pointer<Type> pointer2(std::move(pointer));
    unique_pointer<Type> pointer3;
    pointer3 = std::move(pointer2);
}


void test_shaptr()
{
    shared_pointer<Type> pointer(new Type);
    std::cout << "pointer's share_count：" << pointer.use_count() << std::endl;

    shared_pointer<Type> pointer2(pointer);
    std::cout << "pointer's share_count：" << pointer2.use_count() << std::endl;

    shared_pointer<Type> pointer3;
    pointer3 = pointer2;
    std::cout << "pointer's share_count：" << pointer3.use_count() << std::endl;

}


