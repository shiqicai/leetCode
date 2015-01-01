int main(){



class Solution {
public:
class Solution {
public:
    bool isInt(string s1,int l1,string s2,int l2,string s3,int l3){
        int len1=s1.length();
        int len2=s2.length();
        int isMatch;
        if(l1==len1 && l2==len2)  return true;
        if(l1==len1){//s1到尾了
            isMatch=true;
            while(l2!=len2){
                if(s2[l2]!=s3[l3]){
                    isMatch=false;
                    break;
                }
                l2++,l3++;
            }
            return isMatch;            
        }
        if(l2==len2){//s1到尾了
            isMatch=true;
            while(l1!=len1){
                if(s1[l1]!=s3[l3]){
                    isMatch=false;
                    break;
                }
                l1++;l3++;
            }
            return isMatch;            
        }
                
        if(s1[l1]!=s2[l2]){
            if(s1[l1]==s3[l3]){
                return isInt(s1,l1+1,s2,l2,s3,l3+1);
            }else if(s2[l2]==s3[l3]){
                return isInt(s1,l1,s2,l2+1,s3,l3+1);
            }else
                return false;
        }else{
            if(s1[l1]==s3[l3])
                return isInt(s1,l1+1,s2,l2,s3,l3+1) || isInt(s1,l1,s2,l2+1,s3,l3+1);
            else 
                return false;
        }
    }
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function  
        if(s1.length() + s2.length() < s3.length())
        {
            return false;
        }
        return isInt(s1,0,s2,0,s3,0);
    }
};
};
