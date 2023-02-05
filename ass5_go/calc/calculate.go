package calc

import (
	"fmt"
    "strconv"
	"ass5_go/converter"
    "ass5_go/operation"
    "ass5_go/stack"
	"ass5_go/valid"
    "ass5_go/queue"
)


func Calculate(query string) float64 {
    result := &queue.QueueUsingSlices{}
    if !valid.IsValid(query) {
        fmt.Println("invalid")
    }
    result = converter.InfixToPostfix(query)
    return Evaluate(result)
    // return 34.65
}

func Evaluate(result *queue.QueueUsingSlices) float64 {

    stk := &stack.StackUsingSlices{}

    for result.Len() != 0 {
        fr := result.Pop().(string)
        if valid.Isnum(rune(fr[0])) {
            num, _ := strconv.ParseFloat(fr, 64)
            stk.Push(num)
        } else {
        val1 := stk.Pop().(float64)
        val2 := stk.Pop().(float64)
        stk.Push(operation.Calc(val2, rune(fr[0]), val1))
        }
    }
    return stk.Peek().(float64)
}