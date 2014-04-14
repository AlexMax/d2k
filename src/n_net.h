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
 *
 *
 *-----------------------------------------------------------------------------
 */

#ifndef NET_H__
#define NET_H__

#define DEFAULT_PORT 10666
#define CONNECT_TIMEOUT 3
#define DISCONNECT_TIMEOUT 3

#define MULTINET    (netgame && (!solonet))
#define CMDSYNC     (netsync == NET_SYNC_TYPE_COMMAND)
#define DELTASYNC   (netsync == NET_SYNC_TYPE_DELTA)
#define CLIENT      (MULTINET && (!netserver))
#define SERVER      (MULTINET && netserver)
#define CMDCLIENT   (CLIENT && CMDSYNC)
#define CMDSERVER   (SERVER && CMDSYNC)
#define DELTACLIENT (CLIENT && DELTASYNC)
#define DELTASERVER (SERVER && DELTASYNC)

typedef enum {
  AUTH_LEVEL_NONE,
  AUTH_LEVEL_SPECTATOR,
  AUTH_LEVEL_PLAYER,
  AUTH_LEVEL_MODERATOR,
  AUTH_LEVEL_ADMINISTRATOR,
  AUTH_LEVEL_MAX
} auth_level_e;

typedef enum {
  NET_CHANNEL_RELIABLE,
  NET_CHANNEL_UNRELIABLE,
  MAX_CHANNELS
} net_channel_e;

typedef enum {
  NET_SYNC_TYPE_NONE,
  NET_SYNC_TYPE_COMMAND,
  NET_SYNC_TYPE_DELTA,
} net_sync_type_e;

typedef struct netticcmd_s {
  int index;
  ticcmd_t cmd;
} netticcmd_t;

extern dboolean        netgame;
extern dboolean        solonet;
extern dboolean        netserver;
extern net_sync_type_e netsync;

size_t      N_IPToString(int address, char *buffer);
const char* N_IPToConstString(int address);
int         N_IPToInt(const char *address);
size_t      N_GetHostFromAddressString(const char *address, char **host);
dboolean    N_GetPortFromAddressString(const char *address,
                                       unsigned short *port);
size_t      N_ParseAddressString(const char *address, char **host,
                                 unsigned short *port);

void        N_Init(void);
void        N_Disconnect(void);
void        N_Shutdown(void);
dboolean    N_Listen(const char *host, unsigned short port);
dboolean    N_Connect(const char *host, unsigned short port);
dboolean    N_Reconnect(void);
dboolean    N_ConnectToServer(const char *address);
void        N_PrintAddress(FILE *fp, int peernum);
void        N_DisconnectPeer(int peernum);
void        N_DisconnectPlayer(short playernum);
void        N_ServiceNetworkTimeout(int timeout_ms);
void        N_ServiceNetwork(void);

#endif

/* vi: set et ts=2 sw=2: */

