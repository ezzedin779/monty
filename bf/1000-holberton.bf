+++++++++           c0 = 9
[                   Start loop
    >++++++++       Forward to c1 and add 8
        <-              Back to c0 subtract 1
	]                   Repeat until = 0
	>.                  Forward to c1 and print (c0 = 72 = 'H')
	[-]                 Decrement c1 until 0
	+++++++++++         c0 = 11
	[                   Start loop
	    >++++++++++     Forward to c1 and add 10
	        <-              Back to c0 and subtract 1
		]                   Repeat (until c1 = 110)
		>+.                 Forward to c1 add 1 and print (c1 = 111 = 'o')
		---.                Subtract 3 to c1 and print (c1 = 108 = 'l')
		----------.         Subtract 10 to c1 and print (c1 = 98 = 'b')
		+++.                Add 3 to c1 and print (c1 = 101 = 'e')
		+++++++++++++.      Add 13 to c1 and print (c1 = 114 = 'r')
		++.                 Add 2 to c1 and print (c1 = 116 = 't')
		-----.              Subtract 5 to c1 and print (c1 = 111 = 'o')
		-.                  Subtract 1 to c1 and print (c1 = 110 = 'n')
		[-]                 Subtract 1 to c1 until c1 = 0
		++++++++++.         Add 10 to c1 and print (c1 = 10 = '\n')