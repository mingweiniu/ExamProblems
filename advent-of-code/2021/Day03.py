import numpy as np

inputs = []
with open('input.txt', 'r') as input_file:
    for line in input_file:
        inputs.append(int(line, base=2))


test = "test"
bits = np.zeros(12)

for i in inputs:
	for b in range(12):
		mask = 1 << b
		if i & mask :
			bits[b] = bits[b] + 1

gamma = 0
epsilon = 0

for b in range(12):
	if bits[b] > len(inputs) / 2:
		gamma = gamma + (1 << b);
	else:
		epsilon = epsilon + (1 << b)

print(gamma * epsilon)
