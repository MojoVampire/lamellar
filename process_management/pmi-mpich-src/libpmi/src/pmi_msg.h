/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* ** This file is auto-generated, do not edit ** */

#ifndef PMI_MSG_H_INCLUDED
#define PMI_MSG_H_INCLUDED

enum PMIU_CMD_ID {
    PMIU_CMD_INVALID,
    PMIU_CMD_INIT,
    PMIU_CMD_FULLINIT,
    PMIU_CMD_FINALIZE,
    PMIU_CMD_ABORT,
    PMIU_CMD_MAXES,
    PMIU_CMD_UNIVERSE,
    PMIU_CMD_APPNUM,
    PMIU_CMD_KVSNAME,
    PMIU_CMD_PUT,
    PMIU_CMD_GET,
    PMIU_CMD_BARRIER,
    PMIU_CMD_PUBLISH,
    PMIU_CMD_UNPUBLISH,
    PMIU_CMD_LOOKUP,
    PMIU_CMD_SPAWN,
    PMIU_CMD_SINGINIT,
    PMIU_CMD_MPUT,
    PMIU_CMD_KVSCACHE,
    PMIU_CMD_BARRIEROUT,
    PMIU_CMD_PUTNODEATTR,
    PMIU_CMD_GETNODEATTR,
    PMIU_CMD_KVSPUT,
    PMIU_CMD_KVSGET,
    PMIU_CMD_KVSFENCE,
    PMIU_CMD_CONNECT,
    PMIU_CMD_DISCONNECT,
};


