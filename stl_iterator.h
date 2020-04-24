#include<iostream>
#include <vector>
#include <list>
#include <deque>
#include <fstream>
#include <iterator>
#include <sstream>

using namespace std;

class FileEditor : public vector<string>{
        public:
                //FileEditor(char *filename);
                FileEditor(string filename);
                void write(ostream& out = cout);
};

class Z{
        public:
                Z(int ii);
                void g();
                friend ostream& operator<<(ostream& os, const Z& z);

        private:
                int i;
};

class Noisy{
	long id;
};
