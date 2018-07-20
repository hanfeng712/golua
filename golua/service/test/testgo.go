package test

/*
#cgo CFLAGS: -I/home/hanfeng/golang/src/golua/service/test
#cgo LDFLAGS: -L/home/hanfeng/golang/src/golua/service/test/ -llua5.2
#include "testc.h"
#include <stdlib.h>
*/
import "C"
import (
	"fmt"
	"unsafe"
)

type GoluaOp struct {
	luaCtx unsafe.Pointer
}

var goluaHandler *GoluaOp

func (op *GoluaOp) Init() {
	op.luaCtx = C.init_lua()
	luaPath := "/home/hanfeng/golang/src/golua/testLua/HelloWord.lua"
	cluaPath := C.CString(luaPath)
	C.load_lua_file(op.luaCtx, cluaPath)
	C.free(unsafe.Pointer(cluaPath))
}

func Init() {
	goluaHandler = &GoluaOp{}
	goluaHandler.Init()
}
func AddTestFunc() {
	fmt.Print("start\n")
	fmt.Printf("1:go call C == AddTestFunc\n")
	C.cAddFuncLua(goluaHandler.luaCtx, 1)
}

//export AddCallFuncGo
func AddCallFuncGo(a string) int {
	fmt.Printf("3:C call go == AddCallFuncGo == key : %s\n", a)
	return 1
}

//export GetGoTime
func GetGoTime() {

}
