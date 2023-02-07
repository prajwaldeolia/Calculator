
class Validations:
    def isnum(self, ch):
        return (ch >= '0' and ch <= '9') or ch == '.'
        
    def isValid(self, query):
        x = {'.', '+', '-', '*', '/', '(', ')'}
        y = {'0', '1', '2', '3', '3', '4', '5', '6', '7', '8', '9'}
        for i in query:
            if i not in x and i not in y:
                return False
        return True
    
    def precedence(self, ch):
        if (ch == '^'):
            return 3
        elif (ch == '/' or ch == '*'):
            return 2
        elif (ch == '+' or ch == '-'):
            return 1