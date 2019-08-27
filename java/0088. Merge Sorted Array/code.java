class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int last1 = nums1.length;
        for(int i=0;i<m;i++){
            nums1[last1-i-1] = nums1[m-i-1];
        }
        int index1 = last1-m;
        int index2 = 0;
        
        
        int index = 0;
        while(index1<last1||index2<n){
            if(index1==last1){
                nums1[index] = nums2[index2];
                index2++;
            }else if(index2==n){
                nums1[index] = nums1[index1];
                index1++;
            }else if(nums1[index1]>nums2[index2]){
                nums1[index] = nums2[index2];
                index2++;
            }else{
                nums1[index] = nums1[index1];
                index1++;
            }
            index++;
        }
        
    }
}
