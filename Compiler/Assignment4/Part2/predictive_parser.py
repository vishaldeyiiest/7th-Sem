#Non recursive predictive parser

class Parser(object):
	def __init__(self, start, terminal, nonterminal):
		self.start = start
		#self.grammar = grammar
		self.term = set(terminal)
		self.nonterm = set(nonterminal)
		#self.first = get_first()
		#self.follow = get_follow()
		self.table = self.get_table()

	def check_terminal(self, s):
		if not s or s[0].isupper():
			return False
		return True

	def print_table(self):
		for nt in self.nonterm:
			self.term = self.term.union(set(['$']))
			for t in self.term:
				try:
					temp = self.table[nt, t]
					print '(' + nt + ', ' + t + ') => ' + ''.join(temp)
				except KeyError:
					pass

	def get_table(self):
		table = {}
		table['E', 'id'] = ['T', "E'"]
		table['E', '('] = ['T', "E'"]
		table["E'", '$'] = ['']
		table["E'", '+'] = ['+', 'T', "E'"]
		table["E'", ')'] = ['']
		table["T'", '$'] = ['']
		table["T'", ')'] = ['']
		table["T'", '+'] = ['']
		table["T'", '*'] = ['*', 'F', "T'"]
		table['T', '('] = ['F', "T'"]
		table['T', 'id'] = ['F', "T'"]
		table['F', '('] = ['(', 'E', ')']
		table['F', 'id'] = ['id']
		return table

	def match(self, input):
		input.append('$')
		i = 0
		stack = ['$', self.start]
		top = self.start
		while top != '$':
			if top == '$' or self.check_terminal(top):
				if top == input[i]:
					stack.pop()
					i += 1
				else:
					return False
			
			else:
				try:
					temp = self.table[top, input[i]]
					stack.pop()
					if temp != ['']:
						print "Derive {0} on `{1}` to: {2}".format(top, input[i], ''.join(temp))
						stack.extend(reversed(temp))

				except KeyError:
					print "ERROR: No such derivation of {0} on '{1}'".format(top, input[i])
					return False
			
			top = stack[-1]
		if input[i] != '$':
			return False
		return True

if __name__ == '__main__':
	parser = Parser('E', ['+', '*', '(', ')', 'id'], ['E', "E'", 'T', "T'", 'F', "F'"])
	#print parser.table
	parser.print_table()
	if parser.match(['id', '*', '(', 'id', '+', 'id', ')']):
		print 'SUCCESS..No syntax error.. :)'
	else:
		print 'OOPS..Syntax Error.. :('