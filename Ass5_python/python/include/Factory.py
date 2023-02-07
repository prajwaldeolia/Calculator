from abc import ABC, abstractmethod
class Ioperation(ABC):
    @abstractmethod
    def calc(self, a, b):
        pass

class Sum(Ioperation):
    def calc(self, a, b):
        return a + b

class Substract(Ioperation):
    def calc(self, a, b):
        return a - b

class Multiply(Ioperation):
    def calc(self, a, b):
        return a * b

class Devision(Ioperation):
    def calc(self, a, b):
        return a / b

class OperationFactory:
    def factory(self,ch):
        if ch == '+':
            return Sum()
        elif ch == '-':
            return Substract()
        elif ch == '*':
            return Multiply()
        elif ch == '/':
            return Devision()