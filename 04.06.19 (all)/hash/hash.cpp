// Написать хеш-таблицу методом цепочек
// Построить график времени вполнения алгоритма (ось у) от размера массива (ось х). Для этого нужно сгенерировать массив случайных ключей и значений (порядка миллиона значений),
// вставить их в таблицу, а после по всем имеющимся сгенерированным ключам сделать поиск в таблице. Замерять необходимо именно время поиска.
// Так необходимо сделать для различных max_len (1, 2, 4, 8 , ..., 256, 512, 1024). Построить таблицу можно в любом удобном для вас инструменте.
#include <iostream>
#include <algorithm>
#include <ctime>
#include <stdio.h>
#include <limits.h>
#include <fstream>

using namespace std;
const int max_len = 256; // максимальный размер хеш-таблицы

struct Node
{
    string key;
    string value;
    Node *next = NULL;
    Node *prev = NULL;
    Node(string key, string value)
    {
        this->key = key;
        this->value = value;
    }
};

int Hash(string key) // функция должна возвращать сумму кодов букв по модулю max_len
{
    int sum = 0;
    for (int i = 0; i < key.length(); sum += key[i++]);
    return sum;
}

void set(Node *table[], string key, string value) // функция добавляет пару ключ значение в массив
{
    int k = Hash(key) % max_len;
    Node *tmp = table[k];

    if (table[k] == NULL)
    {
        table[k] = new Node(key, value);
        return;
    }

    table[k] = new Node(key, value);
    table[k]->next = tmp;
    tmp->prev = table[k];
}

string search(Node *table[], string key) //  функция должна возвращать найденное знаечение по ключу иначе NULL
{
    int k = Hash(key) % max_len;
    Node *tmp = table[k];

    while (tmp != NULL)
    {
        if (tmp->key == key)
            return tmp->value;
        tmp = tmp->next;
    }

    return 0;
}

void print(Node *table[]) // вывод
{
    int K = 0;

    for (int i = 0; i < max_len; i++)
    {
        cout << i << ')' << endl;
        Node *tmp = table[i];
        while (tmp != NULL)
        {
            cout << tmp->key << " " << tmp->value << endl;
            tmp = tmp->next;
            K++;
        }
        cout << '\n';
    }
    cout << K;
}

bool get(Node *table[], string key) // функция должна возвращать найденное знаечение по ключу и удалять его из таблицы иначе NULL
{
    int k = Hash(key) % max_len;
    Node *tmp = table[k];

    while (tmp != NULL)
    {
        if (tmp->key == key)
        {
            if (tmp->next != NULL)
            {
                if (tmp != table[k])
                {
                    tmp->next->prev = tmp->prev;
                    tmp->prev->next = tmp->next;
                    delete tmp;
                    return;
                }
                else table[k] = tmp->next;
            }
            tmp->prev->next = NULL;
            delete tmp;
            return;
        }
        tmp = tmp->next;
    }
    cout << "Такого ключа не существует" << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    ifstream file_in1("input.txt");
    Node *table[max_len]{NULL};
    string key;
    string value;
    while (file_in1 >> key, file_in1 >> value) set(table, key, value);
    file_in1.close();
    ifstream file_in2("input.txt");
    int K = 0;
    unsigned int start_time = clock();
    while (file_in2>>key)
    {
        cout << search(table, key) << endl;
        file_in2 >> key;
        K++;
    }
    unsigned int end_time = clock();
    cout << end_time - start_time << endl;
    cout << K;
}