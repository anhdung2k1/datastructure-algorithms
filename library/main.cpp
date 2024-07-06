#include "Library.cpp"

int getIntegerLength(int num) {
    if (num == 0) return 1;
    int length = 0;
    while (num != 0) {
        num /= 10;
        length++;
    }
    return length;
}

int main() {
    Library library;
    library.readFromFile("books.txt");

    int choice;
    do {
        cout << "Library Management System" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Delete Book" << endl;
        cout << "3. Find Book by ID" << endl;
        cout << "4. Edit Book" << endl;
        cout << "5. Generate Barcode" << endl;
        cout << "6. Sort Books by Price" << endl;
        cout << "7. Display all Books in Library" << endl;
        cout << "8. Save and Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string bookName, bookID;
            int bookPrice, bookQuantity;
            cout << "Enter book name: ";
            cin.ignore(); // Ignore the leftover newline character
            getline(cin, bookName);
            cout << "Enter book ID: ";
            cin >> bookID;
            cout << "Enter book price: ";
            cin >> bookPrice;
            cout << "Enter book quantity: ";
            cin >> bookQuantity;
            library.addBook(Book(bookName, bookID, bookPrice, bookQuantity));
            break;
        }
        case 2: {
            string bookID;
            cout << "Enter book ID: ";
            cin >> bookID;
            library.deleteBook(bookID);
            break;
        }
        case 3: {
            string bookID;
            cout << "Enter book ID: ";
            cin >> bookID;
            BookNode* bookNode = library.findBookByID(bookID);
            library.displayBook(bookNode);
            break;
        }
        case 4: {
            string bookID;
            cout << "Enter book ID: ";
            cin >> bookID;
            library.editBook(bookID);
            break;
        }
        case 5: {
            string bookID;
            cout << "Enter book ID: ";
            cin >> bookID;
            library.generateBarcode(bookID, "barcode.jpg");
            break;
        }
        case 6: {
            library.sortBooksByPrice();
            library.writeToFile("Sorted.txt");
            cout << "Books sorted by price and saved to Sorted.txt" << endl;
            break;
        }
        case 7: {
            library.displayAllBooks();
            break;
        }
        case 8: {
            library.writeToFile("books.txt");
            break;
        }
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 8);

    return 0;
}
