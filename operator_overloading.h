#include <iostream>

using namespace std;

class integer{
	int i;
	public:
		integer(int ii);
		const integer operator+(const integer& rv) const;
		integer & operator+=(const integer& rv);
};
