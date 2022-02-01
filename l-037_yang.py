import sys


class Solution(object):
    # not all functions need self

    def onestep(self, m, i, num, index):
        # find all possible j from set index for a number m in row i
        l = 0
        pj = []
        # print(num[m-1])
        if index[i] == []:
            return pj

        for l in range(len(index[i])):
            pk = i//3 + (index[i][l]//3)*3
            sign = 1

            for j in range(9):
                jk  = j//3 + ((num[m-1][j])//3)*3
                if (index[i][l] == num[m-1][j]) or (pk == jk):
                    sign = 0
            if sign:
                pj.append(index[i][l])

        return pj


    def search(self, num, index, order):
        ### search for each number m
        numbers = [0,1,2,3,4,5,6,7,8]
        #sign = True

        if index is None:
            #print(num)
            return True

        for mi in range(len(order)):
            m = order[mi]
            print(m)
            sys.exit()

            #print("loop 1, m", m, num[m-1])
            check = [0]*9
            for i in range(9):
                pj = []
                if num[m-1][i] == -100:
                    pj = self.onestep(m, i, num, index)
                    check[i] = len(pj)

            orderpj = [x for _,x in sorted(zip(check,numbers))]
            #print("check", check)

            for ii in range(9):
                i= orderpj[ii]
                # print("loop 2, index[3]", index[3])

                #if check[i]==0 and num[m-1][i] == -100:
                #    print("reverse")
                #    return False

                if num[m-1][i] == -100:
                    pj = self.onestep(m, i, num, index)

                    if len(pj) == 0:
                        print("reverse")
                        return False


                    if len(pj) == 1:
                        #print("test1", m,i,pj)
                        num[m-1][i] = (pj[0])
                        index[i].remove(pj[0])
                        #print("i,pj,index",i,pj,index)

                    if len(pj) > 1:
                        #print("test2", m,i,pj)
                        for l in range(len(pj)):
                            num[m-1][i] = (pj[l])
                            #print("m",m, "i", i, num[m-1], "pj", pj, pj[l], index)
                            print("mistake", num[8], i)
                            index[i].remove(pj[l])
                            sign = self.search(num, index, order)
                            if sign == False:
                                num[m-1][i] = -100
                                #print("before reverse m", m, "index[i]", index[i])
                                index[i].append(pj[l])
                                #print("reverse m", m, "index[i]", index[i])

            #print("loop 1 end, m", m, num[m-1])


    # index[i] save row, which contains all .
    # num[digit][i] save digit at row i's j index
    # size[digit] = - # of digit in the sudoku
    # order sort size in increasing order => -6, -4, -3, -1 ...

    # row[:] x
    def solveSudoku(self, board):
        num = [[-100 for i in range(9)] for j in range(9)]

        index = []
        size = [0]*9
        ### initialize the array
        for i in range(9): # row i on the board
            row = []
            for j in range(9):
                if board[i][j] == ".":
                    row.append(j)
                else:
                    m = int(board[i][j])
                    num[m-1][i] = j
                    size[m-1] = size[m-1]-1
            index.append(row[:])

        print(index)

        numbers = [1,2,3,4,5,6,7,8,9]
        order = [x for _,x in sorted(zip(size,numbers))]
        print(sorted(zip(size,numbers)), order)
        #print(num[7])
        #print(min(num[7]))
        #print(self.onestep(8, 0, num, index))

        self.search(num,index,order)

        # m => str(m)
        for m in range(9):
            for i in range(9):
                j = num[m-1][i]
                if j >-1:
                    board[i][j] = m

        return board
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """

board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
a = Solution()
a.solveSudoku(board)
