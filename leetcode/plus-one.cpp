#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int> &digits) {
	int z=1,cur=digits.size()-1;
	std::vector<int> result;
	while(z>0 && cur>=0){
		int x=digits[cur]+z;
		digits[cur]=x%10;
		z=x/10;
		cur--;
	}
	if (z>0) digits.insert(digits.begin(),1);
	return digits;
}

int main(int argc, char const *argv[])
{
	std::vector<int> digits;
	digits.push_back(9);
	digits.push_back(9);
	digits.push_back(9);
	digits=plusOne(digits);
	for(int i=0;i<digits.size();i++)
	{
		cout<<digits[i];
	}
	cout<<endl;
	return 0;
}