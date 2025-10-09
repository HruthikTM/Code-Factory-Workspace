#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct library {
    int accno;
    char title[20];
    char author[20];
    float price;
    int is_issued;
};

void addBook(struct library books[], int *count);
void displayBooks(struct library books[], int count);
void listByAuthor(struct library books[], int count);
void searchByTitle(struct library books[], int count);
void countBooks(int count);
void listByAccession(struct library books[], int count);

int compareAccession(const void *a, const void *b) {
    struct library *book1 = (struct library *)a;
    struct library *book2 = (struct library *)b;
    return book1->accno - book2->accno;
}

int main() {
    struct library books[MAX];
    int count = 0, choice;

    do {
        printf("\n--- Library Menu ---\n");
        printf("1. Add book information\n");
        printf("2. Display book information\n");
        printf("3. List all books of given author\n");
        printf("4. List the title of specified book\n");
        printf("5. List the count of books in the library\n");
        printf("6. List the books in the order of accession number\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
        case 1:
            addBook(books, &count);
            break;
        case 2:
            displayBooks(books, count);
            break;
        case 3:
            listByAuthor(books, count);
            break;
        case 4:
            searchByTitle(books, count);
            break;
        case 5:
            countBooks(count);
            break;
        case 6:
            listByAccession(books, count);
            break;
        case 7:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 7);

    return 0;
}

void addBook(struct library books[], int *count) {
    if (*count >= MAX) {
        printf("Library is full\n");
        return;
    }

    printf("Enter the accession number: ");
    scanf("%d", &books[*count].accno);
    getchar();

    printf("Enter the book title: ");
    scanf(" %19[^\n]", books[*count].title);

    printf("Enter the author name: ");
    scanf(" %19[^\n]", books[*count].author);

    printf("Enter the price of the book: ");
    scanf("%f", &books[*count].price);

    printf("Is the book issued? (1 = Yes, 0 = No): ");
    scanf("%d", &books[*count].is_issued);

    (*count)++;
    printf("Book added successfully.\n");
}

void displayBooks(struct library books[], int count) {
    if (count == 0) {
        printf("No books available.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\nBook %d\n", i + 1);
        printf("Accession No: %d\n", books[i].accno);
        printf("Book Title: %s\n", books[i].title);
        printf("Author Name: %s\n", books[i].author);
        printf("Book Price: %.2f\n", books[i].price);
        printf("Book Issued: %s\n", books[i].is_issued ? "Yes" : "No");
    }
}

void listByAuthor(struct library books[], int count) {
    char author[20];
    int found = 0;

    printf("Enter the author name: ");
    scanf(" %19[^\n]", author);

    for (int i = 0; i < count; i++) {
        if (strcmp(books[i].author, author) == 0) {
            printf("Title: %s | Accession No: %d\n", books[i].title, books[i].accno);
            found = 1;
        }
    }

    if (!found)
        printf("No books found by this author.\n");
}

void searchByTitle(struct library books[], int count) {
    char title[20];
    int found = 0;

    printf("Enter the book title: ");
    scanf(" %19[^\n]", title);

    for (int i = 0; i < count; i++) {
        if (strcmp(books[i].title, title) == 0) {
            printf("\nBook found\n");
            printf("Accession No: %d\n", books[i].accno);
            printf("Author Name: %s\n", books[i].author);
            printf("Book Price: %.2f\n", books[i].price);
            printf("Book Issued: %s\n", books[i].is_issued ? "Yes" : "No");
            found = 1;
        }
    }

    if (!found)
        printf("No books found by this title.\n");
}

void countBooks(int count) {
    printf("Total number of books in the library: %d\n", count);
}

void listByAccession(struct library books[], int count) {
    if (count == 0) {
        printf("No books to display.\n");
        return;
    }

    qsort(books, count, sizeof(struct library), compareAccession);
    printf("Books sorted by accession number:\n");
    displayBooks(books, count);
}
