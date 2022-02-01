import sys

class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

class Solution(object):
    # not all functions need self

    def getNumPos_v2(self, b): # get the num and i j_list at the same time
        r = [set() for i in range(9)]
        c = [set() for i in range(9)]
        bl = [set() for i in range(9)]

        for i in range(9):
            for j in range(9):
                ij = (i//3)*3 + j//3
                if b[i][j] != 0:
                    r[i].add(b[i][j])
                    c[j].add(b[i][j])
                    bl[ij].add(b[i][j])

        pos = []
        for i in range(9):
            for m in range(1,10):
                if m not in r[i]:
                    j_list = []
                    for j in range(9):
                        if b[i][j] == 0:
                            ij = (i//3)*3 + j//3
                            if (m not in c[j]) and (m not in bl[ij]):
                                j_list.append(j)
                    if len(j_list) == 0:
                        return (m, [len(j_list), i, j_list])
                    pos.append([len(j_list), m, i, j_list])
        min_pos = min(pos)
        return (min_pos[1], [min_pos[0], min_pos[2], min_pos[3]])
        # min([[1,'s'],[32],[0]])


    # return (num,best_i_j_list), where best_i_j_list = row_i = [0, i, []]
    def getNumPos_v1(self, b):
        # find num, which appear most, but < 9 times
        cntn = [0]*10
        for i in range(9):
            for j in range(9):
                if b[i][j] != 0:
                    n = b[i][j]
                    cntn[n] += 1

        cntn_n = sorted(zip(cntn[1:], range(1,10)), reverse=True)
        for i in range(9):
            if cntn_n[i][0]!=9:
                num = cntn_n[i][1]
                break;

        # print(num)

        # find row and col's choices
        r = [True]*9
        c = [True]*9
        bl = [True]*9
        for i in range(9):
            for j in range(9):
                if b[i][j] == num:
                    r[i] = False
                    c[j] = False
                    ij = (i//3)*3 + j//3
                    bl[ij] = False
        # print(r, c, bl)

        pos = []
        for i in range(9):
            if r[i]:
                row_i = [0, i, []]
                for j in range(9):
                    ij = (i//3)*3 + j//3
                    if b[i][j] == 0 and r[i] and c[j] and bl[ij]:
                        row_i[0] += 1
                        row_i[2].append(j)
                pos.append(row_i)
        # print(pos)
        pos.sort()
        min(pos)
        # print(pos)

        best_i_j_list = pos[0] if pos else [];
        return (num,best_i_j_list)

    # python when to add self
    def search(self, cnt0, b):
        if cnt0 == 0:
            return True
        # num,i_j_list = self.getNumPos(b)
        num,i_j_list = self.getNumPos_v2(b)
        print(num, i_j_list)

        if i_j_list[0] == 0:
            return False
        i = i_j_list[1]
        for j in i_j_list[2]:
            b[i][j] = num
            self.print_b(b, i, j)
            input("Press Enter to continue...")
            if self.search(cnt0-1, b):
                return True
            b[i][j] = 0

    def print_b(self, b, i0, j0):
        for i in range(9):
            for j in range(9):
                if i == i0 and j == j0:
                    print(bcolors.WARNING+str(b[i][j])+bcolors.ENDC, sep=' ',end='')
                else:
                    print(b[i][j], sep=' ',end='')
            print()



    def solveSudoku(self, board):
        b = []
        cnt0 = 0
        for i in range(9):
            row = []
            for j in range(9):
                if board[i][j] == ".":
                    row.append(0)
                    cnt0 += 1
                else:
                    row.append(int(board[i][j]))
            b.append(row)

        # print(b, cnt0)
        # self.getNumPos(b)

        if self.search(cnt0, b):
            pass
        else:
            print('Fail')

        for i in range(9):
            for j in range(9):
                board[i][j] = str(b[i][j])

        return board
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """

board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
board = \
[['.', '.', '2', '3', '1', '.', '.', '8', '.'],
 ['8', '5', '.', '6', '.', '.', '.', '.', '.'],
 ['.', '.', '.', '.', '.', '.', '2', '.', '6'],
 ['7', '3', '.', '.', '.', '5', '6', '.', '.'],
 ['.', '.', '1', '.', '.', '.', '8', '.', '7'],
 ['2', '.', '9', '.', '.', '.', '.', '.', '.'],
 ['1', '.', '.', '.', '.', '.', '.', '7', '.'],
 ['.', '.', '.', '.', '.', '7', '1', '.', '.'],
 ['.', '.', '.', '8', '9', '.', '.', '.', '.']];

a = Solution()
a.solveSudoku(board)

# find with regex \d
# 0 0 2 3 1 0 0 8 0
# 8 5 0 6 0 0 0 0 0
# 0 0 0 0 0 0 2 0 6
# 7 3 0 0 0 5 6 0 0
# 0 0 1 0 0 0 8 0 7
# 2 0 9 0 0 0 0 0 0
# 1 0 0 0 0 0 0 7 0
# 0 0 0 0 0 7 1 0 0
# 0 0 0 8 9 0 0 0 0
