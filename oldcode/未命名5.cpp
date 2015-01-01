/**
 * 这道题重点在于空间的利用
 * */
 #include <stdlib.h>
 #include <stdio.h>
 

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i=0,j=0,k;
        for(k=n+m-1;k>=n;k--){//挪m个元素
            A[k]=A[k-n];
        }
        k=0;
        i=n;
        while(i!=m+n-1 && j!=n-1){
            if(A[i]>B[j]){
                A[k]=B[j];
                k++;j++;
            }
            else{
                A[k]=A[i];
                i++;k++;
            }
        }
        while(i!=m+n-1){
            A[k]=A[i]; 
            i++;k++;
        }
        while(j!=n-1){
            A[k]=B[j];
            j++;k++;
        }
    }
};
    int main(){
		int A[1]={1};int B[0]; 
		Solution s=new Solution();
		s.merge(A,1,B,0);
		getchar();
	}
