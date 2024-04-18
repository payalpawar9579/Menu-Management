#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm> 
using namespace std;

// Define a structure for menu items
struct MenuItem {
    int id;
    string name;
    double price;
    int quantity;
};

// Define a map to store menu items by category
map<string, map<int, MenuItem>> menu;

// Vector to store IDs of inserted items
vector<int> insertedItems;

// Function to initialize the menu with food items and prices
void initializeMenu() {
    // Starters
    menu["starters"][1] = {1, "Vegetable Spring Rolls", 299, 10};
    menu["starters"][2] = {2, "Paneer Tikka", 399, 10};
    menu["starters"][3] = {3, "Samosa", 199, 10};
    menu["starters"][4] = {4, "Onion Rings", 249, 10};
    menu["starters"][5] = {5, "Masala Papad", 149, 10};
    menu["starters"][6] = {6, "Aloo Chaat", 199, 10};
    menu["starters"][7] = {7, "Hara Bhara Kabab", 299, 10};
    menu["starters"][8] = {8, "Mushroom Tikka", 349, 10};
    menu["starters"][9] = {9, "Corn Cutlet", 249, 10};
    menu["starters"][10] = {10, "Chilli Potato", 279, 10};
    menu["starters"][11] = {11, "Cheese Balls", 349, 10};
    menu["starters"][12] = {12, "Tandoori Mushroom", 399, 10};
    menu["starters"][13] = {13, "Veg Momos", 199, 10};
    menu["starters"][14] = {14, "Dahi Bhalla", 229, 10};
    menu["starters"][15] = {15, "Cheese Corn Balls", 349, 10};
    menu["starters"][16] = {16, "Chana Chaat", 179, 10};
    menu["starters"][17] = {17, "Veg Seekh Kabab", 299, 10};
    menu["starters"][18] = {18, "Crispy Corn", 249, 10};
    menu["starters"][19] = {19, "Papdi Chaat", 199, 10};
    menu["starters"][20] = {20, "Aloo Tikki", 199, 10};

    // Chinese
    menu["chinese"][21] = {21, "Vegetable Fried Rice", 499, 10};
    menu["chinese"][22] = {22, "Gobi Manchurian", 599, 10};
    menu["chinese"][23] = {23, "Chilli Chicken", 699, 10};
    menu["chinese"][24] = {24, "Manchow Soup", 299, 10};
    menu["chinese"][25] = {25, "Hakka Noodles", 499, 10};
    menu["chinese"][26] = {26, "Sweet Corn Soup", 249, 10};
    menu["chinese"][27] = {27, "Schezwan Fried Rice", 549, 10};
    menu["chinese"][28] = {28, "Chilli Paneer", 649, 10};
    menu["chinese"][29] = {29, "Spring Roll", 349, 10};
    menu["chinese"][30] = {30, "Hot and Sour Soup", 299, 10};
    menu["chinese"][31] = {31, "Mushroom Manchurian", 599, 10};
    menu["chinese"][32] = {32, "Crispy Honey Chilli Potato", 399, 10};
    menu["chinese"][33] = {33, "Veg Manchurian", 499, 10};
    menu["chinese"][34] = {34, "Chicken Manchurian", 749, 10};
    menu["chinese"][35] = {35, "Egg Fried Rice", 549, 10};
    menu["chinese"][36] = {36, "Hot Garlic Chicken", 699, 10};
    menu["chinese"][37] = {37, "Vegetable Chow Mein", 499, 10};
    menu["chinese"][38] = {38, "Schezwan Noodles", 549, 10};
    menu["chinese"][39] = {39, "Crispy Chilli Chicken", 699, 10};
    menu["chinese"][40] = {40, "Paneer Chilli", 649, 10};

    // Thai
    menu["thai"][41] = {41, "Pad Thai", 699, 10};
    menu["thai"][42] = {42, "Tom Yum Soup", 349, 10};
    menu["thai"][43] = {43, "Green Curry", 599, 10};
    menu["thai"][44] = {44, "Thai Basil Fried Rice", 549, 10};
    menu["thai"][45] = {45, "Massaman Curry", 649, 10};
    menu["thai"][46] = {46, "Som Tum (Papaya Salad)", 399, 10};
    menu["thai"][47] = {47, "Pad See Ew", 499, 10};
    menu["thai"][48] = {48, "Tom Kha Soup", 349, 10};
    menu["thai"][49] = {49, "Pineapple Fried Rice", 599, 10};
    menu["thai"][50] = {50, "Red Curry", 599, 10};
    menu["thai"][51] = {51, "Panang Curry", 649, 10};
    menu["thai"][52] = {52, "Chicken Satay", 449, 10};
    menu["thai"][53] = {53, "Pad Kee Mao", 549, 10};
    menu["thai"][54] = {54, "Mango Sticky Rice", 349, 10};
    menu["thai"][55] = {55, "Thai Spring Rolls", 299, 10};
    menu["thai"][56] = {56, "Thai Iced Tea", 149, 10};
    menu["thai"][57] = {57, "Green Papaya Salad", 399, 10};
    menu["thai"][58] = {58, "Thai Basil Chicken", 599, 10};
    menu["thai"][59] = {59, "Papaya Pok Pok", 349, 10};
    menu["thai"][60] = {60, "Tom Yum Fried Rice", 599, 10};

    // Punjabi
    menu["punjabi"][61] = {61, "Dal Makhani", 499, 10};
    menu["punjabi"][62] = {62, "Butter Chicken", 699, 10};
    menu["punjabi"][63] = {63, "Paneer Butter Masala", 599, 10};
    menu["punjabi"][64] = {64, "Aloo Gobi", 399, 10};
    menu["punjabi"][65] = {65, "Chole Bhature", 449, 10};
    menu["punjabi"][66] = {66, "Sarson Ka Saag", 549, 10};
    menu["punjabi"][67] = {67, "Amritsari Kulcha", 249, 10};
    menu["punjabi"][68] = {68, "Pindi Chole", 499, 10};
    menu["punjabi"][69] = {69, "Punjabi Kadhi Pakora", 349, 10};
    menu["punjabi"][70] = {70, "Matar Paneer", 549, 10};
    menu["punjabi"][71] = {71, "Makki Ki Roti", 199, 10};
    menu["punjabi"][72] = {72, "Paneer Bhurji", 449, 10};
    menu["punjabi"][73] = {73, "Bhindi Masala", 399, 10};
    menu["punjabi"][74] = {74, "Aloo Paratha", 299, 10};
    menu["punjabi"][75] = {75, "Punjabi Lassi", 149, 10};
    menu["punjabi"][76] = {76, "Rajma Chawal", 399, 10};
    menu["punjabi"][77] = {77, "Papad Paratha", 299, 10};
    menu["punjabi"][78] = {78, "Punjabi Samosa", 199, 10};
    menu["punjabi"][79] = {79, "Baingan Bharta", 449, 10};
    menu["punjabi"][80] = {80, "Punjabi Kadi", 349, 10};

    // Kashmiri
    menu["kashmiri"][81] = {81, "Rogan Josh", 799, 10};
    menu["kashmiri"][82] = {82, "Yakhni", 899, 10};
    menu["kashmiri"][83] = {83, "Kashmiri Pulao", 699, 10};
    menu["kashmiri"][84] = {84, "Dum Aloo", 599, 10};
    menu["kashmiri"][85] = {85, "Kashmiri Roti", 149, 10};
    menu["kashmiri"][86] = {86, "Kahwa", 249, 10};
    menu["kashmiri"][87] = {87, "Modur Pulav", 799, 10};
    menu["kashmiri"][88] = {88, "Mutton Rogan Josh", 999, 10};
    menu["kashmiri"][89] = {89, "Nadru Yakhni", 649, 10};
    menu["kashmiri"][90] = {90, "Chaman Curry", 499, 10};
    menu["kashmiri"][91] = {91, "Shufta", 399, 10};
    menu["kashmiri"][92] = {92, "Wazwan", 1299, 10};
    menu["kashmiri"][93] = {93, "Kashmiri Chai", 199, 10};
    menu["kashmiri"][94] = {94, "Haaq", 299, 10};
    menu["kashmiri"][95] = {95, "Gushtaba", 1199, 10};
    menu["kashmiri"][96] = {96, "Phirni", 199, 10};
    menu["kashmiri"][97] = {97, "Kashmiri Roti", 99, 10};
    menu["kashmiri"][98] = {98, "Dum Olav", 599, 10};
    menu["kashmiri"][99] = {99, "Nadru Monje", 749, 10};
    menu["kashmiri"][100] = {100, "Aab Gosht", 1099, 10};

    // Italian
    menu["italian"][101] = {101, "Margherita Pizza", 499, 10};
    menu["italian"][102] = {102, "Spaghetti Carbonara", 599, 10};
    menu["italian"][103] = {103, "Fettuccine Alfredo", 549, 10};
    menu["italian"][104] = {104, "Lasagna", 699, 10};
    menu["italian"][105] = {105, "Risotto", 649, 10};
    menu["italian"][106] = {106, "Bruschetta", 299, 10};
    menu["italian"][107] = {107, "Tiramisu", 349, 10};
    menu["italian"][108] = {108, "Calzone", 549, 10};
    menu["italian"][109] = {109, "Caprese Salad", 399, 10};
    menu["italian"][110] = {110, "Penne Arrabiata", 449, 10};
    menu["italian"][111] = {111, "Gnocchi", 499, 10};
    menu["italian"][112] = {112, "Pizza Napoletana", 549, 10};
    menu["italian"][113] = {113, "Tortellini", 599, 10};
    menu["italian"][114] = {114, "Chicken Parmigiana", 699, 10};
    menu["italian"][115] = {115, "Minestrone Soup", 299, 10};
    menu["italian"][116] = {116, "Panettone", 349, 10};
    menu["italian"][117] = {117, "Ravioli", 549, 10};
    menu["italian"][118] = {118, "Linguine with Clam Sauce", 599, 10};
    menu["italian"][119] = {119, "Cannoli", 349, 10};
    menu["italian"][120] = {120, "Vegetable Risotto", 549, 10};

    // South Indian
    menu["south indian"][121] = {121, "Masala Dosa", 199, 10};
    menu["south indian"][122] = {122, "Idli Sambhar", 149, 10};
    menu["south indian"][123] = {123, "Vada Sambhar", 149, 10};
    menu["south indian"][124] = {124, "Uttapam", 179, 10};
    menu["south indian"][125] = {125, "Pongal", 159, 10};
    menu["south indian"][126] = {126, "Rava Dosa", 199, 10};
    menu["south indian"][127] = {127, "Appam with Stew", 249, 10};
    menu["south indian"][128] = {128, "Pesarattu", 169, 10};
    menu["south indian"][129] = {129, "Neer Dosa", 189, 10};
    menu["south indian"][130] = {130, "Upma", 129, 10};
    menu["south indian"][131] = {131, "Medu Vada", 99, 10};
    menu["south indian"][132] = {132, "Coconut Chutney", 49, 10};
    menu["south indian"][133] = {133, "Sambar", 59, 10};
    menu["south indian"][134] = {134, "Rasam", 59, 10};
    menu["south indian"][135] = {135, "Curd Rice", 99, 10};
    menu["south indian"][136] = {136, "Lemon Rice", 129, 10};
    menu["south indian"][137] = {137, "Tomato Rice", 129, 10};
    menu["south indian"][138] = {138, "Puliyogare", 139, 10};
    menu["south indian"][139] = {139, "Avial", 149, 10};
    menu["south indian"][140] = {140, "Mysore Masala Dosa", 229, 10};

    // Drinks
    menu["drinks"][141] = {141, "Mango Lassi", 99, 10};
    menu["drinks"][142] = {142, "Fresh Lime Soda", 79, 10};
    menu["drinks"][143] = {143, "Iced Tea", 89, 10};
    menu["drinks"][144] = {144, "Cold Coffee", 109, 10};
    menu["drinks"][145] = {145, "Hot Chocolate", 129, 10};
    menu["drinks"][146] = {146, "Green Tea", 69, 10};
    menu["drinks"][147] = {147, "Milkshake", 119, 10};
    menu["drinks"][148] = {148, "Orange Juice", 99, 10};
    menu["drinks"][149] = {149, "Apple Juice", 99, 10};
    menu["drinks"][150] = {150, "Cranberry Juice", 109, 10};
    menu["drinks"][151] = {151, "Pineapple Juice", 99, 10};
    menu["drinks"][152] = {152, "Coconut Water", 49, 10};
    menu["drinks"][153] = {153, "Buttermilk", 59, 10};
    menu["drinks"][154] = {154, "Sugarcane Juice", 69, 10};
    menu["drinks"][155] = {155, "Guava Juice", 89, 10};
    menu["drinks"][156] = {156, "Watermelon Juice", 89, 10};
    menu["drinks"][157] = {157, "Strawberry Shake", 129, 10};
    menu["drinks"][158] = {158, "Blueberry Smoothie", 139, 10};
    menu["drinks"][159] = {159, "Peach Iced Tea", 99, 10};
    menu["drinks"][160] = {160, "Lemonade", 79, 10};

    // Refreshment
    menu["refreshment"][161] = {161, "Masala Chai", 49, 10};
    menu["refreshment"][162] = {162, "Mint Lemonade", 59, 10};
    menu["refreshment"][163] = {163, "Ginger Tea", 39, 10};
    menu["refreshment"][164] = {164, "Iced Coffee", 79, 10};
    menu["refreshment"][165] = {165, "Hot Cocoa", 69, 10};
    menu["refreshment"][166] = {166, "Rose Milk", 59, 10};
    menu["refreshment"][167] = {167, "Lemon Tea", 49, 10};
    menu["refreshment"][168] = {168, "Orange Soda", 89, 10};
    menu["refreshment"][169] = {169, "Lemon Soda", 79, 10};
    menu["refreshment"][170] = {170, "Mint Tea", 49, 10};
    menu["refreshment"][171] = {171, "Cucumber Cooler", 69, 10};
    menu["refreshment"][172] = {172, "Hibiscus Iced Tea", 59, 10};
    menu["refreshment"][173] = {173, "Jaljeera", 49, 10};
    menu["refreshment"][174] = {174, "Kesar Badam Milk", 99, 10};
    menu["refreshment"][175] = {175, "Kokum Juice", 79, 10};
    menu["refreshment"][176] = {176, "Butterfly Pea Flower Tea", 69, 10};
    menu["refreshment"][177] = {177, "Kashmiri Kahwa", 149, 10};
    menu["refreshment"][178] = {178, "Lime Mint Cooler", 69, 10};
    menu["refreshment"][179] = {179, "Pineapple Mint Juice", 89, 10};
    menu["refreshment"][180] = {180, "Strawberry Lemonade", 99, 10};
}


