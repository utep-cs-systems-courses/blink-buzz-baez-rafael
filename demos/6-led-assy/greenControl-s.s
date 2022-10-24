	.arch msp430g2553
	.p2align 1,0
	.text


	.global greenControl
	.global blinkUpdate
	.global blinkLimit
	.global blinkCount
	.extern tempSub
	.extern P1OUT

greenControl:
	cmp #0, r12
	jz off
	bis #64, &P1OUT		;or
	pop r0
off:	and #~64, &P1OUT
	pop r0
	
blinkUpdate:
	add #1, blinkCount
	mov #blinkCount, tempSub
	sub blinkLimit, tempSub
	cmp #0, C
	jz bUpdateOff
	mov #0, blinkCount
	clrc
	mov #1, r12
	jz greenControl
	pop r0
bUpdateOff:	clrc
	mov #1, r12
	jz greenControl
	pop r0
	
