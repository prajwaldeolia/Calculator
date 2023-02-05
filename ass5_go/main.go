package main

import (
	"fmt"
	"ass5_go/calc"
)

func main() {
    var query string
    for{
        fmt.Print("Enter Query: ")
        fmt.Scanln(&query)
		fmt.Println(calc.Calculate(query))
        fmt.Print("\nfor continue press 1\nfor exit press 0: ")
        var response int
        fmt.Scanln(&response)
        if response == 1 {
            continue
        } else {
            break
        }
    }
}