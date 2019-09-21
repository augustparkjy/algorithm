class Node:
	def __init__(self, data):
		self.data = data
		self.left = self.right = None
		
class BST:
    def __init__(self):
        self.size = 0
        self.root = None
    
    def search(self, data):
        temp = self.root
        while temp:
            if temp.data == data:
                return True
            elif temp.data > data:
                temp = temp.left
            else:
                temp = temp.right
        return None
    
    def insert(self, data):
        temp = self.root
        if self.size==0:
            self.root = Node(data)
            self.size +=1
            return True
        while temp:
            if temp.data >= data:
                if not temp.left:
                    temp.left = Node(data)
                    self.size+=1
                    break
                else:
                    temp = temp.left
            else:
                if not temp.right:
                    temp.right = Node(data)
                    self.size+=1
                    break
                else:
                    temp = temp.right
    
    def delete(self, data):
        self.root, deleted = self._delete(self.root, data)
        return deleted
        
    def _delete(self, node, data):
        if node is None:
            return node, None
            
        deleted = None
        
        if data == node.data:
            deleted = True
            self.size -=1
            if node.left and node.right:
                parent, child = node, node.right
                while child.left is not None:
                    parent, child = child, child.left
                if parent==node:
                    node.data =child.data
                    node.right = child.right
                    del child
                else:
                    parent.left = child.right
                    node.data = child.data
                    del child
            elif node.left or node.right:
                node = node.left or node.right
            else:
                node = None
        elif data < node.data:
            node.left, deleted = self._delete(node.left, data)
        else:
            node.right, deleted = self._delete(node.right, data)
        return node, deleted
    
    def getSize(self):
        return self.size
    
    def __str__(self):
        return self.traversal(self.root)
    
    def traversal(self, node):
        a=b=c=s=''
        if node.left:
            a=self.traversal(node.left)
        b=str(node.data)
        if node.right:
            c=self.traversal(node.right)
        
        if a:
            s=a+' '
        s+=b
        if c:
            s=s+' '+c
        
        return s
        
bst = BST()
arr = [40, 4, 34, 45, 14, 55, 48, 13, 15, 49, 47]
print(bst.getSize())
for x in arr:
    bst.insert(x)
    print(bst)
    
print(bst.search(40))
print(bst.search(99))
print(bst.getSize())
print(bst.delete(49))
print(bst)
print(bst.search(49))
print(bst.delete(40))
print(bst)

