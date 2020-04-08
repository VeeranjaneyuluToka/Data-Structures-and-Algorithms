#include "templates_learning.h" 

/*
 * Function templates
 */
template <typename T> T myMax(T x, T y){
	return x > y ? x : y;
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

//template function with static variables
template<typename T> void func_static_var(const T& x){
	static int i = 0;
	i += 1;
	cout << i << endl;
	return;
}

void static_temp_func_test(){
	func_static_var<int>(10);
	func_static_var<double>(20.01);
}

/*
 * Class templates
 * */
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
template<class T, class U> A<T, U>::A(){
	cout << "multi arg default constructor called" << endl;
}

//default parameters
template<class T, typename U> DP<T, U>::DP(){
	cout << "DP defualut constructor called"<<endl;
}

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

template<class T>static_test<T>::static_test(){
	count++;
}

template<class T> int static_test<T>::count = 0;

void static_temp_class_test(){
	static_test<int> a;
	cout << static_test<int>::count << endl;
	static_test<double> b;
	cout << static_test<double>::count << endl;
	static_test<int> c;
	cout << static_test<int>::count << endl;
}

/* class Array definations
 */
template<typename T> nArray<T>::nArray(int i){
	len_ = i;
	cout << "in arg constructor: " << len_ << endl;
}

template<typename T> nArray<T>::nArray(const nArray& arrObj){

}

template<typename T> nArray<T>::~nArray(){
	cout << "int nArray destructor" << endl;
}

template<typename T> int nArray<T>::len()const{
}

template<typename T> T const& nArray<T>::operator[](int i) const{
}

template<typename T> T& nArray<T>::operator[](int i){
}

template<typename T> nArray<T>& nArray<T>::operator=(const nArray<T>& tmobj){
}

//driver function
int main(){
	//function template test
	cout << "### function templates testing ###" << endl;
	simple_max_func_template();
	buble_sort_func_template();
	cout << "func template with static variable test case" <<endl;
	static_temp_func_test();
	cout << endl;

	//class template test
	cout << "### class templates testing ###" << endl;
	class_temp_check();
	cout << "class template with static variable test case"<<endl;
	static_temp_class_test();

	nArray<int> a_int;
	nArray<double> a_d;
	nArray<float> a_f;
	nArray<string> a_str;
	nArray<nArray<int>> arr_arr;
}
