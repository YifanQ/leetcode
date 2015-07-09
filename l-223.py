class Solution:
    # @param {integer} A
    # @param {integer} B
    # @param {integer} C
    # @param {integer} D
    # @param {integer} E
    # @param {integer} F
    # @param {integer} G
    # @param {integer} H
    # @return {integer}
    def computeArea(self, A, B, C, D, E, F, G, H):
        xL = [A, C, E, G]
        yL = [B, D, F, H]
        xL.sort(); yL.sort()
        # xL = self.unique_sorted(xL)
        # yL = self.unique_sorted(yL)
        self.unique_sorted_inplace(xL)
        self.unique_sorted_inplace(yL)


        xD = {xL[i]:i for i in xrange(len(xL))}
        yD = {yL[i]:i for i in xrange(len(yL))}
        # occ = [[0]*(len(xL)-1)]*(len(yL)-1)
        occ = [[0 for x in xrange(len(yL)-1)] for x in xrange(len(xL)-1)]

        rec1 = [ [xD[ax], yD[ay]] for ax, ay in [(A, B), (C, D)] ]
        rec2 = [ [xD[ax], yD[ay]] for ax, ay in [(E, F), (G, H)] ]
        # print occ
        for rec in [rec1, rec2]:
            for i in xrange(rec[0][0], rec[1][0]):
                for j in xrange(rec[0][1],rec[1][1]):
                    occ[i][j] = 1;

        area = 0.0
        for i in xrange(0, len(xL)-1):
            for j in xrange(0, len(yL)-1):
                if occ[i][j] == 1:
                    area = area + (xL[i+1]-xL[i])*(yL[j+1]-yL[j])
        # print area
        return area


    # http://stackoverflow.com/questions/480214/how-do-you-remove-duplicates-from-a-list-in-python-whilst-preserving-order
    def unique_unsorted(seq):
        seen = set()
        seen_add = seen.add
        return [ x for x in seq if not (x in seen or seen_add(x))]

    def unique_sorted(self, seq):
        if len(seq)==0:
            return []
        uniqueList = [seq[0]]
        for i in xrange(1, len(seq)):
            if seq[i]!=seq[i-1]:
                uniqueList.append(seq[i])
        return uniqueList

    def unique_sorted_inplace(self,seq):
        if len(seq)==0:
            return []
        offset = 0;
        for i in xrange(1, len(seq)):
            if seq[i]!=seq[i-offset-1]:
                seq[i-offset] = seq[i]
            else:
                offset = offset + 1
        del seq[len(seq)-offset:]


x = Solution()
print x.computeArea(-3, 0, 3, 4, 0, -1, 9, 4)


