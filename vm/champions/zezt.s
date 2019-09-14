.name "zzezting"
.comment "da zezt"

live %:live   

add r1, r2, r3
sub r1, r2, r3
aff r8

fork %5999

and r1, -3, r2 
or r1, -8, r3 
xor r1, 1, r4 


and 1, -3, r5
or 1, -8, r6
xor 1, 1, r7

and 1, r3, r8
or 1, r8, r9
xor 1, r1, r10

and r1, 1, r11 
or r3, -8, r12
xor r13, 1, r13

add r10, r2, r3
sub r3, r4, r8
aff r8

ld  %-1235102394, r14
ld   -3, r2 

ldi 1, r2, r6

ldi r1, %2, r2
ldi r1, r2, r3
ldi %2, r2, r4
ldi %1, %2, r5

ldi 1, r2, r8

ldi 1, %2, r7
ldi r1, %2, r9
ldi r1, r2, r10
ldi %2, r2, r11
ldi %1, %2, r12

ldi -13, r2, r13
ldi -28, r2, r14
ldi -1, r2, r15
ldi -31, r2, r16

ldi -1, %-2, r4

st r1, r2 
st r1, 2

add r1, r2, r3

sti r1, %:live, %1

live:	live %1
		lfork %2000000
