/*
 *  GRUB  --  GRand Unified Bootloader
 *  Copyright (C) 2002,2003,2005,2007,2008  Free Software Foundation, Inc.
 *
 *  GRUB is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  GRUB is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with GRUB.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <grub/i386/vga_common.h>
#include <grub/term.h>
#include <grub/types.h>

grub_uint8_t grub_console_cur_color = 0x7;
static grub_uint8_t grub_console_standard_color = 0x7;
static grub_uint8_t grub_console_normal_color = 0x7;
static grub_uint8_t grub_console_highlight_color = 0x70;

grub_uint16_t
grub_console_getwh (struct grub_term_output *term __attribute__ ((unused)))
{
  return (80 << 8) | 25;
}

void
grub_console_setcolorstate (struct grub_term_output *term __attribute__ ((unused)),
			    grub_term_color_state state)
{
  switch (state) {
    case GRUB_TERM_COLOR_STANDARD:
      grub_console_cur_color = grub_console_standard_color;
      break;
    case GRUB_TERM_COLOR_NORMAL:
      grub_console_cur_color = grub_console_normal_color;
      break;
    case GRUB_TERM_COLOR_HIGHLIGHT:
      grub_console_cur_color = grub_console_highlight_color;
      break;
    default:
      break;
  }
}

void
grub_console_setcolor (struct grub_term_output *term __attribute__ ((unused)),
		       grub_uint8_t normal_color, grub_uint8_t highlight_color)
{
  grub_console_normal_color = normal_color;
  grub_console_highlight_color = highlight_color;
}

void
grub_console_getcolor (struct grub_term_output *term __attribute__ ((unused)),
		       grub_uint8_t *normal_color, grub_uint8_t *highlight_color)
{
  *normal_color = grub_console_normal_color;
  *highlight_color = grub_console_highlight_color;
}
