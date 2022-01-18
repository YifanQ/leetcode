## remember to save x as x0 before flipping into y

class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x<0:
            return False

        x0=x
        y=0

        while x>0:
            y=y*10+x%10
            x=x//10
            # print(x,y)

        return y==x0
