#include <iostream>

using namespace std;

/* function templates */

// max checking function
template<class T> T myMax(T x, T y);

//buble sort function
template <typename T> void bublesort(T a[], int n);

//template function with static variables
template<typename T> void func_static_var(const T& x);

/* class templates */
template<typename T>
class Array{
        private:
                T *ptr;
                int size;
        public:
                Array(T arr[], int s);
                void print();
};

// multiple parameters
template <class T, class U> class A{
	private:
        	T x;
        	U y;
        public:
        	A();
};

//default parameters
template<typename T, typename U=char> class DP{
	private:
        	T x;
        	U y;
        public:
        	DP();
};

template <typename T> class static_test{
        private:
                T val;

        public:
                static int count;
                static_test();

};

template <typename T>
class nArray{
	public:
		nArray(int len = 10);
		~nArray();
		int len() const;
		T const& operator[](int i) const;
		T& operator[](int i);
		nArray(const nArray<T>&);
		nArray<T>& operator=(const nArray<T>&);
	private:
		int len_;
		T* data;
		int check(int i) const;

};
