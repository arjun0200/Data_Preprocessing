"""
Instance methods
Instance methods are the most used methods in a Python class. These methods are only accessible through class objects. If we want to modify any class variable, this should be done inside an instance method.

The first parameter in these methods is self. self is used to refer to the current class object’s properties and attributes.

Take a look at the code snippet below to understand this.
"""

class Cricket:
    teamName = None

    def setTeamName(self, name):
        self.teamName = name

    def getTeamName(self):
        return self.teamName

c = Cricket()
c.setTeamName('India')
print(c.getTeamName())

"""
Class methods are usually used to access class variables. You can call these methods directly using the class name instead of creating an object of that class.

To declare a class method, we need to use the @classmethod decorator. Also, as in the case of instance methods, self is the keyword used to access the class variables. In class methods, we use use the cls variable to refer to the class.

Take a look at the code snippet below to understand this concept.
"""
class Cricket:
  teamName = 'India'

  @classmethod
  def getTeamName(cls):
    return cls.teamName

print(Cricket.getTeamName())

"""
Static methods are usually used as a utility function or when we do not want an inherited class to modify a function definition. These methods do not have any relation to the class variables and instance variables; so, are not allowed to modify the class attributes inside a static method.

To declare a static method, we need to use the @staticmethod. Again, we will be using the cls variable to refer to the class. These methods can be accessed using the class name as well as class objects.

Take a look at the code snippet below to understand this concept.
"""
class Cricket:
    teamName = 'India'

    @staticmethod
    def utility():
        print("This is a static method.")

c1 = Cricket()
c1.utility()

Cricket.utility()
