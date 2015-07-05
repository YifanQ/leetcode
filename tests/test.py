def reverse(x):
        f = +1
        if x < 0:
            f = -1
            x = -x
        s = str(x)[::-1]
        res = int(s)*f
        if (res < -2**31 or res > 2**31 - 1):
            res = 0
        return res

print reverse(321)
