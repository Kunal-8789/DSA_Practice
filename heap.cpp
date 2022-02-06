#include <bits/stdc++.h>
using namespace std;

void swap(int &x, int &y)
{
    int temp = y;
    y = x;
    x = temp;
}

class Minheap
{
public:
    int heapsize;
    int capacity;
    int *harr;

    Minheap(int cap)
    {
        heapsize = 0;
        capacity = cap;
        harr = new int[cap];
    }

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int right(int i)
    {
        return (2 * i + 2);
    }

    int left(int i)
    {
        return (2 * i + 1);
    }

    void insert(int key)
    {
        if (heapsize == capacity)
        {
            cout << "Overflow" << endl;
            return;
        }
        heapsize++;
        int i = heapsize - 1;
        harr[i] = key;
        while (i != 0 && (harr[parent(i)] < harr[i]))
        {
            swap(harr[i], harr[parent(i)]);
            i = parent(i);
        }
    }

    void linearSearch(int val)
    {
        for (int i = 0; i < heapsize; i++)
        {
            if (harr[i] == val)
            {
                cout << "Value Found!";
                return;
            }
        }
        cout << "Value NOT Found!";
    }

    void printArray()
    {
        for (int i = 0; i < heapsize; i++)
            cout << harr[i] << " ";
        cout << endl;
    }

    int height()
    {
        return ceil(log2(heapsize + 1)) - 1;
    }

    void MinHeapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int largest = i;
        if (l < heapsize && harr[l] > harr[i])
        {
            largest = l;
        }
        else if (r < heapsize && harr[r] > harr[largest])
        {
            largest = r;
        }
        if (largest != i)
        {
            swap(harr[i], harr[largest]);
            MinHeapify(largest);
        }
    }

    int extractMin()
    {
        if (heapsize <= 0)
        {
            return INT_MAX;
        }
        else if (heapsize == 1)
        {
            heapsize--;
            return harr[0];
        }
        else if (heapsize > 1)
        {
            int root = harr[0];
            harr[0] = harr[heapsize - 1];
            heapsize--;
            MinHeapify(0);
            return root;
        }
    }

    void decreaseKey(int i, int new_val)
    {
        harr[i] = new_val;
        while (i != 0 && harr[parent(i)] > harr[i])
        {
            swap(harr[i], harr[parent(i)]);
            i = parent(i);
        }
    }
    void deleteKey(int i)
    {
        decreaseKey(i, INT_MIN);
        extractMin();
    }
};

int main()
{
    int s;
    cout << "Enter size of min heap" << endl;
    Minheap obj(s);
    cout << "Minheap is created" << endl;

    int option, val;

    do
    {
        cout << "What operation do you want to perform? "
             << " Select Option number. Enter 0 to exit." << endl;
        cout << "1. Insert Key/Node" << endl;
        cout << "2. Search Key/Node" << endl;
        cout << "3. Delete Key/Node" << endl;
        cout << "4. Get Min" << endl;
        cout << "5. Extract Min" << endl;
        cout << "6. Height of Heap" << endl;
        cout << "7. Print/Traversal Heap values" << endl;
        cout << "8. Clear Screen" << endl;
        cout << "0. Exit Program" << endl;

        cin >> option;

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "INSERT Operation -" << endl;
            cout << "Enter VALUE to INSERT in HEAP: ";
            cin >> val;
            obj.insert(val);
            cout << endl;
            break;
        case 2:
            cout << "SEARCH Operation -" << endl;
            cout << "Enter VALUE to SEARCH in HEAP: ";
            cin >> val;
            obj.linearSearch(val);
            break;
        case 3:
            cout << "DELETE Operation -" << endl;
            cout << "Enter INDEX of Heap Array to DELETE: ";
            cin >> val;
            obj.deleteKey(val);
            break;
        case 4:
            cout << "GET Min value : ";
            //<< obj.getMin();
            cout << endl;
            break;
        case 5:
            cout << "EXTRACT Min value : " << obj.extractMin();
            cout << endl;
            break;
        case 6:
            cout << "HEAP TREE HEIGHT : " << obj.height() << endl;
            break;

        case 7:
            cout << "PRINT Heap Array : " << endl;
            obj.printArray();

            cout << endl;
            break;

        case 8:
            system("cls");
            break;

        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);

    return 0;
}
