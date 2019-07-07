class hashing:
    def __init__(self):
        self.hash_arr={}
    def insert(self,data,value):
        hash=int(data/10)
        self.hash_arr[hash+50+data%10]=value
        print("insterted successfully")
    def get_value(self,data):
        hash=int(data/10)
        return self.hash_arr[hash+50+data%10]
h=hashing()
h.insert(100,"hari")
h.insert(20,"anju")
h.insert(25,"vv")
h.insert(30,"alex")
print(h.get_value(100))
print(h.get_value(25))