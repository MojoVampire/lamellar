/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* ** This file is auto-generated, do not edit ** */

#include "pmi_config.h"

#include "mpl.h"

#include "pmi_util.h"

#include "pmi_common.h"

#include "pmi_wire.h"

#include "pmi_msg.h"

int PMIU_msg_cmd_to_id(const char *cmd)
{
    if (strcmp(cmd, "init") == 0) {
        return PMIU_CMD_INIT;
    } else if (strcmp(cmd, "initack") == 0 || strcmp(cmd, "fullinit") == 0) {
        return PMIU_CMD_FULLINIT;
    } else if (strcmp(cmd, "finalize") == 0) {
        return PMIU_CMD_FINALIZE;
    } else if (strcmp(cmd, "abort") == 0) {
        return PMIU_CMD_ABORT;
    } else if (strcmp(cmd, "get_maxes") == 0) {
        return PMIU_CMD_MAXES;
    } else if (strcmp(cmd, "get_universe_size") == 0) {
        return PMIU_CMD_UNIVERSE;
    } else if (strcmp(cmd, "get_appnum") == 0) {
        return PMIU_CMD_APPNUM;
    } else if (strcmp(cmd, "get_my_kvsname") == 0 || strcmp(cmd, "job-getid") == 0) {
        return PMIU_CMD_KVSNAME;
    } else if (strcmp(cmd, "put") == 0) {
        return PMIU_CMD_PUT;
    } else if (strcmp(cmd, "get") == 0 || strcmp(cmd, "info-getjobattr") == 0) {
        return PMIU_CMD_GET;
    } else if (strcmp(cmd, "barrier_in") == 0) {
        return PMIU_CMD_BARRIER;
    } else if (strcmp(cmd, "publish_name") == 0 || strcmp(cmd, "name-publish") == 0) {
        return PMIU_CMD_PUBLISH;
    } else if (strcmp(cmd, "unpublish_name") == 0 || strcmp(cmd, "name-unpublish") == 0) {
        return PMIU_CMD_UNPUBLISH;
    } else if (strcmp(cmd, "lookup_name") == 0 || strcmp(cmd, "name-lookup") == 0) {
        return PMIU_CMD_LOOKUP;
    } else if (strcmp(cmd, "spawn") == 0) {
        return PMIU_CMD_SPAWN;
    } else if (strcmp(cmd, "singinit") == 0) {
        return PMIU_CMD_SINGINIT;
    } else if (strcmp(cmd, "mput") == 0) {
        return PMIU_CMD_MPUT;
    } else if (strcmp(cmd, "keyval_cache") == 0) {
        return PMIU_CMD_KVSCACHE;
    } else if (strcmp(cmd, "barrier_out") == 0) {
        return PMIU_CMD_BARRIEROUT;
    } else if (strcmp(cmd, "info-putnodeattr") == 0) {
        return PMIU_CMD_PUTNODEATTR;
    } else if (strcmp(cmd, "info-getnodeattr") == 0) {
        return PMIU_CMD_GETNODEATTR;
    } else if (strcmp(cmd, "kvs-put") == 0) {
        return PMIU_CMD_KVSPUT;
    } else if (strcmp(cmd, "kvs-get") == 0) {
        return PMIU_CMD_KVSGET;
    } else if (strcmp(cmd, "kvs-fence") == 0) {
        return PMIU_CMD_KVSFENCE;
    } else if (strcmp(cmd, "job-connect") == 0) {
        return PMIU_CMD_CONNECT;
    } else if (strcmp(cmd, "job-disconnect") == 0) {
        return PMIU_CMD_DISCONNECT;
    } else {
        return PMIU_CMD_INVALID;
    }
}

const char *PMIU_msg_id_to_query(int version, int cmd_id)
{
    switch(cmd_id) {
        case PMIU_CMD_INIT:
            return "init";
        case PMIU_CMD_FULLINIT:
            return (version == PMIU_WIRE_V1) ? "initack" : "fullinit";
        case PMIU_CMD_FINALIZE:
            return "finalize";
        case PMIU_CMD_ABORT:
            return "abort";
        case PMIU_CMD_MAXES:
            return "get_maxes";
        case PMIU_CMD_UNIVERSE:
            return "get_universe_size";
        case PMIU_CMD_APPNUM:
            return "get_appnum";
        case PMIU_CMD_KVSNAME:
            return (version == PMIU_WIRE_V1) ? "get_my_kvsname" : "job-getid";
        case PMIU_CMD_PUT:
            return "put";
        case PMIU_CMD_GET:
            return (version == PMIU_WIRE_V1) ? "get" : "info-getjobattr";
        case PMIU_CMD_BARRIER:
            return "barrier_in";
        case PMIU_CMD_PUBLISH:
            return (version == PMIU_WIRE_V1) ? "publish_name" : "name-publish";
        case PMIU_CMD_UNPUBLISH:
            return (version == PMIU_WIRE_V1) ? "unpublish_name" : "name-unpublish";
        case PMIU_CMD_LOOKUP:
            return (version == PMIU_WIRE_V1) ? "lookup_name" : "name-lookup";
        case PMIU_CMD_SPAWN:
            return "spawn";
        case PMIU_CMD_SINGINIT:
            return "singinit";
        case PMIU_CMD_MPUT:
            return "mput";
        case PMIU_CMD_KVSCACHE:
            return "keyval_cache";
        case PMIU_CMD_BARRIEROUT:
            return "barrier_out";
        case PMIU_CMD_PUTNODEATTR:
            return "info-putnodeattr";
        case PMIU_CMD_GETNODEATTR:
            return "info-getnodeattr";
        case PMIU_CMD_KVSPUT:
            return "kvs-put";
        case PMIU_CMD_KVSGET:
            return "kvs-get";
        case PMIU_CMD_KVSFENCE:
            return "kvs-fence";
        case PMIU_CMD_CONNECT:
            return "job-connect";
        case PMIU_CMD_DISCONNECT:
            return "job-disconnect";
        default:
            return NULL;
    }
}

