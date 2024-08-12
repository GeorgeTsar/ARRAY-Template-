#include<iostream>
#include<time.h>
using namespace std;

template<class T>
class Array
{
	T* arr = nullptr;
	int size;
public:
	Array();
	void output();
	~Array();
	int get_size() const
	{
		return size;
	}
	void set_size(int s, int grow);
	int get_upper_bound();
	void is_empty();
	void free_extra();
	void remove_all();
	T get_at(int index);   // Получение определённого элемента (по индексу)
	void set_at(int index, T el);
	T operator[](int index);
	void add(T el);
	T append(T first, T second);
	T operator=(const Array& T);
	void get_data();   // Получение адреса массива с данными;
	void insert_at(int index, T el);   // Вставка элемента(-ов) в заданную позицию
	void remove_at(int index);   // Удаление элемента с заданной позиции
};


template<class T>
Array<T>::Array()
{
	size = 10;
	arr = new T[10];
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100 * 1.2;
	}
}

template<class T>
void Array<T>::output()
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl << endl;
}

template<class T>
Array<T>::~Array()
{
	delete[] arr;
}

template<class T>
void Array<T>::set_size(int s, int grow)
{
	if (size < s)
	{
		size = size + grow;
		delete[] arr;
		arr = new T[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = rand() % 100 * 1.2;
		}
	}
	else (size >= s)
	{
		size = s;
		delete[] arr;
		arr = new T[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = rand() % 100 * 1.2;
		}
	}


}

template<class T>
int Array<T>::get_upper_bound()
{
	return size - 1;
}

template<class T>
void Array<T>::is_empty()
{
	if (arr != nullptr)
	{
		cout << "The array is full";
	}
	else
	{
		cout << "The array is empty";
	}
}

template<class T>
void Array<T>::remove_all()
{
	delete[] arr;
}


template<class T>
T Array<T>::get_at(int index)
{
	return arr[index];
}

template<class T>
void Array<T>::set_at(int index, T el)
{
	arr[index] = el;
}

template<class T>
void Array<T>::add(T el)
{
	size = size + 1;
	arr[size - 1] = el;
}

template<class T>
T Array <T>::operator=(const Array& b)
{
	//1. Проверка ситуации a = a (адрес объекта слева равен адресу объекта справа)
	if (this == &b)
	{
		return *this;
	}
	//2. Проверка состояния левостороннего объекта
	if (this->arr != nullptr)
	{
		delete[] arr;
	}
	size = b.size;
	arr = new T[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = b.arr[i];
	}
	//3. Из перегруженного метода необходимо вернуть сам объект после изменения
	return *this;
}

template<class T>
T Array<T>::operator[](int index)
{
	return arr[index];
}

template<class T>
void Array<T>::get_data()
{
	cout << &arr[0] << endl;
}

template<class T>
T Array<T>::append(T a, T b)
{
	int new_size = a.size + b.size;
	arr = new T[new_size];
	for (int i = 0; i < a.size; i++)
	{
		arr[i] = a.arr[i];
	}
	for (int i = 0; i > a.size && i < b.size; i++)
	{
		arr[i] = b.arr[i];
	}
	return arr;
}

template<class T>
void Array<T>::insert_at(int index, T el)
{
	size = size + 1;
	T new_arr = new T[size];
	for (int i = 0; i < index; i++)
	{
		new_arr[i] = arr[i];
	}
	new_arr[index] = el;
	for (int i = index; i < size; i++)
	{
		new_arr[i] = arr[i];
	}
}

template<class T>
void Array<T>::remove_at(int index)
{
	arr[index] = 0;
}





void main()
{
	srand(time(0));
	Array<int> obj_1;
	obj_1.output();

	Array<char> obj_2;
	obj_2.output();

	Array<double>obj_3;
	obj_3.output();

	cout << obj_3[2] << endl;

	obj_1.set_at(1, 111);
	obj_1.output();
	
	obj_1.add(555);
	obj_1.output();

	obj_1.get_data();

	obj_1.remove_at(1);
	obj_1.output();

}