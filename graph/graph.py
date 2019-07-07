# # raw implementation
# class graph:
#     def __init__(self,num):
#         self.list=[[]for i in range(num)]
#     def add_edge(self,parent,node):
#         self.list[parent].append(node)
#         print(self.list)
#     def disp(self,a):
#         ans,visited,q=[],[],[]
#         q.append(a)
#         while(len(q)):
#             temp=q[0]
#             ans.append(temp)
#             visited.append(temp)
#             q.pop(0)
#             for i in range(len(self.list[temp])):
#                 if self.list[temp][i] in visited:
#                     continue
#                 else:
#                     q.append(self.list[temp][i])
#         return ans

# g=graph(4)
# g.add_edge(0,1)
# g.add_edge(1,2)
# g.add_edge(1,3)
# g.add_edge(2,3)
# g.add_edge(2,0)
# print(g.disp(2))

# python simple implementation
graph = { "a" : ["c"],
          "b" : ["c", "e"],
          "c" : ["a", "b", "d", "e"],
          "d" : ["c"],
          "e" : ["c", "b"],
          "f" : []
        }
def show_edge(graph):
    edge=[]
    for node in graph:
        for adj in graph[node]:
            edge.append((node,adj))
    return edge
# print(show_edge(graph))

def find_path(graph, start_vertex, end_vertex, path=None):
        if path == None:
            path = []
        path = path + [start_vertex]
        if start_vertex == end_vertex:
            return path
        if start_vertex not in graph:
            return None
        for vertex in graph[start_vertex]:
            if vertex not in path:
                extended_path = find_path(graph,vertex, 
                                               end_vertex, 
                                               path)
                if extended_path: 
                    return extended_path
        return None 
path=[]
print(find_path(graph,'a','e',path))