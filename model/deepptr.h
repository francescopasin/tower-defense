#ifndef MODEL_DEEPPTR_H_
#define MODEL_DEEPPTR_H_

#define U_LINT unsigned int

namespace model {

template <class T>
class DeepPtr {
   private:
    T* _ptr;
    U_LINT* _counter;

   public:
    DeepPtr(T* ptr = nullptr);
    DeepPtr(const DeepPtr<T>& deepPtr);

    DeepPtr<T>& operator=(const DeepPtr<T>& deepPtr);
    void swap(DeepPtr<T>& deepPtr);

    operator bool() const;

    T* get() const;
    T& operator*() const;
    T* operator->() const;
    T& operator[](U_LINT index) const;

    void reset(const T* ptr = nullptr);

    bool unique() const;
    U_LINT use_count() const;

    ~DeepPtr();
};

template <class T>
DeepPtr<T>::DeepPtr(T* ptr) : _ptr(ptr), _counter(new U_LINT(0)) {}

template <class T>
DeepPtr<T>::DeepPtr(const DeepPtr<T>& deepPtr) : _ptr(deepPtr._ptr), _counter(deepPtr._counter) {
    (*_counter)++;
}

template <class T>
DeepPtr<T>& DeepPtr<T>::operator=(const DeepPtr<T>& deepPtr) {
    if (this != &deepPtr) {
        (*_counter)--;
        if (*_counter <= 0) {
            delete _ptr;
            delete _counter;
        }
        _ptr = deepPtr._ptr;
        _counter = deepPtr._counter;
        (*_counter)++;
    }
    return *this;
}

template <class T>
void DeepPtr<T>::swap(DeepPtr<T>& deepPtr) {
    T* temp = _ptr;
    U_LINT* tempCount = _counter;

    _ptr = deepPtr._ptr;
    deepPtr._ptr = temp;

    _counter = deepPtr._counter;
    deepPtr._counter = tempCount;
}

template <class T>
DeepPtr<T>::operator bool() const {
    return _ptr != nullptr;
}

template <class T>
T* DeepPtr<T>::get() const {
    return _ptr;
}

template <class T>
T& DeepPtr<T>::operator*() const {
    return *_ptr;
}

template <class T>
T* DeepPtr<T>::operator->() const {
    return _ptr;
}

template <class T>
T& DeepPtr<T>::operator[](U_LINT index) const {
    return _ptr[index];
}

template <class T>
void DeepPtr<T>::reset(const T* ptr) {
    (*_counter)--;
    if (*_counter <= 0) {
        delete _ptr;
        delete _counter;
    }
    _ptr = ptr;
    _counter = new U_LINT(0);
}

template <class T>
bool DeepPtr<T>::unique() const {
    return (_counter ? *_counter : 0) == 1;
}

template <class T>
U_LINT DeepPtr<T>::use_count() const {
    return (_counter ? *_counter : 0);
}

template <class T>
DeepPtr<T>::~DeepPtr() {
    (*_counter)--;
    if (*_counter <= 0) {
        delete _ptr;
        delete _counter;
    }
}

}  // namespace model

#endif
