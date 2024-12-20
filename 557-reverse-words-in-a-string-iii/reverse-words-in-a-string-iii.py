class Solution:
    def reverseWords(self, s: str) -> str:
        l=s.split()
        s=''
        for i in l:
            s=s+' '+i[::-1]
        return(s[1:])