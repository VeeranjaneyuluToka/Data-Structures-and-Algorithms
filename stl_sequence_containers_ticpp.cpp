#include "stl_sequence_containers_ticpp.h"

void set_simple_int_test(){
	set<int> intset;
	for (int i = 0; i < 25; i++){
		for (int j = 0; j < 10; j++){
			intset.insert(j);
		}
	}

	copy(intset.begin(), intset.end(), ostream_iterator<int> (cout, "\n"));
}

void set_simple_string_test(){
	ifstream source("/home/dell/Downloads/DSA/cpp/text.txt");
	if (source.is_open())
		cout << "file is opened" << endl;
	else{
		cout << "file is not opened" << endl;
	}

	string word;
	set<string> words;
	while (source >> word)
		words.insert(word);
	copy(words.begin(), words.end(), ostream_iterator<string> (cout, "\n"));
	cout << "Number of unique words:" << words.size() << endl;
}

//shape class and derived classes implementations
shape::~shape(){
	cout << "virtual destructor" << endl;
}

void circle::draw(){
	cout << "in circle draw function" << endl;
}

circle::~circle(){
	cout <<"in circle destructor"<<endl;
}

void traingle::draw(){
	cout <<"in traingle draw function" << endl;
}

traingle::~traingle(){
	cout << "in traingle destructor" << endl;
}

void square::draw(){
	cout << "in square draw function" << endl;
}

square::~square(){
	cout <<"in square destructor" << endl;
}

void shape_classes_test(){
	typedef vector<shape*> container;
	typedef container::iterator itr;

	container shapes;
	shapes.push_back(new circle);
	shapes.push_back(new traingle);
	shapes.push_back(new square);

	for (itr i = shapes.begin(); i != shapes.end(); i++)
		(*i)->draw();

	for (itr i = shapes.begin(); i!= shapes.end(); i++)
		delete *i;
}

void string_container_test(){
	ifstream in("/home/dell/Downloads/DSA/cpp/text.txt");
	if (in.is_open())
		cout<<"file is opened" << endl;
	else
		cout << "file is not opened" << endl;

	typedef vector<string> container;
	string line;
	container strings;
	while(getline(in, line)){
		strings.push_back(line);
	}
	int i = 1;
	container::iterator w;
	for (w=strings.begin(); w!= strings.end(); w++){
		ostringstream ss;
		ss << i++;
		*w = ss.str()+": "+*w;
	}

	copy(strings.begin(), strings.end(), ostream_iterator<string>(cout, "\n"));
}

int main(){
	set_simple_int_test();
	set_simple_string_test();

	shape_classes_test();

	string_container_test();
	return 0;
}
