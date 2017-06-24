#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "kernel/tty.h"
#include "kernel/hal.h"

#include "vga.h"

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
static uint16_t* const VGA_MEMORY = (uint16_t*) 0xB8000;

static const uint16_t FRAMEBUFFER_COMMAND_PORT = 0x3D4;
static const uint16_t FRAMEBUFFER_DATA_PORT = 0x3D5;
static const uint16_t FRAMEBUFFER_HIGH_BYTE_COMMAND = 14;
static const uint16_t FRAMEBUFFER_LOW_BYTE_COMMAND = 15;
 
static size_t cursor_y;
static size_t cursor_x;
static uint8_t terminal_colour;
static uint16_t* terminal_buffer;

void terminal_initialise(void)
{
	terminal_colour = vga_entry_colour(VGA_COLOUR_LIGHT_GREY, VGA_COLOUR_BLACK);
	terminal_buffer = VGA_MEMORY;
	terminal_clear();
	
	terminal_writestr("Terminal initialised\n");
}

void terminal_setcolour(uint8_t colour)
{
	terminal_colour = colour;
}

void terminal_putentryat(char c, uint8_t colour, size_t x, size_t y)
{
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, colour);
}

void terminal_mv_csr(void)
{
	uint16_t index = cursor_y * VGA_WIDTH + cursor_x;
	outportb(FRAMEBUFFER_COMMAND_PORT, FRAMEBUFFER_HIGH_BYTE_COMMAND);
	outportb(FRAMEBUFFER_DATA_PORT, (index & 0xFF00) >> 8);
	outportb(FRAMEBUFFER_COMMAND_PORT, FRAMEBUFFER_LOW_BYTE_COMMAND);
	outportb(FRAMEBUFFER_DATA_PORT, index & 0x00FF);
}

void terminal_putchar(char c)
{
	if (c == '\n')
	{
		cursor_y++;
		cursor_x = 0;
	}
	else
	{
		terminal_putentryat(c, terminal_colour, cursor_x, cursor_y);
		if (++cursor_x == VGA_WIDTH)
		{
			cursor_x = 0;
			if (++cursor_y == VGA_HEIGHT)
				cursor_y = 0;
		}
	}
	terminal_mv_csr();
}

void terminal_write(const char* data, size_t size)
{
	for (size_t i = 0; i < size; i++)
		terminal_putchar(data[i]);
}

void terminal_writestr(const char* data)
{
	terminal_write(data, strlen(data));
}

void terminal_clear()
{
	cursor_y = 0;
	cursor_x = 0;
	for (size_t y = 0; y < VGA_HEIGHT; y++)
		for (size_t x = 0; x < VGA_WIDTH; x++)
		{
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_colour);
		}
}

