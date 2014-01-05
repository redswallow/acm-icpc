int findLeftBound(int A[], int n, int target){
    int l=0, r=n-1, ans(-1);
    while (l<=r){
        int mid=(l+r)/2;
        if (A[mid]==target){
            ans=mid;r=mid-1;
        }
        else if (A[mid]>target) r=mid-1;
        else l=mid+1;
    }
    return ans;
}
int findRightBound(int A[], int n, int target){
    int l=0, r=n-1,ans(-1);
    while (l<=r){
        int mid=(l+r)/2;
        if (A[mid]==target){
            ans=mid;l=mid+1;
        }else if (A[mid]>target) r=mid-1;
        else l=mid+1;
    }
    return ans;
}
vector<int> searchRange(int A[], int n, int target){
    vector<int> range;
    int left=findLeftBound(A, n, target);
    int right=findRightBound(A, n, target);
    range.push_back(left);range.push_back(right);
    return range;
}