class node:
    def __init__(self):
        self.data=None
        self.right=None
        self.left=None

class tree:
    def __init__(self,val):
        self.root=node()
        self.root.data=val
    def insert(self,val):
        q=[]
        q.append(self.root)
        new=node()
        new.data=val
        while len(q):
            temp=q.pop(0)
            if temp.left:
                q.append(temp.left)
            else:
                temp.left=new
                return
            if temp.right:
                q.append(temp.right)
            else:
                temp.right=new
                return
    def draw(self):
        q=[]
        h=0
        q.append([self.root,0])
        while len(q):
            temp=q.pop(0)
            if h!=temp[1]:
                h=temp[1]
                print('')
            print(temp[0].data,end=' ')
            if temp[0].left:
                q.append([temp[0].left,temp[1]+1])
            if temp[0].right:
                q.append([temp[0].right,temp[1]+1])
    def height(self):
        q=[]
        h=0
        q.append([self.root,0])
        while len(q):
            temp=q.pop(0)
            h=max(h,temp[1])
            if temp[0].left:
                q.append([temp[0].left,temp[1]+1])
            if temp[0].right:
                q.append([temp[0].right,temp[1]+1])
        return h

tr=tree(0)
for i in range(1,15):
    tr.insert(i)
tr.draw()
print('')
print(tr.height())