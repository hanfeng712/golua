/* Created by cgo - DO NOT EDIT. */
#include <stdlib.h>
#include "_cgo_export.h"

extern void crosscall2(void (*fn)(void *, int, __SIZE_TYPE__), void *, int, __SIZE_TYPE__);
extern __SIZE_TYPE__ _cgo_wait_runtime_init_done();
extern void _cgo_release_context(__SIZE_TYPE__);

extern char* _cgo_topofstack(void);
#define CGO_NO_SANITIZE_THREAD
#define _cgo_tsan_acquire()
#define _cgo_tsan_release()

extern void _cgoexp_1508cd6507c2_AddCallFuncGo(void *, int, __SIZE_TYPE__);

CGO_NO_SANITIZE_THREAD
GoInt AddCallFuncGo(GoString p0)
{
	__SIZE_TYPE__ _cgo_ctxt = _cgo_wait_runtime_init_done();
	struct {
		GoString p0;
		GoInt r0;
	} __attribute__((__packed__, __gcc_struct__)) a;
	a.p0 = p0;
	_cgo_tsan_release();
	crosscall2(_cgoexp_1508cd6507c2_AddCallFuncGo, &a, 24, _cgo_ctxt);
	_cgo_tsan_acquire();
	_cgo_release_context(_cgo_ctxt);
	return a.r0;
}
extern void _cgoexp_1508cd6507c2_GetGoTime(void *, int, __SIZE_TYPE__);

CGO_NO_SANITIZE_THREAD
void GetGoTime()
{
	__SIZE_TYPE__ _cgo_ctxt = _cgo_wait_runtime_init_done();
	struct {
		char unused;
	} __attribute__((__packed__, __gcc_struct__)) a;
	_cgo_tsan_release();
	crosscall2(_cgoexp_1508cd6507c2_GetGoTime, &a, 0, _cgo_ctxt);
	_cgo_tsan_acquire();
	_cgo_release_context(_cgo_ctxt);
}

CGO_NO_SANITIZE_THREAD
void _cgo_1508cd6507c2_Cfunc__Cmalloc(void *v) {
	struct {
		unsigned long long p0;
		void *r1;
	} __attribute__((__packed__, __gcc_struct__)) *a = v;
	void *ret;
	_cgo_tsan_acquire();
	ret = malloc(a->p0);
	if (ret == 0 && a->p0 == 0) {
		ret = malloc(1);
	}
	a->r1 = ret;
	_cgo_tsan_release();
}
