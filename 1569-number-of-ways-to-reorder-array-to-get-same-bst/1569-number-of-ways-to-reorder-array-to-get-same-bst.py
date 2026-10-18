class Solution(object):
    def numOfWays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mod=10**9+7
        n=len(nums)
        pt=[[1]*(i+1) for i in range(n+1)]
        def f(nums):
            n=len(nums)
            if n<3: return 1
            root=nums[0]
            lft=[]
            rgt=[]
            for i in range(1,n):
                if nums[i]<root: lft.append(nums[i])
                else: rgt.append(nums[i])
            
            z=pt[n-1][len(lft)]
            x=f(lft)
            y=f(rgt)
            return (((x*y)%mod)*z)%mod

        for i in range(2,n+1):
            for j in range(1,i):
                pt[i][j]=(pt[i-1][j]+pt[i-1][j-1])%mod
        
        return f(nums)-1
        