const char *PMIU_msg_id_to_response(int version, int cmd_id)
{
    switch(cmd_id) {
        case PMIU_CMD_INIT:
            return "response_to_init";
        case PMIU_CMD_FULLINIT:
            return (version == PMIU_WIRE_V1) ? "initack" : "fullinit-response";
        case PMIU_CMD_FINALIZE:
            return (version == PMIU_WIRE_V1) ? "finalize_ack" : "finalize-response";
        case PMIU_CMD_MAXES:
            return "maxes";
        case PMIU_CMD_UNIVERSE:
            return "universe_size";
        case PMIU_CMD_APPNUM:
            return "appnum";
        case PMIU_CMD_KVSNAME:
            return (version == PMIU_WIRE_V1) ? "my_kvsname" : "job-getid-response";
        case PMIU_CMD_PUT:
            return "put_result";
        case PMIU_CMD_GET:
            return (version == PMIU_WIRE_V1) ? "get_result" : "info-getjobattr-response";
        case PMIU_CMD_BARRIER:
            return "barrier_out";
        case PMIU_CMD_PUBLISH:
            return (version == PMIU_WIRE_V1) ? "publish_result" : "name-publish-response";
        case PMIU_CMD_UNPUBLISH:
            return (version == PMIU_WIRE_V1) ? "unpublish_result" : "name-unpublish-response";
        case PMIU_CMD_LOOKUP:
            return (version == PMIU_WIRE_V1) ? "lookup_result" : "name-lookup-response";
        case PMIU_CMD_SPAWN:
            return (version == PMIU_WIRE_V1) ? "spawn_result" : "spawn-response";
        case PMIU_CMD_SINGINIT:
            return "singinit_info";
        case PMIU_CMD_PUTNODEATTR:
            return "info-putnodeattr-response";
        case PMIU_CMD_GETNODEATTR:
            return "info-getnodeattr-response";
        case PMIU_CMD_KVSPUT:
            return "kvs-put-response";
        case PMIU_CMD_KVSGET:
            return "kvs-get-response";
        case PMIU_CMD_KVSFENCE:
            return "kvs-fence-response";
        case PMIU_CMD_CONNECT:
            return "job-connect-response";
        case PMIU_CMD_DISCONNECT:
            return "job-disconnect-response";
        default:
            return NULL;
    }
}


void PMIU_msg_set_query_init(struct PMIU_cmd *pmi_query, int version, bool is_static, int pmi_version, int pmi_subversion)
{
    PMIU_msg_set_query(pmi_query, version, PMIU_CMD_INIT, is_static);
    PMIU_cmd_add_int(pmi_query, "pmi_version", pmi_version);
    PMIU_cmd_add_int(pmi_query, "pmi_subversion", pmi_subversion);
}

int PMIU_msg_get_query_init(struct PMIU_cmd *pmi, int *pmi_version, int *pmi_subversion)
{
    int pmi_errno = PMIU_SUCCESS;

    PMIU_CMD_GET_INTVAL(pmi, "pmi_version", *pmi_version);
    PMIU_CMD_GET_INTVAL(pmi, "pmi_subversion", *pmi_subversion);

  fn_exit:
    return pmi_errno;
  fn_fail:
    goto fn_exit;
}

int PMIU_msg_set_response_init(struct PMIU_cmd *pmi_query, struct PMIU_cmd *pmi_resp, bool is_static, int pmi_version, int pmi_subversion)
{
    int pmi_errno = PMIU_SUCCESS;

    PMIU_Assert(pmi_query->cmd_id == PMIU_CMD_INIT);
    pmi_errno = PMIU_msg_set_response(pmi_query, pmi_resp, is_static);
    PMIU_cmd_add_int(pmi_resp, "pmi_version", pmi_version);
    PMIU_cmd_add_int(pmi_resp, "pmi_subversion", pmi_subversion);

    return pmi_errno;
}

int PMIU_msg_get_response_init(struct PMIU_cmd *pmi, int *pmi_version, int *pmi_subversion)
{
    int pmi_errno = PMIU_SUCCESS;

    PMIU_CMD_GET_INTVAL(pmi, "pmi_version", *pmi_version);
    PMIU_CMD_GET_INTVAL(pmi, "pmi_subversion", *pmi_subversion);

  fn_exit:
    return pmi_errno;
  fn_fail:
    goto fn_exit;
}

