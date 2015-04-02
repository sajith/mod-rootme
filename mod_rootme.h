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

#ifndef __mod_rootme_h__
#define __mod_rootme_h__

typedef struct sock_userdata_t sock_userdata_t;

typedef struct apr_socket_t
{
    apr_pool_t          *cntxt;
    int                  socketdes;
    int                  type;
    int                  protocol;
    apr_sockaddr_t      *local_addr;
    apr_sockaddr_t      *remote_addr;
    apr_interval_time_t  timeout;
    int                  local_port_unknown;
    int                  local_interface_unknown;
    int                  remote_addr_unknown;
    apr_int32_t          netmask;
    apr_int32_t          inherit;
    sock_userdata_t     *userdata;
} apr_socket_t;

#endif


