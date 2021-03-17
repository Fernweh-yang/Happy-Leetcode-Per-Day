class Solution:
    def minWindow(self, s: str, t: str) -> str:
        need=collections.defaultdict(lambda:0)   #defaultdict:当键不存在时,自动实例化一个值作为默认值
        flag=collections.defaultdict(lambda:0)
        for c in t:         
            need[c]+=1          #还需要的字符的数目
            flag[c]+=1          #用于判断是否是需要的字符
        count = 0
        l=0
        min_l=0
        min_size=len(s)
        for r,c in enumerate(s):         #enumerate返回的是一个元组(1,c)所以要2个遍历元素,第一个是序号,第二个是s对应的值
            if flag[c]:
                need[c]-=1
                if need[c]>=0:
                    count+=1               
            while count==len(t):
                if r-l <min_size:
                    min_l=l
                    min_size=r-l
                
                if flag[s[l]]:
                    need[s[l]]+=1 
                    if need[s[l]]>0:
                        count-=1
                l+=1
        return '' if min_size >=len(s) else s[min_l:min_l+min_size+1]
        
       
