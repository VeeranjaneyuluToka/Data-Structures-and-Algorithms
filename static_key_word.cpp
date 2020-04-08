#include <iostream>

using namespace std;

void normal_var_demo(){
	int i = 0;
	cout << i << endl;

	i++;
}

void static_var_demo(){
	static int i = 0;
	cout << i << endl;
	i++;
}

class static_exp{
	public:
		static int i;

		static_exp();
		~static_exp();

		static void print_msg();
		static_exp& test();
	private:
		int var;
		static float stat_var;
};

static_exp::static_exp(){
	var = 10;
	//stat_var = 20.03; //gives error
	cout << "inside constructor" << endl;
}

static_exp::~static_exp(){
	cout << "inside destructor" << endl;
}

int static_exp::i = 1;
float static_exp::stat_var = 20.0;

void static_exp::print_msg(){
	cout << "inside static member functions" << endl;
	//cout << var << endl; // trying to access normal member variable from static member function (gives error)
	cout << stat_var << endl; // trying to access static member variable from static member function
}

static_exp& static_exp::test(){
	static_exp::i++;
	cout << static_exp::i << " ";
	return *this;
}

void normal_class_obj_test(){
	int count = 0;
        if (count == 0){
        static_exp se1;
        static_exp se2;

        /*
        se1.i = 1;
        se2.i = 2; gives error "undefined referece to static_exp::i" */

        cout << se1.i << endl;}
}

void static_class_obj_test(){
	int count = 0;
	if (count == 0){
		static static_exp se1;
		cout << se1.i << endl;
	}
}

class base{
	private:
		int x;
	public:
		base(int x_){
			x = x_;
		}
		int get(){
			return x;
		}
};

class derive{
	private:
		static base b_obj;
	public:
		static int get(){
			return b_obj.get();
		}
};

base derive::b_obj(0);

int main(){
	cout << "normal variable"<<endl;
	for (int i = 0; i < 3; i++)
		normal_var_demo();

	cout << "static variable" << endl;
	for (int i = 0; i < 3; i++)
		static_var_demo();

	cout << "class experimentations"<<endl;
	normal_class_obj_test();

	static_class_obj_test();

	static_exp::print_msg();

	static_exp se_obj;
	se_obj.test().test().test().test();
	cout << endl;

	derive d_obj;
	cout << d_obj.get() << endl;

	cout << "end of main" << endl;
	return 0;
}
