#include <stdio.h>
#include <string>

class A{
public:
	A(){
		m_data = new char(100);
		printf("default constructor\n");
	}
	A(const A& other){
		m_data = new char(100);
		memcpy(m_data, other.m_data, strlen(other.m_data));
		printf("copy constructor\n");
	}
	~A(){
		if(m_data != NULL){
			delete m_data;
			m_data=NULL;
			printf("destructor\n");
		}
	}
private:
	char *m_data;	// pointer
};

int main(int argc, char const *argv[])
{
	A a;
	A b(a); // use memberwise copy
	return 0;
}
// bitwise-copy-crash(25789,0x7fff74a78310) malloc: *** error for object 0x7ff628c038f0: pointer being freed was not allocated