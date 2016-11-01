def mean(seq):
	n = 0.0

	for x in seq:
		n += x
	return n / len(seq)


sequence = [1,2,3,4,5]
print "the mean of the sequence is:\t", mean(sequence)


