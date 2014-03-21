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

#include "z_zone.h"

#include <msgpack.h>

#include "n_peer.h"

#define SERVER_ONLY(s) \
  if (!server) { \
    doom_printf( \
      "N_HandlePacket: Erroneously received packet [" #s "] from the server\n" \
    ); \
    return; \
  }

#define CLIENT_ONLY(s) \
  if (server) { \
    doom_printf( \
      "N_HandlePacket: Erroneously received packet [" #s "] from a client\n" \
    ); \
    return; \
  }

#define CHECK_CONNECTION(np)                                                  \
  if (np == NULL) {                                                           \
    doom_printf(__func__ ": Not connected\n");                                \
    return;                                                                   \
  }

/* CG: C/S Message Handlers here */

static void handle_game_state_message(netpeer_t *np) {
}

static void handle_server_message_message(netpeer_t *np) {
}

static void handle_auth_response_message(netpeer_t *np) {
}

static void handle_player_message_message(netpeer_t *np) {
  if (server) {
    /* CG: TODO */
  }
  else {
    /* CG: TODO */
  }
}

static void handle_player_command_message(netpeer_t *np) {
}

static void handle_auth_request_message(netpeer_t *np) {
}

static void handle_name_change_message(netpeer_t *np) {
}

static void handle_team_change_message(netpeer_t *np) {
}

static void handle_pwo_change_message(netpeer_t *np) {
}

static void handle_wsop_change_message(netpeer_t *np) {
}

static void handle_bobbing_change_message(netpeer_t *np) {
}

static void handle_autoaim_change_message(netpeer_t *np) {
}

static void handle_weapon_speed_change_message(netpeer_t *np) {
}

static void handle_color_change_message(netpeer_t *np) {
}

static void handle_skin_change_message(netpeer_t *np) {
}

static void handle_rcon_message(netpeer_t *np) {
}

static void handle_vote_request_message(netpeer_t *np) {
}

typedef enum {
  P2P_STATE_NONE,
  P2P_STATE_INITIALIZED,
  P2P_STATE_SETUP,
  P2P_STATE_GO,
  P2P_STATE_MAX
} p2p_state_e;

/* CG: P2P Message Handlers here */

static void handle_init_message(netpeer_t *np) {
}

static void handle_setup_message(netpeer_t *np) {
}

static void handle_go_message(netpeer_t *np) {
}

static void handle_client_tic_message(netpeer_t *np) {
}

static void handle_server_tic_message(netpeer_t *np) {
}

static void handle_retransmission_request_message(netpeer_t *np) {
}

static void handle_color_message(netpeer_t *np) {
}

static void handle_save_game_name_message(netpeer_t *np) {
}

static void handle_quit_message(netpeer_t *np) {
}

static void handle_down_message(netpeer_t *np) {
}

static void handle_wad_message(netpeer_t *np) {
}

static void handle_backoff_message(netpeer_t *np) {
}

static void dispatch_p2p_message(netpeer_t *np, byte message_type) {
  switch(message_type) {
    case PKT_INIT:
      SERVER_ONLY("initialization");
      handle_init_request_message(np);
    break;
    case PKT_SETUP:
      CLIENT_ONLY("setup");
      handle_setup_message(np);
    break;
    case PKT_GO:
      /* CG: Both clients and servers receive PKT_GO messages */
      handle_go_message(np);
    break;
    case PKT_TICC:
      SERVER_ONLY("client tic");
      handle_client_tic_message(np);
    break;
    case PKT_TICS:
      CLIENT_ONLY("server tic")
      handle_server_tic_message(np);
    break;
    case PKT_RETRANS:
      /* CG: Both clients and servers receive PKT_RETRANS messages */
      handle_retransmission_request_message(np);
    break;
    case PKT_COLOR:
      /* CG: Both clients and servers receive PKT_COLOR messages */
      handle_color_message(np);
    break;
    case PKT_SAVEG:
      /* CG: Both clients and servers receive PKT_SAVEG messages */
      handle_save_game_name_message(np);
    break;
    case PKT_QUIT:
      /* CG: Both clients and servers receive PKT_QUIT messages */
      handle_quit_message(np);
    break;
    case PKT_DOWN:
      CLIENT_ONLY("down");
      handle_down_message(np);
    break;
    case PKT_WAD:
      /* CG: Both clients and servers receive PKT_WAD messages */
      handle_wad_message(np);
    break;
    case PKT_BACKOFF:
      CLIENT_ONLY("backoff");
      handle_backoff_message(np);
    break;
    default:
      doom_printf("Received unknown message type %u from peer %s:%u.\n"
        message_type,
        I_IPToString(np->peer->address.host),
        np->peer->address.peer
      );
    break;
  }
}

