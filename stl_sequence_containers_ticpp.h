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

class Noisy{
	static long create, assign, copycons, destroy;
	long id;
	public:
		Noisy();
		Noisy(const Noisy& rv);
		Noisy& operator=(const Noisy& rv);

		~Noisy();

		friend bool operator<(const Noisy& lv, const Noisy& rv){return lv.id < rv.id;}
		friend bool operator==(const Noisy& lv, const Noisy& rv);
		friend ostream& operator<<(ostream& os, const Noisy& n);

		friend class NoisyReport;
};

struct NoisyGen{
	Noisy operator()();
};

class NoisyReport{
	static NoisyReport nr;
	NoisyReport(); //private constructor
	public:
		~NoisyReport();
};
