#ifndef MODEL_MYLIST_H_
#define MODEL_MYLIST_H_

//TODO: INSERIRE PUNATORI SMART AL POSTO DI PUNTATORI NORMALI, NON DOOVREBBE CAMBIARE NIENTE

namespace model {

template <class T>
class MyList {
   private:
    class Node {
       public:
        T _info;
        T *_prev, *_next;

        Node(const T& info, T* prev, T* next);
        ~Node();
    };

    Node *_first, *_last;
    int _size;

    static Node* ricCopy(Node* from, Node* prev, Node* last);
    static Node* ricGet(Node* from, int index, int size);

   public:
    MyList();
    MyList(const MyList<T>& list);
    MyList<T>& operator=(const MyList<T>& list);

    void pushBack(const T& info);
    void insert(const T& info, int index);
    void pushTop(const T& info);

    T& popTop();
    T& erease(int index);
    T& popBack();

    T& operator[](int index) const;

    int size() const;

    ~MyList();

    class iterator {
        friend class MyList<T>;

       private:
        Node* _ptr;
        bool _pastTheEnd;

        iterator(Node* n, bool pastTheEnd = false);

       public:
        iterator();

        T& operator*() const;

        T* operator->() const;

        iterator& operator++();

        iterator& operator--();

        bool operator==(const iterator& x) const;

        bool operator!=(const iterator& x) const;
    };

    iterator begin() const;
    iterator end() const;
};

template <class T>
MyList<T>::Node::Node(const T& info, T* prev, T* next) : _info(info), _prev(prev), _next(next) {}

template <class T>
MyList<T>::Node::~Node() {
    delete _next;
}

template <class T>
MyList<T>::MyList() : _size(0), _first(nullptr), _last(nullptr) {}

template <class T>
typename MyList<T>::Node* MyList<T>::ricCopy(Node* from, Node* prev, Node* last) {
    if (from == nullptr) {
        last = prev;
        return nullptr;
    }

    Node* temp = new Node(from->_key, from->_info);
    temp->_prec = prev;
    temp->_next = ricCopy(from->_next, temp, last);
    return temp;
}

template <class T>
typename MyList<T>::Node* MyList<T>::ricGet(Node* from, int index, int size) {
    if (index < 0 || index > size)
        return nullptr;
    if (index == 0)
        return from;
    return ricGet(from->_next, index--, size);
}

template <class T>
MyList<T>::MyList(const MyList<T>& list) {
    _first = ricCopy(list._first, _first, _last);
    _size = list._size;
}

template <class T>
MyList<T>& MyList<T>::operator=(const MyList<T>& list) {
    if (this != &list) {
        delete _first;
        _first = ricCopy(list._first, _first, _last);
        _size = list._size;
    }
    return this;
}

template <class T>
MyList<T>::~MyList() {
    delete _first;
}

template <class T>
void MyList<T>::pushBack(const T& info) {
    _size++;
    _last->_next = new Node(info, _last, nullptr);
}

template <class T>
void MyList<T>::pushTop(const T& info) {
    _size++;
    _first->_prev = new Node(info, nullptr, _first);
}

template <class T>
void MyList<T>::insert(const T& info, int index) {
    if (index == 0)
        pushTop(info);
    else if (index == _size)
        pushBack(info);
    else if (index > 0 && index < _size) {
        Node* temp = ricGet(_first, index, _size);
        temp->_next = new Node(info, temp, temp->_next);
    } else {
        //! ERRORE!
    }
}

template <class T>
T& MyList<T>::popBack() {
    T* temp = new T(_last->_info);
    Node* ultimo = _last;
    _last = _last->_prev;
    _last->_next = nullptr;
    delete ultimo;
    _size--;
    return *temp;
}

template <class T>
T& MyList<T>::popTop() {
    T* temp = new T(_first->_info);
    Node* second = _first->_next;
    _first->_next = nullptr;
    delete _first;
    _first = second;
    _size--;
    return *temp;
}

template <class T>
T& MyList<T>::operator[](int index) const {
    return ricGet(_first, index, _size);
}

template <class T>
T& MyList<T>::erease(int index) {
    if (index == 0)
        return popTop();

    if (index == _size)
        return popBack();

    if (index > 0 && index < _size) {
        Node* temp = ricGet(_first, index, _size);
        temp->_prev->_next = temp->_next;
        temp->_next->_prev = temp->_prev;
        T* info = new T(temp->_info);
        delete temp;
        _size--;
        return *info;
    }

    return nullptr;
}

template <class T>
int MyList<T>::size() const {
    return _size;
}

template <class T>
MyList<T>::iterator::iterator() : _ptr(nullptr), _pastTheEnd(false) {}

template <class T>
MyList<T>::iterator::iterator(Node* n, bool pastTheEnd) : _ptr(n), _pastTheEnd(pastTheEnd) {}

template <class T>
T& MyList<T>::iterator::operator*() const {
    return _ptr->_info;
}

template <class T>
T* MyList<T>::iterator::operator->() const {
    return &(_ptr->_info);
}

template <class T>
typename MyList<T>::iterator& MyList<T>::iterator::operator++() {
    if (_ptr != nullptr) {
        if (!_pastTheEnd) {
            if (_ptr->next == nullptr) {
                _ptr++;
                _pastTheEnd = true;
            } else {
                _ptr = _ptr->_next;
            }
        }
    }
    return *this;
}

template <class T>
typename MyList<T>::iterator& MyList<T>::iterator::operator--() {
    if (_ptr != nullptr) {
        if (_pastTheEnd) {
            _ptr--;
            _pastTheEnd = false;
        } else
            _ptr = _ptr->_prec;
    }
    return *this;
}

template <class T>
bool MyList<T>::iterator::operator==(const iterator& x) const {
    return _ptr == x._ptr;
}

template <class T>
bool MyList<T>::iterator::operator!=(const iterator& x) const {
    return _ptr != x._ptr;
}

template <class T>
typename MyList<T>::iterator MyList<T>::begin() const {
    return _first;
}

template <class T>
typename MyList<T>::iterator MyList<T>::end() const {
    if (_last == nullptr)
        return nullptr;
    return iterator(_last + 1, true);
}

}  // namespace model

#endif
