#include <string>
#include <iostream>
using std::cin;
using std::cout;
using std::ostream;

template <typename T>
class DynamicArray {
private:
    int size;
    T* data;
public:
    DynamicArray() {
        size = 0;
        data = nullptr;
    }
    DynamicArray(int newSize) : size(newSize) {
        if (size != 0)
            data = new T[size];
    }
    DynamicArray(const DynamicArray<T>& arr) {
        size = arr.size;
        if (size != 0) {
            data = new T[size];
        }
        else data = nullptr; // изначально был 0
        for (int i = 0; i < size; i++) {
            data[i] = arr.array[i];
        }
    }
    void resize(int newSize);

    void push_back(T val) //Метод push_back добавляет один новый элемент в конец массива.
    {
        resize(size + 1);
        data[size - 1] = val;
    }

    int getSize() const//Метод Size возвращает размер массива.
    {
        return size;
    }

    T& operator[] (int i) // перегрузим оператор []
    {
        return data[i];
    }
    void deleteElement(int element) {
        T* intermediateData = new T[size - 1];
        for (int i = 0; i < element; i++)
            intermediateData[i] = data[i];
        for (int i = element + 1; i < size; i++)
            intermediateData[i - 1] = data[i];
        delete[] data;
        data = intermediateData;
    }
    ~DynamicArray() {
        delete[] data;
    }
};
template <typename T>
void DynamicArray<T>::resize(int newSize) {
    if (size != newSize) {
        T* newData = nullptr;
        newData = new T[newSize];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    size = newSize;
}

template<typename T> //Перегрузка оператора вывода
ostream& operator << (ostream& out, DynamicArray <T> arr)
{
    for (int i = 0; i < arr.Size(); ++i)
        out << arr[i] << " ";
    return out;
}

template < typename Type>
class Stack {
private:
    int count = 0;
    DynamicArray <Type> stack;
public:
    Stack() = default;
    Stack(int size) {
        stack = DynamicArray<Type>(size);
    }
    void Push(Type element) {
        if (count >= stack.getSize()) {
            stack.push_back(element);
        }
        else {
            stack[count] = element;
        }
        count++;
    }
    void Pop() {
        stack.deleteElement(stack.getSize() - 1);
        count--;
    }
    Type Top() {
        return stack[count - 1];
    }
    int Size() {
        return count;
    }
    ~Stack() = default;
};

int main()
{
    Stack <int> stack;
    stack.Push(10);
    stack.Push(7);
    stack.Push(3);
    stack.Push(15);
    cout << "Top el: " << stack.Top();
    cout << std::endl;
    stack.Pop();
    cout << "Top el: " << stack.Top();
    cout << std::endl;
    cout << "Stack's size: " << stack.Size();
    cout << std::endl;
}