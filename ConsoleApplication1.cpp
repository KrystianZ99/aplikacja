#include <iostream>
#include <vector>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    int yearOfPublication;
    bool isAvailable;

public:
    Book(const std::string& bookTitle, const std::string& bookAuthor, int publicationYear)
        : title(bookTitle), author(bookAuthor), yearOfPublication(publicationYear), isAvailable(true) {}

    std::string getTitle() const {
        return title;
    }

    std::string getAuthor() const {
        return author;
    }

    int getYearOfPublication() const {
        return yearOfPublication;
    }

    bool getAvailability() const {
        return isAvailable;
    }

    void setAvailability(bool availability) {
        isAvailable = availability;
    }
};

class Library {
private:
    std::vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void searchByTitle(const std::string& title) {
        bool found = false;
        for (const Book& book : books) {
            if (book.getTitle() == title) {
                displayBookDetails(book);
                found = true;
            }
        }
        if (!found) {
            std::cout << "Book with title \"" << title << "\" not found." << std::endl;
        }
    }

    void searchByAuthor(const std::string& author) {
        bool found = false;
        for (const Book& book : books) {
            if (book.getAuthor() == author) {
                displayBookDetails(book);
                found = true;
            }
        }
        if (!found) {
            std::cout << "Book by author \"" << author << "\" not found." << std::endl;
        }
    }

    void displayBookDetails(const Book& book) {
        std::cout << "Title: " << book.getTitle() << std::endl;
        std::cout << "Author: " << book.getAuthor() << std::endl;
        std::cout << "Year of Publication: " << book.getYearOfPublication() << std::endl;
        std::cout << "Availability: " << (book.getAvailability() ? "Available" : "Not Available") << std::endl;
        std::cout << std::endl;
    }
};

int main() {
    Library library;

    // Add books to the library
    Book book1("The Catcher in the Rye", "J.D. Salinger", 1951);
    Book book2("To Kill a Mockingbird", "Harper Lee", 1960);
    Book book3("1984", "George Orwell", 1949);
    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);

    // Search for books
    std::cout << "Searching for books by title:" << std::endl;
    library.searchByTitle("To Kill a Mockingbird");

    std::cout << "Searching for books by author:" << std::endl;
    library.searchByAuthor("George Orwell");

    return 0;
}
