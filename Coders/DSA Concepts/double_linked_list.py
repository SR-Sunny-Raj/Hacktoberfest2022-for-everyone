class Node():
    def __init__(self, data):
        self.prev = None # previous node address
        self.next = None # next node address
        self.data = data
    
class dbl_lnk_lst:
    def __init__(self):
        self.head = None
        self.tail = None

    def create(self):
        new_node = Node(input("Enter Data: "))
        self.head = new_node # head node
        self.tail = new_node # tail node
    
    def insertion(self):
        new_node = Node(input("Enter Data: "))
        if self.head == None:
            self.head = new_node
            self.tail = new_node
        else:
            new_node.prev = self.tail
            self.tail.next = new_node
            self.tail = new_node
        

    def deletion(self): # to delete the last node
        if self.head == None:
            print("Nothing left to remove")
        else:
            if self.tail.prev == None:
                print("here")
                head = self.head
                self.head = None
                self.tail = None
                print(f"{head.data} has been deleted")
                del head
                
            else:
                print("HERE")
                tail_node = self.tail
                self.tail.prev.next = None
                self.tail = self.tail.prev
                print(f"{tail_node.data} has been deleted")
                del tail_node

    def Display(self): # traversal in both ways
        if self.head == None:
            print("There are no elements to display")
        else:
            print("Select:\n\t1. From first\n\t2. From last")
            query = int(input("Enter your option: "))
            if query == 1:
                curr_node = self.head
                print("Printing list elements from starting...")
                while curr_node.next != None:
                    print(curr_node.data, end = " ")
                    curr_node = curr_node.next
                print(curr_node.data, "\n")
            elif query == 2:
                print("Printing list elements from end...")
                curr_node = self.tail
                while curr_node.prev != None:
                    print(curr_node.data, end = " ")
                    curr_node = curr_node.prev
                print(curr_node.data, "\n")


dbl = dbl_lnk_lst()
cnd = True
while cnd:
    print("Menu\n\t1. Create\n\t2. insert\n\t3. Display\n\t4. Delete\n\t5. Quit")
    query = int(input("Enter selected option: "))
    
    if query == 1:
        dbl.create()
    elif query == 2:
        dbl.insertion()
    elif query == 3:
        dbl.Display()
    elif query == 4:
        dbl.deletion()
               
    elif query == 5:
        print("Quitting...")
        cnd = False
    else:
        print("Select a valid option from menu")
