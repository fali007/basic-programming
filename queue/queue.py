class node:
    def __init__(self):
        self.data=None
        self.next=None
class queue:
    def __init__(self):
        self.bottom=None
        self.top=None
    def push(self,data):
        temp=node()
        temp.data=data
        if self.top==None:
            self.top=temp
        temp.next=self.bottom
        self.bottom=temp
        print("push success")
    def pop(self):
        self.top.data=None
        self.top.next=None
        temp=self.bottom
        while temp.next.data!=None:
            temp=temp.next
        self.top=temp
        print("pop success")
    def disp(self):
        temp=self.bottom
        while temp:
            print(temp.data)
            temp=temp.next
q=queue()
q.push(1)
q.push(2)
q.push(3)
q.push(4)
q.disp()
q.pop()
q.disp()
q.pop()
q.disp()
print(q.top.data)