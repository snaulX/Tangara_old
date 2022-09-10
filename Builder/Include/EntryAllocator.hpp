#ifndef TANGARA_TYPEALLOCATOR_HPP
#define TANGARA_TYPEALLOCATOR_HPP
#include <vector>

namespace Tangara {
    template<typename T>
    struct EntryAllocator {
    public:
        EntryAllocator() : EntryAllocator(1 << 7) { }

        explicit EntryAllocator(size_t max_size) :
                _start(0), _length(0), _capacity(max_size), _data((T*)calloc(max_size, sizeof(T)))
        { }

        ~EntryAllocator() {
            free(_data);
        }

        void Begin() {
            _start = _length; // move '_start' to the end of filled data
        }

        void Append(T elem) {
            _data[_length++] = elem;
            if (_length > _capacity) {
                _capacity <<= 1; // *= 2 but faster
                _data = (T*) realloc(_data, _capacity * sizeof(T));
            }
        }

        void End(T **out_data, size_t &count) {
            *out_data = &_data[_start];
            count = GetCount();
        }

        void Trim() {
            _capacity = _length;
            _data = (T*) realloc(_data, _capacity * sizeof(T));
        }

        [[nodiscard]] size_t GetCapacity() const { return _capacity; }
        [[nodiscard]] size_t GetCount() const { return _length - _start; }
        [[nodiscard]] size_t GetLength() const { return _length; }
        [[nodiscard]] T* GetRawData() const { return _data; }

    private:
        size_t _start;
        size_t _length;
        size_t _capacity;
        T* _data;
    };
}

#endif //TANGARA_TYPEALLOCATOR_HPP
