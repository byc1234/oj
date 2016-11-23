Many of the posts have the same algorithm. In short we can first solve 2 simpler problem

Create the maximum number of one array
Create the maximum number of two array using all of their digits.
For an long and detailed explanation see my blog here.

The algorithm is O((m+n)^3) in the worst case. It runs in 22 ms.

    //get the max k-length number of array nums ...
    vector<int> helper(vector<int>& nums, int k){
        int n=nums.size();
        int j=0; // the count of the stacked array 
        vector<int> result(k,0);
        for(int i=0; i<n; i++){
            //result[j-1] stores the top of the stack 
            while(j>0 && n-i+j>k && nums[i]>result[j-1])  j--;
            if(j<k) result[j++]=nums[i];
        }
        return result;
    }

    vector<int> merge(vector<int>& nums1, vector<int>& nums2, int k){
        vector<int> result(k, 0);
        ostringstream num_str1, num_str2;
        string str1, str2;
        for(auto num:nums1)  num_str1 << num;
        for(auto num:nums2)  num_str2 << num;
        str1=num_str1.str();
        str2=num_str2.str();
        for(int i=0, j=0, r=0; r<k; r++){
            result[r] = str1.substr(i).compare(str2.substr(j)) > 0 ? nums1[i++] : nums2[j++];
        }
        return result;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size(), m=nums2.size();
        vector<int> result(k, 0);
        string result_str;
        for(int i=max(0, k-m); i<=k && i<=n; i++){
            vector<int> sub_1 = helper(nums1, i);
            vector<int> sub_2 = helper(nums2, k-i);
            vector<int> candidate = merge(sub_1, sub_2, k);
            ostringstream str_c;
            for(auto number:candidate)  str_c << number;
            if(result_str=="" || str_c.str().compare(result_str) > 0 ){
                result_str=str_c.str();
                result=candidate;
            }
        }
        return result;
    }

