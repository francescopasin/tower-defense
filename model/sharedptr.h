#ifndef MODEL_SHAREDPTR_H_
#define MODEL_SHAREDPTR_H_

#define U_LINT unsigned int

namespace model {

template <class T>
class SharedPtr;  // Dichiarazione incompleta

template <class T>
bool operator==(const SharedPtr<T>& left, const SharedPtr<T>& right);  // Dichiarazione incompleta

template <class T>
bool operator!=(const SharedPtr<T>& left, const SharedPtr<T>& right);  // Dichiarazione incompleta

template <class T>
class SharedPtr {
    friend bool operator==<T>(const SharedPtr& left, const SharedPtr& right);
    friend bool operator!=<T>(const SharedPtr& left, const SharedPtr& right);

   private:
    T* _ptr;
    U_LINT* _counter;

   public:
    SharedPtr(T* ptr = nullptr);
    SharedPtr(const SharedPtr<T>& SharedPtr);

    SharedPtr<T>& operator=(const SharedPtr<T>& SharedPtr);
    void swap(SharedPtr<T>& SharedPtr);

    operator bool() const;

    T* get() const;
    T& operator*() const;
    T* operator->() const;
    T& operator[](U_LINT index) const;

    void reset(T* ptr = nullptr);

    U_LINT use_count() const;

    ~SharedPtr();
};

template <class T>
bool operator==(const SharedPtr<T>& left, const SharedPtr<T>& right) {
    return left._ptr == right._ptr;
}

template <class T>
bool operator!=(const SharedPtr<T>& left, const SharedPtr<T>& right) {
    return left._ptr != right._ptr;
}

template <class T>
SharedPtr<T>::SharedPtr(T* ptr) : _ptr(ptr), _counter(new U_LINT(0)) {}

template <class T>
SharedPtr<T>::SharedPtr(const SharedPtr<T>& SharedPtr) : _ptr(SharedPtr._ptr), _counter(SharedPtr._counter) {
    (*_counter)++;
}

template <class T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T>& SharedPtr) {
    if (this != &SharedPtr) {
        (*_counter)--;
        if (*_counter <= 0) {
            delete _ptr;
            delete _counter;
        }
        _ptr = SharedPtr._ptr;
        _counter = SharedPtr._counter;
        (*_counter)++;
    }
    return *this;
}

template <class T>
void SharedPtr<T>::swap(SharedPtr<T>& SharedPtr) {
    T* temp = _ptr;
    U_LINT* tempCount = _counter;

    _ptr = SharedPtr._ptr;
    SharedPtr._ptr = temp;

    _counter = SharedPtr._counter;
    SharedPtr._counter = tempCount;
}

template <class T>
SharedPtr<T>::operator bool() const {
    return _ptr != nullptr;
}

template <class T>
T* SharedPtr<T>::get() const {
    return _ptr;
}

template <class T>
T& SharedPtr<T>::operator*() const {
    return *_ptr;
}

template <class T>
T* SharedPtr<T>::operator->() const {
    return _ptr;
}

template <class T>
T& SharedPtr<T>::operator[](U_LINT index) const {
    return _ptr[index];
}

template <class T>
void SharedPtr<T>::reset(T* ptr) {
    (*_counter)--;
    if (*_counter <= 0) {
        delete _ptr;
        delete _counter;
    }
    _ptr = ptr;
    _counter = new U_LINT(0);
}

template <class T>
U_LINT SharedPtr<T>::use_count() const {
    return (_counter ? *_counter : 0);
}

template <class T>
SharedPtr<T>::~SharedPtr() {
    (*_counter)--;
    if (*_counter <= 0) {
        delete _ptr;
        delete _counter;
    }
}

}  // namespace model

#endif
