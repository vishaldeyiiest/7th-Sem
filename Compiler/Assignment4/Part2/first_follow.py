from predictive_parser import check_terminal
def get_first(grammar):
	fd = {}
	for sym, prod in grammar.iteritems():
		fd[sym] = set()
		if check_terminal(prod[0]):
			fd[prod[0]] = set([prod[0]]) 

	while True:
		temp = fd.copy()
		for lhs, rhs in grammar.iteritems():
			for p in rhs:
				if not p[0]:
					fd[lhs] = fd[lhs].union(set(['']))
				else:
					fd[lhs] = fd[lhs].union(fd[p[0]])
				for i in xrange(1, len(p)):
					if contains_null(p[:i]):
						if not p[0]:
							fd[lhs] = fd[lhs].union(set(['']))
						else:
							fd[lhs] = fd[lhs].union(fd[p[0]])
		if temp == fd:
			return fd

'''
def get_follow(grammar):
	follow = {}
	for h in grammar:
		if h == predictive_parser.start:
			follow[h] = set(['$'])
		else:
			follow[h] = set()
	while True:
		temp = follow.copy()
		for l, r in grammar.iteritems():
			for p in r:
				for i in xrange(len(r)-1):
					if not check_terminal(p[i]):
						follow[p[i]] = follow[p[i]].union(first(p[i+1:]))

                for i in reversed(xrange(len(p))):
                	if not check_terminal(p[i]) and self.nullable(p[i+1:]):
						follow[p[i]] = follow[p[i]].union(follow[h])
			if temp == follow:
			return follow
		'''