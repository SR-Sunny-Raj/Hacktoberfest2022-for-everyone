#Method overriding is redefining a superclass(parent class) method with the same name, datatypes and arguments(parameters) in a subclass(child class).
#It allows for a more specific implementation of an already present method of the parent class.

class Animals:
    def __init__(self,name):
        self.name=name;
    
    def eat(self):
        print('Animals like %s eat to survive'%(self.name))
        
class Herbivore(Animals):
    def __init__(self,name):
        super().__init__(name)
    
    def eat(self):
        print('A herbivore like %s eats plants'%(self.name))
        
class Carnivore(Animals):
    def __init__(self,name):
        super().__init__(name)
        
    def eat(self):
        print('A carnivore like %s eats other animals'%(self.name))
       
        
a=Animals('Pig')
a.eat() 
h=Herbivore('Cow')
h.eat() #it chooses the function defined in the Herbivore class thereby overidding the function in Animals class
c=Carnivore('Lion')
c.eat() #it chooses the function defined in the Carnivore class thereby overidding the function in Animals class
