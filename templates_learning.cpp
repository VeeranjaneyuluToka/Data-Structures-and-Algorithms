#include <iostream>

using namespace std;

/*
 * Function templates
 */

// max checking function
template<class T> T myMax(T x, T y){
	return (x>y)?x:y;
}

void simple_max_func_template(){
	cout << myMax<int>(3, 7) << endl;
	cout << myMax<char>('g', 'e')<<endl;
}

//buble sort function
template <typename T> void bublesort(T a[], int n){
	for (int i =0; i < n; i++){
		for (int j = i+1; j < n; j++){
			if (a[i] > a[j]){
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

void buble_sort_func_template(){
	int arr[] ={ 5, 2, 1, 4, 9, 8};
	int n = sizeof(arr) / sizeof(arr[0]);
	bublesort(arr, n);

	for (int i = 0; i < n; i++){
		cout<<arr[i] <<" ";
	}
	cout << endl;
}

/*
 * Class templates
 * */
template<typename T>
class Array{
	private:
		T *ptr;
		int size;
	public:
		Array(T arr[], int s);
		void print();
};

template<typename T> Array<T>::Array(T arr[], int s){
	ptr = new T[s];
	size = s;
	for (int i = 0; i < size; i++){
		ptr[i] = arr[i];
	}
}

template<typename T> void Array<T>::print(){
	for (int i = 0; i < size; i++){
		cout << *(ptr+i) << " ";
	}
}

// multiple parameters
template <class T, class U> class A{
	T x;
	U y;
	public:
	A(){
		cout << "multi arg default constructor called" << endl;
	}
};

//default parameters
template<typename T, typename U=char> class DP{
	T x;
	U y;
	public:
	DP(){
		cout << "DP defualut constructor called"<<endl;
	}
};

void class_temp_check(){
	int arr[5] = {1, 2, 3, 4, 5};
	Array<int> a(arr, 5);
	a.print();
	cout << endl;

	A< char, int> a_obj1;
	A<float, int> a_obj2;

	DP <int> dp_obj1;
	DP <float, double> dp_obj2;
}

int main(){
	//function template test
	simple_max_func_template();
	buble_sort_func_template();

	//class template test
	cout << endl;
	class_temp_check();
}
