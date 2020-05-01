#include "operator_overloading.h"

integer::integer(int ii):i(ii){
}

const integer integer::operator+(const integer& rv) const{
	cout << "operator+" << endl;
	return integer(i+rv.i);
}

integer& integer::operator+=(const integer& rv){
	cout << "operator+=" << endl;
	i += rv.i;
	return *this;
}

void pre_user_defined_overloading_test(){
	cout << "built-in types:" << endl;
	int i = 1, j = 2, k = 3;
	k += i + j;

	cout << "user-defined types:" << endl;
	integer ii(1), jj(2), kk(3);
	kk += ii + jj;
}

int main(){
	pre_user_defined_overloading_test();
	return 0;
}
