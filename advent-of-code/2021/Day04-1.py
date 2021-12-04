import numpy as np

class Table:
    def __init__(self, square_matrix):
        # convert strings to table
        table = square_matrix[1:]
        table = [[int(i) for i in line.split(' ')] for line in table]
        self.table = np.array(table)
        self.record = np.zeros(self.table.shape, dtype=int)
        self.already_bingo = False

    def IfAlreadyBingo(self):
        return self.already_bingo

    def IfBingo(self, number):
        pose = np.where(self.table == number)
        self.record[pose] = 1
        if( (self.record.sum(axis=0).tolist().count(5) > 0) or (self.record.sum(axis=1).tolist().count(5) > 0)):
            self.already_bingo = True
        return self.already_bingo

    def GetAnswer(self, bingo_number):
        self.record = 1 - self.record
        multiply = self.table * self.record
        sum_matrix = sum(sum(multiply))
        return bingo_number * sum_matrix
       


input_lines = []
with open('input.txt', 'r') as input_file:
    for line in input_file:
	    # replace many space to one space
        input_lines.append(' '.join(line.split()))

# data for each round
play_rounds = [int(i) for i in input_lines[0].split(',')]
input_lines = input_lines[1:]

# create tables
list_tables = []
while input_lines:
    list_tables.append(Table(input_lines[:6]))
    input_lines = input_lines[6:]


# play part1 game
list_bingo_table = []
bingo_numbers = []
for current_round in play_rounds:
    if list_bingo_table:
        break

    for table in list_tables:
        if not table.IfAlreadyBingo():
            if(table.IfBingo(current_round)):
                list_bingo_table.append(table)
                bingo_numbers.append(current_round)


print(str(list_bingo_table[-1].GetAnswer(bingo_numbers[-1])))

# play part2 game
list_bingo_table = []
bingo_numbers = []
for current_round in play_rounds:

    for table in list_tables:
        if not table.IfAlreadyBingo():
            if(table.IfBingo(current_round)):
                list_bingo_table.append(table)
                bingo_numbers.append(current_round)


print(str(list_bingo_table[-1].GetAnswer(bingo_numbers[-1])))
