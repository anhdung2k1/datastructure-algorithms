#include <iostream>
#include <fstream>
#include <string>
#include <opencv2/opencv.hpp>
#include <iomanip>

using namespace std;
using namespace cv;

struct Book {
    string bookName;
    string bookID;
    int bookPrice;
    int bookQuantity;

    // Default constructor
    Book() : bookName(""), bookID(""), bookPrice(0), bookQuantity(0) {}

    // Parameterized constructor
    Book(const string& bookName, const string& bookID, int bookPrice, int bookQuantity)
        : bookName(bookName), bookID(bookID), bookPrice(bookPrice), bookQuantity(bookQuantity) {}
};

class BookNode {
public:
    Book book;
    BookNode* prev;
    BookNode* next;

    BookNode(const Book& book) : book(book), prev(nullptr), next(nullptr) {}
};

class Library {
private:
    int calculateChecksum(const string& code) {
        int sumOdd = 0, sumEven = 0;
        for (size_t i = 0; i < code.size(); ++i) {
            if (i % 2 == 0) {
                sumOdd += code[i] - '0';
            } else {
                sumEven += code[i] - '0';
            }
        }
        int total = (sumOdd * 3) + sumEven;
        return (10 - (total % 10)) % 10;
    }

    string generateBarcodeString(const string& code) {
        string left[] = { "0001101", "0011001", "0010011", "0111101", "0100011", "0110001", "0101111", "0111011", "0110111", "0001011" };
        string right[] = { "1110010", "1100110", "1101100", "1000010", "1011100", "1001110", "1010000", "1000100", "1001000", "1110100" };

        string barcode = "101"; // Start code

        for (int i = 0; i < 6; ++i) {
            barcode += left[code[i] - '0'];
        }

        barcode += "01010"; // Middle separator

        for (int i = 6; i < 12; ++i) {
            barcode += right[code[i] - '0'];
        }

        barcode += "101"; // End code

        return barcode;
    }

    void displayBarcodeInConsole(const string& barcode) {
        for (char c : barcode) {
            if (c == '1') {
                cout << "|";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

    BookNode* merge(BookNode* left, BookNode* right) {
        if (!left) return right;
        if (!right) return left;

        if (left->book.bookPrice <= right->book.bookPrice) {
            left->next = merge(left->next, right);
            if (left->next) left->next->prev = left;
            left->prev = nullptr;
            return left;
        } else {
            right->next = merge(left, right->next);
            if (right->next) right->next->prev = right;
            right->prev = nullptr;
            return right;
        }
    }

    BookNode* mergeSort(BookNode* node) {
        if (!node || !node->next) {
            return node;
        }

        BookNode* second = split(node);
        node = mergeSort(node);
        second = mergeSort(second);
        return merge(node, second);
    }

    BookNode* split(BookNode* node) {
        BookNode* fast = node;
        BookNode* slow = node;

        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        BookNode* temp = slow->next;
        slow->next = nullptr;
        return temp;
    }

public:
    BookNode* head;
    BookNode* tail;
    Library() : head(nullptr), tail(nullptr) {}

    void addBook(const Book& book) {
        BookNode* newNode = new BookNode(book);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void deleteBook(const string& bookID) {
        for (BookNode* current = head; current; current=current->next) {
            if (findBookByID(bookID) != nullptr) {
                if (current->prev) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }

                if (current->next) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }

                delete current;
                cout << "Book with ID " << bookID << " has been deleted." << endl;
                return;
            }
        }
        cout << "Book with ID " << bookID << " not found." << endl;
    }

    void readFromFile(const string& filename) {
        ifstream inFile(filename);
        if (!inFile) {
            cerr << "Unable to open file for reading" << endl;
            return;
        }
        string line;
        while (getline(inFile, line)) {
            stringstream ss(line);
            string bookName, bookID;
            int bookPrice, bookQuantity;

            if (getline(ss, bookName, ',') &&
                ss >> bookID >> bookPrice >> bookQuantity) {
                addBook(Book(bookName, bookID, bookPrice, bookQuantity));
            }
        }
        inFile.close();
    }


    void writeToFile(const string& filename) {
        ofstream outFile(filename);
        if (!outFile) {
            cerr << "Unable to open file for writing" << endl;
            return;
        }
        BookNode* current = head;
        while (current) {
            outFile << current->book.bookName << ","
                    << current->book.bookID << " "
                    << current->book.bookPrice << " "
                    << current->book.bookQuantity << endl;
            current = current->next;
        }
        outFile.close();
    }

    BookNode* findBookByID(const string& bookID) {
        BookNode* current = head;
        while (current) {
            if (current->book.bookID == bookID) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void displayBook(const BookNode* node) {
        if (node) {
            cout << "Book Name: " << node->book.bookName << endl;
            cout << "Book ID: " << node->book.bookID << endl;
            cout << "Book Price: " << node->book.bookPrice << endl;
            cout << "Book Quantity: " << node->book.bookQuantity << endl;
        } else {
            cout << "Book not found" << endl;
        }
    }

    void displayAllBooks() {
        if (!head) {
            cout << "No books in the library." << endl;
            return;
        }

        // Print table header
        cout << left << setw(30) << "Book Name"
            << setw(15) << "Book ID"
            << setw(10) << "Price"
            << setw(10) << "Quantity" << endl;

        cout << string(65, '-') << endl;

        // Print each book's details
        BookNode* current = head;
        while (current) {
            cout << left << setw(30) << current->book.bookName
                << setw(15) << current->book.bookID
                << setw(10) << current->book.bookPrice
                << setw(10) << current->book.bookQuantity << endl;
            current = current->next;
        }
    }

    void generateBarcode(const string& bookID, const string& outputFilename) {
        if (findBookByID(bookID) == nullptr) {
            cerr << "Book not found in the library..." << endl;
            return;
        }
        string code = bookID;
        if (code.size() < 11) {
            code = string(11 - code.size(), '0') + code;
        } else if (code.size() > 11) {
            cerr << "Book ID must be 11 digits long to generate UPC-A barcode" << endl;
            return;
        }
        int checksum = calculateChecksum(code);
        code += to_string(checksum);

        string barcode = generateBarcodeString(code);

        // Display barcode on console
        cout << "Barcode for Book ID " << bookID << ": " << endl;
        displayBarcodeInConsole(barcode);

        // Create the barcode image
        int width = barcode.size();
        int height = 100;
        Mat img(height, width, CV_8UC1, Scalar(255));

        for (int i = 0; i < width; ++i) {
            if (barcode[i] == '1') {
                line(img, Point(i, 0), Point(i, height), Scalar(0), 1);
            }
        }

        // Save the barcode image
        imwrite(outputFilename, img);
        cout << "Barcode saved to " << outputFilename << endl;
    }

    void editBook(const string& bookID) {
        BookNode* bookNode = findBookByID(bookID);
        if (bookNode) {
            cout << "Enter new book name: ";
            cin.ignore(); // Ignore the leftover newline character
            getline(cin, bookNode->book.bookName);
            cout << "Enter new book ID: ";
            cin >> bookNode->book.bookID;
            cout << "Enter new book price: ";
            cin >> bookNode->book.bookPrice;
            cout << "Enter new book quantity: ";
            cin >> bookNode->book.bookQuantity;
        } else {
            cout << "Book not found" << endl;
        }
    }

    void sortBooksByPrice() {
        head = mergeSort(head);
        // Reset tail
        BookNode* current = head;
        while (current && current->next) {
            current = current->next;
        }
        tail = current;
    }
};