void PMIU_msg_set_query_fullinit(struct PMIU_cmd *pmi_query, int version, bool is_static, int pmiid)
{
    PMIU_msg_set_query(pmi_query, version, PMIU_CMD_FULLINIT, is_static);
    if (version == PMIU_WIRE_V1) {
        PMIU_cmd_add_int(pmi_query, "pmiid", pmiid);
    } else if (version == PMIU_WIRE_V2) {
        PMIU_cmd_add_int(pmi_query, "pmirank", pmiid);
    }
}

int PMIU_msg_get_query_fullinit(struct PMIU_cmd *pmi, int *pmiid)
{
    int pmi_errno = PMIU_SUCCESS;

    if (pmi->version == PMIU_WIRE_V1) {
        PMIU_CMD_GET_INTVAL(pmi, "pmiid", *pmiid);
    } else if (pmi->version == PMIU_WIRE_V2) {
        PMIU_CMD_GET_INTVAL(pmi, "pmirank", *pmiid);
    } else {
        PMIU_ERR_SETANDJUMP(pmi_errno, PMIU_FAIL, "invalid version");
    }

  fn_exit:
    return pmi_errno;
  fn_fail:
    goto fn_exit;
}

int PMIU_msg_set_response_fullinit(struct PMIU_cmd *pmi_query, struct PMIU_cmd *pmi_resp, bool is_static, int rank, int size, int appnum, const char *spawner_jobid, int debug)
{
    int pmi_errno = PMIU_SUCCESS;

    PMIU_Assert(pmi_query->cmd_id == PMIU_CMD_FULLINIT);
    pmi_errno = PMIU_msg_set_response(pmi_query, pmi_resp, is_static);
    if (pmi_query->version == PMIU_WIRE_V1) {
        PMIU_cmd_add_int(pmi_resp, "rank", rank);
        PMIU_cmd_add_int(pmi_resp, "size", size);
        if (appnum != -1) {
            PMIU_cmd_add_int(pmi_resp, "appnum", appnum);
        }
        if (spawner_jobid) {
            PMIU_cmd_add_str(pmi_resp, "spawner-jobid", spawner_jobid);
        }
        PMIU_cmd_add_int(pmi_resp, "debug", debug);
    } else if (pmi_query->version == PMIU_WIRE_V2) {
        PMIU_cmd_add_int(pmi_resp, "rank", rank);
        PMIU_cmd_add_int(pmi_resp, "size", size);
        PMIU_cmd_add_int(pmi_resp, "appnum", appnum);
        if (spawner_jobid) {
            PMIU_cmd_add_str(pmi_resp, "spawner-jobid", spawner_jobid);
        }
        PMIU_cmd_add_int(pmi_resp, "pmiverbose", debug);
    } else {
        PMIU_ERR_SETANDJUMP(pmi_errno, PMIU_FAIL, "invalid version");
    }

  fn_exit:
    return pmi_errno;
  fn_fail:
    goto fn_exit;
}

int PMIU_msg_get_response_fullinit(struct PMIU_cmd *pmi, int *rank, int *size, int *appnum, const char **spawner_jobid, int *debug)
{
    int pmi_errno = PMIU_SUCCESS;

    if (pmi->version == PMIU_WIRE_V1) {
        PMIU_CMD_GET_INTVAL(pmi, "rank", *rank);
        PMIU_CMD_GET_INTVAL(pmi, "size", *size);
        PMIU_CMD_GET_INTVAL_WITH_DEFAULT(pmi, "appnum", *appnum, -1);
        PMIU_CMD_GET_STRVAL_WITH_DEFAULT(pmi, "spawner-jobid", *spawner_jobid, NULL);
        PMIU_CMD_GET_INTVAL(pmi, "debug", *debug);
    } else if (pmi->version == PMIU_WIRE_V2) {
        PMIU_CMD_GET_INTVAL(pmi, "rank", *rank);
        PMIU_CMD_GET_INTVAL(pmi, "size", *size);
        PMIU_CMD_GET_INTVAL(pmi, "appnum", *appnum);
        PMIU_CMD_GET_STRVAL_WITH_DEFAULT(pmi, "spawner-jobid", *spawner_jobid, NULL);
        PMIU_CMD_GET_INTVAL(pmi, "pmiverbose", *debug);
    } else {
        PMIU_ERR_SETANDJUMP(pmi_errno, PMIU_FAIL, "invalid version");
    }

  fn_exit:
    return pmi_errno;
  fn_fail:
    goto fn_exit;
}

void PMIU_msg_set_query_abort(struct PMIU_cmd *pmi_query, int version, bool is_static, int exitcode, const char *message)
{
    PMIU_msg_set_query(pmi_query, version, PMIU_CMD_ABORT, is_static);
    if (version == PMIU_WIRE_V1) {
        PMIU_cmd_add_int(pmi_query, "exitcode", exitcode);
        if (message) {
            PMIU_cmd_add_str(pmi_query, "message", message);
        }
    } else if (version == PMIU_WIRE_V2) {
        if (exitcode != 1) {
            PMIU_cmd_add_int(pmi_query, "exitcode", exitcode);
        }
        if (message) {
            PMIU_cmd_add_str(pmi_query, "message", message);
        }
    }
}

