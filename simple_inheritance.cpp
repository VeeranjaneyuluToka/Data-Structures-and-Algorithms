#include <iostream>

using namespace std;

class A{
	private:
		int callA;
		void inc(){
			callA++;
		}

	public:
		A(){
			callA = 0;
		}

		int getA(){
			cout << "getA() function" << endl;
			return callA;
		}

	protected:
		void func(int &a){
			cout << "A::func()" << endl;
			a *= 2;
			inc();
		}
};

class B{
	private:
		int callB;
		void inc(){
			callB++;
		}

	public:
		B(){
			callB = 0;
		}

		int getB(){
			cout << "getB() function" << endl;
			return callB;
		}

	protected:
		void func(int &a){
			cout << "B::func()" << endl;
			a *= 3;
			inc();
		}
};

class C{
	private:
		int callC;
		void inc(){
			callC++;
		}

	public:
		C(){
			callC = 0;
		}

		int getC(){
			cout <<"getC() function" << endl;
			return callC;
		}
	
	protected:
		void func(int &a){
			cout << "getC() function" << endl;
			a *= 5;
			inc();
		}
};

class D:public A, public B, public C{
	private:
		int val;
	public:
		D(){
			val = 1;
		}

		int update_val(int new_val){
			cout << "in update_val" << endl;
			int a = new_val;
			while (a%2 == 0){
				a = a/2;
				A::func(val);
			}
			while (a%3 == 0){
				a = a/3;
				B::func(val);
			}
			while (a%5 == 0){
				a = a/5;
				C::func(val);
			}
		}

		void check(int);
};

void D::check(int v){
	update_val(v);
	cout << "value: "<<val << endl;
	cout << getA() << endl;
	cout << getB() << endl;
	cout << getC() << endl;
}

void exp(int nv)
{
	int a = nv;
	//int val = a % 2;
	while (a%2 == 0){
		a = a/2;
		//val = a%2;
		cout << a << endl;
	}
}

int main(){
	D d_obj;
	int new_val = 60;
	d_obj.check(new_val);
	//exp(new_val);
	return 0;
}
