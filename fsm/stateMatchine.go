package fsm

import (
	"container/list"
	"fmt"
)

type callBackFunc func(arg interface{})
//master-1111111111111
//master-2222222222222
// State父struct-3
type FSMState struct {
	id       string
	callback callBackFunc
	arg      interface{}
}

func CreateMatchineState(id string, fun callBackFunc, arg interface{}) FSMState {
	return FSMState{
		id:       id,
		callback: fun,
		arg:      arg,
	}
}

// 进入状态
func (this *FSMState) Enter() {
	//
	fmt.Println("state enter")
}

//状态处理函数
func (this *FSMState) Do() {
	fmt.Printf("FSMState do - key : %s", this.id)
	this.callback(this.arg)
}

// 退出状态
func (this *FSMState) Exit() {
	//
	fmt.Println("state exit")
}

//添加状态回调函数
func (this *FSMState) addStateCallBack(f callBackFunc) {
	this.callback = f
}

// 状态转移检测
func (this *FSMState) CheckTransition() {
	//
}

/*******************************************************************************************/
func CreateFSM() *FSM {
	it := &FSM{}
	it.Init()
	return it
}

type FSM struct {
	// 持有状态集合
	statesMap map[string]FSMState
	//
	action *list.List
	// 当前状态
	current_state FSMState
	// 下一个状态
	next_state FSMState
	// 默认状态
	default_state FSMState
	runState      int
}

// 初始化FSM
func (this *FSM) Init() {
	//
	this.runState = 0
	this.statesMap = make(map[string]FSMState)
	this.action = list.New()
}

func (this *FSM) Start() {
	fmt.Printf("FSM-Start():enter")
	if this.action.Len() == 0 {
		fmt.Printf("FSM-Start():leave1")
		return
	}
	firstKey := this.action.Front()
	this.current_state = this.statesMap[firstKey.Value.(string)]
	var index string = this.CalcNextStateKey(this.current_state)
	this.next_state = this.statesMap[index]
	this.default_state = this.statesMap[firstKey.Value.(string)]

	this.runState = 1
	this.SwitchFsmState()
	fmt.Printf("FSM-Start():leave2")
}

// 设置默认的State
func (this *FSM) SetDefaultState(state FSMState) {
	this.default_state = state
}

// 添加状态到FSM
func (this *FSM) AddState(key string, state FSMState) {
	this.statesMap[key] = state
	this.action.PushBack(key)
}

//获取当前状态
func (this *FSM) GetCurrentState() FSMState {
	return this.current_state
}

//获取下一下状态
func (this *FSM) GetNextState() FSMState {
	return this.next_state
}

//状态切换
func (this *FSM) SwitchFsmState() {
	if this.runState != 1 {
		return
	}
	//执行当前状态的动作
	this.current_state.Do()

	this.current_state = this.next_state
	var index string = this.CalcNextStateKey(this.current_state)
	this.next_state = this.statesMap[index]
	this.SwitchFsmState()
}

func (this *FSM) CalcNextStateKey(current FSMState) string {
	var index string = this.default_state.id
	for e := this.action.Front(); e != nil; e = e.Next() {
		if e.Value == current.id {
			if e.Next() != nil {
				index = (e.Next().Value).(string)
			}
			break
		}
	}
	return index
}

//暂停FSM
func (this *FSM) PauseStateMachine() {
	this.runState = 2
}

// 重置FSM
func (this *FSM) ResetStateMachine() {
	this.runState = 1
	this.current_state = this.default_state
	// 下一个状态
	var index string = this.CalcNextStateKey(this.current_state)
	this.next_state = this.statesMap[index]
}
