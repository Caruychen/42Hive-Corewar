.name "all_op"
.comment "I WILL RULE THE WORLD"

l2:		live %1
		ld %1, r2
		st r2, 42
		add r3, r4, r5
		sub r6, r7, r8
		and r1, %0, r2
		or %:live, :live, r9
		xor %:live, :live, r10
		zjmp %:live
		ldi 1, %1, r11
		sti r1, %:live, %1
		fork %1
		lld 1, r12
		lldi :live, r13, r14
		lfork %:live
		aff r10
		lfork %:dead

live:	live %1
		zjmp %:live

dead:
