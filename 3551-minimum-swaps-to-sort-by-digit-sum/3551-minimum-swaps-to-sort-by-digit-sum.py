class Solution(object):
    def minSwaps(self, nums):
        n=len(nums)
        def sum(x):
            res=0
            while x:
                lst=x%10
                res+=lst
                x//=10
            return res
        
        arr=sorted(nums,key=lambda x: (sum(x),x))
        pos={arr[i]:i for i in range(n)}
        ans=0
        for i in range(n):
            while nums[i]!=arr[i]:
                j=pos[nums[i]]
                nums[i],nums[j]=nums[j],nums[i]
                ans+=1

        return ans

        
        