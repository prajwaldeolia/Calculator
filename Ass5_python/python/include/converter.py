import validations as vd
import queue

class Converter(vd.Validations):
    def __init__(self, str):
        super().__init__()
        self.result = queue.Queue()
        self.ec = vd.Validations()
        if not self.ec.isValid(str):
            print("invalid")

    def infixToPostfix(self, query):
        st = queue.LifoQueue()
        n = len(query)
        for i in range(n):
            ch = query[i]
            if ch == '(':
                st.put("(")
            elif ch == ')':
                val = st.get()
                while val != "(":
                    self.result.put(val)
                    st.get()
            elif ch == '+' or ch == '-' or ch == '*' or ch == '/':
                if not st.empty():
                    val = st.get()
                    st.put(val)
                while not st.empty() and (self.ec.precedence(ch) <= self.ec.precedence(val[0])): 
                    self.result.put(st.get())
                ss = ""
                ss += ch
                st.put(ss)
            else:
                temp = ""
                while i < n and (query[i] >= '0' and query[i] <= '9' or query[i] == '.'):
                    temp += query[i]
                    i+=1
                i-=1
                self.result.put(temp)
            # print("2")
        while not st.empty():
            self.result.put(st.get())

        return self.result