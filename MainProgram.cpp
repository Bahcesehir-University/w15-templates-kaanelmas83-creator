// ============================================================================
//  Lab: C++ Templates  (STUDENT VERSION)
//  Course: Object-Oriented Programming with C++
//  Single file only. No headers. C++17.
//
//  Complete every TODO. Do NOT rename the functions/classes/methods,
//  and do NOT change their signatures - the autograder depends on them.
// ============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

// ================================
// CLASS / TEMPLATE DEFINITIONS
// ================================

// ---- Group 1: Basic function template -------------------------------------
// TODO 1: Write a function template maxValue that takes two values of the
//         SAME type T and returns the larger one.
template <typename T>
T maxValue(T a, T b) {
    // TODO 1: return the larger of a and b
    return (a > b ) ? a : b ; // <-- replace
}

// ---- Group 2: Function template with multiple type parameters --------------
// TODO 2: Write a function template addValues that takes two values which may
//         be of DIFFERENT types (T1, T2) and returns their sum.
//         The return type must follow the usual arithmetic rules
//         (e.g. int + double -> double). Use a trailing return type
//         with decltype.
template <typename T1, typename T2>
auto addValues(T1 a, T2 b) -> decltype(a + b) {
    // TODO 2: return the sum of a and b
    return a + b ; // <-- replace
}

// ---- Group 3: Class template ----------------------------------------------
// TODO 3: Complete the class template Pair that stores two values of types
//         A and B. Implement the getters, setters, and swapValues().
template <typename A, typename B>
class Pair {
private:
    A first_;
    B second_;
public:
    // TODO 3a: constructor that initializes first_ and second_
    Pair(A first, B second) : first_(first) , second_(second){}

    // TODO 3b: getters (const)
    A getFirst() const  { return first_; }   // <-- replace
    B getSecond() const { return second_; }   // <-- replace

    // TODO 3c: setters
    void setFirst(A value)  { first_ = value;}           // <-- replace
    void setSecond(B value) {second_ = value;}           // <-- replace

    // TODO 3d: swapValues - swap first_ and second_ (assume A == B when called)
    void swapValues() {
        // replace
        A temp = first_;
        first_ = static_cast<A>(second_);
        second_ = static_cast<B>(temp);
    }
};

// ---- Group 4: Generic container -------------------------------------------
// TODO 4: Complete the class template Box, a generic dynamic container that
//         stores elements of type T inside a std::vector<T>.
template <typename T>
class Box {
private:
    std::vector<T> items_;
public:
    // TODO 4a: add an item to the back
    void add(const T& item) {items_.push_back(item); }

    // TODO 4b: return number of stored items as int
    int size() const { return static_cast<int>(items_.size()); }        // <-- replace

    // TODO 4c: return the item at index; throw std::out_of_range if invalid
    T get(int index) const {
        if (index < 0 || index >=size())
            throw std::out_of_range("Box index out of range");
        return items_[index];
    }

    // TODO 4d: return the sum of all stored elements
    T total() const {
        T sum = T();
        for(const T& value : items_) 
            sum+=value;
        return sum; // <-- replace
    }
};

// ---- Group 5: Template specialization -------------------------------------
// TODO 5a: Generic describe() - return 1 for any non-string type.
template <typename T>
int describe(const T& value) {
    return 1; // <-- replace with 1
}

// TODO 5b: Full specialization of describe for std::string.
//          It must return 2 + the length of the string.
//          Write the specialization below (template<> int describe<std::string>...).
//
//          <-- write your specialization here
template <>
int describe<std::string>(const std::string& value){
    return 2 + static_cast<int>(value.size());
}

// ---- Group 6: Non-type template parameter ---------------------------------
// TODO 6: Complete FixedArray<T, N>, a stack array of compile-time size N.
template <typename T, int N>
class FixedArray {
private:
    T data_[N];
public:
    // TODO 6a: default-construct all N elements to T()
    FixedArray() {
        for(int i = 0 ; i < N ; ++i ) data_[i] = T();
    }

    // TODO 6b: return N
    int capacity() const { return N; }    // <-- replace

    // TODO 6c: set data_[index]; throw std::out_of_range if invalid
    void set(int index, const T& value) {
        // replace
        if (index < 0 || index >=N)
            throw std::out_of_range("FixedArray index out of range");
        data_[index] = value;
    }

    // TODO 6d: return data_[index]; throw std::out_of_range if invalid
    T at(int index) const {
        if (index < 0 || index >=N)
            throw std::out_of_range("FixedArray index out of range");
        return data_[index];
    }
};

// ================================
// FUNCTION IMPLEMENTATIONS / main
// ================================

int main() {
    std::cout << "=== C++ Templates Lab ===\n";

    // You may add your own test calls here to experiment.
    std::cout << "maxValue(3, 7) = " << maxValue(3, 7) << "\n";

    return 0;
}