int PMIU_msg_get_query_abort(struct PMIU_cmd *pmi, int *exitcode, const char **message)
{
    int pmi_errno = PMIU_SUCCESS;

    if (pmi->version == PMIU_WIRE_V1) {
        PMIU_CMD_GET_INTVAL(pmi, "exitcode", *exitcode);
        PMIU_CMD_GET_STRVAL_WITH_DEFAULT(pmi, "message", *message, NULL);
    } else if (pmi->version == PMIU_WIRE_V2) {
        PMIU_CMD_GET_INTVAL_WITH_DEFAULT(pmi, "exitcode", *exitcode, 1);
        PMIU_CMD_GET_STRVAL_WITH_DEFAULT(pmi, "message", *message, NULL);
    } else {
        PMIU_ERR_SETANDJUMP(pmi_errno, PMIU_FAIL, "invalid version");
    }

  fn_exit:
    return pmi_errno;
  fn_fail:
    goto fn_exit;
}

int PMIU_msg_set_response_maxes(struct PMIU_cmd *pmi_query, struct PMIU_cmd *pmi_resp, bool is_static, int kvsname_max, int keylen_max, int vallen_max)
{
    int pmi_errno = PMIU_SUCCESS;

    PMIU_Assert(pmi_query->cmd_id == PMIU_CMD_MAXES);
    pmi_errno = PMIU_msg_set_response(pmi_query, pmi_resp, is_static);
    PMIU_cmd_add_int(pmi_resp, "kvsname_max", kvsname_max);
    PMIU_cmd_add_int(pmi_resp, "keylen_max", keylen_max);
    PMIU_cmd_add_int(pmi_resp, "vallen_max", vallen_max);

    return pmi_errno;
}

int PMIU_msg_get_response_maxes(struct PMIU_cmd *pmi, int *kvsname_max, int *keylen_max, int *vallen_max)
{
    int pmi_errno = PMIU_SUCCESS;

    PMIU_CMD_GET_INTVAL(pmi, "kvsname_max", *kvsname_max);
    PMIU_CMD_GET_INTVAL(pmi, "keylen_max", *keylen_max);
    PMIU_CMD_GET_INTVAL(pmi, "vallen_max", *vallen_max);

  fn_exit:
    return pmi_errno;
  fn_fail:
    goto fn_exit;
}

int PMIU_msg_set_response_universe(struct PMIU_cmd *pmi_query, struct PMIU_cmd *pmi_resp, bool is_static, int size)
{
    int pmi_errno = PMIU_SUCCESS;

    PMIU_Assert(pmi_query->cmd_id == PMIU_CMD_UNIVERSE);
    pmi_errno = PMIU_msg_set_response(pmi_query, pmi_resp, is_static);
    PMIU_cmd_add_int(pmi_resp, "size", size);

    return pmi_errno;
}

int PMIU_msg_get_response_universe(struct PMIU_cmd *pmi, int *size)
{
    int pmi_errno = PMIU_SUCCESS;

    PMIU_CMD_GET_INTVAL(pmi, "size", *size);

  fn_exit:
    return pmi_errno;
  fn_fail:
    goto fn_exit;
}

int PMIU_msg_set_response_appnum(struct PMIU_cmd *pmi_query, struct PMIU_cmd *pmi_resp, bool is_static, int appnum)
{
    int pmi_errno = PMIU_SUCCESS;

    PMIU_Assert(pmi_query->cmd_id == PMIU_CMD_APPNUM);
    pmi_errno = PMIU_msg_set_response(pmi_query, pmi_resp, is_static);
    PMIU_cmd_add_int(pmi_resp, "appnum", appnum);

    return pmi_errno;
}

int PMIU_msg_get_response_appnum(struct PMIU_cmd *pmi, int *appnum)
{
    int pmi_errno = PMIU_SUCCESS;

    PMIU_CMD_GET_INTVAL(pmi, "appnum", *appnum);

  fn_exit:
    return pmi_errno;
  fn_fail:
    goto fn_exit;
}

int PMIU_msg_set_response_kvsname(struct PMIU_cmd *pmi_query, struct PMIU_cmd *pmi_resp, bool is_static, const char *kvsname)
{
    int pmi_errno = PMIU_SUCCESS;

    PMIU_Assert(pmi_query->cmd_id == PMIU_CMD_KVSNAME);
    pmi_errno = PMIU_msg_set_response(pmi_query, pmi_resp, is_static);
    if (pmi_query->version == PMIU_WIRE_V1) {
        PMIU_cmd_add_str(pmi_resp, "kvsname", kvsname);
    } else if (pmi_query->version == PMIU_WIRE_V2) {
        PMIU_cmd_add_str(pmi_resp, "jobid", kvsname);
    } else {
        PMIU_ERR_SETANDJUMP(pmi_errno, PMIU_FAIL, "invalid version");
    }

  fn_exit:
    return pmi_errno;
  fn_fail:
    goto fn_exit;
}

int PMIU_msg_get_response_kvsname(struct PMIU_cmd *pmi, const char **kvsname)
{
    int pmi_errno = PMIU_SUCCESS;

    if (pmi->version == PMIU_WIRE_V1) {
        PMIU_CMD_GET_STRVAL(pmi, "kvsname", *kvsname);
    } else if (pmi->version == PMIU_WIRE_V2) {
        PMIU_CMD_GET_STRVAL(pmi, "jobid", *kvsname);
    } else {
        PMIU_ERR_SETANDJUMP(pmi_errno, PMIU_FAIL, "invalid version");
    }

  fn_exit:
    return pmi_errno;
  fn_fail:
    goto fn_exit;
}

