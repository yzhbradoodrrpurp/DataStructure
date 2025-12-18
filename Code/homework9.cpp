//
// Created by 易治行 on 2025/12/18.
//

#include <iostream>
#include <vector>
#include <random>

void quickSort(std::vector<int>&, int, int);
void heapSort(std::vector<int>&);
void swap(int&, int&);
void heapify(std::vector<int>&, int, int);

int main(void) {
    int length;
    std::cout << "Enter length of elements: ";
    std::cin >> length;

    std::vector<int> elements;
    bool isRandom;

    std::cout << "Randomly generate elements, (1 for yes, 0 for no): ";
    std::cin >> isRandom;

    std::mt19937 rng((unsigned int)(time(0)));
    std::uniform_int_distribution<int> dist(0, 100);

    for (int i = 0; i < length; i++) {
        if (isRandom) {
            int newRandom = dist(rng);
            elements.push_back(newRandom);
        }
        else {
            int newElement;
            std::cin >> newElement;
            elements.push_back(newElement);
        }
    }

    std::cout << "Original elements: ";
    for (auto element: elements)
        std::cout << element << " ";
    std::cout << std::endl;

    quickSort(elements, 0, length - 1);

    std::cout << "After quick sort: ";
    for (auto element: elements)
        std::cout << element << " ";
    std::cout << std::endl;

    heapSort(elements);
    std::cout << "After heap sort: ";
    for (auto element: elements)
        std::cout << element << " ";
    std::cout << std::endl;

    return 0;
}

void quickSort(std::vector<int>& elements, int left, int right) {
    if (left >= right)
        return;

    int pivot = elements[left];
    int i = left, j = right;

    while (i < j) {
        while (i < j && elements[j] >= pivot)
            j--;

        while (i < j && elements[i] <= pivot)
            i++;

        if (i < j)
            swap(elements[i], elements[j]);
    }

    swap(elements[left], elements[i]);

    quickSort(elements, left, i - 1);
    quickSort(elements, i + 1, right);
}

void swap(int& a, int& b) {
    int c = a;
    a = b;
    b = c;
}

void heapify(std::vector<int>& elements, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && elements[l] > elements[largest])
        largest = l;

    if (r < n && elements[r] > elements[largest])
        largest = r;

    if (largest != i) {
        swap(elements[i], elements[largest]);
        heapify(elements, n, largest);
    }
}

void heapSort(std::vector<int>& elements) {
    int n = static_cast<int>(elements.size());
    if (n <= 1) return;

    // 建堆（构造最大堆）
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(elements, n, i);
    }

    // 逐个取出堆顶到数组末尾，并对剩余元素重新堆化
    for (int i = n - 1; i > 0; --i) {
        swap(elements[0], elements[i]);
        heapify(elements, i, 0);
    }

}