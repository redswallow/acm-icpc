#include <iostream>
#include <string>
#include <deque>
#include "stack.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
	try{
		Stack<int,deque<int> > intStack;
		Stack<string> strStack;
		// int stack
		intStack.push(7);
		cout<<intStack.top()<<endl;
		// string stack
		strStack.push("hello");
		cout<<strStack.size()<<endl;
		strStack.pop();
		strStack.pop();
	}catch (exception const& ex){
		cerr<<ex.what()<<endl;
		return EXIT_FAILURE;
	}
	return 0;
}