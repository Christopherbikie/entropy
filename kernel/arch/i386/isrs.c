#include <kernel/isrs.h>
#include <stdio.h>

#include <kernel/idt.h>

/* +---+---+---+---+---+---+---+---+
 * | P |  DPL  | S |    GateType   |
 * +---+---+---+---+---+---+---+---+
 *   1   0   0   0   1   1   1   0
 *
 *   P    Set to 0 for unused interrupts
 *   DPL  Descriptor Privilege Level
 *   S    Storage Segment (Set to 0 for interrupt and trap gates)
 *   Type 1110 = 32-bit interrupt gate
 *   
 *   0b10001110 == 0x8E
 */
#define IDT_SET_GATE_N(idx) idt_set_gate(idx, (uint32_t) &isr_stub_##idx, 0x08, 0x8E);

int isr_handler(struct registers regs)
{
	printf("recieved interrupt ");
	for (int i = 0; i < regs.int_no; i++)
		printf("+");
	printf("\n");
	return 0;
}

extern void isr_stub_0();
extern void isr_stub_1();
extern void isr_stub_2();
extern void isr_stub_3();
extern void isr_stub_4();
extern void isr_stub_5();
extern void isr_stub_6();
extern void isr_stub_7();
extern void isr_stub_8();
extern void isr_stub_9();
extern void isr_stub_10();
extern void isr_stub_11();
extern void isr_stub_12();
extern void isr_stub_13();
extern void isr_stub_14();
extern void isr_stub_15();
extern void isr_stub_16();
extern void isr_stub_17();
extern void isr_stub_18();
extern void isr_stub_19();
extern void isr_stub_20();
extern void isr_stub_21();
extern void isr_stub_22();
extern void isr_stub_23();
extern void isr_stub_24();
extern void isr_stub_25();
extern void isr_stub_26();
extern void isr_stub_27();
extern void isr_stub_28();
extern void isr_stub_29();
extern void isr_stub_30();
extern void isr_stub_31();

void isrs_init()
{
	printf("Setting ISRs... ");
	
	IDT_SET_GATE_N(0)
	IDT_SET_GATE_N(1)
	IDT_SET_GATE_N(2)
	IDT_SET_GATE_N(3)
	IDT_SET_GATE_N(4)
	IDT_SET_GATE_N(5)
	IDT_SET_GATE_N(6)
	IDT_SET_GATE_N(7)
	IDT_SET_GATE_N(8)
	IDT_SET_GATE_N(9)
	IDT_SET_GATE_N(10)
	IDT_SET_GATE_N(11)
	IDT_SET_GATE_N(12)
	IDT_SET_GATE_N(13)
	IDT_SET_GATE_N(14)
	IDT_SET_GATE_N(15)
	IDT_SET_GATE_N(16)
	IDT_SET_GATE_N(17)
	IDT_SET_GATE_N(18)
	IDT_SET_GATE_N(19)
	IDT_SET_GATE_N(20)
	IDT_SET_GATE_N(21)
	IDT_SET_GATE_N(22)
	IDT_SET_GATE_N(23)
	IDT_SET_GATE_N(24)
	IDT_SET_GATE_N(25)
	IDT_SET_GATE_N(26)
	IDT_SET_GATE_N(27)
	IDT_SET_GATE_N(28)
	IDT_SET_GATE_N(29)
	IDT_SET_GATE_N(30)
	IDT_SET_GATE_N(31)
	
	printf("done\n");
}
