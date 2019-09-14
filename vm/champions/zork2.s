.name "zork"
.comment "I'M ALIIIIVE"

		ld %2003792492, r2
		aff r2
		ld %92, r3
		aff r3
l2:		sti r1, %:liv, r1
		and r1, %0, r1

liv:	live %1
		zjmp %:liv
