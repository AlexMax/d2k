/* Emacs style mode select   -*- C++ -*-
 *-----------------------------------------------------------------------------
 *
 *
 *  PrBoom: a Doom port merged with LxDoom and LSDLDoom
 *  based on BOOM, a modified and improved DOOM engine
 *  Copyright (C) 1999 by
 *  id Software, Chi Hoang, Lee Killough, Jim Flynn, Rand Phares, Ty Halderman
 *  Copyright (C) 1999-2000 by
 *  Jess Haas, Nicolas Kalkhof, Colin Phipps, Florian Schulze
 *  Copyright 2005, 2006 by
 *  Florian Schulze, Colin Phipps, Neil Stevens, Andrey Budko
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 *  02111-1307, USA.
 *
 * DESCRIPTION:
 *  Console
 *
 *-----------------------------------------------------------------------------
 */

#ifndef C_MAIN__
#define C_MAIN__

void C_Init(void);
void C_Reset(void);
void C_Ticker(void);
void C_Drawer(void);
bool C_Responder(event_t *ev);
void C_ScrollDown(void);
void C_ScrollUp(void);
void C_ToggleScroll(void);
void C_Banish(void);
void C_SetFullScreen(void);
bool C_Active(void);
void C_Printf(const char *fmt, ...) PRINTF_DECL(1, 2);
void C_MPrintf(const char *fmt, ...) PRINTF_DECL(1, 2);
void C_Echo(const char *message);
void C_MEcho(const char *message);

#endif

/* vi: set et ts=2 sw=2: */

