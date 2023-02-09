package operation

func Calc(a float64, ch rune, b float64) float64 {
    switch ch {
        case '+': return a + b
        case '-': return a - b
        case '*': return a * b
        case '/': return a / b
    }
    return 0
}