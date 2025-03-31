#define MAX_LENGTH 100

// define struct BookLoan
typedef struct{
    char name[MAX_LENGTH];
    char bookLoan[MAX_LENGTH];
}BookLoan;

// define struct InventoryBook
typedef struct{
    char bookName[MAX_LENGTH];
    int bookCopy;
}InventoryBook;
/**
 * createMenu creates a user menù with the following options:
 * 1 - Print current loans count
 * 2 - Get book inventory
 * 3 - Add new book loan
 * 4 - Add new book to inventory
 * 5 - Print user loans
 * If the line is empty, -1 is returned
 * If the choice is valid, its number is returned.
 */
int createMenu() {
    int choice;
    do {
        printf("1 - Print current loans count");
        printf("2 - Get book inventory");
        printf("3 - Add new book loan");
        printf("4 - Add new book to inventory");
        printf("5 - Print user loans");
        scanf("%d", &choice);
    }while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5);
    return choice;
}

/**
 * doOperation takes the number representing a choice and
 * executes the corresponding operation
 * Returns -1 in case of any error.
 */
int doOperation(int choice) {
    switch (choice) {
        case 1:
            getCurrentLoanCount();
            break;
        case 2:
            printBookInventory();
            break;
        case 3:
            addNewLoan(BookLoan loan);
        case 4:
            addNewBookInInventory(InventoryBook book);
            break;
        case 5:
            printUserLoans(name[MAX_LENGTH]);
            break;
    }
}

/**
 * getCurrentLoanCount returns the number of loans available in the
 * "loans.txt" file.
 * Returns -1 in case of any error.
 */
int getCurrentLoanCount() {
    FILE *src = fopen("./loans.txt", "r");
    int cnt = 0;
    int row [MAX_LENGTH];
    if (src== NULL) {
        printf("Errore di apertura di un file\n");
    }
    for (int i = 0; i < feof(src);i++){
        if(fgets(row, MAX_LENGTH, src) != "")
        {
            cnt++;
        }

    }
    fclose;
    return cnt;
}

/**
 * printBookInventory prints each book and number of copies in the inventory
 * file "books.txt", one by line, with the following format
 *
 * Book Name - Number of copies
 *
 * Example
 *
 * Zibaldone - 5
 * Astrology_For_Dummies - 1
 */
int printBookInventory() {
    FILE *src = fopen("./books.txt", "r");
    int name[MAX_LENGTH];
    int copies;
    if (src == NULL) {
        printf("Errore di apertura di un file\n");
    }
    while(!feof(src))
    {
    fgets(name, MAX_LENGTH, src);
    }
    fclose;
    return ;
}

/**
 * addNewLoan adds a new loan to the loans file.
 * Returns -1 in case of any error.
 */
int addNewLoan(BookLoan loan) {
    // implement function logic here
    return -1;
}

/**
 * addNewBookInInventory adds a new book to the inventory file.
 * Returns -1 in case of any error.
 */
int addNewBookInInventory(InventoryBook book) {
    // implement function logic here
    return -1;
}

/**
 * printUserLoans prints all the books loaned to a user with
 * the specified name.
 * Returns -1 in case of any error.
 */
int printUserLoans(char name[MAX_LENGTH]) {
    // implement function logic here
    return -1;
}