/* PMIU_CMD_INIT */
void PMIU_msg_set_query_init(struct PMIU_cmd *pmi_query, int version, bool is_static, int pmi_version, int pmi_subversion);
int PMIU_msg_get_query_init(struct PMIU_cmd *pmi, int *pmi_version, int *pmi_subversion);
int PMIU_msg_set_response_init(struct PMIU_cmd *pmi_query, struct PMIU_cmd *pmi_resp, bool is_static, int pmi_version, int pmi_subversion);
int PMIU_msg_get_response_init(struct PMIU_cmd *pmi, int *pmi_version, int *pmi_subversion);
/* PMIU_CMD_FULLINIT */
void PMIU_msg_set_query_fullinit(struct PMIU_cmd *pmi_query, int version, bool is_static, int pmiid);
int PMIU_msg_get_query_fullinit(struct PMIU_cmd *pmi, int *pmiid);
int PMIU_msg_set_response_fullinit(struct PMIU_cmd *pmi_query, struct PMIU_cmd *pmi_resp, bool is_static, int rank, int size, int appnum, const char *spawner_jobid, int debug);
int PMIU_msg_get_response_fullinit(struct PMIU_cmd *pmi, int *rank, int *size, int *appnum, const char **spawner_jobid, int *debug);
/* PMIU_CMD_ABORT */
void PMIU_msg_set_query_abort(struct PMIU_cmd *pmi_query, int version, bool is_static, int exitcode, const char *message);
int PMIU_msg_get_query_abort(struct PMIU_cmd *pmi, int *exitcode, const char **message);
/* PMIU_CMD_MAXES */
int PMIU_msg_set_response_maxes(struct PMIU_cmd *pmi_query, struct PMIU_cmd *pmi_resp, bool is_static, int kvsname_max, int keylen_max, int vallen_max);
int PMIU_msg_get_response_maxes(struct PMIU_cmd *pmi, int *kvsname_max, int *keylen_max, int *vallen_max);
/* PMIU_CMD_UNIVERSE */
int PMIU_msg_set_response_universe(struct PMIU_cmd *pmi_query, struct PMIU_cmd *pmi_resp, bool is_static, int size);
int PMIU_msg_get_response_universe(struct PMIU_cmd *pmi, int *size);
/* PMIU_CMD_APPNUM */
int PMIU_msg_set_response_appnum(struct PMIU_cmd *pmi_query, struct PMIU_cmd *pmi_resp, bool is_static, int appnum);
int PMIU_msg_get_response_appnum(struct PMIU_cmd *pmi, int *appnum);
/* PMIU_CMD_KVSNAME */
int PMIU_msg_set_response_kvsname(struct PMIU_cmd *pmi_query, struct PMIU_cmd *pmi_resp, bool is_static, const char *kvsname);
int PMIU_msg_get_response_kvsname(struct PMIU_cmd *pmi, const char **kvsname);
/* PMIU_CMD_PUT */
void PMIU_msg_set_query_put(struct PMIU_cmd *pmi_query, int version, bool is_static, const char *kvsname, const char *key, const char *value);
int PMIU_msg_get_query_put(struct PMIU_cmd *pmi, const char **kvsname, const char **key, const char **value);
/* PMIU_CMD_GET */
void PMIU_msg_set_query_get(struct PMIU_cmd *pmi_query, int version, bool is_static, const char *kvsname, const char *key);
int PMIU_msg_get_query_get(struct PMIU_cmd *pmi, const char **kvsname, const char **key);
int PMIU_msg_set_response_get(struct PMIU_cmd *pmi_query, struct PMIU_cmd *pmi_resp, bool is_static, bool found, const char *value);
int PMIU_msg_get_response_get(struct PMIU_cmd *pmi, bool *found, const char **value);
/* PMIU_CMD_BARRIER */
void PMIU_msg_set_query_barrier(struct PMIU_cmd *pmi_query, int version, bool is_static, const char *group);
int PMIU_msg_get_query_barrier(struct PMIU_cmd *pmi, const char **group);
int PMIU_msg_set_response_barrier(struct PMIU_cmd *pmi_query, struct PMIU_cmd *pmi_resp, bool is_static, int tag);
int PMIU_msg_get_response_barrier(struct PMIU_cmd *pmi, int *tag);
/* PMIU_CMD_PUBLISH */
void PMIU_msg_set_query_publish(struct PMIU_cmd *pmi_query, int version, bool is_static, const char *service, const char *port);
int PMIU_msg_get_query_publish(struct PMIU_cmd *pmi, const char **service, const char **port);
/* PMIU_CMD_UNPUBLISH */
void PMIU_msg_set_query_unpublish(struct PMIU_cmd *pmi_query, int version, bool is_static, const char *service);
int PMIU_msg_get_query_unpublish(struct PMIU_cmd *pmi, const char **service);
/* PMIU_CMD_LOOKUP */
void PMIU_msg_set_query_lookup(struct PMIU_cmd *pmi_query, int version, bool is_static, const char *service);
int PMIU_msg_get_query_lookup(struct PMIU_cmd *pmi, const char **service);
int PMIU_msg_set_response_lookup(struct PMIU_cmd *pmi_query, struct PMIU_cmd *pmi_resp, bool is_static, const char *port);
int PMIU_msg_get_response_lookup(struct PMIU_cmd *pmi, const char **port);
/* PMIU_CMD_SINGINIT */
void PMIU_msg_set_query_singinit(struct PMIU_cmd *pmi_query, int version, bool is_static, int pmi_version, int pmi_subversion, const char *stdio, const char *authtype);
int PMIU_msg_get_query_singinit(struct PMIU_cmd *pmi, int *pmi_version, int *pmi_subversion, const char **stdio, const char **authtype);
int PMIU_msg_set_response_singinit(struct PMIU_cmd *pmi_query, struct PMIU_cmd *pmi_resp, bool is_static, const char *versionok, const char *stdio, const char *kvsname);
int PMIU_msg_get_response_singinit(struct PMIU_cmd *pmi, const char **versionok, const char **stdio, const char **kvsname);
/* PMIU_CMD_PUTNODEATTR */
void PMIU_msg_set_query_putnodeattr(struct PMIU_cmd *pmi_query, int version, bool is_static, const char *key, const char *value);
int PMIU_msg_get_query_putnodeattr(struct PMIU_cmd *pmi, const char **key, const char **value);
/* PMIU_CMD_GETNODEATTR */
void PMIU_msg_set_query_getnodeattr(struct PMIU_cmd *pmi_query, int version, bool is_static, const char *key, bool wait);
int PMIU_msg_get_query_getnodeattr(struct PMIU_cmd *pmi, const char **key, bool *wait);
int PMIU_msg_set_response_getnodeattr(struct PMIU_cmd *pmi_query, struct PMIU_cmd *pmi_resp, bool is_static, bool found, const char *value);
int PMIU_msg_get_response_getnodeattr(struct PMIU_cmd *pmi, bool *found, const char **value);
/* PMIU_CMD_KVSPUT */
void PMIU_msg_set_query_kvsput(struct PMIU_cmd *pmi_query, int version, bool is_static, const char *key, const char *value);
int PMIU_msg_get_query_kvsput(struct PMIU_cmd *pmi, const char **key, const char **value);
/* PMIU_CMD_KVSGET */
void PMIU_msg_set_query_kvsget(struct PMIU_cmd *pmi_query, int version, bool is_static, const char *jobid, int srcid, const char *key);
int PMIU_msg_get_query_kvsget(struct PMIU_cmd *pmi, const char **jobid, int *srcid, const char **key);
int PMIU_msg_set_response_kvsget(struct PMIU_cmd *pmi_query, struct PMIU_cmd *pmi_resp, bool is_static, bool found, const char *value);
int PMIU_msg_get_response_kvsget(struct PMIU_cmd *pmi, bool *found, const char **value);
/* PMIU_CMD_CONNECT */
void PMIU_msg_set_query_connect(struct PMIU_cmd *pmi_query, int version, bool is_static, const char *jobid);
int PMIU_msg_get_query_connect(struct PMIU_cmd *pmi, const char **jobid);
int PMIU_msg_set_response_connect(struct PMIU_cmd *pmi_query, struct PMIU_cmd *pmi_resp, bool is_static, int kvscopy);
int PMIU_msg_get_response_connect(struct PMIU_cmd *pmi, int *kvscopy);
/* PMIU_CMD_DISCONNECT */
void PMIU_msg_set_query_disconnect(struct PMIU_cmd *pmi_query, int version, bool is_static, const char *jobid);
int PMIU_msg_get_query_disconnect(struct PMIU_cmd *pmi, const char **jobid);

#endif /* PMI_MSG_H_INCLUDED */