void PMIU_msg_set_query_put(struct PMIU_cmd *pmi_query, int version, bool is_static, const char *kvsname, const char *key, const char *value)
{
    PMIU_msg_set_query(pmi_query, version, PMIU_CMD_PUT, is_static);
    if (kvsname) {
        PMIU_cmd_add_str(pmi_query, "kvsname", kvsname);
    }
    PMIU_cmd_add_str(pmi_query, "key", key);
    PMIU_cmd_add_str(pmi_query, "value", value);
}

int PMIU_msg_get_query_put(struct PMIU_cmd *pmi, const char **kvsname, const char **key, const char **value)
{
    int pmi_errno = PMIU_SUCCESS;

    PMIU_CMD_GET_STRVAL_WITH_DEFAULT(pmi, "kvsname", *kvsname, NULL);
    PMIU_CMD_GET_STRVAL(pmi, "key", *key);
    PMIU_CMD_GET_STRVAL(pmi, "value", *value);

  fn_exit:
    return pmi_errno;
  fn_fail:
    goto fn_exit;
}

void PMIU_msg_set_query_get(struct PMIU_cmd *pmi_query, int version, bool is_static, const char *kvsname, const char *key)
{
    PMIU_msg_set_query(pmi_query, version, PMIU_CMD_GET, is_static);
    if (kvsname) {
        PMIU_cmd_add_str(pmi_query, "kvsname", kvsname);
    }
    PMIU_cmd_add_str(pmi_query, "key", key);
}

int PMIU_msg_get_query_get(struct PMIU_cmd *pmi, const char **kvsname, const char **key)
{
    int pmi_errno = PMIU_SUCCESS;

    PMIU_CMD_GET_STRVAL_WITH_DEFAULT(pmi, "kvsname", *kvsname, NULL);
    PMIU_CMD_GET_STRVAL(pmi, "key", *key);

  fn_exit:
    return pmi_errno;
  fn_fail:
    goto fn_exit;
}

int PMIU_msg_set_response_get(struct PMIU_cmd *pmi_query, struct PMIU_cmd *pmi_resp, bool is_static, bool found, const char *value)
{
    int pmi_errno = PMIU_SUCCESS;

    PMIU_Assert(pmi_query->cmd_id == PMIU_CMD_GET);
    pmi_errno = PMIU_msg_set_response(pmi_query, pmi_resp, is_static);
    if (pmi_query->version == PMIU_WIRE_V1) {
        if (!found) {
            PMIU_cmd_add_bool(pmi_resp, "found", found);
        }
        PMIU_cmd_add_str(pmi_resp, "value", value);
    } else if (pmi_query->version == PMIU_WIRE_V2) {
        PMIU_cmd_add_bool(pmi_resp, "found", found);
        PMIU_cmd_add_str(pmi_resp, "value", value);
    } else {
        PMIU_ERR_SETANDJUMP(pmi_errno, PMIU_FAIL, "invalid version");
    }

  fn_exit:
    return pmi_errno;
  fn_fail:
    goto fn_exit;
}

int PMIU_msg_get_response_get(struct PMIU_cmd *pmi, bool *found, const char **value)
{
    int pmi_errno = PMIU_SUCCESS;

    if (pmi->version == PMIU_WIRE_V1) {
        PMIU_CMD_GET_BOOLVAL_WITH_DEFAULT(pmi, "found", *found, true);
        PMIU_CMD_GET_STRVAL(pmi, "value", *value);
    } else if (pmi->version == PMIU_WIRE_V2) {
        PMIU_CMD_GET_BOOLVAL(pmi, "found", *found);
        PMIU_CMD_GET_STRVAL(pmi, "value", *value);
    } else {
        PMIU_ERR_SETANDJUMP(pmi_errno, PMIU_FAIL, "invalid version");
    }

  fn_exit:
    return pmi_errno;
  fn_fail:
    goto fn_exit;
}

void PMIU_msg_set_query_barrier(struct PMIU_cmd *pmi_query, int version, bool is_static, const char *group)
{
    PMIU_msg_set_query(pmi_query, version, PMIU_CMD_BARRIER, is_static);
    if (group) {
        PMIU_cmd_add_str(pmi_query, "group", group);
    }
}

int PMIU_msg_get_query_barrier(struct PMIU_cmd *pmi, const char **group)
{
    int pmi_errno = PMIU_SUCCESS;

    PMIU_CMD_GET_STRVAL_WITH_DEFAULT(pmi, "group", *group, NULL);

    return pmi_errno;
}

int PMIU_msg_set_response_barrier(struct PMIU_cmd *pmi_query, struct PMIU_cmd *pmi_resp, bool is_static, int tag)
{
    int pmi_errno = PMIU_SUCCESS;

    PMIU_Assert(pmi_query->cmd_id == PMIU_CMD_BARRIER);
    pmi_errno = PMIU_msg_set_response(pmi_query, pmi_resp, is_static);
    if (tag != 0) {
        PMIU_cmd_add_int(pmi_resp, "tag", tag);
    }

    return pmi_errno;
}

