/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _CRYPT_H_RPCGEN
#define	_CRYPT_H_RPCGEN

#include <rpc/rpc.h>

#ifdef __cplusplus
extern "C" {
#endif


enum des_dir {
	ENCRYPT_DES = 0,
	DECRYPT_DES = 1
};
typedef enum des_dir des_dir;

enum des_mode {
	CBC_DES = 0,
	ECB_DES = 1
};
typedef enum des_mode des_mode;

struct desargs {
	u_char des_key[8];
	des_dir des_dir;
	des_mode des_mode;
	u_char des_ivec[8];
	struct {
		u_int desbuf_len;
		char *desbuf_val;
	} desbuf;
};
typedef struct desargs desargs;

struct desresp {
	struct {
		u_int desbuf_len;
		char *desbuf_val;
	} desbuf;
	u_char des_ivec[8];
	int stat;
};
typedef struct desresp desresp;

#define	CRYPT_PROG ((unsigned long)(600100029))
#define	CRYPT_VERS ((unsigned long)(1))

extern  void crypt_prog_1(struct svc_req *rqstp, SVCXPRT *transp);
#define	DES_CRYPT ((unsigned long)(1))
extern  desresp * des_crypt_1(desargs *, CLIENT *);
extern  desresp * des_crypt_1_svc(desargs *, struct svc_req *);
extern int crypt_prog_1_freeresult(SVCXPRT *, xdrproc_t, caddr_t);

/* the xdr functions */
extern  bool_t xdr_des_dir(XDR *, des_dir*);
extern  bool_t xdr_des_mode(XDR *, des_mode*);
extern  bool_t xdr_desargs(XDR *, desargs*);
extern  bool_t xdr_desresp(XDR *, desresp*);

#ifdef __cplusplus
}
#endif

#endif /* !_CRYPT_H_RPCGEN */