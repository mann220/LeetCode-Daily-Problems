class Solution:
    def findColoredRoot(self, edges: list[list[int]], colors: str) -> int:
        n=len(colors)
        if n==1: return 0
        indegree=[0]*n
        outdegree=[0]*n
        for u,v in edges:
            cu,cv=colors[u],colors[v]
            if cu=='R' and cv=='B': 
                indegree[v]+=1
                outdegree[u]+=1
            elif cv=='R' and cu=='B': 
                indegree[u]+=1
                outdegree[v]+=1
            elif cu=='B' and cv=='W': 
                indegree[v]+=1
                outdegree[u]+=1
            elif cv=='B' and cu=='W': 
                indegree[u]+=1
                outdegree[v]+=1
            elif cu=='W' and cv=='R': 
                indegree[v]+=1
                outdegree[u]+=1
            elif cv=='W' and cu=='R': 
                indegree[u]+=1
                outdegree[v]+=1
            else: return -1

        roots=[]
        for i in range(n):
            if indegree[i]==0: roots.append(i)
            elif indegree[i]>1 or outdegree[i]>2: return -1
        
        if len(roots)==1 and outdegree[roots[0]]>2: return -1
        return roots[0] if len(roots)==1 else -1
