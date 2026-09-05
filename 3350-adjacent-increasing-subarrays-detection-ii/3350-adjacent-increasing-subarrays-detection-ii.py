class Solution:
    def maxIncreasingSubarrays(self, arr: List[int]) -> int:
        mp ={}
        n = len(arr)
        mp[n-1]=1
        maxi=0
        
        for i in range(n-2,-1,-1):
            if (arr[i]< arr[i+1]):
                mp[i]=mp[i+1]+1
            else:
                mp[i]=1
        
        prev=1
        for i in range(1,n):
            mini= min(prev,mp[i])
            maxi=max(mini,maxi)

            if (arr[i]>arr[i-1]):
                prev= prev+1
            else:
                prev=1
        return maxi