static void dispatch_cs_message(netpeer_t *np, byte message_type) {
  switch (message_type) {
    case nm_gamestate:
      CLIENT_ONLY("game state");
      handle_game_state_message(np);
    break;
    case nm_servermessage:
      CLIENT_ONLY("server message");
      handle_server_message_message(np);
    break;
    case nm_authresponse:
      CLIENT_ONLY("authorization response");
      handle_auth_response_message(np);
    break;
    case nm_playermessage:
      /* CG: Both servers and clients receive player message messages */
      handle_player_message_message(np);
    break;
    case nm_playercommand:
      SERVER_ONLY("player command");
      handle_player_command_message(np);
    break;
    case nm_authrequest:
      SERVER_ONLY("authorization request");
      handle_auth_request_message(np);
    break;
    case nm_namechange:
      SERVER_ONLY("name change");
      handle_name_change_message(np);
    break;
    case nm_teamchange:
      SERVER_ONLY("team change");
      handle_team_change_message(np);
    break;
    case nm_pwochange:
      SERVER_ONLY("PWO change");
      handle_pwo_change_message(np);
    break;
    case nm_wsopchange:
      SERVER_ONLY("WSOP change");
      handle_wsop_change_message(np);
    break;
    case nm_bobbingchange:
      SERVER_ONLY("bobbing change");
      handle_bobbing_change_message(np);
    break;
    case nm_autoaimchange:
      SERVER_ONLY("autoaim change");
      handle_autoaim_change_message(np);
    break;
    case nm_weaponspeedchange:
      SERVER_ONLY("weapon speed change");
      handle_weapon_speed_change_message(np);
    break;
    case nm_colorchange:
      SERVER_ONLY("color change");
      handle_color_change_message(np);
    break;
    case nm_skinchange:
      SERVER_ONLY("skin change");
      handle_skin_change_message(np);
    break;
    case nm_rconcommand:
      SERVER_ONLY("RCON command");
      handle_rcon_message(np);
    break;
    case nm_voterequest:
      SERVER_ONLY("vote request");
      handle_vote_request_message(np);
    break;
    default:
      doom_printf("Received unknown message type %u from peer %s:%u.\n"
        message_type,
        I_IPToString(np->peer->address.host),
        np->peer->address.peer
      );
    break;
  }
}

void N_HandlePacket(int peernum, void *data, size_t data_size) {
  netpeer_t *np = N_GetPeer(peernum);
  byte message_type = 0;

  msgpack_unpacker_reserve_buffer(pac, data_size);
  memcpy(msgpack_unpacker_buffer(pac), data, data_size);
  msgpack_unpacker_buffer_consumed(pac, data_size);

  while (N_LoadNewMessage(np, &message_type)) {
    if (use_p2p_netcode)
      dispatch_p2p_message(np, message_type);
    else
      dispatch_cs_message(np, message_type);
  }
}

#define CHECK_VALID_PLAYER(np, playernum) \
  if (((np) == N_GetPlayerForPeer((playernum))) == NULL) \
    I_Error(__func__ ": Invalid player %d.\n", playernum)

