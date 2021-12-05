import numpy as np

line_pairs = []
with open('input.txt', 'r') as input_file:
    for line in input_file:
	    # replace many space to one space
        pairs = [pose.split(',') for pose in line.split(' -> ')]
        line_pairs.append([list(map(int, x)) for x in pairs])
    pass

line_pairs = np.array(line_pairs)

max_num = line_pairs.max() + 1
terrain = np.zeros([max_num, max_num])

for pair in line_pairs:
    start_point, end_point = pair 

    if start_point[0] == end_point[0]:
        a = start_point[1]
        b = end_point[1]
        for x in range(min(a, b), max(a, b) + 1):
            terrain[x][start_point[0]] +=1  
            

    if start_point[1] == end_point[1]:
        a = start_point[0]
        b = end_point[0]
        for y in range(min(a, b), max(a, b) + 1):
            terrain[start_point[1]][y] +=1
    pass

print((np.asarray(terrain) > 1).sum())


# part 2
for pair in line_pairs:
    start_point, end_point = pair 
    
    # base on part 1 is done
    # only add diagonal line
    vec = start_point - end_point
    if abs(vec[0]) == abs(vec[1]):
        steps = abs(vec[0])
        ont_step = (end_point - start_point) // steps
        for t in range(0, steps + 1):
            target = start_point + t * ont_step
            terrain[target[1]][target[0]] +=1

    pass

print((np.asarray(terrain) > 1).sum())