int PMIU_msg_get_response_barrier(struct PMIU_cmd *pmi, int *tag)
{
    int pmi_errno = PMIU_SUCCESS;

    PMIU_CMD_GET_INTVAL_WITH_DEFAULT(pmi, "tag", *tag, 0);

    return pmi_errno;
}

void PMIU_msg_set_query_publish(struct PMIU_cmd *pmi_query, int version, bool is_static, const char *service, const char *port)
{
    PMIU_msg_set_query(pmi_query, version, PMIU_CMD_PUBLISH, is_static);
    if (version == PMIU_WIRE_V1) {
        PMIU_cmd_add_str(pmi_query, "service", service);
        PMIU_cmd_add_str(pmi_query, "port", port);
    } else if (version == PMIU_WIRE_V2) {
        PMIU_cmd_add_str(pmi_query, "name", service);
        PMIU_cmd_add_str(pmi_query, "port", port);
    }
}

int PMIU_msg_get_query_publish(struct PMIU_cmd *pmi, const char **service, const char **port)
{
    int pmi_errno = PMIU_SUCCESS;

    if (pmi->version == PMIU_WIRE_V1) {
        PMIU_CMD_GET_STRVAL(pmi, "service", *service);
        PMIU_CMD_GET_STRVAL(pmi, "port", *port);
    } else if (pmi->version == PMIU_WIRE_V2) {
        PMIU_CMD_GET_STRVAL(pmi, "name", *service);
        PMIU_CMD_GET_STRVAL(pmi, "port", *port);
    } else {
        PMIU_ERR_SETANDJUMP(pmi_errno, PMIU_FAIL, "invalid version");
    }

  fn_exit:
    return pmi_errno;
  fn_fail:
    goto fn_exit;
}

void PMIU_msg_set_query_unpublish(struct PMIU_cmd *pmi_query, int version, bool is_static, const char *service)
{
    PMIU_msg_set_query(pmi_query, version, PMIU_CMD_UNPUBLISH, is_static);
    if (version == PMIU_WIRE_V1) {
        PMIU_cmd_add_str(pmi_query, "service", service);
    } else if (version == PMIU_WIRE_V2) {
        PMIU_cmd_add_str(pmi_query, "name", service);
    }
}

int PMIU_msg_get_query_unpublish(struct PMIU_cmd *pmi, const char **service)
{
    int pmi_errno = PMIU_SUCCESS;

    if (pmi->version == PMIU_WIRE_V1) {
        PMIU_CMD_GET_STRVAL(pmi, "service", *service);
    } else if (pmi->version == PMIU_WIRE_V2) {
        PMIU_CMD_GET_STRVAL(pmi, "name", *service);
    } else {
        PMIU_ERR_SETANDJUMP(pmi_errno, PMIU_FAIL, "invalid version");
    }

  fn_exit:
    return pmi_errno;
  fn_fail:
    goto fn_exit;
}

void PMIU_msg_set_query_lookup(struct PMIU_cmd *pmi_query, int version, bool is_static, const char *service)
{
    PMIU_msg_set_query(pmi_query, version, PMIU_CMD_LOOKUP, is_static);
    if (version == PMIU_WIRE_V1) {
        PMIU_cmd_add_str(pmi_query, "service", service);
    } else if (version == PMIU_WIRE_V2) {
        PMIU_cmd_add_str(pmi_query, "name", service);
    }
}

int PMIU_msg_get_query_lookup(struct PMIU_cmd *pmi, const char **service)
{
    int pmi_errno = PMIU_SUCCESS;

    if (pmi->version == PMIU_WIRE_V1) {
        PMIU_CMD_GET_STRVAL(pmi, "service", *service);
    } else if (pmi->version == PMIU_WIRE_V2) {
        PMIU_CMD_GET_STRVAL(pmi, "name", *service);
    } else {
        PMIU_ERR_SETANDJUMP(pmi_errno, PMIU_FAIL, "invalid version");
    }

  fn_exit:
    return pmi_errno;
  fn_fail:
    goto fn_exit;
}

int PMIU_msg_set_response_lookup(struct PMIU_cmd *pmi_query, struct PMIU_cmd *pmi_resp, bool is_static, const char *port)
{
    int pmi_errno = PMIU_SUCCESS;

    PMIU_Assert(pmi_query->cmd_id == PMIU_CMD_LOOKUP);
    pmi_errno = PMIU_msg_set_response(pmi_query, pmi_resp, is_static);
    PMIU_cmd_add_str(pmi_resp, "port", port);

    return pmi_errno;
}

int PMIU_msg_get_response_lookup(struct PMIU_cmd *pmi, const char **port)
{
    int pmi_errno = PMIU_SUCCESS;

    PMIU_CMD_GET_STRVAL(pmi, "port", *port);

  fn_exit:
    return pmi_errno;
  fn_fail:
    goto fn_exit;
}

