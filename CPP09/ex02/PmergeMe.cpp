#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

// The merge function runs in O(n) time, where n is the total number of elements in the two subarrays
template <typename Container>
void PmergeMe::merge(Container& container, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary containers for left and right subarrays
    Container L(n1), R(n2);

    // Copy the left and right subarrays into L and R
    for (int i = 0; i < n1; i++)
        L[i] = container[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = container[mid + 1 + i];

    int i = 0, j = 0, k = left;

    // Compare elements of L and R directly (no need to access first element)
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {  // Compare elements directly
            container[k] = L[i];
            i++;
        } else {
            container[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements from L
    while (i < n1) {
        container[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements from R
    while (j < n2) {
        container[k] = R[j];
        j++;
        k++;
    }
}



template <typename Container>
void PmergeMe::mergeSort(Container& container, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(container, left, mid);
        mergeSort(container, mid + 1, right);
        merge(container, left, mid, right);
    }
}


// Generate Jacobsthal numbers
std::vector<int> PmergeMe::generateJacobsthalNumbers(int n) {
    std::vector<int> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    
    while (jacobsthal.back() < n) {
        int next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        jacobsthal.push_back(next);
    }
    return jacobsthal;
}

// Binary search and insert function
template <typename Container>
void PmergeMe::binarySearchAndInsert(Container& data, int value) {
    int left = 0;
    int right = data.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (data[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    data.insert(data.begin() + left, value);
}

// Ford-Johnson algorithm implementation
template <typename Container>
void PmergeMe::fordJohnsonSort(Container& container) {
    if (container.size() <= 1) return;

    // Step 1: Make pairs and sort them
    Container pairs;
    for (size_t i = 0; i < container.size() - 1; i += 2) {
        if (container[i] < container[i + 1]) {
            pairs.push_back(container[i + 1]);
            pairs.push_back(container[i]);
        } else {
            pairs.push_back(container[i]);
            pairs.push_back(container[i + 1]);
        }
    }

    // Step 3: Sort the pairs using merge sort
    mergeSort(pairs, 0, pairs.size() - 1);

    Container insert;
    if (container.size() % 2 != 0) {
        insert.push_back(container.back()); // Store the smallest element in insert
    }

    // Step 4: Create the data array (store the largest element)
    Container data;
    for (size_t i = 0; i < pairs.size(); i += 2) {
        data.push_back(pairs[i]);
    }

    // Step 5: Generate Jacobsthal numbers
    std::vector<int> jacobsthal = generateJacobsthalNumbers(insert.size());

    // Step 6: Insert elements using binary search based on Jacobsthal numbers
    for (size_t i = 0; i < jacobsthal.size(); i++) {
        if (static_cast<size_t>(jacobsthal[i]) < insert.size()) {
            binarySearchAndInsert(data, insert[jacobsthal[i]]);
        }
    }

    // Step 7: Insert the remaining elements from pairs
    for (size_t i = 1; i < pairs.size(); i += 2) {
        binarySearchAndInsert(data, pairs[i]);
    }

    // Update the original container with the sorted data
    container = data;
}

// Display sequence
// Display sequence for std::vector<int>
void PmergeMe::displaySequence(const std::string& message, const std::vector<int>& sequence) {
    std::cout << message;
    for (size_t i = 0; i < sequence.size(); i++) {
        std::cout << sequence[i] << " ";
    }
    std::cout << std::endl;
}

// Display sequence for std::deque<int>
void PmergeMe::displaySequence(const std::string& message, const std::deque<int>& sequence) {
    std::cout << message;
    for (size_t i = 0; i < sequence.size(); i++) {
        std::cout << sequence[i] << " ";
    }
    std::cout << std::endl;
}


// Display time
void PmergeMe::displayTime(const std::string& containerType, size_t size, double time) {
    std::cout << "Time to process a range of " << size << " elements with " << containerType << ": "
              << std::fixed << std::setprecision(5) << time << " us" << std::endl;
}

// Main sorting and display function
void PmergeMe::sortAndDisplay(std::vector<int>& vec, std::deque<int>& deq) {
    // Display unsorted sequence for vector
    displaySequence("Before (std::vector): ", vec);

    // Sort using vector
    clock_t start = clock();
    fordJohnsonSort(vec);
    clock_t end = clock();
    double time_vec = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

    // Display sorted sequence for vector
    displaySequence("After (std::vector): ", vec);

    // Display time for vector
    displayTime("std::vector", vec.size(), time_vec);

    // Display unsorted sequence for deque
    displaySequence("Before (std::deque): ", deq);

    // Sort using deque
    start = clock();
    fordJohnsonSort(deq);
    end = clock();
    double time_deq = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

    // Display sorted sequence for deque
    displaySequence("After (std::deque): ", deq);

    // Display time for deque
    displayTime("std::deque", deq.size(), time_deq);
}
