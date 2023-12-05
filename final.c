#include <stdio.h>

    // Function to display available movies
    void displayMovies() {
        printf("1. Avengers: Endgame\n");
        printf("2. The Shawshank Redemption\n");
        printf("3. The Dark Knight\n");
    }

    // Function to display seat matrix
    void displaySeatMatrix(int rows, int cols, char seatMatrix[][cols]) {
        printf("\nSeat Matrix:\n");

        // Display column letters
        printf("  ");
        for (int j = 0; j < cols; j++) {
            printf("%c ", 'a' + j);
        }
        printf("\n");

        // Display seat matrix with row numbers
        for (int i = 0; i < rows; i++) {
            printf("%d ", i + 1); // Display row number

            for (int j = 0; j < cols; j++) {
                printf("%c ", seatMatrix[i][j]);
            }
            printf("\n");
        }
    }

    // Function to calculate total price based on the number of selected seats
    int calculatePrice(int numSeats, int pricePerSeat) {
        return numSeats * pricePerSeat;
    }

    int main() {
        // Movie details
        int selectedMovie;
        char movies[3][30] = {"Avengers: Endgame", "The Shawshank Redemption", "The Dark Knight"};

        // Seat details
        const int rows = 5;
        const int cols = 10;
        char seatMatrix[rows][cols];
        int selectedSeats[rows * cols];
        int numSeats;

        // Booked seats information
        int bookedSeatsCount = 0;
        int bookedSeats[rows * cols];

        // Ticket pricing
        const int pricePerSeat = 10;

        // Main loop for the program
        while (1) {
            // Display available movies
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

            selectedMovie--; // Adjust index

            // Initialize seat matrix
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    seatMatrix[i][j] = 'O'; // 'O' represents an available seat
                }
            }

            // Display booked seats from the previous selections
            for (int i = 0; i < bookedSeatsCount; i++) {
                int row = bookedSeats[i] / cols;
                int col = bookedSeats[i] % cols;
                seatMatrix[row][col] = 'X'; // Mark booked seats as 'X'
            }

            // Display seat matrix
            displaySeatMatrix(rows, cols, seatMatrix);

            // Select seats
            printf("\nEnter the number of seats you want to book: ");
            scanf("%d", &numSeats);

            printf("\nEnter seat numbers (row and column, e.g., 1 a) separated by space:\n");
            for (int i = 0; i < numSeats; i++) {
                while (1) {
                    int row;
                    char col;
                    scanf("%d %c", &row, &col);

                    // Check if the seat is available
                    if (row >= 1 && row <= rows && col >= 'a' && col < 'a' + cols && seatMatrix[row - 1][col - 'a'] == 'O') {
                        seatMatrix[row - 1][col - 'a'] = 'X'; // 'X' represents a booked seat
                        selectedSeats[i] = (row - 1) * cols + (col - 'a'); // Save seat number
                        bookedSeats[bookedSeatsCount++] = selectedSeats[i]; // Save booked seat information
                        break;
                    } else {
                        printf("Invalid seat selection. Please choose another seat.\n");
                    }
                }
            }

            // Display updated seat matrix
            displaySeatMatrix(rows, cols, seatMatrix);

            // Calculate and display total price
            int totalPrice = calculatePrice(numSeats, pricePerSeat);
            printf("\nTotal Price for %d seats: $%d\n", numSeats, totalPrice);

            // Option to go back to the home page or exit the program
            printf("\nOptions:\n");
            printf("1. Go to Home Page (Select a new movie)\n");
            printf("2. Exit\n");

            int option;
            scanf("%d", &option);

            if (option == 2) {
                break; // Exit the program
            }
            // Otherwise, continue to the next iteration of the main loop
        }

        return 0;
    }
