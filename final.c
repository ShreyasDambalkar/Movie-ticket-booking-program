#include <stdio.h>

void displayMovies() {
    printf("1. Avengers: Endgame\n");
    printf("2. The Shawshank Redemption\n");
    printf("3. The Dark Knight\n");
}

void displaySeatMatrix(int rows, int cols, char seatMatrix[][cols]) {
    printf("\nSeat Matrix:\n");
    printf("  ");
    for (int j = 0; j < cols; j++) {
        printf("%c ", 'a' + j);
    }
    printf("\n");
    for (int i = 0; i < rows; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < cols; j++) {
            printf("%c ", seatMatrix[i][j]);
        }
        printf("\n");
    }
}

int calculatePrice(int numSeats, int pricePerSeat) {
    return numSeats * pricePerSeat;
}

int main() {
    int selectedMovie;
    char movies[3][30] = {"Avengers: Endgame", "The Shawshank Redemption", "The Dark Knight"};
    const int rows = 5;
    const int cols = 10;
    char seatMatrix[rows][cols];
    int selectedSeats[rows * cols];
    int numSeats;
    int bookedSeatsCount = 0;
    int bookedSeats[rows * cols];
    const int pricePerSeat = 10;

    while (1) {
        while (1) {
            printf("Select a movie:\n");
            displayMovies();
            scanf("%d", &selectedMovie);

            if (selectedMovie >= 1 && selectedMovie <= 3) {
                break;
            } else {
                printf("Invalid movie selection. Please try again.\n");
            }
        }

        selectedMovie--;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                seatMatrix[i][j] = 'O';
            }
        }

        for (int i = 0; i < bookedSeatsCount; i++) {
            int row = bookedSeats[i] / cols;
            int col = bookedSeats[i] % cols;
            seatMatrix[row][col] = 'X';
        }

        displaySeatMatrix(rows, cols, seatMatrix);

        printf("\nEnter the number of seats you want to book: ");
        scanf("%d", &numSeats);

        printf("\nEnter seat numbers (row and column, e.g., 1 a) separated by space:\n");
        for (int i = 0; i < numSeats; i++) {
            while (1) {
                int row;
                char col;
                scanf("%d %c", &row, &col);

                if (row >= 1 && row <= rows && col >= 'a' && col < 'a' + cols && seatMatrix[row - 1][col - 'a'] == 'O') {
                    seatMatrix[row - 1][col - 'a'] = 'X';
                    selectedSeats[i] = (row - 1) * cols + (col - 'a');
                    bookedSeats[bookedSeatsCount++] = selectedSeats[i];
                    break;
                } else {
                    printf("Invalid seat selection. Please choose another seat.\n");
                }
            }
        }

        displaySeatMatrix(rows, cols, seatMatrix);

        int totalPrice = calculatePrice(numSeats, pricePerSeat);
        printf("\nTotal Price for %d seats: $%d\n", numSeats, totalPrice);

        printf("\nOptions:\n");
        printf("1. Go to Home Page (Select a new movie)\n");
        printf("2. Exit\n");

        int option;
        scanf("%d", &option);

        if (option == 2) {
            break;
        }
    }

    return 0;
}
