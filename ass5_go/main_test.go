package main

import (
	"testing"
	// "ass5_go/converter"
	"ass5_go/queue"
    "ass5_go/operation"
	"ass5_go/valid"
	"ass5_go/calc"
)

func temp() *queue.QueueUsingSlices{
	Q := &queue.QueueUsingSlices{}
	Q.Push("2")
    Q.Push("3")
    Q.Push("+")
    Q.Push("4")
    Q.Push("-")
    Q.Push("8")
    Q.Push("+")
	return Q
}





	//testing valid

func TestIsnum(t *testing.T) {
	if valid.Isnum('3') != true {
		t.Error("Test Failed: Check ur Isnum func in valid")
	}
	if valid.Isnum('+') != false {
		t.Error("Test Failed: Check ur Isnum func in valid")
	}
}

func TestIsValid(t *testing.T) {
	if valid.IsValid("3+2") != true {
		t.Error("Test Failed: Check ur IsValid func in valid")
	}
}

func TestTablePrecedence(t *testing.T) {
	var tests = []struct {
		input rune
		expected int
	}{
		{'+', 1},
		{'-', 1},
		{'*', 2},
		{'/', 2},
		{'^', 3},
	}
	for _, test := range tests {
		if output := valid.Precedence(test.input); output != test.expected {
			t.Error("Test Failed: Check ur Precedence func in valid: ", test.input, test.expected, output)
		}
	}
}


	//testing operation

func TestTableCalc(t *testing.T) {
	var tests = []struct {
		input_a float64
		input_op rune
		input_b float64
		expected float64
	}{
		{56, '+', 7, 63},
		{56, '-', 7, 49},
		{56, '*', 7, 392},
		{56, '/', 7, 8},
	}
	for _, test := range tests {
		if output := operation.Calc(test.input_a, test.input_op, test.input_b); output != test.expected {
			t.Error("Test Failed: Check ur calc func in operation: ", test.input_a, string(test.input_op), test.input_b, test.expected, output)
		}
	}
}


	//testing converter

// func TestInfixToPostfix(t *testing.T) {
// 	if *converter.InfixToPostfix("2+3-4+8") != *temp() {
// 		t.Error("Test Failed: Check ur InfixToPostfix func in converter", converter.InfixToPostfix("2+3-4+8"), temp())
// 	}
// }

// func TestInfixToPostfix(t *testing.T) {
// 	for i := 0; i < 7; i++ {
// 		result := *converter.InfixToPostfix("2+3-4+8")
// 		tmp := *temp()
// 		if result[i] != tmp[i] {
// 			t.Error("Test Failed: Check ur InfixToPostfix func in converter", converter.InfixToPostfix("2+3-4+8"), temp())
// 			break
// 		}	
// 	}
// }


	//testing calc

func TestCalculate(t *testing.T) {
	if calc.Calculate("2+3-4+8") != 9 {
		t.Error("Test Failed: Check ur calculate func in calc")
	}
}

func TestEvaluate(t *testing.T) {
	if calc.Evaluate(temp()) != 9 {
		t.Error("Test Failed: Check ur evaluate func in calc")
	}
}