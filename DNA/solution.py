from collections import Counter
from re import findall

symbols = findall(r'[ACGT]', open('input.txt').read())
frequencies = Counter(symbols)
print "%s %s %s %s" % (frequencies['A'],
	                   frequencies['C'],
	                   frequencies['G'],
	                   frequencies['T'])
