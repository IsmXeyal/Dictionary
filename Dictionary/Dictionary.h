#pragma once

template<class TKey = string, class TValue = string>
class KeyValuePairs {
public:
    TKey _KeyPair;
    TValue _ValuePair;

    KeyValuePairs() : _KeyPair(), _ValuePair() {}

    KeyValuePairs(TKey key, TValue value) : _KeyPair(key), _ValuePair(value) {}

    TValue& operator[](const TKey key) {
        if (_KeyPair == key)
            return _ValuePair;
        assert(!"Key is not Correct");
    }
};

template<class TKey = string, class TValue = string>
class Dictionary {
private:
    KeyValuePairs<TKey, TValue>* _pairs = nullptr;
    size_t _count = 0;
    size_t _capacity = 5;

public:

    Dictionary() {
        _pairs = new KeyValuePairs<TKey, TValue>[_capacity];
    }

    TValue& item(const TKey key) {
        for (size_t i = 0; i < _count; i++) {
            if (key == _pairs[i]._KeyPair)
                return _pairs[i]._ValuePair;
        }
        assert(!"This key doesn't exists in the dictionary!");
    }

    TValue& operator[](const TKey key) {
        for (size_t i = 0; i < _count; i++) {
            if (_pairs[i]._KeyPair == key)
                return _pairs[i][key];
        }
        assert(!"NULL");
    }

    void add(const KeyValuePairs<TKey, TValue> pair) {
        if (_count < _capacity) {
            _pairs[_count] = pair;
            _count++;
            return;
        }
        for (size_t i = 0; i < _count; i++) {
            if (_pairs[i]._KeyPair == pair._KeyPair)
                assert(!"This key already exists in the dictionary!");
        }

        _capacity += 5;

        KeyValuePairs<TKey, TValue>* temp = new KeyValuePairs<TKey, TValue>[_capacity];

        for (size_t i = 0; i < _count; i++)
            temp[i] = _pairs[i];

        temp[_count] = pair;
        _count++;

        delete[] _pairs;
        _pairs = temp;
    }

    void add(const TKey key, const TValue value) {
        if (_count < _capacity) {
            _pairs[_count] = KeyValuePairs<TKey, TValue>(key, value);
            _count++;
            return;
        }

        _capacity += 5;

        KeyValuePairs<TKey, TValue>* temp = new KeyValuePairs<TKey, TValue>[_capacity];

        for (size_t i = 0; i < _count; i++)
            temp[i] = _pairs[i];

        temp[_count] = KeyValuePairs<TKey, TValue>(key, value);
        _count++;

        delete[] _pairs;
        _pairs = temp;
    }

    size_t count() const {
        return _count;
    }

    size_t capacity() const {
        return _capacity;
    }

    TKey* keys() {
        TKey* keyArray = new TKey[_count];
        for (size_t i = 0; i < _count; i++) {
            keyArray[i] = _pairs[i]._KeyPair;
        }
        return keyArray;
    }

    TValue* values() {
        TValue* valueArray = new TValue[_count];
        for (size_t i = 0; i < _count; i++) {
            valueArray[i] = _pairs[i]._ValuePair;
        }
        return valueArray;
    }

    KeyValuePairs<TKey, TValue>* items() {
        KeyValuePairs<TKey, TValue>* itemArray = new KeyValuePairs<TKey, TValue>[_count];
        for (size_t i = 0; i < _count; i++) {
            itemArray[i] = _pairs[i];
        }
        return itemArray;
    }

    void clear() {
        delete[] _pairs;
        _pairs = nullptr;
        _count = 0;
        _capacity = 5;
    }

    bool containsKey(const TKey key) const {
        for (size_t i = 0; i < _count; i++) {
            if (_pairs[i]._KeyPair == key)
                return true;
        }
        return false;
    }

    bool containsValue(const TValue value) const {
        for (size_t i = 0; i < _count; i++) {
            if (_pairs[i]._ValuePair == value)
                return true;
        }
        return false;
    }

    bool remove(const TKey key) {
        for (size_t i = 0; i < _count; i++) {
            if (_pairs[i]._KeyPair == key) {
                for (size_t j = i; j < _count - 1; j++) {
                    _pairs[j] = _pairs[j + 1];
                }
                _count--;
                return true;
            }
        }
        return false;
    }

    Dictionary<TKey, TValue> copy() {
        Dictionary<TKey, TValue> newDict;
        newDict._count = _count;
        newDict._capacity = _capacity;
        newDict._pairs = new KeyValuePairs<TKey, TValue>[_capacity];
        for (size_t i = 0; i < _count; i++) {
            newDict._pairs[i] = _pairs[i];
        }
        return newDict;
    }

    void update(const TKey& key, const TValue& value) {
        for (size_t i = 0; i < _count; i++) {
            if (_pairs[i]._KeyPair == key) {
                _pairs[i]._ValuePair = value;
                return; 
            }
        }
        add(key, value);
    }

    void items_() {
        KeyValuePairs<TKey, TValue>* items = this->items();
        cout << "Key_Value pairs in the dictionary: " << endl;
        for (size_t i = 0; i < _count; i++) {
            cout << items[i]._KeyPair << " : " << items[i]._ValuePair << endl;
        }
        delete[] items;
    }

    ~Dictionary() {
        delete[] _pairs;
    }
};
