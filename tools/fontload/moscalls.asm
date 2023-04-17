	.ASSUME	ADL = 1		
	
	;INCLUDE	"equs.inc"
	INCLUDE "mos_api.inc"

	SEGMENT CODE
	XDEF	_load_file
	
	
	; int load_file(char *filename, char *buffer, int maxlen)
	;
_load_file:

	PUSH	IX
	LD	IX, 0
	ADD	IX, SP
	
	LD 	HL, (IX+6)		; source file name
	LD	DE, (IX+9)		; buffer
	LD	BC, (IX+12)		; max len
	MOSCALL mos_load
	LD	HL,0
	LD 	L, A
	
	LD 	SP,IX
	POP	IX				
	RET
	
	
	
	
