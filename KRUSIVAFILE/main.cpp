#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "Product.h"
#include "Quantity.h"
#include "Ingredient.h"
#include "Dish.h"

void displayMenu(std::unordered_map<int, Dish>& dishes, const std::unordered_map<std::string, Product>& products) {
    while (true) {
        std::cout << "\nAvailable dishes:\n";
        for (const auto& pair : dishes) {
            std::cout << pair.first << ". " << pair.second.getName() << '\n';
        }
        std::cout << "Enter the number of the dish to see the cost breakdown, 'add' to add an ingredient, 'remove' to remove an ingredient, or '0' to quit: ";

        std::string choice;
        std::cin >> choice;

        if (choice == "0") {
            break;
        }
        else if (choice == "add") {
            int dishNumber;
            std::string productName;
            double grams;
            std::cout << "Enter the dish number: ";
            std::cin >> dishNumber;
            std::cout << "Enter the product name: ";
            std::cin >> productName;
            std::cout << "Enter the quantity in grams: ";
            std::cin >> grams;

            auto dishIt = dishes.find(dishNumber);
            auto productIt = products.find(productName);
            if (dishIt != dishes.end() && productIt != products.end()) {
                dishIt->second.addIngredient(Ingredient(productIt->second, Quantity(grams)));
                std::cout << "Ingredient added.\n";
            }
            else {
                std::cout << "Dish or product not found.\n";
            }
        }
        else if (choice == "remove") {
            int dishNumber;
            std::string ingredientName;
            std::cout << "Enter the dish number: ";
            std::cin >> dishNumber;
            std::cout << "Enter the ingredient name: ";
            std::cin >> ingredientName;

            auto dishIt = dishes.find(dishNumber);
            if (dishIt != dishes.end()) {
                dishIt->second.removeIngredient(ingredientName);
                std::cout << "Ingredient removed.\n";
            }
            else {
                std::cout << "Dish not found.\n";
            }
        }
        else {
            int dishNumber = std::stoi(choice);
            auto it = dishes.find(dishNumber);
            if (it != dishes.end()) {
                it->second.printCostBreakdown();
            }
            else {
                std::cout << "Dish not found. Please try again.\n";
            }
        }
    }
}

int main() {
    // Define some products
    Product tomato("Tomato", 75); // Price per kg in UAH
    Product cheese("Cheese", 210); // Price per kg in UAH
    Product bread("Bread", 45); // Price per kg in UAH
    Product chicken("Chicken", 160); // Price per kg in UAH
    Product lettuce("Lettuce", 60); // Price per kg in UAH

    Product potatoes("Potatoes", 55); // Price per kg in UAH
    Product carrot("Carrot", 49); // Price per kg in UAH
    Product eggs("Eggs", 30); // Price per kg in UAH
    Product cucumber("Cucumber", 93); // Price per kg in UAH
    Product sausage("Sausage", 180); // Price per kg in UAH
    Product mayonnaise("Mayonnaise", 188); // Price per kg in UAH

    // Define some ingredients
    Ingredient tomatoIngredient(tomato, Quantity(100)); // 100 grams
    Ingredient cheeseIngredient(cheese, Quantity(70)); // 70 grams
    Ingredient breadIngredient(bread, Quantity(100)); // 100 grams
    Ingredient chickenIngredient(chicken, Quantity(170)); // 170 grams
    Ingredient lettuceIngredient(lettuce, Quantity(100)); // 100 grams

    Ingredient potatoesIngredient(potatoes, Quantity(120)); // 120 grams
    Ingredient carrotIngredient(carrot, Quantity(100)); // 100 grams
    Ingredient eggsIngredient(eggs, Quantity(100)); // 100 grams
    Ingredient cucumberIngredient(cucumber, Quantity(100)); // 100 grams
    Ingredient sausageIngredient(sausage, Quantity(90)); // 90 grams
    Ingredient mayonnaiseIngredient(mayonnaise, Quantity(40)); // 40 grams

    // Define some dishes
    Dish sandwich("Sandwich");
    sandwich.addIngredient(tomatoIngredient);
    sandwich.addIngredient(cheeseIngredient);
    sandwich.addIngredient(breadIngredient);

    Dish chickenSalad("Chicken Salad");
    chickenSalad.addIngredient(chickenIngredient);
    chickenSalad.addIngredient(lettuceIngredient);
    chickenSalad.addIngredient(tomatoIngredient);
    chickenSalad.addIngredient(cucumberIngredient);
    chickenSalad.addIngredient(mayonnaiseIngredient);

    Dish cheeseSandwich("Cheese Sandwich");
    cheeseSandwich.addIngredient(cheeseIngredient);
    cheeseSandwich.addIngredient(breadIngredient);
    cheeseSandwich.addIngredient(lettuceIngredient);

    Dish olivier("Olivier");
    olivier.addIngredient(potatoesIngredient);
    olivier.addIngredient(carrotIngredient);
    olivier.addIngredient(eggsIngredient);
    olivier.addIngredient(cucumberIngredient);
    olivier.addIngredient(sausageIngredient);
    olivier.addIngredient(mayonnaiseIngredient);

    // Store dishes in a map for easy lookup
    std::unordered_map<int, Dish> dishes;
    dishes[1] = sandwich;
    dishes[2] = chickenSalad;
    dishes[3] = cheeseSandwich;
    dishes[4] = olivier;

    // Store products in a map for easy lookup
    std::unordered_map<std::string, Product> products;
    products["Tomato"] = tomato;
    products["Cheese"] = cheese;
    products["Bread"] = bread;
    products["Chicken"] = chicken;
    products["Lettuce"] = lettuce;
    products["Potatoes"] = potatoes;
    products["Carrot"] = carrot;
    products["Eggs"] = eggs;
    products["Cucumber"] = cucumber;
    products["Sausage"] = sausage;
    products["Mayonnaise"] = mayonnaise;

    // Display the menu and handle user input
    displayMenu(dishes, products);

    return 0;
}
