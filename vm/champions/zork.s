.name "zork"
.comment "sadf"

l2:	
		sti r1, %:live, %1
		and r1, %0, r2
		#fork %-8

live:	live %1
		lfork %:live
		zjmp %:live
