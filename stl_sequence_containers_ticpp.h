#include<iostream>
#include <set>
#include <iterator>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class shape{
	public:
		virtual void draw() = 0;
		virtual ~shape();
};

class circle:public shape{
	public:
		void draw();
		~circle();
};

class traingle:public shape{
	public:
		void draw();
		~traingle();
};

class square:public shape{
	public:
		void draw();
		~square();
};
