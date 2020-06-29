#include <iostream>
#include <time.h>
#include <ctime>
#include <algorithm>
using namespace std;

struct tree
{
    tree *left;
    tree *right;
    int value;
    int height;

    tree(int value)
    {
        this->value = value;
        this->left = this->right = NULL;
        this->height = 1;
    }
};

int height(tree *root)
{
    if (root) return root->height;
    return 0;
}

void correctHeight(tree *root)
{
    int hL = height(root->left);
    int hR = height(root->right);
    if (hL>hR) root->height = hL + 1;
    else root->height = hR + 1;
}

int diff(tree *root) //разница высот
{
    return height(root->right) - height(root->left);
}

tree *Left(tree *root)
{
    tree *tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;
    correctHeight(root);
    correctHeight(tmp);
    return tmp;
}

tree *Right(tree *root)
{
    tree *tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;
    correctHeight(root);
    correctHeight(tmp);
    return tmp;
}

tree *balance(tree *root)
{
    correctHeight(root);
    int d = diff(root);

    if (d == 2)
    {
        if (diff(root->right) < 0) root->right = Right(root->right);
        return Left(root);
    }
    if (d == -2)
    {
        if (diff(root->left) > 0) root->left = Left(root->left);
        return Right(root);
    }
    return root;
}

tree *del_min(tree *root)
{
    if (root->left == NULL) return root->right;
    root->left = del_min(root->left);
    return balance(root);
}

tree *MIN(tree *root)
{
    if (root->left) return MIN(root->left);
    return root;
}

tree *MAX(tree *root)
{
    if (root->right) MAX(root->right);
    return root;
}

tree *search(tree *root, int value)
{
    if (root == NULL) return 0;
    if (root->value == value) return root;
    if (value < root->value) return search(root->left, value);
    return search(root->right, value);
}

tree *addTree(tree *root, int value)
{
    if (!root) return new tree(value);
    if (value > root->value) root->right = addTree(root->right, value);
    else if (value < root->value) root->left = addTree(root->left, value);

    return balance(root);
}

tree *del(tree *root, int value)
{
    if (!root) return NULL;
    if (value < root->value) root->left = del(root->left, value);
    else if (value > root->value) root->right = del(root->right, value);
    else
    {
        tree *l = root->left;
        tree *r = root->right;
        delete root;
        if (!r)
            return l;
        tree *min = MIN(r);
        min->right = del_min(r);
        min->left = l;
        return balance(min);
    }
    return balance(root);
}

void Print(tree *root, int r = 0)
{
    if (root == NULL) return;
    Print(root->right, r + 2);
    for (int i = 0; i < r; i++)
    {
        cout << "*";
    }
    cout << root->value << endl;
    Print(root->left, r + 2);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    tree *root = NULL;
    int N, k;
    cout << "Введите количество значений: ";
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> k;
        root = addTree(root, k);
    }
    
    cout << "Вывод дерева:\n";
    Print(root);

    cout << MIN(root)->value << " " << MAX(root)->value << endl;

    for (int i = 0; i < 5; i++)
    {
        k = 50 + rand() % 51; // [50; 100]
        del(root, k);
        Print(root);
        cout << endl << endl;
    }

    cout << MIN(root)->value << " " << MAX(root)->value << endl;
}