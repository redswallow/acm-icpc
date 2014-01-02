#include <iostream>
using namespace std;

int atoi(const char* str){
	if (!str) return 0;

	long n=0,sign=1,i=0;
	while(str[i]==' ') i++;
	if (str[i]=='-'){
		i++;sign=-1;
	}else if(str[i]=='+') i++;
	for (; str[i]!='\0'; ++i)
	if (str[i]<'0' || str[i]>'9') break;
	else {
		n=n*10+str[i]-'0';
	}
	n=sign*n;
	if (n>2147483647) return 2147483647;
	if (n<-2147483648) return -2147483648;
	return n;
}

int main(int argc, char const *argv[])
{
	cout<<atoi("123")<<endl;
	cout<<atoi("-123")<<endl;
	cout<<atoi("")<<endl;
	cout<<atoi(NULL)<<endl;
	cout<<atoi("-1-2")<<endl;
	cout<<atoi("+1-2")<<endl;
	cout<<atoi("+12")<<endl;
	cout<<atoi("a12")<<endl;
	cout<<atoi(" 012a43")<<endl;
	cout<<atoi("2147483648")<<endl;
	return 0;
}