void PMIU_msg_set_query_singinit(struct PMIU_cmd *pmi_query, int version, bool is_static, int pmi_version, int pmi_subversion, const char *stdio, const char *authtype)
{
    PMIU_msg_set_query(pmi_query, version, PMIU_CMD_SINGINIT, is_static);
    PMIU_cmd_add_int(pmi_query, "pmi_version", pmi_version);
    PMIU_cmd_add_int(pmi_query, "pmi_subversion", pmi_subversion);
    if (strcmp(stdio, "yes") == 0) {
        PMIU_cmd_add_str(pmi_query, "stdio", stdio);
    }
    if (strcmp(authtype, "none") == 0) {
        PMIU_cmd_add_str(pmi_query, "authtype", authtype);
    }
}

int PMIU_msg_get_query_singinit(struct PMIU_cmd *pmi, int *pmi_version, int *pmi_subversion, const char **stdio, const char **authtype)
{
    int pmi_errno = PMIU_SUCCESS;

    PMIU_CMD_GET_INTVAL(pmi, "pmi_version", *pmi_version);
    PMIU_CMD_GET_INTVAL(pmi, "pmi_subversion", *pmi_subversion);
    PMIU_CMD_GET_STRVAL_WITH_DEFAULT(pmi, "stdio", *stdio, "yes");
    PMIU_CMD_GET_STRVAL_WITH_DEFAULT(pmi, "authtype", *authtype, "none");

  fn_exit:
    return pmi_errno;
  fn_fail:
    goto fn_exit;
}

int PMIU_msg_set_response_singinit(struct PMIU_cmd *pmi_query, struct PMIU_cmd *pmi_resp, bool is_static, const char *versionok, const char *stdio, const char *kvsname)
{
    int pmi_errno = PMIU_SUCCESS;

    PMIU_Assert(pmi_query->cmd_id == PMIU_CMD_SINGINIT);
    pmi_errno = PMIU_msg_set_response(pmi_query, pmi_resp, is_static);
    PMIU_cmd_add_str(pmi_resp, "versionok", versionok);
    if (strcmp(stdio, "yes") == 0) {
        PMIU_cmd_add_str(pmi_resp, "stdio", stdio);
    }
    PMIU_cmd_add_str(pmi_resp, "kvsname", kvsname);

    return pmi_errno;
}

int PMIU_msg_get_response_singinit(struct PMIU_cmd *pmi, const char **versionok, const char **stdio, const char **kvsname)
{
    int pmi_errno = PMIU_SUCCESS;

    PMIU_CMD_GET_STRVAL(pmi, "versionok", *versionok);
    PMIU_CMD_GET_STRVAL_WITH_DEFAULT(pmi, "stdio", *stdio, "yes");
    PMIU_CMD_GET_STRVAL(pmi, "kvsname", *kvsname);

  fn_exit:
    return pmi_errno;
  fn_fail:
    goto fn_exit;
}

void PMIU_msg_set_query_putnodeattr(struct PMIU_cmd *pmi_query, int version, bool is_static, const char *key, const char *value)
{
    PMIU_msg_set_query(pmi_query, version, PMIU_CMD_PUTNODEATTR, is_static);
    PMIU_cmd_add_str(pmi_query, "key", key);
    PMIU_cmd_add_str(pmi_query, "value", value);
}

int PMIU_msg_get_query_putnodeattr(struct PMIU_cmd *pmi, const char **key, const char **value)
{
    int pmi_errno = PMIU_SUCCESS;

    PMIU_CMD_GET_STRVAL(pmi, "key", *key);
    PMIU_CMD_GET_STRVAL(pmi, "value", *value);

  fn_exit:
    return pmi_errno;
  fn_fail:
    goto fn_exit;
}

void PMIU_msg_set_query_getnodeattr(struct PMIU_cmd *pmi_query, int version, bool is_static, const char *key, bool wait)
{
    PMIU_msg_set_query(pmi_query, version, PMIU_CMD_GETNODEATTR, is_static);
    PMIU_cmd_add_str(pmi_query, "key", key);
    if (wait) {
        PMIU_cmd_add_bool(pmi_query, "wait", wait);
    }
}

int PMIU_msg_get_query_getnodeattr(struct PMIU_cmd *pmi, const char **key, bool *wait)
{
    int pmi_errno = PMIU_SUCCESS;

    PMIU_CMD_GET_STRVAL(pmi, "key", *key);
    PMIU_CMD_GET_BOOLVAL_WITH_DEFAULT(pmi, "wait", *wait, false);

  fn_exit:
    return pmi_errno;
  fn_fail:
    goto fn_exit;
}

int PMIU_msg_set_response_getnodeattr(struct PMIU_cmd *pmi_query, struct PMIU_cmd *pmi_resp, bool is_static, bool found, const char *value)
{
    int pmi_errno = PMIU_SUCCESS;

    PMIU_Assert(pmi_query->cmd_id == PMIU_CMD_GETNODEATTR);
    pmi_errno = PMIU_msg_set_response(pmi_query, pmi_resp, is_static);
    PMIU_cmd_add_bool(pmi_resp, "found", found);
    PMIU_cmd_add_str(pmi_resp, "value", value);

    return pmi_errno;
}

int PMIU_msg_get_response_getnodeattr(struct PMIU_cmd *pmi, bool *found, const char **value)
{
    int pmi_errno = PMIU_SUCCESS;

    PMIU_CMD_GET_BOOLVAL(pmi, "found", *found);
    PMIU_CMD_GET_STRVAL(pmi, "value", *value);

  fn_exit:
    return pmi_errno;
  fn_fail:
    goto fn_exit;
}

