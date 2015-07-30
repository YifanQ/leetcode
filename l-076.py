class Solution:
    # @param {string} s
    # @param {string} t
    # @return {string}
    def minWindow(self, s, t):
        # s_0
        t_set = set(t)
        s_0 = []
        for i in xrange(len(s)):
            if s[i] in t_set:
                s_0.append( (s[i], i) )

        if len(s_0) < len(t):
            return ""

        # t_stat
        t_stat = [0]*128
        for ch in t:
            t_stat[ord(ch)] = t_stat[ord(ch)] + 1

        p = 0
        q = 0
        curr = [0]*128
        sum0 = 0; sum1 = 0
        best = len(s) + 1
        result = None

        while True:
            while q < len(s_0):
                ch = ord(s_0[q][0])
                if curr[ch] < t_stat[ch]:
                    sum1 = sum1 + 1
                curr[ch] = curr[ch] + 1; sum0 = sum0 + 1
                if sum1 == len(t):
                    break
                q = q + 1
            if sum1 < len(t):
                break

            while True:
                ch = ord(s_0[p][0])
                if curr[ch] > t_stat[ch]:
                    p = p + 1; curr[ch] = curr[ch] - 1; sum0 = sum0 - 1
                else:
                    break

            if s_0[q][1]+1 - s_0[p][1] < best:
                best = s_0[q][1]+1 - s_0[p][1]
                result =  s_0[p][1], s_0[q][1]+1

            # move ahead on p, make sum1 -1
            ch = ord(s_0[p][0])
            print curr[ch] == t_stat[ch]
            p = p + 1; curr[ch] = curr[ch] - 1; sum0 = sum0 - 1
            sum1 = sum1 - 1
            # move ahead on q
            q = q + 1

        return s[result[0] : result[1]] if best<=len(s) else ""
