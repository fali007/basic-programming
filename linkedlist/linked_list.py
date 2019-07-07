# class school:
# 	def __init__(self,name,idno):
# 		self.name=name
# 		self.idno=idno
# class clss(school):
# 	def __init__(self,name,stre,div,idno):
# 		school.__init__(self,name,idno)
# 		self.name=name
# 		self.stre=stre
# 		self.div=div
# jnv=clss("jnv",43,"B",2)
# print(jnv.name)
# print(jnv.idno)
# print(jnv.div)

# class polygon:
# 	def __init__(self,side):
# 		self.side=side
# class triangle(polygon):
# 	def __init__(self,side):
# 		self.side=side
# 		self.is_tri()
# 	def is_tri(self):
# 		if self.side==3:
# 			return True
# 		return False
# class square(polygon):
# 	def __init__(self):
# 		self.side=side
# 		self.is_squ()
# 	def is_squ(self):
# 		if self.side==4:
# 			return True
# 		return False
# pol=triangle(5)
# print(pol.is_tri())

class node:
	def __init__(self):
		self.value=None
		self.next=None
class linkedlist:
	def __init__(self):
		self.cur_node=None
		self.ini=None
	def addnode(self,data):
		newnode=node()
		newnode.value=data
		newnode.next=self.cur_node
		print("added successfully")
		self.cur_node=newnode
	def addnode_pos(self,data,pos):
		temp=self.cur_node
		newnode=node()
		for i in range(1,pos):
			temp=temp.next
		newnode.value=data
		newnode.next=temp
		temp=self.cur_node
		for i in range(1,pos-1):
			temp=temp.next
		temp.next=newnode
		print("added successfully")
	def getlen(self):
		count=0
		node=self.cur_node
		while node:
			count+=1
			node=node.next
		print("length of linked list is %d"%(count))
		return count
	def printnode(self):
		node=self.cur_node
		while node:
			print(node.value)
			node=node.next
l=linkedlist()
l.addnode(1)
l.addnode(2)
l.addnode(3)
l.printnode()
l.getlen()
l.addnode_pos(12,2)
l.printnode()
l.getlen()