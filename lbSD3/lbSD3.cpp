#include <iostream>
#include <vector>

using namespace std;

// Реализация через динамический массив
void dynamicArrayVersion(int k)
{
    int n = 1 << k;

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    int num = 1;

    for (int col = 0; col < n; col++)
    {
        if (col % 2 == 0)
        {
            for (int row = 0; row < n; row++)
                a[row][col] = num++;
        }
        else
        {
            for (int row = n - 1; row >= 0; row--)
                a[row][col] = num++;
        }
    }

    cout << "\nРезультат (динамический массив):\n\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }

    for (int i = 0; i < n; i++)
        delete[] a[i];

    delete[] a;
}

// Реализация через связанный список

struct Node
{
    int value;
    Node* next;
};

void pushBack(Node*& head, Node*& tail, int value)
{
    Node* temp = new Node;
    temp->value = value;
    temp->next = nullptr;

    if (head == nullptr)
    {
        head = tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

void linkedListVersion(int k)
{
    int n = 1 << k;

    Node* head = nullptr;
    Node* tail = nullptr;

    int num = 1;

    for (int col = 0; col < n; col++)
    {
        if (col % 2 == 0)
        {
            for (int row = 0; row < n; row++)
                pushBack(head, tail, num++);
        }
        else
        {
            int start = num + n - 1;

            for (int row = 0; row < n; row++)
                pushBack(head, tail, start - row);

            num += n;
        }
    }

    cout << "\nРезультат (связанный список):\n\n";

    Node* cur = head;
    int count = 0;

    while (cur != nullptr)
    {
        cout << cur->value << "\t";
        count++;

        if (count % n == 0)
            cout << endl;

        cur = cur->next;
    }

    while (head != nullptr)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Реализация через STL vector

void stlVersion(int k)
{
    int n = 1 << k;

    vector<vector<int>> a(n, vector<int>(n));

    int num = 1;

    for (int col = 0; col < n; col++)
    {
        if (col % 2 == 0)
        {
            for (int row = 0; row < n; row++)
                a[row][col] = num++;
        }
        else
        {
            for (int row = n - 1; row >= 0; row--)
                a[row][col] = num++;
        }
    }

    cout << "\nРезультат (STL vector):\n\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << "\t";

        cout << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int k;
    cout << "Введите k: ";
    cin >> k;

    int choice;

    do
    {
        cout << "\n===== Меню =====\n";
        cout << "1 - Динамический массив\n";
        cout << "2 - Связанный список\n";
        cout << "3 - STL vector\n";
        cout << "0 - Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            dynamicArrayVersion(k);
            break;

        case 2:
            linkedListVersion(k);
            break;

        case 3:
            stlVersion(k);
            break;

        case 0:
            cout << "Программа завершена.\n";
            break;

        default:
            cout << "Неверный пункт меню!\n";
        }

    } while (choice != 0);
    cout << "Автор: Белоногов Олег Сергеевич, группа: 090301-ПОВа-о25";
    return 0;
}