#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target) {
    int f=0,r=numbers.size()-1,sum=0;
    vector<int> result;
    while(f<=r){
        sum=numbers[f]+numbers[r];
        if (sum==target){
            result.push_back(numbers[f]);
            result.push_back(numbers[r]);
            return result;
        }else if(sum>target) r--;
        else f++;
    }
    return result;
}

int main(){
    int testData[] = {2,7,11,15};
    int target=9;
    vector<int> numbers(testData, testData + sizeof(testData)/sizeof(int));
    vector<int> result=twoSum(numbers,target);
    vector<int>::iterator it;
    for (it = result.begin(); it != result.end(); ++it)
        cout<<*it<<" ";
    cout<<endl;
    return 0;
}
