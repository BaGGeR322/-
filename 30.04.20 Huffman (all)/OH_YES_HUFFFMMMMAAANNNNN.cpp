#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Node 
{
	char key; // буква
	int frequency; // частота
	Node* left; // левый потомок
	Node* right; // правый потомок
	Node(char val, int freq) 
    {
		key = val;
		left = NULL;
		right = NULL;
		frequency = freq;
	}
};

bool compare(Node* f, Node* s) 
{
	return f->frequency < s->frequency;
}

struct hufftree 
{
	Node* root;
	string* map;
	string str;
	string coding;
	int count_map[256]{ 0 };

	hufftree(string str1) 
    {
		root = NULL;
		str = str1;
		build();
	}

	void build() 
    {
		int arr_count = 0;
		Node** arr = new Node * [256];
		for (int i = 0; i < str.length(); i++)
			count_map[str[i]]++;
		for (int i = 0; i < 256; i++) 
			if (count_map[i]) 
			{
				arr[arr_count] = new Node(i, count_map[i]);
				arr_count++;
			}
		
		int x = arr_count;
		while (arr_count > 1) 
        {
			sort(arr, arr + arr_count, compare);
			arr[0] = merger(arr[0], arr[1]);
			arr_count--;
			arr[1] = arr[arr_count];
		}

		root = arr[0];
		make_map();
	}

	Node* merger(Node* f, Node* s) 
    {
		Node* tmp = new Node('#', f->frequency + s->frequency);
		tmp->left = f;
		tmp->right = s;
		return tmp;
	}

	void make_map() 
    {
		map = new string[256]{ "" };
		intersection(root, "");
	}

	void intersection(Node* node, string coding) 
    {
		if (node->key != '#') map[node->key] = coding;

		if (node->left && node->right) 
        {
			intersection(node->left, coding + '0');
			intersection(node->right, coding + '1');
		}
	}

	bool is_list(string str) 
    {
		return !get_node(str)->left;
	}

	Node* get_node(string str) 
    {
		Node* node = root;
		for (int i = 0; i < str.length(); i++) 
            node = str[i] == '0' ? node->left : node->right;
		return node;
	}

	string code() 
    {
		for (int i = 0; i < str.length(); i++) 
            coding += map[str[i]];
		return coding;
	}

	string decode() 
    {
		string txt = "";
		string res = "";
		for (int i = 0; i < coding.length(); i++) 
        {
			txt += coding[i];
			if (is_list(txt)) 
            {
				res += get_node(txt)->key;
				txt = "";
			}
		}
		return res;
	}
};

int main()
{
    setlocale(LC_ALL, "Russian");
	string text;
    cout << "Введите строку: ";
    getline(cin, text);
	hufftree bt(text);

	cout << "Частоты:\n";
	for (int i = 0; i < 256; i++)
    {
        char k = i;
		if (bt.count_map[i]) 
            cout << k << " : " << bt.count_map[i] << '\n';
    }

    cout << "Кодирование символов:\n";
	for (int i = 0; i < 256; i++)
    {
        char k = i;
		if (bt.map[i] != "") 
            cout << k << " : " << bt.map[i] << '\n';
    }
	string cod = bt.code(), decod = bt.decode();
	cout << "Шифрование:\n" << cod << "\nРасшифровка:\n" << decod;
}