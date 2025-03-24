class Component:           
    def operation(self):
        pass

    def add(self, component):
        pass

    def remove(self, component):
        pass

    def get_child(self, index):
        pass

class Leaf(Component):
    def operation(self):
        print("Operacja na pliku")

class Composite(Component):
    def __init__(self):
        self.children = []

    def operation(self):
        for child in self.children:
            child.operation()

    def add(self, component):
        self.children.append(component)

    def remove(self, component):
        self.children.remove(component)

    def get_child(self, index):
        return self.children[index]

# Przykład użycia
folder1 = Composite() # instancja klasy Composite
folder2 = Composite() # instancja klasy Composite
file1 = Leaf()        # instancja klasy Leaf
file2 = Leaf()        # instancja klasy Leaf

folder1.add(file1) 
# Metoda add klasy Composite jest wywoływana na obiekcie folder1. 
# Plik file1 jest dodawany do listy children folderu folder1
# Teraz folder1 zawiera jeden element: file1.
folder2.add(file2) # podobnie jak w poprzedniej w linji, folder2 zawiera file2
folder1.add(folder2)
# Metoda add klasy Composite jest wywoływana na obiekcie folder1.
#Folder folder2 jest dodawany do listy children folderu folder1.
#Teraz folder1 zawiera dwa elementy: file1 i folder2.
# folder1
# ├── file1
# └── folder2
#     └── file2
folder1.operation()  # Wykonuje operację na wszystkich plikach i folderach wewnątrz folder1
