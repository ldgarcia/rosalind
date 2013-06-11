import sys
with open('input.txt') as f:
	while True:
		c = f.read(1)
		if not c:
			break
		sys.stdout.write(c if c != 'T' else 'U')
		
