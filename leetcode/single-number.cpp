class Solution {
public:
    int singleNumber(int A[], int n) {
        int i,singleNum=0;
        for (i=0;i<n;i++)
            singleNum=singleNum^A[i];
        return singleNum;
    }
};
