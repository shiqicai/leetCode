class Solution {
public:
    bool isInt(string s1,int l1,string s2,int l2,string s3,int l3){
        if(l1==s1.length() && l2==s2.length())  return true;
        if(l1==s1.length())
            if(s2[l2]==s3[l3])
                return isInt(s1,l1,s2,l2+1,s3,l3+1);
            else
                return false;
        if(l2==s2.length())
            if(s1[l1]==s3[l3])
                return isInt(s1,l1+1,s2,l2,s3,l3+1);
            else
                return false;
        if(s1[l1]!=s2[l2]){
            if(s1[l1]==s3[l3]){
                return isInt(s1,l1+1,s2,l2,s3,l3+1);
            }else if(s2[l2]==s3[l3]){
                return isInt(s1,l1,s2,l2+1,s3,l3+1);
            }else
                return false;
        }else{
            return isInt(s1,l1+1,s2,l2,s3,l3+1) || isInt(s1,l1,s2,l2+1,s3,l3+1);
        }
    }
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        return isInt(s1,0,s2,0,s3,0);
    }
};
