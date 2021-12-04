import numpy as np

class Table:
    def __init__(self, square_matrix):
        # convert strings to table
        table = square_matrix[1:]
        table = [[int(i) for i in line.split(' ')] for line in table]
        self.table = np.array(table)
        self.record = np.zeros(self.table.shape, dtype=int)
        
    def IfBingo(self, number):
        pose = np.where(self.table == number)
        self.record[pose] = 1
        if( (self.record.sum(axis=0).tolist().count(5) > 0) or (self.record.sum(axis=1).tolist().count(5) > 0)):
            return True
        else:
            return False

    def GetAnswer(self, bingo_number):
        self.record = 1 - self.record
        multiply = self.table * self.record
        sum_matrix = sum(sum(multiply))
        return bingo_number * sum_matrix
       


lines_temp = open('input.txt', 'r').readlines()
Lines = []
for line in lines_temp:
	# replace many space to one space
	Lines.append(' '.join(line.split()))

# data for each round
play_rounds = [int(i) for i in Lines[0].split(',')]
Lines = Lines[1:]

# create tables
list_tables = []
while Lines:
    list_tables.append(Table(Lines[:6]))
    Lines = Lines[6:]


# play game
list_bingo_table = []
bingo_number = -1
for current_round in play_rounds:
    if list_bingo_table:
        break
    else:
        bingo_number = current_round
        for table in list_tables:
            res = table.IfBingo(current_round)
            if(res):
                list_bingo_table.append(table)



print(str(list_bingo_table[0].GetAnswer(bingo_number)))
