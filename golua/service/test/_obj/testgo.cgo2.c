#line 3 "/home/hanfeng/golang/src/golua/service/test/testgo.go"



#include "testc.h"
#include <stdlib.h>

#line 1 "cgo-generated-wrapper"


#line 1 "cgo-gcc-prolog"
/*
  If x and y are not equal, the type will be invalid
  (have a negative array count) and an inscrutable error will come
  out of the compiler and hopefully mention "name".
*/
#define __cgo_compile_assert_eq(x, y, name) typedef char name[(x-y)*(x-y)*-2+1];

/* Check at compile time that the sizes we use match our expectations. */
#define __cgo_size_assert(t, n) __cgo_compile_assert_eq(sizeof(t), n, _cgo_sizeof_##t##_is_not_##n)

__cgo_size_assert(char, 1)
__cgo_size_assert(short, 2)
__cgo_size_assert(int, 4)
typedef long long __cgo_long_long;
__cgo_size_assert(__cgo_long_long, 8)
__cgo_size_assert(float, 4)
__cgo_size_assert(double, 8)

extern char* _cgo_topofstack(void);

#include <errno.h>
#include <string.h>


#define CGO_NO_SANITIZE_THREAD
#define _cgo_tsan_acquire()
#define _cgo_tsan_release()

CGO_NO_SANITIZE_THREAD
void
_cgo_1508cd6507c2_Cfunc_cAddFuncLua(void *v)
{
	struct {
		void* p0;
		int p1;
		char __pad12[4];
		int r;
		char __pad20[4];
	} __attribute__((__packed__, __gcc_struct__)) *a = v;
	char *stktop = _cgo_topofstack();
	__typeof__(a->r) r;
	_cgo_tsan_acquire();
	r = cAddFuncLua(a->p0, a->p1);
	_cgo_tsan_release();
	a = (void*)((char*)a + (_cgo_topofstack() - stktop));
	a->r = r;
}

CGO_NO_SANITIZE_THREAD
void
_cgo_1508cd6507c2_Cfunc_free(void *v)
{
	struct {
		void* p0;
	} __attribute__((__packed__, __gcc_struct__)) *a = v;
	_cgo_tsan_acquire();
	free(a->p0);
	_cgo_tsan_release();
}

CGO_NO_SANITIZE_THREAD
void
_cgo_1508cd6507c2_Cfunc_init_lua(void *v)
{
	struct {
		void* r;
	} __attribute__((__packed__, __gcc_struct__)) *a = v;
	char *stktop = _cgo_topofstack();
	__typeof__(a->r) r;
	_cgo_tsan_acquire();
	r = (__typeof__(a->r)) init_lua();
	_cgo_tsan_release();
	a = (void*)((char*)a + (_cgo_topofstack() - stktop));
	a->r = r;
}

CGO_NO_SANITIZE_THREAD
void
_cgo_1508cd6507c2_Cfunc_load_lua_file(void *v)
{
	struct {
		void* p0;
		char const* p1;
		int r;
		char __pad20[4];
	} __attribute__((__packed__, __gcc_struct__)) *a = v;
	char *stktop = _cgo_topofstack();
	__typeof__(a->r) r;
	_cgo_tsan_acquire();
	r = load_lua_file(a->p0, a->p1);
	_cgo_tsan_release();
	a = (void*)((char*)a + (_cgo_topofstack() - stktop));
	a->r = r;
}

