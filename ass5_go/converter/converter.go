package converter

import (
	// "fmt"
    "ass5_go/stack"
    "ass5_go/queue"
    "ass5_go/valid"
)


func InfixToPostfix(query string) *queue.QueueUsingSlices {

    st := &stack.StackUsingSlices{}
	result := &queue.QueueUsingSlices{}

    for i := 0; i < len(query); i++ {
        var ch rune = rune(query[i])
        
        if ch == '(' {
            st.Push("(")
        } else if ch == ')' {
            for st.Peek().(string) != "(" {
                result.Push(st.Pop().(string))
            }
            st.Pop()
        } else if ch == '+' || ch == '-' || ch == '*' || ch == '/' {
            for st.Len() != 0 && valid.Precedence(ch) <= valid.Precedence(rune(st.Peek().(string)[0])) {
                result.Push(st.Pop().(string))
            }
            var ss string
            ss += string(ch)
            st.Push(ss)
        } else {
            var temp string
            for i < len(query) && valid.Isnum(rune(query[i])) {
                temp += string(query[i])
                i++
            }
            i--
            result.Push(temp)
        }
    }
    for st.Len() !=  0 {
        result.Push(st.Pop().(string))
    }
    return result
}