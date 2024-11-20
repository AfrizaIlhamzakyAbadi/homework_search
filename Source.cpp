#include <iostream>
#include <stdlib.h>
#define N 30
#define MAX_VAL 20

using namespace std;

void fill_array(unsigned int x[])
{
    srand(time(0));
    for (unsigned int i = 0; i < N; i++)
        x[i] = rand() % MAX_VAL;
}

void print_array(unsigned int x[])
{
    cout << "{ ";
    for (unsigned int i = 0; i < N - 1; i++)
        cout << x[i] << ", ";
    cout << x[N - 1] << " }";
    cout << endl;
}

void bubble_sort(unsigned int x[])
{
    for (unsigned int u = 0; u < N; u++)
    {
        for (unsigned int i = 0; i < N - u - 1; i++)
        {
            if (x[i] > x[i + 1])
            {
                unsigned int temp = x[i];
                x[i] = x[i + 1];
                x[i + 1] = temp;
            }
        }
    }
}

int linear_search(unsigned int search_val, unsigned int x[])
{
    unsigned int i = 0;

    while ((x[i] < search_val) && (i < N)) //the checked value is smaller than search_val
        i = i + 1; //move i to the next position

    if (i == N)
        return -1;
    else if (x[i] == search_val)
        return i;
    else
        return -1;
}
int f[N];
void binary_search(unsigned int search_val, unsigned int x[])
{
    int L{ 0 }, R{ N - 1 };
    while (L <= R)
    {
        if (x[(L + R) / 2] == search_val)
        {
            int u = ((L + R) / 2);
            int v{ u }, i{ 1 }, k{ 1 };
            f[0] = u;
            while (x[u - 1] == x[u] && u >= 0)
            {
                f[i] = u - 1;
                k += 1;
                i++;
                u--;
            }
            while (x[u + 1] == x[u] && u < N)
            {
                f[i] = u + 1;
                k += 1;
                i++;
                u++;
            }
            cout << "index of element n: [ " << f[0];
            for (int l{ 1 }; l < k; l++)
            {     
                
                cout << ", " << f[l];
            }
            cout << " ]";
            break;
        }
        else if (search_val < x[(L + R) / 2])
        {
            R = (L + R) / 2 - 1;
        }
        else if (search_val > x[(L + R) / 2])
        {
            L = (L + R) / 2 + 1;
        }
        else
        {
            cout << "Array above doesn't contain element with value "<< search_val;
        }
    }
}

int main()
{
    cout << "Bubble Sort & Search" << endl;

    unsigned int data[N];

    fill_array(data);
    cout << "data: ";
    print_array(data);
    cout << "shorted data: ";
    bubble_sort(data);
    print_array(data);
    int p = linear_search(10, data);
    if (linear_search(10, data) == -1)
    {
        cout << "Array above doesn't contain element with value 10.\n";
    }
    else
    {
        cout << "One of the index of element which has the value 10 in the array above is [" << p << "].\n" << endl;

    }

    int n;
    cout << "searched element value: n = ";
    cin >> n;
    binary_search(n, data);
    return 0;
}