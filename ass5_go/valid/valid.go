package valid

func IsValid(query string) bool {

    for _, v := range query {
        if !Isnum(v) && v != '.' && v != '+' && v != '-' && v != '*' && v != '/' && v != '(' && v != ')' {
            return false
        }
    }
    return true
}

func Precedence(ch rune) int {
    if ch == '^' {
        return 3
    } else if ch == '/' || ch == '*' {
        return 2
    } else if ch == '+' || ch == '-' {
        return 1
    }
    return -1
}

func Isnum(ch rune) bool {
    return ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9' || ch == '.'
}