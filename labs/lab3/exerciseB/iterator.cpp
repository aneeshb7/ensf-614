// iterator.cpp
// ENSF 614 - Lab 3, Ex B

#include <iostream>
#include <assert.h>
#include "mystring2.h"

using namespace std;

template <class T>
class Vector {
public: 

  class VectIter{
    friend class Vector;
  private:
    Vector *v; // points to a vector object of type T
    int index;    // represents the subscript number of the vector's
                  // array.
  public:
    VectIter(Vector& x);
 
    T operator++();
    //PROMISES: increments the iterator's indes and return the 
    //          value of the element at the index position. If
    //          index exceeds the size of the array it will 
    //          be set to zero. Which means it will be circulated
    //          back to the first element of the vector.


    T  operator++(int);
    // PRIMISES: returns the value of the element at the index
    //           position, then increments the index. If
    //           index exceeds the size of the array it will 
    //           be set to zero. Which means it will be circulated
    //           back to the first element of the vector.

    T  operator--();
    // PROMISES: decrements the iterator index, and return the
    //           the value of the element at the index. If
    //           index is less than zero it will be set to the 
    //           last element in the aray. Which means it will be
    //           circulated to the last element of the vector.

    T  operator--(int);
    // PRIMISES: returns the value of the element at the index
    //           position, then decrements the index. If
    //           index is less than zero it will be set to the 
    //           last element in the aray. Which means it will be
    //           circulated to the last element of the vector.

    T operator *();
    // PRIMISES: returns the value of the element at the current 
    //           index position.
  };

  Vector(int sz); 
  ~Vector();

  T & operator[](int i);
  // PRIMISES: returns existing value in the ith element of 
  //           array or sets a new value to  the ith element in
  //           array. 
  
	void ascending_sort();
  // PRIMISES: sorts the vector values in ascending order. 
	
private:
  int *array;               // points to the first element of an array of T
  int size;               // size of array
  void swap(int&, int &); // swaps the values of two elements in array
public:
};

template <class T>
void Vector<T>::ascending_sort()
{
	for(int i=0; i< size-1; i++)
		for(int j=i+1; j < size; j++)
			if(array[i] > array[j])
				swap(array[i], array[j]);
}

template <class T>
void Vector<T>::swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

template <class T>
T Vector<T>::VectIter::operator *()
{
  return v -> array[index];
}

template <class T>
T Vector<T>::VectIter::operator++()
{
  if (index == v->size-1)
    index = 0;
  else
    index++;
  return v->array[index];
}

template <class T>
T Vector<T>::VectIter::operator++(int)
{
  int tmp = v->array[index];
  if (index == v->size-1)
    index = 0;
  else
    index++;
  return tmp;
}

template <class T>
T Vector<T>::VectIter::operator--()
{
  if (index == 0) 
    index = v->size-1;
  else 
    index--;
  return v->array[index];
}

template <class T>
T Vector<T>::VectIter::operator--(int)
{
  int tmp = v->array[index];
  if (index == 0) 
    index = v->size-1;
  else 
    index--;
  return tmp;
}

template <class T>
T Vector<T>::VectIter::operator *()
{
  return v->array[index];
}

template <class T>
Vector<T>::VectIter::VectIter(Vector<T>& x)
{
  v = &x;
  index = 0;
}

template <class T>
Vector<T>::Vector(int sz)
{
  size=sz;
  array = new int [sz];
  assert (array != NULL);
}


template <class T>
Vector<T>::~Vector()
{
  delete [] array;
  array = NULL;
}


template <class T>
T & Vector<T>::operator [] (int i)
{
  return array[i];
}

int main()
{

 Vector<int> x(3);
 x[0] = 999;
 x[1] = -77;
 x[2] = 88;

 Vector<int>::VectIter iter(x);

 cout << "\n\nThe first element of vector x contains: " << *iter; 

 // the code between the  #if 0 and #endif is ignored by
 // compiler. If you change it to #if 1, it will be compiled
 
#if 0
	cout << "\nTesting an <int> Vector: " << endl;
	
	cout << "\n\nTesting sort";
	x.ascending_sort();
	
	for (int i=0; i<3 ; i++)
		cout << endl << iter++;
	
	cout << "\n\nTesting Prefix --:";
	for (int i=0; i<3 ; i++)
		cout << endl << --iter;
	
	cout << "\n\nTesting Prefix ++:";
	for (int i=0; i<3 ; i++)
		cout << endl << ++iter;	
	
	cout << "\n\nTesting Postfix --";
	for (int i=0; i<3 ; i++)
		cout << endl << iter--;
	
	cout << endl;
	
	cout << "Testing a <Mystring> Vector: " << endl;
	Vector<Mystring> y(3);
	y[0] = "Bar";
	y[1] = "Foo";
	y[2] = "All";;
	
	Vector<Mystring>::VectIter iters(y);
	
	cout << "\n\nTesting sort";
	y.ascending_sort();
	
	for (int i=0; i<3 ; i++)
		cout << endl << iters++;
	
	cout << "\n\nTesting Prefix --:";
	for (int i=0; i<3 ; i++)
		cout << endl << --iters;
	
	cout << "\n\nTesting Prefix ++:";
	for (int i=0; i<3 ; i++)
		cout << endl << ++iters;
	
	cout << "\n\nTesting Postfix --";
	for (int i=0; i<3 ; i++)
		cout << endl << iters--;
	
	cout << endl; cout << "Testing a <char *> Vector: " << endl;
	Vector<const char*> z(3);
	z[0] = "Orange";
	z[1] = "Pear";
	z[2] = "Apple";;
	
	Vector<const char*>::VectIter iterchar(z);
	
	cout << "\n\nTesting sort";
	z.ascending_sort();
	
	for (int i=0; i<3 ; i++)
		cout << endl << iterchar++;
	
#endif
	cout << "\nPrgram Terminated Successfully." << endl;
	
	return 0;
}












