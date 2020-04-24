#include "stl_iterator.h"

FileEditor::FileEditor(string filename){
        ifstream in(filename);
        string line;
        while (getline(in, line))
                push_back(line);
}

void FileEditor::write(ostream & out){
        for (iterator w = begin(); w != end(); w++)
                out << *w << endl;
}

void fileEditor_test(){
        string fname = "/home/dell/Downloads/DSA/cpp/text.txt";
        int i = 1;

        FileEditor f(fname);

        FileEditor::iterator w = f.begin();
        while (w != f.end()){
                ostringstream ss;
                ss << i++;
                *w = ss.str() + ": " + *w;
                w++;
        }

        f.write();
}

Z::Z(int ii):i(ii){
}

void Z::g(){
        i++;
}

ostream& operator<<(ostream& os, const Z& z){
        return os << z.i;
}

template<class Cont, class PtrMemFun> void apply(Cont& c, PtrMemFun f){
        typename Cont::iterator it = c.begin();
        while (it != c.end()){
                //(it->*f)();
                ((*it).*f)();
                it++;
        }
}

void iterator_test(){
        ostream_iterator<Z> out(cout, " ");
        vector<Z> vz;

        for (int i =0; i < 10; i++)
                vz.push_back(Z(i));
        copy(vz.begin(), vz.end(), out);
        cout << endl;

        apply(vz, &Z::g);
        copy(vz.begin(), vz.end(), out);
        cout << endl;
}

void reversable_iterator_test(){
        ifstream in("/home/dell/Downloads/DSA/cpp/templates_learning.h");

        string line;
        vector<string> lines;
        while(getline(in, line))
                lines.push_back(line);

        vector<string>::reverse_iterator r;
        for (r = lines.rbegin(); r != lines.rend(); r++)
                cout << *r << endl;
}

int a[]={1, 3, 5, 7, 11, 13, 17, 19, 23};

template <class cont> void frontInsertion(cont& ci){
	copy(a, a+sizeof(a)/sizeof(a[0]), front_inserter(ci));
	copy(ci.begin(), ci.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

template <class cont> void backInsertion(cont& ci){
	copy(a, a+sizeof(a)/sizeof(a[0]), back_inserter(ci));
	copy(ci.begin(), ci.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

template <class cont> void midInsertion(cont& ci){
	typename cont::iterator it = ci.begin();
	it++; it++; it++;
	copy(a, a+sizeof(a)/(sizeof(a[0])*2), inserter(ci, it));
	copy(ci.begin(), ci.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

void insert_diff_position_test(){
	deque<int> di;
	list<int> li;
	vector<int> vi;

	cout << "front insertion" << endl;
	frontInsertion(di);
	frontInsertion(li);
	//frontInsertion(vi);

	di.clear();
	li.clear();
	//vi.clear();

	cout << "back insertion" << endl;
	backInsertion(di);
	backInsertion(li);
	backInsertion(vi);

	cout << "mid insertion" << endl;
	midInsertion(di);
	midInsertion(li);
	midInsertion(vi);
}

void io_stream_iterator_test(){
	ifstream in("/home/dell/Downloads/DSA/cpp/stl_iterator.h");

	istream_iterator<string> init(in), end;
	ostream_iterator<string> out(cout, "\n");
	vector<string> vs;

	copy(init, end, back_inserter(vs));
	copy(vs.begin(), vs.end(), out);

	*out++ = vs[0];
	*out++ = "That's all, folks!";
}

void io_stream_buf_iterator_test(){
	ifstream in("/home/dell/Downloads/DSA/cpp/stl_iterator.h");

	istreambuf_iterator<char> isb(in), end;
	ostreambuf_iterator<char> osb(cout);

	while(isb != end)
		*osb++ = *isb++;
	cout << endl;

	ifstream in2("/home/dell/Downloads/DSA/cpp/stl_iterator.h");

	istreambuf_iterator<char> is(in2), end2;
	ostreambuf_iterator<char> os(cout);

	while (is != end2)
		*os++ = *is++;
	cout << endl;
}

void storage_iterator_test(){
	const int quantity = 10;

	Noisy* np = (Noisy*) new char[quantity * sizeof(Noisy)];
	raw_storage_iterator<Noisy*, Noisy> rsi(np);
	for (int i = 0; i < quantity; i++)
		*rsi++ = Noisy();
	cout << endl;
	copy(np, np+quantity, ostream_iterator<Noisy>(cout, " "));
	cout << endl;

	for (int i = 0; i < quantity; i++)
		(&np[j]->~Noisy();

	delete (char*) np;
}

int main(){
	iterator_test();

	reversable_iterator_test();
	
	insert_diff_position_test();

	io_stream_iterator_test();
}
