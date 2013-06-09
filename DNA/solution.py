from collections import Counter

counter = Counter()
with open('input.txt', 'r') as f:
	while True:
		c = f.read(1)
		if not c:
			break
		counter[c] += 1
print "%s %s %s %s" % (counter['A'],
	                   counter['C'],
	                   counter['G'],
	                   counter['T'])
