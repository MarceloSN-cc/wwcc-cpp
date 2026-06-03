#include <iostream>
#include <string> 
#include <iomanip>
#include <cctype>
#include <limits>
#include <vector>

using namespace std;

struct Recipe {
    string name;
    vector<string> ingredients;
    vector<string> steps;
};

//Prototype functions
void displayMenu();
void addRecipe(vector<Recipe>& recipes);
void displayAllRecipes(const vector<Recipe>& recipes);
void searchRecipes(const vector<Recipe>& recipes);
void removeRecipe(vector<Recipe>& recipes);
void showStatistics(const vector<Recipe>& recipes);
string toLowerCase(string text);

int main () {
    vector<Recipe> recipes;
    int choice;

    do {
        displayMenu();
        if(!(cin >> choice)) {
            cout << "Invalid choice!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            continue;
        }
        cin.ignore();

        switch(choice) {
            case 1: 
                addRecipe(recipes);
                break;
            case 2:
                displayAllRecipes(recipes);
                break;
            case 3:
                searchRecipes(recipes);
                break;
            case 4:
                removeRecipe(recipes);
                break;
            case 5:
                showStatistics(recipes);
                break;
            case 6:
                cout << "Exiting Dynamic Recipe Manager.\n"; 
                break;
            default : 
                cout << "Invalid option, please enter from one of "
                     << "the prompted choices.\n";
        }
    }while(choice != 6);

    return 0;
}

void displayMenu() {
    cout << "DYNAMIC RECIPE MANAGER\n";
    cout << "======================\n";
    cout << "1. Add Recipe\n";
    cout << "2. Display All Recipes\n";
    cout << "3. Search Recipes\n";
    cout << "4. Remove Recipe\n";
    cout << "5. Show Statistics\n";
    cout << "6. Exit\n";
    cout << "\nEnter your choice: ";
}

void addRecipe(vector<Recipe>& recipes) {
    Recipe newRecipe;

    cout << "\nEnter recipe name: ";
    getline(cin, newRecipe.name);

    while(newRecipe.name.empty()) {
        cout << "Error: Name cannot be left empty!" << endl;
        cout << "Please enter recipe name: ";
        getline(cin, newRecipe.name);

    }
    int ingredientCount;

    cout << "\nHow many ingredients? " << endl;

    if(!(cin >> ingredientCount)) {
        cout << "Invalid input!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    cin.ignore();

    if(ingredientCount <= 0) {
        cout << "Invalid ingredient amount!" << endl;
        return;
    }

    for(int i = 0; i < ingredientCount; i++) {
        string ingredient;

        cout << "Enter ingredient " << (i +1) << ": ";
        getline(cin, ingredient); 

        newRecipe.ingredients.push_back(ingredient);
    }

    int stepCount;

    cout << "How many steps? ";

    if(!(cin >> stepCount)) {
        cout << "Invalid steps input!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    cin.ignore();

    if(stepCount <= 0) {
        cout << "Invalid amount!" << endl;
        return;
    }

    for(int i = 0; i < stepCount; i++) {
        string steps;

        cout << "Enter step " << (i + 1) << ": ";
        getline(cin, steps);

        newRecipe.steps.push_back(steps);
    }

    recipes.push_back(newRecipe);

    cout << "\nRecipe added successfully!\n";
}

void displayAllRecipes(const vector<Recipe>& recipes) {
    cout << "\nRECIPE COLLECTION\n";
    cout << "--------------------\n";

    if(recipes.empty()) {
        cout << "No recipes found.\n";
        return;
    }

    for(size_t i = 0; i < recipes.size(); i++) {
        cout << "\nRecipe #" << (i + 1) << endl;
        cout << "Name: " << recipes.at(i).name << endl;

        cout << "\nIngredients:\n";
        for (size_t j = 0; j < recipes.at(i).ingredients.size(); j++) {
            cout << "  - " << recipes.at(i).ingredients.at(j) << endl;
        }

        cout << "\nSteps:\n";
        for(size_t j = 0; j < recipes.at(i).steps.size(); j++) {
            cout << " " << (j + 1) << ". " 
            << recipes.at(i).steps.at(j) << endl; 
        }

        cout << "\n----------------------------\n";
    }
}

void searchRecipes(const vector<Recipe>& recipes) {
    if(recipes.empty()) {
        cout << "\nNo recipes available to search.\n";
        return;
    }

    string searchTerm;

    cout << "\nEnter recipe name or ingredient to search: ";
    getline(cin, searchTerm);

    string searchToLower = toLowerCase(searchTerm);
    bool found = false;

    cout << "\nSEARCH RESULTS\n";
    cout << "-----------------\n";

    for(size_t i = 0; i < recipes.size(); i++) {
        bool match = false;

        string recipeName = toLowerCase(recipes.at(i).name);

        if(recipeName.find(searchToLower) != string::npos) {
            match = true;
        }

        if(!match) {
            for(size_t j = 0; j < recipes.at(i).ingredients.size(); j++) {
                string ingredient = toLowerCase(recipes.at(i).ingredients.at(j));

                if(ingredient.find(searchToLower) != string::npos) {
                    match = true;
                    break;
                }
            }
        }
        if(match) {
            found = true;

            cout << "\nRecipe: " << recipes.at(i).name << endl;

            cout << "Ingredients: " << recipes.at(i).ingredients.size() << endl;

            cout << "Steps: " << recipes.at(i).steps.size() << endl;
        }
    }
    if(!found) {
        cout << "No matching recipes found.\n";
    }
}

void removeRecipe(vector<Recipe>& recipes) {
    if(recipes.empty()) {
        cout << "\nNo existing recipes to be removed.\n";
        return;
    }
    cout << "\nRECIPES\n";
    cout << "-----------\n";

    for(size_t i = 0; i < recipes.size(); i++) {
        cout << (i + 1) << ". " << recipes.at(i).name << endl;
    }

    int recipeNum;

    cout << "Enter a recipe by its listed number to be removed: ";
   
    if(!(cin >> recipeNum)) {
        cout << "Invalid input!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        return;
    }
    cin.ignore(); 

    if(recipeNum < 1 || recipeNum > static_cast<int>(recipes.size())) {
        cout << "Invalid choice!\n";
        return;
    }

    string removedRecipe = recipes.at(recipeNum - 1).name;

    recipes.erase(recipes.begin() + (recipeNum - 1));

    cout << "\nRecipe: " << removedRecipe << " removed successfully!\n";
}

void showStatistics(const vector<Recipe>& recipes) {
    cout << "\nCOLLECTION STATISTICS\n";
    cout << "-------------------------\n";

    if(recipes.empty()) {
        cout << "No available recipes to show statistics.\n";
        return;
    }

    int totalRecipes = static_cast<int>(recipes.size());

    cout << "Total recipes: " << totalRecipes << endl;

    int totalIngredients = 0, totalSteps = 0;

    for(size_t i = 0; i < recipes.size(); i++) {
        totalIngredients += static_cast<int>(recipes.at(i).ingredients.size());

        totalSteps += static_cast<int>(recipes.at(i).steps.size());
    }

    double averageIngredients = static_cast<double>(totalIngredients)/recipes.size();
    double averageSteps = static_cast<double>(totalSteps)/recipes.size();

    cout << fixed << setprecision(1);
    cout << "Average ingredients per recipe: " << averageIngredients << endl;
    cout << "Average steps per recipe: " << averageSteps << endl;
}

string toLowerCase(string text) {
    for(char& c : text) {
        c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
    }
    return text;
}