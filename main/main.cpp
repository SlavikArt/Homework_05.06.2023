#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

template<typename T>
struct Greater
{
    bool operator()(const T& a, const T& b) const
    {
        return a > b;
    }
};

template <typename T>
class SortStrategy abstract
{
public:
    virtual void Sort(vector<T>& v) abstract;
};

template <typename T>
class AscendingSort : public SortStrategy<T>
{
public:
    void Sort(vector<T>& v) override
    {
        sort(v.begin(), v.end());
    }
};

template <typename T>
class DescendingSort : public SortStrategy<T>
{
public:
    void Sort(vector<T>& v) override
    {
        sort(v.begin(), v.end(), Greater<T>());
    }
};

template <typename T>
class SortedArray
{
    vector<T> vector;
    SortStrategy<T>* sortstrategy;
public:
    void SetSortStrategy(SortStrategy<T>* sortstrategy)
    {
        this->sortstrategy = sortstrategy;
    }
    void Add(T value)
    {
        vector.push_back(value);
    }
    void Sort()
    {
        sortstrategy->Sort(vector);

        for (T value : vector)
            cout << value << ", ";
        cout << "\n";
    }
};

int main()
{
    SortedArray<string> arStr;

    arStr.Add("Strategy");
    arStr.Add("Observer");
    arStr.Add("Iterator");
    arStr.Add("Mediator");
    arStr.Add("Memento");
    arStr.Add("Interpreter");
    arStr.Add("State");
    arStr.Add("Command");

    AscendingSort<string> ascendingStr;
    arStr.SetSortStrategy(&ascendingStr);
    arStr.Sort();

    DescendingSort<string> descendingStr;
    arStr.SetSortStrategy(&descendingStr);
    arStr.Sort();

    cout << "\n";

    SortedArray<int> arInt;

    arInt.Add(2);
    arInt.Add(6);
    arInt.Add(4);
    arInt.Add(1);
    arInt.Add(5);
    arInt.Add(3);

    AscendingSort<int> ascendingInt;
    arInt.SetSortStrategy(&ascendingInt);
    arInt.Sort();

    DescendingSort<int> descendingInt;
    arInt.SetSortStrategy(&descendingInt);
    arInt.Sort();
}
