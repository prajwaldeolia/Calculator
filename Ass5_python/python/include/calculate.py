# import validations as vd, Factory as ft, converter as conv
import validations as vd
import Factory as ft
import converter as conv
import queue

class Calculate(conv.Converter, ft.OperationFactory):
    def __init__(self, query):
        # super().__init__(query)
        obj = conv.Converter(query)
        self.result = queue.Queue()
        self.result = obj.infixToPostfix(query)
        # if e is 1:
        #     print("Please enter valid expression")
    
    def evaluate(self):
        stk = queue.LifoQueue()
        while not self.result.empty():
            fr = self.result.get()
            ec = vd.Validations()
            if ec.isnum(fr[0]):
                num = float(fr)
                stk.put(num)
            else:
                val1 = stk.get()
                val2 = stk.get()
                op = ft.OperationFactory()
                optr = op.factory(fr[0])
                stk.put(optr.calc(val2, val1))

        return stk.get()