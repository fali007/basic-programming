class node:
    def __init__(self):
        self.data=None
        self.left=None
        self.right=None


class tree:
    def __init__(self):
        self.root=None

    def add_lnode(self,nod,data):
        temp=node()
        temp.data=data
        nod.left=temp
        print("added left")

    def add_rnode(self,nod,data):
        temp=node()
        temp.data=data
        nod.right=temp
        print("added right")
    
    def insert(self,nod,data):
        q=[]
        q.append(nod)
        while (len(q)):
            temp=q[0]
            q.pop(0)
            if not temp.left:
                self.add_lnode(temp,data)
                break
            else:
                q.append(temp.left)
            if not temp.right:
                self.add_rnode(temp,data)
                break
            else:
                q.append(temp.right)

    def add_node(self,data):
        temp=node()
        temp.data=data
        if self.root == None:
            self.root=temp
            print("added as root")
        else:
            temp1=self.root
            while temp1:
                if temp1.left==None:
                    temp1.left=temp
                    print("added as left")
                    return
                elif temp1.right==None:
                    temp1.right=temp
                    print("added as right")
                    return
                temp1=temp1.left
                print("new node")

    def disp_inorder(self,node):
        if node:
            self.disp_inorder(node.left)
            print(node.data)
            self.disp_inorder(node.right)

    def post_order(self,node):
        if node:
            self.post_order(node.left)
            self.post_order(node.right)
            print(node.data)
            
    def pre_order(self,node):
        if node:
            print(node.data)
            self.pre_order(node.left)
            self.pre_order(node.right)

tr=tree()
tr.add_node(5)
tr.add_node(4)
tr.add_node(3)
tr.add_node(2)
tr.add_lnode(tr.root.right,1)
tr.insert(tr.root,0)
tr.insert(tr.root,6)
print("inorder")
tr.disp_inorder(tr.root)
print("post-order")
tr.post_order(tr.root)
print("pre-order")
tr.pre_order(tr.root)