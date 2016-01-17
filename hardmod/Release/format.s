	.file	"format.c"
__SREG__ = 0x3f
__SP_H__ = 0x3e
__SP_L__ = 0x3d
__CCP__ = 0x34
__tmp_reg__ = 0
__zero_reg__ = 1
.global	periodTable
	.section	.rodata.periodTable,"a",@progbits
	.type	periodTable, @object
	.size	periodTable, 72
periodTable:
	.word	856
	.word	808
	.word	762
	.word	720
	.word	678
	.word	640
	.word	604
	.word	570
	.word	538
	.word	508
	.word	480
	.word	453
	.word	428
	.word	404
	.word	381
	.word	360
	.word	339
	.word	320
	.word	302
	.word	285
	.word	269
	.word	254
	.word	240
	.word	226
	.word	214
	.word	202
	.word	190
	.word	180
	.word	170
	.word	160
	.word	151
	.word	143
	.word	135
	.word	127
	.word	120
	.word	113
.global __do_copy_data
