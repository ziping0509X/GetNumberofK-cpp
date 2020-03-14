//剑指offer
//统计一个数字在排序数组中出现的次数。

#include <vector>
#include <iostream>

using namespace std;

class Solution1 {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int len=data.size();
        int i=0;
        while(data[i]!=k){
            i++;
        }
        int j=0;
        while(data[i]==k){
            j++;
            i++;
        }
        return j;

    }
};
//这是自己设计的比较笨拙的方法，但本题是要使用二分查找；


class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int len=data.size();
        int start=0,end=len-1;
        int result;
        int first=GetFirstK(data,k,start,end);
        int last=GetLastK(data,k,start,end);
        return result=last-first+1;

    }

private:
    int GetFirstK(vector<int>data,int k,int start,int end){
        int middindex=(start+end)/2;
        int midddata=data[middindex];
        if(midddata==k){
            if(data[middindex-1]!=k)
                return middindex;
            else
                end=middindex-1;

        }
        else if(midddata>k)
            end=middindex-1;
        else
            start=middindex+1;
        return GetFirstK(data,k,start,end);
    }

private:
    int GetLastK(vector<int> data,int k,int start,int end){
        int middindex=(start+end)/2;
        int midddata=data[middindex];

        if(midddata==k){
            if(data[middindex+1]!=k)
                return middindex;
            else
                start=middindex+1;
        }
        else if(midddata>k)
            end=middindex-1;
        else
            start=middindex+1;
        return GetLastK(data,k,start,end);
    }



};

//使用Solution2提示内存超出限制！

int main(void){
    int a[8]={1,2,3,3,3,3,4,5};
    vector<int> data;
    for(int i=0;i<8;i++){
        data.push_back(a[i]);
    }
    Solution solution;
    int k=solution.GetNumberOfK(data,3);
    cout<<k<<endl;
}

//方法正确，但编译器一直提示内存使用过多；