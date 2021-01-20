#ifndef MODEL_DEEPPTR_H_
#define MODEL_DEEPPTR_H_

namespace model {

template <class T>
class DeepPtr {
   private:
    T* _ptr;

   public:
    DeepPtr(T* ptr = nullptr);
    DeepPtr(const DeepPtr<T>& deepPtr);

    DeepPtr<T>& operator=(const DeepPtr<T>& deepPtr);
    void swap(DeepPtr<T>& deepPtr);

    operator bool() const;

    T* get() const;
    T& operator*() const;
    T* operator->() const;

    T* release();
    void reset(const T* ptr = nullptr);

    ~DeepPtr();
};

template <class T>
DeepPtr<T>::DeepPtr(T* ptr) : _ptr(ptr) {}

template <class T>
DeepPtr<T>::DeepPtr(const DeepPtr<T>& deepPtr) {
    _ptr = deepPtr->clone();
}

template <class T>
DeepPtr<T>& DeepPtr<T>::operator=(const DeepPtr<T>& deepPtr) {
    if (this != &deepPtr) {
        delete _ptr;
        _ptr = deepPtr->clone();
    }
    return *this;
}

template <class T>
void DeepPtr<T>::swap(DeepPtr<T>& deepPtr) {
    T* temp = _ptr;
    _ptr = deepPtr._ptr;
    deepPtr._ptr = temp;
}

template <class T>
DeepPtr<T>::operator bool() const {
    return _ptr;
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
T* DeepPtr<T>::release() {
    T* temp = _ptr;
    _ptr = nullptr;
    return temp;
}

template <class T>
void DeepPtr<T>::reset(const T* ptr) {
    delete _ptr;
    _ptr = ptr;
}

template <class T>
DeepPtr<T>::~DeepPtr() {
    delete _ptr;
}

}  // namespace model

#endif