void PMIU_msg_set_query_kvsput(struct PMIU_cmd *pmi_query, int version, bool is_static, const char *key, const char *value)
{
    PMIU_msg_set_query(pmi_query, version, PMIU_CMD_KVSPUT, is_static);
    PMIU_cmd_add_str(pmi_query, "key", key);
    PMIU_cmd_add_str(pmi_query, "value", value);
}

int PMIU_msg_get_query_kvsput(struct PMIU_cmd *pmi, const char **key, const char **value)
{
    int pmi_errno = PMIU_SUCCESS;

    PMIU_CMD_GET_STRVAL(pmi, "key", *key);
    PMIU_CMD_GET_STRVAL(pmi, "value", *value);

  fn_exit:
    return pmi_errno;
  fn_fail:
    goto fn_exit;
}

void PMIU_msg_set_query_kvsget(struct PMIU_cmd *pmi_query, int version, bool is_static, const char *jobid, int srcid, const char *key)
{
    PMIU_msg_set_query(pmi_query, version, PMIU_CMD_KVSGET, is_static);
    if (jobid) {
        PMIU_cmd_add_str(pmi_query, "jobid", jobid);
    }
    if (srcid != -1) {
        PMIU_cmd_add_int(pmi_query, "srcid", srcid);
    }
    PMIU_cmd_add_str(pmi_query, "key", key);
}

int PMIU_msg_get_query_kvsget(struct PMIU_cmd *pmi, const char **jobid, int *srcid, const char **key)
{
    int pmi_errno = PMIU_SUCCESS;

    PMIU_CMD_GET_STRVAL_WITH_DEFAULT(pmi, "jobid", *jobid, NULL);
    PMIU_CMD_GET_INTVAL_WITH_DEFAULT(pmi, "srcid", *srcid, -1);
    PMIU_CMD_GET_STRVAL(pmi, "key", *key);

  fn_exit:
    return pmi_errno;
  fn_fail:
    goto fn_exit;
}

int PMIU_msg_set_response_kvsget(struct PMIU_cmd *pmi_query, struct PMIU_cmd *pmi_resp, bool is_static, bool found, const char *value)
{
    int pmi_errno = PMIU_SUCCESS;

    PMIU_Assert(pmi_query->cmd_id == PMIU_CMD_KVSGET);
    pmi_errno = PMIU_msg_set_response(pmi_query, pmi_resp, is_static);
    PMIU_cmd_add_bool(pmi_resp, "found", found);
    PMIU_cmd_add_str(pmi_resp, "value", value);

    return pmi_errno;
}

int PMIU_msg_get_response_kvsget(struct PMIU_cmd *pmi, bool *found, const char **value)
{
    int pmi_errno = PMIU_SUCCESS;

    PMIU_CMD_GET_BOOLVAL(pmi, "found", *found);
    PMIU_CMD_GET_STRVAL(pmi, "value", *value);

  fn_exit:
    return pmi_errno;
  fn_fail:
    goto fn_exit;
}

void PMIU_msg_set_query_connect(struct PMIU_cmd *pmi_query, int version, bool is_static, const char *jobid)
{
    PMIU_msg_set_query(pmi_query, version, PMIU_CMD_CONNECT, is_static);
    PMIU_cmd_add_str(pmi_query, "jobid", jobid);
}

int PMIU_msg_get_query_connect(struct PMIU_cmd *pmi, const char **jobid)
{
    int pmi_errno = PMIU_SUCCESS;

    PMIU_CMD_GET_STRVAL(pmi, "jobid", *jobid);

  fn_exit:
    return pmi_errno;
  fn_fail:
    goto fn_exit;
}

int PMIU_msg_set_response_connect(struct PMIU_cmd *pmi_query, struct PMIU_cmd *pmi_resp, bool is_static, int kvscopy)
{
    int pmi_errno = PMIU_SUCCESS;

    PMIU_Assert(pmi_query->cmd_id == PMIU_CMD_CONNECT);
    pmi_errno = PMIU_msg_set_response(pmi_query, pmi_resp, is_static);
    PMIU_cmd_add_int(pmi_resp, "kvscopy", kvscopy);

    return pmi_errno;
}

int PMIU_msg_get_response_connect(struct PMIU_cmd *pmi, int *kvscopy)
{
    int pmi_errno = PMIU_SUCCESS;

    PMIU_CMD_GET_INTVAL(pmi, "kvscopy", *kvscopy);

  fn_exit:
    return pmi_errno;
  fn_fail:
    goto fn_exit;
}

void PMIU_msg_set_query_disconnect(struct PMIU_cmd *pmi_query, int version, bool is_static, const char *jobid)
{
    PMIU_msg_set_query(pmi_query, version, PMIU_CMD_DISCONNECT, is_static);
    PMIU_cmd_add_str(pmi_query, "jobid", jobid);
}

int PMIU_msg_get_query_disconnect(struct PMIU_cmd *pmi, const char **jobid)
{
    int pmi_errno = PMIU_SUCCESS;

    PMIU_CMD_GET_STRVAL(pmi, "jobid", *jobid);

  fn_exit:
    return pmi_errno;
  fn_fail:
    goto fn_exit;
}
