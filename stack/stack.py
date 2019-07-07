class node:
    def __init__(self):
        self.data=None
        self.next=None
class stack:
    def __init__(self):
        self.top=None
        self.bottom=None
    def push(self,data):
        temp=node()
        temp.data=data
        temp.next=self.top
        self.top=temp
        print("push success")
    def pop(self):
        self.top=self.top.next
        print("pop success")
    def disp(self):
        temp=self.top
        while temp:
            print(temp.data)
            temp=temp.next
st=stack()
st.push(1)
st.push(2)
st.push(3)
st.disp()
st.pop()
st.disp()