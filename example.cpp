#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
// Abstrakcyjna klasa komponentu, reprezentuje wspólny interfejs
class MenuComponent {
public:
    virtual void display() const = 0; // Metoda do wyœwietlania elementu menu
    virtual void add(std::shared_ptr<MenuComponent> component) {}
    virtual void remove(std::shared_ptr<MenuComponent> component) {}
    virtual ~MenuComponent() = default;
};

// Klasa liœcia (Leaf), czyli konkretna pozycja w menu
class MenuItem : public MenuComponent {
    std::string name;
public:
    MenuItem(std::string n) : name(n) {}
    void display() const override {
        std::cout << "Item: " << name << std::endl;
    }
};

// Klasa kompozytu (Composite), czyli menu mog¹ce zawieraæ inne elementy
class Menu : public MenuComponent {
    std::string name;
    std::vector<std::shared_ptr<MenuComponent>> components; // Przechowuje elementy menu
public:
    Menu(std::string n) : name(n) {}

    void add(std::shared_ptr<MenuComponent> component) override {
        components.push_back(component);
    }

    void remove(std::shared_ptr<MenuComponent> component) override {
        components.erase(std::remove(components.begin(), components.end(), component), components.end());
    }

    void display() const override {
        std::cout << "Menu: " << name << std::endl;
        for (const auto& component : components) {
            component->display();
        }
    }
};

// Przyk³adowe u¿ycie
int main() {
    auto mainMenu = std::make_shared<Menu>("Main Menu");
    auto fileMenu = std::make_shared<Menu>("File");
    auto editMenu = std::make_shared<Menu>("Edit");

    auto openItem = std::make_shared<MenuItem>("Open");
    auto saveItem = std::make_shared<MenuItem>("Save");
    auto copyItem = std::make_shared<MenuItem>("Copy");

    fileMenu->add(openItem);
    fileMenu->add(saveItem);
    editMenu->add(copyItem);

    mainMenu->add(fileMenu);
    mainMenu->add(editMenu);

    mainMenu->display(); // Wyœwietla ca³e menu

    return 0;
}