// Function to display all menu items
void displayMenu() {
    for (const auto& category : menu) {
        cout << "Category: " << category.first << endl;
        for (const auto& item : category.second) {
            cout << "  ID: " << item.second.id << " - " << item.second.name << " - Rs " << item.second.price << " - Quantity: " << item.second.quantity << endl;
        }
    }
}

// Function to add an order
void addOrder() {
    int itemId, quantity;
    cout << "Enter item ID: ";
    cin >> itemId;
    cout << "Enter quantity: ";
    cin >> quantity;

    // Check if the item ID exists in the menu
    bool found = false;
    for (const auto& category : menu) {
        for (const auto& item : category.second) {
            if (item.second.id == itemId) {
                found = true;
                insertedItems.push_back(itemId);
                cout << "Order added successfully!" << endl;
                break;
            }
        }
        if (found) break;
    }
    if (!found) {
        cout << "Item not found in the menu!" << endl;
    }
}

// Function to remove an order
void removeOrder() {
    int itemId;
    cout << "Inserted Items:" << endl;
    for (int id : insertedItems) {
        cout << id << endl;
    }
    cout << "Enter item ID to remove: ";
    cin >> itemId;

    auto it = find(insertedItems.begin(), insertedItems.end(), itemId);
    if (it != insertedItems.end()) {
        insertedItems.erase(it);
        cout << "Item removed successfully!" << endl;
    } else {
        cout << "Item not found in the inserted items!" << endl;
    }
}

// Function to calculate total bill
double calculateBill() {
    double total = 0.0;
    for (int itemId : insertedItems) {
        for (const auto& category : menu) {
            for (const auto& item : category.second) {
                if (item.second.id == itemId) {
                    total += item.second.price;
                    break;
                }
            }
        }
    }
    return total;
}

int main() {
    // Initialize the menu
    initializeMenu();

    int choice;
    do {
        cout << "\nHotel Menu Management System" << endl;
        cout << "1. Display Menu" << endl;
        cout << "2. Add Order" << endl;
        cout << "3. Remove Order" << endl;
        cout << "4. Calculate Bill" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayMenu();
                break;
            case 2:
                addOrder();
                break;
            case 3:
                removeOrder();
                break;
            case 4:
                cout << "Total Bill: Rs " << calculateBill() << endl;
                break;
            case 5:
                cout << "Exiting... Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
