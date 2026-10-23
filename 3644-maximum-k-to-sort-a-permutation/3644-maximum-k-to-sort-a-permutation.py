class Solution:
    def sortPermutation(self, nums: List[int]) -> int:
        v=list()
        for i in range(len(nums)):
            if nums[i]!=i: v.append(nums[i])
        
        if len(v)==0: return 0
        ans=v[0]
        for i in range(1,len(v)):
            ans=ans&v[i]

        return ans

