#include "vectorHeader.hpp"

int main() {
    Vector<int> vec;

    std::cout << "Initial vector:\n";
    std::cout << "Size: " << vec.getsize() << ", Capacity: " << vec.getcapacity() << '\n';

    // Push elements
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    std::cout << "Vector after push_back operations:\n";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << "\nSize: " << vec.getsize() << ", Capacity: " << vec.getcapacity() << '\n';

    // Insert at index 1
    vec.insert(1, 10);
    std::cout << "Vector after insert at index 1:\n";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << "\nSize: " << vec.getsize() << ", Capacity: " << vec.getcapacity() << '\n';

    // Erase element at index 2
    vec.erase(2);
    std::cout << "Vector after erase at index 2:\n";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << "\nSize: " << vec.getsize() << ", Capacity: " << vec.getcapacity() << '\n';

    // Pop last element
    vec.pop_back();
    std::cout << "Vector after pop_back:\n";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << "\nSize: " << vec.getsize() << ", Capacity: " << vec.getcapacity() << '\n';

    // Test front() and back()
    if (!vec.empty()) {
        std::cout << "Front element: " << vec.front() << '\n';
        std::cout << "Back element: " << vec.back() << '\n';
    }

    // Reserve capacity
    vec.reserve(10);
    std::cout << "Vector after reserving capacity 10:\n";
    std::cout << "Size: " << vec.getsize() << ", Capacity: " << vec.getcapacity() << '\n';

    // Resize the vector
    vec.resize(6);
    std::cout << "Vector after resize to 6 elements:\n";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << "\nSize: " << vec.getsize() << ", Capacity: " << vec.getcapacity() << '\n';

    // Shrink to fit
    vec.shrink_to_fit();
    std::cout << "Vector after shrink_to_fit:\n";
    std::cout << "Size: " << vec.getsize() << ", Capacity: " << vec.getcapacity() << '\n';

    // Clear the vector
    vec.clear();
    std::cout << "Vector after clear:\n";
    std::cout << "Size: " << vec.getsize() << ", Capacity: " << vec.getcapacity() << '\n';

    // Check if vector is empty
    if (vec.empty()) {
        std::cout << "Vector is now empty.\n";
    }

    return 0;
}