void SV_SendStateDelta(short playernum) {
  netpeer_t *np = NULL;
  int tic_from = 0;
  int tic_to = 0;


  CHECK_VALID_PLAYER(np, playernum);

  N_PackStateDelta(playernum, 

void SV_BroadcastGameState(byte *state_data, size_t state_size) {
  netpeer_t *np = NULL;

  for (int i = 0; i < N_GetPeerCount(); i++) {
    netpeer_t *np = N_GetPeer(i);

    if ((np = N_GetPeer(i)) != NULL)
      N_PackGameState(np, state_data, state_size);
  }
}

void SV_SendMessage(short playernum, rune *message) {
  netpeer_t *np = NULL;
  CHECK_VALID_PLAYER(np, playernum);

  N_PackMessage(np, message);
}

void SV_BroadcastMessage(rune *message) {
  netpeer_t *np = NULL;

  for (int i = 0; i < N_GetPeerCount(); i++) {
    netpeer_t *np = N_GetPeer(i);

    if ((np = N_GetPeer(i)) != NULL)
      N_PackMessage(np, message);
  }
}

void SV_SendAuthResponse(short playernum, auth_level_e auth_level) {
  netpeer_t *np = N_GetPeerForPlayer(playernum);

  if (np == NULL)
    I_Error("SV_SendAuthResponse: Invalid player %d.\n", playernum);

  N_PackMessage(np, auth_level);
}

void CL_SendPlayerMessage(short recipient, rune *message) {
  netpeer_t *np = N_GetPeer(0);
  CHECK_CONNECTION(np);

  N_PackClientMessage(np, recipient, message);
}

void CL_SendPlayerCommand(unsigned int   index,
                          unsigned int   world_index,
                          signed   char  forward,
                          signed   char  side,
                          signed   short angle,
                          byte           buttons) {
  netpeer_t *np = N_GetPeer(0);
  CHECK_CONNECTION(np);

  N_PackPlayerCommand(np, index, world_index, forward, side, angle, buttons);
}

void CL_SendAuthRequest(rune *password) {
  netpeer_t *np = N_GetPeer(0);
  CHECK_CONNECTION(np);

  N_PackAuthRequest(np, password);
}

void CL_SendNameChange(rune *new_name) {
  netpeer_t *np = N_GetPeer(0);
  CHECK_CONNECTION(np);

  N_PackNameChange(np, new_name);
}

void CL_SendTeamChange(byte new_team) {
  netpeer_t *np = N_GetPeer(0);
  CHECK_CONNECTION(np);

  N_PackTeamChange(np, new_team);
}

void CL_SendPWOChange(void) {
  netpeer_t *np = N_GetPeer(0);
  CHECK_CONNECTION(np);
  /* CG: TODO */
}

void CL_SendWSOPChange(byte new_wsop_flags) {
  netpeer_t *np = N_GetPeer(0);
  CHECK_CONNECTION(np);

  N_PackWSOPChange(np, new_wsop_flags);
}

void CL_SendBobbingChange(double new_bobbing_amount) {
  netpeer_t *np = N_GetPeer(0);
  CHECK_CONNECTION(np);

  N_PackBobbingChange(np, new_bobbing_amount);
}

void CL_SendAutoaimChange(dboolean new_autoaim_enabled) {
  netpeer_t *np = N_GetPeer(0);
  CHECK_CONNECTION(np);

  N_PackAutoaimChange(np, new_autoaim_enabled);
}

void CL_SendWeaponSpeedChange(byte new_weapon_speed) {
  netpeer_t *np = N_GetPeer(0);
  CHECK_CONNECTION(np);

  N_PackWeaponSpeedChange(np, new_weapon_speed);
}

void CL_SendColorChange(byte new_red, byte new_green, byte new_blue) {
  netpeer_t *np = N_GetPeer(0);
  CHECK_CONNECTION(np);

  N_PackColorChange(np, new_red, new_green, new_blue);
}

void CL_SendSkinChange(void) {
  netpeer_t *np = N_GetPeer(0);
  CHECK_CONNECTION(np);
  /* CG: TODO */
}

void CL_SendRCONCommand(rune *command) {
  netpeer_t *np = N_GetPeer(0);
  CHECK_CONNECTION(np);

  N_PackRCONCommand(np, command);
}

void CL_SendVoteRequest(rune *command) {
  netpeer_t *np = N_GetPeer(0);
  CHECK_CONNECTION(np);

  N_PackVoteRequest(np, command);
}

/* vi: set cindent et ts=2 sw=2: */

