import os

f = open('l-188.input','r')
if f:
    print "Good!"
s = f.read().replace(',','\n')
f.close()
f2 = open('l-188-1.input','w')
f2.write(s)
f2.close()
