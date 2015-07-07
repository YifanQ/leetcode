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
        sort(xL); sort(yL)
        xL = unique_sorted(xL)
        yL = unique_sorted(yL)
        xD = {xL[i]:i for i in xrange(len(xL))}
        yD = {yL[i]:i for i in xrange(len(yL))}


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
