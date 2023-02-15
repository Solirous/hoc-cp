class Solution {
public:
    int prefix[100001],a[100001];
    int bs(int target,int m,int n){
        int lo =0 ,hi = n-1,kq=-1;
        while(hi>=lo){
            int mid = lo + (hi-lo)/2;
        //z   cout<<prefix[mid]-m<< " "<< m<<"\n";
            if(prefix[mid]-m>=target){
                kq = mid;
                hi = mid-1;
            }else{
                lo=mid+1;
            }
        }
        return kq;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        for(int i=0;i<nums.size();i++) a[i]=nums[i];
        prefix[0]=0+a[0];
        for(int i=1;i<nums.size();i++){
            prefix[i]=prefix[i-1]+a[i];
        }
        if(prefix[nums.size()-1]==target){
            return nums.size();
        }
       /* for(int i=0;i<nums.size();++i){
            if(prefix[i]==target){
                return abs(-(i+1));
            }
        }*/

        int res=INT_MAX;
       for(int i=0;i<nums.size();++i) cout<<prefix[i]<<" ";
        cout<<"\n";
        for(int i=0;i<nums.size();i++){
            int idx = bs(target,prefix[i],nums.size());
            if(idx!=-1){
              res = min(res,idx-i);
            }
        }
       // cout<<res<<'\n';
           for(int i=0;i<nums.size();++i){
               if(prefix[i]==target){
                    res = min(res,i+1);
               }
           }

        return (res==INT_MAX?0:res);
    }
};