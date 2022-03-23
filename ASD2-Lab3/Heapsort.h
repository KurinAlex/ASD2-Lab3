#pragma once

template<typename T>
void swap(T* a, T* b)
{
    T tmp = *a;
    *a = *b;
    *b = tmp;
}

template<typename T>
void siftDown(int i, int n, T* l)
{
    T d = *(l + i - 1);
    int child;
    while (i <= n / 2)
    {
        child = 2 * i;
        if (child < n && *(l + child - 1) < *(l + child))
        {
            child++;
        }
        if (!(d < *(l + child - 1)))
        {
            break;
        }
        *(l + i - 1) = *(l + child - 1);
        i = child;
    }
    *(l + i - 1) = d;
}

template<typename T>
void heapsort(T* l, T* r)
{
    int n = r - l;
    for (int i = n / 2; i >= 1; i--)
    {
        siftDown(i, n, l);
    }
    for (int i = n; i > 1; i--)
    {
        swap(l, l + i - 1);
        siftDown(1, i - 1, l);
    }
}