class Solution {

private: 

    void merge(vector<int>& a,int l,int mid,int r)
    {
        int i,j,k;
        int n1 = mid-l+1;
        int n2 = r-mid;

        vector<int> L(n1), R(n2);

        for(i=0;i<n1;i++) 
            L[i] = a[l+i];

        for(j=0;j<n2;j++) 
            R[j] = a[mid+1+j];

        i=0,j=0,k=l;

        while(i<n1 && j<n2)
        {
            if(L[i] <= R[j])
            {
                a[k] = L[i++];
            }
            else
            {
                a[k] = R[j++];
            }
            k++;
        }

        while(i<n1)
        {
            a[k++] = L[i++];
        }

        while(j<n2)
        {
            a[k++] = R[j++];
        }
    }

    void merge_sort(vector<int>& a, int l,int r)
    {
        int mid = (l+r)/2;
        if(l<r)
        {
            merge_sort(a,l,mid);
            merge_sort(a,mid+1,r);

            merge(a,l,mid,r);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        merge_sort(nums,l,r);

        return nums;
    }
};