void Solution::merge(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> C;
    int i = 0;
    int j = 0;
    int m = A.size();
    int n = B.size();
    while(i < m && j<n){
        if(A[i] < B[j]){
            C.push_back(A[i]);
            i++;
        } else {
            C.push_back(B[j]);
            j++;
        }
    }
    while(i < m){
        C.push_back(A[i]);
        i++;
    }
    while(j < n){
        C.push_back(B[j]);
        j++;
    }
    A.clear();
    for (int i : C){
        A.push_back(i);
    }
    
}
