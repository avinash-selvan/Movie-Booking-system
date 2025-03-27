#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef maxtime
#define maxtime 3
#endif

#define maxrow 7
#define maxcolumn 6
#define maxmovie 3
#define maxscreen 3

typedef struct Movie {
    char movie_name[30];
    char time[maxtime][10];
    int screen_no;
    int adjmat[maxtime][maxrow][maxcolumn];
} MOVIE;

void initMatrix(int adjmat[][maxrow][maxcolumn], int max_time) {
    for (int t = 0; t < max_time; t++) {
        for (int i = 1; i < maxrow; i++) {
            for (int j = 1; j < maxcolumn; j++) {
                adjmat[t][i][j] = 0;
            }
        }
    }
}

void displayMatrix(int adjmat[][maxrow][maxcolumn], int max_time, int timing) {
    printf("Seat Matrix for Time %s:\n", timing == 0 ? "1st Show" : (timing == 1 ? "2nd Show" : "3rd Show"));
    for (int i = 1; i < maxrow; i++) {
        for (int j = 1; j < maxcolumn; j++) {
            printf(" %d ", adjmat[timing][i][j]);
        }
        printf("\n");
    }
}

int seat_selection(int adjmat[][maxrow][maxcolumn], int size, int row, int column, int timing) {
    if (row < maxrow && column < maxcolumn) {
        for (int i = column; i < column + size; i++) {
            if (adjmat[timing][row][i] == 1) {
                printf("Those seats are already taken, please select the available ones\n");
                return 0;
            }
        }
        for (int i = column; i < column + size; i++) {
            adjmat[timing][row][i] = 1;
        }
        printf("Seats Selected Successfully\n");
        return 1;
    } else {
        printf("Invalid row or column, please select appropriate ones\n");
        return 0;
    }
}

int cancel_booking(int adjmat[][maxrow][maxcolumn], int row, int column, int size, int timing) {
    if (row < maxrow && column < maxcolumn) {
        for (int i = column; i < column + size; i++) {
            if (adjmat[timing][row][i] != 1) {
                printf("Seats were not cancelled, inappropriate details\n");
                return 0;
            }
        }
        for (int i = column; i < column + size; i++) {
            adjmat[timing][row][i] = 0;
        }
        printf("Seats successfully cancelled\n");
        return 1;
    } else {
        printf("Invalid row or column, please provide appropriate details\n");
        return 0;
    }
}

int price_calculation(int adjmat[][maxrow][maxcolumn], int timing, int row, int size) {
    int price;
    if (row >= 1 && row < 3) {
        price = 450 * size;
    } else if (row >= 3 && row < 6) {
        price = 375 * size;
    } else {
        price = 300 * size;
    }
    return price;
}

int create_theater(MOVIE *moviep[]) {
    int n_movies;

    printf("Welcome to the Movie Booking System!\n");
    printf("Enter the number of movies in the theater: ");
    scanf("%d", &n_movies);

    for (int i = 0; i < n_movies; i++) {
        moviep[i] = (MOVIE *)malloc(sizeof(MOVIE));
    }

    // Clear the input buffer
    while (getchar() != '\n');

    for (int i = 0; i < n_movies; i++) {
        printf("Enter the movie name %d: ", i + 1);
        fgets(moviep[i]->movie_name, sizeof(moviep[i]->movie_name), stdin);
        moviep[i]->movie_name[strcspn(moviep[i]->movie_name, "\n")] = 0;  // Remove the trailing newline character

        printf("Enter the showtimes for %s for %d times\n", moviep[i]->movie_name, maxtime);
        for (int j = 0; j < maxtime; j++) {
            printf("Showtime %d: ", j + 1);
            fgets(moviep[i]->time[j], sizeof(moviep[i]->time[j]), stdin);
            moviep[i]->time[j][strcspn(moviep[i]->time[j], "\n")] = 0;  // Remove the trailing newline character
        }
        moviep[i]->screen_no = i + 1;
    }
    return n_movies;
}

void display_theater(MOVIE *moviep[], int n_movies) {
    printf("\nMovies in the Theater:\n");
    for (int i = 0; i < n_movies; i++) {
        printf("%d. %s\n", i + 1, moviep[i]->movie_name);
        printf("   Showtimes:\n");
        for (int j = 0; j < maxtime; j++) {
            printf("   - %s\n", moviep[i]->time[j]);
        }
    }
    printf("-------------------------------\n");

